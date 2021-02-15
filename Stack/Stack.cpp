#include <stdio.h>

struct Stack
{
	int top = -1;
	size_t mass_size = 10;
	int mass[10] = { 0 };
};

bool IsEmpty(Stack *x)
{
	if (x->top == -1)
	{
		printf("Stack is empty\n");
		return true;
	}
	else
	{
		return false;
	}
}

bool IsFull(Stack *x)
{
	if (x->top == (x->mass_size - 1))
	{
		printf("Stack is full\n");
		return true;
	}
	else
	{
		return false;
	}
}

void Pop(Stack *x)
{
	if (IsEmpty(x))
	{
		printf("Can not pop\n");
	}
	else
	{
		printf("%d was got from the stack\n", x->mass[x->top]);
		x->mass[x->top] = 0;
		x->top--;
	}
}

void Push(Stack *x, char number)
{
	if (IsFull(x))
	{
		printf("Can not push\n");
	}
	else
	{
		x->top++;
		x->mass[x->top] = number;
		printf("%c was added to the stack\n", number);
	}
}

void Top(Stack *x)
{
	if (IsEmpty(x))
	{
		printf("No top in stack\n");
	}
	else
	{
		printf("%d\n", x->mass[x->top]);
	}
}

void Size(Stack *x)
{
	if (IsEmpty(x) == false)
	{
		printf("%d\n", (x->top + 1));
	}
}

void ShowAll(Stack *x)
{
	for (int i = 1; i <= x->top; i++)
	{
		printf("%d\n", x->mass[i]);
	}
}

void FlushKeyBoard(int i)
{
	while ((i = getc(stdin)) != EOF && i != '\n');
}

char ActionChoise()
{
	char actionS;
	int i = 0;
	while (i != 1)
	{
		scanf_s("%c", &actionS);
		if (actionS != EOF && actionS != '\n')
		{
			FlushKeyBoard(i);
			i = 1;
		}
		else
		{
			printf("Please choose action\n");
		}
	}
	return actionS;
}

char NumberChoise()
{
	char numberS;
	int i = 0;
	while (i != 1)
	{
		scanf_s("%c", &numberS);
		if (numberS != EOF && numberS != '\n')
		{
			FlushKeyBoard(i);
			i = 1;
		}
		else
		{
			printf("Please choose action\n");
		}
	}
	return numberS;
}

int ActionSwitch(Stack *x, char action)
{
	char number;
	switch (action)
	{
		case '1':
			number = NumberChoise();
			Push(x, number);
			break;
		case '2':
			Pop(x);
			break;
		case '3':
			Size(x);
			break;
		case '4':
			Top(x);
			break;
		case '5':
			ShowAll(x);
			break;
		case '6':
			return 0;
	}
}

int main()
{
	Stack x;
	for (int i = 1; i != 0; i++)
	{
		printf("choose action:\n");
		printf("1. Add the number into the stack\n");
		printf("2. Get the number out of the stack\n");
		printf("3. Count the numbers in the stack\n");
		printf("4. Show the last added number\n");
		printf("5. Show all numbers in the stack\n");
		printf("6. Exit\n");
		char action = ActionChoise();
		ActionSwitch(&x, action);
	}
}