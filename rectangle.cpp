#include "rectangle.h"
#include "stdlib.h"

// Конструктор по умолчанию, который вызывает конструктор базового класса для создания пустой формы.
Rectangle::Rectangle()
        :Shape()
{

}

// Конструктор, который строит прямоугольник с заданными атрибутами, он сначала вызывает конструктор базового класса.
Rectangle::Rectangle(int xStart, int yStart, int xEnd, int yEnd, bool f)
        :Shape(xStart, yStart, xEnd, yEnd, f)
{
    // Вычисление ширины и высоты прямоугольника.
    this->width = this->xEnd - this->xStart;
    this->height = this->yEnd - this->yStart;
}

// Конструктор копирования, который копирует оригинальный прямоугольник.
Rectangle::Rectangle(const Rectangle &orig)
        : Shape(orig.xStart, orig.yStart, orig.xEnd, orig.yEnd, orig.filled)
{
    this->width = orig.width;
    this->height = orig.height;
}

// Деструктор прямоугольника.
Rectangle::~Rectangle()
{

}

// Устанавливает ширину прямоугольника.
void Rectangle::setWidth(int w)
{
    this->width = w;
}

// Устанавливает высоту прямоугольника.
void Rectangle::setHeight(int h)
{
    this->height = h;
}

// Получает ширину прямоугольника.
int Rectangle::getWidth()
{
    return this->width;
}

// Gets the height of a rectangle.
int Rectangle::getHeight()
{
    return this->height;
}
// Получает высоту прямоугольника.
int Rectangle::getArea()
{
    return abs (this->width * this->height);
}
