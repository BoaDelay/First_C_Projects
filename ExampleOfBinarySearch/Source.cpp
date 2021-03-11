#include <stdio.h>

struct list
{
	int mass[100];
	int max = 100;
	int min = 0;
	int mid;
};

int BinarySearch(list* x)
{
	int number;

	scanf_s("%d", &number);

	while (x->min < x->max - 1)
	{
		x->mid = ((x->max + x->min) / 2);

		if (x->mass[x->mid - 1] < number)
		{
			x->min = x->mid;
		}
		else
		{
			x->max = x->mid;
		}
	}

	if (number != 100 && x->max == 100)
	{
		return NULL;
	}
	else
	{
		return x->max;
	}
}

int main()
{
	list x;

	for (int i = 0; i < 100; i++)
	{
		x.mass[i] = i + 1;
	}

	int answer = BinarySearch(&x);

	if (answer == NULL)
	{
		printf("number was not found");
	}
	else
	{
		printf("%d\n", answer);
	}
}