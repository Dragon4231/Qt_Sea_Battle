#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QTableWidgetItem>
#include <boat.h>
namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    bool checkForField();
    Boat boat[10];

public slots:
    void keyPressEvent(QKeyEvent *e);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    bool on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    void update();
    void newField();
    Ui::Game *ui;
    QBrush brush;
    QTableWidgetItem *itm;
    int tcolumn = 0, trow = 0;
    int gamePers[10][10];

};

#endif // GAME_H
