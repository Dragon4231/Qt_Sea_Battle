#include "draw.h"
#include "ui_draw.h"

Draw::Draw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Draw)
{
    ui->setupUi(this);
}

Draw::~Draw()
{
    delete ui;
}

void Draw::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    QPen pen;
    QBrush brush;
    if(!ui->textEdit->toPlainText().isEmpty()){
        pen.setWidth(ui->textEdit->toPlainText().toInt());
    }
    if(colourBack != 0){
        if(colourBack == 1) brush.setColor(Qt::blue);
        else if(colourBack == 2) brush.setColor(Qt::red);
        else if(colourBack == 3) brush.setColor(Qt::green);
    }
    if(colourLine != 0){
        if(colourLine == 1) pen.setColor(Qt::black);
        else if(colourLine == 2) pen.setColor(Qt::red);
        else if(colourLine == 3) pen.setColor(Qt::blue);
        else if(colourLine == 4) pen.setColor(Qt::green);
    }
    if(typeLine != 0){
        if(typeLine == 1) pen.setStyle(Qt::SolidLine);
        else if(typeLine == 2) pen.setStyle(Qt::DashLine);
        else if(typeLine == 3) pen.setStyle(Qt::DotLine);
    }
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setBackground(brush);
    painter.setPen(pen);
    // каркас корабл
    painter.drawLine(180,400,200,500);
    painter.drawLine(200,500,600,500);
    painter.drawLine(600,500,660,400);
    painter.drawLine(660,400,180,400);
    painter.drawLine(180,400,150,260);
    painter.drawLine(150,260,270,260);
    painter.drawLine(270,260,400,260);
    painter.drawLine(400,260,440,320);
    painter.drawLine(440,320,605,320);
    painter.drawLine(605,320,700,320);
    painter.drawLine(700,320,660,400);
    //крыша
    painter.drawLine(210,260,240,150);
    painter.drawLine(240,150,600,150);
    painter.drawLine(600,150,605,320);

    painter.drawEllipse(315,170,80,80);
    painter.drawEllipse(450,170,80,80);

    painter.end();


}

void Draw::on_pushButton_clicked()
{
    if(ui->textEdit->toPlainText().isEmpty()){
        width = 0;
    }else width = ui->textEdit->toPlainText().toInt();
    if(ui->comboBox->currentIndex() == 0) colourBack = 0;
    else colourBack = ui->comboBox->currentIndex();

    if(ui->comboBox_2->currentIndex() == 0) colourLine = 0;
    else colourLine = ui->comboBox_2->currentIndex();
    if(ui->comboBox_3->currentIndex() == 0) typeLine = 0;
    else typeLine = ui->comboBox_3->currentIndex();
    repaint();
}
