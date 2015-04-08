#pragma once
#include "Inventory.h"
#include <string>

class Player{

public:
	//constructor/destructor
	Player();
	~Player();

	//accessor functions
	std::string getPlayerName() const;
	double getPlayerHealth() const;
		//inventory
	InventoryItem getInventorySlotItem(int) const;
	std::string getInventorySlotItemName(int) const;
	int getInventorySlotQuantity(int) const;
	int getInventorySlotQuantity(InventoryItem) const;
	void displayInventory() const;

	//mutator functions
	void setPlayerName(std::string);
	void setPlayerHealth(double);
		//inventory
	void addToInventory(InventoryItem);
	void removeFromInventory(int);
	void useItem(InventoryItem, int slot = -1);

private:
	std::string playerName;
	double playerHealth;
	Inventory playerInventory;

};