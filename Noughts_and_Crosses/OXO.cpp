#include<iostream>
#include<conio.h>
using namespace std;

#define VERTICAL_LINE 179 //Символы
#define HORIZONTAL_LINE 196
#define TOP_RIGHT 191
#define TOP_LEFT 218
#define LOWER_RIGHT 217
#define LOWER_LEFT 192
#define X 88
#define O 79
#define TARGET 42
#define SPACE 32

#define MOVE_LEFT 75  //Задание переменных для отлова с клавиатуры
#define MOVE_RIGHT 77
#define MOVE_UP 72
#define MOVE_DOWN 80
#define ENTER 13
#define ESC 27
	
const int SIZE = 3;

void Fill_Grid(char grid[SIZE][SIZE], int SIZE, int trg_i, int trg_j);
void Print_Grid(char grid[SIZE][SIZE], int SIZE);

void main()
{
	//setlocale(LC_ALL, "ru");
	int control;
	int trg_i = 0, trg_j = 0;
	char grid[SIZE][SIZE];

	Fill_Grid(grid, SIZE, trg_i, trg_j);
	Print_Grid(grid, SIZE);

	do //цикл отлова событий
	{
		control = _getch();
		switch (control)
		{
		case MOVE_UP: if (trg_i != 0) trg_i--; Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_DOWN: if (trg_i != 2) trg_i++; Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_RIGHT: if (trg_j != 2) trg_j++; Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_LEFT: if (trg_j != 0) trg_j--; Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case ENTER: cout << "Enter"; break;
		}
	} while (control != ESC);
}

void Print_Grid(char grid[SIZE][SIZE], int SIZE)
{
	system("cls");
	cout << "-------" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "|";
		for (int j = 0; j < SIZE; j++)
		{
			cout << grid[i][j] << "|";
		}
		cout << endl << "-------" << endl;
	}
}

void Fill_Grid(char grid[SIZE][SIZE], int SIZE, int trg_i, int trg_j)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == trg_i && j == trg_j)
			{
				grid[i][j] = TARGET;
			}
			else
			{
				grid[i][j] = SPACE;
			}
		}
	}
}