// CrazyTanks.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int tankX, tankY, enemyX, enemyY, score, life;
enum eMovement {STOP = 0, UP, DOWN, LEFT, RIGHT};
eMovement mov;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position;

void Setup() {
	gameOver = false;
	mov = STOP;
	tankX = width / 2 - 1;
	tankY = height - 1;
	position.X = tankX;
	position.Y = tankY;
	enemyX = rand() % width;
	enemyY = rand() % height;
	score = 0;
	life = 3;
}

void Drawing() {
	system("cls");
	for (int i = 0; i < width + 1; i++)
		cout << "@";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << "@";
			if (i == tankY && j == tankX)
				cout << "0";
		cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < width; i++)
		cout << "@";
	cout << endl;	
}

void Control() {
	int key = _getch();

	if (key == 224) {
		key = _getch();
		if (key == 72) {
			mov = UP;
			return;
		}
		if (key == 80) {
			mov = DOWN;
			return;
		}
		if (key == 75) {
			mov = LEFT;
			return;
		}
		if (key == 77) {
			mov = RIGHT;
			return;
		}		
		if (key == 113) {
			gameOver = true;
			return;
		}
	}
}

void Logic() {
	switch (mov)
	{
	case UP:
		if (position.Y > 1) {
			SetConsoleCursorPosition(h, position);
			cout << " ";
			position.Y--;
			SetConsoleCursorPosition(h, position);
			cout << "0";
		}
		break;

	case DOWN:
		if (position.Y < height) {
			SetConsoleCursorPosition(h, position);
			cout << " ";
			position.Y++;
			SetConsoleCursorPosition(h, position);
			cout << "0";
		}
		break;
	case LEFT:
		if (position.X > 1) {
			SetConsoleCursorPosition(h, position);
			cout << " ";
			position.X--;
			SetConsoleCursorPosition(h, position);
			cout << "0";
		}
		break;
	case RIGHT:
		if (position.X < width -1) {
			SetConsoleCursorPosition(h, position);
			cout << " ";
			position.X++;
			SetConsoleCursorPosition(h, position);
			cout << "0";
		}
		break;
	}

}

int main()
{
	srand(time(0));
	Setup();
	Drawing();
	while (!gameOver)
	{
		
		Control();
		Logic();
	}

    return 0;
}

