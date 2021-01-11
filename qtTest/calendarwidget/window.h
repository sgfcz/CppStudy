#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDateTime>

QT_BEGIN_NAMESPACE
class QCalendarWidgetl;
class QCheckBox;
class QcomboBox;
class QDate;
class QDateEdit;
class QGridLayout;
class QGroupBox;
class QLabel;
QT_END_NAMESPACE

class Window: public QWidget
{
    Q_OBJECT
public:
    Window(Qwidget *parent = nullptr);
private slots:
private:
};

#endif