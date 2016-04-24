//---------------------------------------------------------------------------

#ifndef RoomWindowH
#define RoomWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TShape *ShapeAnswer1;
	TShape *ShapeAnswer2;
	TShape *ShapeAnswer4;
	TShape *ShapeAnswer3;
	TLabel *LabelAnswer1;
	TLabel *LabelAnswer2;
	TLabel *LabelAnswer3;
	TLabel *LabelAnswer4;
	TLabel *Label1;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void InitComponents(int* answersPercent);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
