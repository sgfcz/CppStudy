#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDateTime>

QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QCheckBox;
class QComboBox;
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
    Window(QWidget *parent = nullptr);
private slots:
    void localeChanged(int index);
    void firstDayChanged(int index);
    void selectionModeChanged(int index);
    void horizontalHeaderChanged(int index);
    void verticalHeaderChanged(int index);
    void selectedDateChanged();
    void minimumDateChanged(QDate date);
    void maximumDateChanged(QDate date);
    void weekdayFormatChanged();
    void weekendFormatChanged();
    void reformatHeaders();
    void reformatCalendarPage();
private:
    void createPreviewGroupBox();
    void createGeneralOptionsGroupBox();
    void createDatesGroupBox();
    void createTextFormatsGroupBox();
    QComboBox *createColorComboBox();

    QGroupBox *previewGroupBox;
    QGridLayout *previewLayout;
    QCalendarWidget *calendar;

    QGroupBox *generalOptionsGroupBox;
    QLabel *localeLabel;
    QLabel *firstDayLabel;
    QLabel *selectionModeLabel;
    QLabel *horizontalHeaderLabel;
    QLabel *verticalHeaderLabel;

    QComboBox *localeCombo;
    QComboBox *firstDayCombo;
    QComboBox *selectionModeCombo;
    QCheckBox *gridCheckBox;
    QCheckBox *navigationCheckBox;
    QComboBox *horizontalHeaderCombo;
    QComboBox *verticalHeaderCombo;

    QGroupBox *datesGroupBox;
    QLabel *currentDateLabel;
    QLabel *minimumDateLabel;
    QLabel *maximumDateLabel;
    QDateEdit *currentDateEdit;
    QDateEdit *minimumDateEdit;
    QDateEdit *maximumDateEdit;

    QGroupBox *textFormatsGroupBox;
    QLabel *weekdayColorLabel;
    QLabel *weejebdColorLabel;
    QLabel *headerTextFormatLabel;
    QDateEdit *weekdayColorEdit;
    QDateEdit *weejebdColorEdit;
    QDateEdit *headerTextFormatEdit;

    QCheckBox *firstFridayCheckBox;
    QCheckBox *mayFirstCheckBox;
};

#endif