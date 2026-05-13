#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.setWindowTitle("Painting - Circle");
    w.resize(650, 650);
    w.show();

    return a.exec();
}
