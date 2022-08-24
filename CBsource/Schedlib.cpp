
#include "Schedlib.h"

// For example
// vector <t_Event> BaseEvent;  // Full base of events
// vector <t_Event> TodayList;  // Today events


AnsiString MonthName[] = {"января","февраля","марта", "апреля",
                           "мая", "июня", "июля", "августа",
                           "сентября", "октября", "ноября", "декабря"};


AnsiString WeekSDay[] = {"Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"};




void InitEvent(t_Event * event)
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

   //event->end_date = event->start_date;

   event->start_time.hour = 0;
   event->start_time.minute = 0;
   event->start_time.second = 0;
   event->start_time.use_hour = true;
   event->start_time.use_minute = true;
   event->start_time.use_second = false;

   //event->end_time = event->start_time;
   //event->pre_start_time = event->start_time;
   //event->pre_end_time = event->start_time;


   event->cycle_flags.all_flags = 0;
   event->cycle_flags.el.id_event = -1;
   event->cycle_flags.el.id_rfile = -1;
   event->event_sign.all_signs = 0;
   event->event_sign.el.ring_time = 10;

   #ifdef ENV_BORLAND_BUILDER
      event->message_file = "";
      event->message_text = "";
   #endif
   event->Message.clear();
  }

int SetTodaySchedule(vector <t_Event> & base, vector <t_Event> & shed)
 {
  TDateTime dt;
  unsigned short n_year, n_mon, n_day, n_wd, i;

  dt=Now();
  dt.DecodeDate(&n_year,&n_mon,&n_day);
  n_wd = dt.DayOfWeek();
  if(n_wd == 1) n_wd = 6;
    else n_wd -=2;

 vector<t_Event>::iterator iter = base.begin();

  if( base.empty() )
    {
     return 1;
    }
    else
    {
     shed.clear();

     while ( iter != base.end() )
       {
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
    }
    
   return 0;
 }

unsigned int CheckSchedule(vector <t_Event> & base)
{
 TDateTime dt;
 unsigned short n_hour, n_min, n_sec, n_msec;
 int  find;

 dt=Now();
 dt.DecodeTime(&n_hour,&n_min,&n_sec, &n_msec);

 vector<t_Event>::iterator iter = base.begin();

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

#ifdef ENV_BORLAND_BUILDER
int MomentToStr( t_Date in_date,
                 t_Time in_time,
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
    if (in_date.use_day) str_date=str_date+" число ";
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
      else str_time=str_buf+" мин.";
   }
   else
   {
    if (in_time.use_hour) str_time=str_time+" ч.";
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


