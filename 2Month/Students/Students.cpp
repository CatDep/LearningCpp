#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>


struct Student
{
    std::string name;
    int age;
    float averageScore;
};


enum E_Menu
{
    AddStudent = 1,
    ViewStudents = 2,
    FindStudent = 3,
    DeleteStudent = 4,
    HighScoreStudents = 5,
    Exit = 6
};


void F_AddStudent(std::vector<Student>& students)
{
    std::cout << "\n\tДобавление студента\n";

    std::cin.ignore();
    int i = students.size();
    students.push_back({});
    std::cout << "\nВведите имя студента :";
    std::getline(std::cin, students[i].name);

    std::cout << "\nВведите возраст студента :";
    std::cin >> students[i].age;

    std::cout << "\nВведите средний бал студента :";
    std::cin >> students[i].averageScore;

}


void F_ViewStudents(const std::vector<Student>& students)
{
    std::cout << "\n\tСписок всех студентов\n";

    if (students.size() > 0)
    {
        for (int i = 0, j = 1; i < students.size(); i++, j++)
        {
            std::cout << j << ". " << students[i].name << " " << students[i].age << " " << students[i].averageScore << std::endl;
        }
    }
    else
    {
        std::cout << "\tСписок пуст\n" << std::endl;
    }
}


void F_FindStudents(const std::vector<Student>& students)
{
    std::cout << "\n\tПоиск студента по имени\n" << std::endl;

    std::string name;

    std::cout << "Введите имя студента: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    int l = 0;
    if (students.size() > 0)
    {
        for (int i = 0, j = 1; i < students.size(); i++, j++)
        {
            if (name == students[i].name)
            {
                std::cout << j << ". " << students[i].name << " " << students[i].age << " " << students[i].averageScore << std::endl;
                l++;
            }
        }
        if (l == 0)
        {
            std::cout << "\nСтудент не найден\n";
        }
    }
    else
    {
        std::cout << "\tСписок пуст\n" << std::endl;
    }
}

void F_DeleteStudent(std::vector<Student>& students)
{
    std::cout << "\n\tУдаление студента\n\n";

    int id;
    int l = 0;
    if (students.size() > 0)
    {
        std::cout << "Введите ID студента которого хотите удалить: ";
        std::cin >> id;
        for (int i = 0, j = 1; i < students.size(); i++, j++)
        {
            if (id == j)
            {
                std::cout << "Вы действительно хотите удалить студента(y/n): ";
                std::cout << j << ". " << students[i].name << " " << students[i].age << " " << students[i].averageScore << std::endl;
                char d;
                std::cin >> d;
                switch (d)
                {
                case ('y'):
                    students.erase(students.begin() + i);
                    std::cout << "Студент удален" << std::endl;
                    break;
                case ('n'):
                    break;
                default:
                    std::cout << "Неверный ввод" << std::endl;
                    break;
                }
                l++;
                break;
            }
        }
        if (l == 0)
        {
            std::cout << "\nСтудент не найден\n";
        }
    }
    else
    {
        std::cout << "\tСписок пуст\n" << std::endl;
    }
}


void F_HighScoreStudents(const std::vector<Student>& students)
{
    std::cout << "\n\tСтудент с лучшим средним баллом\n\n";
    float highscore = 0;
    if (students.size() > 0)
    {
        for (int i = 0, j = 1; i < students.size(); i++, j++)
        {
            if (highscore < students[i].averageScore)
            {
                highscore = students[i].averageScore;
            }
        }
        for (int i = 0, j = 1; i < students.size(); i++, j++)
        {
            if (highscore == students[i].averageScore)
            {
                std::cout << j << ". " << students[i].name << " " << students[i].age << " " << students[i].averageScore << std::endl;
            }
        }
    }
    else
    {
        std::cout << "\tСписок пуст\n" << std::endl;
    }
}


void F_Menu(std::vector<Student> &students)
{
    while (true)
    {
        std::cout << "\n\tГлавное меню\n" << std::endl;

        std::cout << "1 - Добавить студента" << std::endl;
        std::cout << "2 - Показать всех студентов" << std::endl;
        std::cout << "3 - Найти студента" << std::endl;
        std::cout << "4 - Удалить студента" << std::endl;
        std::cout << "5 - Лучший студент" << std::endl;
        std::cout << "6 - Выход\n" << std::endl;

        std::cout << "Ожидаем ввода: ";
        int count;
        std::cin >> count;


        switch (count)
        {
        case AddStudent:
            F_AddStudent(students);
            break;
        case ViewStudents:
            F_ViewStudents(students);
            break;
        case FindStudent:
            F_FindStudents(students);
            break;
        case DeleteStudent:
            F_DeleteStudent(students);
            break;
        case HighScoreStudents:
            F_HighScoreStudents(students);
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

    std::vector<Student> students;

    F_Menu(students);

    return 0;
}

