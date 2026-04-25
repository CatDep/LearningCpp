#include <iostream>
#include <Windows.h>

enum E_Menu
{
    Addition = 1,
    Subtraction = 2,
    Multiplication = 3,
    Division = 4,
    Exit = 5
};

void F_Addition()
{
    std::cout << "\n\tСложение\n\n" << std::endl;

    int a;
    int b;

    std::cout << "Введите первое число: ";
    std::cin >> a;

    std::cout << "Введите второе число: ";
    std::cin >> b;

    std::cout << "\n\nСумма: " << a + b << std::endl;

}


void F_Subtraction()
{
    std::cout << "\n\tВычитание\n\n" << std::endl;

    int a;
    int b;

    std::cout << "Введите первое число: ";
    std::cin >> a;

    std::cout << "Введите второе число: ";
    std::cin >> b;

    std::cout << "\n\nРазность: " << a - b << std::endl;

}


void F_Multiplication()
{
    std::cout << "\n\tУмножение\n\n" << std::endl;

    int a;
    int b;

    std::cout << "Введите первое число: ";
    std::cin >> a;

    std::cout << "Введите второе число: ";
    std::cin >> b;

    std::cout << "\n\nПроизведение: " << a * b << std::endl;

}


void F_Division()
{
    std::cout << "\n\tДеление\n\n" << std::endl;

    float a;
    float b;

    std::cout << "Введите первое число: ";
    std::cin >> a;

    std::cout << "Введите второе число: ";
    std::cin >> b;
    while (b == 0)
    {
        std::cout << "На ноль делить нельзя" << std::endl;
        std::cout << "Введите второе число: ";
        std::cin >> b;
    }
    std::cout << "\n\nЧастное: " << a / b << std::endl;
}

void F_Menu()
{
    while (true)
    {
        std::cout << "\n\tКалькулятор\n\n" << std::endl;

        std::cout << "1 - Сложение" << std::endl;
        std::cout << "2 - Вычитание" << std::endl;
        std::cout << "3 - Умножение" << std::endl;
        std::cout << "4 - Деление" << std::endl;
        std::cout << "5 - Выход\n" << std::endl;
        std::cout << "\nВведите пункт меню: ";
        int count;
        enum E_Menu choice;
        std::cin >> count;
        choice = (enum E_Menu)count;
        switch (choice)
        {
        case Addition:
            F_Addition();
            break;
        case Subtraction:
            F_Subtraction();
            break;
        case Multiplication:
            F_Multiplication();
            break;
        case Division:
            F_Division();
            break;
        case Exit:
            std::exit(0);
            break;
        default:
            std::cout << "\nНеверный ввод\n" << std::endl;
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
