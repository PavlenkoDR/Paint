#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"

class Square : public Rectangle
{
public:
    Square();

    Square(int xStart, int yStart, int xEnd, int yEnd, bool f);

    Square(const Square &orig);

    ~Square();

};

#endif // SQUARE_H
