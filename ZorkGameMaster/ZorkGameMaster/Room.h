#pragma once
#include "Entity.h"
#include <string>
#include <list>

using namespace std;

class Room : public Entity{

public:
	Room(const char* Name,const char* Description);
	void Look() const;
	~Room();
};

