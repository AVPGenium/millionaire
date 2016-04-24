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
	void __fastcall friendPhoneMouseEnter(TObject *Sender);
	void __fastcall friendPhoneMouseLeave(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormHelpPhone(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHelpPhone *FormHelpPhone;
//---------------------------------------------------------------------------
#endif
