#include "stdafx.h"
#include "Inventory.h"

//default constructor; default inventory space
Inventory::Inventory() {
	inventorySpace = 6;
	itemSlot = std::vector<InventoryItem>(inventorySpace);
	quantitySlot = std::vector<int>(inventorySpace, 0);
}

//constructor with custom inventory space
Inventory::Inventory(int invSpace) {
	inventorySpace = invSpace;
	itemSlot = std::vector<InventoryItem>(inventorySpace);
	quantitySlot = std::vector<int>(inventorySpace, 0);
}

//destructor
Inventory::~Inventory() {};

//return total inventory slots
int Inventory::getInventorySpace() const {
	return inventorySpace;
}

//return item name given inventory slot
std::string Inventory::getInventorySlotItemName(int invSlot) const {
	InventoryItem item = itemSlot[invSlot];
	return item.getItemName();
}

//return item given inventory slot
InventoryItem Inventory::getInventorySlotItem(int invSlot) const {
	return itemSlot[invSlot];
}

//return item quantity given inventory slot
int Inventory::getInventorySlotQuantity(int invSlot) const {
	return quantitySlot[invSlot];
}

//return item quantity given item
int Inventory::getInventoryItemQuantity(InventoryItem itemRef) const {
	int itemQuantity = 0;
	for (int i = 0; i < inventorySpace; i++) {
		InventoryItem item = itemSlot[i];
		if (item.getItemName() == itemRef.getItemName()) {
			itemQuantity += getInventorySlotQuantity(i);
		}//if
	}//for
	return itemQuantity;
}

void Inventory::displayInventory() const {
	for (int i = 0; i < inventorySpace; i++) {
		InventoryItem item = itemSlot[i];
		std::cout << i + 1 << ". " << item.getItemName();
		if (quantitySlot[i] > 0) {std::cout << " X" << quantitySlot[i] << std::endl;}
		else { std::cout << std::endl; }
	}
	std::cout << std::endl;
}

//Add an item to inventory
void Inventory::addToInventory(InventoryItem newItem) {
	for (int i = 0; i < inventorySpace; i++) {
		InventoryItem currentItem = itemSlot[i];
		if ((newItem.getItemName() == currentItem.getItemName()) && quantitySlot[i] < currentItem.getMaxStackable()) {
			quantitySlot[i]++;
			return;
		}

		else if (currentItem.getItemName() == "") {
			itemSlot[i] = newItem;
			quantitySlot[i]++;
			return;
		}//if
	}//for
	std::cout << "Inventory full" << std::endl;
	system("pause");
}

//remove item from inventory
void Inventory::removeFromInventory(int invSlot) {
	if (quantitySlot[invSlot] < 1) { std::cout << "Nothing to drop" << std::endl; system("pause"); }
	
	else {
		quantitySlot[invSlot]--;
		if ( quantitySlot[invSlot] < 1 ) { InventoryItem nullItem; itemSlot[invSlot] = nullItem;	}//if
	}//if
}

bool Inventory::targetDrop(std::string target) {
	return false;
}

void Inventory::stackItems() {
	//for each (std::string in in itemInSlot)
}