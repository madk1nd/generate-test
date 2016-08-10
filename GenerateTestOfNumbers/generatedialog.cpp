#include <QtGui>
#include <QtWidgets>
#include <QPrinter>
#include "generatedialog.h"
#include "ui_generatedialog.h"

generatedialog::generatedialog(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(browseButton,SIGNAL(clicked(bool)),this,SLOT(getFullFileName()));
    connect(createButton,SIGNAL(clicked(bool)),this,SLOT(generateTest()));

    setFixedSize(sizeHint().width(),sizeHint().height());
}

void generatedialog::getFullFileName()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Куда будем сохранять?"),
                                                    ".",
                                                    tr("Файлы PDF (*.pdf)"));
    lineEdit->setText(filename);
}

void generatedialog::generateTest()
{
    if (lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Что то пошло не так..."),
                                tr("<h1>Ошибка</h1><p>Пожалуйста укажите место сохранения<br>файла с помощью кнопки <b>Обзор</b></p>"),
                                QMessageBox::Ok );
        return;
    }
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(lineEdit->text());

    QTextDocument doc;
    doc.setHtml("<h1>Hello, World!</h1>\n<p>Lorem ipsum dolor sit amet, consectitur adipisci elit.</p>");
    doc.print(&printer);
    QApplication::restoreOverrideCursor();
    lineEdit->clear();
}
