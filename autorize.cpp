#include "autorize.h"
#include "ui_autorize.h"
#include <QMessageBox>
#include <game.h>
#include <war.h>

Autorize::Autorize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Autorize)
{
    ui->setupUi(this);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
}

Autorize::~Autorize()
{
    delete ui;
}

void Autorize::on_pushButton_clicked()
{
    if(ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty()){
        QMessageBox box;
        box.setWindowTitle("Ошибка.");
        box.setText("Одно из полей пустое!");
        box.exec();
        return;
    }
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit_2->setFocusPolicy(Qt::NoFocus);
    ui->textEdit_2->setReadOnly(true);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    ui->pushButton_4->setVisible(true);
}

void Autorize::on_pushButton_2_clicked()
{
    //game1
    person1->show();
}

void Autorize::on_pushButton_3_clicked()
{
    //game2
    person2->show();
}

void Autorize::on_pushButton_4_clicked()
{
    if(person1->checkForField() && person2->checkForField()){
        startGame = new War;
        startGame->setModal(true);
        startGame->setAllBoat(this->person1->boat, this->person2->boat);
        startGame->setPlayerName(ui->textEdit->toPlainText(),ui->textEdit_2->toPlainText());
        startGame->show();
    }else if(person1->checkForField() == false){
        QMessageBox box;
        box.setWindowTitle("Ошибка.");
        box.setText("В поле №1 неправильно расставлены корабли.");
        box.exec();
        return;
    }else if(person2->checkForField() == false){
        QMessageBox box;
        box.setWindowTitle("Ошибка.");
        box.setText("В поле №2 неправильно расставлены корабли.");
        box.exec();
        return;
    }
}
