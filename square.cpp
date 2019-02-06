#include "square.h"

// По умолчанию конструктор, который создает пустой квадрат, он вызывает конструктор базового класса в первую очередь.
Square::Square()
        :Rectangle()
{
}

// Конструктор, который строит квадрат с заданными параметрами.
Square::Square(int xStart, int yStart, int xEnd, int yEnd, bool f)
        :Rectangle(xStart, yStart, xEnd, yEnd, f)
{
    // Вычисление ширины.
    this->width = (this->xEnd - this->xStart);
    // Высота равна ширине.
    this->height = (this->width);
}

// Конструкторы копирования, что делает копию исходного квадрата.
Square::Square(const Square &orig)
        : Rectangle(orig.xStart, orig.yStart, orig.xEnd, orig.yEnd, orig.filled)
{
    this->width = orig.width;
    this->height = orig.height;
}

// Деструктор квадрата.
Square::~Square()
{
}


