#include <QLayout>
#include "paintwidget.h"


// Конструктор, который строит главный виджет без родителей и добавляет компоненты к нему в соответствующих макетов.
PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    // Создание кнопок с использованием ярлыков.
    this->rectangle = new QPushButton("&Rectangle");
    this->square = new QPushButton("&Square");
    this->circle = new QPushButton("&Circle");
    this->line = new QPushButton("&Line");
    this->eraser = new QPushButton("&Eraser");
    this->brush = new QPushButton("&Brush");
    this->fill = new QPushButton("&Fill");
    this->close = new QPushButton("C&lose");
    this->clear = new QPushButton("Cle&ar");
    this->save = new QPushButton("Sa&ve");

    // Создание формы отрисовки
    this->showingAreaLabel = new QLabel("Area = ");
    this->showingArea = new QLineEdit;
    this->showingArea->setEnabled(false);
    QFont *areaFont = new QFont();
    areaFont->setBold(true);
    this->showingArea->setFont(*areaFont);

    // Создание параметров для заполнения или отрисовки с эффектами.
    this->fillOption = new QCheckBox("&Filled");
    this->effectsOption = new QCheckBox("&Effects");

    // Создание области, где будут нарисованы компоненты.
    this->paper = new DrawingArea(this);

    // Создание цвета ползунков и лейблов.
    this->redColorLabel = new QLabel("R");
    this->colorChangerRed = new QSlider(Qt::Horizontal);
    this->colorChangerRed->setRange(0, 255);
    this->colorChangerRed->setTickInterval(1);
    this->greenColorLabel = new QLabel("G");
    this->colorChangerGreen = new QSlider(Qt::Horizontal);
    this->colorChangerGreen->setRange(0, 255);
    this->colorChangerGreen->setTickInterval(1);
    this->blueColorLabel = new QLabel("B");
    this->colorChangerBlue = new QSlider(Qt::Horizontal);
    this->colorChangerBlue->setRange(0, 255);
    this->colorChangerBlue->setTickInterval(1);
    this->alphaColorLabel = new QLabel("A");
    this->colorChangerAlpha = new QSlider(Qt::Horizontal);
    this->colorChangerAlpha->setRange(0, 255);
    this->colorChangerAlpha->setTickInterval(1);
    this->colorChangerAlpha->setValue(255);
    this->penWidthLabel = new QLabel("pen width");
    this->penChangerWidth = new QSpinBox();
    this->penChangerWidth->setRange(1, 100);

    // Создание области, чтобы показать, как выбранный цвет выглядит.
    this->colorPen = new QPushButton();
    this->colorBrush = new QPushButton();

    // Установка стиля компонентов
    this->redColorLabel->setStyleSheet("* {  font-size: 20px; color: white;}");
    this->greenColorLabel->setStyleSheet("* {  font-size: 20px; color: white;}");
    this->blueColorLabel->setStyleSheet("* {  font-size: 20px; color: white;}");
    this->alphaColorLabel->setStyleSheet("* {  font-size: 20px; color: white;}");
    this->penWidthLabel->setStyleSheet("* {  font-size: 20px; color: white;}");
    this->penChangerWidth->setStyleSheet("* {  font-size: 20px; color: black; background-color: white;}");
    this->colorPen->setStyleSheet("* { background-color: black; }");
    this->colorBrush->setStyleSheet("* { background-color: white; }");
    this->square->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->line->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->brush->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->eraser->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->circle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->rectangle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->fill->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->close->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->clear->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->save->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->showingAreaLabel->setStyleSheet("* {  font-size: 20px; color: white;}");
    this->showingArea->setStyleSheet("* {  font-weight: bolder; font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->fillOption->setStyleSheet("* {  font-size: 20px; color: white;}");
    this->effectsOption->setStyleSheet("* {  font-size: 20px; color: white;}");
    this->setStyleSheet("* {background-color: rgb(76,76,76)}");

    // Изменение размера главного окна.
    this->resize(800, 500);

    /* Creating layouts.
     The main layout is horizontal, it includes two layouts: the drawing area layout and the control layout,
     which are vertical.
     The control layout contains three layouts: buttons, options and calculating area, all are vertical.
     The options layout contains three layouts: three for three colors and one for the filled and effects options.
    */
    /* Создание отступов.
    Основной отступ по горизонтали, он включает в себя два отступа: отступ области рисования и схема управления,
    которые являются вертикальными.
    Схема управления содержит три отступа: кнопки, опции и вычисления площади, все вертикальные.
    Схема настроек содержит три отступа: три для трех цветов и один для заполнения и вариантов эффектов.
    */
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QHBoxLayout *calculatingAreaLayout = new QHBoxLayout;
    QVBoxLayout *optionsLayout = new QVBoxLayout;
    QVBoxLayout *controlLayout = new QVBoxLayout;
    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    QVBoxLayout *drawingAreaLayout = new QVBoxLayout;
    QHBoxLayout *redColorLayout = new QHBoxLayout;
    QHBoxLayout *greenColorLayout = new QHBoxLayout;
    QHBoxLayout *blueColorLayout = new QHBoxLayout;
    QHBoxLayout *alphaColorLayout = new QHBoxLayout;
    QHBoxLayout *penWidthLayout = new QHBoxLayout;

    // Добавление виджетов в их макетов

    // Добавление области рисования.
    drawingAreaLayout->addWidget(this->paper);

    // Добавление кнопок.
    buttonsLayout->addWidget(this->rectangle);
    buttonsLayout->addWidget(this->square);
    buttonsLayout->addWidget(this->circle);
    buttonsLayout->addWidget(this->line);
    buttonsLayout->addWidget(this->brush);
    buttonsLayout->addWidget(this->eraser);
    buttonsLayout->addWidget(this->fill);
    buttonsLayout->addWidget(this->save);
    buttonsLayout->addWidget(this->clear);
    buttonsLayout->addWidget(this->close);

    // Добавление заполнения и опции эффектов.
    optionsLayout->addWidget(this->fillOption);
    optionsLayout->addWidget(this->effectsOption);

    // Добавление отступов цветов.
    redColorLayout->addWidget(this->redColorLabel);
    redColorLayout->addWidget(this->colorChangerRed);
    greenColorLayout->addWidget(this->greenColorLabel);
    greenColorLayout->addWidget(this->colorChangerGreen);
    blueColorLayout->addWidget(this->blueColorLabel);
    blueColorLayout->addWidget(this->colorChangerBlue);
    alphaColorLayout->addWidget(this->alphaColorLabel);
    alphaColorLayout->addWidget(this->colorChangerAlpha);
    penWidthLayout->addWidget(this->penWidthLabel);
    penWidthLayout->addWidget(this->penChangerWidth);
    optionsLayout->addLayout(redColorLayout);
    optionsLayout->addLayout(greenColorLayout);
    optionsLayout->addLayout(blueColorLayout);
    optionsLayout->addLayout(alphaColorLayout);
    optionsLayout->addLayout(penWidthLayout);
    optionsLayout->addWidget(this->colorPen);
    optionsLayout->addWidget(this->colorBrush);

    // Добавление вычисления компонентов площади.
    calculatingAreaLayout->addWidget(this->showingAreaLabel);
    calculatingAreaLayout->addWidget(this->showingArea);

    // Добавление отступов,
    controlLayout->addLayout(buttonsLayout,3);
    controlLayout->addLayout(optionsLayout,1);
    controlLayout->addLayout(calculatingAreaLayout,1);

    mainLayout->addLayout(drawingAreaLayout, 4);
    mainLayout->addLayout(controlLayout,1);

    // Настройка главного отступа.
    this->setLayout(mainLayout);

    // Connecting signals with their corresponding signals.

    // Подключение сигналов с их соответствующими сигналами.
    connect(this->close, SIGNAL(clicked()), this, SLOT(close()));

    // Каждая кнопка изменяет тип формы, которые будут нарисованы в области рисования.
    connect(this->rectangle, SIGNAL(clicked()), this, SLOT(drawRectangle()));
    connect(this->square, SIGNAL(clicked()), this, SLOT(drawSquare()));
    connect(this->circle, SIGNAL(clicked()), this, SLOT(drawCircle()));
    connect(this->line, SIGNAL(clicked()), this, SLOT(drawLine()));
    connect(this->brush, SIGNAL(clicked()), this, SLOT(drawBrush()));
    connect(this->eraser, SIGNAL(clicked()), this, SLOT(drawFill()));
    connect(this->fill, SIGNAL(clicked()), this, SLOT(drawEraser()));
    connect(this->colorPen, SIGNAL(clicked()), this, SLOT(changeSetColorPen()));
    connect(this->colorBrush, SIGNAL(clicked()), this, SLOT(changeSetColorBrush()));

    // Кнопка Очистить очищает область рисования, разрушая старую пиксельную карту и создать новую.
    connect(this->clear, SIGNAL(clicked()), this->paper, SLOT(clearPixMap()));

    connect(this->save, SIGNAL(clicked()), this->paper, SLOT(savePixMap()));

    // Область сообщает линия редактирования, где область показана о зоне парного формы.
    connect(this->paper, SIGNAL(updateArea(double)), this, SLOT(changeAreaValue(double)));

    // Флажки уведомляющие свой статус, чтобы изменить способ отрисовки формы.
    connect(this->fillOption, SIGNAL(stateChanged(int)), this, SLOT(drawFilled(int)));
    connect(this->effectsOption, SIGNAL(stateChanged(int)), this, SLOT(enableEffects(int)));

    // Цвет ползунков изменит тип цвета, который будет использоваться, чтобы нарисовать форму.
    connect(this->colorChangerRed, SIGNAL(valueChanged(int)), this, SLOT(changeRedColor(int)));
    connect(this->colorChangerGreen, SIGNAL(valueChanged(int)), this, SLOT(changeGreenColor(int)));
    connect(this->colorChangerBlue, SIGNAL(valueChanged(int)), this, SLOT(changeBlueColor(int)));
    connect(this->colorChangerAlpha, SIGNAL(valueChanged(int)), this, SLOT(changeAlphaColor(int)));
    connect(this->penChangerWidth, SIGNAL(valueChanged(int)), this, SLOT(changePenWidth(int)));

    colorFlag = 0;
    paper->penColor = QColor(0, 0, 0);
    paper->brushColor = QColor(255, 255, 255);
}

// Destructor
PaintWidget::~PaintWidget()
{

}

// Слот, который вызывается, когда нажата кнопка прямоугольника, чтобы начать рисовать прямоугольник.
void PaintWidget::drawRectangle()
{
    // Устанавливает тип фигуры, которая будет обращаться на "1", что означает прямоугольник.
    this->paper->setType(1);

    // Изменение внешнего вида кнопок форм, отличающих кнопку прямоугольник.
    this->rectangle->setStyleSheet("* {  font-size: 20px; color: black; background-color: rgb(179,179,179) }");
    this->square->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->circle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->line->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->brush->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->eraser->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->fill->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
}

// Слот, который вызывается, когда нажата кнопка квадрата, чтобы начать рисовать квадрат.
void PaintWidget::drawSquare()
{
    // Устанавливает тип фигуры, которая будет обращаться на "2", что означает квадрат.
    this->paper->setType(2);

    // Изменение внешнего вида кнопок форм, отличающих квадратную кнопку.
    this->square->setStyleSheet("* {  font-size: 20px; color: black; background-color: rgb(179,179,179) }");
    this->circle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->rectangle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->line->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->brush->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->eraser->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->fill->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
}

// Слот, который вызывается, когда кнопка нажата круг, чтобы начать рисовать круг.
void PaintWidget::drawCircle()
{
    // Устанавливает тип фигуры, которая будет обращаться на "3", что означает круг.
    this->paper->setType(3);

    // Изменение внешнего вида кнопок форм, отличающих кнопку круг.
    this->circle->setStyleSheet("* {  font-size: 20px; color: black; background-color: rgb(179,179,179) }");
    this->square->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->rectangle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->line->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->brush->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->eraser->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->fill->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
}

void PaintWidget::drawLine()
{
    // Устанавливает тип фигуры, которая будет обращаться на "4", что означает линия.
    this->paper->setType(4);

    // Изменение внешнего вида кнопок форм, отличающих кнопку круг.
    this->line->setStyleSheet("* {  font-size: 20px; color: black; background-color: rgb(179,179,179) }");
    this->brush->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->circle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->square->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->rectangle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->eraser->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->fill->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
}

void PaintWidget::drawBrush()
{
    // Устанавливает тип фигуры, которая будет обращаться на "4", что означает линия.
    this->paper->setType(5);

    // Изменение внешнего вида кнопок форм, отличающих кнопку круг.
    this->brush->setStyleSheet("* {  font-size: 20px; color: black; background-color: rgb(179,179,179) }");
    this->line->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->circle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->square->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->rectangle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->eraser->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->fill->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
}

void PaintWidget::drawFill()
{
    // Устанавливает тип фигуры, которая будет обращаться на "4", что означает линия.
    this->paper->setType(6);

    // Изменение внешнего вида кнопок форм, отличающих кнопку круг.
    this->eraser->setStyleSheet("* {  font-size: 20px; color: black; background-color: rgb(179,179,179) }");
    this->line->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->circle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->square->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->rectangle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->brush->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->fill->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
}

void PaintWidget::drawEraser()
{
    // Устанавливает тип фигуры, которая будет обращаться на "4", что означает линия.
    this->paper->setType(7);

    // Изменение внешнего вида кнопок форм, отличающих кнопку круг.
    this->fill->setStyleSheet("* {  font-size: 20px; color: black; background-color: rgb(179,179,179) }");
    this->line->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->circle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->square->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->rectangle->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->brush->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
    this->eraser->setStyleSheet("* {  font-size: 20px; color: white; background-color: rgb(120,120,120) }");
}

void PaintWidget::changeSetColorPen()
{
    colorFlag = false;
    colorChangerRed->setValue(paper->penColor.red());
    colorChangerGreen->setValue(paper->penColor.green());
    colorChangerBlue->setValue(paper->penColor.blue());
    colorChangerAlpha->setValue(paper->penColor.alpha());
}

void PaintWidget::changeSetColorBrush()
{
    colorFlag = true;
    colorChangerRed->setValue(paper->brushColor.red());
    colorChangerGreen->setValue(paper->brushColor.green());
    colorChangerBlue->setValue(paper->brushColor.blue());
    colorChangerAlpha->setValue(paper->brushColor.alpha());
}

// Слот, который обновляет область, показанную с данной области, которая принадлежит к последней нарисованной форме.
void PaintWidget::changeAreaValue(double newArea)
{
    this->showingArea->setText( QString::number(newArea));
}

// Слот, который определяет, будет ли заполнена форма или нет в зависимости от состояния флажка.
void PaintWidget::drawFilled(int value)
{
    if(value == 2)
    {
        this->paper->setShapeFilled(true);

        // Uncheck the effects option.
        this->effectsOption->setChecked(false);
    }
    else this->paper->setShapeFilled(false);
}

// Слот, который определяет, будут ли составлены эффекты или нет в зависимости от состояния флажка.
void PaintWidget::enableEffects(int value)
{
    // If the box is checked.
    if(value == 2)
    {
        this->paper->setEffectsEnabled(true);

        // Uncheck the filled option.
        this->fillOption->setChecked(false);
    }
    else this->paper->setEffectsEnabled(false);
}

// Слот, который изменяет значение красного процент цвета, который будет использоваться, чтобы нарисовать форму.
void PaintWidget::changeRedColor(int redValue)
{
    // Установка значения.

    // Отображение влияния изменения на лейбле цвета тестирования.
    if (!colorFlag)
    {
        paper->penColor.setRed(redValue);
        this->colorPen->setStyleSheet("* { background-color: rgb(" +    QString::number(redValue) + "," +
                                                                        QString::number(this->paper->penColor.green()) + "," +
                                                                        QString::number(this->paper->penColor.blue()) +  "," +
                                                                        QString::number(this->paper->penColor.alpha()) + "); }");
    }else{
        paper->brushColor.setRed(redValue);
        this->colorBrush->setStyleSheet("* { background-color: rgb("  + QString::number(redValue) + "," +
                                                                        QString::number(this->paper->brushColor.green()) + "," +
                                                                        QString::number(this->paper->brushColor.blue()) +  "," +
                                                                        QString::number(this->paper->brushColor.alpha()) + "); }");
    }
}

// Слот, который изменяет значение зеленого процента от цвета, который будет использоваться, чтобы нарисовать форму.
void PaintWidget::changeGreenColor(int greenValue)
{
    // Установка значения.

    // Отображение влияния изменения на этикетке цвета тестирования.
    if (!colorFlag)
    {
        paper->penColor.setGreen(greenValue);
        this->colorPen->setStyleSheet("* { background-color: rgb(" +    QString::number(this->paper->penColor.red()) + "," +
                                                                        QString::number(greenValue) + "," +
                                                                        QString::number(this->paper->penColor.blue()) +  "," +
                                                                        QString::number(this->paper->penColor.alpha()) + "); }");
    }else{
        paper->brushColor.setGreen(greenValue);
        this->colorBrush->setStyleSheet("* { background-color: rgb("  + QString::number(this->paper->brushColor.red()) + "," +
                                                                        QString::number(greenValue) + "," +
                                                                        QString::number(this->paper->brushColor.blue()) +  "," +
                                                                        QString::number(this->paper->brushColor.alpha()) + "); }");
    }
}   // Установка значения.

// Слот, который изменяет значение синего процент цвета, который будет использоваться, чтобы нарисовать форму.
void PaintWidget::changeBlueColor(int blueValue)
{
    // Установка значения.

    // Отображение влияния изменения на этикетке цвета тестирования.
    if (!colorFlag)
    {
        paper->penColor.setBlue(blueValue);
        this->colorPen->setStyleSheet("* { background-color: rgb(" +    QString::number(this->paper->penColor.red()) + "," +
                                                                        QString::number(this->paper->penColor.green()) + "," +
                                                                        QString::number(blueValue) +  "," +
                                                                        QString::number(this->paper->penColor.alpha()) + "); }");
    }else{
        paper->brushColor.setBlue(blueValue);
        this->colorBrush->setStyleSheet("* { background-color: rgb("  + QString::number(this->paper->brushColor.red()) + "," +
                                                                        QString::number(this->paper->brushColor.green()) + "," +
                                                                        QString::number(blueValue) +  "," +
                                                                        QString::number(this->paper->brushColor.alpha()) + "); }");

    }
}

void PaintWidget::changeAlphaColor(int alphaValue)
{
    // Установка значения.

    // Отображение влияния изменения на этикетке цвета тестирования.
    if (!colorFlag)
    {
        paper->penColor.setAlpha(alphaValue);
        this->colorPen->setStyleSheet("* { background-color: rgb(" +    QString::number(this->paper->penColor.red()) + "," +
                                                                        QString::number(this->paper->penColor.green()) + "," +
                                                                        QString::number(this->paper->penColor.blue()) +  "," +
                                                                        QString::number(alphaValue) + "); }");
    }else{
        paper->brushColor.setAlpha(alphaValue);
        this->colorBrush->setStyleSheet("* { background-color: rgb("  + QString::number(this->paper->brushColor.red()) + "," +
                                                                        QString::number(this->paper->brushColor.green()) + "," +
                                                                        QString::number(this->paper->brushColor.blue()) +  "," +
                                                                        QString::number(alphaValue) + "); }");

    }
}

void PaintWidget::changePenWidth(int penWidth)
{
    // Установка значения.
    this->paper->setPenWidth(penWidth);
}
