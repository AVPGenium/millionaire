//---------------------------------------------------------------------------

#ifndef LoseWindowH
#define LoseWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormLoseWindow : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
private:	// User declarations
public:		// User declarations
	__fastcall TFormLoseWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormLoseWindow *FormLoseWindow;
//---------------------------------------------------------------------------
#endif
