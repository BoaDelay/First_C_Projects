#include <stdio.h>
#include <cstdlib>
#include <assert.h>

struct Stack
{
	int* memory_pointer;
	unsigned int size;
	unsigned int amount_of_elements;
};

void Stack_Init(Stack* x)
{
	x->size = 8;
	x->amount_of_elements = 0;
	x->memory_pointer = (int*)calloc(x->size, sizeof(int));
}

void Stack_Delete(Stack* x)
{
	free(x->memory_pointer);
}

void Push(Stack* x, int stack_data)
{
	if (x->amount_of_elements == x->size)
	{
		x->size = x->size * 2;
		x->memory_pointer = (int*)realloc(x->memory_pointer, (x->size * sizeof(int)));
		x->memory_pointer[x->amount_of_elements++] = stack_data;
		printf("%d was added to the stack\n", x->memory_pointer[x->amount_of_elements - 1]);
	}
	else
	{
		x->memory_pointer[x->amount_of_elements++] = stack_data;
		printf("%d was added to the stack\n", x->memory_pointer[x->amount_of_elements - 1]);
	}
}

void Pop(Stack* x)
{
	if ((x->size / 4) == x->amount_of_elements)
	{
		x->size = x->size / 3;
		x->memory_pointer = (int*)realloc(x->memory_pointer, (x->size * sizeof(int)));
		assert(x->amount_of_elements != 0 && "Pop from empety stack");
		printf("%d was deleted from the stack\n", x->memory_pointer[x->amount_of_elements - 1]);
		x->memory_pointer[--x->amount_of_elements] = NULL;
	}
	else
	{
		assert(x->amount_of_elements != 0 && "Pop from empety stack");
		printf("%d was deleted from the stack\n", x->memory_pointer[x->amount_of_elements - 1]);
		x->memory_pointer[--x->amount_of_elements] = NULL;
	}
}

void ShowAll(const Stack* x)
{
	for (int i = 0; i < x->amount_of_elements; i++)
	{
		printf("%d\n", x->memory_pointer[i]);
	}
}

void Top(const Stack* x)
{
	printf("The last element is %d\n", x->memory_pointer[x->amount_of_elements - 1]);
}

void Amount_Of_Elements(const Stack* x)
{
	printf("There are %d elements in the stack\n", x->amount_of_elements);
}

int main()
{
	Stack x;

	Stack_Init(&x);
	Stack_Delete(&x);
	return 0;
}