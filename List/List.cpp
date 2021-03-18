#include <stdio.h>
#include <cstdlib>

struct node
{
	int data;
	struct node* next;
};

void RoadToElement(node* x)
{

}

void ListInitialization(node* x)
{
	x = (node*)malloc(sizeof(node));
	x->next = NULL;
}

void ListDelete(node* x)
{
	free(x);
}

void ShowAll(const node* x)
{

}

void ElementAdd(node* x)
{

}

void ElementDelete(node* x)
{

}

void AmountOfElements(const node* x)
{

}

void ShowElement(const node* x)
{

}

bool ActionChoise(node* x)
{
	char input;

	scanf_s("%c", &input);

	printf("Choose action:\n");
	printf("1. Show element\n");
	printf("2. Show all elements\n");
	printf("3. Add element\n");
	printf("4. Delete element\n");
	printf("5. Find out the number of elements\n");
	printf("6. Exit\n");

	switch (input)
	{
		case '1':
			ShowElement(x);
			return false;
		case '2':
			ShowAll(x);
			return false;
		case '3':
			ElementAdd(x);
			return false;
		case '4':
			ElementDelete(x);
			return false;
		case '5':
			AmountOfElements(x);
			return false;
		case '6':
			return true;
	}
}

int main()
{
	node list;

	for (;;)
	{
		if (ActionChoise(&list))
		{
			exit(0);
		}
	}
}