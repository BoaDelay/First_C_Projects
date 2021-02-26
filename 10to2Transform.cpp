#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Transform(int x)
{
	int x_copy = x;
	int a = 1;

	while (x >= 1)
	{
		if ((x % 2) != 0)
		{
			x = x - 1;
		}
		x = x / 2;
		a++;
	}

	int a_copy = a;

	int* y;
	y = (int*)calloc(a, sizeof(int));
	while (x_copy >= 1)
	{
		if ((x_copy % 2) == 0)
		{
			y[a-1] = 0;
		}
		else
		{
			y[a-1] = 1;
			x_copy = x_copy - 1;
		}
		x_copy = x_copy / 2;
		a--;
	}

	for (int b = 1; b < a_copy; b++)
	{
		cout << y[b];
	}

	free(y);
}

int main()
{
	int x;
	cin >> x;

	Transform(x);
}