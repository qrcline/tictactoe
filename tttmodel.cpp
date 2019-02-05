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
    array[row][col]= getWhosTurn().at(0);

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

QString TTTModel::getWhosTurn() // "X" or "O" or if somebody already won, return anything
{
   if(player=="X")
       player="O";
   else
       player="X";
   return player;
}

bool TTTModel::hasSomeoneWon() // return if somebody has won
{


    QChar tempRowMatch[ASIZE];
    QChar tempColMatch[ASIZE];
    for(int i=0; i<ASIZE; i++)
    {
        for (int j=0;j<ASIZE;j++)
        {
            tempRowMatch[j]=array[i][j];
            tempColMatch[j]=array[j][i];
            std::cout<<"Execution"<<j<<std::endl;
        }


          std::cout<<arrayToString(tempColMatch,ASIZE).toStdString()<<std::endl;


        if(arrayToString(tempColMatch,ASIZE)=="XXX" || arrayToString(tempColMatch,ASIZE)=="OOO")
        {
             return true;
        }
        if(tempRowMatch[0]==tempRowMatch[1]==tempColMatch[2])
        {
             return true;
        }

    }
    std::cout<<"No Winner"<<std::endl;
        return false;
}

QString TTTModel::arrayToString(QChar array[],int lenght)
{
    QString tempString="";
    for(int i=0;i<lenght;i++)
    {
         tempString=array[i];
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
    return "";

}

























