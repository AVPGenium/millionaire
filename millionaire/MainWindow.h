//---------------------------------------------------------------------------

#ifndef MainWindowH
#define MainWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu;
	TMenuItem *startGameMenuItem;
	TMenuItem *aboutMainMenu;
	TImage *tvLogoImage;
	TImage *help5050Label;
	TImage *helpRoomImage;
	TImage *helpFriendImage;
	TImage *questionTextImage;
	TImage *getMoneyImage;
	TImage *answer1Image;
	TImage *answer3Image;
	TImage *answer4Image;
	TImage *answer2Image;
	TLabel *LabelWin1;
	TLabel *LabelWin5;
	TLabel *LabelWin4;
	TLabel *LabelWin3;
	TLabel *LabelWin2;
	TLabel *LabelWin10;
	TLabel *LabelWin9;
	TLabel *LabelWin8;
	TLabel *LabelWin7;
	TLabel *LabelWin6;
	TLabel *LabelWin15;
	TLabel *LabelWin14;
	TLabel *LabelWin13;
	TLabel *LabelWin12;
	TLabel *LabelWin11;
	TImage *currentWinImage;
	TLabel *answer1TextLabel;
	TLabel *answer3TextLabel;
	TLabel *answer2TextLabel;
	TLabel *answer4TextLabel;
	TLabel *questionTextLabel;
	TMemo *MemoQuestionText;
	void __fastcall answerImageMouseEnter(TObject *Sender);
	void __fastcall answerImageMouseLeave(TObject *Sender);
	void __fastcall aboutMainMenuClick(TObject *Sender);
	void __fastcall helpImageClick(TObject *Sender);
	void __fastcall answerImageClick(TObject *Sender);
	void __fastcall startGameMenuItemClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	void loadNextQuestion();
	void answerImageClick(int answerIndex);
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
