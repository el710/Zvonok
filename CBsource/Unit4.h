//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------



class TMessWindow : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TMemo *Memo1;
        TButton *Button;
        TMediaPlayer *MessPlayer;
        TCheckBox *UnSetWarn;
        void __fastcall ButtonClick(TObject *Sender);
        void __fastcall UnSetWarnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMessWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMessWindow *MessWindow;
//---------------------------------------------------------------------------


extern void UpSetWarning(bool in_off);


#endif
