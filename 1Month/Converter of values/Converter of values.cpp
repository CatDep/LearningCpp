#include <iostream>
#include <Windows.h>

enum E_Menu
{
	centimeters_meters = 1,
	meters_centimeters = 2,
	Climbers_Grams = 3,
	Grams_Climbers = 4,
	Cyssia_Fahrenheit = 5,
	Fahrenheit_Cyssia = 6,
	Exit = 7
};


void F_centimeters()
{
	std::cout << "\n\tСантиметры -> метры\n\n" << std::endl;

	double count;
	
	std::cout << "\nВведите число которое вы хотите перевести в метры: ";
	std::cin >> count;
	std::cout << "\n" << count << " сантиметров = " << count / 100 << " метров." << std::endl;
}


void F_Meters()
{
	std::cout << "\n\tМетры -> сантиметры\n\n" << std::endl;

	double count;

	std::cout << "\nВведите число которое вы хотите перевести в сантиметры: ";
	std::cin >> count;
	std::cout << "\n" << count << " метров = " << count * 100 << " сантиметров." << std::endl;
}


void F_Climbers()
{
	std::cout << "\n\tКилограммы -> граммы\n\n" << std::endl;

	double count;

	std::cout << "\nВведите число которое вы хотите перевести в граммы: ";
	std::cin >> count;
	std::cout << "\n" << count << " килограммов = " << count * 1000 << " грамм" << std::endl;
}


void F_Grams()
{
	std::cout << "\n\tГраммы -> килограммы\n\n" << std::endl;

	double count;

	std::cout << "\nВведите число которое вы хотите перевести в килограммы: ";
	std::cin >> count;

	std::cout << "\n" << count << " граммов = " << count / 1000 << " килограмм" << std::endl;
}


void F_Cyssia()
{
	std::cout << "\n\tЦельсия -> Фаренгейт\n\n" << std::endl;

	double count;

	std::cout << "\nВведите число которое вы хотите перевести в градусы Фаренгейта: ";
	std::cin >> count;
	
	std::cout << "\n" << count << " Сº = " << ((count * 9) / 5) + 32 << " Fº." << std::endl;
}


void F_Fahrenheit()
{
	std::cout << "\n\tФаренгейт -> Цельсия\n\n" << std::endl;

	double count;

	std::cout << "\nВведите число которое вы хотите перевести в градусы Цельсия: ";
	std::cin >> count;

	std::cout << "\n" << count << " Fº = " << (count - 32) * 5 / 9  << " Сº." << std::endl;
}


void F_Menu()
{
	while (true)
	{
		std::cout << "\n\tДобро пожаловать в конвертёр величин\n\n" << std::endl;

		std::cout << "\n1 - Сантиметры -> метры" << std::endl;
		std::cout << "2 - Метры -> сантиметры" << std::endl;
		std::cout << "3 - Килограммы -> граммы" << std::endl;
		std::cout << "4 - Граммы -> килограммы" << std::endl;
		std::cout << "5 - Градусы Цельсия -> градусы Фаренгейта" << std::endl;
		std::cout << "6 - Градусы Фаренгейта -> градусы Цельсия" << std::endl;
		std::cout << "7 - Выход\n" << std::endl;
		std::cout << "Выбирите пункт меню: ";
		int count;
		enum E_Menu choice;
		std::cin >> count;
		choice = (enum E_Menu)count;
		switch (choice)
		{
		case centimeters_meters:
			F_centimeters();
			break;
		case meters_centimeters:
			F_Meters();
			break;
		case Climbers_Grams:
			F_Climbers();
			break;
		case Grams_Climbers:
			F_Grams();
			break;
		case Cyssia_Fahrenheit:
			F_Cyssia();
			break;
		case Fahrenheit_Cyssia:
			F_Fahrenheit();
			break;
		case Exit:
			std::exit(0);
			break;
		default:
			std::cout << "Попробуйте ещё раз" << std::endl;
			break;
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	F_Menu();
}

