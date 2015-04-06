// InventoryPrototype.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "Player.h"
#include "InventoryPrototype.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Player MyChar;

	while (true)
	{
		int selection = 0, subSelection = 0;

		std::cout << "1. Add Can" << std::endl
			<< "2. Add Apple" << std::endl
			<< "3. Add keyboard" << std::endl
			<< "4. Drop an item" << std::endl
			<< "5. Show my inventory" << std::endl
			<< "6. Look for items" << std::endl;
	
		std::cin >> selection;
		switch (selection)
		{
		case 1:
			MyChar.addToInventory("Can");
			break;
		case 2:
			MyChar.addToInventory("Apple");
			break;
		case 3:
			MyChar.addToInventory("Keyboard");
			break;
		case 4:
			MyChar.displayInventory();
			std::cin >> subSelection;
			switch (subSelection)
			{
			case 1:
				MyChar.removeFromInventory(0);
				break;
			case 2:
				MyChar.removeFromInventory(1);
				break;
			case 3:
				MyChar.removeFromInventory(2);
				break;
			case 4:
				MyChar.removeFromInventory(3);
				break;
			case 5:
				MyChar.removeFromInventory(4);
				break;
			case 6:
				MyChar.removeFromInventory(5);
				break;
			}//switch subSelection

		case 5:
			MyChar.displayInventory();
			break;
		case 10:
			return 0;
		}//switch selection
	}//while true
	return 0;
}
