//---------------------------------------------------------------------------

#ifndef ModelH
#define ModelH
//---------------------------------------------------------------------------
#endif
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Question{
	string questionText;
	string rightAnswer;
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

class Level{
	vector<Question*> *questions;
	int levelIndex;
	void loadQuestionsFromFile();
public:
	Level(){}
	Level(int levelIndex);
	Question* getRandomQuestion();
};

class ModelHandler{
	Level* levels;
public:
	ModelHandler();
	Question* getGameSession();
};
