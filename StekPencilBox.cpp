#include <stdio.h>

struct Stek
{
	int top;
	int size;
	int repository[10];
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

int main()
{
	Stek PencilBox;
	int c = 1;
	printf("choose action:\n");
	printf("1. Put the pencil into the box\n");
	printf("2. Get the pencil out of the box\n");
	printf("3. Count the pencil in the box\n");
	printf("4. Show the last putted pencil\n");
	printf("5. Do nothing\n");
	for (int i = 1; i != 0; i++)
	{
		char afteraction = ActionChoise();
		switch (afteraction)
		{
		case 1:
			//printf("1\n");
			//раскоментить для отладки
		case 2:
			//printf("2\n");
			//раскоментить для отладки
		case 3:
			//printf("3\n");
			//раскоментить для отладки
		case 4:
			//printf("4\n");
			//раскоментить для отладки
		case 5:
			//printf("5\n");
			//раскоментить для отладки
		default:
			printf("Please choose action\n");
		}
	}
	return 0;
}