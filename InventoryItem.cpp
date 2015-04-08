#include "stdafx.h"
#include "InventoryItem.h"


InventoryItem::InventoryItem(){
	itemName = "";
	maxStackable = 0;
	affectPlayerHealth = 0.0;
}

InventoryItem::InventoryItem(int setMaxStackable, double playerHealth, std::string name){
	maxStackable = setMaxStackable;
	affectPlayerHealth = playerHealth;
	itemName = name;
}

InventoryItem::~InventoryItem(){}


//accessors
int InventoryItem::getMaxStackable(){
	return maxStackable;
}

std::string InventoryItem::getItemName(){
	return itemName;
}

double InventoryItem::getAffectPlayerHealth(){
	return affectPlayerHealth;
}
