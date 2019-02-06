#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H
#include <QPixmap>
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <QFileDialog>
#include <QAction>
#include "shape.h"
#include <iostream>
#include <vector>

// Класс, который наследуется от QWidget и определяет область, где вы можете рисовать фигуры.
class DrawingArea : public QWidget
{
    Q_OBJECT
public:

    // Конструктор, который создает новую область рисования.
    DrawingArea(QWidget *parent = 0);

    // Destructor
    ~DrawingArea();

    // Setters
    void setType(int value);
    void setShapeFilled(bool value);
    void setEffectsEnabled(bool value);
    void setPenWidth(int width);
    void setPenColor(int r, int g, int b, int a);
    void setBrushColor(int r, int g, int b, int a);

    // Getters
    int getType();
    bool isShapeFilled();
    bool effectsEnabled();
    QPen getPen();
    QBrush getBrush();
    QColor penColor, brushColor;
protected:
    // Виртуальные методы для переопределений тех или иных событий, чтобы начать собственно рисовать

    // Вызывается при щелчке мышью.
    virtual void mousePressEvent(QMouseEvent *event);

    // Вызывается, когда мышь движется в виджет при нажатии этой кнопки.
     virtual void mouseMoveEvent(QMouseEvent *event);

    // Вызывается, когда пользователь отпускает кнопку мыши.
     virtual void mouseReleaseEvent(QMouseEvent *event);

    // Вызывается при изменении размера виджета или перерисовки.
     virtual void paintEvent(QPaintEvent *event);
     void Fill(QMouseEvent *event);
     //virtual QPoint globalPos(){std::cout << "@" << std::endl;}
    //virtual void keyPressEvent(QKeyEvent *){};


public slots:
    // Слот, который очищает область рисования, разрушая старую пиксельную карту и создать новую.
     void clearPixMap();

     // Слот, который сохраняет рисунок в растровое изображение.
     void savePixMap();

     void Undo();
     void Redo();


signals:
     // Обновить область отрисовки.
    void updateArea(double newArea);

private:
    // Растровое изображение, для сохранения нарисованных фигур в нем.
    QPixmap *history;
    int Fill(int x, int y);
    // Паинтер, который рисует в pixmap
    QPainter *historyPainter;
    std::list<QImage> historyVec;
    std::list<QImage>::iterator historyVec_iterator;

    // Форма, что мы рисуем.
    Shape *s;

    // Логическое значение, определяет, будет ли эффекты включены или нет.
    bool enabledEffects;

    // Целое число, начинает рисовать.
    int trigger;

    // Определяет тип фигуры, которая будет нарисована
         // 1 = Прямоугольник
         // 2 = Квадратный
         // 3 = Круг
         // 4 = Линия
    int type;

    // Логическое значение, определяющее, будет ли заполнена форма или нет.
    bool shapeFilled;

    // Целые которые представляют значение каждого цвета RGB.
    QPen pen;
    QPen cursor;
    int xOld, yOld;
};

#endif // DRAWINGAREA_H
