//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWindow.h"
#include "AboutWindow.h"
#include "PhoneWIndow.h"
#include "LoseWindow.h"
#include "Presenter.h"
#include <iostream>
#include <string>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
Presenter* presenter;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
   presenter = new Presenter();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::answerImageMouseEnter(TObject *Sender)
{
	string senderName = ((TImage*)Sender)->Name.c_str();
	if(senderName == "answer1Image"){
		answer1Image->Picture->LoadFromFile("resources\\images\\question_bg_4_in.bmp");
	} else if(senderName == "answer2Image"){
		answer2Image->Picture->LoadFromFile("resources\\images\\question_bg_4_in.bmp");
	} else if(senderName == "answer3Image"){
		answer3Image->Picture->LoadFromFile("resources\\images\\question_bg_4_in.bmp");
	} else if(senderName == "answer4Image"){
		answer4Image->Picture->LoadFromFile("resources\\images\\question_bg_4_in.bmp");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::answerImageMouseLeave(TObject *Sender)
{
	 string senderName = ((TImage*)Sender)->Name.c_str();
	if(senderName == "answer1Image"){
		answer1Image->Picture->LoadFromFile("resources\\images\\question_bg_small.bmp");
	} else if(senderName == "answer2Image"){
		answer2Image->Picture->LoadFromFile("resources\\images\\question_bg_small.bmp");
	} else if(senderName == "answer3Image"){
		answer3Image->Picture->LoadFromFile("resources\\images\\question_bg_small.bmp");
	} else if(senderName == "answer4Image"){
		answer4Image->Picture->LoadFromFile("resources\\images\\question_bg_small.bmp");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::aboutMainMenuClick(TObject *Sender)
{
	FormAboutWindow->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::helpImageClick(TObject *Sender)
{
	string senderName = ((TImage*)Sender)->Name.c_str();
	if(senderName == "help5050Label"){
		help5050Label->Picture->LoadFromFile("resources\\images\\50_used.bmp");
		presenter->OnHelpClick(3);
		string *answers = presenter->getCurrentQuestion();
		answer1TextLabel->Caption =  AnsiString(answers[1].c_str());
		answer2TextLabel->Caption =  AnsiString(answers[2].c_str());
		answer3TextLabel->Caption =  AnsiString(answers[3].c_str());
		answer4TextLabel->Caption =  AnsiString(answers[4].c_str());
	} else if(senderName == "helpRoomImage"){
		helpRoomImage->Picture->LoadFromFile("resources\\images\\help_used.bmp");
		presenter->OnHelpClick(1);
	} else if(senderName == "helpFriendImage"){
		helpFriendImage->Picture->LoadFromFile("resources\\images\\phone_used.bmp");
		presenter->OnHelpClick(2);
	} else if(senderName == "getMoneyImage"){
		presenter->OnHelpClick(4);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::answerImageClick(TObject *Sender)
{
	if(presenter->isGameOver()){
    	return;
	}
	string senderName = ((TImage*)Sender)->Name.c_str();
	if(senderName == "answer1Image"){
		answerImageClick(1);
	} else if(senderName == "answer2Image"){
		answerImageClick(2);
	} else if(senderName == "answer3Image"){
		answerImageClick(3);
	} else if(senderName == "answer4Image"){
		answerImageClick(4);
	}
}

void TFormMain::answerImageClick(int answerIndex){
	if(!presenter->OnAnswerClick(answerIndex)){
		switch(answerIndex){
			case 1: answer1Image->Picture->LoadFromFile("resources\\images\\question_bg_3_wrong.bmp");
					return;
			case 2: answer2Image->Picture->LoadFromFile("resources\\images\\question_bg_3_wrong.bmp");
					return;
			case 3: answer3Image->Picture->LoadFromFile("resources\\images\\question_bg_3_wrong.bmp");
					return;
			case 4: answer4Image->Picture->LoadFromFile("resources\\images\\question_bg_3_wrong.bmp");
					return;
		}
	}
	switch(answerIndex){
		case 1:	answer1Image->Picture->LoadFromFile("resources\\images\\question_bg_2_true.bmp");
				break;
		case 2:	answer2Image->Picture->LoadFromFile("resources\\images\\question_bg_2_true.bmp");
				break;
		case 3:	answer3Image->Picture->LoadFromFile("resources\\images\\question_bg_2_true.bmp");
				break;
		case 4:	answer4Image->Picture->LoadFromFile("resources\\images\\question_bg_2_true.bmp");
				break;

	}
	loadNextQuestion();
}
//---------------------------------------------------------------------------
 void TFormMain::loadNextQuestion(){
	string* nextQuestion = presenter->getNextQuestion();
	MemoQuestionText->Text = AnsiString(nextQuestion[0].c_str());
	answer1TextLabel->Caption =  AnsiString(nextQuestion[1].c_str());
	answer2TextLabel->Caption =  AnsiString(nextQuestion[2].c_str());
	answer3TextLabel->Caption =  AnsiString(nextQuestion[3].c_str());
	answer4TextLabel->Caption =  AnsiString(nextQuestion[4].c_str());
	currentWinImage->Top -= 20;
 }


void __fastcall TFormMain::startGameMenuItemClick(TObject *Sender)
{
	currentWinImage->Top = 312;
	help5050Label->Picture->LoadFromFile("resources\\images\\50.bmp");
	helpRoomImage->Picture->LoadFromFile("resources\\images\\help.bmp");
	helpFriendImage->Picture->LoadFromFile("resources\\images\\phone.bmp");
	presenter->OnGameStartClick();
	loadNextQuestion();
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::FormShow(TObject *Sender)
{
	startGameMenuItemClick(NULL);
}
//---------------------------------------------------------------------------

