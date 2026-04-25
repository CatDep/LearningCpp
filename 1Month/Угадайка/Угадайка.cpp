#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::srand(std::time(0));
	int random = rand() % 100 + 1;
	int number = 0;
	int count = 0;
	std::cout << "Загадано число от 1 до 100" << std::endl;
	while (random != number)
	{
		std::cout << "Введите число: ";
		std::cin >> number;
		if (number > 0 && number < 101)
		{
			if (number > random)
			{
				std::cout << "Загаданное число меньше" << std::endl;
			}
			else if (number < random)
			{
				std::cout << "Загаданное число больше" << std::endl;
			}
		}
		else
		{
			std::cout << "Число должно быть от 1 до 100" << std::endl;
		}
		
		count++;
	}
	std::cout << "Вы угадали! Количество попыток: " << count << "." << std::endl;
}

