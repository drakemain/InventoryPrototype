#include "stdafx.h"
#include "Inventory.h"

//default constructor; default inventory space
Inventory::Inventory()
{
	inventorySpace = 6;
	itemInSlot = std::vector<std::string>(inventorySpace, "");
	quantityInSlot = std::vector<int>(inventorySpace, 0);
}

//constructor with custom inventory space
Inventory::Inventory(int invSpace)
{
	inventorySpace = invSpace;
	itemInSlot = std::vector<std::string>(inventorySpace, "");
	quantityInSlot = std::vector<int>(inventorySpace, 0);
}

//destructor
Inventory::~Inventory(){};

//return item given inventory slot
std::string Inventory::getInventorySlotItem(int invSlot) const
{
	return itemInSlot[invSlot];
}

//return item quantity given inventory slot
int Inventory::getInventorySlotQuantity(int invSlot) const
{
	return quantityInSlot[invSlot];
}

//return item quantity given item name
int Inventory::getInventorySlotQuantity(std::string itemName) const
{
	for (int i = 0; i < inventorySpace; i++)
	{
		if (itemInSlot[i] == itemName)
		{
			return quantityInSlot[i];
		}//if
	}//for

	return 0; //returns 0 if item is not found
}

void Inventory::displayInventory() const
{
	for (int i = 0; i < inventorySpace; i++)
	{
		std::cout << i + 1 << ". " << itemInSlot[i];

		if (quantityInSlot[i] > 0) {
			std::cout << " X" << quantityInSlot[i] << std::endl;
		} else {
			std::cout << std::endl;
		}
	}
}

//Add an item to inventory
void Inventory::addToInventory(std::string invItem)
{
	for (int i = 0; i < inventorySpace; i++) {
		if ((invItem == itemInSlot[i]) && quantityInSlot[i] < 2) {
			quantityInSlot[i]++;
			return;
		} else if (itemInSlot[i] == "") {
			itemInSlot[i] = invItem;
			quantityInSlot[i]++;
			return;
		}//if
	}//for

	std::cout << "Inventory full" << std::endl;
}

//remove item from inventory
void Inventory::removeFromInventory(int invSlot)
{
	if (quantityInSlot[invSlot] < 1) {
		std::cout << "Nothing to drop" << std::endl;
	} else {
		quantityInSlot[invSlot]--;

		if (quantityInSlot[invSlot] < 1) {
			itemInSlot[invSlot] = "";
		}
	}//if
}
