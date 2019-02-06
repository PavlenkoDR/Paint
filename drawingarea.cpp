#include <QPainter>
#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include "line.h"
#include "drawingarea.h"
#include <iostream>
#include <list>
#include <vector>

const int pix_width = 1000, pix_height = 1000;

// Конструктор, который строит область рисования, что мы будем рисовать в нем.
DrawingArea::DrawingArea(QWidget *parent)
        :QWidget(parent)
{
        // Создать pixmap изображение, что мы продолжаем историю составления в нем.
        this->history = new QPixmap(pix_width, pix_height);

        // Инициализировать pixmap.
        this->history->fill(Qt::transparent);

        // Создать паинтер, который рисует в pixmap.
        this->historyPainter = new QPainter(this->history);

        // Отрисовка фона.
        pen.setColor(QColor(0, 0, 0));
        cursor.setColor(QColor(0, 0, 0));
        brushColor = QColor(255, 255, 255);
        this->historyPainter->setBrush(brushColor);
        this->historyPainter->drawRect(0, 0, pix_width, pix_height);

        // Создание формы, которая будет нарисована.
        s = new Shape;

        // Установить форму незаполненной и без каких-либо эффектов в самом начале.
        shapeFilled = false;
        enabledEffects = false;
        setMouseTracking(true);

        QAction* CtrlZ = new QAction("test", this);
        CtrlZ -> setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
        connect(CtrlZ, SIGNAL(triggered()), this, SLOT(Undo()));
        addAction(CtrlZ);

        QAction* CtrlShiftZ = new QAction("test", this);
        CtrlShiftZ -> setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_Z));
        connect(CtrlShiftZ, SIGNAL(triggered()), this, SLOT(Redo()));
        addAction(CtrlShiftZ);
        this->historyVec.push_back(history->toImage());
        this->historyVec_iterator = this->historyVec.end();
        historyVec_iterator--;
        this->historyPainter->drawImage(0, 0, *historyVec_iterator);
        // Задает начальный цвет, как черный.
}

// Destructor.
DrawingArea::~DrawingArea()
{
    delete s;
    delete history;
    delete historyPainter;
}

void DrawingArea::Undo()
{
    if (historyVec_iterator != historyVec.begin())
    {
        --historyVec_iterator;
        this->historyPainter->drawImage(0, 0, *historyVec_iterator);
        this->repaint();
    }
}

void DrawingArea::Redo()
{
    std::list<QImage>::iterator end = historyVec.end();
    end--;
    if (historyVec_iterator != end){
        ++historyVec_iterator;
        this->historyPainter->drawImage(0, 0, *historyVec_iterator);
        this->repaint();
    }
}

void DrawingArea::setType(int value)
{
    this->type = value;
}

int DrawingArea::getType()
{
    return this->type;
}

void DrawingArea::setShapeFilled(bool value)
{
    this->shapeFilled = value;
    this->s->setFilled(value);
}

bool DrawingArea::isShapeFilled()
{
    return this->shapeFilled;
}

void DrawingArea::setEffectsEnabled(bool value)
{
    this->enabledEffects = value;
}

bool DrawingArea::effectsEnabled()
{
    return this->enabledEffects;
}

QPen DrawingArea::getPen()
{
    return pen;
}

QBrush DrawingArea::getBrush()
{
    return brushColor;
}

void DrawingArea::setPenWidth(int width)
{
    pen.setWidth(width);
}

void DrawingArea::setPenColor(int r, int g, int b, int a)
{
    pen.setColor(QColor(r, g, b, a));
}

void DrawingArea::setBrushColor(int r, int g, int b, int a)
{
    brushColor = QColor(r, g, b, a);
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    // Установить начальные x и y.
    this->s->setXStart(event->pos().x());
    this->s->setYStart(event->pos().y());
    this->s->setXEnd(event->pos().x());
    this->s->setYEnd(event->pos().y());
    this->trigger = 1;
    emit updateArea(0);
}

void DrawingArea::mouseMoveEvent(QMouseEvent *event)
{
    // Включаем отрисовку.
    // Установить координаты конца x и y.
    xOld = s->getXEnd();
    yOld = s->getYEnd();
    this->s->setXEnd(event->pos().x());
    this->s->setYEnd(event->pos().y());
    this->repaint();
}

int DrawingArea::Fill(int x, int y)
{
    this->historyPainter->setPen(QColor(penColor));
    std::vector<std::pair<int, int> > equal;
    unsigned left = 0, right = 0;
    QRgb stok = history->toImage().pixel(x, y);
    QRgb newColor = qRgb(pen.color().red(), pen.color().blue(), pen.color().green());
    equal.push_back(std::make_pair(x, y));
    long area = 0;
    right++;
    QImage img = history->toImage();
    //*
    x = equal.front().first;
    y = equal.front().second;
    img.setPixel(x, y, newColor);
    if (stok == newColor) return 0;
    unsigned n = 10000;
    while (right - left != 0)
    {
        x = equal[left].first;
        y = equal[left].second;
        if (x < pix_width - 1)
        if (img.pixel(x + 1, y) == stok)
        {
            if (equal.size() != n)
                equal.push_back(std::make_pair(x + 1, y));
            else
                equal[right] = std::make_pair(x + 1, y);
            img.setPixel(x + 1, y, newColor);
            right++;
            if (right == n)
                right = 0;
        }
        if (x > 0)
        if (img.pixel(x - 1, y) == stok)
        {
            if (equal.size() != n)
                equal.push_back(std::make_pair(x - 1, y));
            else
                equal[right] = std::make_pair(x - 1, y);
            img.setPixel(x - 1, y, newColor);
            right++;
            if (right == n)
                right = 0;
        }
        if (y < pix_height - 1)
        if (img.pixel(x, y + 1) == stok)
        {
            if (equal.size() != n)
                equal.push_back(std::make_pair(x, y + 1));
            else
                equal[right] = std::make_pair(x, y + 1);
            img.setPixel(x, y + 1, newColor);
            right++;
            if (right == n)
                right = 0;
        }
        if (y > 0)
        if (img.pixel(x, y - 1) == stok)
        {
            if (equal.size() != n)
                equal.push_back(std::make_pair(x, y - 1));
            else
                equal[right] = std::make_pair(x, y - 1);
            img.setPixel(x, y - 1, newColor);
            right++;
            if (right == n)
                right = 0;
        }
        left++;
        if (left == n)
            left = 0;
        area++;
    }
    this->historyPainter->drawImage(0, 0, img);
    this->historyPainter->setPen(pen);
    return area;
}


// При отпускании кнопки мыши нарисованная форма будет нарисован в истории пиксельной.
void DrawingArea::mouseReleaseEvent(QMouseEvent *event)
{
    this->trigger = 0;
    // Установка пера паинтера по выбранному цвету и толщине.
    this->historyPainter->setPen(pen);
    // Если форма заполнена, то мы не использую ручку и используем цветную кисть.
    if(shapeFilled)
        {
            pen.setColor(penColor);
            this->historyPainter->setPen(pen);
            this->historyPainter->setBrush(brushColor);
        }
    // Ксли type это 1 = прямоугольник.
    if(type == 1)
        {
            // Создаем прямоугольник, который будет отрисовываться.
            Rectangle *rect =  new Rectangle(s->getXStart(), s->getYStart(), s->getXEnd(), s->getYEnd(), s->isFilled());;

            // Рисуем в истории pixmap.
            this->historyPainter->drawRect(rect->getXStart(), rect->getYStart(), rect->getXEnd() - rect->getXStart(), rect->getYEnd() - rect->getYStart());

            // Считаем площадь и обновляем.
            emit updateArea(rect->getArea());

            // Удаляем прямоугольник, так как он уже есть в истории и больше не будет нужен.
            delete rect;
        }
    // Квадрат.
        else if(type == 2)
        {
            // Создаем квадрат.
            Square *sqr = new Square(s->getXStart(), s->getYStart(), s->getXEnd(), s->getYEnd(), s->isFilled());
            // Определяем, какой квадрат будет нарисован (верхний левый, верхний правый, нижний левый или нижний правый).

            // Нижний правый.
               if(sqr->getYEnd() > sqr->getYStart() && sqr->getXEnd() > sqr->getXStart())
                   // Рисуем в истории pixmap.
            this->historyPainter->drawRect(sqr->getXStart(), sqr->getYStart(), sqr->getXEnd() - sqr->getXStart(), sqr->getXEnd() - sqr->getXStart());

               // Верхний првый.
            else if(sqr->getYEnd() < sqr->getYStart() && sqr->getXEnd() > sqr->getXStart())
                // Draw in the history pixmap.
                this->historyPainter->drawRect(sqr->getXStart(), sqr->getYStart(), sqr->getXEnd() - sqr->getXStart(), sqr->getXStart() - sqr->getXEnd());

            // Верхний левый.
            else if(sqr->getYEnd() < sqr->getYStart() && sqr->getXEnd() < sqr->getXStart())
                // Рисуем в истории pixmap.
                this->historyPainter->drawRect(sqr->getXStart(), sqr->getYStart(),  sqr->getXEnd() - sqr->getXStart(), sqr->getXEnd() - sqr->getXStart());

            // Нижний левый.
            // Рисуем в истории pixmap.
            else this->historyPainter->drawRect(sqr->getXStart(), sqr->getYStart(), sqr->getXEnd() - sqr->getXStart(), sqr->getXStart() - sqr->getXEnd());

            // Пересчитываем площадь и обновляем.
            emit updateArea(sqr->getArea());

            // Удаляем квадрат.
            delete sqr;
        }

        // Круг.
        else if(type == 3)
        {
            // Создаем круг.
            Circle *cir = new Circle(s->getXStart(), s->getYStart(), s->getXEnd(), s->getYEnd(), s->isFilled());

            // Рисуем в истории pixmap.
            this->historyPainter->drawEllipse(QPoint(cir->getXStart(), cir->getYStart()), cir->getXEnd() - cir->getXStart(), cir->getXEnd() - cir->getXStart());

            // Пересчитываем площадь.
            emit updateArea(cir->getArea());

            // Удаляем круг.
            delete cir;
        }

    // Линия.
    else if(type == 4)
    {
        // Создаем Линию.
        Line *line = new Line(s->getXStart(), s->getYStart(), s->getXEnd(), s->getYEnd(), s->isFilled());

        // Рисуем в истории pixmap.
        this->historyPainter->drawLine(QPoint(line->getXStart(), line->getYStart()), QPoint(line->getXEnd(), line->getYEnd()));

        // Пересчитываем площадь.
        emit updateArea(line->getArea());

        // Удаляем круг.
        delete line;

    }

    // Кисть.
    else if(type == 5)
    {
        this->historyPainter->drawLine(QPoint(event->pos().x(), event->pos().y()), QPoint(event->pos().x(), event->pos().y()));
        emit updateArea(0);
    }
    else if(type == 6)
    {
        QPen tmp;
        tmp.setColor(brushColor);
        tmp.setWidth(pen.width());
        historyPainter->setPen(tmp);
        this->historyPainter->drawLine(QPoint(event->pos().x(), event->pos().y()), QPoint(event->pos().x(), event->pos().y()));
        emit updateArea(0);
    }
    else if(type == 7)
    {
        emit updateArea(Fill(event->pos().x(), event->pos().y()));
        //*/
    }
    if ((type >= 1)&&(type <=7))
    {
        //this->historyVec.pop_back();
        //this->historyVec.push_back(new QPixmap(*history));
        std::list<QImage>::iterator end = this->historyVec.end();
        end--;
        if (this->historyVec_iterator != end)
        {
            this->historyVec_iterator++;
            this->historyVec.erase(this->historyVec_iterator, this->historyVec.end());
        }
        this->historyVec.push_back(history->toImage());
        end = this->historyVec.end();
        end--;
        this->historyVec_iterator = end;
        //history = *(this->historyVec.end());
    }
        // Перерисовываем область отрисовки.
    this->repaint();

    // Сброс паинтера . Определяем ручку и обнуляем кисть (по умолчанию).
    this->historyPainter->setPen(pen);
    this->historyPainter->setBrush(Qt::NoBrush);
}

// Вызывается всякий раз, когда виджет создается, изменяется или перекрашивается.
void DrawingArea::paintEvent(QPaintEvent *event)
{
    // Создаем паинтер.
        QPainter w(this);

        // Отрисовываем бэкграунд на клеар.
        w.setBrush(brushColor);
        w.drawRect(0, 0, pix_width, pix_height);

        // Настраиваем ручку в соответствии с цветом.

        // Прописываем историю.
        w.drawPixmap(0, 0, *(this->history));

        // Настройка ручки в исторической отрисовке.
        w.setBrush(Qt::NoBrush);
        w.setPen(cursor);
        w.drawEllipse(QPoint(s->getXEnd(), s->getYEnd()), pen.width() - 1, pen.width() - 1);
        w.setPen(pen);
        w.setBrush(brushColor);

    if(this->trigger == 1)
    {
        pen.setColor(penColor);
        this->historyPainter->setPen(pen);
            // Если прорисовка включена

        // Если форма должна быть заполнена, то подрубаем заполнение
        if(shapeFilled)
            w.setBrush(brushColor);
        else
            w.setBrush(Qt::NoBrush);

        // Прямоугольник.
        if(type == 1)
        {
            // Рисуем.
            w.drawRect(s->getXStart(), s->getYStart(), s->getXEnd() - s->getXStart(), s->getYEnd() - s->getYStart());

            // Если эффекты включены.
            if(enabledEffects)
                this->historyPainter->drawRect(s->getXStart(), s->getYStart(), s->getXEnd() - s->getXStart(), s->getYEnd() - s->getYStart());
        }
        // Квадрат.
        else if(type == 2)
        {
            // Таже муть чо и сверху.

            // Нижний правый.
            if(s->getYEnd() > s->getYStart() && s->getXEnd() > s->getXStart())
            {
                w.drawRect(s->getXStart(), s->getYStart(), s->getXEnd() - s->getXStart(), s->getXEnd() - s->getXStart());

            if(enabledEffects)
                this->historyPainter->drawRect(s->getXStart(), s->getYStart(), s->getXEnd() - s->getXStart(), s->getXEnd() - s->getXStart());
            }

            // Верхний правый.
            else if(s->getYEnd() < s->getYStart() && s->getXEnd() > s->getXStart())
               {
                w.drawRect(s->getXStart(), s->getYStart(), s->getXEnd() - s->getXStart(), s->getXStart() - s->getXEnd());

                if(enabledEffects)
                    this->historyPainter->drawRect(s->getXStart(), s->getYStart(), s->getXEnd() - s->getXStart(), s->getXStart() - s->getXEnd());
            }

            // Верхний левый.
            else if(s->getYEnd() < s->getYStart() && s->getXEnd() < s->getXStart())
            {
                w.drawRect(s->getXStart(), s->getYStart(),  s->getXEnd() - s->getXStart(), s->getXEnd() - s->getXStart());

                if(enabledEffects)
                    this->historyPainter->drawRect(s->getXStart(), s->getYStart(),  s->getXEnd() - s->getXStart(), s->getXEnd() - s->getXStart());
            }

            // Нижний левый.
            else
            {
                w.drawRect(s->getXStart(), s->getYStart(), s->getXEnd() - s->getXStart(), s->getXStart() - s->getXEnd());

                if(enabledEffects)
                    this->historyPainter->drawRect(s->getXStart(), s->getYStart(), s->getXEnd() - s->getXStart(), s->getXStart() - s->getXEnd());
            }
        }

        // Круг.
        else if(type == 3)
        {
           w.drawEllipse(QPoint(s->getXStart(), s->getYStart()), s->getXEnd() - s->getXStart(), s->getXEnd() - s->getXStart());

                if(enabledEffects)
                    this->historyPainter->drawEllipse(QPoint(s->getXStart(), s->getYStart()), s->getXEnd() - s->getXStart(), s->getXEnd() - s->getXStart());
        }

        // Линия.
        else if(type == 4)
        {
           w.drawLine(QPoint(s->getXStart(), s->getYStart()), QPoint(s->getXEnd(), s->getYEnd()));

                if(enabledEffects)
                    this->historyPainter->drawLine(QPoint(s->getXStart(), s->getYStart()), QPoint(s->getXEnd(), s->getYEnd()));
        }

        // Кисть.
        else if(type == 5)
        {
            this->historyPainter->drawLine(QPoint(xOld, yOld), QPoint(s->getXEnd(), s->getYEnd()));
        }
        else if (type == 6)
        {
            QPen tmp;
            tmp.setColor(brushColor);
            tmp.setWidth(pen.width());
            historyPainter->setPen(tmp);
            this->historyPainter->drawLine(QPoint(xOld, yOld), QPoint(s->getXEnd(), s->getYEnd()));
        }
        // Отрубаем отрисовку.
        //this->trigger = 0;
    }
}

// Очищение истории и области отрисовки.
void DrawingArea::clearPixMap()
{
    this->historyPainter->setPen(QColor(255, 255, 255));
    this->historyPainter->setBrush(QColor(255, 255, 255));
    this->historyPainter->drawRect(0, 0, pix_width, pix_height);
    std::list<QImage>::iterator end = this->historyVec.end();
    end--;
    if (this->historyVec_iterator != end)
    {
        this->historyVec_iterator++;
        this->historyVec.erase(this->historyVec_iterator, this->historyVec.end());
    }
    this->historyVec.push_back(history->toImage());
    end = this->historyVec.end();
    end--;
    this->historyVec_iterator = end;
    this->repaint();
}

// Сохранение.
void DrawingArea::savePixMap()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                 "/home",
                                                 tr("Images (*.jpg)"));

    this->history->save(fileName, "jpg", 50);
}
