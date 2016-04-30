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
	int* mixRoomAnswers(int* answers);
	// ���������, ������������ ������ �� �������
	bool isAnswerTrue(int index);
};

/*
* ����� ��������� �������� ������ ����: ��������� ������� �� ������� � ���������
*/
class BaseGame{
	// ����� �������� ��� �������� ������ ����
	Question* questions;
	// ��������� ������ ��� ������������� ��������� ������ �� ������
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
	// ��������� ��������� "������ ����"
	void processRoomHelp();
	// ��������� ���������� "������ �����"
	void processFriendHelp();
	// ��������� ��������� "50 �� 50"
	void processFiftyFiftyHelp();
public:
	BaseGame(){}
	BaseGame(Question* questions);
    // �������� ������� ������
	string* getCurrentQuestion();
	// �������� ��������� ������
	string* getNextQuestion();
	// �������� ��������� "������ ����"
	void getRoomHelp();
	// �������� ��������� "������ �����"
	void getFriendHelp();
	// �������� ��������� "50 �� 50"
	void getFiftyFiftyHelp();
	// �������� ������ � ��������� ����
	void getMoneyAndLeave();
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
	/*
	 * ��������� �������� �� ������� ������ ������� �� View
	 * @param answerIndex - ������ ������� ������
	 * @return true, ���� ������� ������� ���������� �����, � false, ���� ���
	 */
	bool OnAnswerClick(int answerIndex);
	/*
	 * ��������� �������� �� ������� ������ ��������� �� View
	 * @param helpType - ��� ��������� ���������
	 * @return true, ���� ������� ������� ��������� ���������, � false, ���� ���
	 */
	bool OnHelpClick(int helpType);
	/* ��������� �������� �� ������� ������ "������ ����" �� View
	*  @return true, ���� ������� ������ ����� ����� ����, � false, ���� ���
	*/
	bool OnGameStartClick();
	/* ���������� "��������� �� ����?" �� View
	 * @return true, ���� ���� ��������, � false, ���� ���
	 */
	bool isGameOver(){return gameLogic->isGameOver();}
	// ���������� ��������� ������ ���������� ������� �� View
	string* getNextQuestion(){ return gameLogic->getNextQuestion();}
    // ���������� ��������� ������ �������� ������� �� View
	string* getCurrentQuestion(){ return gameLogic->getCurrentQuestion();}
};
