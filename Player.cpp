#include "stdafx.h"
#include "Player.h"


Player::Player() {
	playerName = "Player";
	Player::playerHealth = 1.0;
	Inventory playerInventory;
}

Player::~Player() {};

//accessors
std::string Player::getPlayerName() const {
	return playerName;
}

double Player::getPlayerHealth() const {
	return playerHealth;
}

//mutators
void Player::setPlayerName(std::string playerName) {
	this->playerName = playerName;
}

void Player::setPlayerHealth(double playerHealth) {
	this->playerHealth = playerHealth;
}

// inventory
Inventory& Player::inventory() {
	return this->playerInventory;
}

void Player::useItem(InventoryItem item, int slot) {
	if (item.getItemName() != "")  {
		playerHealth += item.getAffectPlayerHealth();
		if (playerHealth > 1.0)  { playerHealth = 1.0; }

		if (slot > -1) {
			inventory().removeFromInventory(slot);
		}
		else {
			std::string itemName = item.getItemName();
			int inventorySpace = playerInventory.getInventorySpace();
			for (int i = 0; i < inventorySpace; i++) {
				if (itemName == inventory().getInventorySlotItemName(i)) { playerInventory.removeFromInventory(i); break; }
			}//for
		}//if
	}//if
	else { std::cout << "No item" << std::endl; system("pause"); }
}

