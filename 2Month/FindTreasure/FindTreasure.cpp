#include <iostream>
#include <windows.h>
#include <vector>


bool Treasure(std::vector<std::vector<char>>& map, int &rowTreasure, int &colTreasure)
{
    int size = map.size();
    for (int i = 0; i < size; i++)
    {
        int length = map[i].size();
        for (int j = 0; j < length; j++)
        {
            if (map[i][j] == 'T')
            {
                rowTreasure = i;
                colTreasure = j;
                map[i][j] = '.';
                return true;
            }
        }
    }
    return false;
}


void PrintMap(const std::vector <std::vector<char>>& map)
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
        std::cout << "\nЭто стена/ ход невозможен" << std::endl;
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


bool FindPlayer(const std::vector<std::vector<char>>& map, int& rowPlayer, int& colPlayer)
{
    int size = map.size();
    for (int i = 0; i < size; i++)
    {
        int length = map[i].size();
        for (int j = 0; j < length; j++)
        {
            if (map[i][j] == 'P')
            {
                rowPlayer = i;
                colPlayer = j;
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


bool MovePlayer(std::vector<std::vector<char>>& map, char command)
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
        }
        else if (command == 's')
        {
            newRow++;
        }
        else if (command == 'a')
        {
            newCol--;
        }
        else if (command == 'd')
        {
            newCol++;
        }
        else
        {
            std::cout << "Ход невозможен" << std::endl;
            return false;

        }

        if (CanMove(map, newRow, newCol) == false)
        {
            std::cout << "Ход невозможен" << std::endl;
            return false;
        }



        map[row][col] = '.';
        map[newRow][newCol] = 'P';
        return true;
    }
    return false;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    std::vector<std::vector<char>> map =
    {
        {'#','#','#','#','#'},
        {'#','P','.','.','#'},
        {'#','.','.','.','#'},
        {'#','.','.','T','#'},
        {'#','#','#','#','#'}
    };
    bool isPlay = true;
    char command = ' ';
    int treasureRow = 0;
    int treasureCol = 0;

    bool hasTreasure = Treasure(map, treasureRow, treasureCol);

    if (hasTreasure == false)
    {
        std::cout << "Сокровище не найдено" << std::endl; 
        return 0;
    }

    while (isPlay == true)
    {
        PrintMap(map);
        std::cout << "Введите куда вы хотите походить: ";
        std::cin >> command;
        if (command == 'q')
        {
            isPlay = false;
            break;
        }
        MovePlayer(map, command);
        
        int playerRow = 0;
        int playerCol = 0;

        FindPlayer(map, playerRow, playerCol);


        if (playerRow == treasureRow && playerCol == treasureCol)
        {
            PrintMap(map);
            std::cout << "Вы нашли сокровище" << std::endl;
            isPlay = false;
            break;
        }
        

    }
}
