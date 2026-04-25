#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>


enum E_Menu
{
	InputText = 1,
	ViewText = 2,
	CountCharacters = 3,
	CountWords = 4,
	CountSpaces = 5,
	CountLines = 6,
	FindWord = 7,
	ClearText = 8,
	Exit = 9
};


void F_InputText(std::vector<std::string>& lines)
{
	std::cout << "\n\tВвод текста\n\n" << std::endl;

	std::cout << "\nВведите текст. Для завершения введите END: " << std::endl;
	std::string line;

	std::cin.ignore();

	while (true)
	{
		std::getline(std::cin, line);
		if (line == "END")
		{
			break;
		}
		else
		{
			lines.push_back(line);
		}
	}


}


void F_ViewText(const std::vector<std::string>& lines)
{
	std::cout << "\n\tПоказ текста\n\n" << std::endl;

	int size = lines.size();
	if (size == 0)
	{
		std::cout << "Текст пуст" << std::endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << lines[i] << std::endl;
		}
	}
}


void F_CountCharacters(const std::vector<std::string>& lines)
{
	std::cout << "\n\tПодсчет символов\n\n" << std::endl;
	int sum = 0;
	int size = lines.size();
	if (size == 0)
	{
		std::cout << "Текст пуст" << std::endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			sum = sum + lines[i].length();
		}
		std::cout << "Общее количество символов: " << sum << std::endl;
	}
}


void F_CountWords(const std::vector<std::string>& lines)
{
	std::cout << "\n\tПодсчет слов\n\n" << std::endl;

	char space = ' ';
	bool inWord = false;
	int sum = 0;
	int length = 0;
	int size = lines.size();
	if (size == 0)
	{
		std::cout << "Текст пуст" << std::endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			inWord = false;
			length = lines[i].length();
			for (int j = 0; j < length; j++)
			{
				if (space != lines[i][j] && inWord == false)
				{
					sum++;
					inWord = true;
				}
				else if (space == lines[i][j])
				{
					inWord = false;
				}
			}
		}
		std::cout << "Общее количество слов: " << sum << std::endl;
	}
}


void F_CountSpaces(const std::vector<std::string>& lines)
{
	std::cout << "\n\tПодсчет пробелов\n\n" << std::endl;

	char space = ' ';
	int sum = 0;
	int length = 0;
	int size = lines.size();
	if (size == 0)
	{
		std::cout << "Текст пуст" << std::endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			length = lines[i].length();
			for (int j = 0; j < length; j++)
			{
				if (space == lines[i][j])
				{
					sum++;
				}
			}
		}
		std::cout << "Общее количество пробелов: " << sum << std::endl;
	}

}


void F_CountLines(const std::vector<std::string>& lines)
{
	std::cout << "\n\tПодсчет строк\n\n" << std::endl;
	
	
	int size = lines.size();
	if (size == 0)
	{
		std::cout << "Текст пуст" << std::endl;
	}
	else
	{
		std::cout << "Общее количество строк: " << size << std::endl;
	}
}


void F_FindWord(const std::vector<std::string>& lines)
{
	std::cout << "\n\tПоиск слова\n\n" << std::endl;
	std::string line;
	bool found = false;
	int size = lines.size();
	if (size == 0)
	{
		std::cout << "Текст пуст" << std::endl;
	}
	else
	{
		std::cout << "Введите слово для поиска: ";
		std::cin.ignore();
		std::getline(std::cin, line);
		for (int i = 0; i < size; i++)
		{
			if (lines[i].find(line) != std::string::npos)
			{
				std::cout << "Номер и сама строка: " << i + 1 << " " << lines[i] << std::endl;
				found = true;
			}
			
		}
		if (found == false)
		{
			std::cout << "Слово не найдено" << std::endl;
		}
	}
}


void F_ClearText(std::vector<std::string>& lines)
{
	std::cout << "\n\tОчистка текста\n\n" << std::endl;

	int size = lines.size();
	if (size == 0)
	{
		std::cout << "Текст пуст" << std::endl;
	}
	else
	{
		std::cout << "Вы уверены что хотите очистить текст(y/n)?" << std::endl;
		char choice = ' ';
		std::cin >> choice;
		switch (choice)
		{
		case 'y':
			lines.clear();
			std::cout << "Текст был очищен" << std::endl;
			break;
		case 'n':
			break;
		default:
			std::cout << "Неверный пункт меню" << std::endl;
			break;
		}
	}
}


void F_Menu(std::vector<std::string> &lines)
{
	while (true)
	{
		std::cout << "\n\tТекстовый помощник Plus\n\n" << std::endl;

		std::cout << "\n\tМеню" << std::endl;
		std::cout << "1 - Ввести текст" << std::endl;
		std::cout << "2 - Показать текст" << std::endl;
		std::cout << "3 - Посчитать символы" << std::endl;
		std::cout << "4 - Посчитать слова" << std::endl;
		std::cout << "5 - Посчитать пробелы" << std::endl;
		std::cout << "6 - Посчитать строки" << std::endl;
		std::cout << "7 - Найти слово" << std::endl;
		std::cout << "8 - Очистить текст" << std::endl;
		std::cout << "9 - Выход\n" << std::endl;
		std::cout << "Введите пункт меню: ";
		int count = 0;
		std::cin >> count;
		enum E_Menu choice;
		choice = (enum E_Menu)count;
		switch (choice)
		{
		case InputText:
			F_InputText(lines);
			break;
		case ViewText:
			F_ViewText(lines);
			break;
		case CountCharacters:
			F_CountCharacters(lines);
			break;
		case CountWords:
			F_CountWords(lines);
			break;
		case CountSpaces:
			F_CountSpaces(lines);
			break;
		case CountLines:
			F_CountLines(lines);
			break;
		case FindWord:
			F_FindWord(lines);
			break;
		case ClearText:
			F_ClearText(lines);
			break;
		case Exit:
			std::exit(0);
			break;
		default:
			std::cout << "Неверный пункт" << std::endl;
			break;
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<std::string> lines;

	F_Menu(lines);
}

