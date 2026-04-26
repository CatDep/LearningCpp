#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>


void PrintBoard(const std::vector<std::string>& board)
{
    int size = board.size();
    std::cout << " " << 1 << " " << 2 << " " << 3 << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1;
        int length = board[i].length();
        for (int j = 0; j < length; j++)
        {
            std::cout << board[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}


bool MakeMove(std::vector<std::string>& board, char player)
{
    int i = 0;
    int j = 0;

    std::cout << "\nВведите номер столбца куда хотите походить: ";
    std::cin >> j;
    std::cout << "\nВведите номер строки куда хотите походить: ";
    std::cin >> i;

        if (i < 1 || i > 3)
        {
            std::cout << "Неправельные кординаты" << std::endl;
            return false;
        }
        if (j < 1 || j > 3)
        {
            std::cout << "Неправельные кординаты" << std::endl;
            return false;
        }
        
  
    i = i - 1;
    j = j - 1;

    if (board[i][j] != '.')
    {

        std::cout << "\nКлетка занята" << std::endl;
        return false;
    }
    else if (board[i][j] == '.')
    {

        std::cout << "Вы походили" << std::endl;
        board[i][j] = player;
        return true;
    }
    return false;
}


bool CheckWin(const std::vector<std::string>& board, char player)
{
    int size = board.size();
    for (int i = 0; i < size; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
    {
        return true;
    }
    return false;
}


bool IsDraw(const std::vector<std::string>& board)
{
    int size = board.size();
    for (int i = 0; i < size; i++)
    {
        int length = board[i].length();
        for (int j = 0; j < length; j++)
        {
            if (board[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char player = 'X';
    std::vector<std::string> board = {
        "...",
        "...",
        "..."
    };

    bool isPlay = true;
    bool isWin = false;
    bool isDraw = false;
    while (isPlay == true)
    {
        PrintBoard(board);
        bool isMove = false;

        while (isMove == false)
        {
            isMove = MakeMove(board, player);
        }

        isWin = CheckWin(board, player);
        if (isWin == true)
        {
            std::cout << "Победил игрок " << player << std::endl;
            isPlay = false;
            PrintBoard(board);
            break;
        }
        isDraw = IsDraw(board);
        if (isDraw == true)
        {
            std::cout << "Ничья" << std::endl;
            isPlay = false;
            PrintBoard(board);
            break;
        }

        if (player == 'X')
        {
            player = 'O';
        }

        else
        {
            player = 'X';
        }
    }
}