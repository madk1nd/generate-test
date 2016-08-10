#ifndef GENERATEDIALOG_H
#define GENERATEDIALOG_H

#include <QWidget>
#include "ui_generatedialog.h"

class generatedialog : public QWidget, public Ui::generatedialog
{
    Q_OBJECT

public:
    generatedialog(QWidget *parent = 0);

private slots:
    void getFullFileName();
    void generateTest();

};

#endif // GENERATEDIALOG_H
