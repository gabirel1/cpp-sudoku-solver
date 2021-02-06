/*
** EPITECH PROJECT, 2021
** sudokuBoard.hpp
** File description:
** sudokuBoard.hpp
*/

#ifndef SUDOKUBOARD_HPP_
#define SUDOKUBOARD_HPP_

#include "main.hpp"

class sudokuBoard
{
    public:
        sudokuBoard(const std::vector<std::string> &board);
        ~sudokuBoard();
        std::vector<std::string> getBoard() const;
        void setBoard(const std::vector<std::string> &board);
    protected:
    private:
        std::vector<std::string> _board;
};

#endif /* !SUDOKUBOARD_HPP_ */
