#ifndef SHAPE_H
#define SHAPE_H

// Класс, который определяет основные атрибуты любой формы.
class Shape
{
public:
    // Создает форму с нулевыми значениями.
    Shape();

    // Создаёт форму с заданными аргументами.
    Shape(int xStart, int yStart, int xEnd, int yEnd, bool f);

    // Конструктор копирования.
    Shape(const Shape &orig);

    // Деструктор.
    ~Shape();

    // Сеттеры для атрибутов формы.
    void setXStart(int x);
    void setYStart(int y);
    void setXEnd(int x);
    void setYEnd(int y);
    void setFilled(bool f);

    // Геттеры для атрибутов формы.
    int getXStart();
    int getYStart();
    int getXEnd();
    int getYEnd();
    bool isFilled();

protected:
    // Х и Y индексы, начала формы.
    int xStart;
    int yStart;

    // Х и Y индексы, конца формы.
    int xEnd;
    int yEnd;

    // Определяет, заполнена ли форма или нет.
    bool filled;
};

#endif // SHAPE_H

