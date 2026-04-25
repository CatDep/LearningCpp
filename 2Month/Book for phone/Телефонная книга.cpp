#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

struct Contact
{
    std::string name;
    std::string phone;
};


enum eMenu
{
    AddContact = 1,
    ViewContacts = 2,
    FindContact = 3,
    DeleteContact = 4,
    Exit = 5
};

void F_AddContact(std::vector<Contact>& contacts)
{
    std::cout << "\n\tДобавление контакта\n";

    std::cin.ignore();
    int i = contacts.size();
    contacts.push_back({});
    std::cout << "\nВведите имя контакта: ";
    std::getline(std::cin, contacts[i].name);

    std::cout << "Введите номер контакта: ";
    std::getline(std::cin, contacts[i].phone);
}

void F_ViewContacts(const std::vector<Contact>& contacts)
{
    std::cout << "\n\tСписок контактов\n" << std::endl;

    if (contacts.size() > 0)
    {
        for (int i = 0, j = 1; i < contacts.size(); i++, j++)
        {
            std::cout << j << ". " << contacts[i].name << " " << contacts[i].phone << std::endl;
        }
    }
    else
        std::cout << "\tСписок пуст\n" << std::endl;

}

void F_FindContacts(const std::vector<Contact>& contacts)
{
    std::cout << "\n\tПоиск контакта по имени\n" << std::endl;
    std::string name;
    std::cout << "Введите имя контакта: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    int l = 0;
    if (contacts.size() > 0)
    {
        for (int i = 0, j = 1; i < contacts.size(); i++, j++)
        {
            if (name == contacts[i].name)
            {
                std::cout << j << ". " << contacts[i].name << " " << contacts[i].phone << std::endl;
                l++;
            }

        }
        if (l == 0)
        {
            std::cout << "\nКонтакт не найден\n";
        }
    }
    else
        std::cout << "\tСписок пуст\n" << std::endl;

}

void F_DeleteContact(std::vector<Contact>& contacts)
{
    std::cout << "\n\tУдаление контакта\n\n";


    int l;
    int a = 0;
    if (contacts.size() > 0)
    {
        std::cout << "Введите ID контакта который хотите удалить: ";
        std::cin >> l;
        for (int i = 0, j = 1; i < contacts.size(); i++, j++)
        {

            if (l == j)
            {
                std::cout << "Вы действительно хотите удалить контакт(y/n): ";
                std::cout << j << ". " << contacts[i].name << " " << contacts[i].phone << std::endl;
                char d;
                std::cin >> d;
                switch (d)
                {
                case ('y'):
                    contacts.erase(contacts.begin() + i);
                    std::cout << "Контакт удален" << std::endl;
                    break;
                case ('n'):
                    break;
                default:
                    std::cout << "Неверный ввод" << std::endl;
                    break;
                }
                a++;
            }

        }
        if (a == 0)
        {
            std::cout << "\nКонтакт не найден\n";
        }
    }
    else
        std::cout << "\n\tСписок пуст\n" << std::endl;

}


void f_Menu(std::vector<Contact>& contacts)
{
    while (true)
    {

        std::cout << "\n1 - Добавление контакта" << std::endl;
        std::cout << "2 - Показать все контакты" << std::endl;
        std::cout << "3 - Найти контакт" << std::endl;
        std::cout << "4 - Удалить контакт" << std::endl;
        std::cout << "5 - Выход\n" << std::endl;

        std::cout << "Ожидаем ввода: ";
        int count;
        std::cin >> count;

        switch (count)
        {
        case AddContact:
            F_AddContact(contacts);
            break;
        case ViewContacts:
            F_ViewContacts(contacts);
            break;
        case FindContact:
            F_FindContacts(contacts);
            break;
        case DeleteContact:
            F_DeleteContact(contacts);
            break;
        case Exit:
            break;
        default:
            std::cout << "Неверный ввод, попробуйте ещё раз" << std::endl;
            break;
        }
        if (count == Exit)
        {
            break;
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Contact> contacts;



    f_Menu(contacts);



    return 0;
}


