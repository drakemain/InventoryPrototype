#include "stdafx.h"
#include "World.h"


World::World() {
	Inventory worldInventory(15);
}


World::~World() {}

Inventory& World::inventory() {
	return this->worldInventory;
}
