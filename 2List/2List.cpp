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

	x->size++;

	printf("Element was added to the beginning of the list\n");

	return temp;
}

node* AddEnd(doublelinkedlist* x, int data)
{
	node* temp = (node*)malloc(sizeof(node));

	x->end->prev = temp;
	temp->next = x->end;
	temp->data = data;

	x->size++;

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

	x->size--;

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

	x->size--;

	printf("Element was deleted from the end of the list\n");
}

void ShowAll(const doublelinkedlist* x)
{
	node* slider = x->begin;

	while (slider != NULL)
	{
		printf("%d\n", slider);

		slider = slider->next;
	}
}

node* AddFree(doublelinkedlist* x, int index, int data)
{
	node* temp = (node*)malloc(sizeof(node));

	if (index <= x->size / 2)
	{
		node* slider = x->begin;
		
		for (int i = 1; i != index - 1; i++)
		{
			slider = slider->next;
		}

		node* temp_slider = slider->next;

		temp->next = temp_slider;
		temp->prev = slider;
		temp->data = data;
	}
	else
	{
		node* slider = x->end;

		for (int i = x->size; i != index + 1; i--)
		{
			slider = slider->prev;
		}

		node* temp_slider = slider->prev;

		temp->next = slider;
		temp->prev = temp_slider;
		temp->data = data;
	}

	x->size++;

	printf("Element was added to the %d posision of the list\n", index);

	return temp;
}

void DeleteFree(doublelinkedlist* x, int index)
{
	if (index <= x->size / 2)
	{
		node* slider = x->begin;

		for (int i = 1; i != index - 1; i++)
		{
			slider = slider->next;
		}

		node* temp_slider = slider->next;
		temp_slider = temp_slider->next;

		free(slider->next);

		slider->next = temp_slider;
		temp_slider->prev = slider;
	}
	else
	{
		node* slider = x->end;

		for (int i = x->size; i != index + 1; i--)
		{
			slider = slider->prev;
		}

		node* temp_slider = slider->prev;
		temp_slider = temp_slider->prev;

		free(slider->prev);

		slider->prev = temp_slider;
		temp_slider->next = slider;
	}

	x->size--;

	printf("Element was deleted from the %d posision of the list\n", index);
}

int main()
{
	doublelinkedlist* x = DoubleLinkedListInit();
	DoubleLinkedListDelete(x);
}