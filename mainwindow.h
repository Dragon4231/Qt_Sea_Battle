#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <game.h>
#include <autorize.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exit_game_clicked();

    void on_info_game_clicked();

    void on_start_game_clicked();

    void on_last_game_clicked();

private:
    Ui::MainWindow *ui;
    Autorize *newGame;
};
#endif // MAINWINDOW_H
