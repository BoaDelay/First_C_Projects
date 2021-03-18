#include "StackOnDynamicMemory.h"

void Calculator(Stack* x)
{
	int input;

	while ((input = getchar()) != '\n')
	{
		int stack_data;

		//printf("%d\n", input);
		switch (input)
		{
			case ' ': 
				break;
			case '+':
				stack_data = x->memory_pointer[x->amount_of_elements - 2] + x->memory_pointer[x->amount_of_elements - 1];
				//printf("%d\n", stack_data);
				Pop(x);
				Pop(x);
				Push(x, stack_data);
				break;
			case '*':
				stack_data = x->memory_pointer[x->amount_of_elements - 2] * x->memory_pointer[x->amount_of_elements - 1];
				Pop(x);
				Pop(x);
				Push(x, stack_data);
				break;
			case '-':
				stack_data = x->memory_pointer[x->amount_of_elements - 2] - x->memory_pointer[x->amount_of_elements - 1];
				Pop(x);
				Pop(x);
				Push(x, stack_data);
				break;
			case '/':
				stack_data = x->memory_pointer[x->amount_of_elements - 2] / x->memory_pointer[x->amount_of_elements - 1];
				Pop(x);
				Pop(x);
				Push(x, stack_data);
				break;
			default:
				ungetc(input, stdin);
				assert(scanf_s("%d", &stack_data) == 1 && "Can not read in");
				Push(x, stack_data);
				break;
		}
	}
}

int main()
{
	Stack x;

	Stack_Init(&x);
	Calculator(&x);
	int result = x.memory_pointer[x.amount_of_elements - 1];
	printf("The result is %d\n", result);
	Stack_Delete(&x);
	return 0;
}