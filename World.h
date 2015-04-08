#pragma once
#include "Inventory.h"
#include <string>

class World{

public:
	World();
	~World();



private:
	Inventory worldInventory;
};

