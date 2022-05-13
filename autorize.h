#ifndef AUTORIZE_H
#define AUTORIZE_H

#include <QDialog>
#include <game.h>
#include <war.h>

namespace Ui {
class Autorize;
}

class Autorize : public QDialog
{
    Q_OBJECT

public:
    explicit Autorize(QWidget *parent = nullptr);
    ~Autorize();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Autorize *ui;
    Game *person1 = new Game;
    Game *person2 = new Game;
    War *startGame;
};

#endif // AUTORIZE_H
