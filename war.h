#ifndef WAR_H
#define WAR_H

#include <QDialog>
#include <boat.h>
#include <QBrush>
namespace Ui {
class War;
}

class War : public QDialog
{
    Q_OBJECT

public:
    explicit War(QWidget *parent = nullptr);
    ~War();
    Boat person1[10];
    Boat person2[10];
    void setAllBoat(Boat first[10], Boat second[10]);
    void setPlayerName(QString first, QString second);
    QString name1, name2;
    int step = 1;

private slots:

    void on_tableWidget_cellActivated(int row, int column);

    void on_tableWidget_2_cellActivated(int row, int column);

    bool checkFire(int row, int column, int person);

    bool checkForWin();

    bool checkAliveBoat(Boat b, int n);

    void newGame();
    void on_pushButton_2_clicked();

private:
    Ui::War *ui;
    QBrush brush;
};

#endif // WAR_H
