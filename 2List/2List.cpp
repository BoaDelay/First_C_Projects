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
	assert(x->size >= index && index > 0 && "Wrong index\n");

	node* slider = NULL;

	if (index >= x->size / 2)
	{
		slider = x->end;

		for (int i = x->size; i > index; i--)
		{
			slider = slider->prev;
		}
	}
	else
	{
		slider = x->begin;

		for (int i = 1; i < index; i++)
		{
			slider = slider->next;
		}
	}

	return slider;
}

void Insert(doublelinkedlist* x, int index, int data)
{
	node* slider = GetNthElem(x, index);
	node* temp = (node*)malloc(sizeof(node));

	temp->data = data;

	if (slider->next == NULL)
	{
		x->end = temp;
	}
	else
	{

	}

	x->size++;

	printf("%d Element was added to the list\n", index);
}

void DeleteNthElem(doublelinkedlist* x, int index)
{
	node* slider = GetNthElem(x, index);

	node* deleter = slider;
	node* temp_slider = slider->next;

	slider = slider->prev;

	free(deleter);

	if (slider)
	{
		slider->next = temp_slider;
	}
	else
	{
		x->begin = slider;
	}

	if (temp_slider)
	{
		temp_slider->prev = slider;
	}
	else
	{
		x->end = temp_slider;
	}

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

	AddEnd(x, 1);
	//AddEnd(x, 2);
	//AddEnd(x, 3);
	//AddEnd(x, 4);
	//node* elem = GetNthElem(x, 1);
	//printf("%d", elem->data);
	//AddEnd(x, 4);
	//AddBegin(x, 2);
	//AddBegin(x, 1);
	//DeleteBegin(x);
	//DeleteEnd(x);
	//ShowAll(x);
	DeleteNthElem(x, 1);
	ShowAll(x);

	DoubleLinkedListDelete(x);
}