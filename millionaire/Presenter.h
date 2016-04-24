//---------------------------------------------------------------------------

#ifndef PresenterH
#define PresenterH
//---------------------------------------------------------------------------
#endif

#include "Model.h"

/*
*  ласс задает пор€док ответов в вопросе после перемешивани€
*/
class AnswerOrder {
	string* order;
public:
	// инициализаци€ пор€дка ответов
	AnswerOrder(){ AnswerOrder(true);}
    // инициализаци€ пор€дка ответов, если isMixed=false то перемешиватьс€ не будет
	AnswerOrder(bool isMixed);
	//string* getOrder();
	// ¬озвращает текст ответа на указанной позиции, с учЄт перемешивани€
	string getAnswerByIndex(Question question, int i);
    // ¬озвращает текст вопроса по его номерной строке("answer1", "answer2", ...)
	string getAnswerByName(Question question, string answerName);
	// ѕровер€ет, правильность ответа по индексу
	bool isAnswerTrue(int index);
};

/*
*  ласс реализует основную логику игры: обработка ответов на вопросы и подсказок
*/
class BaseGame{
	// набор вопросов дл€ текущего сеанса игры
	Question* questions;
	AnswerOrder* answerOrder;
	// текущее игровое состо€ние (є текущего вопроса)
	int currentState;
	// доступна ли подсказка "ѕомощь зада"
	bool isRoomHelpAvialable;
	// доступна ли подсказка "50 на 50"
	bool isFiftyFiftyAvialable;
	// доступна ли подсказка "ѕомощь друга"
	bool isFriendAvialable;
	// завершен ли сеанс игры
	bool gameOver;
	// выигрыши дл€ каждого из вопросов
	int* gameWinSums;
	// загрузка выигрышей из файла
	void loadGameWinSums();
	// обработка окончани€ игры
	void processGameOver();
public:
	BaseGame(){}
	BaseGame(Question* questions);
	// получить следующий вопрос
	string* getNextQuestion();
	// получить подсказку "ѕомощь зала"
	void getRoomHelp();
	// получить подсказку "ѕомощь друга"
	void getFriendHelp();
	// получить подсказку "50 на 50"
	void getFiftyFiftyHelp();
	/*
	* 	узнать, окончена ли игра
	* 	@return true, если игра окончена, и false, если нет
	*/
	bool isGameOver(){return gameOver;}
	/*
	*	узнать, правильный ли дан ответ
	* 	@param index - »ндекс данного ответа
	* 	@return true, если ответ на вопрос правильный, и false, если нет
	*/
	bool isAnswerTrue(int index);
};

/*
*  ласс организует взаимодействие Model и View
*/
class Presenter{
	ModelHandler* modelHandler;
	BaseGame* gameLogic;
public:
	Presenter();
	// ќбработка действи€ на нажатие кнопок ответов во View
	bool OnAnswerClick(int answerIndex);
	// ќбработка действи€ на нажатие кнопок подсказок во View
	bool OnHelpClick(int helpType);
	// ќбработка действи€ на нажатие кнопки "Ќачать игру" во View
	bool OnGameStartClick();
	// ¬озвращает "«акончена ли игра?" во View
	bool isGameOver(){return gameLogic->isGameOver();}
	// ¬озвращает текстовые данные следующего вопроса во View
	string* getNextQuestion(){ return gameLogic->getNextQuestion();}
};
