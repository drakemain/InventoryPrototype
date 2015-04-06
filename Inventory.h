#pragma once
#include <iostream>
#include <string>
#include <vector>

class Inventory
{
public:
	//constructor/destructor
	Inventory();
	Inventory(int);
	~Inventory();


	//accessor functions
	std::string getInventorySlotItem(int) const;
	int getInventorySlotQuantity(int) const;
	int getInventorySlotQuantity(std::string) const;
	void displayInventory() const;

	//mutator functions
	void addToInventory(std::string);
	void removeFromInventory(int);

private:
	int inventorySpace;
	std::vector<std::string> itemInSlot;
	std::vector<int> quantityInSlot;
};

