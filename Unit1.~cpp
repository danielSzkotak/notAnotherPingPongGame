//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::heroTimerLeftTimer(TObject *Sender)
{
       if(hero->Left > 5) hero->Left -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::heroTimerRightTimer(TObject *Sender)
{
       if(hero->Left+hero->Width < background->Width -5) hero->Left += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::heroTimerUpTimer(TObject *Sender)
{
       if(hero->Top > 5) hero->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::heroTimerDownTimer(TObject *Sender)
{
       if(hero->Top+hero->Height < background->Height -5) hero->Top +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_LEFT) heroTimerLeft->Enabled = true;
        if (Key == VK_RIGHT) heroTimerRight->Enabled = true;
        if (Key == VK_UP) heroTimerUp->Enabled = true;
        if (Key == VK_DOWN) heroTimerDown->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == VK_LEFT) heroTimerLeft->Enabled = false;
        if (Key == VK_RIGHT) heroTimerRight->Enabled = false;
        if (Key == VK_UP) heroTimerUp->Enabled = false;
        if (Key == VK_DOWN) heroTimerDown->Enabled = false;
}

