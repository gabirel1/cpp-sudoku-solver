/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main.cpp
*/

#include "main.hpp"

std::vector<std::string> read_and_fill_board(std::string filepath)
{
    std::ifstream file;
    file.open(filepath);
    if (file.is_open() == false) {
        std::cerr << "Please provide a valid file" << std::endl;
        exit(84);
    }

    std::vector<std::string> board;
    std::string line;
    while (std::getline(file, line)) {
        board.push_back(line);
    }
    return board;
}

void print_final_board(std::vector<std::string> board)
{
    for (std::string &mystring : board) {
        int i = 0;
        for (std::string::iterator it=mystring.begin(); it!=mystring.end(); ++it, i++) {
            if (i < 8)
                std::cout << *it << ", ";
            else
                std::cout << *it;
        }
        std::cout << std::endl;
    }
}

bool isPossible(std::vector<std::string> board, int x, int y, char toFind)
{
    for (int i = 0; i < 9; i++) {
        if (board[y][i] == toFind) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (board[i][x] == toFind) {
            return false;
        }
    }

    int x0 = (std::floor(x/3))*3;
    int y0 = (std::floor(y/3))*3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[y0 + i][x0 + j] == toFind) {
                return false;
            }
        }
    }
    return true;
}

int solve_board(sudokuBoard &boardClass)
{
    std::vector<std::string> board = boardClass.getBoard();
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (board[y][x] == '0') {
                for (int i = 1; i < 10; i++) {
                    std::string oldString = board[y];
                    std::string newString = board[y];
                    if (isPossible(board, x, y, (i + '0')) == true) {
                        newString[x] = i + '0';
                        std::replace(board.begin(), board.end(), oldString, newString);
                        boardClass.setBoard(board);
                        if (solve_board(boardClass) == 0)
                            return 0;
                        newString[x] = '0';
                        std::replace(board.begin(), board.end(), oldString, newString);
                        boardClass.setBoard(board);
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}

void solver(const std::string &filepath)
{
    std::vector<std::string> board = read_and_fill_board(filepath);
    sudokuBoard initialBoard(board);
    solve_board(initialBoard);
    sudokuBoard finalBoard(initialBoard.getBoard());
    print_final_board(finalBoard.getBoard());
}

int main(int ac, char *av[])
{
    if (ac <= 1) {
        std::cerr << "Please provide a file containing an unresolved sudoku (you are responsible of the validity of your sudoku map)" << std::endl;
        return 84;
    }
    solver(av[1]);
    return 0;
}