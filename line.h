#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape
{
public:
    Line();

    Line(int xStart, int yStart, int xEnd, int yEnd, bool f);

    Line(const Line &orig);

    inline ~Line(){}
    double getArea(){return 0;}
};

#endif // LINE_H
