#include <QApplication>
#include "square.h"
#include <QPushButton>
#include "paintwidget.h"

// Основной метод, где начинается программа.
int main(int argc, char *argv[])
{
    // Запуск Qt приложения с заданными аргументами, не окно, а переменная
    QApplication a(argc, argv);

    // Установить стиль приложения к Plastique.
    a.setStyle("plastique");

    // Создать новый виджет рисовалки.
    PaintWidget *w = new PaintWidget;

    // Показать виджет.
    w->show();

    // Возвращает 0, если программа завершится без каких-либо сбоев.
    return a.exec();
}
