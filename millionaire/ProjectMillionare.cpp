//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdlib>
#include <ctime>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainWindow.cpp", FormMain);
USEFORM("PhoneWindow.cpp", FormHelpPhone);
USEFORM("AboutWindow.cpp", FormAboutWindow);
USEFORM("WinWindow.cpp", FormWinWindow);
USEFORM("LoseWindow.cpp", FormLoseWindow);
USEFORM("RoomWindow.cpp", FormHelpRoom);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		srand ( time(NULL) );
		Application->Initialize();
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TFormHelpPhone), &FormHelpPhone);
		Application->CreateForm(__classid(TFormAboutWindow), &FormAboutWindow);
		Application->CreateForm(__classid(TFormWinWindow), &FormWinWindow);
		Application->CreateForm(__classid(TFormLoseWindow), &FormLoseWindow);
		Application->CreateForm(__classid(TFormHelpRoom), &FormHelpRoom);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
