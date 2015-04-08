#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "InventoryItem.h"

class Inventory{
public:
	//constructor/destructor
	Inventory();
	Inventory(int);
	~Inventory();


	//accessor functions
	int getInventorySpace() const;
	InventoryItem getInventorySlotItem(int) const;
	std::string getInventorySlotItemName(int) const;
	int getInventorySlotQuantity(int) const;
	int getInventorySlotQuantity(InventoryItem) const;
	void displayInventory() const;

	//mutator functions
	void addToInventory(InventoryItem);
	void removeFromInventory(int);

private:
	int inventorySpace;
	bool targetDrop(std::string); //places dropped item into target inventory (work in progress)
	void stackItems(); //stacks duplicate items together
	std::vector<InventoryItem> itemSlot;
	std::vector<int> quantitySlot;
};