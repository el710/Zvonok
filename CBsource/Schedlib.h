#pragma once
#ifndef SHEDULE_LIB_HEADER
#define SHEDULE_LIB_HEADER

#define ENV_BORLAND_BUILDER  //use in Borland Builder C++

#ifdef ENV_BORLAND_BUILDER
   #include <vcl.h>
#endif

#include <vector>

using namespace std;

#define WD_MONDAY   0x1
#define WD_TUESDAY  0x2
#define WD_WEDNSDAY 0x4
#define WD_THURSDAY 0x8
#define WD_FRIDAY   0x10
#define WD_SATURDAY 0x20
#define WD_SUNDAY   0x40


typedef struct
{
 unsigned year    :16;  // 0x270F
 unsigned month   :4;   // 0xC
 unsigned day     :5;   // 0x1F
 unsigned weekday :7;   //  WD_MONDAY +... + WD_SUNDAY

 bool use_year:1;
 bool use_month:1;
 bool use_day:1;
 bool use_weekly:1;
 bool exclusive_day:1;     // this date is exclusive - for Example New Year Day

}t_Date;

typedef struct
{
 bool use_hour;
 bool use_minute;
 bool use_second;

 unsigned hour;  // 0x1F
 unsigned minute;
 unsigned second;
}t_Time;


typedef struct
{
 t_Date start_date;

 t_Time start_time;

 union
   {
    unsigned int all_flags;
    struct
      {
       int id_event        : 21;
       int id_rfile        : 8;
       unsigned is_event_active : 1;    // active / hide
       unsigned is_showed : 1;
       unsigned even_in_exclusive : 1;  // show event in exclusive days
      }el;
   }cycle_flags;

 union
   {
    unsigned int all_signs;
    struct
      {
       unsigned ring_time :8; // in seconds
       unsigned is_ring : 1;
       unsigned is_sound : 1;
       unsigned is_text : 1;
      }el;
   }event_sign;


 #ifdef ENV_BORLAND_BUILDER
   AnsiString message_file;
   AnsiString message_text;


   vector <AnsiString> Message;

 #endif

}t_Event;


extern AnsiString MonthName[];


void InitEvent(t_Event * event);

int SetTodaySchedule(vector <t_Event> & base, vector <t_Event> & shed);

unsigned int CheckSchedule(vector <t_Event> & base);

#ifdef ENV_BORLAND_BUILDER
   int MomentToStr(t_Date in_date,
                   t_Time in_time,
                   AnsiString * out_day,
                   AnsiString * out_time);
//   int MomentToStr(t_Date &n_date, t_Time & n_time, AnsiString * text);


#endif

#endif // SHEDULE_LIB_HEADER
