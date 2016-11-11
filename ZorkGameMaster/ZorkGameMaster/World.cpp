#include "stdafx.h"
#include "World.h"


World::World(){
	Room * Forense = new Room("Forense","Forense Room Here is where we analyzed dead bodies");
	Room * Evidence = new Room("Evidence", "Evidence Room where we bring all objects from crime scene");
	Room * Witness = new Room("Witness", "Room where are the two witness of the murder");
	Room * Office = new Room("Office","You´re Personal office");
	Room * Suspects = new Room("Suspects","Room where are the two suspects of the murder");

	Entities.push_back(Forense);
	Entities.push_back(Evidence);
	Entities.push_back(Witness);
	Entities.push_back(Office);
	Entities.push_back(Suspects);

	Locations.push_back(Forense);
	Locations.push_back(Evidence);
	Locations.push_back(Witness);
	Locations.push_back(Office);
	Locations.push_back(Suspects);

	//Office Objects
	Item * Laptop = new Item("Laptop", "Help to get info about suspects", Office, TOOL);
	Item * Analizer = new Item("Analizer", "Help to analize objects for more info", Office, TOOL);
	Item * NoteBook = new Item("NoteBook", "Write Notes about the case", Office, TOOL);

	Entities.push_back(Laptop);
	Entities.push_back(Analizer);
	Entities.push_back(NoteBook);

	//Evidence Room Objects
	Item * EvidenceBox = new Item("EvidenceBox","Contains objects related to the murder",Evidence,TOOL);
	Item * Pistol = new Item("Pistol", "Pistol found in the murder scene", EvidenceBox, EVIDENCE);
	Item * Pictures = new Item("Pictures", "Pictures take it from the murder scene", EvidenceBox, EVIDENCE);

	//NPC Objects 

	Creature * prisioner1= new Creature("Prisioner1", "Suspect", Suspects, Locations,true);

	player = new Player("Player","Player Test", Suspects,Locations);

	Item * Notebook = new Item("Notebook", "Contains objects related to the murder", Suspects, TOOL);
	Item * Note1 = new Item("Note1", "Note Content", Notebook, NOTE);
	
	Entities.push_back(player);
	Entities.push_back(prisioner1);
	Entities.push_back(NoteBook);

	vector<string> args;
	args.push_back("Take");
	args.push_back("Notebook");
	player->Take(args);
	args.clear();

	args.push_back("Equip");
	args.push_back("Notebook");
	player->Equip(args);

	args.clear();
	
	args.push_back("Notebook");
	args.push_back("Read");
	args.push_back("Note1");

	player->UseObject(args);
	player->CheckMap();
	args.clear();


}


World::~World(){
	for (vector<Entity*>::iterator it = Entities.begin(); it != Entities.end(); ++it)
		delete *it;

	Entities.clear();
	Locations.clear();
}

void World::SendInstrucction(const vector<string>& args){

	// Separate instruccions by number of parameters also check the false and bool of each object

	switch (args.size())
	{

	case 1:
		if (args[0] == "Map") {
			player->CheckMap();
		}
		else if (args[0]=="Help") {
			player->Help();
		}
		else if (args[0] == "Look") {
			cout << "\nLook";
		}
		else if (args[0] == "Inventary") {
			cout << "\nInventory";
		}
		else {
			cout << "\n Bad Instruction";
		}
		break;

	case 2:
		if (args[0] == "Move") {
			
		}
		else if (args[0] == "Equip") {

		}
		else if (args[0] == "UnEquip") {

		}
		else if (args[0] == "Talk") {

		}else {
			cout << "\n Bad Instruction";
		}
		break;

	case 3:
		if (args[0] == "PDA" && args[1]=="SCAN") {
			
		}else if (args[0] == "Notebook" && args[1]=="READ"){

		}else if (args[0] == "Notebook" && args[1] == "LIST") {
			
		}else {
			cout << "\n Bad Instruction";
		}

		break;

	default:
		cout << "\n Bad Instruction";
		break;
	}
}