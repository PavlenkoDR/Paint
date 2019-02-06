#include "line.h"

Line::Line(int xStart, int yStart, int xEnd, int yEnd, bool f)
    : Shape(xStart, yStart, xEnd, yEnd, f){}

Line::Line(const Line &orig)
    : Shape(orig.xStart, orig.yStart, orig.xEnd, orig.yEnd, orig.filled){}

Line::Line()
    : Shape(){}
