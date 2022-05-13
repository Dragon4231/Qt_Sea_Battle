#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    Position();
    Position(int x, int y);
    int row,column;
    int getRow();
    int getColumn();
};

#endif // POSITION_H
