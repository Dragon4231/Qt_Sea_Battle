#include "boat.h"
#include <QVector>
#include <position.h>
#include <QMessageBox>

Boat::Boat()
{

}

Boat::Boat(int size, int nmb)
{
    //pos.resize(size);
    this->size = size;
    this->numberOfBoat = nmb;
    this->turn = false;
}

void Boat::addPos(int row, int column)
{
    Position temp(row,column);
    pos.push_back(temp);
}

void Boat::upBoat()
{
    if(!(pos[pos.size()-1].row-1 >= 0)){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Движение вверх невозможно.");
        box.exec();
        return;
    }
    for(int i = 0; i < pos.size(); i ++){
        pos[i].row -= 1;
    }
}

void Boat::downBoat()
{
    if(!(pos[0].row+1 <= 9)){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Движение вниз невозможно.");
        box.exec();
        return;
    }
    for(int i = 0; i < pos.size(); i ++){
        pos[i].row += 1;
    }
}

void Boat::leftBoat()
{
    if(!(pos[0].column-1 >= 0)){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Движение влево невозможно.");
        box.exec();
        return;
    }
    for(int i = 0; i < pos.size(); i ++){
        pos[i].column -= 1;
    }
}

void Boat::rightBoat()
{
    if(!(pos[pos.size()-1].column+1 <= 9)){
        QMessageBox box;
        box.setWindowTitle("Ошибка");
        box.setText("Движение вправо невозможно.");
        box.exec();
        return;
    }
    for(int i = 0; i < pos.size(); i ++){
        pos[i].column += 1;
    }
}

void Boat::reverseBoat()
{
    if(this->size == 1){
        return;
    }
    if(turn){
        if((pos[0].column + (size-1)) > 9){
            QMessageBox box;
            box.setWindowTitle("Ошибка");
            box.setText("Разворот невозможен.");
            box.exec();
            return;
        }
        for(int i = 1; i < pos.size(); i++){
            pos[i].row = pos[0].row;
            pos[i].column = pos[i-1].column + 1;
        }
        turn = false;
    }else{
        if((pos[0].row - (size-1)) < 0){
            QMessageBox box;
            box.setWindowTitle("Ошибка");
            box.setText("Разворот невозможен.");
            box.exec();
            return;
        }
        for(int i = 1; i < pos.size(); i++){
            pos[i].column = pos[0].column;
            pos[i].row = pos[i-1].row - 1;
        }
        turn = true;
    }
}

bool Boat::checkBoatPos(QVector<Position> p)
{
    for(int i = 0; i < p.size(); i ++){
        for(int l = 0; l < pos.size(); l ++){
            if(p[i].row == pos[l].row && p[i].column == pos[l].column) return true;
        }
    }
    return false;
}

bool Boat::checkPos(int r, int c)
{
    for(int l = 0; l < pos.size(); l ++){
        if(r == pos[l].row && c == pos[l].column) return true;
    }
    return false;
}
