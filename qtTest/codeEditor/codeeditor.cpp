#include <QtWidgets>

#include "codeeditor.h"

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect, int)), this, SLOT(updateLineNumberAreaWidth(QRect, int)));
    connect(this, SIGNAL(cursorPositionChanged(int)), this, SLOT(highlighCurrentLine()));

    updateLineNumberAreaWidth(0);
    highlighCurrentLine();
}

int CodeEditor::lineNumberAreaWidth()
{

}

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{

}

void CodeEditor::resizeEvent(QResizeEvent *e)
{

}

void CodeEditor::highlighCurrentLine()
{

}

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{

}

