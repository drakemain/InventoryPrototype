#pragma once

#ifdef _WIN32
	#include <windows.h>
#endif

Player MyChar;
World Game;

void gotoxy(int x, int y);

void status(double);