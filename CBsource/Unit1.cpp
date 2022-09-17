//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
using namespace std;

#include "IniFiles.hpp"

#include "malloc.h"

#pragma hdrstop
             
#include "Unit1.h"

#include "Defines.h"

#include "Ring_prot.h"
#include "CRC32.h"
#include "SerialCOM_WIN.h"

#include "Schedlib.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;


typedef struct
{
 AnsiString SetAlarmFile;
 AnsiString SetFireFile;
 AnsiString SetRingFile;
}T_SoundFiles;

typedef struct
{
 unsigned FileNumber;
 bool used;
 bool in_weekday[7];
}t_OldActiveEvent;

typedef struct
{
  AnsiString  full_name;
  AnsiString  file_name;
}t_SoundFileList;


enum IO_State {IDLE, SEND_COMM, SEND_BLOCK, GET_ANSWER, IO_ERROR};


enum T_TypeList {BASE_LIST, TODAY_LIST, DATE_LIST};

typedef struct
{
  s_Date date;
  T_TypeList list;
}T_ViewList;



//====================================================================
// ---------------------- interface ----------------

AnsiString Months[] = {"января","февраля","марта", "апреля",
                           "мая", "июня", "июля", "августа",
                           "сентября", "октября", "ноября", "декабря"};


AnsiString WeekFDay[] = {"Понедельник",
                         "Вторник",
                         "Среда",
                         "Четверг",
                         "Пятница",
                         "Суббота",                                
                         "Воскресенье"};


// ------------- control time choice
bool fix_inc_hour, fix_dec_hour, fix_inc_min, fix_dec_min;

T_ViewList ShowList;    //  witch Schedule shown

bool NewDayCheck;  // flag to check days change
bool IsHolyDay;


//--------------- envirounment
AnsiString wdir;  // work directory

vector <t_SoundFileList> SoundFiles; // list of all existing sound files
T_SoundFiles  UseSoundFiles;     // used sound defined files

TIniFile * ini_file;
AnsiString WorkScheduleFile;

//--------------- Schedule
T_EventList BaseEventList;   // all events
T_EventList TodayEventList;  // today events
T_EventList EditEventList;   // edit day events
T_EventList DateEventList;   // view day events

//--------------- work states
bool StartWork; // init period for timer

bool DeleteMode; // delete event mode
unsigned TimeChoice; // delay for user's hold mousebutton down
bool GridGetMouse;
unsigned SelGridRow; // choosen  event
int DelNumEvent;

bool stop_process;   // flag to stop cycling process

T_SupportPlan sup_plan;



unsigned f_hour, f_min;



//===================================================
//==================== RING online===================
bool RingAutoControl;        // enable flag for auto control RING

AnsiString CommName;         // active COM
bool CheckRingDelay;
unsigned int EventRingTime;  // delay counter for ring
unsigned int CheckRingTime;  // delay counter for check ring




//================================================================
// ============== User Functions =================================

void NowString(AnsiString & date,AnsiString & time)
{
 AnsiString str_date, str_time, str_buf;
 TDateTime dt;
 unsigned short n_year, n_mon, n_day, n_wd;
 unsigned short n_hour, n_min, n_sec, n_msec;


 dt = Now();
 dt.DecodeDate(&n_year,&n_mon,&n_day);
 dt.DecodeTime(&n_hour,&n_min,&n_sec,&n_msec);
 n_wd = dt.DayOfWeek();
 if(n_wd == 1) n_wd = 6; else n_wd -=2;

 str_date=""; str_time="";

 str_date=IntToStr(n_day);

// if(n_mon < 10) str_date=str_date+".0"+IntToStr(n_mon)+"."+IntToStr(n_year);
//   else str_date=str_date+"."+IntToStr(n_mon)+"."+IntToStr(n_year);
 str_date = str_date + " " + Months[n_mon-1] + " " + IntToStr(n_year);

 str_date=str_date+" "+WeekFDay[n_wd];


 str_time=IntToStr(n_hour);
 if (n_min < 10 )  str_time=str_time+":0";
   else str_time=str_time+":";
 str_time=str_time+IntToStr(n_min);
 //if (n_sec < 10 )  str_time=str_time+":0";
 //  else str_time=str_time+":";
// str_time=str_time+IntToStr(n_sec);

 date = str_date;
 time = str_time;
}
//=========================================================

//=========================================================
//============== SUPPORT
int InitSupPlan()
{
  sup_plan.sup_state = true;
  for( unsigned int i = 0; i<SUPPORT_PLAN_SIZE; i++)
  {
    sup_plan.sup_steps[i] = true;
  }
  return 0;
}
//=======================================================

int SetSupFail(T_SUP_STEPS item)
{
 sup_plan.sup_state = false;
 sup_plan.sup_steps[item] = false;

 return 0;
}

int SetSupClear(T_SUP_STEPS item)
{
  sup_plan.sup_steps[item] = true;
  sup_plan.sup_state = true;

  for( unsigned int i = 0; i<SUPPORT_PLAN_SIZE; i++)
  {
   sup_plan.sup_state *= sup_plan.sup_steps[i];
  }
  return 0;
}
//=====================================================

void ShowSupResults(bool in_win)
{
  AnsiString ws;
  int i;

  if(!sup_plan.sup_state)  // sup_state = false - there are problems
  {
    if(MainForm->DefShowWarnWindow->Checked)
    {
      MessWindow->UnSetWarn->Visible = true;
      MessWindow->UnSetWarn->Checked = false;
    }
    else
    {
      in_win = false;
      MessWindow->UnSetWarn->Visible = false;
    }

    if( in_win )
    {
      MessWindow->Caption = "Внимание!";
      MessWindow->Button->Caption = "Закрыть";
      MessWindow->Memo1->Clear();
    }

    for( i=0; i<SUPPORT_PLAN_SIZE; i++)
    {
      if(!sup_plan.sup_steps[i])
      {
        MainForm->Memo1->Lines->Add(SupMess[i]);
        MainForm->Memo1->Lines->Add("---------");
        if(in_win)
        {
          MessWindow->Memo1->Lines->Add(SupMess[i]);
          MessWindow->Memo1->Lines->Add("---------");
        }
      }
    }

    if(in_win)
    {
       MessWindow->Memo1->Lines->Add("\n-------------------------------------------------");
       MessWindow->Memo1->Lines->Add("\n\n Если нужна помощь, сообщите нам: info@kbret.ru");
       MessWindow->Visible = true;
    }

  }//sup state
}
//=========================================================

void UpSetWarning(bool in_off)
{
 if (in_off) MainForm->DefShowWarnWindow->Checked = false;
}
//=============================================================

void ShowStatus(AnsiString in_pre, int in_r_state)
{
 AnsiString as_buf;

 if(in_r_state == R_CLEAR) as_buf = "Состояние не определено";
 if(in_r_state == R_OK) as_buf = "Операция выполнена";
 if(in_r_state == R_ALLOCMEM_ERROR) as_buf = "Ошибка выделения памяти";
 if(in_r_state == R_COMM_ERROR) as_buf = "Ошибка СОМ порта";
 if(in_r_state == R_KVITANCE_ERROR) as_buf = "Квитанция Ring не верна";
 if(in_r_state == R_RING_FAIL) as_buf = "Отказ Ring";
 if(in_r_state == R_NO_FILE) as_buf = "Файл не найден";
 if(in_r_state == R_FILE_EMPTY) as_buf = "Файл пуст";
 if(in_r_state == R_READ_FILE_ERROR) as_buf = "Ошибка чтения файла";
 if(in_r_state == R_NO_OLD_FILES) as_buf = "Файлы старого формата не найдены";

 MainForm->StatusBar1->Panels->Items[0]->Text = in_pre +" : " +as_buf;
}
//==========================================================

void ShowStatus(AnsiString in_status)
{
 MainForm->StatusBar1->Panels->Items[0]->Text = in_status;
}
//==========================================================


//=============================================================================
//===========================  EVENT BASE
void SaveBase(AnsiString in_SchedFile)
{
  AnsiString rec;
  TFileStream * s_file;
  unsigned i;
  T_ListItem* item;

  vector <AnsiString>::iterator it_mess;

  if(BaseEventList.size > 0)
  {
    s_file = new TFileStream(in_SchedFile,fmCreate|fmOpenWrite|fmShareExclusive);
    s_file->Seek(0,0);

    item = BaseEventList.first;

    for(i=0; i<BaseEventList.size; i++)
    {
      rec = "#\n";
      s_file->Write(rec.c_str(),rec.Length());

      rec = IntToStr(item->event.start_date.year) + " ";                  // DEF_PARAMETERS_COUNT - 1
      rec = rec + IntToStr(item->event.start_date.month) + " ";
      rec = rec + IntToStr(item->event.start_date.day) + " ";
      rec = rec + IntToStr(item->event.start_date.weekday) + " ";
      rec = rec + IntToStr(item->event.start_date.use_year) + " ";
      rec = rec + IntToStr(item->event.start_date.use_month ) + " ";
      rec = rec + IntToStr(item->event.start_date.use_day ) + " ";
      rec = rec + IntToStr(item->event.start_date.use_weekly ) + " ";
      rec = rec + IntToStr(item->event.start_date.exclusive_day ) + " ";

      rec = rec + IntToStr(item->event.start_time.use_hour) + " ";        // DEF_PARAMETERS_COUNT - 10
      rec = rec + IntToStr(item->event.start_time.use_minute) + " ";
      rec = rec + IntToStr(item->event.start_time.use_second) + " ";
      rec = rec + IntToStr(item->event.start_time.hour) + " ";
      rec = rec + IntToStr(item->event.start_time.minute) + " ";
      rec = rec + IntToStr(item->event.start_time.second) + " ";

      rec = rec + IntToStr(item->event.cycle_flags.all_flags) + " ";     // DEF_PARAMETERS_COUNT - 16
      rec = rec + IntToStr(item->event.event_sign.all_signs) + " ";

      rec = rec + "1\n";                            // DEF_PARAMETERS_COUNT - 18
      s_file->Write(rec.c_str(),rec.Length());

      rec = AnsiString(item->event.sound) + "\n";
      s_file->Write(rec.c_str(),rec.Length());

      rec = AnsiString(item->event.caption) + "\n";
      s_file->Write(rec.c_str(),rec.Length());
/*
      while(it_mess != iter->Message.end())
      {

       rec = *it_mess + "\n";
       s_file->Write(rec.c_str(),rec.Length());
       ++it_mess;
      }

 */
      item = item->next;
      if(item == NULL) break;
     }
    s_file->Free();
   }
}
//=========================================================

int AddSoundList(AnsiString & sound_file)
{
 vector<t_SoundFileList>::iterator iter = SoundFiles.begin();
 t_SoundFileList ex_file;

 bool find_rec=false;

 ex_file.full_name = sound_file;
 ex_file.file_name = ExtractFileName(sound_file);

 while ( iter != SoundFiles.end() )
   {
    if (iter->file_name.AnsiCompareIC(ex_file.file_name) == 0 )
       find_rec=true;
    ++iter;
   }

 if (!find_rec)
   SoundFiles.push_back(ex_file);

 return 0;
}
//=======================================================================

unsigned int OpenSchedule(AnsiString in_SchedFile, T_EventList* out_base)
{
  TFileStream  * tfile;
  char* virtual_file;

  tfile=new TFileStream(in_SchedFile,fmOpenReadWrite);

  if(tfile->Size == 0)
  {
    tfile->Free();
    MainForm->Memo1->Lines->Add("Файл расписания пуст");
    SetSupFail(SUP_SCHED_EMPTY);

    return R_FILE_EMPTY;
  }

  tfile->Seek(0,0);
  virtual_file = (char *) malloc(tfile->Size);

  if( virtual_file == NULL )
  {
    tfile->Free();
    MainForm->Memo1->Lines->Add("Ошибка выделения памяти virtual_file");
    return R_ALLOCMEM_ERROR;
  }

  tfile->Read(virtual_file,tfile->Size);
  MainForm->Memo1->Lines->Add("Get virtual_file");

  EventList_ReadMem(virtual_file, tfile->Size, out_base);

  free(virtual_file);
  tfile->Free();

  return R_OK;
}
//=======================================================================


unsigned int OpenOldSchedule(AnsiString in_SchedFile, T_EventList* out_base)
{
  int i,j,k,reccount, wd, num, i_ch;
  unsigned int res;
  AnsiString bs,ws,str_buf, w_file;
  bool variants[100];
  int Founded_rec;
  Ti_Event temp_list[MAX_OLD_EVENTS+1]; // thought that they have 2 variants per day
  bool correct_event;

  t_OldActiveEvent active_rxx[7];


  for(i=0; i<MAX_OLD_EVENTS+1; i++)
  {
    k = NewEvent(&temp_list[i]);
    if(k == EL_RES_ALLOCMEM_ERROR) return R_ALLOCMEM_ERROR;
    InitEvent(&temp_list[i]);
  }

  EventList_clear(out_base);

  k=0;
  Founded_rec = 0;
  res=0;

  // Search for all rxx files
  for(i=0;i<100;i++)
  {
    variants[i]=false;
    bs = IntToStr(i);
    if(i<10) ws="r0"+bs+".txt";
        else ws="r"+bs+".txt";
    MainForm->Memo1->Lines->Add("Ищем файл "+ws+"...");

    if( FileExists(ws) )
    {
      reccount = 0; // quantity of events in this file

      MainForm->Memo1->Lines->Add("Найден файл "+ws);
      MainForm->Memo2->Lines->Clear();
      MainForm->Memo2->Lines->LoadFromFile(ws);

      if(MainForm->Memo2->Lines->Count>0) // read header
      {
        bs=MainForm->Memo2->Lines->Strings[0];

        if(bs.Length()>=8) // name of plan
        {
          ws=bs.SubString(1,8);
          j=ws.AnsiPos("^");
          if(j >= 1) ws = ws.SubString(1,j-1);
        }
        else
        {
          ws="-";
          MainForm->Memo1->Lines->Add(IntToStr(i)+"file: read header failed");
        }
        MainForm->Memo1->Lines->Add(IntToStr(i)+"file: read header = "+ws);

        if(bs.Length()>=11) // events quantity in the plan - reccount
        {
          ws=bs.SubString(9,3);
          j=ws.AnsiPos("^");
          if(j >= 1) ws = ws.SubString(1,j-1);

          if(TryStrToInt(ws,reccount))
          {
            if(reccount<=0) reccount = 0;
          }
          else
          {
            reccount = 0;
            MainForm->Memo1->Lines->Add(IntToStr(i)+"file: int counter failed");
          }
        }
        else
        {
          ws="-";
          MainForm->Memo1->Lines->Add(IntToStr(i)+"file: read counter failed");
        }
        MainForm->Memo1->Lines->Add(IntToStr(i)+"file: read counter = "+ws);
      } // header line

      // read events
      if(reccount != 0)
      {
        for(k=1;k<=reccount;k++)
        {
          if(Founded_rec>=MAX_OLD_EVENTS) // limit for all old events
          {
            MainForm->Memo1->Lines->Add("Out of temp "+MAX_OLD_EVENTS);
            break;
          }

          if(MainForm->Memo2->Lines->Count > k)
          {
            bs=MainForm->Memo2->Lines->Strings[k];

            if(bs.Length()>=14)
            {
              correct_event=true;

              ws=bs.SubString(1,2); // hours
              if(TryStrToInt(ws,j))
              {
                if(j>=0 && i<24)
                {
                  temp_list[Founded_rec].start_time.hour = j;
                } else correct_event = false;
              } else correct_event = false;

              ws=bs.SubString(3,2); // minutes
              if(TryStrToInt(ws,j))
              {
                if(j>=0 && i<60)
                {
                  temp_list[Founded_rec].start_time.minute = j;
                } else correct_event = false;
              } else correct_event = false;

              ws=bs.SubString(5,8); // sound file without type
              j=ws.AnsiPos("^");
              if(j >= 1) ws = ws.SubString(1,j-1);
              //remove space chars
              while (ws.AnsiPos(" ") != 0 ) ws.Delete(ws.AnsiPos(" "),1);

              if(ws.Length()>0)
              {
                str_buf = ExtractFileExt(ws);
                if(str_buf == "") ws = ws+".mp3";
                temp_list[Founded_rec].sound=ws.c_str();

                if(FileExists(ws))
                {
                  AddSoundList(ws);
                  temp_list[Founded_rec].event_sign.el.is_sound = 1;
                }
                else
                {
                  MainForm->Memo1->Lines->Add("Звуковой файл "+ws+" не найден");
                }
              }

              ws=bs.SubString(13,2); // ring delay time
              if(TryStrToInt(ws,j))
              {
                if(j>=0 && i<100)
                {
                  temp_list[Founded_rec].event_sign.el.ring_time = j;
                  if(j>0) temp_list[Founded_rec].event_sign.el.is_ring = 1;
                } else correct_event = false;
              } else correct_event = false;

              if(correct_event)
              {
                temp_list[Founded_rec].cycle_flags.el.id_rfile = i;
                //MainForm->Memo1->Lines->Add(IntToStr(i)+"file: new event: "+IntToStr(k));
                //MainForm->Memo1->Lines->Add(IntToStr(k)+"event: hour "+IntToStr(temp_list[Founded_rec].start_time.alltime.el.hour));
                //MainForm->Memo1->Lines->Add(IntToStr(k)+"event: min "+IntToStr(temp_list[Founded_rec].start_time.alltime.el.minute));
                //MainForm->Memo1->Lines->Add(IntToStr(k)+"event: file "+temp_list[Founded_rec].message_file);
                //MainForm->Memo1->Lines->Add(IntToStr(k)+"event: ring time "+IntToStr(temp_list[Founded_rec].event_sign.el.ring_time));

                Founded_rec++;
                variants[i] = true; // at least one rec is enable
              }
            }
            else
            {
              MainForm->Memo1->Lines->Add(IntToStr(i)+"file: wrong rec "+IntToStr(k));
            } // correct row
          }// if < Lines->Count
        }//for k  events in file
      }// reccount
      else
      {
        variants[i] = false;
        MainForm->Memo1->Lines->Add(IntToStr(i)+"file: empty");
      }
    }//open file rxx
  }//for rii files

  //Results: we have quantity of events from all rxx files  - Founded_rec
  //         we have list of rxx files - temp_list[Founded_rec]
  MainForm->Memo1->Lines->Add("Founded "+IntToStr(Founded_rec)+"events");

  if(Founded_rec == 0)
  {
    MainForm->Memo1->Lines->Add("Файлы расписания rxx не найдены или повреждены");
    SetSupFail(SUP_IS_RSCHED_FILE);
  }
  else
  {
    res |= IS_RXX_FILES;
  }// if Founded_rec

  if( FileExists(OLD_WEEK_FILE) )
  {
    res |= IS_WEEK_FILE;

    MainForm->Memo2->Lines->Clear();
    MainForm->Memo2->Lines->LoadFromFile(OLD_WEEK_FILE);

    //init week set - witch of rxx files are used
    for(i=0;i<7;i++)
    {
      active_rxx[i].used = false;
      active_rxx[i].FileNumber = 0;
      for(j=0;j<7;j++) active_rxx[i].in_weekday[j] = false;
    }

    for(k=1;k<=7;k++)   // check out week days
    {
      if(MainForm->Memo2->Lines->Count > k-1)
      {
        bs=MainForm->Memo2->Lines->Strings[k-1];
        MainForm->Memo1->Lines->Add("Week day "+IntToStr(k)+" - "+bs);

        if(bs.Length()>=6)
        {
          ws=bs.SubString(3,2); // file number
          if(TryStrToInt(ws,j))
          {
            if(j>=0 && j<100)
            {
              reccount = k-1;

              // find already used file rxx
              for(i=0;i<7;i++)
              {
                if( (active_rxx[i].used) && (active_rxx[i].FileNumber == j) )
                { reccount = i; }
              }

              active_rxx[reccount].used = true;
              active_rxx[reccount].FileNumber = j;
              active_rxx[reccount].in_weekday[k-1] = true;  // rjj used in this week day

              MainForm->Memo1->Lines->Add("R "+IntToStr(j)+" are used at "+IntToStr(k));
            }
            else
            {
              MainForm->Memo1->Lines->Add("Week day "+IntToStr(k)+" - filename outrange");
            }
          }
          else
          {
            MainForm->Memo1->Lines->Add("Week day "+IntToStr(k)+" - filename failed");
          }
        }
        else
        {
          MainForm->Memo1->Lines->Add("Week day "+IntToStr(k)+" - failed");
        }
      } // if < Lines->Count
    } //for k

    // Result: we got list of used rxx files - active_rxx[i]
    // and how they being used per week

    for(i=0;i<7;i++)
    {
      if( active_rxx[i].used )
      {
        MainForm->Memo1->Lines->Add("R "+IntToStr(active_rxx[i].FileNumber)+" split at: ");

        // Mark events that stored in active rxx files   as  active
        // and set in what days of week they will be showed

        for(k=0;k<Founded_rec;k++)
        {
          if(temp_list[k].cycle_flags.el.id_rfile == active_rxx[i].FileNumber)
          {
            temp_list[k].cycle_flags.el.is_event_active = 1;

            for(j=0;j<7;j++)
            {
              if( active_rxx[i].in_weekday[j] )
              {
                temp_list[k].start_date.use_weekly = true;
                temp_list[k].start_date.weekday |= (1 << j);

                wd = temp_list[k].start_date.weekday;
                MainForm->Memo1->Lines->Add("Event "+IntToStr(k+1)+"at day : "+IntToStr(j+1)+"("+IntToHex(wd,2)+")");
              }
            }//for
          }// if non hidden
        } //for all k events
      } // rii used
    }// for active rii
  }
  else
  {
    MainForm->Memo1->Lines->Add("Файл расписания day.txt не найден");
    SetSupFail(SUP_IS_DSCHED_FILE);
  }

  // get exclusive events
  if( FileExists(OLD_EX_FILE) )
  {
    res |= IS_EX_FILE;
    MainForm->Memo2->Lines->Clear();
    MainForm->Memo2->Lines->LoadFromFile(OLD_EX_FILE);

    for(i=0;i<MainForm->Memo2->Lines->Count;i++)
    {
      bs=MainForm->Memo2->Lines->Strings[i];

      MainForm->Memo1->Lines->Add("Ex "+IntToStr(i+1)+" "+bs);
      //correct_event=false;

      // make event
      InitEvent(&temp_list[MAX_OLD_EVENTS]);
      if(bs.Length()>=8)
      {
        ws=bs.SubString(1,2); // day
        if(TryStrToInt(ws,j))
        {
          if(j == 0) break;
          if(j>0 && j<32)
          {
            temp_list[MAX_OLD_EVENTS].start_date.use_day = true;
            temp_list[MAX_OLD_EVENTS].start_date.day = j;

           // correct_event=true;
            MainForm->Memo1->Lines->Add("Ex "+IntToStr(i+1)+" day "+IntToStr(j));
          } else break;
        } else break;

        ws=bs.SubString(3,2); // mounth
        if(TryStrToInt(ws,j))
        {
          if(j == 0) break;
          if(j>0 && j<13)
          {
            temp_list[MAX_OLD_EVENTS].start_date.use_month = true;
            temp_list[MAX_OLD_EVENTS].start_date.month = j;

            //correct_event=true;
            MainForm->Memo1->Lines->Add("Ex "+IntToStr(i+1)+" mon "+IntToStr(j));
          } else break;
        }else break;

        ws=bs.SubString(7,2); // rxx
        if(TryStrToInt(ws,j))
        {
          if( j>=0 && j<100 && variants[j] )
          {
            temp_list[MAX_OLD_EVENTS].cycle_flags.el.id_rfile = j;
            //correct_event=true;
            MainForm->Memo1->Lines->Add("Ex "+IntToStr(i+1)+" R "+IntToStr(j));
          }
        }else break;

        // save exclusive day as event
        temp_list[MAX_OLD_EVENTS].start_date.exclusive_day = 1;
        if(temp_list[MAX_OLD_EVENTS].caption != NULL)
          strcpy(temp_list[MAX_OLD_EVENTS].caption, "Праздник");

        temp_list[MAX_OLD_EVENTS].event_sign.el.is_text = 1;
        temp_list[MAX_OLD_EVENTS].cycle_flags.el.is_event_active = 1;
        temp_list[MAX_OLD_EVENTS].start_time.use_hour = false;
        temp_list[MAX_OLD_EVENTS].start_time.use_minute = false;
        temp_list[MAX_OLD_EVENTS].start_time.use_second = false;

        EventList_push(out_base,&temp_list[MAX_OLD_EVENTS]);
        MainForm->Memo1->Lines->Add("Add Ex "+bs+" to Base");

        if(temp_list[MAX_OLD_EVENTS].cycle_flags.el.id_rfile != -1)
        {
          // save events from rxx file as exclusive
          for(k=0;k<Founded_rec;k++)
          {
            if(temp_list[k].cycle_flags.el.id_rfile == temp_list[MAX_OLD_EVENTS].cycle_flags.el.id_rfile)
            {
              temp_list[MAX_OLD_EVENTS].start_time = temp_list[k].start_time;
              temp_list[MAX_OLD_EVENTS].event_sign = temp_list[k].event_sign;
              temp_list[MAX_OLD_EVENTS].event_sign.el.is_text = 1;
              temp_list[MAX_OLD_EVENTS].cycle_flags.el.even_in_exclusive = 1;

              if(temp_list[k].sound[0] != 0)
              {
                if(temp_list[MAX_OLD_EVENTS].sound != NULL)
                  strcpy(temp_list[MAX_OLD_EVENTS].sound, temp_list[k].sound);
                temp_list[MAX_OLD_EVENTS].event_sign.el.is_sound = 1;
              }
              if(temp_list[MAX_OLD_EVENTS].caption != NULL)
                strcpy(temp_list[MAX_OLD_EVENTS].caption, "Сигнал");

              EventList_push(out_base, &temp_list[MAX_OLD_EVENTS]);
              MainForm->Memo1->Lines->Add("Add event of Ex "+bs+" to Base");
            }
          }// for k events
        }// if rxx exists
      }// good rec
      else
      {
        MainForm->Memo1->Lines->Add("Wrong ex file "+bs);
        break;
      }
    }//for i records
  }// OLD EX EVENTS
  else
  {
    MainForm->Memo1->Lines->Add("Файл исключений ex.txt не найден");
    SetSupFail(SUP_IS_EXSCHED_FILE);
  }

  // Add all founded simple events to Base
  for(k=0;k<Founded_rec;k++)
  {
    if(temp_list[k].cycle_flags.el.id_rfile != -1)
    {
      temp_list[k].start_date.use_day=false;
      if (temp_list[k].caption[0] == 0) strcpy(temp_list[k].caption, temp_list[k].sound);

      EventList_push(out_base, &temp_list[k]);
      MainForm->Memo1->Lines->Add("Add event "+IntToStr(k+1)+" to Base");
      MainForm->Memo1->Lines->Add("Size of Base "+IntToStr(out_base->size));
    }
  }// for k events

  SaveBase(in_SchedFile);
  MainForm->Memo1->Lines->Add("Size of BaseEvent "+IntToStr(out_base->size));

  for(i=0; i<MAX_OLD_EVENTS+1; i++)
  {
    FreeEvent(&temp_list[i]);
  }

  if(res == 0)
  {
    SetSupFail(SUP_IS_SCHED_FILE);
    return R_NO_FILE;
  }
  else
  {
    if(  ((res & ~IS_RXX_FILES) == 0)
       ||((res & ~IS_WEEK_FILE) == 0)
       ||((res & ~IS_EX_FILE) == 0)
      )
    return R_NO_OLD_FILES;
  }

  return R_OK;
} // OpenOldSchedule()
//=========================================================

unsigned int OpenFiles(T_SoundFiles * set)
{
  AnsiString d_file,w_file;
  unsigned int res =  R_OK;

  if(FileExists("manual.txt"))
  {
    SetSupClear(SUP_IS_MANUAL);
    MainForm->Manual->Lines->LoadFromFile("manual.txt");
  }
  else
  {
    SetSupFail(SUP_IS_MANUAL);
    res = R_NO_FILE;
  }

  d_file = DEF_ALARM_SOUND;
  if( FileExists(d_file) )
  {
    AddSoundList(d_file);
  }
  else
  {
    MainForm->Memo1->Lines->Add(" Файл "+d_file+" не найден");
    SetSupFail(SUP_IS_DALARM_FILE);
    res = R_NO_FILE;
  }

  w_file = set->SetAlarmFile;
  if(w_file != d_file )
  {
    if( FileExists(w_file) )
    {
      AddSoundList(w_file);
    }
    else
    {
      MainForm->Memo1->Lines->Add(" Файл "+w_file+" не найден");
      SetSupFail(SUP_IS_UALARM_FILE);
      res = R_NO_FILE;
    }
  }

  d_file = DEF_FIRE_SOUND;
  if( FileExists(d_file) )
  {
    AddSoundList(d_file);
  }
  else
  {
    MainForm->Memo1->Lines->Add(" Файл "+d_file+" не найден");
    SetSupFail(SUP_IS_DFIRE_FILE);
    res = R_NO_FILE;
  }

  w_file = set->SetFireFile;
  if(w_file != d_file )
  {
    if( FileExists(w_file) )
    {
      AddSoundList(w_file);
    }
    else
    {
      MainForm->Memo1->Lines->Add(" Файл "+w_file+" не найден");
      SetSupFail(SUP_IS_UFIRE_FILE);
      res = R_NO_FILE;
    }
  }

  d_file = DEF_RING_SOUND;
  if( FileExists(d_file) )
  {
    AddSoundList(d_file);
  }
  else
  {
    MainForm->Memo1->Lines->Add(" Файл "+d_file+" не найден");
    SetSupFail(SUP_IS_DRING_FILE);
    res = R_NO_FILE;
  }

  w_file = set->SetRingFile;
  if(w_file != d_file )
  {
    if( FileExists(w_file) )
    {
      AddSoundList(w_file);
    }
    else
    {
      MainForm->Memo1->Lines->Add(" Файл "+w_file+" не найден");
      SetSupFail(SUP_IS_URING_FILE);
      res = R_NO_FILE;
    }
  }


  return res;
} // OpenFiles()
//=========================================================


void ShowBase()
{
  int i, CurRow;
  AnsiString str_date, str_time, str_buf;

  T_EventList* e_list;
  T_ListItem* item;

  T_Date in_date;
  T_Time in_time;

#ifdef GRID_TITLE
   MainForm->CurrentBase->RowCount = 2;
#else
   MainForm->CurrentBase->RowCount = 1;
#endif

  if(ShowList.list == BASE_LIST)
  {
    e_list = &BaseEventList;
  }
  else
  {
    if(ShowList.list == DATE_LIST)
    {
      e_list = &DateEventList;
    }
    else
    {
      e_list = &TodayEventList;
    }

    in_date.year = ShowList.date.year;
    in_date.use_year = true;
    in_date.month = ShowList.date.month;
    in_date.use_month = true;
    in_date.day = ShowList.date.day;
    in_date.use_day = true;
    in_date.weekday = ShowList.date.weekday;
    in_date.use_weekly = true;
    in_time.use_hour = false;
    in_time.use_minute = false;
    in_time.use_second = false;

    MomentToStr(in_date, item->event.start_time, &str_date, &str_time);
#ifdef GRID_TITLE
   MainForm->CurrentBase->Cells[1][0] = "События на: " + str_date;
#endif
  }




  if( e_list->size > 0)
  {
#ifdef GRID_TITLE
   MainForm->CurrentBase->RowCount = e_list->size + 1;
   CurRow=1;
#else
   MainForm->CurrentBase->RowCount = e_list->size;
   CurRow=0;
#endif
    item = e_list->first;
    for(i=0; i<e_list->size; i++)
    {
      MomentToStr(item->event.start_date, item->event.start_time, &str_date, &str_time);

      if(str_date != "")
      {
        if(str_time != "") str_date = str_date+" - "+str_time;
      }
      else
      {
        if(str_time != "") { str_date = str_time; }
      }
      MainForm->CurrentBase->Cells[0][CurRow] = str_date;

      if(item->event.caption != NULL)
      {
        MainForm->CurrentBase->Cells[1][CurRow] = AnsiString(item->event.caption);
      }
      else
      {
        if(item->event.sound != NULL)
          MainForm->CurrentBase->Cells[1][CurRow] = AnsiString(item->event.sound);
      }
      MainForm->CurrentBase->Cells[2][CurRow] = IntToStr(item->event.cycle_flags.el.id_event);

      ++CurRow;

      item = item->next;

      if(item == NULL) break;
    } // for
  }
  else
  {
#ifdef GRID_TITLE
     MainForm->CurrentBase->Cells[0][1] = "";
     MainForm->CurrentBase->Cells[1][1] = "Добавьте событие...";
     MainForm->CurrentBase->Cells[2][1] = "";
#else
     MainForm->CurrentBase->Cells[0][0] = "";
     MainForm->CurrentBase->Cells[1][0] = "Добавьте событие...";
     MainForm->CurrentBase->Cells[2][0] = "";
#endif
  }

}
//=========================================================



//==========================================================
//================ RING IO =================================

void FindComm()
{
  unsigned int i,j;
  AnsiString ws;

  InitCOM();
  MainForm->COMList->Items->Clear();

  i = GetCOMCount();
  for(j=0;j<i;j++)
  {
    ws = GetCOMItem(j);
    MainForm->COMList->Items->Add(ws);
  }

  if(i==0)
  {
    SetSupFail(SUP_IS_COMM);

    MainForm->COMList->Items->Add(COM_EMPTY_ITEM);
    MainForm->COMConnect->Caption = "Поиск СОМ";
    MainForm->StatusBar1->Panels->Items[0]->Text = SupMess[SUP_IS_COMM];
  }
  else
  {
    MainForm->COMConnect->Caption = "Подключение";
    MainForm->StatusBar1->Panels->Items[0]->Text = "Обнаружено "+IntToStr(i)+" СОM портов";
    SetSupClear(SUP_IS_COMM);
  }
  
  MainForm->COMList->ItemIndex = 0;
}
//=======================================================================

int LinkCOM(AnsiString in_comname)
{
  T_Result COMres;
  unsigned int num_port, port_speed;
  unsigned char data_size, parity;


  port_speed = CBR_115200;
  data_size = DEF_COMM_DATA_SIZE;
  parity = DEF_COMM_PARITY;

  COMres = OpenCOMPort(in_comname, port_speed, data_size, parity, ONESTOPBIT);

  if(COMres == COM_OK)
  {
    MainForm->StatusBar1->Panels->Items[0]->Text = in_comname+" открыт";
    MainForm->COMConnect->Caption = "Отключить";
    MainForm->ButCommSetup->Enabled =true;

    CommName =  in_comname;
    SetSupClear(SUP_DEF_COMM);
  }
  else
  {
    MainForm->Memo1->Lines->Add(GetCOMStatus("LinkCOM ",COMres));
    MainForm->StatusBar1->Panels->Items[0]->Text = in_comname+" ошибка открытия: "+COMres;
    MainForm->COMConnect->Caption = "Подключение";
    MainForm->ButCommSetup->Enabled =false;
  }

  return COMres;
}
//=========================================================================


int SendToRing( void* in_code,
                unsigned int in_size,
                void* in_kvit_code,
                unsigned int in_kvit_size,
                T_Result * out_res)

{
 AnsiString as_buf;
 DWORD sended;
 unsigned int i,j, iter;
 T_Result res;

 unsigned char* io_buf = NULL;

 stop_process = false;

 sended = 0;
 MainForm->Memo1->Lines->Add("Send kodoram: size "+IntToStr(in_size));
// if(in_size > 20) j = 20;
// else
 j = in_size;

 as_buf = "";
 for(i=0; i<j; i++)
 {
  as_buf = as_buf + IntToHex(((unsigned char*)in_code)[i],2) + " : ";
 }
  MainForm->Memo1->Lines->Add(as_buf);

 res = TransmitComPort(in_code, in_size, &sended);

 *out_res = res;
 if(res != COM_OK)
   {
    MainForm->Memo1->Lines->Add("WriteComPort: Ошибка отправки "+IntToStr(*out_res));
    return R_COMM_ERROR;
   }

 if(in_kvit_size != 0) // need confirmation
   {
    sended = 0;
    iter = 30;

    while ( (iter !=0) && (sended == 0) && !stop_process )
    {
      res = ReceiveComPort(in_kvit_code, in_kvit_size, &sended);
      as_buf = "Wait state: res ";
      as_buf += IntToStr((int)res);
      as_buf += " data ";
      as_buf += IntToStr(sended);
      MainForm->Memo1->Lines->Add(as_buf);
//    MainForm->Memo1->Lines->Add("GET data: ");
      as_buf = "";
      io_buf = (unsigned char*)in_kvit_code;
      for(i=0; i<sended; i++)
      {
        as_buf = as_buf + IntToHex((unsigned char)io_buf[i],2) + " : ";
      }
      MainForm->Memo1->Lines->Add(as_buf);

      --iter;
      Application->ProcessMessages();
    }

    *out_res = res;

    if(res != COM_OK)
      {
       MainForm->Memo1->Lines->Add("ReadComPort: Ring не отвечает ... ");
       return R_COMM_ERROR;
      }

   }// confirmation

 return R_OK;
}
//========================================================

int ReadFromRing( void* in_kvit_code,
                  unsigned int in_kvit_size,
                  T_Result * out_res)

{
  AnsiString as_buf;
  DWORD sended;
  unsigned int i,j, iter;
  T_Result res;

  unsigned char* uc_buf = NULL;

  /*  dont use malloc - it leads to troubles
  if( (io_buf = (char*) malloc(in_kvit_size)) == NULL )
  {
    MainForm->Memo1->Lines->Add("Ошибка выделения памяти для буфера");
    return R_ALLOCMEM_ERROR;
  }
  memset(io_buf,0,in_kvit_size);
 */

  sended = 0;
  iter = 20;

  while ( (iter !=0) && (sended == 0) && !stop_process )
  {
    res = ReceiveComPort(in_kvit_code, in_kvit_size, &sended);

    as_buf = "Wait state: res ";
    as_buf += IntToStr(res);
    as_buf += " data ";
    as_buf += IntToStr(sended);

    MainForm->Memo1->Lines->Add(as_buf);

    as_buf = "";
    i = sended / 4;
    uc_buf = (unsigned char*)in_kvit_code;
    if(i==0)
    {
      for(i=0; i<sended; i++)
      {
        as_buf = as_buf + IntToHex((unsigned char)uc_buf[i],2) + " : ";
      }
    }
    else
    {
      for(i=0; i<(sended /4); i++)
      {
        as_buf = as_buf + IntToHex((unsigned char)uc_buf[i*4],2)
                        + IntToHex((unsigned char)uc_buf[i*4 + 1],2)
                        + IntToHex((unsigned char)uc_buf[i*4 + 2],2)
                        + IntToHex((unsigned char)uc_buf[i*4 + 3],2)
                        + " : ";
      }
    }
    MainForm->Memo1->Lines->Add(as_buf);

    --iter;
    Application->ProcessMessages();
  }

  *out_res = res;

  if(res != COM_OK)
  {
    MainForm->Memo1->Lines->Add("ReadComPort: Ring не отвечает ... ");
    return R_COMM_ERROR;
  }

  return R_OK;
}
//========================================================

int GetTransmit()
{
  T_Result io_res;
  unsigned int res, iter;
  T_RingIO_Head ring_comm;
  T_RingIO_Status RingStatus;

  RingInitHead(&ring_comm, RING_ON_TRANSFER);
  iter = 0;
  stop_process = false;
  res = R_CLEAR;

  MainForm->Memo1->Lines->Add(" запуск трансляции от  Ring ");

  res = SendToRing(&ring_comm, sizeof(ring_comm), &RingStatus, sizeof(RingStatus),&io_res);

  if(res == R_OK)
  {
    while(!stop_process)
    {
      Application->ProcessMessages();
      iter++;

      res = ReadFromRing(&RingStatus, sizeof(RingStatus),&io_res);

      if(res == R_OK)
      {

      }// gfood read
      else
      {
        if(io_res != COM_OK)
          MainForm->Memo1->Lines->Add(IntToStr(iter)+": Ошибка COM порта ...");
      }

      MainForm->Memo1->Lines->Add(GetCOMStatus("Прием данных",io_res));
      Sleep(900);
    } //while
  }// gfood read
  else
  {
    if(io_res != COM_OK)
      MainForm->Memo1->Lines->Add(IntToStr(iter)+": Ошибка COM порта ...");
    return res;
  }

 MainForm->Memo1->Lines->Add(" конец трансляции  Ring ");

 return res;
}
//========================================================


int GetRingState()
{
  T_RingIO_Status RingStatus;
  T_RINGState  RingState;
  T_RingIO_Head ring_comm;

  T_Result io_res;
  unsigned int res;
  AnsiString as_buf, status;


  RingInitHead(&ring_comm, RING_GET_STATE);
  res = R_CLEAR;

  MainForm->Memo1->Lines->Add("Запрос состояния  Ring ");

  res = SendToRing(&ring_comm, sizeof(ring_comm), &RingStatus, sizeof(RingStatus),&io_res);

  if( io_res == COM_IO_ERROR || res == R_COMM_ERROR)
  {
    SetSupFail(SUP_RING_NO_ANSWER);
    MainForm->RingLinkState->Caption="нет связи";
  }

  as_buf = GetCOMStatus("Прием данных",io_res);
  MainForm->Memo1->Lines->Add(as_buf);

  if(res == R_OK && RingStatus.head.index == RING_GET_STATE)
  {
    SetSupClear(SUP_RING_NO_ANSWER);
    MainForm->RingLinkState->Caption="Связь установлена";

    RingState.all = RingStatus.data.data1;
    status = "Ring:";

    if(RingState.el.ready == RING_READY)
    {
      MainForm->ButStateRing->Font->Color = clGreen;
      status += "готов; ";
      SetSupClear(SUP_RING_SETUP);
      MainForm->RingModeState->Caption="Готов";
    }
    else
    {
      MainForm->ButStateRing->Font->Color = clRed;
      status += "режим настройки; ";
      SetSupFail(SUP_RING_SETUP);
      MainForm->RingModeState->Caption="Режим настройки";
    }

    status += "EMB RTS: ";
    as_buf = "Встроенные часы реального времени: ";
    switch(RingState.el.RTC_EMB_State)
    {
      case RTC_OK:
      {
        as_buf = as_buf + " работают "
                        + IntToStr(RingStatus.data.data2) + ":"
                        + IntToStr(RingStatus.data.data3) + ":"
                        + IntToStr(RingStatus.data.data4);
        status +="OK; ";
        MainForm->RingEmbRTC->Caption = "Работают "+ IntToStr(RingStatus.data.data2) + ":"
                                        + IntToStr(RingStatus.data.data3) + ":"
                                        + IntToStr(RingStatus.data.data4);
        break;
      }
      case RTC_RESET:
      {
        as_buf = as_buf + " не настроены "
                        + IntToStr(RingStatus.data.data2) + ":"
                        + IntToStr(RingStatus.data.data3) + ":"
                        + IntToStr(RingStatus.data.data4);
        status =status + "сброшены "
                       + IntToStr(RingStatus.data.data2) + ":"
                       + IntToStr(RingStatus.data.data3) + ":"
                       + IntToStr(RingStatus.data.data4);
        MainForm->RingEmbRTC->Caption = "Не настроены";
        break;
      }
      case RTC_NO:
      {
        as_buf = as_buf + " не найдены";
        status +="не найдены; ";
        MainForm->RingEmbRTC->Caption = "Не найдены";
        break;
      }
      default:
      {
        as_buf = as_buf + " состояние не определено "
                        + IntToStr(RingStatus.data.data2) + ":"
                        + IntToStr(RingStatus.data.data3) + ":"
                        + IntToStr(RingStatus.data.data4);
        status +="нет данных; ";
        MainForm->RingEmbRTC->Caption = "Нет данных";
      }
    }// switch
    MainForm->Memo1->Lines->Add(as_buf);

    status += "DS3231: ";
    as_buf = "Часы реального времени DS3231: ";
    switch(RingState.el.RTC_DS_State)
    {
      case RTC_OK:
      {
        as_buf = as_buf + " работают.";
        status += "работают. ";
        break;
      }
      case RTC_RESET:
      {
        as_buf = as_buf + " не настроены.";
        status += "сброшены; ";
        break;
      }
      case RTC_NO:
      {
        as_buf = as_buf + " не найдены";
        status +="не найдены; ";
        break;
      }
      default:
      {
        as_buf = as_buf + " состояние не определено ";
        status +="нет данных; ";
      }
    }// switch
    MainForm->Memo1->Lines->Add(as_buf);

    status += "Расписание: ";
    as_buf = "Расписание: ";
    switch(RingState.el.SchedFile)
    {
      case SCHED_NO:
      {
        as_buf = as_buf + " нет файла";
        status += "нет файла; ";
        break;
      }
      case SCHED_IS:
      {
        as_buf = as_buf + " во Flash памяти";
        status += "on Flash; ";
        break;
      }
      case SCHED_RAM:
      {
        as_buf = as_buf + "сохранено в RAM";
        status += "on RAM; ";
        break;
      }
      case SCHED_ON:
      {
        as_buf = as_buf + "в работе";
        status += "в работе; ";
        break;
      }
      default:
      {
        as_buf = as_buf + "нет данных";
        status += "нет данных; ";
        break;
      }
    }// switch
    MainForm->Memo1->Lines->Add(as_buf);


    ShowStatus(status);
  }// OK
  else
  {
    MainForm->Memo1->Lines->Add("Ошибка приема : "+IntToStr(res));
    MainForm->RingLinkState->Caption="нет связи";

    SetSupFail(SUP_RING_NO_ANSWER);
  }



  return res;
}
//========================================================

int TimeSync()
{
  T_Result io_res;
  unsigned int res= R_OK;

  TDateTime dt;
  unsigned short n_year, n_mon, n_day, n_wd;
  unsigned short n_hour, n_min, n_sec, n_msec;
  unsigned short start_sec;

  T_RingIO_Status SyncTime, kvSyncTime;


  dt = Now();
  dt.DecodeTime(&n_hour,&n_min,&n_sec,&n_msec);

  InitRingSyncTime(&SyncTime, 0, n_hour, n_min, n_sec);

  MainForm->Memo1->Lines->Clear();
  MainForm->Memo1->Lines->Add(" синхронизация времени... ");

  start_sec = n_sec;
  while(start_sec == n_sec )
  {
    dt = Now();
    dt.DecodeTime(&n_hour,&n_min,&n_sec,&n_msec);
    SyncTime.data.data4 = n_sec;
  }
  
  res = SendToRing(&SyncTime, sizeof(SyncTime), &kvSyncTime, sizeof(kvSyncTime), &io_res);
  MainForm->Memo1->Lines->Add(GetCOMStatus("Синхронизация секунд: ",io_res));

  if(res == R_OK)
  {
    dt.DecodeDate(&n_year,&n_mon,&n_day);
    dt.DecodeTime(&n_hour,&n_min,&n_sec,&n_msec);
    n_wd = dt.DayOfWeek();

    InitRingSyncTime(&SyncTime, 1, n_hour, n_min, n_wd);

    res = SendToRing(&SyncTime, sizeof(SyncTime), &kvSyncTime, sizeof(kvSyncTime), &io_res);
    MainForm->Memo1->Lines->Add(GetCOMStatus("Синхронизация времени: ",io_res));

    if(res == R_OK)
    {
      MainForm->Memo1->Lines->Add( "Установлено время: "
                                  +IntToStr(kvSyncTime.data.data1)+ ":"
                                  +IntToStr(kvSyncTime.data.data2)+ ":"
                                  +IntToStr(kvSyncTime.data.data3)
                                  +" WeekDay: "+ IntToStr(kvSyncTime.data.data4));

      InitRingSyncTime(&SyncTime, 2, n_year, n_mon, n_day);

      res = SendToRing(&SyncTime, sizeof(SyncTime), &kvSyncTime, sizeof(kvSyncTime), &io_res);
      MainForm->Memo1->Lines->Add(GetCOMStatus("Синхронизация даты: ",io_res));

      if(res == R_OK)
      {
        MainForm->Memo1->Lines->Add( "Установлена дата: "
                                  +IntToStr(kvSyncTime.data.data1)+ "."
                                  +IntToStr(kvSyncTime.data.data2)+ "."
                                  +IntToStr(kvSyncTime.data.data3)
                                  +" WeekDay: "+ IntToStr(kvSyncTime.data.data4));

      }
      else
      {
        MainForm->Memo1->Lines->Add( "Сбой синхронизации даты");
      }
    }
    else
    {
      MainForm->Memo1->Lines->Add( "Сбой синхронизации времени");
    }
  }
  else
  {
   MainForm->Memo1->Lines->Add( "Сбой синхронизации секунд ");
  }

  return res;
}
//========================================================

int SendSchedule(AnsiString in_SchedFile)
{
 T_Result io_res;
 unsigned int res;

 T_RingIO_SchData ring_data, kv_ring_data;
 T_RingIO_BlockInfo ring_block_info, kvring_block_info, kvblock_info;


 AnsiString as_buf;
 TFileStream  * tfile;
 char * virtual_file;
 unsigned int file_size, crc32_sum, sum_crc32;

 unsigned short block_count, tail_size, block_size, io_iter, buf_pointer;
 unsigned char io_buf[IO_BLOCK_SIZE] = {0};

 enum IO_State  io_state;

 io_state = SEND_COMM;

 MainForm->Memo1->Lines->Clear();
 MainForm->ProgressBar1->Position = 0;

 // open SCHEDULE_FILE
 as_buf = in_SchedFile;

 if( ! FileExists(as_buf) ) return R_NO_FILE;

 tfile=new TFileStream(as_buf,fmOpenReadWrite);

 if(tfile->Size == 0)
 {
   tfile->Free();
   return R_FILE_EMPTY;
 }

 tfile->Seek(0,0);

 virtual_file = (char *) malloc(tfile->Size);

 if( virtual_file == NULL )
   {
    tfile->Free();
    return R_ALLOCMEM_ERROR;
   }

 file_size = tfile->Size;
 tfile->Read(virtual_file,tfile->Size);
// == check of load
// as_buf.sprintf(virtual_file);
// MainForm->Memo1->Lines->Clear();
// MainForm->Memo1->Lines->Add(as_buf);

 // get CRC32
 crc32_sum = CRC32(virtual_file, tfile->Size);

 MainForm->Memo1->Lines->Add("передача информации о файле расписания ");
 MainForm->Memo1->Lines->Add("size = "+IntToStr(file_size));
 MainForm->Memo1->Lines->Add("crc32 = "+IntToHex((int)crc32_sum,8));

 InitExchSchedCom(&ring_data, file_size, crc32_sum);

 MainForm->ProgressBar1->StepIt();


 res = SendToRing( &ring_data, sizeof(ring_data),
                   &kv_ring_data, sizeof(ring_data), &io_res);

 if(res == R_OK)
  {
    if( memcmp(&ring_data, &kv_ring_data, sizeof(ring_data)) )
    {
      res = R_KVITANCE_ERROR;
      if((kv_ring_data.head.index & 0xFF00) == 0xEE00)
      {
        // ошибка программы Ring
        kv_ring_data.head.index &= 0xFF;
        if( !memcmp(&ring_data, &kv_ring_data, sizeof(ring_data)) ) // valid answer
         {
           MainForm->Memo1->Lines->Add("Сбой программы Ring");
           res = R_RING_FAIL;
         }
      }// get error  message

      if(res == R_KVITANCE_ERROR)
        {
          MainForm->Memo1->Lines->Add("Неверный ответ от Ring: ");
          MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_data.head.name,4)+" - "
                                         +"A: " +IntToHex(kv_ring_data.head.name,4)
                                        );
          MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_data.head.index,4)+" - "
                                         +"A: " +IntToHex(kv_ring_data.head.index,4)
                                        );
          MainForm->Memo1->Lines->Add( "S: " +IntToHex((int)ring_data.data.size,8)+" - "
                                         +"A: " +IntToHex((int)kv_ring_data.data.size,8)
                                        );
          MainForm->Memo1->Lines->Add( "S: " +IntToHex((int)ring_data.data.crc32,8)+" - "
                                         +"A: " +IntToHex((int)kv_ring_data.data.crc32,8)
                                        );
        }
    }
    else
    {
      MainForm->Memo1->Lines->Add("Квитанция о файле расписания ");
      MainForm->Memo1->Lines->Add("size = "+IntToStr(kv_ring_data.data.size));
      MainForm->Memo1->Lines->Add("crc32 = "+IntToHex((int)kv_ring_data.data.crc32,8));

      MainForm->Memo1->Lines->Add("Ring готов к синхронизации");
      MainForm->Memo1->Lines->Add("");
    }
  }// gfood read
  else
  {
   if(io_res != COM_OK) MainForm->Memo1->Lines->Add("Ошибка COM порта ...");
  }

  if(res != R_OK)
  {
    free(virtual_file);
    tfile->Free();
    return res;
  }

  block_count = file_size / IO_BLOCK_SIZE;
  tail_size  = file_size % IO_BLOCK_SIZE;
  io_iter = 1;
  buf_pointer = 0;

  if( block_count == 0)  block_size = tail_size;
                   else  block_size = IO_BLOCK_SIZE;

  if(tail_size > 0) block_count++;

  io_state = SEND_COMM;


  while(!stop_process && io_state != IDLE)
  {
    Application->ProcessMessages();
    Sleep(MainForm->COMDelayBF->Position);

    if(io_state == SEND_COMM)
    {
      MainForm->Memo1->Lines->Add("-------");
      MainForm->Memo1->Lines->Add("передача информации о блоке файла расписания "+IntToStr(io_iter) );

      memcpy(io_buf, virtual_file+buf_pointer, block_size);
      crc32_sum = CRC32(io_buf, block_size);
      InitBlockInfo(&ring_block_info, io_iter, block_size, crc32_sum);

      MainForm->Memo1->Lines->Add( "блок "+IntToStr(io_iter)
                                  +" siz - " +IntToStr(block_size)
                                  +" sum - " +IntToHex((int)crc32_sum,8)
                                 );


      res = SendToRing(&ring_block_info, sizeof(ring_block_info),
                       &kvring_block_info, sizeof(ring_block_info), &io_res);

      if(res == R_OK)
      {
        if( memcmp(&ring_block_info, &kvring_block_info, sizeof(ring_block_info)) )
        {
          res = R_KVITANCE_ERROR;
          if((kvring_block_info.head.index & 0xFF00) == 0xEE00)
          {
            // ошибка программы Ring
            kvring_block_info.head.index &= 0xFF;
            if( !memcmp(&ring_block_info, &kvring_block_info, sizeof(ring_block_info)) ) // valid answer
            {
              MainForm->Memo1->Lines->Add("Сбой программы Ring");

              res = R_RING_FAIL;
            }
          }// get error  message

         if(res == R_KVITANCE_ERROR)
         {
           MainForm->Memo1->Lines->Add("Неверный ответ от Ring: ");
           MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_block_info.head.name,4)+" - "
                                          +"A: " +IntToHex(kvring_block_info.head.name,4)
                                         );
           MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_block_info.head.index,4)+" - "
                                          +"A: " +IntToHex(kvring_block_info.head.index,4)
                                         );
           MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_block_info.data.number,4)+" - "
                                          +"A: " +IntToHex(kvring_block_info.data.number,4)
                                         );
           MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_block_info.data.size,4)+" - "
                                          +"A: " +IntToHex(kvring_block_info.data.size,4)
                                         );
           MainForm->Memo1->Lines->Add( "S: " +IntToHex((int)ring_block_info.data.crc32,8)+" - "
                                          +"A: " +IntToHex((int)kvring_block_info.data.crc32,8)
                                         );
         }
       }
       else
       {
        MainForm->Memo1->Lines->Add("Блок "+IntToStr(io_iter)+" готов к передаче");
        io_state =  SEND_BLOCK;
       }
     }// good IO
     else
     {
      if(io_res != COM_OK) MainForm->Memo1->Lines->Add("Ошибка COM порта ...");
     }

   }// SEND_COMM

   if(io_state == SEND_BLOCK)
   {
     MainForm->Memo1->Lines->Add("");
     MainForm->Memo1->Lines->Add("передача блока файла расписания "+IntToStr(io_iter)+" из "+IntToStr(block_count) );

     SetIdleData(&kvblock_info, sizeof(kvblock_info));

     res = SendToRing(io_buf, block_size,
                      &kvblock_info, sizeof(kvblock_info),&io_res);


     if(res == R_OK)
     {
       if( (kvblock_info.head.index & 0xFF00) == 0xEE00 )
       {
         MainForm->Memo1->Lines->Add("Сбой программы Ring");
         res = R_RING_FAIL;
       }
       else
       if(    (kvblock_info.head.name == RING_PROT_NAME)
           && (kvblock_info.head.index == RING_GET_BLOCK)
           && (kvblock_info.data.number == io_iter)
           && (kvblock_info.data.size == block_size)
           && (kvblock_info.data.crc32 == crc32_sum)
         )
       {
         MainForm->Memo1->Lines->Add("Блок "+IntToStr(io_iter)+" передан");
         MainForm->Memo1->Lines->Add( "блок "+IntToStr(io_iter)
                                     +" s - " +IntToStr(kvblock_info.data.size)
                                     +" sum - "+IntToHex((int)kvblock_info.data.crc32,8)
                                    );

         if(io_iter == block_count)
         {
           io_state = IDLE;
         }
         else
         {
           if( (io_iter + 1) == block_count) // next block is tail
           {
             if( tail_size == 0) block_size = IO_BLOCK_SIZE;
                            else block_size = tail_size;
           }
           else
           {
             block_size = IO_BLOCK_SIZE;
           }

           buf_pointer += IO_BLOCK_SIZE;
           io_iter++;
           io_state = SEND_COMM;
         }

          MainForm->ProgressBar1->Position = (io_iter * 99) / block_count;
       }
       else
       {
         MainForm->Memo1->Lines->Add("Неверный ответ от Ring: ");
         MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_block_info.head.name,4)+" - "
                                        +"A: " +IntToHex(kvblock_info.head.name,4)
                                       );
         MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_block_info.head.index,4)+" - "
                                        +"A: " +IntToHex(kvblock_info.head.index,4)
                                       );
         MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_block_info.data.number,4)+" - "
                                        +"A: " +IntToHex(kvblock_info.data.number,4)
                                       );
         MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_block_info.data.size,4)+" - "
                                        +"A: " +IntToHex(kvblock_info.data.size,4)
                                       );
         MainForm->Memo1->Lines->Add( "S: " +IntToHex((int)ring_block_info.data.crc32,8)+" - "
                                        +"A: " +IntToHex((int)kvblock_info.data.crc32,8)
                                       );
         res = R_KVITANCE_ERROR;
       }
     }// good IO
     else
     {
       if(io_res != COM_OK) MainForm->Memo1->Lines->Add("Ошибка COM порта ...");
     }
   }// SEND_BLOCK

   if(res != R_OK)
   {
     free(virtual_file);
     tfile->Free();
     return res;
   }
 }// while

 Sleep(MainForm->COMDelayBF->Position);

 MainForm->Memo1->Lines->Add("");
 MainForm->Memo1->Lines->Add("Send end:   ");

 //  send command - end transmit
 crc32_sum = CRC32(virtual_file, tfile->Size);
 InitRingEndSched(&ring_block_info, block_count, tfile->Size, crc32_sum);

 res = SendToRing(&ring_block_info, sizeof(ring_block_info),
                  &kvring_block_info, sizeof(ring_block_info), &io_res);

 if(res == R_OK)
  {
   if(  (kvring_block_info.data.size == tfile->Size)
      &&(kvring_block_info.data.crc32 == crc32_sum)
     )
   {
    MainForm->Memo1->Lines->Add("Файл Schedule успешно передан");
   }
   else
   {
    MainForm->Memo1->Lines->Add("Сбой передачи файла Schedule");
    MainForm->Memo1->Lines->Add("Неверный ответ от Ring: ");
    MainForm->Memo1->Lines->Add( "S: " +IntToHex((int)tfile->Size,8)+" - "
                                   +"A: " +IntToHex((int)kvring_block_info.data.size,8)
                                  );
    MainForm->Memo1->Lines->Add( "S: " +IntToHex((int)crc32_sum,8)+" - "
                                   +"A: " +IntToHex((int)kvring_block_info.data.crc32,8)
                                  );
    res = R_KVITANCE_ERROR;
   }
  }// gfood read
  else
  {
    if(io_res != COM_OK) MainForm->Memo1->Lines->Add("Ошибка COM порта ...");
  }

 MainForm->ProgressBar1->Position = 0;

 free(virtual_file);
 tfile->Free();

 return res;
}
//=========================================================================

int UpRing(unsigned int in_ring_time, T_Result * out_io_res)
{
  T_RingIO_Head ring_comm, kv_ring_comm;
  unsigned int res;

  InitRingOnCom(&ring_comm);

  res = SendToRing( &ring_comm, sizeof(ring_comm),
                    &kv_ring_comm, sizeof(ring_comm), out_io_res);

  if(res == R_OK)
  {
    if( memcmp(&ring_comm, &kv_ring_comm, sizeof(ring_comm)) == 0)
    {
      MainForm->RingButton->Caption = "СТОП";
      EventRingTime = in_ring_time; // Decrease in timer
      return R_OK;
    }
    else
    {
      MainForm->Memo1->Lines->Add(": Неверный ответ от Ring: ");
      MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_comm.name,4)+" - "
                                  +"A: " +IntToHex(kv_ring_comm.name,4)
                                 );
      MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_comm.index,4)+" - "
                                  +"A: " +IntToHex(kv_ring_comm.index,4)
                                 );

     return R_KVITANCE_ERROR;
    }
  }

  return res;
}
//====================================================

int DownRing(T_Result * out_io_res)
{
  T_RingIO_Head ring_comm, kv_ring_comm;
  unsigned int res;

  InitRingOffCom(&ring_comm);

  res = SendToRing( &ring_comm, sizeof(ring_comm),
                    &kv_ring_comm, sizeof(ring_comm), out_io_res);
  if(res == R_OK)
  {
    if( memcmp(&ring_comm, &kv_ring_comm, sizeof(ring_comm)) == 0 )
    {
       MainForm->RingButton->Caption = "Звонок";
       EventRingTime = 0;
       return R_OK;
    }
    else
    {
      MainForm->Memo1->Lines->Add(": Неверный ответ от Ring: ");
      MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_comm.name,4)+" - "
                                  +"A: " +IntToHex(kv_ring_comm.name,4)
                                 );
      MainForm->Memo1->Lines->Add( "S: " +IntToHex(ring_comm.index,4)+" - "
                                  +"A: " +IntToHex(kv_ring_comm.index,4)
                                 );
      return R_KVITANCE_ERROR;
    }
  }

  return res;
}
//============================== STOP


//=========================================================================
//========================== EVENT Handle ===============================


int GetIDSound(AnsiString & sound_file)
{
 vector<t_SoundFileList>::iterator iter = SoundFiles.begin();
 int res = 0;

 while ( iter != SoundFiles.end() )
   {
    if (iter->file_name.AnsiCompareIC(sound_file) ==0 )
      {
       return res;
      }
    ++iter;  ++res;
   }
 return -1;
}
//=======================================================================

void SetUseHour(bool set)
{
 MainForm->IncHour->Enabled = set;
 MainForm->TextHour->Enabled = set;
 MainForm->DecHour->Enabled = set;
}
//====================================================================

void SetHour(unsigned s_hour)
{
 unsigned i;

 if (s_hour < 10)
   MainForm->TextHour->Text = "0"+IntToStr(s_hour);
   else MainForm->TextHour->Text = IntToStr(s_hour);

 if(s_hour == 23) i = 0; else i = s_hour + 1;

 if(i < 10) MainForm->IncHour->Caption = "0"+IntToStr(i);
   else MainForm->IncHour->Caption = IntToStr(i);

 if(s_hour == 0) i = 23; else i = s_hour - 1;

 if ( i < 10) MainForm->DecHour->Caption = "0"+IntToStr(i);
   else MainForm->DecHour->Caption = IntToStr(i);
}
//======================================================================

void SetUseMinute(bool set)
{
 MainForm->IncMinute->Enabled = set;
 MainForm->TextMinute->Enabled = set;
 MainForm->DecMinute->Enabled = set;
}
//========================================================================

void SetMinute(unsigned s_min)
{
 unsigned i;

 if (s_min < 10)
   MainForm->TextMinute->Text = "0"+IntToStr(s_min);
   else MainForm->TextMinute->Text = IntToStr(s_min);

 if(s_min == 59) i = 0; else i = s_min + 1;
 if(i < 10) MainForm->IncMinute->Caption = "0"+IntToStr(i);
   else MainForm->IncMinute->Caption = IntToStr(i);

 if(s_min == 0) i = 59;  else i = s_min - 1;
 if ( i < 10) MainForm->DecMinute->Caption = "0"+IntToStr(i);
   else MainForm->DecMinute->Caption = IntToStr(i);
}
//========================================================================

void SetVariant()
{
 if (MainForm->PageControl3->ActivePage == MainForm->WeekTab)
   {
    MainForm->But_date->Font->Color = clSilver;
    MainForm->But_daily->Font->Color = clSilver;
    MainForm->But_monthly->Font->Color = clSilver;
    MainForm->But_weekly->Font->Color = clGreen;
   }
   else
   {
    if(MainForm->At_month->Checked
//       || MainForm->At_day->Checked
      )
      {
       MainForm->But_date->Font->Color = clGreen;
       MainForm->But_daily->Font->Color = clSilver;
       MainForm->But_monthly->Font->Color = clSilver;
       MainForm->But_weekly->Font->Color = clSilver;
      }
      else
      {
       if(!MainForm->At_month->Checked
          && !MainForm->At_day->Checked
          && !MainForm->At_year->Checked
         )
         {
          MainForm->But_date->Font->Color = clSilver;
          MainForm->But_daily->Font->Color = clGreen;
          MainForm->But_monthly->Font->Color = clSilver;
          MainForm->But_weekly->Font->Color = clSilver;
         }
         else
         {
          if(!MainForm->At_month->Checked
             && MainForm->At_day->Checked
            )
            {
             MainForm->But_date->Font->Color = clSilver;
             MainForm->But_daily->Font->Color = clSilver;
             MainForm->But_monthly->Font->Color = clGreen;
             MainForm->But_weekly->Font->Color = clSilver;
            }
         }
      }
   }
}
//========================================================================

void SetUseDate(bool f_year, bool f_month, bool f_day)
{
 MainForm->At_year->Checked = f_year;
 MainForm->At_month->Checked = f_month;
 MainForm->At_day->Checked = f_day;
}
//====================================================================

void SetLinkDate()
{
 if ( !MainForm->At_day->Checked
     && !MainForm->At_month ->Checked
     && !MainForm->At_year->Checked

    )
   {
    MainForm->DateTimePicker1->Enabled = false;
   }
   else
   {
    MainForm->DateTimePicker1->Enabled = true;
   }

 if(!MainForm->At_day->Checked)
    {
     MainForm->Is_seleb->Enabled = false;
    }
    else
    {
     MainForm->Is_seleb->Enabled = true;
    }
}
//=====================================================================


void ChangeDate(double i)
{
 unsigned short n_year, n_mon, n_day;

 TDateTime dt = MainForm->DateTimePicker1->Date;
 dt +=i;
 MainForm->DateTimePicker1->Date = dt;

}
//=====================================================================

void SetWeek()
{
  if( !MainForm->At_mon->Checked
     && !MainForm->At_tue->Checked
     && !MainForm->At_wed->Checked
     && !MainForm->At_thur->Checked
     && !MainForm->At_fri->Checked
     && !MainForm->At_sat->Checked
     && !MainForm->At_sun->Checked
    )
   {
    MainForm->PageControl3->ActivePage = MainForm->DayTab;
   }

}
//=====================================================================

void MakeDate(T_Date * out_date)
{
 unsigned short n_year, n_mon, n_day;
 unsigned f_week;

 MainForm->DateTimePicker1->Date.DecodeDate(&n_year,&n_mon,&n_day);

 out_date->use_year = MainForm->At_year->Checked;
 out_date->use_month = MainForm->At_month->Checked;
 out_date->use_day = MainForm->At_day->Checked;

 out_date->use_weekly =  MainForm->PageControl3->ActivePage == MainForm->WeekTab ? true:false;

 out_date->year = n_year;
 out_date->month = n_mon;
 out_date->day = n_day;

 f_week=0;
 if (MainForm->At_mon->Checked) f_week+=WD_MONDAY;
 if (MainForm->At_tue->Checked) f_week+=WD_TUESDAY;
 if (MainForm->At_wed->Checked) f_week+=WD_WEDNSDAY;
 if (MainForm->At_thur->Checked) f_week+=WD_THURSDAY;
 if (MainForm->At_fri->Checked) f_week+=WD_FRIDAY;
 if (MainForm->At_sat->Checked) f_week+=WD_SATURDAY;
 if (MainForm->At_sun->Checked) f_week+=WD_SUNDAY;
 out_date->weekday=f_week;
 out_date->exclusive_day=MainForm->Is_seleb->Checked;

}
//========================================================================

void MakeTime(T_Time * out_time)
{
 out_time->use_hour = MainForm->FUseHour->Checked;
 out_time->use_minute = MainForm->FUseMinute->Checked;
 out_time->use_second = false;

 out_time->hour = f_hour;
 out_time->minute = f_min;
 out_time->second = 0;
}
//========================================================================


int MakeEvent(Ti_Event* event)
{
  int num;

  MakeDate(&event->start_date);
  MakeTime(&event->start_time);

  event->cycle_flags.el.is_event_active = 1;
  event->cycle_flags.el.is_showed = 0;
  event->cycle_flags.el.even_in_exclusive = MainForm->At_seleb->Checked;

  event->event_sign.el.ring_time = MainForm->RingDelay->Position;
  event->event_sign.el.is_ring = MainForm->Add_ring->Checked;

  event->event_sign.el.is_sound = MainForm->Add_sound->Checked;
  if(event->sound != NULL)
  {
    if(MainForm->Add_sound->Checked)
    {
      event->sound = SoundFiles[MainForm->SigFiles->ItemIndex].full_name.c_str();
    }
    else
    {
      event->sound[0] = 0;
    }
  }

  event->event_sign.el.is_text = 1;
  if(event->caption != NULL)
  {
    if(MainForm->Memo3->Lines->Count > 0)
    {
      event->caption = MainForm->Memo3->Lines->Strings[0].c_str();
    }
    else
    {
      if(MainForm->Add_sound->Checked)
      {
        event->caption = SoundFiles[MainForm->SigFiles->ItemIndex].file_name.c_str();
      }
      else
      {
        strcpy(event->caption, "событие");
      }
    }
  }

 if(TryStrToInt(MainForm->EventNum->Caption, num))
 {
   return num;
 }

 return -1;
}
//========================================================================

void ShowMomentTitle()
{
 AnsiString str_day, str_time;
 T_Date in_date;
 T_Time in_time;

 MakeDate(&in_date);
 MakeTime(&in_time);

 MomentToStr(in_date, in_time, &str_day, &str_time);

 if(str_day == "") MainForm->DateEvent->Caption = "Ежедневно";
 else MainForm->DateEvent->Caption = str_day;
 if(str_time == "") MainForm->TimeEvent->Caption = "при включении";
 else MainForm->TimeEvent->Caption = str_time;
}
//========================================================================

void SetAllControl(Ti_Event & event)
{
 AnsiString str_day, str_time;

 f_hour = event.start_time.hour;
 f_min =  event.start_time.minute;

 MainForm->FUseHour->Checked = event.start_time.use_hour;
 SetHour(f_hour);  // set values;
 SetUseHour(MainForm->FUseHour->Checked);

 MainForm->FUseMinute->Checked = event.start_time.use_minute;
 SetMinute(f_min);  // set values;
 SetUseMinute(MainForm->FUseMinute->Checked);

 SetUseDate(event.start_date.use_year,event.start_date.use_month,event.start_date.use_day);
 SetLinkDate();
 if (event.start_date.use_weekly)
   {
    MainForm->PageControl3->ActivePage = MainForm->WeekTab;
   }
 SetVariant();

 MainForm->Is_seleb->Checked = event.start_date.exclusive_day;

 if(MainForm->PageControl3->ActivePage == MainForm->WeekTab)
   {
    MainForm->At_mon->Checked = ((event.start_date.weekday & WD_MONDAY) !=0) ? true:false;
    MainForm->At_tue->Checked = ((event.start_date.weekday & WD_TUESDAY) !=0) ? true:false;
    MainForm->At_wed->Checked =  ((event.start_date.weekday & WD_WEDNSDAY) !=0) ? true:false;
    MainForm->At_thur->Checked = ((event.start_date.weekday & WD_THURSDAY) !=0) ? true:false;
    MainForm->At_fri->Checked =  ((event.start_date.weekday & WD_FRIDAY) !=0) ? true:false;
    MainForm->At_sat->Checked =  ((event.start_date.weekday & WD_SATURDAY) !=0) ? true:false;
    MainForm->At_sun->Checked =  ((event.start_date.weekday & WD_SUNDAY) !=0) ? true:false;
   }
 MainForm->At_seleb->Checked = (event.cycle_flags.el.even_in_exclusive==1) ? true:false;


 MainForm->Add_ring->Checked = (event.event_sign.el.is_ring == 1) ? true:false;
 MainForm->RingDelay->Position = event.event_sign.el.ring_time;

 MainForm->Add_sound->Checked = (event.event_sign.el.is_sound == 1) ? true:false;

 ShowMomentTitle();

}
//======================================================================


void ShowAddDialog()
{
 TDateTime dt;
 AnsiString str_buf;
 Ti_Event  mem_event;

 unsigned short n_hour, n_min, n_sec, n_msec;
 unsigned short n_year, n_mon, n_day;

 vector<t_SoundFileList>::iterator iter = SoundFiles.begin();

 MainForm->EventNum->Caption = "new";

 dt=Now();
 dt.DecodeDate(&n_year,&n_mon,&n_day);
 dt.DecodeTime(&n_hour,&n_min,&n_sec, &n_msec);

 InitEvent(&mem_event);
 mem_event.start_date.use_day = true;
 mem_event.start_date.use_month = true;
 mem_event.start_date.use_year = false;
 mem_event.start_date.use_weekly = false;

 mem_event.start_date.year = n_year;
 mem_event.start_date.month = n_mon;
 mem_event.start_date.day = n_day;

 n_day = dt.DayOfWeek();
 if(n_day == 1) n_day = 6; else n_day -=2;
 mem_event.start_date.weekday = (1 << (n_day-1));

 mem_event.start_time.hour = n_hour;
 mem_event.start_time.minute = n_min;

 MainForm->DateTimePicker1->DateTime= dt;

 MainForm->Caption="Добавить событие";
 MainForm->ButSaveEvent->Caption="Сохранить";
 MainForm->EventText->Caption = " Новое событие ";
 MainForm->ButSaveas->Visible= false;

 SetAllControl(mem_event);

 MainForm->Memo1->Clear();

 MainForm->SigFiles->Items->Clear();

 if (!SoundFiles.empty())
   {
    while ( iter != SoundFiles.end() )
      {
       MainForm->SigFiles->Items->Add(iter->file_name);
       ++iter;
      }

    // clear previous sound
  if (MainForm->MediaPlayer1->Mode == mpPlaying)
  MainForm->MediaPlayer1->Stop();
  MainForm->MediaPlayer1->Close();

    str_buf = SoundFiles[MainForm->SigFiles->Items->Count-1].full_name;
    if (FileExists(str_buf))
      {
       MainForm->MediaPlayer1->FileName=str_buf;
       MainForm->MediaPlayer1->Open();
      }

   }
 MainForm->SigFiles->ItemIndex = MainForm->SigFiles->Items->Count-1;

 MainForm->PageControl1->ActivePage = MainForm->EditWin;
}
//==========================================================================

void ShowEditDialog(Ti_Event & in_event)
{
 TDateTime dt;
 AnsiString str_buf;
 unsigned short n_year, n_mon, n_day;
 int i;

 vector<t_SoundFileList>::iterator iter = SoundFiles.begin();

 dt = Now();
 dt.DecodeDate(&n_year,&n_mon,&n_day);

 MainForm->EventNum->Caption = IntToStr(in_event.cycle_flags.el.id_event);

 MainForm->Caption="Изменить событие";
 MainForm->ButSaveEvent->Caption="Сохранить изменения";
 MainForm->EventText->Caption = " Событие: " + IntToStr(in_event.cycle_flags.el.id_event +1)+ " ";
 MainForm->ButSaveas->Visible= true;

 if(!in_event.start_date.use_day)
   {
    MainForm->DateTimePicker1->Date = dt;
   }
   else
    {
     str_buf = IntToStr(in_event.start_date.day)+"."+IntToStr(in_event.start_date.month);
     if (in_event.start_date.use_year)
       {
        str_buf = str_buf + "."+IntToStr(in_event.start_date.year);
       }
       else
       {
        str_buf = str_buf + "."+IntToStr(n_year);
       }
     MainForm->DateTimePicker1->Date =StrToDate(str_buf);
    }
 
 SetAllControl(in_event);

 MainForm->Memo3->Clear();
 if(in_event.caption != NULL)
   MainForm->Memo3->Lines->Add(AnsiString(in_event.caption));

 MainForm->Memo3->CaretPos = Point(MainForm->Memo3->Lines[0].Text.Length()-1 ,0);

 MainForm->SigFiles->Items->Clear();

  if (!SoundFiles.empty())
   {
    while ( iter != SoundFiles.end() )
      {
       MainForm->SigFiles->Items->Add(iter->file_name);
       ++iter;
      }

    if(in_event.sound != NULL)
    {
      i =  GetIDSound(AnsiString(in_event.sound));
    }
    else { i = -1; }

    if(i >= 0)
      {
       MainForm->SigFiles->Text = AnsiString(in_event.sound);
       MainForm->SigFiles->ItemIndex = i;
      }
      else
      {
       MainForm->SigFiles->ItemIndex = MainForm->SigFiles->Items->Count-1;
      }
   }
   else
   {
    MainForm->SigFiles->ItemIndex = MainForm->SigFiles->Items->Count-1;
   }

  // clear previous sound
  if (MainForm->MediaPlayer1->Mode == mpPlaying)
  MainForm->MediaPlayer1->Stop();
  MainForm->MediaPlayer1->Close();

  str_buf = SoundFiles[MainForm->SigFiles->ItemIndex].full_name;
  if (FileExists(str_buf))
    {
     MainForm->MediaPlayer1->FileName=str_buf;
     MainForm->MediaPlayer1->Open();
    }

 MainForm->PageControl1->ActivePage = MainForm->EditWin;
}
//==========================================================================

void SaveEvent(bool new_event)
{
  int number;
  Ti_Event  event;

  NewEvent(&event);

  number = MakeEvent(&event);

  if((number == -1) || new_event) // new event
  {
    EventList_push(&BaseEventList,&event);
  }
  else
  {
    EventList_update(&BaseEventList, number, &event);
  }

  FreeEvent(&event);
}
//========================================================================

int LoadSetup(AnsiString in_dir, T_SoundFiles * in_set)
{
  AnsiString  as_buf;
  AnsiString bs,ws;
  int i,res;

  //  set default data - for no setup files
  MainForm->DefRingUnited->Checked = DEF_RING_UNIT;
  as_buf =  RING_LINK;
  MainForm->DefRingComm->Checked = true;

  CommName = DEF_COMM_NAME;
  SetSupFail(SUP_DEF_COMM);

  MainForm->COMDelayBF->Position = COM_DELAY_BF;

  MainForm->RingDelay->Position = DEF_RING_DELAY;
  MainForm->UpBoosterDelay->Position = DEF_UP_BOOSTER_DELAY;
  MainForm->DownBoosterDelay->Position = DEF_DOWN_BOOSTER_DELAY;

  MainForm->DefShowWarnWindow->Checked = DEF_SHOW_WORN_WIN;

  MainForm->ListTimeZone->ItemIndex = DEF_TIME_ZONE - 2;

  WorkScheduleFile = DEF_SCHEDULE_FILE;
  in_set->SetAlarmFile = DEF_ALARM_SOUND;
  in_set->SetFireFile = DEF_FIRE_SOUND;
  in_set->SetRingFile = DEF_RING_SOUND;

// try to find setup files
  if(FileExists(in_dir+SETUP_FILE))
  {
    MainForm->DefRingUnited->Checked = ini_file->ReadInteger(INI_DEP_RING, INI_RING_UNIT, DEF_RING_UNIT);
    as_buf =  ini_file->ReadString(INI_DEP_RING, INI_RING_LINK, RING_LINK);
    MainForm->DefRingComm->Checked = (as_buf == RING_LINK)? true: false ;

    CommName = ini_file->ReadString(INI_DEP_COMM, INI_COMM_NAME, DEF_COMM_NAME);
    if(CommName == DEF_COMM_NAME)
    {
      SetSupFail(SUP_DEF_COMM);
    }

    MainForm->COMDelayBF->Position = ini_file->ReadInteger(INI_DEP_COMM, INI_COMM_F_DELAY, COM_DELAY_BF);

    MainForm->RingDelay->Position = ini_file->ReadInteger(INI_DEP_RING_SETUP, INI_RING_DELAY, DEF_RING_DELAY);
    MainForm->UpBoosterDelay->Position = ini_file->ReadInteger(INI_DEP_RING_SETUP, INI_UP_BOOSTER_DELAY, DEF_UP_BOOSTER_DELAY);
    MainForm->DownBoosterDelay->Position = ini_file->ReadInteger(INI_DEP_RING_SETUP, INI_DOWN_BOOSTER_DELAY, DEF_DOWN_BOOSTER_DELAY);

    MainForm->DefShowWarnWindow->Checked = ini_file->ReadInteger(INI_DEP_UI, INI_SHOW_WORN_WIN, DEF_SHOW_WORN_WIN);

    MainForm->ListTimeZone->ItemIndex = ini_file->ReadInteger(INI_DEP_UI, INI_TIME_ZONE, DEF_TIME_ZONE) - 2;

    WorkScheduleFile = ini_file->ReadString(INI_DEP_FILES, INI_SCHEDULE_FILE, DEF_SCHEDULE_FILE);
    if(WorkScheduleFile == "")  WorkScheduleFile = DEF_SCHEDULE_FILE;
    in_set->SetAlarmFile = ini_file->ReadString(INI_DEP_FILES, INI_USE_ALARM, DEF_ALARM_SOUND);
    if(in_set->SetAlarmFile == "")  in_set->SetAlarmFile = DEF_ALARM_SOUND;
    in_set->SetFireFile = ini_file->ReadString(INI_DEP_FILES, INI_USE_FIRE, DEF_FIRE_SOUND);
    if(in_set->SetFireFile == "" ) in_set->SetFireFile = DEF_FIRE_SOUND;
    in_set->SetRingFile = ini_file->ReadString(INI_DEP_FILES, INI_USE_RING, DEF_RING_SOUND);
    if(in_set->SetRingFile =="" )  in_set->SetRingFile = DEF_RING_SOUND;

    res = R_OK;
  }// if new file
  else
  {
    if( FileExists(in_dir+OLD_PAR_FILE) )
    {
      MainForm->Memo2->Lines->Clear();
      MainForm->Memo2->Lines->LoadFromFile(in_dir+OLD_PAR_FILE);

      if(MainForm->Memo2->Lines->Count>0) // UP & DOWN BOOSTER
      {
        bs=MainForm->Memo2->Lines->Strings[0];   //Lines->GetText(); - take all strings in one

        if(bs.Length() >= 2 ) ws=bs.SubString(1,2);
        else
        {
          ws="-";
          MainForm->Memo1->Lines->Add("read failed!");
          res = R_READ_FILE_ERROR;
          SetSupFail(SUP_FREAD_SETUP);
        }

        MainForm->Memo1->Lines->Add("read UpBoosterDelay = "+ws);
        if(TryStrToInt(ws,i))
        {
          if(i>=0 && i<99)
          {
            MainForm->UpBoosterDelay->Position = i;
          }
          else
          {
            MainForm->Memo1->Lines->Add("read failed!");
            MainForm->UpBoosterDelay->Position = DEF_UP_BOOSTER_DELAY;
            res = R_READ_FILE_ERROR;
            SetSupFail(SUP_FREAD_SETUP);
          }
        }
        else
        {
          MainForm->Memo1->Lines->Add("read failed!");
          MainForm->UpBoosterDelay->Position = DEF_UP_BOOSTER_DELAY;
          res = R_READ_FILE_ERROR;
          SetSupFail(SUP_FREAD_SETUP);
        }

        MainForm->Memo1->Lines->Add("Set UpBoosterDelay = "+IntToStr(MainForm->UpBoosterDelay->Position));

        if(bs.Length() >= 4) ws=bs.SubString(3,2);
        else
        {
          ws="-";
          MainForm->Memo1->Lines->Add("read failed!");
          res = R_READ_FILE_ERROR;
          SetSupFail(SUP_FREAD_SETUP);
        }
        MainForm->Memo1->Lines->Add("read DownBoosterDelay = "+ws);
        if(TryStrToInt(ws,i))
        {
          if(i>=0 && i<99)
          {
            MainForm->DownBoosterDelay->Position = i;
          }
          else
          {
            MainForm->DownBoosterDelay->Position = DEF_DOWN_BOOSTER_DELAY;
            MainForm->Memo1->Lines->Add("read failed!");
            res = R_READ_FILE_ERROR;
            SetSupFail(SUP_FREAD_SETUP);
          }
         }
        else
        {
          MainForm->DownBoosterDelay->Position = DEF_DOWN_BOOSTER_DELAY;
          MainForm->Memo1->Lines->Add("read failed!");
          res = R_READ_FILE_ERROR;
          SetSupFail(SUP_FREAD_SETUP);
        }
        MainForm->Memo1->Lines->Add("Set DownBoosterDelay = "+IntToStr(MainForm->DownBoosterDelay->Position));
      }  // UP & DOWN BOOSTER
      else
      {
        MainForm->Memo1->Lines->Add("Read Delays failed");
        res = R_READ_FILE_ERROR;
        SetSupFail(SUP_FREAD_SETUP);
      }
      if(MainForm->Memo2->Lines->Count>1) // Time zone & Winter Time
      {
        bs=MainForm->Memo2->Lines->Strings[1];
        if(bs.Length() >= 2) ws=bs.SubString(1,2);
        else
        {
          ws="-";
          MainForm->Memo1->Lines->Add("read TimeZone failed!");
          res = R_READ_FILE_ERROR;
          SetSupFail(SUP_FREAD_SETUP);
        }
        MainForm->Memo1->Lines->Add("read TimeZone = "+ws);
        if(TryStrToInt(ws,i))
        {
          if(i>=2 && i<13)
          {
            MainForm->ListTimeZone->ItemIndex = i;
          }
          else
          {
            MainForm->ListTimeZone->ItemIndex = DEF_TIME_ZONE - 2;
            MainForm->Memo1->Lines->Add("read TimeZone failed!");
            res = R_READ_FILE_ERROR;
            SetSupFail(SUP_FREAD_SETUP);
          }
        }
        else
        {
          MainForm->ListTimeZone->ItemIndex = DEF_TIME_ZONE - 2;
          MainForm->Memo1->Lines->Add("read TimeZone failed!");
          res = R_READ_FILE_ERROR;
          SetSupFail(SUP_FREAD_SETUP);
        }
        MainForm->Memo1->Lines->Add("Set TimeZone = "+IntToStr(MainForm->ListTimeZone->ItemIndex+2));
            /*
         if(bs.Length() >= 4) ws=bs.SubString(3,2);
           else
           {
            ws="-";
            MainForm->Memo1->Lines->Add("read WinterTime failed!");
           }
         MainForm->Memo1->Lines->Add("read WinterTime = "+ws);
            if(TryStrToInt(ws,i))
           {
            if(i>=0 && i<2)
              {
               set->winter_time = i;
              }
              else
              {
               set->winter_time = DEF_WINTER_TIME;
               MainForm->Memo1->Lines->Add("read WinterTime failed!");
              }
           }
           else
           {
            set->winter_time = DEF_WINTER_TIME;
            MainForm->Memo1->Lines->Add("read WinterTime failed!");
           }
         MainForm->Memo1->Lines->Add("Set WinterTime = "+IntToStr(set->winter_time));
         */
      }// Time zone & Winter Time
      else
      {
        MainForm->Memo1->Lines->Add("read Zone & WinterTime failed!");
        res = R_READ_FILE_ERROR;
        SetSupFail(SUP_FREAD_SETUP);
      }
      if(MainForm->Memo2->Lines->Count>2) // USER ALARM SOUND
      {
        bs=MainForm->Memo2->Lines->Strings[2];

        MainForm->Memo1->Lines->Add("read file for alarm = "+bs);

        while (bs.AnsiPos(" ") != 0 ) bs.Delete(bs.AnsiPos(" "),1);

        ws = in_dir+bs;
        if(FileExists(ws)) in_set->SetAlarmFile = bs;
                      else in_set->SetAlarmFile = DEF_ALARM_SOUND;
        MainForm->Memo1->Lines->Add("Set ALARM sound = "+in_set->SetAlarmFile);
      } // DEF ALARM SOUND

      if(MainForm->Memo2->Lines->Count>3) // DEF FIRE SOUND
      {
        bs=MainForm->Memo2->Lines->Strings[3];
        MainForm->Memo1->Lines->Add("read file for fire = "+bs);
        while (bs.AnsiPos(" ") != 0 ) bs.Delete(bs.AnsiPos(" "),1);
        ws = in_dir+bs;
        if( FileExists(ws) )  in_set->SetFireFile = bs;
                         else in_set->SetFireFile = DEF_FIRE_SOUND;

        MainForm->Memo1->Lines->Add("Set FIRE sound = "+in_set->SetFireFile);
      } // DEF FIRE SOUND
      if(MainForm->Memo2->Lines->Count>4) // DEF TEST SOUND
      {
        bs=MainForm->Memo2->Lines->Strings[4];

        MainForm->Memo1->Lines->Add("read file for test = "+bs);

        while (bs.AnsiPos(" ") != 0 ) bs.Delete(bs.AnsiPos(" "),1);

        ws = in_dir+bs;
        if( FileExists(ws) ) in_set->SetRingFile = bs;
                        else in_set->SetRingFile = DEF_RING_SOUND;
        MainForm->Memo1->Lines->Add("Set TEST sound = "+in_set->SetRingFile);
      } // DEF TEST SOUND

    }// is old setup
    else
    {
      res = R_NO_FILE;
      SetSupFail(SUP_IS_SETUP);
    }

    SetSupFail(SUP_DEF_COMM);
    CommName = DEF_COMM_NAME;

  }// is ini

 return res;
}
//=========================================================================

void SaveSettings(T_SoundFiles * in_set)
{
  AnsiString as_buf;

  ini_file->WriteInteger(INI_DEP_RING, INI_RING_UNIT, MainForm->DefRingUnited->Checked);
  if(MainForm->DefRingComm->Checked)
    ini_file->WriteString(INI_DEP_RING, INI_RING_LINK, RING_LINK);

  ini_file->WriteString(INI_DEP_COMM, INI_COMM_NAME, CommName);
  ini_file->WriteInteger(INI_DEP_COMM, INI_COMM_F_DELAY, MainForm->COMDelayBF->Position);

  ini_file->WriteInteger(INI_DEP_RING_SETUP, INI_RING_DELAY, MainForm->RingDelay->Position);
  ini_file->WriteInteger(INI_DEP_RING_SETUP, INI_UP_BOOSTER_DELAY, MainForm->UpBoosterDelay->Position);
  ini_file->WriteInteger(INI_DEP_RING_SETUP, INI_DOWN_BOOSTER_DELAY, MainForm->DownBoosterDelay->Position);

  ini_file->WriteInteger(INI_DEP_UI, INI_SHOW_WORN_WIN, MainForm->DefShowWarnWindow->Checked);
  ini_file->WriteInteger(INI_DEP_UI, INI_TIME_ZONE, MainForm->ListTimeZone->ItemIndex + 2);
  
  ini_file->WriteString(INI_DEP_FILES, INI_SCHEDULE_FILE, WorkScheduleFile);
  ini_file->WriteString(INI_DEP_FILES, INI_USE_ALARM, in_set->SetAlarmFile);
  ini_file->WriteString(INI_DEP_FILES, INI_USE_FIRE, in_set->SetFireFile);
  ini_file->WriteString(INI_DEP_FILES, INI_USE_RING, in_set->SetRingFile);

}
//==========================================================================

void DoSignal(Ti_Event & in_event)
{
  AnsiString str_day, str_time, str_buf;

  unsigned int res;
  T_Result io_res;

  MomentToStr(in_event.start_date, in_event.start_time, &str_day, &str_time);
  if(str_day != "")
  {
    if (str_time != "") str_buf = str_day+" - "+str_time;
  }
  else
  {
    if(str_time != "") { str_buf = str_time; }
  }

  MessWindow->UnSetWarn->Visible = false;
  MessWindow->Caption = "Событие: "+str_buf;
  MessWindow->Button->Caption = "Принято";

  if(in_event.caption != NULL) str_buf = AnsiString(in_event.caption);
                          else str_buf = "";
  MessWindow->Memo1->Clear();
  MessWindow->Memo1->Lines->Add(str_buf);

  if((in_event.event_sign.el.is_ring == 1) && IsCOMOpen())
  {
    CheckRingDelay = true;
    res = UpRing(in_event.event_sign.el.ring_time, &io_res);
  }

  if (MessWindow->MessPlayer->Mode == mpPlaying) MessWindow->MessPlayer->Stop();
  if((MessWindow->MessPlayer->Mode != mpPlaying) && (in_event.event_sign.el.is_sound == 1))
   {
    if(in_event.sound != NULL)
    {
      str_buf = AnsiString(in_event.sound);
      if(FileExists(str_buf))
      {
        MessWindow->MessPlayer->FileName=str_buf;
        MessWindow->MessPlayer->Open();
        MessWindow->MessPlayer->Play();
      }
    }
   }
   else
   {
    if (MessWindow->MessPlayer->Mode == mpPlaying) MessWindow->MessPlayer->Stop();
   }

  MessWindow->Visible = true;
}
//=========================================================




//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
   

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Exit_menuClick(TObject *Sender)
{

 MainForm->Close();
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::FormCreate(TObject *Sender)
{
  TDateTime dt;
  T_Result COMres;
  AnsiString ws, str_date, str_time;
  int i, j, res;

  s_Date b_date;
  s_Time b_time;

  unsigned short n_year, n_mon, n_day, n_wd;
  unsigned short n_hour, n_min, n_sec, n_msec;


  dt = Now();
  dt.DecodeDate(&n_year,&n_mon,&n_day);
  dt.DecodeTime(&n_hour,&n_min,&n_sec,&n_msec);
  n_wd = dt.DayOfWeek();
  if(n_wd == 1) n_wd = 6; else n_wd -=2;

  b_date.year = n_year;
  b_date.month = n_mon;
  b_date.day = n_day;
  b_date.weekday = n_wd;

  b_time.hour = n_hour;
  b_time.minute = n_min;
  b_time.second = n_sec;



  InitSupPlan();

  wdir = GetCurrentDir()+"\\";
  MainForm->Memo1->Lines->Add("Work in "+wdir);

  ini_file = new TIniFile(wdir+SETUP_FILE);

  MainForm->SchedWin->TabVisible = false;
  MainForm->SetupWin->TabVisible = false;
  MainForm->EditWin->TabVisible = false;
  MainForm->PageControl1->ActivePage = SchedWin;

  MainForm->MainMenu->TabVisible = false;
  MainForm->EditMenu->TabVisible = false;

  MainForm->PageControl2->ActivePage = MainMenu;

  MainForm->BottomPanel->Height = 63;

  MainForm->MainTab->TabVisible = false;
  MainForm->DayTab->TabVisible = false;
  MainForm->WeekTab->TabVisible = false;
  MainForm->TimeTab->TabVisible = false;
  MainForm->SignalTab->TabVisible = false;
  MainForm->PageControl3->ActivePage = MainTab;

  MainForm->Width = 700;

  MainForm->Memo1->Clear();

  NowString(str_date, str_time);
  MainForm->TabloDate->Caption = str_date;
  MainForm->TabloTime->Caption = str_time;

  StartWork = true;
  DelNumEvent = -1;

  DeleteMode=false;

  SelGridRow = 0;

  fix_inc_hour = fix_dec_hour = fix_inc_min = fix_dec_min = false;


  stop_process = false;
  CheckRingDelay = false;

  LoadSetup(wdir, &UseSoundFiles);

  res = OpenFiles(&UseSoundFiles);

  EventList_init(&BaseEventList);
  EventList_init(&TodayEventList);  // today events
  EventList_init(&EditEventList);   // edit day events
  EventList_init(&DateEventList);   // view day events

  if( FileExists(WorkScheduleFile) ) // new format shedule
  {
    res = OpenSchedule(WorkScheduleFile, &BaseEventList);
  }
  else
  {
    res = OpenOldSchedule(WorkScheduleFile, &BaseEventList);
  }

  if( MakeTodaySchedule(&BaseEventList, &b_date, &TodayEventList, &IsHolyDay) == EL_RES_BASE_EMPTY)
  {
    MainForm->Memo1->Lines->Add("База событий пуста!");
  }

  NewDayCheck = true;

  ShowList.list = TODAY_LIST;
  ShowList.date = b_date;
  ShowBase();

  RingAutoControl = true;
  if(MainForm->DefRingUnited->Checked)
  {
    CheckRingTime = 0;

    if(MainForm->DefRingComm->Checked)
    {
      FindComm();

      if(sup_plan.sup_steps[SUP_IS_COMM]) // COMMs are
      {
        if(sup_plan.sup_steps[SUP_DEF_COMM])  // COM was defined
        {
          j = -1;
          for(i=0; i<MainForm->COMList->Items->Count; i++)
          {
            MainForm->COMList->ItemIndex = i;
            if(CommName == MainForm->COMList->Text) j = i;
          }//for

          if(j >=0 )
          {
            COMres = LinkCOM(CommName);

            if(COMres != COM_OK)
            {
              CommName = DEF_COMM_NAME;
              SetSupFail(SUP_DEF_COMM);
            }
          }
          else
          {
            CommName = DEF_COMM_NAME;
            SetSupFail(SUP_DEF_COMM);
          }
        }
      }
    }// link by comm
  } // add RING

}// create
//---------------------------------------------------------------------------




void __fastcall TMainForm::N2Click(TObject *Sender)
{
  MainForm->Visible=true;
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
  T_Result io_res;
  int rec;
  T_ListItem* NowEvent;
  AnsiString str_date, str_time;

  TDateTime dt;
  unsigned short n_year, n_mon, n_day, n_wd;
  unsigned short n_hour, n_min, n_sec, n_msec;

  s_Date b_date;
  s_Time b_time;

  dt = Now();
  dt.DecodeDate(&n_year,&n_mon,&n_day);
  dt.DecodeTime(&n_hour,&n_min,&n_sec,&n_msec);
  n_wd = dt.DayOfWeek();
  if(n_wd == 1) n_wd = 6; else n_wd -=2;

  b_date.year = n_year;
  b_date.month = n_mon;
  b_date.day = n_day;
  b_date.weekday = n_wd;

  b_time.hour = n_hour;
  b_time.minute = n_min;
  b_time.second = n_sec;



  if( StartWork ) //first start
  {
    MainForm->CurrentBase->SetFocus();
    if( ! sup_plan.sup_state) ShowSupResults(SHOW_WIN_STATE);

    StartWork =false;
  }
  else
  {

    NowString(str_date, str_time);
    MainForm->TabloDate->Caption = str_date;
    MainForm->TabloTime->Caption = str_time;

    if(MainForm->DefRingUnited->Checked && IsCOMOpen())
    {
      if(CheckRingTime == 0)
      {
        if(RingAutoControl)
        {
          CheckRingTime = CHECK_RING_PERIOD;
          // hold remote control
          rec = GetRingState();
          ShowStatus("Опрос состояние Ring: ", rec);
        }
      }
      else if(CheckRingTime > 0)  CheckRingTime--;
    }


    if(!MessWindow->Visible)
    {
      NowEvent = CheckSchedule(&TodayEventList, &b_time);
      if( NowEvent != NULL)
      {
       Application->Restore();
       DoSignal(NowEvent->event);
       NowEvent->event.cycle_flags.el.is_showed = 1;
      }
    }

    if(CheckRingDelay)
    {
      if( EventRingTime>0 ) // Ring is ringing
      {
        --EventRingTime;
      }
      else
      {
        CheckRingDelay = false;
        rec = DownRing(&io_res);
        ShowStatus("Отключение звонка ", rec);
      }
    }//CheckRingDelay

  } // work

  // change TodayList at 00:00
  if(n_hour == 0 && n_min == 0)
  {
    if(NewDayCheck)
    {
      MakeTodaySchedule(&BaseEventList, &b_date, &TodayEventList, &IsHolyDay);
      ShowBase();
      NewDayCheck = false;
    }
  }
  else
  {
    NewDayCheck = true;
  }

}
//---------------------------------------------------------------------------








void __fastcall TMainForm::CurrentBaseDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
 int i;

#ifdef GRID_TITLE
  if( (ARow == 0) || (ACol == 0) )
#else
  if( ACol == 0 )
#endif
    {
     i=CurrentBase->Canvas->TextWidth(CurrentBase->Cells[ACol][ARow]);
     i=(CurrentBase->ColWidths[ACol] - i) / 2 ;
     CurrentBase->Canvas->FillRect(Rect);

//     if(ARow>0) CurrentBase->Canvas->Font->Size = 8;

     CurrentBase->Canvas->TextOut(Rect.Left+i,Rect.Top,CurrentBase->Cells[ACol][ARow]);
    }
 if(ACol == 2)
   {
     CurrentBase->Canvas->Font->Color = CurrentBase->Color;
     CurrentBase->Canvas->FillRect(Rect);
     CurrentBase->Canvas->TextOut(Rect.Left,Rect.Top,CurrentBase->Cells[ACol][ARow]);
   }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormResize(TObject *Sender)
{
  MainForm->CurrentBase->ColWidths[1] = MainForm->CurrentBase->Width - COL_MOMENT_WIDTH-22;

}
//---------------------------------------------------------------------------




void __fastcall TMainForm::CurrentBaseSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
 SelGridRow = ARow;

 CanSelect = (ACol != 2);

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CurrentBaseDblClick(TObject *Sender)
{
 int i;
 Ti_Event base;

 if(MessWindow->Visible)
   {
    if (MessWindow->MessPlayer->Mode == mpPlaying)
       {
        MessWindow->MessPlayer->Stop();
        MessWindow->MessPlayer->Close();
       }
   }else
 if(DeleteMode)
   {
    PageControl2->ActivePage = MainMenu;
    DeleteMode = false;
   }else
// if(!DeleteMode)
   {

#ifdef GRID_TITLE
    if (SelGridRow > 0)
#endif
      {
       if (ShowToday)
         {
          i =  TodayList.size();
          if(( SelGridRow <= i) && (i > 0))
            {
#ifdef GRID_TITLE
             base = TodayList[SelGridRow-1];
#else
             base = TodayList[SelGridRow];
#endif
             ShowEditDialog(base);
            }
         }
         else
         {
#ifdef GRID_TITLE
          base = BaseEvent[SelGridRow-1];
#else
          base = BaseEvent[SelGridRow];
#endif
          ShowEditDialog(base);
         }
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButSetupClick(TObject *Sender)
{
  MainForm->Visible=true;
  PageControl1->ActivePage = SetupWin;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButShowTodayClick(TObject *Sender)
{
AnsiString str_date, str_time;

 if (ShowToday == false)
   {
    MainForm->ButShowToday->Font->Color = clGreen;
    MainForm->ButShowToday->Font->Size = 12;
    MainForm->ButAllEvent->Font->Color = clSilver;
    MainForm->ButAllEvent->Font->Size = 10;

      NowString(str_date, str_time);

#ifdef GRID_TITLE
    MainForm->CurrentBase->Cells[1][0] = "События на: " + str_date;
#endif
    ShowBase(TodayList);
    MainForm->CurrentBase->SetFocus();
    ShowToday  = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButAllEventClick(TObject *Sender)
{
 if (ShowToday )
   {
    MainForm->ButShowToday->Font->Color = clSilver;
    MainForm->ButShowToday->Font->Size = 10;
    MainForm->ButAllEvent->Font->Color = clGreen;
    MainForm->ButAllEvent->Font->Size = 12;
#ifdef GRID_TITLE
    MainForm->CurrentBase->Cells[1][0] = "Все события";
#endif
    ShowBase(BaseEvent);

    MainForm->CurrentBase->SetFocus();
    ShowToday  = false;
   }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::AlarmButtonClick(TObject *Sender)
{
  AnsiString buf;

  if(MessWindow->Visible)
  {
    if (MessWindow->MessPlayer->Mode == mpPlaying)
    {
      MessWindow->MessPlayer->Stop();
      MessWindow->MessPlayer->Close();
    }
  }

  if(MediaPlayer1->Mode != mpPlaying)
  {
    buf = GetCurrentDir()+"\\"+DEF_ALARM_SOUND;
    if (FileExists(buf))
      {
       MainForm->StatusBar1->Panels->Items[0]->Text = "";

       MediaPlayer1->FileName=buf;
       MediaPlayer1->Open();
       MediaPlayer1->Play();
      }
      else
      {
       MainForm->StatusBar1->Panels->Items[0]->Text = "Файл " +buf+ " не найден. Укажите другой файл в настройках";
      }
   }
   else
   {
    if (MediaPlayer1->Mode == mpPlaying)  { MediaPlayer1->Stop();   MediaPlayer1->Close(); }
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::But_FireClick(TObject *Sender)
{
  AnsiString buf;

  if(MessWindow->Visible)
  {
    if (MessWindow->MessPlayer->Mode == mpPlaying)
    {
      MessWindow->MessPlayer->Stop();
      MessWindow->MessPlayer->Close();
    }
  }

  if(MediaPlayer1->Mode != mpPlaying)
  {
    buf = GetCurrentDir()+"\\"+DEF_FIRE_SOUND;
    if (FileExists(buf))
      {
       MainForm->StatusBar1->Panels->Items[0]->Text = "";

       MediaPlayer1->FileName=buf;
       MediaPlayer1->Open();
       MediaPlayer1->Play();
      }
      else
      {
       MainForm->StatusBar1->Panels->Items[0]->Text = "Файл " +buf+ " не найден. Укажите другой файл в настройках";
      }
   }
   else
   {
    if (MediaPlayer1->Mode == mpPlaying)  { MediaPlayer1->Stop();  MediaPlayer1->Close(); }
   }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CurrentBaseMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{


 if ( !DeleteMode
     && (MainForm->CurrentBase->Cells[2][MainForm->CurrentBase->Row] != "")
    )
   {
    GridGetMouse = true;
    TimeChoice = 0;
   }
// if (MainForm->DelEvent->Visible)  MainForm->DelEvent->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CurrentBaseMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 GridGetMouse = false;
}
//---------------------------------------------------------------------------






void __fastcall TMainForm::ButDialNoClick(TObject *Sender)
{
 MainForm->DialPanel->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButDialOkClick(TObject *Sender)
{
 BaseEvent.erase(BaseEvent.begin()+DelNumEvent);

 SaveBase(WorkScheduleFile);
 SetTodaySchedule(BaseEvent, TodayList,&IsHolyDay);
 RepaintBase();


 MainForm->DialPanel->Visible = false;
 PageControl2->ActivePage = MainMenu;
 DeleteMode = false;

}
//---------------------------------------------------------------------------




void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  BaseEvent.clear();
  TodayList.clear();
  ViewList.clear();
  SoundFiles.clear();

  EventList_clear(&BaseEventList);
  EventList_clear(&TodayEventList);  // today events
  EventList_clear(&EditEventList);   // edit day events
  EventList_clear(&ViewEventList);   // view day events

  MainForm->Memo1->Lines->Clear();
  MainForm->Memo2->Lines->Clear();
  MainForm->Memo3->Lines->Clear();

  CloseCOMPort();
  MessWindow->MessPlayer->Close();
  MainForm->MediaPlayer1->Close();

  SaveSettings(&UseSoundFiles);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RingButtonClick(TObject *Sender)
{
  T_Result io_res;
  unsigned int res;

  T_RingIO_Head  ring_comm, kv_ring_comm;


  if( ! IsCOMOpen() )
  {
    MainForm->StatusBar1->Panels->Items[0]->Text = "Соединение с Ring не установлено";
  }
  else
  {
    MainForm->Memo2->Lines->Clear();

    if(MainForm->RingButton->Caption == "Звонок")
    {
      res = UpRing(0, &io_res);
      ShowStatus("Включение звонка ", res);
    }
    else

    if(MainForm->RingButton->Caption == "СТОП")
    {
      res = DownRing(&io_res);
      ShowStatus("Отключение звонка ", res);
    }// STOP

  }// open COM

}
//---------------------------------------------------------------------------



void __fastcall TMainForm::ButAddEventClick(TObject *Sender)
{
 if(MessWindow->Visible)
   {
    if (MessWindow->MessPlayer->Mode == mpPlaying)
       {
        MessWindow->MessPlayer->Stop();
        MessWindow->MessPlayer->Close();
       }
   }
   else
  ShowAddDialog();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeedButton6Click(TObject *Sender)
{
  PageControl1->ActivePage = SchedWin;       
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButEMBackClick(TObject *Sender)
{
 PageControl2->ActivePage = MainMenu;
 DeleteMode = false;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButClearClick(TObject *Sender)
{
 if( MainForm->FlagLog->Checked) MainForm->Memo1->Lines->Clear();
 if( MainForm->FlagBuffer->Checked) MainForm->Memo2->Lines->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ButDelEventClick(TObject *Sender)
{
 DelNumEvent = StrToInt(MainForm->CurrentBase->Cells[2][MainForm->CurrentBase->Row]);
 MainForm->Label2->Caption = MainForm->CurrentBase->Cells[0][MainForm->CurrentBase->Row];
 MainForm->Label3->Caption = MainForm->CurrentBase->Cells[1][MainForm->CurrentBase->Row];




 MainForm->DialPanel->Visible = true;

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::butchClick(TObject *Sender)
{
  unsigned int res;

  RingAutoControl = false;
  MainForm->butch->Enabled = false;
  
  res = GetTransmit();

  ShowStatus("Транзит данных", res);

  MainForm->butch->Enabled = true;
  RingAutoControl = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::COMConnectClick(TObject *Sender)
{
 AnsiString com_name;
 T_Result COMres;
 unsigned int num_port, port_speed;
 unsigned char data_size, parity;


 if(IsCOMOpen())
   {
    CloseCOMPort();
    MainForm->COMConnect->Caption = "Подключение";
    MainForm->StatusBar1->Panels->Items[0]->Text = MainForm->COMList->Text + " отключен";
    MainForm->ButCommSetup->Enabled =false;
   }
   else
 if(GetCOMCount() == 0) FindComm();
   else
   {
    COMres = LinkCOM(MainForm->COMList->Text);

    if(COMres == COM_CREATE_ERROR) FindComm();
   }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButCommSetupClick(TObject *Sender)
{

 COMMCONFIG comm_config;
 unsigned long size;
 HANDLE *port;
 AnsiString as;

 port = GetCommHandle();
 as = MainForm->COMList->Text;

 if (IsCOMOpen())
   {
    GetCommConfig(*port,&comm_config,&size);
    MainForm->FormStyle=fsNormal;
    if(CommConfigDialogA(as.c_str(),0,&comm_config))
      {
       SetCommConfig(*port,&comm_config,size);
      }
    MainForm->FormStyle=fsStayOnTop;  
   }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButStartClick(TObject *Sender)
{
  int res, i;

  RingAutoControl = false;
  MainForm->ButStart->Enabled = false;

  if(IsCOMOpen())
  {
    stop_process = false;
    i = 1;
    while (i != 5 && !stop_process )
    {
     Application->ProcessMessages();
      switch (i)
      {
        case 1:
        case 3:
        {
          res = GetRingState();
          ShowStatus("Опрос состояние Ring: ", res);
          if(res == R_OK)
          {
            if(i==1) i=2; else i=4;
          }else i=5;
          break;
        }
        case 2:
        {
          if(MainForm->FSyncShed->Checked)
          {
            res = SendSchedule(WorkScheduleFile);
            ShowStatus("Ring: передача расписания", res);
            if(res == R_OK) i=3; else i = 5;
            break;
          }else i = 4;
        }
        case 4:
        {
          if(MainForm->FSyncTime->Checked)
          {
            res = TimeSync();
            ShowStatus("Ring:  синхронизация времени", res);
          }
          i = 5;
          Sleep(MainForm->COMDelayBF->Position);
        }
      }//switch
    }// while
  }
  else
  {
    stop_process = true;
    MainForm->StatusBar1->Panels->Items[0]->Text = "Соединение с Ring не установлено";
  }

  MainForm->ButStart->Enabled = true;
  RingAutoControl= true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButStopClick(TObject *Sender)
{
  stop_process = true;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButSigBackClick(TObject *Sender)
{
 PageControl2->ActivePage = MainMenu;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButSoundClick(TObject *Sender)
{
  AnsiString buf;

  if(MessWindow->Visible)
  {
    if (MessWindow->MessPlayer->Mode == mpPlaying)
    {
      MessWindow->MessPlayer->Stop();
      MessWindow->MessPlayer->Close();
    }
  }

 if(MediaPlayer1->Mode != mpPlaying)
   {
    buf = UseSoundFiles.SetRingFile;
    if (FileExists(buf))
      {
       MainForm->StatusBar1->Panels->Items[0]->Text = "";

       MediaPlayer1->FileName=buf;
       MediaPlayer1->Open();
       MediaPlayer1->Play();
      }
      else
      {
       MainForm->StatusBar1->Panels->Items[0]->Text = "Файл " +buf+ " не найден. Укажите другой файл в настройках";
      }
   }
   else
   {
    if (MediaPlayer1->Mode == mpPlaying)  { MediaPlayer1->Stop();  MediaPlayer1->Close(); }
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButBackClick(TObject *Sender)
{
 PageControl1->ActivePage = SchedWin;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButEditBackClick(TObject *Sender)
{
 PageControl1->ActivePage = SchedWin;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButSaveEventClick(TObject *Sender)
{
 SaveEvent(false);
 SaveBase(WorkScheduleFile);
 SetTodaySchedule(BaseEvent, TodayList,&IsHolyDay);
 RepaintBase();

 MainForm->MediaPlayer1->Stop();  MainForm->MediaPlayer1->Close();

 MainForm->PageControl1->ActivePage = MainForm->SchedWin;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer2Timer(TObject *Sender)
{

  if(GridGetMouse)
  {
    ++TimeChoice;
    if (TimeChoice >= UpDownCounter)
    {
      PageControl2->ActivePage = EditMenu;
      DeleteMode = true;
      GridGetMouse = false;
    }
  }

 if(fix_inc_hour)
    {
     if ( f_hour == 23)  f_hour = 0;  else ++f_hour;
    }else
  if(fix_dec_hour)
    {
      if ( f_hour == 0) f_hour = 23; else --f_hour;
    }
  if(fix_inc_min)
    {
     if ( f_min == 59)  f_min = 0;  else ++f_min;
    }else
  if(fix_dec_min)
    {
      if ( f_min == 0) f_min = 59; else --f_min;
    }

   if( fix_inc_hour || fix_dec_hour ) SetHour(f_hour);
   if( fix_inc_min || fix_dec_min ) SetMinute(f_min);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButSaveasClick(TObject *Sender)
{
 SaveEvent(true);
 SaveBase(WorkScheduleFile);
 SetTodaySchedule(BaseEvent, TodayList,&IsHolyDay);
 RepaintBase();
 MediaPlayer1->Stop();  MediaPlayer1->Close();
 PageControl1->ActivePage = SchedWin;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::But_dateClick(TObject *Sender)
{
 //MainForm->PageControl3->ActivePage = MainForm->DayTab;

 SetUseDate(false,true,true); // year,month,day
 SetVariant();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::But_dailyClick(TObject *Sender)
{
 MainForm->DateEvent->Caption = "Ежедневно";

// MainForm->PageControl3->ActivePage = MainForm->DayTab;
 SetUseDate(false,false,false); // year,month,day
 SetVariant();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::But_monthlyClick(TObject *Sender)
{
// MainForm->PageControl3->ActivePage = MainForm->DayTab;

 MainForm->DateEvent->Caption = "Каждое число";

 SetUseDate(false,false,true); // year,month,day
 SetVariant();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::But_weeklyClick(TObject *Sender)
{
 MainForm->PageControl3->ActivePage = MainForm->WeekTab;
 SetUseDate(false,false,false); // year,month,day
 SetVariant();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_monClick(TObject *Sender)
{
 SetWeek();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_tueClick(TObject *Sender)
{
 SetWeek();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_wedClick(TObject *Sender)
{
 SetWeek();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_thurClick(TObject *Sender)
{
 SetWeek();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_friClick(TObject *Sender)
{
 SetWeek();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_satClick(TObject *Sender)
{
 SetWeek();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_sunClick(TObject *Sender)
{
 SetWeek();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Is_selebClick(TObject *Sender)
{
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DateTimePicker1Change(TObject *Sender)
{
 ChangeDate(0);
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_yearClick(TObject *Sender)
{
 SetLinkDate();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_monthClick(TObject *Sender)
{
 SetLinkDate();
 SetVariant();
 ShowMomentTitle();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::At_dayClick(TObject *Sender)
{
 SetLinkDate();
 SetVariant();
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SigFilesChange(TObject *Sender)
{
 AnsiString str_buf;
 
  str_buf = SoundFiles[MainForm->SigFiles->ItemIndex].full_name;
  if (FileExists(str_buf))
    {
     MainForm->MediaPlayer1->FileName=str_buf;
     MainForm->MediaPlayer1->Open();
    }        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OpenSoundClick(TObject *Sender)
{

 AnsiString fn, str_buf;
 int i;

 MainForm->OpenDialog1->InitialDir=GetCurrentDir();

 if ( MainForm->OpenDialog1->Execute())
   {
    fn = MainForm->OpenDialog1->FileName;
    str_buf = ExtractFileExt(fn);
    if(str_buf == ".wav" || str_buf == ".mp3" )
      {
       str_buf = ExtractFileName(fn);
       i =  GetIDSound(str_buf);
       if(i >= 0)
         {
          MainForm->SigFiles->Text = str_buf;
          MainForm->SigFiles->ItemIndex = i;
          MainForm->StatusBar1->Panels->Items[0]->Text = "Файл есть в списке!";
         }
         else   //  add new one
         {
          AddSoundList(fn);
          MainForm->SigFiles->Items->Add(str_buf);
          MainForm->SigFiles->ItemIndex = MainForm->SigFiles->Items->Count-1;

          MainForm->MediaPlayer1->FileName=fn;
          MainForm->MediaPlayer1->Open();

          MainForm->StatusBar1->Panels->Items[0]->Text = "добавлен новый звуковой файл в список";
         }
      }
      else
      {
       MainForm->StatusBar1->Panels->Items[0]->Text = "Формат в выбраного файла не поддерживается";
      }
     
   }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FUseHourClick(TObject *Sender)
{
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FUseHourMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 SetUseHour(!MainForm->FUseHour->Checked);        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FUseMinuteClick(TObject *Sender)
{
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FUseMinuteMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 SetUseMinute(!MainForm->FUseMinute->Checked);         
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IncHourClick(TObject *Sender)
{
 if ( f_hour == 23)  f_hour = 0;  else ++f_hour;

 SetHour(f_hour);
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IncHourMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  fix_inc_hour = true;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IncHourMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 fix_inc_hour = false;
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IncMinuteClick(TObject *Sender)
{
 if ( f_min == 59) f_min = 0; else ++f_min;

 SetMinute(f_min);
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IncMinuteMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 fix_inc_min = true;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IncMinuteMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  fix_inc_min = false;
  ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DecHourClick(TObject *Sender)
{
 if ( f_hour == 0) f_hour = 23; else --f_hour;
 
 SetHour(f_hour);
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DecHourMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  fix_dec_hour = true;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DecHourMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  fix_dec_hour = false;
  ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DecMinuteClick(TObject *Sender)
{
 if ( f_min == 0) f_min = 59; else --f_min;
 
 SetMinute(f_min);
 ShowMomentTitle();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DecMinuteMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 fix_dec_min = true;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DecMinuteMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   fix_dec_min = false;
  ShowMomentTitle();        
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ButSupCheckClick(TObject *Sender)
{
 ShowSupResults(SHOW_LOG_STATE);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::DateEventClick(TObject *Sender)
{
  MainForm->PageControl3->ActivePage = MainForm->DayTab;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimeEventClick(TObject *Sender)
{
  MainForm->PageControl3->ActivePage = MainForm->TimeTab;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SoundEventClick(TObject *Sender)
{
    MainForm->PageControl3->ActivePage = MainForm->SignalTab;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RingEventClick(TObject *Sender)
{
     MainForm->PageControl3->ActivePage = MainForm->SignalTab;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DayBackClick(TObject *Sender)
{
  MainForm->PageControl3->ActivePage = MainForm->MainTab;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WeekBackClick(TObject *Sender)
{
  MainForm->PageControl3->ActivePage = MainForm->MainTab;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimeBackClick(TObject *Sender)
{
  MainForm->PageControl3->ActivePage = MainForm->MainTab;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SigBackClick(TObject *Sender)
{
    MainForm->PageControl3->ActivePage = MainForm->MainTab;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ButStateRingClick(TObject *Sender)
{
  int res;

  MainForm->ButStateRing->Font->Color = clGray;
  RingAutoControl = false;

  res = GetRingState();
  ShowStatus("Опрос состояние Ring: ", res);

  RingAutoControl = true;

}
//---------------------------------------------------------------------------





void __fastcall TMainForm::Is_selebMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//  if(Is_seleb->Checked) Is_seleb->Font->Color = clGray;
 // else  Is_seleb->Font->Color = clGreen;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::AltReadScheduleClick(TObject *Sender)
{
  AnsiString as_buf;

  TFileStream  * tfile;
  char* virtual_file;


  T_EventList BaseEventList, TodayEvList;

  Ti_Event event;
  s_Date b_date;
  s_Time b_time;

  unsigned short k;
  unsigned short n_year, n_mon, n_day, n_wd;
  unsigned short n_hour, n_min, n_sec, n_msec;
  TDateTime dt;


  dt = Now();
  dt.DecodeDate(&n_year,&n_mon,&n_day);
  dt.DecodeTime(&n_hour,&n_min,&n_sec,&n_msec);
  n_wd = dt.DayOfWeek();
  if(n_wd == 1) n_wd = 6; else n_wd -=2;

  b_date.year = n_year;
  b_date.month = n_mon;
  b_date.day = n_day;
  b_date.weekday = n_wd;

  b_time.hour = n_hour;
  b_time.minute = n_min;
  b_time.second = n_sec;

  MainForm->Memo1->Lines->Clear();

  EventList_init(&BaseEventList);
  EventList_init(&TodayEvList);

  EventList_ReadFile(WorkScheduleFile.c_str(),&BaseEventList);

  // check once in 24 hours
  MakeTodaySchedule(&BaseEventList, &b_date, &TodayEvList, &IsHolyDay);

  // check in every minute
  k =  CheckSchedule(&TodayEvList, &b_time);

  TodayList.clear();
  for(k=0; k < TodayEvList.size; k++)
  {
    event = EventList_get(&TodayEvList, k);
    TodayList.push_back(event);
  }
  ShowBase(TodayList);

  EventList_clear(&BaseEventList);
  EventList_clear(&TodayEvList);




/*
  tfile=new TFileStream(WorkScheduleFile,fmOpenReadWrite);

  if(tfile->Size == 0)
  {
    tfile->Free();
    MainForm->Memo1->Lines->Add("Ошибка открытия файла");
  }
  else
  {
    tfile->Seek(0,0);
    virtual_file = (char *) malloc(tfile->Size);

    if( virtual_file == NULL )
    {
      tfile->Free();
      MainForm->Memo1->Lines->Add("Ошибка выделения памяти virtual_file");
    }
    else
    {
      tfile->Read(virtual_file,tfile->Size);
      MainForm->Memo1->Lines->Add("Get virtual_file");



      EventList_ReadMem(virtual_file, tfile->Size, &BaseEventList);

      // check once in 24 hours
      MakeTodaySchedule(&BaseEventList, &b_date, &TodayEvList, &IsHolyDay);

      // check in every minute
      k =  CheckSchedule(&TodayEvList, &b_time);

      TodayList.clear();
      for(k=0; k < TodayEvList.size; k++)
      {
        event = EventList_get(&TodayEvList, k);
        TodayList.push_back(event);
      }
      ShowBase(TodayList);

      EventList_clear(&BaseEventList);
      EventList_clear(&TodayEvList);

      free(virtual_file);
      tfile->Free();
    }
  }

 */
}
//---------------------------------------------------------------------------

