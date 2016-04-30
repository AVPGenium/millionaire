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
	// меню и его элементы
	TMainMenu *MainMenu;
	TMenuItem *startGameMenuItem;
	TMenuItem *aboutMainMenu;
	// логотип игры
	TImage *tvLogoImage;
	// подсказки
	TImage *help5050Label;
	TImage *helpRoomImage;
	TImage *helpFriendImage;
	TImage *getMoneyImage;
	// вопрос и варианты ответа на него
	TImage *questionTextImage;
	TImage *answer1Image;
	TImage *answer3Image;
	TImage *answer4Image;
	TImage *answer2Image;
	TLabel *answer1TextLabel;
	TLabel *answer3TextLabel;
	TLabel *answer2TextLabel;
	TLabel *answer4TextLabel;
	TLabel *questionTextLabel;
	TMemo *MemoQuestionText;
	// выигрыши и текущий выигрыш
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
	// Событие: наведена мышь на кнопку ответа на вопрос
	void __fastcall answerImageMouseEnter(TObject *Sender);
	// Событие: мышь ушла с кнопки ответа на вопрос
	void __fastcall answerImageMouseLeave(TObject *Sender);
	// Событие: выбран пункт меню "О игре"
	void __fastcall aboutMainMenuClick(TObject *Sender);
	// Событие: нажата кнопка одной из подсказок
	void __fastcall helpImageClick(TObject *Sender);
	// Событие: нажата кнопка одного из ответов на вопрос
	void __fastcall answerImageClick(TObject *Sender);
		// Событие: выбран пункт меню "Начать новую игру"
	void __fastcall startGameMenuItemClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	// Загрузка текста следующего вопроса и вариантов ответа на него в эл-ты формы
	void loadNextQuestion();
	// Событие: нажата кнопка ответа номер answerIndex на вопрос
	void answerImageClick(int answerIndex);
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
