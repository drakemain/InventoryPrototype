#pragma once
#include "Inventory.h"
#include <string>

class Player {

public:
	//constructor/destructor
	Player();
	~Player();

	//accessor functions
	std::string getPlayerName() const;
	double getPlayerHealth() const;

	//mutator functions
	void setPlayerName(std::string);
	void setPlayerHealth(double);
	
	//inventory instance
	Inventory& inventory();
	void useItem(InventoryItem, int slot = -1);

private:
	std::string playerName;
	double playerHealth;
	Inventory playerInventory;

};