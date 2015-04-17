#pragma once
#include "Inventory.h"
#include <string>

class World {

public:
	World();
	~World();
	Inventory& inventory();


private:
	Inventory worldInventory;
};

