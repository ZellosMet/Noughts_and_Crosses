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
#define CURSOR 31
#define EMPTY 32

#define MOVE_LEFT 75  //Задание переменных для отлова с клавиатуры
#define MOVE_RIGHT 77
#define MOVE_UP 72
#define MOVE_DOWN 80
#define ENTER 13
#define ESC 27
	
const int SIZE = 3;

void Fill_Grid(char grid[SIZE][SIZE], int SIZE, int trg_i, int trg_j); //Функция заполнения сетки
void Print_Grid(char grid[SIZE][SIZE], int SIZE); //Функция вывода сетки
void Check_Move_Сursor(char grid[SIZE][SIZE], int SIZE, int *ptrg_i, int *ptrg_j, int control); // Функция проверки движения курсора
int Set_Symbol(char grid[SIZE][SIZE], int SIZE, int *ptrg_i, int *ptrg_j, char m_plr); //Функция установки символа игрока
int Set_Symbol(char grid[SIZE][SIZE], int SIZE, int *ptrg_i, int *ptrg_j, int control);
int Check_Win(char grid[SIZE][SIZE], int SIZE); // Функция проверки на победу

void main()
{
	int control, trg_i = 0, trg_j = 0;
	char move_player = X;
	char grid[SIZE][SIZE];

	int *ptrg_i, *ptrg_j;

	ptrg_i = &trg_i;
	ptrg_j = &trg_j;

	Fill_Grid(grid, SIZE, trg_i, trg_j);
	Print_Grid(grid, SIZE);

	setlocale(LC_ALL, "ru");
	cout << "\nУправление: стрелочками выбирается позиция курсора(треугольник), Enter устанавливает символ игрока, ESC - выход" << endl;
	setlocale(LC_ALL, "С");

	do //Цикл отлова событий
	{
		control = _getch();
		switch (control)
		{
		case MOVE_UP: Check_Move_Сursor(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_DOWN: Check_Move_Сursor(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_RIGHT: Check_Move_Сursor(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case MOVE_LEFT: Check_Move_Сursor(grid, SIZE, ptrg_i, ptrg_j, control); Fill_Grid(grid, SIZE, trg_i, trg_j); Print_Grid(grid, SIZE); break;
		case ENTER: Set_Symbol(grid, SIZE, ptrg_i, ptrg_j, move_player); Print_Grid(grid, SIZE); Check_Win(grid, SIZE); move_player == X ? move_player = O : move_player = X; break;
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
				grid[i][j] = CURSOR;
			}
			else if(grid[i][j] != X && grid[i][j] != O)
			{
				grid[i][j] = EMPTY;
			}
		}
	}
}

void Check_Move_Сursor(char grid[SIZE][SIZE], int SIZE, int* ptrg_i, int* ptrg_j, int control)
{
	if (control == MOVE_UP)
	{
		if (*ptrg_i == 2 && grid[(*ptrg_i) - 1][*ptrg_j] !=X && grid[(*ptrg_i) - 1][*ptrg_j] != O) (*ptrg_i)--;
		else if (*ptrg_i == 2 && grid[(*ptrg_i) - 2][*ptrg_j] != X && grid[(*ptrg_i) - 2][*ptrg_j] != O) (*ptrg_i) -= 2;
		else if(*ptrg_i == 1 && grid[(*ptrg_i) - 1][*ptrg_j] != X && grid[(*ptrg_i) - 1][*ptrg_j] != O) (*ptrg_i)--;
		else Set_Symbol(grid, SIZE, ptrg_i, ptrg_j, control);
	}
	else if (control == MOVE_DOWN)
	{
		if (*ptrg_i == 0 && grid[(*ptrg_i) + 1][*ptrg_j] != X && grid[(*ptrg_i) + 1][*ptrg_j] != O) (*ptrg_i)++;
		else if (*ptrg_i == 0 && grid[(*ptrg_i) + 2][*ptrg_j] != X && grid[(*ptrg_i) + 2][*ptrg_j] != O) (*ptrg_i) += 2;
		else if (*ptrg_i == 1 && grid[(*ptrg_i) + 1][*ptrg_j] != X && grid[(*ptrg_i) + 1][*ptrg_j] != O) (*ptrg_i)++;
		else Set_Symbol(grid, SIZE, ptrg_i, ptrg_j, control);
	}
	else if (control == MOVE_RIGHT)
	{
		if (*ptrg_j == 0 && grid[*ptrg_i][(*ptrg_j) + 1] != X && grid[*ptrg_i][(*ptrg_j) + 1] != O) (*ptrg_j)++;
		else if (*ptrg_j == 0 && grid[*ptrg_i][(*ptrg_j) + 2] != X && grid[*ptrg_i][(*ptrg_j) + 2] != O) (*ptrg_j) += 2;
		else if (*ptrg_j == 1 && grid[*ptrg_i][(*ptrg_j) + 1] != X && grid[*ptrg_i][(*ptrg_j) + 1] != O) (*ptrg_j)++;
		else Set_Symbol(grid, SIZE, ptrg_i, ptrg_j, control);		
	}
	else if (control == MOVE_LEFT && *ptrg_j != 0)
	{
		if (*ptrg_j == 2 && grid[*ptrg_i][(*ptrg_j) - 1] != X && grid[*ptrg_i][(*ptrg_j) - 1] != O) (*ptrg_j)--;
		else if (*ptrg_j == 2 && grid[*ptrg_i][(*ptrg_j) - 2] != X && grid[*ptrg_i][(*ptrg_j) - 2] != O) (*ptrg_j) -= 2;
		else if (*ptrg_j == 1 && grid[*ptrg_i][(*ptrg_j) - 1] != X && grid[*ptrg_i][(*ptrg_j) - 1] != O) (*ptrg_j)--;
		else Set_Symbol(grid, SIZE, ptrg_i, ptrg_j, control);
	}
}

int Set_Symbol(char grid[SIZE][SIZE], int SIZE, int* ptrg_i, int* ptrg_j, char m_plr)
{
	grid[*ptrg_i][*ptrg_j] = m_plr;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (grid[i][j] == EMPTY)
			{
				grid[i][j] = CURSOR;
				*ptrg_i = i;
				*ptrg_j = j;
				return 0;
			}
		}
	}	
}

int Set_Symbol(char grid[SIZE][SIZE], int SIZE, int* ptrg_i, int* ptrg_j, int control)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (grid[i][j] == EMPTY)
			{
				grid[i][j] = CURSOR;
				*ptrg_i = i;
				*ptrg_j = j;
				return 0;
			}
		}
	}
}

int Check_Win(char grid[SIZE][SIZE], int SIZE)
{
	if (grid[1][1] != EMPTY && ((grid[1][1] == grid[0][0] && grid[1][1] == grid[2][2]) || (grid[1][1] == grid[0][2] && grid[1][1] == grid[2][0]) || (grid[1][1] == grid[0][1] && grid[1][1] == grid[2][1]) || (grid[1][1] == grid[1][0] && grid[1][1] == grid[1][2]))) //Проверка от центра
	{
		Print_Grid(grid, SIZE);
		setlocale(LC_ALL, "ru");
		cout << "Победил игрок " << grid[1][1] << "!" << endl;
		setlocale(LC_ALL, "С");
	}	
	else if (grid[0][0] != EMPTY && ((grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2]) || (grid[0][0] == grid[1][0] && grid[0][0] == grid[2][0]))) //Проверка от верхнего левого угла
	{
		Print_Grid(grid, SIZE);
		setlocale(LC_ALL, "ru");
		cout << "Победил игрок " << grid[0][0] << "!" << endl;
		setlocale(LC_ALL, "С");
	}
	else if (grid[2][2] != EMPTY && ((grid[2][2] == grid[2][1] && grid[2][2] == grid[2][0]) || (grid[2][2] == grid[1][2] && grid[2][2] == grid[0][2]))) //Проверка от нихнего правого угла
	{
		Print_Grid(grid, SIZE);
		setlocale(LC_ALL, "ru");
		cout << "Победил игрок " << grid[2][2] << "!" << endl;
		setlocale(LC_ALL, "С");
	}
	else //Проверка на ничью
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (grid[i][j] == EMPTY) return 0;
			}
		}
		setlocale(LC_ALL, "ru");
		cout << "Ничья" << endl;
		setlocale(LC_ALL, "С");
		return 0;
	}
}