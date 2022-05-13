#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <Qt>
#include <war.h>
#include <draw.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_game_clicked()
{
    QApplication::quit();
}

void MainWindow::on_info_game_clicked()
{
    QMessageBox box;
    box.setWindowTitle("Information");
    box.setText("Морской бой игра на двоих пользователей\n"
                "1. Введите имена пользователей.\n"
                "2. Расставьте по-очереди ваши корабли.\n"
                "3. Далее по-очереди нажимайте по клеткам противника и уничтожайте его корабли.\n"
                "\nПобедит сильнейший!");
    box.exec();
}

void MainWindow::on_start_game_clicked()
{
    newGame = new Autorize;
   // newGame->setModal(true);
    newGame->show();
}

void MainWindow::on_last_game_clicked()
{
    Draw *dr = new Draw;
    dr->show();
}
