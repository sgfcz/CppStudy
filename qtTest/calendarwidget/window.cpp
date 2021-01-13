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
    : QWidget(parent) {
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

void Window::createPreviewGroupBox() {
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

void Window::createGeneralOptionsGroupBox() {
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
    firstDayCombo->addItem(tr("Monday"), Qt::Monday);
    firstDayCombo->addItem(tr("Tuesday"), Qt::Tuesday);
    firstDayCombo->addItem(tr("Wednesday"), Qt::Wednesday);
    firstDayCombo->addItem(tr("Thursday"), Qt::Thursday);
    firstDayCombo->addItem(tr("Friday"), Qt::Friday);
    firstDayCombo->addItem(tr("Saturday"), Qt::Saturday);

    firstDayLabel = new QLabel(tr("Wee&k starts on:"));
    firstDayLabel->setBuddy(firstDayCombo);

    selectionModeCombo = new QComboBox;
    selectionModeCombo->addItem(tr("Single selection"), QCalendarWidget::SingleSelection);
    selectionModeCombo->addItem(tr("None"), QCalendarWidget::NoSelection);

    selectionModeLabel = new QLabel(tr("&Selection mode:"));
    selectionModeLabel->setBuddy(selectionModeCombo);

    gridCheckBox = new QCheckBox(tr("&Grid"));
    gridCheckBox->setChecked(calendar->isGridVisible());

    navigationCheckBox = new QCheckBox(tr("&Navigation bar"));
    navigationCheckBox->setChecked(true);

    horizontalHeaderCombo =new QComboBox;
    horizontalHeaderCombo->addItem(tr("Single letter day names"), QCalendarWidget::SingleLetterDayNames);
    horizontalHeaderCombo->addItem(tr("Short day names"), QCalendarWidget::ShortDayNames);
    horizontalHeaderCombo->addItem(tr("None"), QCalendarWidget::NoHorizontalHeader);
    horizontalHeaderCombo->setCurrentIndex(1);

    horizontalHeaderLabel = new QLabel(tr("&Horizontal header:"));
    horizontalHeaderLabel->setBuddy(horizontalHeaderCombo);

    verticalHeaderCombo = new QComboBox;
    verticalHeaderCombo->addItem(tr("ISO week numbers"), QCalendarWidget::ISOWeekNumbers);
    verticalHeaderCombo->addItem(tr("None"), QCalendarWidget::NoVerticalHeader);

    verticalHeaderLabel = new QLabel(tr("&Vertical header:"));
    verticalHeaderLabel->setBuddy(verticalHeaderCombo);

    connect(localeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::localeChanged);
    connect(firstDayCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::firstDayChanged);
    connect(selectionModeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::selectionModeChanged);
    connect(gridCheckBox, &QCheckBox::toggled,calendar, &QCalendarWidget::setGridVisible);
    connect(navigationCheckBox, &QCheckBox::toggled,
            calendar, &QCalendarWidget::setNavigationBarVisible);
    connect(horizontalHeaderCombo,  QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::horizontalHeaderChanged);
    connect(verticalHeaderCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::verticalHeaderChanged);
    
    QHBoxLayout *checkBoxLayout = new QHBoxLayout;
    checkBoxLayout->addWidget(gridCheckBox);
    checkBoxLayout->addStretch();
    checkBoxLayout->addWidget(navigationCheckBox);

    QGridLayout *outerLayout = new QGridLayout;
    outerLayout->addWidget(localeLabel, 0,0);
    outerLayout->addWidget(localeCombo, 0,1);
    outerLayout->addWidget(firstDayLabel, 1,0);
    outerLayout->addWidget(firstDayCombo, 1,1);
    outerLayout->addWidget(selectionModeLabel, 2,0);
    outerLayout->addWidget(selectionModeCombo, 2,1);
    outerLayout->addLayout(checkBoxLayout, 3, 0, 1, 2);
    outerLayout->addWidget(horizontalHeaderLabel, 4,0);
    outerLayout->addWidget(horizontalHeaderCombo, 4,1);
    outerLayout->addWidget(verticalHeaderLabel, 5,0);
    outerLayout->addWidget(verticalHeaderCombo, 5,1);
    generalOptionsGroupBox->setLayout(outerLayout);
    
    firstDayChanged(firstDayCombo->currentIndex());
    selectionModeChanged(selectionModeCombo->currentIndex());
    horizontalHeaderChanged(horizontalHeaderCombo->currentIndex());
    verticalHeaderChanged(verticalHeaderCombo->currentIndex());
}

void Window::createDatesGroupBox() {
    datesGroupBox = new QGroupBox(tr("Dates"));

    minimumDateEdit = new QDateEdit;
    minimumDateEdit->setDisplayFormat("MMM d yyyy");
    minimumDateEdit->setDateRange(calendar->minimumDate(), calendar->maximumDate());
    minimumDateEdit->setDate(calendar->minimumDate());

    minimumDateLabel = new QLabel(tr("&Minimum Date:"));
    minimumDateLabel->setBuddy(minimumDateEdit);

    currentDateEdit = new QDateEdit;
    currentDateEdit->setDisplayFormat("MMM d yyyy");
    currentDateEdit->setDateRange(calendar->minimumDate(), calendar->maximumDate());
    currentDateEdit->setDate(calendar->selectedDate());

    currentDateLabel = new QLabel(tr("Ma&ximum Date:"));
    currentDateLabel->setBuddy(currentDateEdit);

    maximumDateEdit = new QDateEdit;
    maximumDateEdit->setDisplayFormat("MMM d yyyy");
    maximumDateEdit->setDateRange(calendar->minimumDate(), calendar->maximumDate());
    maximumDateEdit->setDate(calendar->maximumDate());

    maximumDateLabel = new QLabel(tr("&Minimum Date:"));
    maximumDateLabel->setBuddy(maximumDateEdit);

    connect(currentDateEdit, &QDateEdit::dateChanged,
            calendar, &QCalendarWidget::setSelectedDate);
    
}