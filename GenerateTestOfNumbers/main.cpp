#include "generatedialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    generatedialog generate;

    generate.show();

    return app.exec();
}
