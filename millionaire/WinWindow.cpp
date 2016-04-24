//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <cstring>
#include "WinWindow.h"

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormWinWindow *FormWinWindow;
//---------------------------------------------------------------------------
__fastcall TFormWinWindow::TFormWinWindow(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFormWinWindow::initComponents(int winSum){
	char* buffer = new char[10];
	string win =  itoa(winSum, buffer, 10);
	win += " руб.";
	LabelWinSum->Caption =  win.c_str();
}
