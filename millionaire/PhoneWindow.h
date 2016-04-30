//---------------------------------------------------------------------------

#ifndef PhoneWindowH
#define PhoneWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <string>
#include <vector>
#include <utility>

using namespace std;
//---------------------------------------------------------------------------
class TFormHelpPhone : public TForm
{
__published:	// IDE-managed Components
	TImage *friend1Photo;
	TImage *friend2Photo;
	TImage *friend3Photo;
	TImage *friend4Photo;
	TImage *friend5Photo;
	TImage *friend6Photo;
	TImage *friend7Photo;
	TLabel *friend1NameLabel;
	TLabel *friend2NameLabel;
	TLabel *friend5NameLabel;
	TLabel *friend6NameLabel;
	TLabel *friend3NameLabel;
	TLabel *friend7NameLabel;
	TLabel *friend4NameLabel;
	TLabel *friend1InfoLabel;
	TLabel *friend2InfoLabel;
	TLabel *friend3InfoLabel;
	TLabel *friend4InfoLabel;
	TLabel *friend5InfoLabel;
	TLabel *friend6InfoLabel;
	TLabel *friend7InfoLabel;
	TImage *friend1Phone;
	TImage *friend2Phone;
	TImage *friend3Phone;
	TImage *friend4Phone;
	TImage *friend5Phone;
	TImage *friend6Phone;
	TImage *friend7Phone;
	// Событие: наведена мышь на кнопку звонка другу
	void __fastcall friendPhoneMouseEnter(TObject *Sender);
	// Событие: мышь ушла с кнопки звонка другу
	void __fastcall friendPhoneMouseLeave(TObject *Sender);
	// Событие: нажата кнопка звонка другу
	void __fastcall friendPhoneClick(TObject *Sender);
private:	// User declarations
	// ответ друга на вопрос
	string friendAnswer;
	// друзья и их описания
	vector<pair<string, string> > *friends;
	// фразы друзей
	vector<string> *phrases;
	// загрузка данных о друзьях и их фразах
	void loadData();
public:		// User declarations
	__fastcall TFormHelpPhone(TComponent* Owner);
	// инициализация ответа друга на вопрос
	void InitComponents(string *friendAnswer);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHelpPhone *FormHelpPhone;
//---------------------------------------------------------------------------
#endif
