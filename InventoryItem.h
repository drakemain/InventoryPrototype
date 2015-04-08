#pragma once
#include <string>
class InventoryItem{

public:
	InventoryItem();
	InventoryItem(int, double, std::string);
	~InventoryItem();

	//accessors
	int getMaxStackable();
	std::string getItemName();
	double getAffectPlayerHealth();

private:
	std::string itemName;
	int maxStackable;
	double affectPlayerHealth;

};

