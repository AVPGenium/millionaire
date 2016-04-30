//---------------------------------------------------------------------------

#ifndef RoomWindowH
#define RoomWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <string>

using namespace std;

//---------------------------------------------------------------------------
class TFormHelpRoom : public TForm
{
__published:	// IDE-managed Components
	TShape *ShapeAnswer2;
	TShape *ShapeAnswer3;
	TShape *ShapeAnswer4;
	TShape *ShapeAnswer1;
	TLabel *LabelAnswer1;
	TLabel *LabelAnswer2;
	TLabel *LabelAnswer3;
	TLabel *LabelAnswer4;
	TLabel *Label1;
	TLabel *LabelAnswer1Text;
	TLabel *LabelAnswer2Text;
	TLabel *LabelAnswer3Text;
	TLabel *LabelAnswer4Text;
private:	// User declarations
public:		// User declarations
	__fastcall TFormHelpRoom(TComponent* Owner);
	void InitComponents(int* answersPercents, string* answersTitles);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHelpRoom *FormHelpRoom;
//---------------------------------------------------------------------------
#endif
