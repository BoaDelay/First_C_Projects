#include <stdio.h>
#include <Windows.h>
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 4));
//printf("1. Red\n");
//SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 2));
//printf("2. Green\n");
//SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 1));
//printf("3. Blue\n");
//SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 15));
//a, b, c, d, и так далее это переменный для счетчика

struct Stek
{
	int top;
	int size;
	int repository[9];
};

void flushKeyBoard()
{
	int a;
	while ((a = getc(stdin)) != EOF && a != '\n');
	//эта функция скопирована из интернета
	//она будет заменять метод .ignore из C++
}

char ActionChoise()
{
	char action;
	int b = 1;
	while (b != 0)
	{
		scanf_s("%c", &action);
		if (action != EOF && action != '\n')
		{
			flushKeyBoard();
			//printf("%c\n", action);
			//раскоментить для отладки
			b = 0;
			//если символ не конец файла и не новая строка
			//для того что бы не считался перевод строки как символ
		}
		else
		{
			printf("Please choose action\n");
		}
	}
	return action;
}

//void ColorText()
//{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 4));
	//printf("1. Red\n");
	//SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 2));
	//printf("2. Green\n");
	//SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 1));
	//printf("3. Blue\n");
	//SetConsoleTextAttribute(hConsole, (WORD)((0 << 0) | 15));
//}

int ColorChoise(int d = 1, int color = 0)
{
	printf("Choose pencil color\n");
	printf("1. ");
	printf("Red\n");
	printf("2. ");
	printf("Green\n");
	printf("3. ");
	printf("Blue\n");
	while (d != 0)
	{
		char afteractioncolor = ActionChoise();
		switch (afteractioncolor)
		{
		case '1':
			d = 0;
			color = 1;
			break;
		case '2':
			d = 0;
			color = 2;
			break;
		case '3':
			d = 0;
			color = 3;
			break;
		default:
			printf("Please choose color\n");
			break;
		}
	}
	return color;
}

int main()
{
	Stek PencilBox;
	int c = 0;
	int red = 1, green = 2, blue = 3;
	for (int i = 1; i != 0; i++)
	{
		printf("choose action:\n");
		printf("1. Put the pencil into the box\n");
		printf("2. Get the pencil out of the box\n");
		printf("3. Count the pencil in the box\n");
		printf("4. Show the last putted pencil\n");
		printf("5. Show all pencils in the box\n");
		printf("6. Exit\n");
		char afteraction = ActionChoise();
		switch (afteraction)
		{
			case '1':
				if (c == 10)
				{
					printf("Pencil box is full, please try another action\n");
					break;
				}
				else
				{
					PencilBox.repository[c] = ColorChoise();
					c++;
					if (PencilBox.repository[c - 1] == 1)
					{
						printf("You putted red pencil in the box\n");
					}
					if (PencilBox.repository[c - 1] == 2)
					{
						printf("You putted green pencil in the box\n");
					}
					if (PencilBox.repository[c - 1] == 3)
					{
						printf("You putted blue pencil in the box\n");
					}
				}
				break;
			case '2':
				if (c == 0)
				{
					printf("There are no pencils in the pencil box, please try another action\n");
					break;
				}
				else
				{
					if (PencilBox.repository[c - 1] == 1)
					{
						printf("You held red pencil in the box\n");
					}
					if (PencilBox.repository[c - 1] == 2)
					{
						printf("You held green pencil in the box\n");
					}
					if (PencilBox.repository[c - 1] == 3)
					{
						printf("You held blue pencil in the box\n");
					}
					PencilBox.repository[c-1] = NULL;
					c--;
				}
				break;
			case '3':
				PencilBox.size = c;
				if (PencilBox.size == 1)
				{
					printf("There is 1 pencil in the box\n");
				}
				if (PencilBox.size == 0)
				{
					printf("There are no pencils in the box\n");
				}
				if (PencilBox.size != 1 && PencilBox.size != 0)
				{
					printf("There are %d pencils in the box\n", PencilBox.size);
				}
				break;
			case '4':
				if (c == 0)
				{
					printf("There are no pencils in the box\n");
				}
				else
				{
					if (PencilBox.repository[c - 1] == 1)
					{
						printf("The last putted pencil is red\n");
					}
					if (PencilBox.repository[c - 1] == 2)
					{
						printf("The last putted pencil is green\n");
					}
					if (PencilBox.repository[c - 1] == 3)
					{
						printf("The last putted pencil is blue\n");
					}
				}
				break;
			case '5':
				if (c == 0)
				{
					printf("There are no pencils in the box\n");
				}
				else
				{
					int e = 0;
					int f;
					while (e != c)
					{
						if (PencilBox.repository[c - (c- e)] == 1)
						{
							printf("Red pencil\n");
						}
						if (PencilBox.repository[c - (c - e)] == 2)
						{
							printf("Green pencil\n");
						}
						if (PencilBox.repository[c - (c - e)] == 3)
						{
							printf("Blue pencil\n");
						}
						e++;
					}
				}
				break;
			case '6':
				printf("Good bye\n");
				return 0;
			default:
				printf("Please choose action\n");
				break;
		}
	}
	return 0;
}