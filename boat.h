#ifndef BOAT_H
#define BOAT_H
#include <position.h>
#include <QVector>

class Boat
{
public:
    Boat();
    Boat(int size, int nmb);
    void addPos(int row, int column);
    int size;
    int numberOfBoat;
    bool turn;
    QVector<Position> pos;

     void upBoat();
     void downBoat();
     void leftBoat();
     void rightBoat();
     void reverseBoat();
     bool checkBoatPos(QVector<Position> p);
     bool checkPos(int r, int c);
};

#endif // BOAT_H
