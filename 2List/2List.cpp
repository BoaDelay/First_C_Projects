#include <stdio.h>
#include <cstdlib>
#include <assert.h>

typedef struct node
{
	int data;
	node* next;
	node* prev;
}node;

typedef struct doublelinkedlist
{
	node* begin;
	node* end;
	size_t size;
}doublelinkedlist;

doublelinkedlist* DoubleLinkedListInit()
{
	doublelinkedlist* x = (doublelinkedlist*)malloc(sizeof(doublelinkedlist));

	x->begin = NULL;
	x->end = NULL;
	x->size = 0;

	return x;
}

void DoubleLinkedListDelete(doublelinkedlist* x)
{
	node* slider = x->begin;
	node* deleter = NULL;

	while (slider)
	{
		deleter = slider;
		slider = slider->next;

		free(deleter);
	}

	free(x);
}

void AddBegin(doublelinkedlist* x, int data)
{
	node* temp = (node*)malloc(sizeof(node));

	temp->data = data;
	temp->next = x->begin;
	temp->prev = NULL;

	if (x->begin)
	{
		x->begin->prev = temp;
	}

	x->begin = temp;

	if (x->end == NULL)
	{
		x->end = temp;
	}

	x->size++;

	printf("Element was added to the beginning of the list\n");
}

void AddEnd(doublelinkedlist* x, int data)
{
	node* temp = (node*)malloc(sizeof(node));

	temp->data = data;
	temp->prev = x->end;
	temp->next = NULL;

	if (x->end)
	{
		x->end->next = temp;
	}

	x->end = temp;

	if (x->begin == NULL)
	{
		x->begin = temp;
	}

	x->size++;

	printf("Element was added to the end of the list\n");
}

void DeleteBegin(doublelinkedlist* x)
{
	node* deleter = x->begin;

	assert(x->begin != NULL && "Can not delete element\n");

	x->begin = x->begin->next;

	if (x->begin)
	{
		x->begin->prev = NULL;
	}

	if (deleter == x->end)
	{
		x->end = NULL;
	}

	free(deleter);

	x->size--;

	printf("Element was deleted from the beginning of the list\n");
}

void DeleteEnd(doublelinkedlist* x)
{
	node* deleter = x->end;

	assert(x->end != NULL && "Can not delete element\n");

	x->end = x->end->prev;

	if (x->end)
	{
		x->end->next = NULL;
	}

	if (deleter == x->begin)
	{
		x->begin = NULL;
	}

	free(deleter);

	x->size--;

	printf("Element was deleted from the end of the list\n");
}

void ShowAll(const doublelinkedlist* x)
{
	node* slider = x->begin;

	while (slider != NULL)
	{
		printf("%d\n", slider->data);

		slider = slider->next;
	}
}

node* GetNthElem(doublelinkedlist* x, int index)
{
	assert(x->size >= index && "Wrong index\n");
	assert(index >= 0 && "Wrong index\n");

	node* slider = x->begin;
	size_t i = 0;

	while (slider && i < index)
	{
		slider = slider->next;
		i++;
	}

	return slider;
}

void Insert(doublelinkedlist* x, int index, int data)
{
	assert(index <= x->size && "Wrong index\n");

	node* slider = GetNthElem(x, index);
	node* temp = (node*)malloc(sizeof(node));

	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;

	if (slider)
	{
		temp->next = slider;

		if (slider->prev)
		{
			slider->prev->next = temp;
		}

		temp->prev = slider->prev;
		slider->prev = temp;
	}

	if (!temp->prev)
	{
		x->begin = temp;
	}

	if (!temp->next)
	{
		x->end = temp;
	}

	x->size++;

	printf("%d Element was added to the list\n", index);
}

void DeleteNthElem(doublelinkedlist* x, int index)
{
	assert(x->size >= index + 1 && "Wrong index\n");

	node* slider = GetNthElem(x, index);

	printf("data %d\n", slider->data);

	if (slider->prev)
	{
		slider->prev->next = slider->next;
	}

	if (slider->next)
	{
		slider->next->prev = slider->prev;
	}

	if (!slider->prev)
	{
		x->begin = slider->next;
	}

	if (!slider->next)
	{
		x->end = slider->prev;
	}

	free(slider);

	x->size--;

	printf("%d element was deleted from the list\n", index);
}

void size(const doublelinkedlist* x)
{
	printf("%d", x->size);
}

int main()
{
	doublelinkedlist* x = DoubleLinkedListInit();

	Insert(x, 0, 1);
	DeleteNthElem(x, 0);
	ShowAll(x);

	DoubleLinkedListDelete(x);
}