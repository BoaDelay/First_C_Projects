#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void FileRead()
{
	int i = 0;
	int numerical_commands[256] = { 0 };
	std::string buff;
	std::ifstream user_instructions ( "user_data.txt", std::ios::in);

	if (!user_instructions)
	{
		std::cout << "Reading of file is failed" << std::endl;
	}

	while (std::getline(user_instructions, buff, '\n'))
	{
		std::stringstream iss(buff);
		std::string command;

		iss >> command;

		if (!command.compare("push"))
		{
			numerical_commands[i] = 1;
			i++;

			std::string number;
			int k = 5;

			while (buff[k] != NULL && buff[k] != ' ')
			{
				number += buff[k];
				k++;
			}

			numerical_commands[i] = std::stoi(number);
			i++;
		}

		if (!command.compare("pop"))
		{
			numerical_commands[i] = 2;
			i++;
		}

		if (!command.compare("add"))
		{
			numerical_commands[i] = 3;
			i++;
		}

		if (!command.compare("sub"))
		{
			numerical_commands[i] = 4;
			i++;
		}

		if (!command.compare("mul"))
		{
			numerical_commands[i] = 5;
			i++;
		}

		if (!command.compare("div"))
		{
			numerical_commands[i] = 6;
			i++;
		}
	}

	for (int i = 0; i < 11; i++)
	{
		std::cout << numerical_commands[i] << std::endl;
	}
}

int main()
{
	FileRead();
}