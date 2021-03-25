#include <stdio.h>
#include <cstdlib>
#include <assert.h>

struct node
{
	int data;
	node* next;
	node* prev;
};

struct doublelinkedlist
{
	node* begin;
	node* end;
	size_t size;
};

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

node* AddBegin(doublelinkedlist* x, int data)
{
	node* temp = (node*)malloc(sizeof(node));

	x->begin->next = temp;
	temp->prev = x->begin;
	temp->data = data;

	printf("Element was added to the beginning of the list\n");

	return temp;
}

node* AddEnd(doublelinkedlist* x, int data)
{
	node* temp = (node*)malloc(sizeof(node));

	x->end->prev = temp;
	temp->next = x->end;
	temp->data = data;

	printf("Element was added to the end of the list\n");

	return temp;
}

void DeleteBegin(doublelinkedlist* x)
{
	node* slider = x->begin;
	node* deleter = NULL;

	assert(slider->next != x->end && "Can not delete root element\n");

	slider = slider->next;
	deleter = slider;
	slider = slider->next;

	free(deleter);

	x->begin->next = slider;
	slider->prev = x->begin;

	printf("Element was deleted from the beginning of the list\n");
}

void DeleteEnd(doublelinkedlist* x)
{
	node* slider = x->end;
	node* deleter = NULL;

	assert(slider->prev != x->begin && "Can not delete root element\n");

	slider = slider->prev;
	deleter = slider;
	slider = slider->prev;

	free(deleter);

	x->end->prev = slider;
	slider->next = x->end;

	printf("Element was deleted from the end of the list\n");
}

int main()
{
	doublelinkedlist* x = DoubleLinkedListInit();
	DoubleLinkedListDelete(x);
}