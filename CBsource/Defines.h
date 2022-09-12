#ifndef DEFINES_H
#define DEFINES_H


#define SHOW_LOG_STATE     0
#define SHOW_WIN_STATE     1

//---------------------------------
//------  Support plan


typedef enum { SUP_IS_COMM,          //1 - наличие СОМ портов
               SUP_DEF_COMM,         //2 -
               SUP_IS_MANUAL,        //3 -
               SUP_IS_SETUP,         //4 -
               SUP_FREAD_SETUP,      //5 -  ошибки чтения файла настроек
               SUP_IS_DALARM_FILE,   //6 -
               SUP_IS_UALARM_FILE,   //7 -
               SUP_IS_DFIRE_FILE,    //8 -
               SUP_IS_UFIRE_FILE,    //9 -
               SUP_IS_DRING_FILE,    //10 -
               SUP_IS_URING_FILE,    //11 -
               SUP_IS_RSCHED_FILE,   //12 -
               SUP_IS_DSCHED_FILE,   //13 -
               SUP_IS_EXSCHED_FILE,  //14 -
               SUP_IS_SCHED_FILE,    //15 -

               SUP_RING_NO_ANSWER,
               SUP_RING_SETUP,
               SUP_RING_RTC_NO,
               SUP_RING_RTC_RESET,
               SUP_RING_DS3231_NO,
               SUP_RING_DS3231_RESET,
               SUP_RING_SCHED_NO,
               SUP_RING_SCHED_MEM,

               SUPPORT_PLAN_SIZE
             }T_SUP_STEPS;

AnsiString SupMess[] = { "СOM порты не обнаружены. Проверьте подключение.",
                         "Не определен СOM порт связи с Ring.",
                         "Файл описания не найден.",
                         "Файл настроек не найден. Используются исходные настройки.",
                         "Файл настроек содержит ошибки",
                         "Файл сообщения <Тревога> по умолчанию не найден",
                         "Файл сообщения <Тревога> заданный пользователем не найден",
                         "Файл сообщения <Пожар> по умолчанию не найден",
                         "Файл сообщения <Пожар> заданный пользователем не найден",
                         "Файл сообщения <Звонок> по умолчанию не найден",
                         "Файл сообщения <Звонок> заданный пользователем не найден",
                         "Файлы расписания не найдены (rxx)",
                         "Файл расписания не найден (day)",
                         "Файл исключений не найден (ex)",
                         "Файл расписания не найден",
                         "RING: нет связи",
                         "RING: режим настройки",
                         "RING: RTC не обнаружены",
                         "RING: RTC сброшены",
                         "RING: RTC DS3231 не обнаружены",
                         "RING: RTC DS3231 сброшены",
                         "RING: файл расписаний отсутствует",
                         "RING: файл расписаний обрабатывается...",


                         "---------"
                       };
typedef struct
{
 bool sup_state;
 bool sup_steps[SUPPORT_PLAN_SIZE];
} T_SupportPlan;


typedef union
{
	unsigned int all;
	struct
	{
          unsigned int RTC_EMB_State: 8;
          unsigned int RTC_DS_State: 8;
          unsigned int SchedFile: 8;
          unsigned int ready: 8;
	}el;
} T_RINGState;

//======= for T_RINGState =======
#define RTC_OK          0  // RTC is ready
#define RTC_RESET       1  // RTC works but reset
#define RTC_NO          2  // RTC not found
#define RTC_UNDEF       3  // unknown state

#define SCHED_NO        0  // no schedule file
#define SCHED_IS        1  // schedule file on flash
#define SCHED_RAM       2  // schedule file on RAM - gotten from PC
#define SCHED_ON        3  // schedule ready for work

#define RING_SETUP      0 // setup RTC & Schedule
#define RING_READY      1 // setup done

#define CHECK_RING_PERIOD  60 // sec

//------------OLD SCHEDULE FILEs -----------

#define OLD_PAR_FILE    "par.txt"
#define OLD_WEEK_FILE   "day.txt"
#define OLD_EX_FILE     "ex.txt"
#define IS_RXX_FILES        0x1
#define IS_WEEK_FILE        0x2
#define IS_EX_FILE          0x4

//-----------------------------------
//----------- SETUP

#define SETUP_FILE "setup.ini"

#define INI_DEP_RING           "Ring"
 #define INI_RING_UNIT          "ADD"
  #define DEF_RING_UNIT          1
 #define INI_RING_LINK          "LINK"
  #define RING_LINK              "COMM"

#define INI_DEP_RING_SETUP     "RING Setup"
 #define INI_UP_BOOSTER_DELAY   "Booster Up Delay"
  #define DEF_UP_BOOSTER_DELAY   3  //in seconds
 #define INI_DOWN_BOOSTER_DELAY  "Booster Down Delay"
  #define DEF_DOWN_BOOSTER_DELAY  1  //in seconds
 #define INI_RING_DELAY          "Ring Delay"
  #define DEF_RING_DELAY          10  //in seconds

#define INI_DEP_COMM           "COMM (UART)"
 #define INI_COMM_NAME          "COMM Name"
  #define DEF_COMM_NAME          "UNDEF"
  #define COM_EMPTY_ITEM         "COM -"
 #define INI_COMM_F_DELAY       "Delay for Big"
  #define COM_DELAY_BF           250   // 250 min

#define INI_DEP_UI             "Interface"
 #define INI_SHOW_WORN_WIN      "Show warning"
  #define DEF_SHOW_WORN_WIN      1
 #define INI_TIME_ZONE          "Time zone"
  #define DEF_TIME_ZONE         3  // +2, +3(MSC) .. + 12 at russia territoiry


#define INI_DEP_FILES          "Files"
 #define INI_SCHEDULE_FILE     "Schedule"
  #define DEF_SCHEDULE_FILE    "schedule.sch"
 #define INI_USE_ALARM         "ALARM sound"
  #define DEF_ALARM_SOUND      "Terror.wav"
 #define INI_USE_FIRE          "Fire sound"
  #define DEF_FIRE_SOUND       "Fire.wav"
 #define INI_USE_RING          "Ring sound"
  #define DEF_RING_SOUND       "Ring.wav"


#define DEF_WINTER_TIME         0  // no winter time - it's atavism

//-----------------------------------
//----------- EVENTS


#define MAX_OLD_EVENTS    365 //(26*14)


#define GRID_TITLE   // use header line in Event List Table

#define COL_MOMENT_WIDTH  150

#define UpDownCounter    3



//----------------------------------------------------
// ---------------- states

#define R_CLEAR              0
#define R_OK                 1
#define R_ALLOCMEM_ERROR     2
#define R_COMM_ERROR         3
#define R_KVITANCE_ERROR     4
#define R_RING_FAIL          5
#define R_NO_FILE            6
#define R_FILE_EMPTY         7
#define R_READ_FILE_ERROR    8
#define R_NO_OLD_FILES       9


#endif // DEFINES_H
