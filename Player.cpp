#include "stdafx.h"
#include "Player.h"
#include "Inventory.h"


Player::Player() {
	Player::playerHealth = 100;
	Inventory playerInventory();
}

Player::~Player(){};

//accessors
std::string Player::getPlayerName() const {
	return playerName;
}

double Player::getPlayerHealth() const {
	return playerHealth;
}

//inventory accessors
std::string Player::getInventorySlotItem(int invSlot) const {
	return playerInventory.getInventorySlotItem(invSlot);
}

int Player::getInventorySlotQuantity(int invSlot) const {
	return playerInventory.getInventorySlotQuantity(invSlot);
}

int Player::getInventorySlotQuantity(std::string itemName) const {
	return playerInventory.getInventorySlotQuantity(itemName);
}

void Player::displayInventory() const {
	playerInventory.displayInventory();
}

//************************************************************************************************

//mutators
void Player::setPlayerName(std::string setName) {
	Player::playerName = setName;
}

void Player::setPlayerHealth(double setHealth) {
	Player::playerHealth = setHealth;
}

void Player::addToInventory(std::string item) {
	playerInventory.addToInventory(item);
}

void Player::removeFromInventory(int invSlot) {
	playerInventory.removeFromInventory(invSlot);
}
