#include <QApplication>

#include "window.h"

int main(int argv, char *args[])
{
    QApplication app(argv,args);
    Window window;
    window.show();
    return app.exec();
}