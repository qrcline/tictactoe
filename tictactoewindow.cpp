#include "tictactoewindow.h"
#include "ui_tictactoewindow.h"

TicTacToeWindow::TicTacToeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToeWindow),
    tttModel(new TTTModel)
{
    ui->setupUi(this);
    updateScreen();
}

TicTacToeWindow::~TicTacToeWindow()
{
    delete ui;
}

void TicTacToeWindow::updateScreen()
{
    //QString getCurrentBoard(); // "---XOXX--"
    //QString getWhosTurn(); // "X" or "O" or if somebody already won, return anything
    //bool hasSomeoneWon(); // return if somebody has won
    //QString whosWinner(); // return "X" or "O" if there's any winner. return anything if there's no winner yet

    QString cur = tttModel->getCurrentBoard();

    ui->board00->setText("" + cur[0]);
    ui->board01->setText("" + cur[1]);
    ui->board02->setText("" + cur[2]);
    ui->board10->setText("" + cur[3]);
    ui->board11->setText("" + cur[4]);
    ui->board12->setText("" + cur[5]);
    ui->board20->setText("" + cur[6]);
    ui->board21->setText("" + cur[7]);
    ui->board22->setText("" + cur[8]);

    ui->boardLabel->setText(cur.left(3) + '\n' + cur.mid(3, 3) + '\n' + cur.right(3));

    // if somebody has won?
    if (tttModel->hasSomeoneWon()) {
        QString msg = tttModel->whosWinner() + " has won!";
        ui->IBStatusLabel->setText(msg);
        ui->TBStatusLabel->setText(msg);
    }
    else {
        // no winner yet
        QString msg = tttModel->getWhosTurn() + "'s turn";
        ui->IBStatusLabel->setText(msg);
        ui->TBStatusLabel->setText(msg);
    }

}

void TicTacToeWindow::on_board00_clicked()
{
    tttModel->put(0, 0);
    updateScreen();
}

void TicTacToeWindow::on_board01_clicked()
{
    tttModel->put(0, 1);
    updateScreen();
}

void TicTacToeWindow::on_board02_clicked()
{
    tttModel->put(0, 2);
    updateScreen();
}

void TicTacToeWindow::on_board10_clicked()
{
    tttModel->put(1, 0);
    updateScreen();
}

void TicTacToeWindow::on_board11_clicked()
{
    tttModel->put(1, 1);
    updateScreen();
}

void TicTacToeWindow::on_board12_clicked()
{
    tttModel->put(1, 2);
    updateScreen();
}

void TicTacToeWindow::on_board20_clicked()
{
    tttModel->put(2, 0);
    updateScreen();
}

void TicTacToeWindow::on_board21_clicked()
{
    tttModel->put(2, 1);
    updateScreen();
}

void TicTacToeWindow::on_board22_clicked()
{
    tttModel->put(2, 2);
    updateScreen();
}

void TicTacToeWindow::on_pushButton_clicked()
{
    int col = ui->colInput->text().toInt();
    int row = ui->rowInput->text().toInt();
    updateScreen();
}

void TicTacToeWindow::on_resetButton_clicked()
{
    tttModel->reset();
    updateScreen();

    // do some cleanup work for your UI
}















