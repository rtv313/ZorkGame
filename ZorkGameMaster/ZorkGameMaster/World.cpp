#include "stdafx.h"
#include "World.h"


World::World(){

}


World::~World(){
	for (vector<Entity*>::iterator it = Entities.begin(); it != Entities.end(); ++it)
		delete *it;

	Entities.clear();
}

void World::SendInstrucction(const vector<string>& args){

}