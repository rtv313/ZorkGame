#include "stdafx.h"
#include "Npc.h"
#include "Dialog.h"

Npc::Npc(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations,bool Alive, vector <string>&Questions, vector <string>&Answers):Creature(Name,Description,Room,Locations,Alive){
	this->Questions = Questions;
	this->Answers = Answers;
	this->Type = NPC;
}


Npc::~Npc()
{
}

void Npc::Speak() {
	while (true) {
		int index = 0;
		int option = 0;
		for (vector<string>::const_iterator it = Questions.begin(); it != Questions.cend(); ++it) {
			cout <<"\n" << index << " " << *it;
			++index;
		}
		cout << "\n";
		cout << "\nSelect Dialog Option\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		cin >> option;

		if (option == (Answers.size() - 1)) {
			cout << "\n" << Name << ":" << Answers[option] << "\n";
			return;
		}

		if (option >= 0 && option < Answers.size()) {
			cout << "\n" << Name << ":" << Answers[option]<<"\n";
		}else{
			cout <<"\nPardon I dont understand(Select a valid choise)";
			return;
		}
	}
}