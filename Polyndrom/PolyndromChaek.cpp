#include <iostream>
#include <string>
#include <sstream>

void IsPolyndrom(const std::string& input, const std::string& input_keeper)
{
	for (int i = 0; i != (input.length() / 2); i++)
	{
		if (input[i] != input[input.length() - i - 1])
		{
			std::cout << input_keeper << " is not polyndrom" << std::endl;
			exit(0);
		}
	}
	std::cout << input_keeper << " is a polyndrom" << std::endl;
	exit(0);
}

void Input()
{
	std::string input;
	std::getline(std::cin, input);
	const std::string input_keeper = input;

	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

	IsPolyndrom(input, input_keeper);
}

int main()
{
	Input();
}