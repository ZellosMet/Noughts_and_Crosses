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
#define EMPTY 32

#define MOVE_LEFT 75  //Задание переменных для отлова с клавиатуры
#define MOVE_RIGHT 77
#define MOVE_UP 72
#define MOVE_DOWN 80
#define ENTER 13
#define ESC 27
	
const int SIZE = 3;

void Fill_Grid(char grid[SIZE][SIZE], int SIZE, int trg_i, int trg_j);
void Print_Grid(char grid[SIZE][SIZE], int SIZE);
void Check_Move_Target(char grid[SIZE][SIZE], int SIZE, int* ptrg_i, int* ptrg_j, int control);
int Set_Symbol(char grid[SIZE][SIZE], int SIZE, int *ptrg_i, int *ptrg_j, char m_plr);

void main()
{
	//setlocale(LC_ALL, "ru");
	int control;
	char move_player = X;
	int trg_i = 0, trg_j = 0;
	int* ptrg_i, * ptrg_j;
	ptrg_i = &trg_i;
	ptrg_j = &trg_j;
	char grid[SIZE][SIZE];

	Fill_Grid(grid, SIZE, trg_i, trg_j);
	Print_Grid(grid, SIZE);

	do //цикл отлова событий
	{
		control = _getch();
		switch (control)
		{
		case MOVE_UP: Check_Move_Target(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_DOWN: Check_Move_Target(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_RIGHT: Check_Move_Target(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_LEFT: Check_Move_Target(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case ENTER: Set_Symbol(grid, SIZE, ptrg_i, ptrg_j, move_player); Print_Grid(grid, SIZE); move_player == X ? move_player = O : move_player = X; break;
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
			else if(grid[i][j] != X && grid[i][j] != O)
			{
				grid[i][j] = EMPTY;
			}
		}
	}
}

void Check_Move_Target(char grid[SIZE][SIZE], int SIZE, int* ptrg_i, int* ptrg_j, int control)
{
	if (control == MOVE_UP)
	{
		if (*ptrg_i == 2 && grid[(*ptrg_i) - 1][*ptrg_j] !=X && grid[(*ptrg_i) - 1][*ptrg_j] != O)
		{
			(*ptrg_i)--;
		}
		else if (*ptrg_i == 2 && grid[(*ptrg_i) - 2][*ptrg_j] != X && grid[(*ptrg_i) - 2][*ptrg_j] != O)
		{
			(*ptrg_i) -= 2;
		}
		else if(*ptrg_i == 1 && grid[(*ptrg_i) - 1][*ptrg_j] != X && grid[(*ptrg_i) - 1][*ptrg_j] != O)
		{
			(*ptrg_i)--;
		}
	}
	else if (control == MOVE_DOWN)
	{
		if (*ptrg_i == 0 && grid[(*ptrg_i) + 1][*ptrg_j] != X && grid[(*ptrg_i) + 1][*ptrg_j] != O)
		{
			(*ptrg_i)++;
		}
		else if (*ptrg_i == 0 && grid[(*ptrg_i) + 2][*ptrg_j] != X && grid[(*ptrg_i) + 2][*ptrg_j] != O)
		{
			(*ptrg_i) += 2;
		}
		else if (*ptrg_i == 1 && grid[(*ptrg_i) + 1][*ptrg_j] != X && grid[(*ptrg_i) + 1][*ptrg_j] != O)
		{
			(*ptrg_i)++;
		}
	}
	else if (control == MOVE_RIGHT)
	{
		if (*ptrg_j == 0 && grid[*ptrg_i][(*ptrg_j) + 1] != X && grid[*ptrg_i][(*ptrg_j) + 1] != O)
		{
			(*ptrg_j)++;
		}
		else if (*ptrg_j == 0 && grid[*ptrg_i][(*ptrg_j) + 2] != X && grid[*ptrg_i][(*ptrg_j) + 2] != O)
		{
			(*ptrg_j) += 2;
		}
		else if (*ptrg_j == 1 && grid[*ptrg_i][(*ptrg_j) + 1] != X && grid[*ptrg_i][(*ptrg_j) + 1] != O)
		{
			(*ptrg_j)++;
		}
	}
	else if (control == MOVE_LEFT && *ptrg_j != 0)
	{
		if (*ptrg_j == 2 && grid[*ptrg_i][(*ptrg_j) - 1] != X && grid[*ptrg_i][(*ptrg_j) - 1] != O)
		{
			(*ptrg_j)--;
		}
		else if (*ptrg_j == 2 && grid[*ptrg_i][(*ptrg_j) - 2] != X && grid[*ptrg_i][(*ptrg_j) - 2] != O)
		{
			(*ptrg_j) -= 2;
		}
		else if (*ptrg_j == 1 && grid[*ptrg_i][(*ptrg_j) - 1] != X && grid[*ptrg_i][(*ptrg_j) - 1] != O)
		{
			(*ptrg_j)--;
		}
	}

}

int Set_Symbol(char grid[SIZE][SIZE], int SIZE, int *ptrg_i, int *ptrg_j, char m_plr)
{
	grid[*ptrg_i][*ptrg_j] = m_plr;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (grid[i][j] == EMPTY)
			{
				grid[i][j] = TARGET;
				*ptrg_i = i;
				*ptrg_j = j;
				return 0;
			}
		}
	}	
}