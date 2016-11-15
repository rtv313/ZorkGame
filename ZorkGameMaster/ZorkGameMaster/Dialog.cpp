#include "stdafx.h"
#include "Dialog.h"


Dialog::Dialog(const vector<string>* PlayerSentences,const vector<string>* NpcSentences, const char* NoteName){
	this->PlayerSentences = PlayerSentences;
	this->NpcSentences = NpcSentences;
	this->NoteName = NoteName;
}


Dialog::~Dialog(){
	delete PlayerSentences;
	delete NpcSentences;
}
