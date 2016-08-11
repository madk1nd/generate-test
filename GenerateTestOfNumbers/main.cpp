#include "generatedialog.h"
#include <ctime>
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication app(argc, argv);
    generatedialog generate;

    generate.show();

    return app.exec();
}
