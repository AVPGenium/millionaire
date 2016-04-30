//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RoomWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHelpRoom *FormHelpRoom;
//---------------------------------------------------------------------------
__fastcall TFormHelpRoom::TFormHelpRoom(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void TFormHelpRoom::InitComponents(int* answersPercents, string* answersTitles){
    char* buffer = new char[10];
	ShapeAnswer1->Brush->Color = RGB(255, 0, 0);
	ShapeAnswer2->Brush->Color = RGB(255, 255, 0);
	ShapeAnswer3->Brush->Color = RGB(0, 255, 0);
	ShapeAnswer4->Brush->Color = RGB(0, 0, 255);
	ShapeAnswer1->Height =  answersPercents[0]*(-2);
	ShapeAnswer2->Height =  answersPercents[1]*(-2);
	ShapeAnswer3->Height =  answersPercents[2]*(-2);
	ShapeAnswer4->Height =  answersPercents[3]*(-2);
	LabelAnswer1->Caption = itoa(answersPercents[0], buffer, 10);
	LabelAnswer2->Caption = itoa(answersPercents[1], buffer, 10);
	LabelAnswer3->Caption = itoa(answersPercents[2], buffer, 10);
	LabelAnswer4->Caption = itoa(answersPercents[3], buffer, 10);
	LabelAnswer1Text->Caption =  answersTitles[1].c_str();
	LabelAnswer2Text->Caption =  answersTitles[2].c_str();
	LabelAnswer3Text->Caption =  answersTitles[3].c_str();
	LabelAnswer4Text->Caption =  answersTitles[4].c_str();
}

