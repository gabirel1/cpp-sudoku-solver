/*
** EPITECH PROJECT, 2021
** sudokuBoard.cpp
** File description:
** sudokuBoard.cpp
*/

#include "main.hpp"

sudokuBoard::sudokuBoard(const std::vector<std::string> &board) : _board(board)
{
}

sudokuBoard::~sudokuBoard()
{
}

std::vector<std::string> sudokuBoard::getBoard() const
{
    return _board;
}

void sudokuBoard::setBoard(const std::vector<std::string> &board)
{
    _board = board;
}