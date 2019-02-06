#include "circle.h"
#include <math.h>

// По умолчанию конструктор, который строит пустой круг, он вызывает конструктор базового класса в первую очередь.
Circle::Circle()
        :Shape()
{
    this->radius = 0;
}

// Конструктор, который строит круг с заданными атрибутами.
Circle::Circle(int xStart, int yStart, int xEnd, int yEnd, bool f)
        :Shape(xStart, yStart, xEnd, yEnd, f)
{
    // Вычисление радиуса окружности с использованием Пифагора. x^2 + y^2 = R^2
    int x = this->xEnd - this->xStart;
    int y = this->yEnd - this->yStart;
    this->radius = sqrt(pow(x, 2) + pow(x, 2));
}

// Конструктор копирования, который копирует исходную окружность.
Circle::Circle(const Circle &orig)
        : Shape(orig.xStart, orig.yStart, orig.xEnd, orig.yEnd, orig.filled)
{
    this->radius = orig.radius;
}

// Destructor
Circle::~Circle()
{
}

// Вычисляет площадь круга.
double Circle::getArea()
{
    return pow(this->radius, 2) * PI;
}


