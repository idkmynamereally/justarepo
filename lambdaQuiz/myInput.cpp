#include <iostream>
#include "myInput.h"

namespace GoodInput
{
	void ignoreLine()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	int getInt()
	{
		int a{};
		while (true)
		{
			std::cin >> a;
			if (std::cin.fail())
			{
				std::cin.clear();
				ignoreLine();
				std::cout << "Invalid Input! Try Again!" << std::endl;
			}
			else
			{
				ignoreLine();
				return a;
			}
		}
	}

	float getFloat()
	{
		float a{};
		while (true)
		{
			std::cin >> a;
			if (std::cin.fail())
			{
				ignoreLine();
				std::cout << "Invalid Input! Try Again";
			}
			else
			{
				ignoreLine();
				return a;
			}
		}
	}
	double getDouble()
	{
		double a{};
		while (true)
		{
			std::cin >> a;
			if (std::cin.fail())
			{
				ignoreLine();
				std::cout << "Invalid Input! Try Again";
			}
			else
			{
				ignoreLine();
				return a;
			}
		}
	}
	char getChar()
	{
		char a{};
		while (true)
		{
			std::cin >> a;
			if (std::cin.fail())
			{
				ignoreLine();
				std::cout << "Invalid Input! Try Again";
			}
			else
			{
				ignoreLine();
				return a;
			}
		}
	}

}
