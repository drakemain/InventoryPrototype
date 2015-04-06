#pragma once

#include <string>
#include "Inventory.h"

#include "Inventory.h"

class Player {
public:
	//constructor/destructor
	Player();
	~Player();

	//accessor functions
	std::string getPlayerName() const;
	double getPlayerHealth() const;
	//inventory
	std::string getInventorySlotItem(int) const;
	int getInventorySlotQuantity(int) const;
	int getInventorySlotQuantity(std::string) const;
	void displayInventory() const;

	//mutator functions
	void setPlayerName(std::string);
	void setPlayerHealth(double);
	//inventory
	void addToInventory(std::string);
	void removeFromInventory(int);

private:
	std::string playerName;
	double playerHealth;
	Inventory playerInventory;
};
