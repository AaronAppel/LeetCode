
#include <iostream>
#include <string>
#include <map>

unsigned short GetNumberFromUser();

int main_unused()
{
	unsigned short problemNumber = 0;

	do
	{
		std::cout << "\n\nEnter problem number or 0 to exit: ";
		problemNumber = GetNumberFromUser();

	} while (problemNumber > 0);

	return 0;
}

unsigned short GetNumberFromUser()
{
	std::string userInput;
	std::cin >> userInput;

	if (userInput.empty())
	{
		return UINT16_MAX; // Invalidate input. Avoid exception in stoi
	}

	for (size_t i = 0; i < userInput.size(); i++)
	{
		if (userInput[i] > 57 || userInput[i] < 48)
		{
			return UINT16_MAX; // Invalidate input. Avoid exception in stoi
		}
	}
	return std::stoi(userInput);
}
