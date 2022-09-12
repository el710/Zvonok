#include "malloc.h"

#include "Schedlib.h"


AnsiString MonthName[] = {"������","�������","�����", "������",
                           "���", "����", "����", "�������",
                           "��������", "�������", "������", "�������"};


AnsiString WeekSDay[] = {"��", "��", "��", "��", "��", "��", "��"};



//======== function's implement

int NewEvent(T_Event * event)
{
  char* p_char;
  p_char = (char *) malloc(MESSAGE_ROW_SIZE);
  if( p_char == NULL ) return EL_RES_NO_MEMORY;
  event->caption = p_char;

  p_char = (char *) malloc(SOUND_FILENAME_SIZE);
  if( p_char == NULL )
  {
   free(event->caption);
   return EL_RES_NO_MEMORY;
  }
  event->sound = p_char;

  event->caption[0] = 0;
  event->sound[0] = 0;

  return EL_RES_OK;
}

void ZeroEvent(T_Event * event)
{
  event->start_date.use_day = false;
  event->start_date.use_month = false;
  event->start_date.use_year = false;
  event->start_date.use_weekly = false;

  event->start_date.year = 0;
  event->start_date.month = 0;
  event->start_date.day = 0;
  event->start_date.weekday=0;
  event->start_date.exclusive_day=false;

  event->start_time.hour = 0;
  event->start_time.minute = 0;
  event->start_time.second = 0;
  event->start_time.use_hour = true;
  event->start_time.use_minute = true;
  event->start_time.use_second = false;

  event->cycle_flags.all_flags = 0;
  event->cycle_flags.el.id_event = -1;
  event->cycle_flags.el.id_rfile = -1;
  event->event_sign.all_signs = 0;
  event->event_sign.el.ring_time = 10;

}
//==================================================

void EventList_init(T_EventList* list)
{
  list->first = NULL;
  list->last = NULL;
  list->size = 0;
}
//==================================================

void EventList_clear(T_EventList* id_list)
{

 void* a;
 T_ListItem* b = id_list->last;


 for(int i = 0; i<id_list->size; i++)
 {
   a = b->prev;
   free(b->event.caption);
   free(b->event.sound);
   free(b);
   if(a != NULL) b = (T_ListItem*)a;
 }

 EventList_init(id_list);
}
//==================================================


T_ListItem* EventList_push(T_EventList* id_list, T_Event* in_event)
{
  T_ListItem* new_item;
  int res;

  new_item = (T_ListItem*) malloc(sizeof(T_ListItem));
  if( new_item == NULL ) return NULL;

  new_item->next = NULL;
  new_item->event.start_date = in_event->start_date;
  new_item->event.start_time = in_event->start_time;
  new_item->event.cycle_flags.all_flags = in_event->cycle_flags.all_flags;
  new_item->event.event_sign.all_signs = in_event->event_sign.all_signs;

  res = NewEvent(&new_item->event);
  if( res == EL_RES_NO_MEMORY )
  {
    free(new_item);
    return NULL;
  }
  strcpy(new_item->event.caption, in_event->caption);
  strcpy(new_item->event.sound, in_event->sound);

  if(id_list->size ==0)
  {
    new_item->prev = NULL;
    id_list->first = new_item;
  }
  else
  {
    new_item->prev = id_list->last;
    id_list->last->next = new_item;
  }

  id_list->last = new_item;
  id_list->size++;

  return new_item;
}
//==================================================

T_Event EventList_get(T_EventList* id_list, unsigned int in_num)
{
  T_ListItem* iter = id_list->first;

  if((in_num + 1) > id_list->size) return id_list->last->event;

  for( unsigned int i = 0; i < in_num; i++ )
  {
    iter = (T_ListItem*)iter->next;
  }

  return iter->event;
}
//==================================================

int EventList_ReadMem(char* in_memfile, unsigned int in_size, T_EventList* out_list)
{
  unsigned int point; // iterator for in_memfile
  unsigned short state = 0; // read states of event records
  int i_ch; // iterator for char string
  unsigned short mes_str_num; // iterator for text strings

  char str[FILE_STRING_SIZE_MAX]={0};  // string buffer
  unsigned int num; // number buffer
  T_Event event; // event buffer

  unsigned short j,k;  // counters

  if(in_memfile == NULL) return EL_RES_NULL_POINTER;

  NewEvent(&event);

  point = 0; state = 0;

  while(point < in_size)
  {
    // read string
    i_ch = 0;
    while(  in_memfile[point] != FILE_STRING_END_CHAR
          && point < in_size
          && i_ch < FILE_STRING_SIZE_MAX)
    {
     str[i_ch++] = in_memfile[point++];
//     i_ch++;
//     point++;
    }
    str[i_ch] = 0;

    if(in_memfile[point] == FILE_STRING_END_CHAR) point++;

    if(str[0] == FILE_RECORD_SEPARATOR)
    {
      state = 1;   // new record
      ZeroEvent(&event);
    }
    else
    {
      if(state == 1)  // event
      {
        j=0;  // iterator for str[]
        for(k=0; k<FILE_PARAMETERS_COUNT; k++) //disassembly of str[]
        {
          num=0;
          while(str[j] != FILE_PARAM_SEPARATOR)
          {
            num = (num * 10) + (str[j] - ASCII_NUMBER_BASE);
            j++;
          }
          j++;

          switch (k)
          {
           case 0: { event.start_date.year = num; break; }
           case 1: { event.start_date.month = num; break; }
           case 2: { event.start_date.day  = num; break; }
           case 3: { event.start_date.weekday = num; break; }
           case 4: { event.start_date.use_year = (num == 1); break; }
           case 5: { event.start_date.use_month = (num == 1); break; }
           case 6: { event.start_date.use_day = (num == 1); break; }
           case 7: { event.start_date.use_weekly = (num == 1); break; }
           case 8: { event.start_date.exclusive_day = (num == 1); break; }
           case 9: { event.start_time.use_hour = (num == 1); break; }
           case 10: { event.start_time.use_minute = (num == 1); break; }
           case 11: { event.start_time.use_second = (num == 1); break; }
           case 12: { event.start_time.hour = num; break; }
           case 13: { event.start_time.minute = num; break; }
           case 14: { event.start_time.second = num; break; }
           case 15: { event.cycle_flags.all_flags = num; break; }
           case 16: { event.event_sign.all_signs = num; break; }
           case 17: { event.cycle_flags.el.id_rfile = num; break; }
          }//switch
        }//for k

        state = 2; // next string is sound file
      }
      else
      if(state == 2) // sound file
      {
        if(i_ch == 0)
          {
            event.event_sign.el.is_sound = 0;
          }
          else
          {
            if(i_ch > SOUND_FILENAME_SIZE) i_ch = SOUND_FILENAME_SIZE;
            strncpy(event.sound,str,i_ch);
            event.sound[i_ch] = 0;
            event.event_sign.el.is_sound = 1;
          }

        mes_str_num=0;
        state = 3; // next string is message
      }
      else
      if(state == 3) // message
      {
        if(mes_str_num == 0)
        {
          if(i_ch > MESSAGE_ROW_SIZE) i_ch = MESSAGE_ROW_SIZE;
          strncpy(event.caption,str,i_ch);
          event.caption[i_ch] = 0;
        }
        if(mes_str_num < event.cycle_flags.el.id_rfile)
        {
          ++mes_str_num;

          if(mes_str_num == event.cycle_flags.el.id_rfile)   // last string of text
          {
            EventList_push(out_list, &event);

            state = 0; // next event record
          }
        }
      }//state 3
    }// event data
  }// while eofile

  return EL_RES_OK;
}
//==================================================

int MakeTodaySchedule(T_EventList* in_base, s_Date* in_date,
                      T_EventList* out_list, bool* out_holyday)
{
  T_Event event;
  bool check_holyday;
  bool found_holyday = false;

  unsigned short i, k;

  if( in_base->size ==0 ) { return EL_RES_BASE_EMPTY; }

  EventList_clear(out_list);


  check_holyday = false;
  for(k=0; k < in_base->size; k++)
  {
    event = EventList_get(in_base, k);

    // check is today Holyday
    if(  (   event.start_date.day == in_date->day     // event day is today
          && event.start_date.month == in_date->month
         )
       ||(   event.start_date.use_weekly            // or event weekday
          && event.start_date.weekday == in_date->weekday   // is now
         )
      )
    {
      if(   check_holyday == false
         && event.start_date.exclusive_day   // event is holyday
        )
      { found_holyday = true; check_holyday = true; }
      else { found_holyday = false; }
    }

    if( !event.start_date.use_year || (event.start_date.year == in_date->year) ) // every year or in this year
    {
      if( !event.start_date.use_month || (event.start_date.month == in_date->month) )
      {
        if( !event.start_date.use_day || (event.start_date.day == in_date->day) )
        {
          if( !event.start_date.use_day)
          {
            if(event.start_date.use_weekly)
            {
              for(i=0;i<7;i++)   // week-day
              {
                if( (event.start_date.weekday & (1 << i)) != 0 )
                {
                  if(in_date->weekday == i)
                  {
                    EventList_push(out_list, &event); break;
                  }
                }
              }//for
            }// weekly
            else EventList_push(out_list, &event);
          } //not day
          else EventList_push(out_list, &event);
        }// every day or in this day
      }// every month or in this month
    }// every year or in this year

  }// for

  *out_holyday = found_holyday;
  return EL_RES_OK;
}
//==================================================

unsigned int CheckSchedule(T_EventList* in_base, s_Time* in_time)
{
  unsigned short i;
  T_Event event;

  if(in_base->size == 0) return EL_RES_NO_EVENT;

  for(i=0; i < in_base->size; i++)
  {
    event = EventList_get(in_base, i);

    if(event.cycle_flags.el.is_showed ==0 )
    {
     if((!event.start_time.use_hour) || (event.start_time.hour == in_time->hour))
       if((!event.start_time.use_minute) || (event.start_time.minute == in_time->minute))
       {
         return i;
       }
    }

  }// for

 return EL_RES_NO_EVENT;
}
//==================================================


int SetTodaySchedule(vector <T_Event> & base, vector <T_Event> & shed, bool* out_holyday)
{
  TDateTime dt;
  unsigned short n_year, n_mon, n_day, n_wd, i;
  bool found_holyday = false;

  vector<T_Event>::iterator iter = base.begin();

  dt=Now();
  dt.DecodeDate(&n_year,&n_mon,&n_day);
  n_wd = dt.DayOfWeek();
  if(n_wd == 1) n_wd = 6; else n_wd -=2;

  if( base.empty() ) { return EL_RES_BASE_EMPTY; }

  shed.clear();

  while ( iter != base.end() )
  {
    // check is today Holyday
    if(!found_holyday)
    {
      if(  (   iter->start_date.day == n_day     // event day is today
            && iter->start_date.month == n_mon
           )
         ||(   iter->start_date.use_weekly       // or event weekday
            && iter->start_date.weekday == n_wd  // is now
           )
        )
        {
          if(iter->start_date.exclusive_day) found_holyday = true;  // event is holyday
        }
    }


        if( !iter->start_date.use_year || (iter->start_date.year == n_year) ) // every year or in this year
          {
           if( !iter->start_date.use_month || (iter->start_date.month == n_mon) )
             {
              if( !iter->start_date.use_day || (iter->start_date.day == n_day) )
                {
                 if( !iter->start_date.use_day)
                   {
                    if(iter->start_date.use_weekly)
                      {
                       for(i=0;i<7;i++)   // week-day
                       {
                        if( (iter->start_date.weekday & (1 << i)) != 0 )
                          {
                           if(n_wd == i)
                             {
                              shed.push_back(*iter); break;
                             }
                          }
                       }//for
                      }// weekly
                      else
                      {
                       shed.push_back(*iter);
                      }
                   } //not day
                   else shed.push_back(*iter);
                }// every day or in this day
             }// every month or in this month
          }// every year or in this year
        ++iter;
       }

   *out_holyday = found_holyday;
   return EL_RES_OK;
 }
//==================================================

unsigned int CheckSchedule(vector <T_Event> & base)
{
 TDateTime dt;
 unsigned short n_hour, n_min, n_sec, n_msec;
 int  find;

 dt=Now();
 dt.DecodeTime(&n_hour,&n_min,&n_sec, &n_msec);

 vector<T_Event>::iterator iter = base.begin();

  find = 0;

  if( base.empty() )
    {
     return -1;
    }
    else
    {
     while ( iter != base.end() )
       {
        if (iter->cycle_flags.el.is_showed ==0 )
          {
           if ((iter->start_time.hour == n_hour) && (iter->start_time.minute == n_min))
             return find;
          }
        ++iter;
        ++find;
       }// while
    }

 return -1;
}
//==================================================


#ifdef ENV_BORLAND_BUILDER
int MomentToStr( T_Date in_date,
                 T_Time in_time,
                 AnsiString * out_day,
                 AnsiString * out_time)
{
 int i, c_f, c_e;
 AnsiString str_date, str_time, str_buf;

 str_date=""; str_time="";

 if(in_date.exclusive_day) str_date="* ";

 if(in_date.use_day) str_date=str_date + IntToStr(in_date.day);
 if(in_date.use_month)
   {
    //if (!event.start_date.use_day) str_date=MonthOfDay[event.start_date.mounth-1];
    //  else
    str_date=str_date+" "+MonthName[in_date.month-1];
   }
   else
   {
    if (in_date.use_day) str_date=str_date+" ����� ";
   }
 if(in_date.use_year)
   {
    if (in_date.use_month)
      {
       str_date=str_date+" "+IntToStr(in_date.year);
      }
      else str_date=str_date+IntToStr(in_date.year);
   }

 if(in_date.use_weekly)
   {
    c_f=c_e=-1;
    for (i=0;i<7;i++)
      {
       if( (in_date.weekday & (1 << i)) != 0 )
         {
          if (c_f == -1) c_f = i;
          c_e = i;
         }
      }// for

    if(c_f != -1)
      {
       str_date=str_date + WeekSDay[c_f];
       if( (c_e != -1) && (c_e != c_f) )
         str_date=str_date + ".."+WeekSDay[c_e];
      }
   } // weekly

 *out_day = str_date;

 if(in_time.use_hour) str_time=IntToStr(in_time.hour);

 if(in_time.use_minute)
   {
    if (in_time.minute<10)
      {
       str_buf = "0"+ IntToStr(in_time.minute);
      }
      else str_buf = IntToStr(in_time.minute);

    if (in_time.use_hour) str_time=str_time+":"+str_buf;
      else str_time=str_buf+" ���.";
   }
   else
   {
    if (in_time.use_hour) str_time=str_time+" �.";
//      else
//      {
//       str_time="-";
//      }
   }

 *out_time = str_time;
 /*
 if(str_date != "")
   {
    if (str_time != "") str_date = str_date+" - "+str_time;
   }
   else
     {
      if(str_time != "") { str_date = str_time; }
     }

 *text = str_date+" ";
 */
 return 0;
}



#endif


