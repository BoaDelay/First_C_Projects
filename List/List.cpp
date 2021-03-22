#include <stdio.h>
#include <cstdlib>

struct node
{
	int data;
	node* next;
};

node* ListInit(int data)
{
	node* root = (node*)malloc(sizeof(node));

	root->data = data;
	root->next = NULL;

	return root;
}

void ListDelete(node* x)
{
	while (x != NULL)
	{
		node* temp = x;
		x = x->next;

		free(temp);
	}
}

node* AddBegin(int data, node* x)
{
	node* temp = (node*)malloc(sizeof(node));

	temp->data = data;
	temp->next = x;

	return temp;
}

node* DelBegin(node* x)
{
	node* temp = x;
	x = x->next;

	free(temp);
}

node* AddEnd(int data, node* x)
{
	node* temp = (node*)malloc(sizeof(node));

	temp->data = data;
	temp->next = NULL;

	node* slider = x;

	while (slider->next != NULL)
	{
		slider = slider->next;
	}

	slider->next = temp;

	return temp;
}

node* DelEnd(node* x)
{
	node* slider = x;
	node* temp_slider = x;
	int i = 0;

	while (slider->next != NULL)
	{
		slider = slider->next;
		if (i != 0)
		{
			temp_slider = temp_slider->next;
		}
		i++;
	}

	free(slider);

	temp_slider->next = NULL;
}

void ShowAll(node* x)
{
	node* slider = x;

	while (slider->next != NULL)
	{
		printf("%d", slider->data);

		slider = slider->next;
	}
}

int main()
{
	node* root = ListInit(1);
	//ListDelete();
}