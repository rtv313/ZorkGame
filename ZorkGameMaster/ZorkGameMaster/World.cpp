#include "stdafx.h"
#include "World.h"


World::World(){
	Room * Forense = new Room("Forense","Forense Room Here is where we analyzed dead bodies");
	Room * Evidence = new Room("Evidence", "Evidence Room where we bring all objects from crime scene");
	Room * Witness = new Room("Witness", "Room where are the two witness of the murder");
	Room * Office = new Room("Office","You're Personal office");
	Room * Suspects = new Room("Suspects","Room where are the two suspects of the murder");
	Room * Hallway = new Room("Hallway", "Room that connect every other room");
	
	Exit * HallwayForense = new Exit("Hallway-Forense","HallwayForenseRoom",Hallway,Forense);
	Exit * HallwayEvidence = new Exit("Hallway-Evidence", "HallwayEvidenceRoom", Hallway, Evidence);
	Exit * HallwayWitness = new Exit("Hallway-Witness", "HallwayWitnessRoom", Hallway, Witness);
	Exit * HallwayOffice = new Exit("Hallway-Office", "HallwayOfficeRoom", Hallway, Office);
	Exit * HallwaySuspects = new Exit("Hallway-Suspects", "HallwaySuspectsRoom", Hallway, Suspects);
	

	Exits.push_back(HallwayForense);
	Exits.push_back(HallwayEvidence);
	Exits.push_back(HallwayWitness);
	Exits.push_back(HallwayOffice);
	Exits.push_back(HallwaySuspects);

	//Exits
	Entities.push_back(HallwayEvidence);
	Entities.push_back(HallwayForense);
	Entities.push_back(HallwayWitness);
	Entities.push_back(HallwayOffice);
	Entities.push_back(HallwaySuspects);
	//Rooms
	Entities.push_back(Forense);
	Entities.push_back(Evidence);
	Entities.push_back(Witness);
	Entities.push_back(Office);
	Entities.push_back(Suspects);
	Entities.push_back(Hallway);

	Locations.push_back(Forense);
	Locations.push_back(Evidence);
	Locations.push_back(Witness);
	Locations.push_back(Office);
	Locations.push_back(Suspects);
	Locations.push_back(Hallway);

	////Office Objects
	Item * Laptop = new Item("Laptop", "Help to get info about suspects", Office, TOOL);
	Item * Analizer = new Item("Analizer", "Help to analize objects for more info", Office, TOOL);
	Item * NoteBook = new Item("NoteBook", "Write Notes about the case", Office, TOOL);

	Entities.push_back(Laptop);
	Entities.push_back(Analizer);
	Entities.push_back(NoteBook);

	////Evidence Room Objects
	Item * EvidenceBox = new Item("EvidenceBox","Contains objects related to the murder",Evidence,TOOL);
	Item * Pistol = new Item("Pistol", "Pistol found in the murder scene", EvidenceBox, EVIDENCE);
	Item * Pictures = new Item("Pictures", "Pictures take it from the murder scene", EvidenceBox, EVIDENCE);

	////NPC Objects 

	Creature * prisioner1= new Creature("Prisioner1", "Suspect", Suspects, Locations,true);
	Item * PDA = new Item("PDA", "PDA for scann and get info", Suspects, TOOL);
	player = new Player("Player","Player Test", Suspects,Locations);

	Item * Notebook = new Item("Notebook", "Contains objects related to the murder", Suspects, TOOL);
	Item * Note1 = new Item("Note1", "Note Content", Notebook, NOTE);
	
	Entities.push_back(PDA);
	Entities.push_back(player);
	Entities.push_back(prisioner1);
	Entities.push_back(Notebook); 
	Entities.push_back(Note1);

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

	//Entities.clear();
	//Locations.clear();
}

void World::SendInstrucction(const vector<string>& args,bool &ExitFlag){

	// Separate instruccions by number of parameters also check the false and bool of each object

	switch (args.size())
	{

	case 1:
		if (CompareStrings(args[0],"Rooms")) {
			player->CheckMap();
		}
		else if (CompareStrings(args[0],"Help")) {
			player->Help();
		}
		else if (CompareStrings(args[0],"Look")) {
			player->Look(args,Exits);
		}
		else if (CompareStrings(args[0],"Inventory")) {
			player->Inventory();
		}
		else {
			cout << "\nBad Instruction";
		}
		break;

	case 2:
		if (CompareStrings(args[0], "Move")) {
			player->Move(args,Exits);
		}
		else if (CompareStrings(args[0],"Equip")) {
			player->Equip(args);
		}
		else if (CompareStrings(args[0],"UnEquip")) {
			player->UnEquip(args);
		}
		else if (CompareStrings(args[0],"Talk")) {
			cout << "\nTalk";
		}
		else if (CompareStrings(args[0],"Take")) {
			player->Take(args);
		}
		else if (CompareStrings(args[0],"Look")) {
			player->Look(args,Exits);
		}
		else if (CompareStrings(args[0],"Drop")){
			player->Drop(args);
		}
		else if (CompareStrings(args[0],"Sentence")) {
			ExitFlag=player->Sentence(args);
		}
		else {
			cout << "\n Bad Instruction";
		}
		break;

	case 3:
		if (CompareStrings(args[0],"PDA") || CompareStrings(args[0],"Notebook")) {
			player->UseObject(args);
		}else {
			cout << "\n Bad Instruction";
		}

		break;
	case 4:
		if (CompareStrings(args[0],"Take")) {
			player->Take(args);
		}
		break;

	default:
		cout << "\n Bad Instruction";
		break;
	}
}