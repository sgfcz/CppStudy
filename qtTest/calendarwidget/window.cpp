#include "window.h"

#include <QCalendarWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLocale>
#include <QTextCharFormat>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    createPreviewGroupBox();
    createGeneralOptionsGroupBox();
    createDatesGroupBox();
    createTextFormatsGroupBox();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(previewGroupBox, 0, 0);
    layout->addWidget(generalOptionsGroupBox, 0, 1);
    layout->addWidget(datesGroupBox, 1, 0);
    layout->addWidget(textFormatsGroupBox, 1, 1);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

    previewLayout->setRowMinimumHeight(0, calendar->sizeHint().height());
    previewLayout->setColumnMinimumWidth(0, calendar->sizeHint().width());

    setWindowTitle(tr("Calendar Widget"));
}

void Window::createPreviewGroupBox()
{
    previewGroupBox = new QGroupBox(tr("Preview"));

    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible(true);

    connect(calendar, &QCalendarWidget::currentPageChanged, 
            this, &Window::reformatCalendarPage);
    
    previewLayout = new QGridLayout;
    previewLayout->addWidget(calendar, 0, 0, Qt::AlignCenter);
    previewGroupBox->setLayout(previewLayout);
}

void Window::createGeneralOptionsGroupBox()
{
    generalOptionsGroupBox = new QGroupBox(tr("General Options"));

    localeCombo = new QComboBox;
    int curLocaleIndex = -1;
    int index = 0;
    for (int _lang = QLocale::C; _lang <= QLocale::LastLanguage; ++_lang){
        QLocale::Language lang = static_cast<QLocale::Language>(_lang);
        QList<QLocale::Country> countries = QLocale::countriesForLanguage(lang);
        for (int i = 0; i < countries.count(); ++i){
            QLocale::Country country = countries.at(i);
            QString label = QLocale::languageToString(lang);
            label += QLatin1Char('/');
            label += QLocale::countryToString(country);
            QLocale locale(lang, country);
            if (this->locale().language() == lang && this->locale().country() == country)
                curLocaleIndex = index;
            localeCombo->addItem(label, locale);
        }
    }
    if (curLocaleIndex != -1)
        localeCombo->setCurrentIndex(curLocaleIndex);
    localeLabel = new QLabel(tr("&Locale"));
    localeLabel->setBuddy(localeCombo);

    firstDayCombo = new QComboBox;
    firstDayCombo->addItem(tr("Sunday"), Qt::Sunday);
}