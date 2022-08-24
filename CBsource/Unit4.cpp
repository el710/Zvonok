//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMessWindow *MessWindow;
//---------------------------------------------------------------------------
__fastcall TMessWindow::TMessWindow(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMessWindow::ButtonClick(TObject *Sender)
{
 if ( MessWindow->Button->Caption == "Закрыть" )
   {
    MessWindow->Visible = false;
   }
   else
   {
    MessWindow->Button->Caption = "Закрыть";
   }
}
//---------------------------------------------------------------------------


void __fastcall TMessWindow::UnSetWarnClick(TObject *Sender)
{
 if(UnSetWarn->Checked) UpSetWarning(UnSetWarn->Checked);
}
//---------------------------------------------------------------------------

