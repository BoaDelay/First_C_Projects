#include <iostream>
#include <string>

using namespace std;

bool IsPolyndrom(string input)
{
	for (int i = 0; i != input.length(); i++)
	{
		input.erase(find(input.begin(), input.end(), ' '));
	}

	for (int i = 0; i != input.length(); i++)
	{
		if (input[i] != input[input.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string input;
	getline(cin, input);

	if (IsPolyndrom(input))
	{
		cout << input << " is a polyndrom" << endl;
	}
	else
	{
		cout << input << " is not polyndrom" << endl;
	}
}