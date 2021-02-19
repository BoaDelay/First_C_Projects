#include <stdio.h>
#include <cstdlib>
#include<locale.h> 

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
		printf("Стек полон\n");
		//Stack is full
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
		printf("Стек пуст\n");
		//Stack is empty
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
		printf("Невозможно добавить число в стек\n");
		//Can not Push
	}
	else
	{
		x->memory_pointer[x->amount_of_elements++] = stack_data;
		printf("число %d было добавлено в стек\n", x->memory_pointer[x->amount_of_elements - 1]);
		//%d was added to the stack
	}
}

void Pop(Stack* x)
{
	if (IsEmpty(x))
	{
		printf("Невозможно убрать число из стека\n");
		//Can not Pop
	}
	else
	{
		printf("число %d было удалено из стека\n", x->memory_pointer[x->amount_of_elements - 1]);
		//%d was deleted from the stack
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
	printf("Последний элемент стека %d\n", x->memory_pointer[x->amount_of_elements - 1]);
	//The last element is %d
}

void Amount_Of_Elements(Stack* x)
{
	printf("В стеке %d элементов\n", x->amount_of_elements);
	//There are %d elements in the stack
}

int Size_Init(Stack* x)
{
	printf("Введите размер стека\n");
	//Enter stack size
	scanf_s("%d", &x->size);
	return x->size;
}

void Stack_Data_Init(int* stack_data)
{
	printf("Выберите число\n");
	//Choose number
	scanf_s("%d", &*stack_data);
}

bool ActionChoise(Stack* x)
{
	printf("Выберете действие:\n");
	printf("1. Добавить значение в стек\n");
	printf("2. Убрать значение из стека\n");
	printf("3. Показать содержимое стека\n");
	printf("4. Показать последнее число в стеке\n");
	printf("5. Показать количество элементов в стеке\n");
	printf("6. Завершить программу\n");
	/*Choose action:
	1. Push
	2. Pop
	3. Show all
	4. Top
	5. Size
	6. Exit*/
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
			Amount_Of_Elements(x);
			break;
		case 6:
			return true;
		default:
			printf("Ошибка выбора, попробуйте снова\n");
			break;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "RUS");

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