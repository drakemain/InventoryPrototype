#include "stdafx.h"
#include "Player.h"


Player::Player(){
	playerName = "Player";
	Player::playerHealth = 1.0;
	Inventory playerInventory;
}

Player::~Player(){};

//accessors
std::string Player::getPlayerName() const{
	return playerName;
}

double Player::getPlayerHealth() const{
	return playerHealth;
}

//inventory accessors
InventoryItem Player::getInventorySlotItem(int invSlot) const{
	return playerInventory.getInventorySlotItem(invSlot);
}

std::string Player::getInventorySlotItemName(int invSlot) const{
	InventoryItem item = getInventorySlotItem(invSlot);
	return item.getItemName();
}

int Player::getInventorySlotQuantity(int invSlot) const{
	return playerInventory.getInventorySlotQuantity(invSlot);
}

int Player::getInventorySlotQuantity(InventoryItem item) const{
	return playerInventory.getInventorySlotQuantity(item);
}

void Player::displayInventory() const{
	playerInventory.displayInventory();
}

//************************************************************************************************

//mutators
void Player::setPlayerName(std::string setName){
	Player::playerName = setName;
}

void Player::setPlayerHealth(double setHealth){
	Player::playerHealth = setHealth;
}

void Player::addToInventory(InventoryItem item){
	playerInventory.addToInventory(item);
}

void Player::removeFromInventory(int invSlot){
	playerInventory.removeFromInventory(invSlot);
}


void Player::useItem(InventoryItem item, int slot){
	if (item.getItemName() != ""){
		playerHealth += item.getAffectPlayerHealth();
		if (playerHealth > 1.0){ playerHealth = 1.0; }

		if (slot > -1){
			removeFromInventory(slot);
		}
		else{
			std::string itemName = item.getItemName();
			int inventorySpace = playerInventory.getInventorySpace();
			for (int i = 0; i < inventorySpace; i++){
				if (itemName == getInventorySlotItemName(i)){ playerInventory.removeFromInventory(i); break; }
			}//for
		}//if
	}//if
	else{ std::cout << "No item" << std::endl; system("pause"); }
}