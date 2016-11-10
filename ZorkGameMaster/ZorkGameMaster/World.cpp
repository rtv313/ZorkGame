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

	
	player = new Player("Player","Player Test", Suspects,Locations);
	Entities.push_back(player);



}


World::~World(){
	for (vector<Entity*>::iterator it = Entities.begin(); it != Entities.end(); ++it)
		delete *it;

	Entities.clear();
	Locations.clear();
}

void World::SendInstrucction(const vector<string>& args){

	// Separate instruccions by number of parameters also check the false and bool of each object


}