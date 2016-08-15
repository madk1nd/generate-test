#ifndef GENERATEDIALOG_H
#define GENERATEDIALOG_H

#include <QWidget>
#include "ui_generatedialog.h"

class generatedialog : public QWidget, public Ui::generatedialog
{
    Q_OBJECT

public:
    generatedialog(QWidget *parent = 0);

private:
    void writeTestToFile(QTextDocument &name, QTextDocument &ans);
    bool checkErrorsIsCorrect();
    bool systemsAreEmpty();
    qint16 getRangeOfNumbersVariant();
    void generateNumbers(qint16* array, qint16 variant);
    void deleteDulicates(qint16* array);
    void getAvailableTranslationsMethods(bool* systems);
    qint16 findType(bool* systems, qint16 type);
    qint16 setRandomRadix(qint16 wrong);
    void setFirstAndLastRadixToArray(qint16* fistArray, qint16* lastArray, qint16 type, qint16 count);
    void generateFirstAndLastRadix(qint16* firstArray, qint16* lastArray);
    void generateFormulations(qint16 *formArray);

private slots:
    void getFullFileName();
    void generateTest();
    void messageAbout();

};

#endif // GENERATEDIALOG_H
