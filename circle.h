#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

// Класс, который определяет круг и расширяет класс формы.
class Circle : public Shape
{
public:
    // конструктор по умолчанию, который строит пустой круг.
    Circle();

    // Конструктор, который строит круг с заданными аргументами.
    Circle(int xStart, int yStart, int xEnd, int yEnd, bool f);

    // Конструктор копирования, который копирует оригинал Circle.
    Circle(const Circle &orig);

    // Destructor.
    ~Circle();

    // Тут задаем радиус.
    void setRadius(double r);

    // Получаем радиус.
    double getRadius();

    // Вычисляет площадь окружности.
    double getArea();

private:
    // Константа PI используется для вычисления площади любого круга.
    double static const PI = 3.1415926535;

    // Радиус круга.
    double radius;

};

#endif // CIRCLE_H
