// InventoryPrototype.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "World.h"
#include "Player.h"
#include "InventoryItem.h"
#include "InventoryPrototype.h"
#include <conio.h>

int _tmain(int argc, _TCHAR* argv[]){
	Player MyChar;
	InventoryItem Can(3, .25, "Can of beans");
	InventoryItem Apple(5, .1, "Apple");
	InventoryItem Keyboard(1, 0, "Keyboard");

	while (true){
		int selection = 0, subSelection = 0;
		system("cls");
		showHealth(MyChar.getPlayerHealth());
		MyChar.displayInventory();
		std::cout << "1. Add Beans" << std::endl
			<< "2. Add Apple" << std::endl
			<< "3. Add keyboard" << std::endl
			<< "4. Drop an item" << std::endl
			<< "5. Show my inventory" << std::endl
			<< "6. Use item" << std::endl
			<< "7. Lose 5 health" << std::endl;
	
		std::cin >> selection;

		system("cls"); 

		switch (selection){
		case 1:
			MyChar.addToInventory(Can);
			break;
		case 2:
			MyChar.addToInventory(Apple);
			break;
		case 3:
			MyChar.addToInventory(Keyboard);
			break;
		case 4:
			MyChar.displayInventory();

			std::cout << "Select item to drop: " << std::flush;
			std::cin >> subSelection;
			MyChar.removeFromInventory(subSelection - 1);

			break;
		case 5:
			MyChar.displayInventory();
			break;
		case 6:
			MyChar.displayInventory();

			std::cout << "Select item to use: " << std::flush;
			std::cin >> subSelection;

			MyChar.useItem(MyChar.getInventorySlotItem(subSelection - 1), subSelection - 1);
			break;
		case 7:
			MyChar.setPlayerHealth(MyChar.getPlayerHealth() - .05);
			break;
		case 10:
			return 0;
		}//switch selection
	}//while true
	return 0;
}

void gotoxy(int x, int y){
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void showHealth(double health){
	int x, y;
	
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleScreenBufferInfo(hStd, &screenBufferInfo))
		printf("GetConsoleScreenBufferInfo (%d)\n", GetLastError());
	x = screenBufferInfo.dwCursorPosition.X;
	y = screenBufferInfo.dwCursorPosition.Y;

	gotoxy(25, 0);
	std::cout << "Health: " << health << std::flush;
	gotoxy(x, y);
}