#include "game.h"
#include "ui_game.h"
#include <Qt>
#include <QPainter>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QMessageBox>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::CustomizeWindowHint);
    ui->pushButton_6->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_7->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->comboBox->setFocusPolicy(Qt::NoFocus);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_4->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_5->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_6->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(10);
    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            ui->tableWidget->setItem(i,j,new QTableWidgetItem());
            ui->tableWidget->item(i,j)->setTextAlignment(4);
        }
        ui->tableWidget->setRowHeight(i,50);
        ui->tableWidget->setColumnWidth(i,50);
    }
    newField();
    /*for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            gamePers[i][j] = 0;
        }
    }
    for(int i = 0; i < 10; i += 2){
        for(int j = 0; j < 10; j ++){
            if(boat<=4){
                gamePers[i][j] = boat;
                j++;
                boat++;
                if(boat == 5) break;
            }else if(boat>4 && boat <= 7){
                gamePers[i][j] = boat;
                gamePers[i][j+1] = boat;
                j+=2;
                boat++;
                if(boat == 8) break;
            }else if(boat > 7 && boat <= 9){
                gamePers[i][j] = boat;
                gamePers[i][j+1] = boat;
                gamePers[i][j+2] = boat;
                j+=3;
                boat++;
                if(boat == 10) break;
            }else if(boat == 10){
                gamePers[i][j] = boat;
                gamePers[i][j+1] = boat;
                gamePers[i][j+2] = boat;
                gamePers[i][j+3] = boat;
                boat = 11;
            }
        }
    }*/
    update();
}

Game::~Game()
{
    delete ui;
}

bool Game::checkForField()
{
    for(int i = 0; i < 10; i++){
        for(int l = 0; l < 10; l ++){
            if(l == i) continue;
            if(boat[i].checkBoatPos(boat[l].pos)){

                return false;
            }
        }
    }
    for(int i = 0; i < 10; i ++){
        for(int l = boat[i].pos[0].getColumn() - 1; l <= boat[i].pos[boat[i].pos.size()-1].getColumn()+1 ;l++ ){
            for(int j = 0; j < 10; j++){
                if(j == i) continue;
                if((boat[j].checkPos(boat[i].pos[0].getRow()-1,l)) || (boat[j].checkPos(boat[i].pos[0].getRow()+1,l)) || (boat[j].checkPos(boat[i].pos[0].getRow(),boat[i].pos[0].getColumn()-1))
                        || (boat[j].checkPos(boat[i].pos[boat[i].size-1].getRow(),boat[i].pos[boat[i].size-1].getColumn()+1))){

                        return false;

                }
            }
        }
    }
    return true;
}

void Game::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Up){
        on_pushButton_clicked();
    }else if(e->key() == Qt::Key_Down){
        on_pushButton_3_clicked();
    }else if(e->key() == Qt::Key_Right){
        on_pushButton_4_clicked();
    }else if(e->key() == Qt::Key_Left){
        on_pushButton_2_clicked();
    }else if(e->key() == Qt::Key_Tab){
        on_pushButton_5_clicked();
    }
}

void Game::on_pushButton_clicked()
{
    if(ui->comboBox->currentText() == "Не выбран корабль"){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Для начала выберите корабль.");
        box.exec();
        return;
    }
   /* if(ui->comboBox->currentText() == "Линкор №1"){
        for(int i = 0 ; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                if(gamePers[i][j] == 10 && (i-1) >= 0){
                    gamePers[i-1][j] = 10;
                    gamePers[i][j] = 0;
                }
            }
        }
    }
    update(); */
    boat[ui->comboBox->currentIndex()-1].upBoat();
    update();
}

void Game::on_pushButton_3_clicked()
{
    if(ui->comboBox->currentText() == "Не выбран корабль"){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Для начала выберите корабль.");
        box.exec();
        return;
    }
    /*if(ui->comboBox->currentText() == "Линкор №1"){
        for(int i = 9 ; i >= 0; --i){
            for(int j = 9; j >= 0; --j){
                if(gamePers[i][j] == 10 && (i+1) < 10 && count < 4){
                    gamePers[i+1][j] = 10;
                    gamePers[i][j] = 0;
                    count++;
                }
            }
        }
    }
    count = 0;
    update();*/
    boat[ui->comboBox->currentIndex()-1].downBoat();
    update();
}

void Game::on_pushButton_4_clicked()
{
    if(ui->comboBox->currentText() == "Не выбран корабль"){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Для начала выберите корабль.");
        box.exec();
        return;
    }
    /*if(ui->comboBox->currentText() == "Линкор №1"){
        for(int i = 9 ; i >= 10; --i){
            for(int j = 9; j >= 0; --j){
                if(gamePers[i][j] == 10){
                    if(j+4 >= 13){
                        return;
                    }
                    gamePers[i][j+1] = 10;
                    gamePers[i][j] = 0;

                }
            }
        }
    }
    update();*/
    boat[ui->comboBox->currentIndex()-1].rightBoat();
    update();
}

void Game::on_pushButton_2_clicked()
{
    if(ui->comboBox->currentText() == "Не выбран корабль"){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Для начала выберите корабль.");
        box.exec();
        return;
    }
    /*if(ui->comboBox->currentText() == "Линкор №1"){
        for(int i = 0 ; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                if(gamePers[i][j] == 10){
                    if(j-4 <= -4){
                        return;
                    }
                    gamePers[i][j-1] = 10;
                    gamePers[i][j] = 0;
                }
            }
        }
    }
    update();*/
    boat[ui->comboBox->currentIndex()-1].leftBoat();
    update();
}

void Game::update()
{

    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            ui->tableWidget->item(i,j)->setBackground(Qt::white);
            gamePers[i][j] = 0;
        }
    }
    for(int i = 0; i < 10; i++){
        brush.setTextureImage(QImage("D:\\sea_battle\\sea_battle\\kv.png"));
        for(int l = 0; l < boat[i].size-1; l++){
            ui->tableWidget->item(boat[i].pos[l].getRow(),boat[i].pos[l].getColumn())->setBackground(brush);
            gamePers[boat[i].pos[l].getRow()][boat[i].pos[l].getColumn()] = boat[i].numberOfBoat;
        }
        if(boat[i].turn){
            brush.setTextureImage(QImage("D:\\sea_battle\\sea_battle\\upTr.png"));
            ui->tableWidget->item(boat[i].pos[boat[i].size-1].getRow(),boat[i].pos[boat[i].size-1].getColumn())->setBackground(brush);
        }else{
            brush.setTextureImage(QImage("D:\\sea_battle\\sea_battle\\rgTr.png"));
            ui->tableWidget->item(boat[i].pos[boat[i].size-1].getRow(),boat[i].pos[boat[i].size-1].getColumn())->setBackground(brush);
        }
        gamePers[boat[i].pos[boat[i].size-1].getRow()][boat[i].pos[boat[i].size-1].getColumn()] = boat[i].numberOfBoat;
    }

    /*for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            ui->tableWidget->item(i,j)->setBackground(Qt::white);
            if(gamePers[i][j]!=0)
            ui->tableWidget->item(i,j)->setBackground(Qt::blue);
        }
    }*/
}

void Game::newField()
{
    for(int i = 0; i < 10; i ++){
            for(int j = 0; j < 10; j ++){
                gamePers[i][j] = 0;
            }
        }
    gamePers[1][1] = 1;
    boat[0] = Boat(1,1);
    boat[0].addPos(1,1);
    gamePers[1][3] = 2;
    boat[1] = Boat(1,2);
    boat[1].addPos(1,3);
    gamePers[1][5] = 3;
    boat[2] = Boat(1,3);
    boat[2].addPos(1,5);
    gamePers[1][7] = 4;
    boat[3] = Boat(1,4);
    boat[3].addPos(1,7);

    gamePers[3][0] = 8;
    gamePers[3][1] = 8;
    gamePers[3][2] = 8;
    boat[7] = Boat(3,8);
    boat[7].addPos(3,0);
    boat[7].addPos(3,1);
    boat[7].addPos(3,2);
    gamePers[3][4] = 9;
    gamePers[3][5] = 9;
    gamePers[3][6] = 9;
    boat[8] = Boat(3,9);
    boat[8].addPos(3,4);
    boat[8].addPos(3,5);
    boat[8].addPos(3,6);

    gamePers[5][1] = 5;
    gamePers[5][2] = 5;
    boat[4] = Boat(2,5);
    boat[4].addPos(5,1);
    boat[4].addPos(5,2);
    gamePers[5][4] = 6;
    gamePers[5][5] = 6;
    boat[5] = Boat(2,6);
    boat[5].addPos(5,4);
    boat[5].addPos(5,5);
    gamePers[5][7] = 7;
    gamePers[5][8] = 7;
    boat[6] = Boat(2,7);
    boat[6].addPos(5,7);
    boat[6].addPos(5,8);

    gamePers[7][2] = 10;
    gamePers[7][3] = 10;
    gamePers[7][4] = 10;
    gamePers[7][5] = 10;
    boat[9] = Boat(4,10);
    boat[9].addPos(7,2);
    boat[9].addPos(7,3);
    boat[9].addPos(7,4);
    boat[9].addPos(7,5);

}


void Game::on_pushButton_5_clicked()
{
    if(ui->comboBox->currentText() == "Не выбран корабль"){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Для начала выберите корабль.");
        box.exec();
        return;
    }
    boat[ui->comboBox->currentIndex()-1].reverseBoat();
    update();
}

bool Game::on_pushButton_6_clicked()
{
    for(int i = 0; i < 10; i++){
        for(int l = 0; l < 10; l ++){
            if(l == i) continue;
            if(boat[i].checkBoatPos(boat[l].pos)){
                QMessageBox box;
                box.setWindowTitle("Ошибка");
                box.setText("Корабль стоит на корабле.");
                box.exec();
                return false;
            }
        }
    }
    for(int i = 0; i < 10; i ++){
        for(int l = boat[i].pos[0].getColumn() - 1; l <= boat[i].pos[boat[i].pos.size()-1].getColumn()+1 ;l++ ){
            for(int j = 0; j < 10; j++){
                if(j == i) continue;
                if((boat[j].checkPos(boat[i].pos[0].getRow()-1,l)) || (boat[j].checkPos(boat[i].pos[0].getRow()+1,l)) || (boat[j].checkPos(boat[i].pos[0].getRow(),boat[i].pos[0].getColumn()-1))
                        || (boat[j].checkPos(boat[i].pos[boat[i].size-1].getRow(),boat[i].pos[boat[i].size-1].getColumn()+1))){
                        QMessageBox box;
                        box.setWindowTitle("Ошибка");
                        box.setText("Клетки рядом с кораблем заняты.");
                        box.exec();
                        return false;

                }
            }
        }
    }
    this->close();
    return true;
}

void Game::on_pushButton_7_clicked()
{
    this->close();
}
