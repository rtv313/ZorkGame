#include "stdafx.h"
#include "Entity.h"




Entity::Entity(const char* Name, const char* Description,Entity* Parent =NULL)
{
	this->Name = Name;
	this->Description = Description;
	this->Parent = Parent;

	if (Parent != NULL) {
		Parent->Container.push_back(this);
	}
	
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

Entity* Entity::Find(EntityType type) const{
	for (list<Entity*>::const_iterator it = Container.begin(); it != Container.cend(); ++it)
	{
		if ((*it)->Type == type) {
			return *it;
		}
	}

	return NULL;
}

Entity* Entity::Find(const string& Name, EntityType Type) const {
	for (list<Entity*>::const_iterator it = Container.begin(); it != Container.cend(); ++it)
	{
		if ((*it)->Type == Type)
		{
			if ((CompareStrings((*it)->Name,Name)))
				return *it;
		}
	}

	return NULL;
}

void Entity::FindAll(EntityType Type, list<Entity*>& ListToFill) const {
	for (list<Entity*>::const_iterator it = Container.begin(); it != Container.cend(); ++it)
	{
		if ((*it)->Type == Type) {
			ListToFill.push_back(*it);
		}
	}
}