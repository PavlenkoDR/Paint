#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QSpinBox>
#include <QAction>
#include <drawingarea.h>

// Основной виджет в приложении, он расширяет класс QWidget.
class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    // Конструктор, который принимает родительский виджет, который равен нулю по умолчанию.
    PaintWidget(QWidget *parent = 0);

    // Деструктор главного окна.
    ~PaintWidget();

    // Слоты, которые принимают сигналы, чтобы изменить значения формы которые пользователь начнет рисовать.
private slots:

    // Каждый слот вызывается, когда пользователь выбирает соответствующую форму, что он хочет рисовать.
    void drawRectangle();
    void drawSquare();
    void drawCircle();
    void drawLine();
    void drawBrush();
    void drawEraser();
    void drawFill();

    void changeSetColorPen();
    void changeSetColorBrush();

    // Слот, который изменяет расчетную площадь обнаженным формы.
    void changeAreaValue(double newArea);

    // Слот, который вызывается, когда опция заполнения изменяется.
    void drawFilled(int value);

    // Слот, который вызывается, когда опция эффектов изменяется.
    void enableEffects(int value);

    // Слоты, которые вызываются, когда пользователь перемещает ползун, которые контролируют цветовую комбинацию RGB.
    void changeRedColor(int redValue);
    void changeGreenColor(int GreenValue);
    void changeBlueColor(int blueValue);
    void changeAlphaColor(int alphaValue);
    void changePenWidth(int penWidth);

    // Компоненты, которые содержатся в главном виджете

private:

    // Кнопки для выбора, какую форму рисовать, ясно область рисования и закрыть приложение
    QPushButton *rectangle;
    QPushButton *square;
    QPushButton *circle;
    QPushButton *line;
    QPushButton *brush;
    QPushButton *eraser;
    QPushButton *fill;
    QPushButton *close;
    QPushButton *clear;
    QPushButton *save;

    // Лейблы
    QLabel *showingAreaLabel;
    QLabel *redColorLabel;
    QLabel *greenColorLabel;
    QLabel *blueColorLabel;
    QLabel *alphaColorLabel;
    QLabel *penWidthLabel;
    QPushButton *colorPen;
    QPushButton *colorBrush;
    bool colorFlag;

    // QLineEdit показывает форму для отрисовки фигуры.
    QLineEdit *showingArea;

    // Флажки, так что пользователь может выбрать, следует ли рисовать заполненные формы или с использованием эффектов.
    QCheckBox *fillOption;
    QCheckBox *effectsOption;

    // Ползунки, управляющие комбинациями RGB, чтобы изменить цвет формы.
    QSlider *colorChangerRed;
    QSlider *colorChangerGreen;
    QSlider *colorChangerBlue;
    QSlider *colorChangerAlpha;
    QSpinBox *penChangerWidth;

    // Расширенное QWidget, чтобы рисовать фигуры.
    DrawingArea *paper;
};

#endif // PAINTWIDGET_H
