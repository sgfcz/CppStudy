#include "calculator.h"
#include "button.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QtMath>

Calculator::Calculator(QWidget *parent)
    :QWidget(parent), sumInMemory(0.0), sumSoFar(0.0)
    ,factorSoFar(0.0), waitngForOperand(true)
{
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    for (int i = 0; i < NumDigitButtons; ++i)
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
}

void Calculator::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue = clickedButton->text().toInt();
    if(display->text() == "0" && digitValue == 0.0)
        return;
    
    if(waitngForOperand)
    {
        display->clear();
        waitngForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
}

Button *Calculator::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}