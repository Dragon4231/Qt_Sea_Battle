#ifndef DRAW_H
#define DRAW_H

#include <QMainWindow>
#include <QPainter>

namespace Ui {
class Draw;
}

class Draw : public QMainWindow
{
    Q_OBJECT

public:
    explicit Draw(QWidget *parent = nullptr);
    ~Draw();

private:
    Ui::Draw *ui;
    int width = 0;
    int colourLine = 0;
    int colourBack = 0;
    int typeLine = 0;
protected:
    void paintEvent(QPaintEvent*) override;

private slots:
    void on_pushButton_clicked();
};

#endif // DRAW_H
