//---------------------------------------------------------------------------

#ifndef ModelH
#define ModelH
//---------------------------------------------------------------------------
#endif
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* Класс "Вопрос" (содержит текст вопроса и ответы на него)
*/
class Question{
	// текст вопроса
	string questionText;
	// правильный ответ на вопрос
	string rightAnswer;
	// неправильные ответы на вопрос
	string answer2;
	string answer3;
	string answer4;
public:
	Question(){}
	Question(	string questionText,
				string rightAnswer,
				string answer2,
				string answer3,
				string answer4)
				:questionText(questionText), rightAnswer(rightAnswer), answer2(answer2), answer3(answer3), answer4(answer4){}

	string getQuestionText(){ return questionText;}
	string getRightAnswer(){ return rightAnswer;}
	string getAnswer2(){ return answer2;}
	string getAnswer3(){ return answer3;}
	string getAnswer4(){ return answer4;}
	void setRightAnswer(string rightAnswer){ this->rightAnswer=rightAnswer;}
	void setAnswer2(string answer2){ this->answer2=answer2;}
	void setAnswer3(string answer3){ this->answer3=answer3;}
	void setAnswer4(string answer4){ this->answer4=answer4;}
};

/*
* Класс "Уровень" (содержит все вопросы данного уровня сложности)
*/
class Level{
	// набор вопросов данного уровня
	vector<Question*> *questions;
	// номер уровня
	int levelIndex;
	// загрузка вопросов данного уровня из файла
	void loadQuestionsFromFile();
public:
	Level(){}
	Level(int levelIndex);
	/*
	 *  Получить случайный вопрос из вопросов уровня
	 *  @return Случайный вопрос
	 */
	Question* getRandomQuestion();
};

/*
* Класс модели, содержащий все данные об уровнях игры
*/
class ModelHandler{
	// набор уровней сложности данной игры
	Level* levels;
public:
	ModelHandler();
	/*
	 *  Получить игровую сессию: набор по 1-му случайному вопросу всех уровней сложности
	 *  @return набор вопросов для данной игровой сессии
	 */
	Question* getGameSession();
};
