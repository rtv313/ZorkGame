#pragma once
#include "Creature.h"
#include "Exit.h"
class Exit;
class Player :
	public Creature
{
public:
	Player(const char* Name, const char* Description, Room* Room, const list<Entity*> Locations);
	~Player();
	
	void Look(const vector<string>&args,vector<Exit*>Exits) const;
	bool Take(const vector<string>&args);
	bool Drop(const vector<string>&args);
	void Inventory() const;
	bool Equip(const vector<string>&args);
	bool UnEquip(const vector<string>&args);
	bool UseObject(const vector<string>&args);
	void CheckMap();
	void Help();
	bool Sentence(const vector<string>&args);
	bool Move(const vector<string>&args,vector<Exit*>Exits);
	bool ScanObject(const vector<string>&args);
};


