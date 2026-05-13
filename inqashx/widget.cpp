#include "widget.h"
#include <QPainter>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent), x(0), y(0), d(0), shouldDraw(false)
{
    this->setFixedSize(650, 650);
    this->setWindowTitle("Painting - Circle");

    xEdit = new QLineEdit(this);
    yEdit = new QLineEdit(this);
    dEdit = new QLineEdit(this);

    xEdit->setPlaceholderText("X");
    yEdit->setPlaceholderText("Y");
    dEdit->setPlaceholderText("Diameter");

    xEdit->setFixedWidth(50);
    yEdit->setFixedWidth(50);
    dEdit->setFixedWidth(80);

    button = new QPushButton("Draw Circle", this);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(xEdit);
    topLayout->addWidget(yEdit);
    topLayout->addWidget(dEdit);
    topLayout->addWidget(button);
    topLayout->addStretch();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
    setLayout(mainLayout);

    connect(button, &QPushButton::clicked, this, &Widget::drawCircle);
}

void Widget::drawCircle() {
    x = xEdit->text().toInt();
    y = yEdit->text().toInt();
    d = dEdit->text().toInt();
    shouldDraw = true;
    update();
}

void Widget::paintEvent(QPaintEvent *) {
    if (!shouldDraw) return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    QBrush brush(Qt::blue, Qt::CrossPattern);
    painter.setBrush(brush);

    painter.drawEllipse(x, y, d, d);

    painter.setBrush(Qt::NoBrush);
    painter.drawLine(x, y + d / 2, x + d, y + d / 2);
}
