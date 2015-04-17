// InventoryPrototype.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "World.h"
#include "Player.h"
#include "InventoryItem.h"
#include "InventoryPrototype.h"
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[]) {
	InventoryItem Can(3, .25, "Can of beans");
	InventoryItem Apple(5, .1, "Apple");
	InventoryItem Keyboard(1, 0, "Keyboard");

	while (true) {
		int selection = 0, subSelection = 0;
		system("cls");
		status(MyChar.getPlayerHealth());
		MyChar.inventory().displayInventory();
		Game.inventory().displayInventory();
		std::cout << "1. Add Beans" << std::endl
			<< "2. Add Apple" << std::endl
			<< "3. Add keyboard" << std::endl
			<< "4. Drop an item" << std::endl
			<< "5. Show my inventory" << std::endl
			<< "6. Get slot quanity" << std::endl
			<< "7. Get item quantity" << std::endl
			<< "8. Use item" << std::endl
			<< "9. Lose 5 health" << std::endl
			<< "10. Exit" << std::endl;
	
		std::cin >> selection;

		system("cls"); 

		switch (selection) {
		case 1:
			MyChar.inventory().addToInventory(Can);
			break;
		case 2:
			MyChar.inventory().addToInventory(Apple);
			break;
		case 3:
			MyChar.inventory().addToInventory(Keyboard);
			break;
		case 4:
			MyChar.inventory().displayInventory();

			std::cout << "Select item to drop: " << std::flush;
			std::cin >> subSelection;
			MyChar.inventory().removeFromInventory(subSelection - 1);

			break;
		case 5:
			MyChar.inventory().displayInventory();
			break;
		case 6:
			MyChar.inventory().displayInventory();
			std::cin >> subSelection;
			subSelection--;
			if ((subSelection > 0) || (subSelection < 6)) {	std::cout << MyChar.inventory().getInventorySlotQuantity(subSelection) << std::endl; }
			else  { std::cout << "Bad input" << std::endl; }
			break;
		case 7:
			std::cout << "1. Beans" << std::endl
				<< "2. Apple" << std::endl
				<< "3. Keyboard" << std::endl;
			std::cin >> subSelection;

			switch (subSelection) {
			case 1:
				std::cout << MyChar.inventory().getInventoryItemQuantity(Can) << std::endl;
				break;
			case 2:
				std::cout << MyChar.inventory().getInventoryItemQuantity(Apple) << std::endl;
				break;
			case 3:
				std::cout << MyChar.inventory().getInventoryItemQuantity(Keyboard) << std::endl;
				break;
			default:
				std::cout << "Bad input" << std::endl;
				break;
			}
			
			break;
		case 8:
			MyChar.inventory().displayInventory();

			std::cout << "Select item to use: " << std::flush;
			std::cin >> subSelection;

			MyChar.useItem(MyChar.inventory().getInventorySlotItem(subSelection - 1), subSelection - 1);
			break;
		case 9:
			MyChar.setPlayerHealth(MyChar.getPlayerHealth() - .05);
			break;
		case 10:
			return 0;
		}//switch selection
		system("pause");
	}//while true
	return 0;
}

void gotoxy(int x, int y) {
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void status(double health) {
	int x, y;
	
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleScreenBufferInfo(hStd, &screenBufferInfo))
		printf("GetConsoleScreenBufferInfo (%d)\n", GetLastError());
	x = screenBufferInfo.dwCursorPosition.X;
	y = screenBufferInfo.dwCursorPosition.Y;

	system("cls");
	gotoxy(25, 0);
	std::cout << "Health: " << health << std::flush;
	gotoxy(x, y);
}