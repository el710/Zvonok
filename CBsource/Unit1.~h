//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>

#include "Unit4.h"
#include <DBGrids.hpp>
#include <MPlayer.hpp>
#include <Dialogs.hpp>



//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TPageControl *PageControl1;
        TTabSheet *SchedWin;
        TPanel *TopPanel;
        TSpeedButton *ButShowToday;
        TSpeedButton *ButAllEvent;
        TSpeedButton *ButPrevDay;
        TSpeedButton *ButNextDay;
        TStatusBar *StatusBar1;
        TPanel *BottomPanel;
        TPageControl *PageControl2;
        TPanel *MidPanel;
        TPanel *DialPanel;
        TStringGrid *CurrentBase;
        TTabSheet *MainMenu;
        TSpeedButton *ButSetup;
        TSpeedButton *ButAddEvent;
        TTabSheet *EditMenu;
        TTabSheet *EditWin;
        TTabSheet *SetupWin;
        TPanel *Panel3;
        TPageControl *Setup;
        TTabSheet *PageSetup;
        TTabSheet *PageRing;
        TTabSheet *PageManual;
        TTabSheet *PageLog;
        TMemo *Memo1;
        TMemo *Memo2;
        TPanel *Panel6;
        TCheckBox *CheckBox1;
        TSpeedButton *ButEMBack;
        TSpeedButton *ButClearSel;
        TSpeedButton *ButSelAll;
        TSpeedButton *ButDelEvent;
        TButton *ButDialNo;
        TButton *ButDialOk;
        TLabel *Label3;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *TabloTime;
        TLabel *TabloDate;
        TMemo *Manual;
        TSpeedButton *ButBack;
        TPanel *Panel1;
        TSpeedButton *ButEditBack;
        TSpeedButton *ButSaveEvent;
        TSpeedButton *ButSaveas;
        TTimer *Timer2;
        TOpenDialog *OpenDialog1;
        TPanel *Panel4;
        TGroupBox *EventText;
        TMemo *Memo3;
        TPanel *Panel5;
        TPanel *Panel8;
        TPageControl *PageControl3;
        TTabSheet *MainTab;
        TTabSheet *DayTab;
        TPanel *Panel10;
        TStringGrid *StringGrid1;
        TSpeedButton *ButSupCheck;
        TSpeedButton *ButClear;
        TCheckBox *FlagLog;
        TCheckBox *FlagBuffer;
        TCheckBox *DefShowWarnWindow;
        TLabel *Label8;
        TComboBox *ListTimeZone;
        TTabSheet *WeekTab;
        TCheckBox *At_mon;
        TCheckBox *At_fri;
        TCheckBox *At_sat;
        TCheckBox *At_tue;
        TCheckBox *At_wed;
        TCheckBox *At_sun;
        TCheckBox *At_thur;
        TCheckBox *At_year;
        TCheckBox *At_month;
        TCheckBox *At_day;
        TDateTimePicker *DateTimePicker1;
        TSpeedButton *But_date;
        TSpeedButton *But_daily;
        TSpeedButton *But_monthly;
        TSpeedButton *But_weekly;
        TSpeedButton *TimeEvent;
        TSpeedButton *DateEvent;
        TTabSheet *TimeTab;
        TCheckBox *FUseHour;
        TCheckBox *FUseMinute;
        TSpeedButton *IncHour;
        TSpeedButton *IncMinute;
        TEdit *TextHour;
        TEdit *TextMinute;
        TSpeedButton *DecHour;
        TSpeedButton *DecMinute;
        TSpeedButton *RemEvent;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TTabSheet *SignalTab;
        TCheckBox *Add_sound;
        TMediaPlayer *MediaPlayer1;
        TComboBox *SigFiles;
        TSpeedButton *OpenSound;
        TCheckBox *Add_ring;
        TLabel *Label4;
        TEdit *ShowRingDelay;
        TUpDown *RingDelay;
        TLabel *Label12;
        TSpeedButton *SoundEvent;
        TSpeedButton *RingEvent;
        TLabel *Label13;
        TSpeedButton *DayBack;
        TSpeedButton *WeekBack;
        TSpeedButton *TimeBack;
        TSpeedButton *SigBack;
        TCheckBox *Is_seleb;
        TCheckBox *At_seleb;
        TLabel *EventNum;
        TPageControl *RingControl;
        TTabSheet *RignStatePage;
        TCheckBox *DefRingUnited;
        TSpeedButton *RingButton;
        TSpeedButton *ButSound;
        TSpeedButton *AlarmButton;
        TSpeedButton *But_Fire;
        TTabSheet *RingCOMPage;
        TCheckBox *DefRingComm;
        TGroupBox *GroupBox1;
        TComboBox *COMList;
        TButton *COMConnect;
        TButton *ButCommSetup;
        TTabSheet *RingHandPage;
        TGroupBox *GroupBox2;
        TLabel *Label6;
        TCheckBox *FSyncTime;
        TCheckBox *FSyncShed;
        TButton *ButStart;
        TButton *ButStop;
        TEdit *TrDelay;
        TUpDown *COMDelayBF;
        TProgressBar *ProgressBar1;
        TButton *butch;
        TTabSheet *RingSetupPage;
        TLabel *Label5;
        TEdit *UpBoosterDelayW;
        TUpDown *UpBoosterDelay;
        TUpDown *DownBoosterDelay;
        TEdit *DownBoosterDelayW;
        TLabel *Label7;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *RingLinkState;
        TLabel *RingModeState;
        TLabel *RingEmbRTC;
        TLabel *Label22;
        TLabel *Label23;
        TSpeedButton *ButStateRing;
        TButton *AltReadSchedule;
        void __fastcall Exit_menuClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall CurrentBaseDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall CurrentBaseSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall CurrentBaseDblClick(TObject *Sender);
        void __fastcall ButSetupClick(TObject *Sender);
        void __fastcall ButShowTodayClick(TObject *Sender);
        void __fastcall ButAllEventClick(TObject *Sender);
        void __fastcall AlarmButtonClick(TObject *Sender);
        void __fastcall But_FireClick(TObject *Sender);
        void __fastcall CurrentBaseMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall CurrentBaseMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButDialNoClick(TObject *Sender);
        void __fastcall ButDialOkClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall RingButtonClick(TObject *Sender);
        void __fastcall ButAddEventClick(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall ButEMBackClick(TObject *Sender);
        void __fastcall ButClearClick(TObject *Sender);
        void __fastcall ButDelEventClick(TObject *Sender);
        void __fastcall butchClick(TObject *Sender);
        void __fastcall COMConnectClick(TObject *Sender);
        void __fastcall ButCommSetupClick(TObject *Sender);
        void __fastcall ButStartClick(TObject *Sender);
        void __fastcall ButStopClick(TObject *Sender);
        void __fastcall ButSigBackClick(TObject *Sender);
        void __fastcall ButSoundClick(TObject *Sender);
        void __fastcall ButBackClick(TObject *Sender);
        void __fastcall ButEditBackClick(TObject *Sender);
        void __fastcall ButSaveEventClick(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall ButSaveasClick(TObject *Sender);
        void __fastcall But_dateClick(TObject *Sender);
        void __fastcall But_dailyClick(TObject *Sender);
        void __fastcall But_monthlyClick(TObject *Sender);
        void __fastcall But_weeklyClick(TObject *Sender);
        void __fastcall At_monClick(TObject *Sender);
        void __fastcall At_tueClick(TObject *Sender);
        void __fastcall At_wedClick(TObject *Sender);
        void __fastcall At_thurClick(TObject *Sender);
        void __fastcall At_friClick(TObject *Sender);
        void __fastcall At_satClick(TObject *Sender);
        void __fastcall At_sunClick(TObject *Sender);
        void __fastcall Is_selebClick(TObject *Sender);
        void __fastcall DateTimePicker1Change(TObject *Sender);
        void __fastcall At_yearClick(TObject *Sender);
        void __fastcall At_monthClick(TObject *Sender);
        void __fastcall At_dayClick(TObject *Sender);
        void __fastcall SigFilesChange(TObject *Sender);
        void __fastcall OpenSoundClick(TObject *Sender);
        void __fastcall FUseHourClick(TObject *Sender);
        void __fastcall FUseHourMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FUseMinuteClick(TObject *Sender);
        void __fastcall FUseMinuteMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall IncHourClick(TObject *Sender);
        void __fastcall IncHourMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall IncHourMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall IncMinuteClick(TObject *Sender);
        void __fastcall IncMinuteMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall IncMinuteMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall DecHourClick(TObject *Sender);
        void __fastcall DecHourMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall DecHourMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall DecMinuteClick(TObject *Sender);
        void __fastcall DecMinuteMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall DecMinuteMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ButSupCheckClick(TObject *Sender);
        void __fastcall DateEventClick(TObject *Sender);
        void __fastcall TimeEventClick(TObject *Sender);
        void __fastcall SoundEventClick(TObject *Sender);
        void __fastcall RingEventClick(TObject *Sender);
        void __fastcall DayBackClick(TObject *Sender);
        void __fastcall WeekBackClick(TObject *Sender);
        void __fastcall TimeBackClick(TObject *Sender);
        void __fastcall SigBackClick(TObject *Sender);
        void __fastcall ButStateRingClick(TObject *Sender);
        void __fastcall Is_selebMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall AltReadScheduleClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------




#endif
