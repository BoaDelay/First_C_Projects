#include <stdio.h>

void Sort(int* x)
{
	for (int i = 0; i < 101; i++)
	{
		if (x[i] != 0)
		{
			for (int j = 0; j < x[i]; j++)
			{
				printf("%d\n", i);
			}
		}
	}
}

int main()
{
	int amount_of_elements;
	int counter;

	scanf_s("%d", &amount_of_elements);

	int storage[101] = {0};
	for (int i = 0; i < amount_of_elements; i++)
	{
		scanf_s("%d", &counter);
		storage[counter] += 1;
	}

	Sort(storage);
}