//---------------------------------------------------------------------------

#ifndef PresenterH
#define PresenterH
//---------------------------------------------------------------------------
#endif

#include "Model.h"

/*
* Класс задает порядок ответов в вопросе после перемешивания
*/
class AnswerOrder {
	string* order;
public:
	// инициализация порядка ответов
	AnswerOrder(){ AnswerOrder(true);}
    // инициализация порядка ответов, если isMixed=false то перемешиваться не будет
	AnswerOrder(bool isMixed);
	//string* getOrder();
	// Возвращает текст ответа на указанной позиции, с учёт перемешивания
	string getAnswerByIndex(Question question, int i);
    // Возвращает текст вопроса по его номерной строке("answer1", "answer2", ...)
	string getAnswerByName(Question question, string answerName);
	int* mixRoomAnswers(int* answers);
	// Проверяет, правильность ответа по индексу
	bool isAnswerTrue(int index);
};

/*
* Класс реализует основную логику игры: обработка ответов на вопросы и подсказок
*/
class BaseGame{
	// набор вопросов для текущего сеанса игры
	Question* questions;
	// экземпляр класса для перемешивания вариантов ответа на вопрос
	AnswerOrder* answerOrder;
	// текущее игровое состояние (№ текущего вопроса)
	int currentState;
	// доступна ли подсказка "Помощь зада"
	bool isRoomHelpAvialable;
	// доступна ли подсказка "50 на 50"
	bool isFiftyFiftyAvialable;
	// доступна ли подсказка "Помощь друга"
	bool isFriendAvialable;
	// завершен ли сеанс игры
	bool gameOver;
	// выигрыши для каждого из вопросов
	int* gameWinSums;
	// загрузка выигрышей из файла
	void loadGameWinSums();
	// обработка окончания игры
	void processGameOver();
	// обработка подсказки "Помощь зала"
	void processRoomHelp();
	// обработка оподсказки "Звонок другу"
	void processFriendHelp();
	// обработка подсказки "50 на 50"
	void processFiftyFiftyHelp();
public:
	BaseGame(){}
	BaseGame(Question* questions);
    // получить текущий вопрос
	string* getCurrentQuestion();
	// получить следующий вопрос
	string* getNextQuestion();
	// получить подсказку "Помощь зала"
	void getRoomHelp();
	// получить подсказку "Помощь друга"
	void getFriendHelp();
	// получить подсказку "50 на 50"
	void getFiftyFiftyHelp();
	// получить деньги и закончить игру
	void getMoneyAndLeave();
	/*
	* 	узнать, окончена ли игра
	* 	@return true, если игра окончена, и false, если нет
	*/
	bool isGameOver(){return gameOver;}
	/*
	*	узнать, правильный ли дан ответ
	* 	@param index - Индекс данного ответа
	* 	@return true, если ответ на вопрос правильный, и false, если нет
	*/
	bool isAnswerTrue(int index);
};

/*
* Класс организует взаимодействие Model и View
*/
class Presenter{
	ModelHandler* modelHandler;
	BaseGame* gameLogic;
public:
	Presenter();
	/*
	 * Обработка действия на нажатие кнопок ответов во View
	 * @param answerIndex - Индекс данного ответа
	 * @return true, если удалось успешно обработать ответ, и false, если нет
	 */
	bool OnAnswerClick(int answerIndex);
	/*
	 * Обработка действия на нажатие кнопок подсказок во View
	 * @param helpType - вид выбранной подсказки
	 * @return true, если удалось успешно выполнить подсказку, и false, если нет
	 */
	bool OnHelpClick(int helpType);
	/* Обработка действия на нажатие кнопки "Начать игру" во View
	*  @return true, если удалось начать сеанс новой игры, и false, если нет
	*/
	bool OnGameStartClick();
	/* Возвращает "Закончена ли игра?" во View
	 * @return true, если игра окончена, и false, если нет
	 */
	bool isGameOver(){return gameLogic->isGameOver();}
	// Возвращает текстовые данные следующего вопроса во View
	string* getNextQuestion(){ return gameLogic->getNextQuestion();}
    // Возвращает текстовые данные текущего вопроса во View
	string* getCurrentQuestion(){ return gameLogic->getCurrentQuestion();}
};
