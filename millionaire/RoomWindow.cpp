//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RoomWindow.h"
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
void TForm1::InitComponents(int* answersPercent){
    char* buffer = new char[10];
	ShapeAnswer1->Brush->Color = RGB(255, 0, 0);
	ShapeAnswer2->Brush->Color = RGB(255, 255, 0);
	ShapeAnswer3->Brush->Color = RGB(0, 255, 0);
	ShapeAnswer4->Brush->Color = RGB(0, 0, 255);
	ShapeAnswer1->Height =  answersPercent[0]*(-2);
	ShapeAnswer2->Height =  answersPercent[1]*(-2);
	ShapeAnswer3->Height =  answersPercent[2]*(-2);
	ShapeAnswer4->Height =  answersPercent[3]*(-2);
	LabelAnswer1->Caption = itoa(answersPercent[0], buffer, 10);
	LabelAnswer2->Caption = itoa(answersPercent[1], buffer, 10);
	LabelAnswer3->Caption = itoa(answersPercent[2], buffer, 10);
	LabelAnswer4->Caption = itoa(answersPercent[3], buffer, 10);
}

void __fastcall TForm1::FormShow(TObject *Sender)
{
		int* answers = new int[4];
		answers[0] = 90; answers[1] = 20; answers[2] = 15;answers[3] = 25;
	  InitComponents(answers);
}
//---------------------------------------------------------------------------

