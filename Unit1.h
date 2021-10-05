//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *hero;
        TTimer *heroTimerLeft;
        TTimer *heroTimerRight;
        TTimer *heroTimerUp;
        TTimer *heroTimerDown;
        TImage *badGuy1;
        TTimer *badGuy1Timer;
        void __fastcall heroTimerLeftTimer(TObject *Sender);
        void __fastcall heroTimerRightTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall heroTimerUpTimer(TObject *Sender);
        void __fastcall heroTimerDownTimer(TObject *Sender);
        void __fastcall badGuy1TimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
