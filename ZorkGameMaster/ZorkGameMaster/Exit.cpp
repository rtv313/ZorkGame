#include "stdafx.h"
#include "Exit.h"


Exit::Exit(const char* Name, const char* Description,Room*Room1,Room*Room2):Entity(Name,Description,NULL){
	this->Room1 = Room1;
	this->Room2 = Room2;
}


Exit::~Exit(){
}
