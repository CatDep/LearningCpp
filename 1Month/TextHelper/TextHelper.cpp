#include <iostream>
#include <string>
#include <Windows.h>


enum E_Menu
{
    InputText = 1,
    ViewText = 2,
    ViewLengthText = 3,
    SpaceCount = 4,
    SimbolsCountNoSpace = 5,
    ClearText = 6,
    Exit = 7
};


void F_InputText(std::string& text)
{
    int length = text.length();
    std::cout << "\n\tДобавить текст\n\n" << std::endl;
    if (length == 0)
    {
        std::cout << "Введите свой текст ниже" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, text);
    }
    else if (length != 0)
    {
        std::cout << "!!!В программе уже есть текст!!!" << std::endl;
        std::cout << text << std::endl;
        std::cout << "\n1 - Вы хотите дописать свой текст" << std::endl;
        std::cout << "2 - Продолжить с текущим текстом\n" << std::endl;
        std::cout << "Введите пункт меню: ";
        int count = 0;
        std::string add;
        std::cin >> count;
        switch (count)
        {
        case 1:
            std::cout << "Допишите текст ниже: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, add);
            text = text + " " + add;
            break;
        case 2:
            break;
        default:
            std::cout << "Неверный пункт меню" << std::endl;
            break;
        }
    }
}


void F_ViewText(const std::string& text)
{
    std::cout << "\n\tВывести текст\n\n" << std::endl;

    std::cout << text << std::endl;
}


void F_ViewLengthText(const std::string& text)
{
    std::cout << "\n\tДлина текста\n\n" << std::endl;

    int length = text.length();
    if (length != 0)
    {
        std::cout << "Длина текста состовляет: " << length << " символов" << std::endl;
    }
    else if (length == 0)
    {
        std::cout << "Вы ещё не ввели никого текста!" << std::endl;
    }
}


void F_SpaceCount(const std::string& text)
{
    std::cout << "\n\tКоличество пробелов в тексте\n\n" << std::endl;

    int length = 0;
    length = text.length();
    int count = 0;
    char space = ' ';

    if (length != 0)
    {
        for (int i = 0; i < length; i++)
        {
            if (space == text[i])
            {
                count++;
            }
        }
        std::cout << "Количество пробелов в тексте: " << count << std::endl;
    }
    else if (length == 0)
    {
        std::cout << "Вы ещё не ввели никого текста!" << std::endl;
    }
}


void F_SimbolsCountNoSpace(const std::string& text)
{
    std::cout << "\n\tКоличество символов без пробелов\n\n" << std::endl;

    int length = 0;
    length = text.length();
    int count = 0;
    int simbolscount = 0;
    char space = ' ';

    if (length != 0)
    {
        for (int i = 0; i < length; i++)
        {
            if (space == text[i])
            {
                count++;
            }
        }
        simbolscount = length - count;
        std::cout << "Количество символов в тексте без пробелов: " << simbolscount << std::endl;
    }
    else if (length == 0)
    {
        std::cout << "Вы ещё не ввели никого текста!" << std::endl;
    }
}


void F_ClearText(std::string& text)
{
    std::cout << "\n\tОчистка текста\n\n" << std::endl;

    std::cout << "Вы уверены что хотите очистеть текст(y/n)?" << std::endl;
    char choice = ' ';
    std::cin >> choice;
    switch (choice)
    {
    case 'y':
        text.clear();
        std::cout << "Текст был очищен" << std::endl;
        break;
    case 'n':
        break;
    default:
        std::cout << "Неверный пункт меню" << std::endl;
        break;
    }
}


void F_Menu(std::string &text)
{
    while (true)
    {
        std::cout << "\n\tВас приветствует текстовый помощник\n\n" << std::endl;

        std::cout << "\n1 - Ввести текст" << std::endl;
        std::cout << "2 - Показать текущей текст" << std::endl;
        std::cout << "3 - Показать длину текста" << std::endl;
        std::cout << "4 - Посчитать количество пробелов" << std::endl;
        std::cout << "5 - Посчитать количество символов без пробелов" << std::endl;
        std::cout << "6 - Очистеть текст" << std::endl;
        std::cout << "7 - Выход\n" << std::endl;
        std::cout << "Введите пункт меню: ";
        int count = 0;
        std::cin >> count;
        enum E_Menu choice;
        choice = (enum E_Menu)count;
        switch (choice)
        {
        case InputText: 
            F_InputText(text);
            break; 
        case ViewText:
            F_ViewText(text);  
            break;
        case ViewLengthText:
            F_ViewLengthText(text);
            break;
        case SpaceCount:
            F_SpaceCount(text);
            break;
        case SimbolsCountNoSpace:
            F_SimbolsCountNoSpace(text);
            break;
        case ClearText:
            F_ClearText(text);
            break;
        case Exit:
            std::exit(0);
            break;
        default:
            std::cout << "Неверный пункт меню" << std::endl;
            break;
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string text;

    F_Menu(text);
}

