#include "mainwindow.h"
#include "characterwidget.h"

#include <QApplication>
#include <QBoxLayout>
#include <QCheckBox>
#include <QClipboard>
#include <QDesktopWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFontComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QScreen>
#include <QScrollArea>
#include <QStatusBar>
#include <QTextStream>

Q_DECLARE_METATYPE(QFontComboBox::FontFilter)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu *fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(tr("Quit"), this, &QWidget::close);
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(tr("Show Font Info"), this, &MainWindow::showInfo);
    helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);

    QWidget *centralWidget = new QWidget;

    QLabel *filterLabel = new QLabel(tr("Filter:"));
    filterCombo = new QComboBox;
    filterCombo->addItem(tr("All"), QVariant::fromValue(QFontComboBox::AllFonts));
    filterCombo->addItem(tr("Scalable"), QVariant::fromValue(QFontComboBox::ScalableFonts));
    filterCombo->addItem(tr("Monospaced"), QVariant::fromValue(QFontComboBox::MonospacedFonts));
    filterCombo->addItem(tr("Proportional"), QVariant::fromValue(QFontComboBox::ProportionalFonts));
    filterCombo->setCurrentIndex(0);
    connect(filterCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::filterChanged);

    QLabel *fontLabel = new QLabel(tr("Font:"));
    fontCombo = new QFontComboBox;
    QLabel *sizeLabel = new QLabel(tr("Size:"));
    sizeCombo = new QComboBox;
    QLabel *styleLabel = new QLabel(tr("Style:"));
    styleCombo = new QComboBox;
    QLabel *fontMergingLabeel = new QLabel(tr("Automatic Font Merging:"));
    fontMerging = new QCheckBox;
    fontMerging->setChecked(true);

    scrollArea = new QScrollArea;
    characterWidget = new CharacterWidget;
    scrollArea->setWidget(characterWidget);

    findStyles(fontCombo->currentFont());
    findSizes(fontCombo->currentFont());

    lineEdit = new QLineEdit;
    lineEdit->setClearButtonEnabled(true);

#ifndef QT_NO_CLIPBOARD
    QPushButton *clipboardButton = new QPushButton(tr("&To clipboard"));
#endif

    connect(fontCombo, &QFontComboBox::currentFontChanged, this, &MainWindow::findStyles);
    connect(fontCombo, &QFontComboBox::currentFontChanged, this, &MainWindow::findSizes);
    connect(fontCombo, &QFontComboBox::currentFontChanged, characterWidget, &CharacterWidget::updateFont);
    connect(sizeCombo, &QComboBox::currentTextChanged, characterWidget, &CharacterWidget::updateSize);
    connect(styleCombo, &QComboBox::currentTextChanged, characterWidget, &CharacterWidget::updateStyle);

#ifndef QT_NO_CLIPBOARD
    connect(clipboardButton, &QAbstractButton::clicked, this, &MainWindow::updateClipboard);
#endif

    connect(fontMerging, &QAbstractButton::toggled, characterWidget, &CharacterWidget::updateFontMerging);

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(filterLabel);
    controlsLayout->addWidget(filterCombo, 1);
    controlsLayout->addWidget(fontLabel);
    controlsLayout->addWidget(fontCombo, 1);
    controlsLayout->addWidget(sizeLabel);
    controlsLayout->addWidget(sizeCombo, 1);
    controlsLayout->addWidget(styleLabel);
    controlsLayout->addWidget(styleCombo, 1);
    controlsLayout->addWidget(fontMergingLabeel);
    controlsLayout->addWidget(fontMerging, 1);
    controlsLayout->addStretch(1);

    QHBoxLayout *lineLayout = new QHBoxLayout;
    lineLayout->addWidget(lineEdit, 1);
    lineLayout->addSpacing(12);

#ifndef QT_NO_CLIPBOARD
    lineLayout->addWidget(clipboardButton);
#endif

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addLayout(controlsLayout);
    centralLayout->addWidget(scrollArea, 1);
    centralLayout->addSpacing(4);
    centralLayout->addLayout(lineLayout);
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
    setWindowTitle(tr("Character Map"));
}

void MainWindow::findStyles(const QFont &font)
{
    QFontDatabase fontDatabase;
    QString currentItem = styleCombo->currentText();
    styleCombo->clear();

    const QStringList styles = fontDatabase.styles(font.family());
}