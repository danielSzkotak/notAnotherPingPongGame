//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

   int verticalRatioOfbudGuyMove =  -8;
   int horizontalRatioOfbudGuyMove =  -8;
   int verticalRatioOfbadGuy2Move =  -8;
   int horizontalRatioOfbadGuy2Move =  -8;
   int coinAmount = 0;
   //int randomCoinLeftPosition = 0;
   //int randomCoinTopPosition = 0;

   bool collision(TImage* hero, TImage* badGuy)
   {
     if (badGuy->Left >= hero->Left-badGuy->Width &&
         badGuy->Left <= hero->Left+hero->Width &&
         badGuy->Top >= hero->Top-badGuy->Height &&
         badGuy->Top <= hero->Top+hero->Width )
         {
                return true;
         }
     else return false;
   }

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

void __fastcall TForm1::badGuy1TimerTimer(TObject *Sender)
{
        badGuy1->Left += horizontalRatioOfbudGuyMove;
        badGuy1->Top += verticalRatioOfbudGuyMove;

        //left wall bump
        if (badGuy1->Left <= background->Left){
          horizontalRatioOfbudGuyMove = -horizontalRatioOfbudGuyMove;
        }
        //top wall bump
        if (badGuy1->Top <= background->Top){
          verticalRatioOfbudGuyMove = -verticalRatioOfbudGuyMove;
        }

        //right wall bump
        if (badGuy1->Left+badGuy1->Width >= background->Width){
          horizontalRatioOfbudGuyMove = -horizontalRatioOfbudGuyMove;
        }

         //bottom wall bump
        if (badGuy1->Top+badGuy1->Height >= background->Height){
          verticalRatioOfbudGuyMove = -verticalRatioOfbudGuyMove;
        }

        if (collision(hero, badGuy1)){
            badGuy1Timer->Enabled = false;
            badGuy2Timer->Enabled = false;
            Form1->OnKeyDown = NULL;
            Sleep(733);
            heroLoseTimer->Enabled = true;
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::badGuy2TimerTimer(TObject *Sender)
{
        badGuy2->Left += horizontalRatioOfbadGuy2Move;
        badGuy2->Top += verticalRatioOfbadGuy2Move;

        //left wall bump
        if (badGuy2->Left <= background->Left){
          horizontalRatioOfbadGuy2Move = -horizontalRatioOfbadGuy2Move;
        }
        //top wall bump
        if (badGuy2->Top <= background->Top){
          verticalRatioOfbadGuy2Move = -verticalRatioOfbadGuy2Move;
        }

        //right wall bump
        if (badGuy2->Left+badGuy2->Width >= background->Width){
          horizontalRatioOfbadGuy2Move = -horizontalRatioOfbadGuy2Move;
        }

         //bottom wall bump
        if (badGuy2->Top+badGuy2->Height >= background->Height){
          verticalRatioOfbadGuy2Move = -verticalRatioOfbadGuy2Move;
        }

        if (collision(hero, badGuy2)){
            badGuy2Timer->Enabled = false;
            badGuy1Timer->Enabled = false;
            Form1->OnKeyDown = NULL;
            Sleep(733);
            heroLoseTimer->Enabled = true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::heroTimerTimer(TObject *Sender)
{

  if (coin->Visible){

      if (collision(hero, coin)){
             coinAmount++;
             //heroTimer->Enabled = false;
             coin->Visible = false;
             coinAmountLabel->Caption = IntToStr(coinAmount);
      }

  } else {

       //heroTimer->Enabled = true;
       coin->Left = random(background->Width - coin->Width);
       coin->Top = random(background->Height - coin->Height);
       coin->Visible = true;

  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Randomize();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::heroLoseTimerTimer(TObject *Sender)
{
     hero->Top += 15;
}
//---------------------------------------------------------------------------

