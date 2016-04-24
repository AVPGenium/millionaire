//---------------------------------------------------------------------------

#ifndef WinWindowH
#define WinWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormWinWindow : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *LabelWinSum;
private:	// User declarations
public:		// User declarations
	__fastcall TFormWinWindow(TComponent* Owner);
	void  initComponents(int winSum);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWinWindow *FormWinWindow;
//---------------------------------------------------------------------------
#endif
