#include <iostream>
#include <vector>
#include <Windows.h>


void PrintMap(const std::vector<std::vector<char>>& map)
{
    int size = map.size();
    for (int i = 0; i < size; i++)
    {
               
        int length = map[i].size();
        for (int j = 0; j < length; j++)
        {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


bool IsInside(const std::vector<std::vector<char>>& map, int row, int col)
{
    int size = map.size();
    if (row >= 0 && row < size)
    {
        int length = map[row].size();

        if (col >= 0 && col < length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}


bool IsWall(const std::vector<std::vector<char>>& map, int row, int col)
{
    if (not IsInside(map, row, col))
    {
        std::cout << "\nЭто стена / ход невозможен" << std::endl;
        return true;
    }

    if (map[row][col] == '#')
    {
        std::cout << "\nЭто стена" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}


bool FindPlayer(const std::vector<std::vector<char>>& map, int& playerRow, int& playerCol)
{
    int size = map.size();
    for (int i = 0; i < size; i++)
    {
        int length = map[i].size();
        for (int j = 0; j < length; j++)
        {
            if (map[i][j] == 'P')
            {
                playerRow = i;
                playerCol = j;
                return true;
            }
        }
    }
    return false;
}


bool CanMove(const std::vector<std::vector<char>>& map, int row, int col)
{
    if (IsInside(map, row, col) == false)
    {
        return false;
    }
    if (IsWall(map, row, col) == true)
    {
        return false;
    }
    return true;
}


bool IsExitCell(const std::vector<std::vector<char>>& map, int row, int col)
{
    if (IsInside(map, row, col) == true)
    {
        if (map[row][col] == 'E')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


bool IsMovePlayer(std::vector<std::vector<char>>& map, char command, bool& isWin)
{
    int row = 0;
    int col = 0;
    if (FindPlayer(map, row, col) == true)
    {
        int newRow = row;
        int newCol = col;
        if (command == 'w')
        {
            newRow--;
            if (CanMove(map, newRow, newCol) == true)
            {
                map[row][col] = '.';
                if (IsExitCell(map, newRow, newCol) == true)
                {
                    isWin = true;
                }

                map[newRow][newCol] = 'P';
                return true;
            }
            else
            {
                std::cout << "Ход невозможен" << std::endl;
                return false;
            }
        }
        if (command == 's')
        {
            newRow++;
            if (CanMove(map, newRow, newCol) == true)
            {
                map[row][col] = '.';
                if (IsExitCell(map, newRow, newCol) == true)
                {
                    isWin = true;
                }
                map[newRow][newCol] = 'P';
                return true;
            }
            else
            {
                std::cout << "Ход невозможен" << std::endl;
                return false;
            }
        }
        if (command == 'a')
        {
            newCol--;
            if (CanMove(map, newRow, newCol) == true)
            {
                map[row][col] = '.';
                if (IsExitCell(map, newRow, newCol) == true)
                {
                    isWin = true;
                }
                map[newRow][newCol] = 'P';
                return true;
            }
            else
            {
                std::cout << "Ход невозможен" << std::endl;
                return false;
            }
        }
        if (command == 'd')
        {
            newCol++;
            if (CanMove(map, newRow, newCol) == true)
            {
                map[row][col] = '.';
                if (IsExitCell(map, newRow, newCol) == true)
                {
                    isWin = true;
                }
                map[newRow][newCol] = 'P';
                return true;
            }
            else
            {
                std::cout << "Ход невозможен" << std::endl;
                return false;
            }
        }
        if (command != 'w' && command != 's' && command != 'a' && command != 'd')
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}





int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    

    std::vector<std::vector<char>> map = 
    {
        {'#','#','#','#','#','#','#'},
        {'#','P','.','.','.','.','#'},
        {'#','.','#','#','#','#','#'},
        {'#','.','.','.','#','.','#'},
        {'#','#','#','.','#','E','#'},
        {'#','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#'}
    };

    int row = 0;
    int col = 0;
    char command = ' ';
    char player = 'P';
    bool isPlay = true;
    bool isWin = false;


    std::cout << "\nУправление: " << std::endl;
    std::cout << "w - вверх " << std::endl;
    std::cout << "s - вниз " << std::endl;
    std::cout << "a - влево " << std::endl;
    std::cout << "d - вправо " << std::endl;
    std::cout << "q - выход из игры " << std::endl;


    while (isPlay == true)
    {
        PrintMap(map);
        std::cout << "Введите куда вы хотите походить: ";
        std::cin >> command;
        if (command == 'q')
        {
            isPlay = false;
        }
        IsMovePlayer(map, command, isWin);

        if (isWin == true)
        {
            std::cout << "Вы победили" << std::endl;
            isPlay = false;
            break;
        }
    }
}