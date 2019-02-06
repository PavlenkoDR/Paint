#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

// класс прямоугольник, который расширяет форму добавления дополнительных атрибутов и методов.
class Rectangle : public Shape
{
public:
    // Конструктор по умолчанию, который создает и пустая форма.
    Rectangle();

    // Конструктор, который строит прямоугольник с заданными атрибутами.
    Rectangle(int xStart, int yStart, int xEnd, int yEnd, bool f);

    // Конструктор копирования, который копирует оригинальный прямоугольник.
    Rectangle(const Rectangle &orig);

    ~Rectangle();

    // Сеттеры ширины и высоты.
    void setWidth(int w);
    void setHeight(int h);

    // Геттеры ширины и высоты.
    int getWidth();
    int getHeight();

    // Виртуальный метод, который вычисляет площадь прямоугольника.
    virtual int getArea();
    
    
protected:
    // Ширина и высота прямоугольника.
    int width;
    int height;
    
};

#endif // RECTANGLE_H
