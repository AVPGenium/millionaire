//---------------------------------------------------------------------------

#ifndef AboutWindowH
#define AboutWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormAboutWindow : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageAbout;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
private:	// User declarations
public:		// User declarations
	__fastcall TFormAboutWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAboutWindow *FormAboutWindow;
//---------------------------------------------------------------------------
#endif
