//---------------------------------------------------------------------------

#ifndef PresenterH
#define PresenterH
//---------------------------------------------------------------------------
#endif

#include "Model.h"

/*
* ����� ������ ������� ������� � ������� ����� �������������
*/
class AnswerOrder {
	string* order;
public:
	// ������������� ������� �������
	AnswerOrder(){ AnswerOrder(true);}
    // ������������� ������� �������, ���� isMixed=false �� �������������� �� �����
	AnswerOrder(bool isMixed);
	//string* getOrder();
	// ���������� ����� ������ �� ��������� �������, � ���� �������������
	string getAnswerByIndex(Question question, int i);
    // ���������� ����� ������� �� ��� �������� ������("answer1", "answer2", ...)
	string getAnswerByName(Question question, string answerName);
	// ���������, ������������ ������ �� �������
	bool isAnswerTrue(int index);
};

/*
* ����� ��������� �������� ������ ����: ��������� ������� �� ������� � ���������
*/
class BaseGame{
	// ����� �������� ��� �������� ������ ����
	Question* questions;
	AnswerOrder* answerOrder;
	// ������� ������� ��������� (� �������� �������)
	int currentState;
	// �������� �� ��������� "������ ����"
	bool isRoomHelpAvialable;
	// �������� �� ��������� "50 �� 50"
	bool isFiftyFiftyAvialable;
	// �������� �� ��������� "������ �����"
	bool isFriendAvialable;
	// �������� �� ����� ����
	bool gameOver;
	// �������� ��� ������� �� ��������
	int* gameWinSums;
	// �������� ��������� �� �����
	void loadGameWinSums();
	// ��������� ��������� ����
	void processGameOver();
public:
	BaseGame(){}
	BaseGame(Question* questions);
	// �������� ��������� ������
	string* getNextQuestion();
	// �������� ��������� "������ ����"
	void getRoomHelp();
	// �������� ��������� "������ �����"
	void getFriendHelp();
	// �������� ��������� "50 �� 50"
	void getFiftyFiftyHelp();
	/*
	* 	������, �������� �� ����
	* 	@return true, ���� ���� ��������, � false, ���� ���
	*/
	bool isGameOver(){return gameOver;}
	/*
	*	������, ���������� �� ��� �����
	* 	@param index - ������ ������� ������
	* 	@return true, ���� ����� �� ������ ����������, � false, ���� ���
	*/
	bool isAnswerTrue(int index);
};

/*
* ����� ���������� �������������� Model � View
*/
class Presenter{
	ModelHandler* modelHandler;
	BaseGame* gameLogic;
public:
	Presenter();
	// ��������� �������� �� ������� ������ ������� �� View
	bool OnAnswerClick(int answerIndex);
	// ��������� �������� �� ������� ������ ��������� �� View
	bool OnHelpClick(int helpType);
	// ��������� �������� �� ������� ������ "������ ����" �� View
	bool OnGameStartClick();
	// ���������� "��������� �� ����?" �� View
	bool isGameOver(){return gameLogic->isGameOver();}
	// ���������� ��������� ������ ���������� ������� �� View
	string* getNextQuestion(){ return gameLogic->getNextQuestion();}
};
