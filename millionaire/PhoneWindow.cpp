//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PhoneWindow.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHelpPhone *FormHelpPhone;
//---------------------------------------------------------------------------
__fastcall TFormHelpPhone::TFormHelpPhone(TComponent* Owner)
	: TForm(Owner)
{
	loadData();
}

void TFormHelpPhone::loadData(){
	friends = new vector<pair<string, string> >;
	phrases = new vector<string>;
	fstream fileStream, fileStream2;
	string* path = new string();
	*path += "resources\\data\\friends.dat";
	fileStream.open(path->c_str(), ios::in);
	while(!fileStream.eof()){
		string* friendName = new string();
		string* friendDescription = new string();
		std::getline(fileStream, *friendName);
		std::getline(fileStream, *friendDescription);
		if(*friendName == "")
			break;
		pair<string, string> element(*friendName, *friendDescription);
		friends->push_back(element);
	}
	fileStream.close();
	*path = "resources\\data\\friends_phrases.dat";
	fileStream.open(path->c_str(), ios::in);
	fileStream.seekg(0, fileStream.beg);
	while(!fileStream.eof()){
		string* phrase = new string();
		std::getline(fileStream, *phrase);
		phrases->push_back(*phrase);
	}
	fileStream.close();
}

void TFormHelpPhone::InitComponents(string *friendAnswer){
	this->friendAnswer = *friendAnswer;
}

void __fastcall TFormHelpPhone::friendPhoneMouseEnter(TObject *Sender)
{
	string senderName = ((TImage*)Sender)->Name.c_str();
	if(senderName == "friend1Phone"){
		friend1Phone->Picture->LoadFromFile("resources\\images\\zvonok_in.bmp");
	} else if(senderName == "friend2Phone"){
		friend2Phone->Picture->LoadFromFile("resources\\images\\zvonok_in.bmp");
	} else if(senderName == "friend3Phone"){
		friend3Phone->Picture->LoadFromFile("resources\\images\\zvonok_in.bmp");
	} else if(senderName == "friend4Phone"){
		friend4Phone->Picture->LoadFromFile("resources\\images\\zvonok_in.bmp");
	} else if(senderName == "friend5Phone"){
		friend5Phone->Picture->LoadFromFile("resources\\images\\zvonok_in.bmp");
	} else if(senderName == "friend6Phone"){
		friend6Phone->Picture->LoadFromFile("resources\\images\\zvonok_in.bmp");
	} else if(senderName == "friend7Phone"){
		friend7Phone->Picture->LoadFromFile("resources\\images\\zvonok_in.bmp");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormHelpPhone::friendPhoneMouseLeave(TObject *Sender)
{
	string senderName = ((TImage*)Sender)->Name.c_str();
	if(senderName == "friend1Phone"){
		friend1Phone->Picture->LoadFromFile("resources\\images\\zvonok.bmp");
	} else if(senderName == "friend2Phone"){
		friend2Phone->Picture->LoadFromFile("resources\\images\\zvonok.bmp");
	} else if(senderName == "friend3Phone"){
		friend3Phone->Picture->LoadFromFile("resources\\images\\zvonok.bmp");
	} else if(senderName == "friend4Phone"){
		friend4Phone->Picture->LoadFromFile("resources\\images\\zvonok.bmp");
	} else if(senderName == "friend5Phone"){
		friend5Phone->Picture->LoadFromFile("resources\\images\\zvonok.bmp");
	} else if(senderName == "friend6Phone"){
		friend6Phone->Picture->LoadFromFile("resources\\images\\zvonok.bmp");
	} else if(senderName == "friend7Phone"){
		friend7Phone->Picture->LoadFromFile("resources\\images\\zvonok.bmp");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormHelpPhone::friendPhoneClick(TObject *Sender)
{
	 int friendIndex = ((TImage*)Sender)->Tag;
	 int phraseRandIndex = (rand() % 100) % phrases->size();
	 string* answerOfFriend = new string();
	 *answerOfFriend += "Ваш друг, ";
	 *answerOfFriend += (*friends)[friendIndex].first.c_str();
	 *answerOfFriend +=  ", говорит:\n\"";
	 *answerOfFriend += (*phrases)[phraseRandIndex].c_str();
	 *answerOfFriend += " ";
	 *answerOfFriend += friendAnswer;
	 *answerOfFriend += "\"";
	 MessageBox(NULL, answerOfFriend->c_str(), "Звоним...", MB_OK);
	 this->Close();
}
//---------------------------------------------------------------------------

