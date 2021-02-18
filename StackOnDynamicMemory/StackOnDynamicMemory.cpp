#include <stdio.h>
#include <cstdlib>

struct Stack
{
	int* memory_pointer;
	unsigned int size;
	unsigned int amount_of_elements;
};

void Stack_Init(Stack* x)
{
	x->amount_of_elements = 0;
	x->memory_pointer = (int*)calloc(x->size, sizeof(int));
}

void Stack_Delete(Stack* x)
{
	free(x->memory_pointer);
}

bool IsFull(Stack* x)
{
	if (x->amount_of_elements == 10)
	{
		printf("Stack is full\n");
		return true;
	}
	else
	{
		return false;
	}
}

bool IsEmpty(Stack* x)
{
	if (x->amount_of_elements == 0)
	{
		printf("Stack is empty\n");
		return true;
	}
	else
	{
		return false;
	}
}

void Push(Stack* x, int stack_data)
{
	if (IsFull(x))
	{
		printf("Can not Push\n");
	}
	else
	{
		x->memory_pointer[x->amount_of_elements++] = stack_data;
		printf("%d was added to the stack\n", x->memory_pointer[x->amount_of_elements - 1]);
	}
}

void Pop(Stack* x)
{
	if (IsEmpty(x))
	{
		printf("Can not Pop\n");
	}
	else
	{
		printf("%d was deleted from the stack\n", x->memory_pointer[x->amount_of_elements - 1]);
		x->memory_pointer[--x->amount_of_elements] = NULL;
	}
}

void ShowAll(Stack* x)
{
	for (int i = 0; i < x->amount_of_elements; i++)
	{
		printf("%d\n", x->memory_pointer[i]);
	}
}

void Top(Stack* x)
{
	printf("The last element is %d\n", x->memory_pointer[x->amount_of_elements - 1]);
}

void Size(Stack* x)
{
	printf("There are %d elements in the stack\n", x->amount_of_elements);
}

int Size_Init(Stack* x)
{
	printf("Enter stack size\n");
	scanf_s("%d", &x->size);
	return x->size;
}

void Stack_Data_Init(int* stack_data)
{
	printf("Choose number\n");
	scanf_s("%d", &*stack_data);
}

bool ActionChoise(Stack* x)
{
	printf("Choose action\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Show all\n");
	printf("4. Top\n");
	printf("5. Size\n");
	printf("6. Exit\n");
	int action;
	scanf_s("%d", &action);
	int stack_data = 0;
	switch (action)
	{
		case 1:
			Stack_Data_Init(&stack_data);
			Push(x, stack_data);
			break;
		case 2:
			Pop(x);
			break;
		case 3:
			ShowAll(x);
			break;
		case 4:
			Top(x);
			break;
		case 5:
			Size(x);
			break;
		case 6:
			return true;
		default:
			printf("Choise error\n");
			break;
	}
	return false;
}

int main()
{
	Stack x;

	Size_Init(&x);
	Stack_Init(&x);
	for (;;)
	{
		if (ActionChoise(&x) == true)
		{
			return 0;
		}
	}
	/*Push(&x, 4);
	Size(&x);
	Top(&x);
	Pop(&x);
	Pop(&x);
	Push(&x, 1);
	Push(&x, 3);
	Push(&x, 2);
	Push(&x, 5);
	Push(&x, 4);
	Push(&x, 7);
	Push(&x, 6);
	Push(&x, 9);
	Push(&x, 8);
	Push(&x, 0);
	ShowAll(&x);
	Push(&x, 1);
	Stack_Delete(&x);*/
	return 0;
}