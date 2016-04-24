//---------------------------------------------------------------------------


#pragma hdrstop

#include "Model.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//---------------------------------------------------------------------------

#pragma package(smart_init)

Level::Level(int levelIndex) : levelIndex(levelIndex){
	questions = new vector<Question*>;
	this->levelIndex = levelIndex;
	loadQuestionsFromFile();
}

void Level::loadQuestionsFromFile(){
	ifstream fileStream;
	string* path = new string();
	char* buffer = new char[10];
	*path += "resources\\data\\";
	*path += itoa(levelIndex, buffer, 10);
	*path += ".dat";
	fileStream.open(path->c_str(), ios::in);
	while(!fileStream.eof()){
		string* questionText = new string();
		string* rightAnswer = new string();
		string* answer2 = new string();
		string* answer3 = new string();
		string* answer4 = new string();
		std::getline(fileStream, *questionText);
		std::getline(fileStream,*rightAnswer);
		std::getline(fileStream,*answer2);
		std::getline(fileStream,*answer3);
		std::getline(fileStream,*answer4);
		Question* question =  new Question(	*questionText,
											*rightAnswer,
											*answer2,
											*answer3,
											*answer4);
		questions->push_back(question);
	}
}

Question* Level::getRandomQuestion(){
	  return (*questions)[rand() % questions->size()];
}

ModelHandler::ModelHandler(){
	levels = new Level[15];
	for(int i = 0; i < 15; i++){
		Level level(i+1);
		levels[i] = level;
	}
}

Question* ModelHandler::getGameSession(){
	Question* questions = new Question[15];
	for(int i = 0; i < 15; i++){
		  questions[i] = *(levels[i].getRandomQuestion());
	}
	return  questions;
}
