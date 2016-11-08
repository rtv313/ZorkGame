#include "stdafx.h"
#include "Entity.h"
#include <iostream>



Entity::Entity(const char* Name, const char* Description)
{
	this->Name = Name;
	this->Description = Description;
	Type = ENTITY;
}


Entity::~Entity()
{

}

void Entity::Look()const {
	cout << Name << "\n";
	cout << Description << "\n";
}

void Entity::Action() {

}

void Entity::ChangeParent(Entity* NewParent) {

	if (Parent != NULL) {
		Parent->Container.remove(this);
	}

	Parent = NewParent;

	if (Parent != NULL) {
		Parent->Container.push_back(this);
	}
}

bool Entity::Find(Entity* entity)const {
	
	for (std::list<Entity*>::const_iterator it = Container.begin(); it != Container.end(); ++it) {
		if (*it == entity) {
			return true;
		}
	}
		
	return false;

}

Entity* Entity::Find(EntityType Type) const
{
	for (list<Entity*>::const_iterator it = Container.begin(); it != Container.cend(); ++it)
	{
		if ((*it)->Type == Type) {
			return *it;
		}
	}

	return NULL;
}

void Entity::FindAll(EntityType Type, list<Entity*>& ListToFill) const
{
	for (list<Entity*>::const_iterator it = Container.begin(); it != Container.cend(); ++it)
	{
		if ((*it)->Type == Type) {
			ListToFill.push_back(*it);
		}
	}
}