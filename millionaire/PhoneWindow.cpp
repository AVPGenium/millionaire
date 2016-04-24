//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PhoneWindow.h"
#include <iostream>
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

