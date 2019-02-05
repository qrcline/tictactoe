#ifndef TTTMODEL_H
#define TTTMODEL_H

#include <QObject>

class TTTModel
{
public:
    TTTModel();

    void reset();
    void put(int row, int col);
    QString getCurrentBoard(); // "---XOXX--"
    QString getWhosTurn(); // "X" or "O" or if somebody already won, return anything
    bool hasSomeoneWon(); // return if somebody has won
    QString whosWinner(); // return "X" or "O" if there's any winner. return anything if there's no winner yet
    void nextPlayer();

private:
    // my own data structure and boolean variable and checking logics if the game has ended?
    // finish implementation of the functions above
    QString boardStatus;
    QString player="X";
    int playCount=1;
    static const int ASIZE=3;
    QChar array[ASIZE][ASIZE]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    QString arrayToString(QChar array[], int lenght);
    QString arrayToString(char array[][ASIZE]);
};

#endif // TTTMODEL_H
