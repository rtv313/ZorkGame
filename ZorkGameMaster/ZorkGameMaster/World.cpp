#include "stdafx.h"
#include "World.h"


World::World(){
	Room * Room1 = new Room("Room1","First Room Testing");
	Room * Room2 = new Room("Room2", "Second Room Testing");
	Room * Room3 = new Room("Room2", "Second Room Testing");

	Entities.push_back(Room1);
	Entities.push_back(Room2);
	Entities.push_back(Room3);

	Locations.push_back(Room1);
	Locations.push_back(Room2);
	Locations.push_back(Room3);

	Creature * Creature1 = new Creature("Creature1", "Creature For Testing", Room1, Locations,true);
	Creature * Creature2 = new Creature("Creature2", "Creature For Testing", Room1, Locations, true);
	Creature * Creature3 = new Creature("Creature3", "Creature For Testing", Room2, Locations, true);

	Entities.push_back(Creature1);
	Entities.push_back(Creature2);
	Entities.push_back(Creature3);

	Item * Item1 = new Item("Item1","Item for testing",Room1,TOOL);
	Item * Item2 = new Item("Item2", "Item inside Item1 for testing", Item1, TOOL);

	Entities.push_back(Item1);
	Entities.push_back(Item2);

	player = new Player("Player","Player Test",Room1,Locations);
	
	Entities.push_back(player);

	// Testing rooms 

	//Room1->Look();
	/*Item* test =(Item *) Room1->Find(ITEM);
	test->Look();
*/
	// Testing Items
	//Item1->Look();
	/*Item1->ChangeParent(Room2);
	Room1->Look();
	Room2->Look();*/

	// Testing Creatures
	Room1->Look();
	cout << "\n";
	vector<string> args;
	args.push_back("Move");
	args.push_back("Room1");
	Creature3->Move(args);
	args.clear();
	args.push_back("Take");
	args.push_back("Item1");
	args.push_back("Take");
	args.push_back("Item2");
	Creature3->Take(args);
	args.clear();
	args.push_back("Drop");
	args.push_back("Item2");
	Creature3->Drop(args);
	Creature3->Inventory();
	args.clear();
}


World::~World(){
	for (vector<Entity*>::iterator it = Entities.begin(); it != Entities.end(); ++it)
		delete *it;

	Entities.clear();
	Locations.clear();
}

void World::SendInstrucction(const vector<string>& args){

	
}