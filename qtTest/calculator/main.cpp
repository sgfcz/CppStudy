#include <QApplication>

#include "calculator.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_ANDROID
    QApplication::setAttribute(Qt::AA_EnableGighDpiScaling);
#endif
    QApplication app(argc, argv);
    Calculator calc;
    calc.show();
    return app.exec();
}