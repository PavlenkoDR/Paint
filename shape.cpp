#include "shape.h"

// Конструктор по умолчанию формы.
Shape::Shape()
{
    this->xStart = 0;
    this->yStart = 0;
    this->xEnd = 0;
    this->yEnd = 0;
    this->filled = false;
}

// Конструктор, который строит форму с заданными значениями.
Shape::Shape(int xStart, int yStart, int xEnd, int yEnd, bool f)
{
    this->xStart = xStart;
    this->yStart = yStart;
    this->xEnd = xEnd;
    this->yEnd = yEnd;
    this->filled = f;
}

// Копировать конструктор, который копирует значения из исходной формы.
Shape::Shape(const Shape &orig)
{
    this->xStart = orig.xStart;
    this->yStart = orig.yStart;
    this->xEnd = orig.xEnd;
    this->yEnd = orig.yEnd;
    this->filled = orig.filled;
}

// Destructor.
Shape::~Shape()
{

}

// Задает Х-координату начальной точки формы.
void Shape::setXStart(int x)
{
    this->xStart = x;
}

// Устанавливает Y-координату начальной точки формы.
void Shape::setYStart(int y)
{
    this->yStart = y;
}

// Устанавливает Х-координату конечной точки формы.
void Shape::setXEnd(int x)
{
    this->xEnd = x;
}

// Устанавливает Y-координату конечной точки формы.
void Shape::setYEnd(int y)
{
    this->yEnd = y;
}

// Заполнена или не заполнена форма.
void Shape::setFilled(bool f)
{
    this->filled = f;
}

// Получает Х-координату начальной точки формы.
int Shape::getXStart()
{
    return this->xStart;
}

// Получает Y-координату начальной точки формы.
int Shape::getYStart()
{
    return this->yStart;
}

// Получает Х-координату конечной точки формы.
int Shape::getXEnd()
{
    return this->xEnd;
}

// Получает Y-координату конечной точки формы.
int Shape::getYEnd()
{
    return this->yEnd;
}

// Показывает, заполнена ли форма.
bool Shape::isFilled()
{
    return this->filled;
}
