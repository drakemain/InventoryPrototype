#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "InventoryItem.h"

class Inventory {
public:
	//constructor/destructor
	Inventory();
	Inventory(int);
	~Inventory();


	//accessor functions
	int getInventorySpace() const; //returns total number of item slots
	InventoryItem getInventorySlotItem(int) const; //returns item in given slot
	std::string getInventorySlotItemName(int) const; //returns name string of item in given slot
	int getInventorySlotQuantity(int) const; //returns quantity of item in given slot
	int getInventoryItemQuantity(InventoryItem) const; //returns total quantity of given item
	void displayInventory() const; //prints inventory to console

	//mutator functions
	void addToInventory(InventoryItem); //adds a given item to inventory
	void removeFromInventory(int); //removes an item from a given slot

private:
	int inventorySpace; //total inventory slots
	bool targetDrop(std::string); //places dropped item into target inventory (work in progress)
	void stackItems(); //stacks duplicate items together
	std::vector<InventoryItem> itemSlot; 
	std::vector<int> quantitySlot;
};