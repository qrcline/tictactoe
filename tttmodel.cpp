#include "tttmodel.h"
#include <iostream>

TTTModel::TTTModel()
{

}

void TTTModel::reset()
{
    std::cout << "reset called" << std::endl;
}

void TTTModel::put(int row, int col)
{
    std::cout << "put called with row " << row << " and col " << col << std::endl;
}

QString TTTModel::getCurrentBoard() // something like "---XOXX--"
{
    return "-X-OX-XO-";
}

QString TTTModel::getWhosTurn() // "X" or "O" or if somebody already won, return anything
{
    return "O";
}

bool TTTModel::hasSomeoneWon() // return if somebody has won
{
    return false;
}

QString TTTModel::whosWinner() // return "X" or "O" if there's any winner. return anything if there's no winner yet
{
    return "";
}























