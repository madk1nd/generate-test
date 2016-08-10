#include <QtGui>
#include <QtWidgets>
#include "generatedialog.h"
#include "ui_generatedialog.h"

generatedialog::generatedialog(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(browseButton,SIGNAL(clicked(bool)),this,SLOT(getFullFileName()));

    setFixedSize(sizeHint().width(),sizeHint().height());
}

void generatedialog::getFullFileName()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Куда будем сохранять?"),
                                                    ".",
                                                    tr("Файлы PDF (*.pdf)"));
    if (filename.isEmpty()) filename = ".";
    lineEdit->setText(filename);
}
