//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

   const int BADGUY1_LEFT_STARTING_POSITION = 80;
   const int BADGUY1_TOP_STARTING_POSITION = 72;
   const int BADGUY2_LEFT_STARTING_POSITION = 656;
   const int BADGUY2_TOP_STARTING_POSITION = 72;
   const int HERO_LEFT_STARTING_POSITION = 400;
   const int HERO_TOP_STARTING_POSITION = 490;
   const int moveRatio = 10;

   int verticalRatioOfbadGuyMove =  0;
   int horizontalRatioOfbadGuyMove =  0;
   int verticalRatioOfbadGuy2Move =  0;
   int horizontalRatioOfbadGuy2Move =  0;
   int coinAmount = 0;

   void setCoinRandomPosition(TShape* background, TImage* coin){

       coin->Left = random(background->Width - coin->Width);
       coin->Top = random(background->Height - coin->Height);
   }

   void setBadGuysRandomStartDirection(){

        int startingDirections[4];

        for (int i=0; i<4; i++){
           startingDirections[i] = rand() % (2);
        }

        if(startingDirections[0]==0) verticalRatioOfbadGuyMove = -moveRatio;
        else verticalRatioOfbadGuyMove = moveRatio;

        if(startingDirections[1]==0) horizontalRatioOfbadGuyMove = -moveRatio;
        else horizontalRatioOfbadGuyMove = moveRatio;

        if(startingDirections[2]==0) verticalRatioOfbadGuy2Move = -moveRatio;
        else verticalRatioOfbadGuy2Move = moveRatio;

        if(startingDirections[3]==0) horizontalRatioOfbadGuy2Move = -moveRatio;
        else horizontalRatioOfbadGuy2Move = moveRatio;

   }

   bool collision(TImage* hero, TImage* badGuy)
   {
     if (badGuy->Left-2 >= hero->Left-badGuy->Width &&
         badGuy->Left+1 <= hero->Left+hero->Width &&
         badGuy->Top-2 >= hero->Top-badGuy->Height &&
         badGuy->Top+2 <= hero->Top+hero->Width)
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
        badGuy1->Left += horizontalRatioOfbadGuyMove;
        badGuy1->Top += verticalRatioOfbadGuyMove;

        //left wall bump
        if (badGuy1->Left <= background->Left){
          horizontalRatioOfbadGuyMove = -horizontalRatioOfbadGuyMove;
        }
        //top wall bump
        if (badGuy1->Top <= background->Top){
          verticalRatioOfbadGuyMove = -verticalRatioOfbadGuyMove;
        }

        //right wall bump
        if (badGuy1->Left+badGuy1->Width >= background->Width){
          horizontalRatioOfbadGuyMove = -horizontalRatioOfbadGuyMove;
        }

         //bottom wall bump
        if (badGuy1->Top+badGuy1->Height >= background->Height){
          verticalRatioOfbadGuyMove = -verticalRatioOfbadGuyMove;
        }

        if (collision(hero, badGuy1)){
            badGuy1Timer->Enabled = false;
            badGuy2Timer->Enabled = false;
            Form1->OnKeyDown = NULL;
            sndPlaySound("snd/collision.wav", SND_ASYNC);
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
            sndPlaySound("snd/collision.wav", SND_ASYNC);
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
             coin->Visible = false;
             coinAmountLabel->Caption = IntToStr(coinAmount);
              Beep(500,50);
      }

  } else {

       setCoinRandomPosition(background, coin);
       coin->Visible = true;

  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        ShowMessage("Witaj w grze ThisIsNotAnotherPingPongGame"  sLineBreak
                     sLineBreak
                    "Sterowanie:"
                    sLineBreak
                    "Strza³ki klawiatury Prawo, Lewo, Góra. Dó³"
                    sLineBreak sLineBreak
                    "Twoje zadanie jest proste - zbierz jak najwiêcej monet!"
                    sLineBreak
                    "Ale uwa¿aj, to trudniejsze ni¿ myœlisz"
                    sLineBreak sLineBreak
                    "Powodzenia! I od³ó¿ nerwy na bok");


        Randomize();
        badGuy1Timer->Enabled = false;
        badGuy2Timer->Enabled = false;
        endGameLabel1->Visible = true;
        endGameLabel2->Visible = true;
        Form1->OnKeyDown = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::heroLoseTimerTimer(TObject *Sender)
{
     hero->Top += 15;
     if (hero->Top >= background->Height){
        heroLoseTimer->Enabled = false;
        endGameLabel1->Visible = true;
        endGameLabel2->Visible = true;
     }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
   if(endGameLabel1->Visible){
     if (Key == VK_RETURN) {

        hero->Left = random(background->Width - hero->Width);
        hero->Top = random(background->Height - hero->Height);
        setCoinRandomPosition(background, coin);
        setBadGuysRandomStartDirection();
        endGameLabel2->Caption = "to play again";
        endGameLabel1->Visible = false;
        endGameLabel2->Visible = false;
        Form1->OnKeyDown = FormKeyDown;
        badGuy1Timer->Enabled = true;
        badGuy2Timer->Enabled = true;
        coinAmount = 0;
        coinAmountLabel->Caption = "0";
        badGuy1->Left = BADGUY1_LEFT_STARTING_POSITION;
        badGuy1->Top = BADGUY1_TOP_STARTING_POSITION;
        badGuy2->Left = BADGUY2_LEFT_STARTING_POSITION;
        badGuy2->Top = BADGUY2_TOP_STARTING_POSITION;
        hero->Left = HERO_LEFT_STARTING_POSITION;
        hero->Top = HERO_TOP_STARTING_POSITION;
        sndPlaySound("snd/backSound.wav", SND_ASYNC);
     }
   }
}
//---------------------------------------------------------------------------




