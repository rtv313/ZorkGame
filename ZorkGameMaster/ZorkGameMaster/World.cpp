#include "stdafx.h"
#include "World.h"
#include "Npc.h"

World::World(){
	Room * Forense = new Room("Forense","Forense Room,here is where we analyzed dead bodies");
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
	//Locatiosn
	Locations.push_back(Forense);
	Locations.push_back(Evidence);
	Locations.push_back(Witness);
	Locations.push_back(Office);
	Locations.push_back(Suspects);
	Locations.push_back(Hallway);

	////Evidence Room Objects
	Item * EvidenceBox = new Item("EvidenceBox","Contains objects related to the murder",Evidence,TOOL);
	Entities.push_back(EvidenceBox);

	Item * Pistol = new Item("Pistol", "Pistol found in the murder scene", EvidenceBox, EVIDENCE);
	Item * PistolNote = new Item("Pistol Scan","The Gun has fingerprints from John",Pistol,NOTE);
	Entities.push_back(PistolNote);

	Item * Pictures = new Item("Pictures", "Pictures take it from the murder scene", EvidenceBox, EVIDENCE);
	Item * PictureslNote = new Item("Pictures Scan", "The pictures shows that in the room was a fight", Pictures, NOTE);
	Entities.push_back(PictureslNote);
	////Office Room Objects
	Item * PDA = new Item("PDA", "PDA for scann and get info", Office, TOOL);
	Item * Notebook = new Item("Notebook", "Contains objects related to the murder", Office, TOOL);
	Entities.push_back(PDA);
	Entities.push_back(Notebook);



	////NPC Suspect1
	vector <string> QuestionsPrisioner1;
	QuestionsPrisioner1.push_back("Tell me John what was you're relation with the victim");
	QuestionsPrisioner1.push_back("What you were doom in the murder scene?");
	QuestionsPrisioner1.push_back("Bye it's all for now");
	vector <string> AnswerPrisioner1;
	AnswerPrisioner1.push_back("I am her boyfriend,I loved sarah and I just try to save her and protect her");
	AnswerPrisioner1.push_back("I was trying to save Sarah from her abusive husband,He abused her and I have to stop him, he is the murder,Please Detective help me I am Innocent");
	AnswerPrisioner1.push_back("Bye Detective");
	Npc * Prisioner1= new Npc("John", "Suspect", Suspects, Locations,true, QuestionsPrisioner1,AnswerPrisioner1);
	Item * Prisioner1Note = new Item("John", "\nBorn:1985-05-12\nJob:Mechanic\nCriminal Background:None", Prisioner1, NOTE);
	Entities.push_back(Prisioner1);
	Entities.push_back(Prisioner1Note);

	///NPC Suspect2
	vector <string> QuestionsPrisioner2;
	QuestionsPrisioner2.push_back("Tell me David what was you're relation with the victim?");
	QuestionsPrisioner2.push_back("What you were doing in the murder scene?");
	QuestionsPrisioner2.push_back("Bye it's all for now");
	vector <string> AnswerPrisioner2;
	AnswerPrisioner2.push_back("I am her Husband");
	AnswerPrisioner2.push_back("I have a discussion with her because she was cheating me with the idiot of John,then that idiot appeared and he shooted her.");
	AnswerPrisioner2.push_back("Bye Detective");
	Npc * Prisioner2 = new Npc("David", "Suspect", Suspects, Locations, true, QuestionsPrisioner2, AnswerPrisioner2);
	Item * Prisioner2Note = new Item("David", "\nBorn:1983-03-03\nJob:None\nCriminal Background:Sold Drugs,Armed robbery", Prisioner2, NOTE);
	Entities.push_back(Prisioner2);
	Entities.push_back(Prisioner2Note);

	//NPC Witness1
	vector <string> QuestionsWitness1;
	QuestionsWitness1.push_back("Tell me Charles what you heard and saw?");
	QuestionsWitness1.push_back("What you were doing in the murder scene?");
	QuestionsWitness1.push_back("Bye it's all for now");
	vector <string> AnswersWitness1;
	AnswersWitness1.push_back("I heard two man figthing and then a shoot , also there was a woman trying to stop them");
	AnswersWitness1.push_back("I was taking out my dog for a walk in the neighborhood and it's everything i know");
	AnswersWitness1.push_back("Bye Detective I hope you find the Murder");
	Npc * Witness1 = new Npc("Charles", "Witness", Witness, Locations, true, QuestionsWitness1, AnswersWitness1);
	Item * Witness1Note = new Item("Charles", "\nBorn:1993-05-03\nJob:Software Engineer\nCriminal Background:None", Witness1, NOTE);
	Entities.push_back(Witness1);
	Entities.push_back(Witness1Note);

	//NPC Witness2
	vector <string> QuestionsWitness2;
	QuestionsWitness2.push_back("Tell me Judith what you know about the suspects and Sarah");
	QuestionsWitness2.push_back("From where you know the suspects");
	QuestionsWitness2.push_back("Bye it's all for now");
	vector <string> AnswersWitness2;
	AnswersWitness2.push_back("Sarah was a good person she always help others, but her husband was an idiot, the other guy John is awesome and very good person");
	AnswersWitness2.push_back("David is my Neighbour but John i only meet him a few times when i hang out with sarah, he is a good guy ");
	AnswersWitness2.push_back("Bye Detective I hope you find the Murder");
	Npc * Witness2 = new Npc("Judith", "Witness", Witness, Locations, true, QuestionsWitness2, AnswersWitness2);
	Item * Witness2Note = new Item("Judith", "\nBorn:1994-05-03\nJob:Artist 2D\nCriminal Background:Use of weed", Witness2, NOTE);
	Entities.push_back(Witness2);
	Entities.push_back(Witness2Note);

	//NPC Forense
	vector <string> QuestionsForense;
	QuestionsForense.push_back("Tell me Jessica what you found from the autopsy");
	vector <string> AnswersForense;
	AnswersForense.push_back("I have not started yet, maybe you can scan the body with you're PDA and find something.");
	Npc * ForenseDoctor = new Npc("Jessica", "Forense Doctor", Forense, Locations, true, QuestionsForense, AnswersForense);
	Item * ForenseNote = new Item("Jessica", "\nBorn:1984-05-03\nJob:Doctor\nCriminal Background:None", ForenseDoctor, NOTE);
	Entities.push_back(ForenseDoctor);
	Entities.push_back(ForenseNote);

	//NPC Sarah Dead
	vector <string> QuestionsSarah;
	QuestionsSarah.push_back("Sorry what happened to you sarah you dont deserve this");
	vector <string> AnswersSarah;
	AnswersSarah.push_back("...");
	Npc * Sarah = new Npc("Sarah", "Witness", Forense, Locations, false, QuestionsSarah, AnswersSarah);
	Item * SarahNote = new Item("Report", "Many Hits around the body, this hits have been here since weeks,Inside the Nails there is blood from David,There is a bullet hole in the chest", Sarah, NOTE);
	Entities.push_back(Sarah);
	Entities.push_back(SarahNote);

	//NPC PoliceOfficer
	vector <string> QuestionsPoliceOfficer;
	QuestionsPoliceOfficer.push_back("Hi Officer some advice for me?");
	vector <string> AnswersPoliceOfficer;
	AnswersPoliceOfficer.push_back("Yes detective you're new PDA and Notebook arrive and are in you're office you will need them for follow this case");
	Npc * PoliceOfficer = new Npc("Officer", "Witness", Hallway, Locations, true, QuestionsPoliceOfficer, AnswersPoliceOfficer);
	Entities.push_back(PoliceOfficer);
	


	
	player = new Player("Player","Detective", Hallway,Locations);

	
	
	
	

}


World::~World(){
	for (vector<Entity*>::iterator it = Entities.begin(); it != Entities.end(); ++it)
		delete *it;
	Entities.clear();
	Locations.clear();
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
			player->Talk(args);
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
			if (CompareStrings(args[1], "LIST") || CompareStrings(args[1], "READ") || CompareStrings(args[1], "SCAN")) {
				player->UseObject(args);
			}
			else
			{
				cout << "\n Bad Instruction";
			}
			
		}else {
			cout << "\n Bad Instruction";
		}

		break;
	case 4:
		if (CompareStrings(args[0], "Take") && CompareStrings(args[2],"in")) {
			player->Take(args);
		}
		else {
			cout << "\n Bad Instruction";
		}
		break;

	default:
		cout << "\n Bad Instruction";
		break;
	}
}