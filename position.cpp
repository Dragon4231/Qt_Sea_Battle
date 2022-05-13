#include "position.h"

Position::Position()
{

}

Position::Position(int x, int y)
{
    this->row = x;
    this->column = y;
}

int Position::getRow()
{
    return this->row;
}

int Position::getColumn()
{
    return this->column;
}
