#include "war.h"
#include "ui_war.h"
#include <QMessageBox>
#include <boat.h>
#include <QBrush>
#include <mainwindow.h>
#include <QFontDialog>
#include <QFont>
#include <draw.h>

War::War(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::War)
{
    ui->setupUi(this);
    brush.setTextureImage(QImage("D:\\sea_battle\\sea_battle\\krest.png"));
    ui->label_3->setVisible(false);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget_2->setRowCount(10);
    ui->tableWidget_2->setColumnCount(10);

    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::NoSelection);

    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            ui->tableWidget->setItem(i,j,new QTableWidgetItem());
            ui->tableWidget->item(i,j)->setTextAlignment(4);
            ui->tableWidget_2->setItem(i,j,new QTableWidgetItem());
            ui->tableWidget_2->item(i,j)->setTextAlignment(4);
        }
        ui->tableWidget->setRowHeight(i,50);
        ui->tableWidget->setColumnWidth(i,50);
        ui->tableWidget_2->setRowHeight(i,50);
        ui->tableWidget_2->setColumnWidth(i,50);
    }
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget_2->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget_2->verticalHeader()->setVisible(false);

}

War::~War()
{
    delete ui;
}

void War::setAllBoat(Boat first[], Boat second[])
{
    for(int i = 0; i<10; i++){
        person1[i] = first[i];
        person2[i] = second[i];
    }
}

void War::setPlayerName(QString first, QString second)
{
    name1 = first;
    name2 = second;
    ui->label->setText(name1);
    ui->label_2->setText(name2);
}

/*void War::on_pushButton_clicked()
{
    for(int i = 0; i < 10; i++){
        for(int l = 0; l < person1[i].pos.size(); l++){
            ui->tableWidget->item(person1[i].pos[l].getRow(),person1[i].pos[l].getColumn())->setBackground(Qt::blue);
        }
        for(int l = 0; l<person2[i].pos.size(); l++){
            ui->tableWidget_2->item(person2[i].pos[l].getRow(),person2[i].pos[l].getColumn())->setBackground(Qt::blue);
        }
    }
}*/

void War::on_tableWidget_cellActivated(int row, int column)
{
    if(ui->tableWidget->item(row,column)->background().color() == Qt::cyan || ui->tableWidget->item(row,column)->background() == brush){
        return;
    }
    if(step == 1){
        QMessageBox box;
        box.setWindowTitle("Куда ходишь?");
        box.setText("Это твоё поле!");
        box.exec();
        return;
    }
    if(checkFire(row,column,1)){
      ui->tableWidget->item(row,column)->setBackground(brush);
      int number = 0;
      for(int i = 0; i < 10; i ++){
          for(int l = 0; l < person1[i].pos.size(); l ++){
              if(person1[i].pos[l].getRow() == row && person1[i].pos[l].getColumn() == column) number = i;
          }
      }
      if(checkAliveBoat(person1[number],1)){
          if(!person1[number].turn){
              for(int l = person1[number].pos[0].getColumn() - 1; l <= person1[number].pos[person1[number].pos.size()-1].getColumn()+1 ;l++ ){
                      if(l < 0 || l > 9) continue;
                      if(person1[number].pos[0].getRow()-1 >= 0)
                      ui->tableWidget->item(person1[number].pos[0].getRow()-1,l)->setBackground(Qt::cyan);
                      if(person1[number].pos[0].getRow()+1 < 10)
                      ui->tableWidget->item(person1[number].pos[0].getRow()+1,l)->setBackground(Qt::cyan);
                  }
              if(person1[number].pos[0].getColumn()-1 >= 0 && person1[number].pos[0].getColumn()-1 <= 9)
              ui->tableWidget->item(person1[number].pos[0].getRow(),person1[number].pos[0].getColumn()-1)->setBackground(Qt::cyan);
              if(person1[number].pos[person1[number].size-1].getColumn()+1 >= 0 && person1[number].pos[person1[number].size-1].getColumn()+1 <= 9)
              ui->tableWidget->item(person1[number].pos[person1[number].size-1].getRow(),person1[number].pos[person1[number].size-1].getColumn()+1)->setBackground(Qt::cyan);
          }else{
              for(int l = person1[number].pos[0].getRow() + 1; l >= person1[number].pos[person1[number].pos.size() - 1].getRow() - 1; l--){
                  if(l < 0 || l > 9) continue;
                  if(person1[number].pos[0].getColumn()-1 >= 0)
                  ui->tableWidget->item(l,person1[number].pos[0].getColumn()-1)->setBackground(Qt::cyan);
                  if(person1[number].pos[0].getColumn()+1 < 10)
                  ui->tableWidget->item(l,person1[number].pos[0].getColumn()+1)->setBackground(Qt::cyan);
              }
              if(person1[number].pos[0].getRow()+1 >= 0 && person1[number].pos[0].getRow()+1 <= 9)
              ui->tableWidget->item(person1[number].pos[0].getRow()+1,person1[number].pos[0].getColumn())->setBackground(Qt::cyan);
              if(person1[number].pos[person1[number].size-1].getRow()-1 >= 0 && person1[number].pos[person1[number].size-1].getRow()-1 <= 9)
              ui->tableWidget->item(person1[number].pos[person1[number].size-1].getRow()-1,person1[number].pos[person1[number].size-1].getColumn())->setBackground(Qt::cyan);
          }
      }
    }else{
        ui->tableWidget->item(row,column)->setBackground(Qt::cyan);
        step = 1;
    }
    if(checkForWin()){
        newGame();
        QMessageBox box;
        box.setWindowTitle("Победа!");
        box.setText("Все корабли соперника потопил игрок "+ui->label_2->text());
        box.exec();
        return;
    }
    if(step == 1){
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(true);
    }
}

void War::on_tableWidget_2_cellActivated(int row, int column)
{
    if(ui->tableWidget_2->item(row,column)->background().color() == Qt::cyan || ui->tableWidget_2->item(row,column)->background() == brush){
        return;
    }
    if(step == 2){
        QMessageBox box;
        box.setWindowTitle("Куда ходишь?");
        box.setText("Это твоё поле!");
        box.exec();
        return;
    }
    if(checkFire(row,column,2)){
      ui->tableWidget_2->item(row,column)->setBackground(brush);
      int number = 0;
      for(int i = 0; i < 10; i ++){
          for(int l = 0; l < person2[i].pos.size(); l ++){
              if(person2[i].pos[l].getRow() == row && person2[i].pos[l].getColumn() == column) number = i;
          }
      }
      if(checkAliveBoat(person2[number],2)){
          if(!person2[number].turn){
              for(int l = person2[number].pos[0].getColumn() - 1; l <= person2[number].pos[person2[number].pos.size()-1].getColumn()+1 ;l++ ){
                      if(l < 0 || l > 9) continue;
                      if(person2[number].pos[0].getRow()-1 >= 0)
                      ui->tableWidget_2->item(person2[number].pos[0].getRow()-1,l)->setBackground(Qt::cyan);
                      if(person2[number].pos[0].getRow()+1 < 10)
                      ui->tableWidget_2->item(person2[number].pos[0].getRow()+1,l)->setBackground(Qt::cyan);
                  }
              if(person2[number].pos[0].getColumn()-1 >= 0 && person2[number].pos[0].getColumn()-1 <= 9)
              ui->tableWidget_2->item(person2[number].pos[0].getRow(),person2[number].pos[0].getColumn()-1)->setBackground(Qt::cyan);
              if(person2[number].pos[person2[number].size-1].getColumn()+1 >= 0 && person2[number].pos[person2[number].size-1].getColumn()+1 <= 9)
              ui->tableWidget_2->item(person2[number].pos[person2[number].size-1].getRow(),person2[number].pos[person2[number].size-1].getColumn()+1)->setBackground(Qt::cyan);
          }else{
              for(int l = person2[number].pos[0].getRow() + 1; l >= person2[number].pos[person2[number].pos.size() - 1].getRow() - 1; l--){
                  if(l < 0 || l > 9) continue;
                  if(person2[number].pos[0].getColumn()-1 >= 0)
                  ui->tableWidget_2->item(l,person2[number].pos[0].getColumn()-1)->setBackground(Qt::cyan);
                  if(person2[number].pos[0].getColumn()+1 < 10)
                  ui->tableWidget_2->item(l,person2[number].pos[0].getColumn()+1)->setBackground(Qt::cyan);
              }
              if(person2[number].pos[0].getRow()+1 >= 0 && person2[number].pos[0].getRow()+1 <= 9)
              ui->tableWidget_2->item(person2[number].pos[0].getRow()+1,person2[number].pos[0].getColumn())->setBackground(Qt::cyan);
              if(person2[number].pos[person2[number].size-1].getRow()-1 >= 0 && person2[number].pos[person2[number].size-1].getRow()-1 <= 9)
              ui->tableWidget_2->item(person2[number].pos[person2[number].size-1].getRow()-1,person2[number].pos[person2[number].size-1].getColumn())->setBackground(Qt::cyan);
          }
      }
    }else{
        ui->tableWidget_2->item(row,column)->setBackground(Qt::cyan);
        step = 2;
    }
    if(checkForWin()){
        newGame();
        QMessageBox box;
        box.setWindowTitle("Победа!");
        box.setText("Все корабли соперника потопил игрок "+ui->label->text());
        box.exec();
        return;
    }
    if(step == 2){
        ui->label_3->setVisible(true);
        ui->label_4->setVisible(false);
    }
}


bool War::checkFire(int row, int column, int person)
{
    Boat tempPersonBoat[10];
    if(person == 1){
        for(int i = 0 ; i< 10; i++){
            tempPersonBoat[i] = person1[i];
        }
    }else if(person == 2){
        for(int i = 0 ; i< 10; i++){
            tempPersonBoat[i] = person2[i];
        }
    }
    for(int i = 0 ; i < 10; i ++){
        for(int j = 0; j < tempPersonBoat[i].pos.size(); j ++){
            if(tempPersonBoat[i].pos[j].getRow() == row && tempPersonBoat[i].pos[j].getColumn() == column){
                return true;
            }
        }
    }
    return false;
}

bool War::checkForWin()
{
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < 10 ; i++){
        for(int j = 0; j < 10; j++){
            if(ui->tableWidget->item(i,j)->background() == brush) count1++;
            if(ui->tableWidget_2->item(i,j)->background() == brush) count2++;
        }
    }
    if(count1 == 20 || count2 == 20){
        return true;
    }else{
        return false;
    }
}

bool War::checkAliveBoat(Boat b, int n)
{
    if(n == 1){
        for(int i = 0; i < b.pos.size(); i++){
            if( ui->tableWidget->item(b.pos[i].getRow(),b.pos[i].getColumn())->background() != brush ){
                return false;
            }
        }
    }else if(n == 2){
        for(int i = 0; i < b.pos.size(); i++){
            if( ui->tableWidget_2->item(b.pos[i].getRow(),b.pos[i].getColumn())->background() != brush ){
                return false;
            }
        }
    }
    return true;
}

void War::newGame()
{
    QApplication::closeAllWindows();
    MainWindow *a;
    a = new MainWindow;
    a->show();
}



void War::on_pushButton_2_clicked()
{
    bool ok;
        QFont font = QFontDialog::getFont(&ok, this);
        if (ok) {
            ui->label->setFont(font);
            ui->label_2->setFont(font);
        } else {
            return;
        }
}
