#include "tttmodel.h"
#include <iostream>

TTTModel::TTTModel()
{

}

void TTTModel::reset()
{
   for(int i=0; i<ASIZE; i++)
   {
       for (int j=0;j<ASIZE;j++)
       {
           array[i][j]='-';
       }
   }
}

void TTTModel::put(int row, int col)
{

    if(!hasSomeoneWon() &&row<ASIZE&&row>=0&&col<ASIZE&&col>=0&&array[row][col]=="-")
    {
        array[row][col]= getWhosTurn().at(0);
        nextPlayer();
    }

}

QString TTTModel::getCurrentBoard() // something like "---XOXX--"
{
    QString tempString="";
    for(int i=0; i<ASIZE; i++)
    {
        for (int j=0;j<ASIZE;j++)
        {
           tempString+=array[i][j];
        }
    }
    getWhosTurn();
    return tempString;

}

void TTTModel::nextPlayer()
{
    player="O";
    if(playCount%2==0)
        player="X";
    playCount++;
    std::cout<<"Current player: "<<player.toStdString()<<std::endl;
}

QString TTTModel::getWhosTurn() // "X" or "O" or if somebody already won, return anything
{
   if(hasSomeoneWon())
        return "W";
   return player;
}

bool TTTModel::hasSomeoneWon() // return if somebody has won
{


    QChar tempRowMatch[ASIZE];
    QChar tempColMatch[ASIZE];
    QChar tempCrossLeft[ASIZE];
    QChar tempCrossRight[ASIZE];
    for(int i=0; i<ASIZE; i++)
    {
        for (int j=0;j<ASIZE;j++)
        {
            tempRowMatch[j]=array[i][j];
            tempColMatch[j]=array[j][i];
            std::cout<<"Execution"<<j<<std::endl;
        }

        tempCrossLeft[i]=array[i][i];
         tempCrossRight[i]=array[ASIZE-1-i][i];
     //std::cout<<arrayToString(tempColMatch,ASIZE).toStdString()<<std::endl;
        if(arrayToString(tempColMatch,ASIZE)=="XXX" || arrayToString(tempColMatch,ASIZE)=="OOO")
             return true;
        if(arrayToString(tempRowMatch,ASIZE)=="XXX" || arrayToString(tempRowMatch,ASIZE)=="OOO")
             return true;
        if(arrayToString(tempCrossLeft,ASIZE)=="XXX" || arrayToString(tempCrossLeft,ASIZE)=="OOO")
             return true;
        if(arrayToString(tempCrossRight,ASIZE)=="XXX" || arrayToString(tempCrossRight,ASIZE)=="OOO")
             return true;
    }
    std::cout<<"No Winner"<<std::endl;
        return false;
}

QString TTTModel::arrayToString(QChar array[],int lenght)
{
    QString tempString="";
    for(int i=0;i<lenght;i++)
    {
         tempString= tempString+array[i];
    }
    return tempString;
}
QString TTTModel::arrayToString(char array[][ASIZE])
{
    QString tempString="";
    for(int i=0; i<ASIZE; i++)
    {
        for (int j=0;j<ASIZE;j++)
        {
           tempString= tempString+ array[i][j];
        }
    }
    return tempString;
}


QString TTTModel::whosWinner() // return "X" or "O" if there's any winner. return anything if there's no winner yet
{
    QString playerTemp=player;
    if(hasSomeoneWon())
    {
        if(playerTemp=="X")
            playerTemp="O";
        else
            playerTemp="X";

        return playerTemp;
    }
    return "N";

}

























