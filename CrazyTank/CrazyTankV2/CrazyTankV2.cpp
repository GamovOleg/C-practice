// CrazyTankV2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <Windows.h>
#include "BatleField.h"
#include "Management.h"
#include <conio.h>
#include "Base.h"

int main()
{
	CONSOLE_CURSOR_INFO cci = { sizeof(CONSOLE_CURSOR_INFO), false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	srand(time(NULL));
	
	Base base;
	BatleField obj;
	//obj.setBoarder();

	while (true) {

		while (!_kbhit())
		{
			if (rand() % 1500 == 0) {
			}
			if (rand() % 2000 == 0) {
				//obj.enemyMove();
			}
		}
		//obj.playerMove();
	}
    return 0;
}

