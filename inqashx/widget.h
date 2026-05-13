#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void drawCircle();

private:
    QLineEdit *xEdit;
    QLineEdit *yEdit;
    QLineEdit *dEdit;
    QPushButton *button;

    int x, y, d;
    bool shouldDraw;
};

#endif // WIDGET_H
