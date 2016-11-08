#pragma once
#include <string>
#include <list>

using namespace std;

enum EntityType {
	ENTITY,
	CREATURE,
	PLAYER,
	ROOM,
	ITEM
};

class Entity
{
public:
	EntityType  Type;
	string  Name;
	string Description;
	list<Entity*> Container;
	Entity * Parent;
	//Methods
	Entity(const char* Name, const char* Description);
	~Entity();
	virtual void Look() const;
	virtual void Action();
	void  ChangeParent(Entity* NewParent);
	bool    Find(Entity* Entity) const;
	Entity* Find(EntityType Type) const;
	Entity* Find(const string& Name, EntityType Type) const;
	void FindAll(EntityType Type, list<Entity*>& ListToFill) const;
	

};
