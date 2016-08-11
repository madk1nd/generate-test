#include <QtGui>
#include <QtWidgets>
#include <QPrinter>
#include <ctime>
#include "generatedialog.h"
#include "ui_generatedialog.h"
#include "question.h"
const qint16 SYSTEMS_COUNT = 9;
const qint16 MAX_NUMERIC_SYSTEM_RADIX = 20;

generatedialog::generatedialog(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(browseButton,SIGNAL(clicked(bool)),this,SLOT(getFullFileName()));
    connect(createButton,SIGNAL(clicked(bool)),this,SLOT(generateTest()));
    connect(aboutButton, SIGNAL(clicked(bool)),this,SLOT(messageAbout()));

    setFixedSize(sizeHint().width(),sizeHint().height());
}

void generatedialog::messageAbout()
{
    QMessageBox::about(this, tr("О программе"),
                            tr("<h3>Генератор тестов по системам счисления</h3>"
                               "<h5>Версия 1.0</h5>"
                               "<p>Программа предназначена для генерации тестов<br>"
                               "по информатике на тему <b>Системы счисления</b></p>"));
            return;
}

void generatedialog::getFullFileName()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Куда будем сохранять?"),
                                                    ".",
                                                    tr("Файлы PDF (*.pdf)"));
    lineEdit->setText(filename);
    return;
}

void generatedialog::generateTest()
{
    if (!checkErrorsIsCorrect())
    {
        return;
    }
    QString filename = lineEdit->text();
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);

    QTextDocument doc;
    QTextDocument ans;
    writeTestToFile(doc, ans);

    doc.print(&printer);
    qint16 index = filename.indexOf(QString(".pdf"));
    filename.insert(index, QString("_answers"));
    printer.setOutputFileName(filename);
    ans.print(&printer);


    QApplication::restoreOverrideCursor();
    lineEdit->clear();

    return;
}

bool generatedialog::checkErrorsIsCorrect()
{
    if (getRangeOfNumbersVariant() == 0)
    {
        QMessageBox::warning(this, tr("Что то пошло не так..."),
                                tr("<h3>Ошибка</h3><p>Пожалуйста укажите диапазон чисел!</p>"),
                                QMessageBox::Ok );
        return false;
    }
    if (systemsAreEmpty())
    {
        QMessageBox::warning(this, tr("Что то пошло не так..."),
                                tr("<h3>Ошибка</h3><p>Пожалуйста укажите хотя бы один способ перевода чисел!</p>"),
                                QMessageBox::Ok );
        return false;
    }
    if (!formulationHowCheckBox->isChecked() && !formulationWhatCheckBox->isChecked())
    {
        QMessageBox::warning(this, tr("Что то пошло не так..."),
                                tr("<h3>Ошибка</h3><p>Пожалуйста укажите хотя бы один способ формулировки вопроса!</p>"),
                                QMessageBox::Ok );
        return false;
    }
    if (lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Что то пошло не так..."),
                                tr("<h3>Ошибка</h3><p>Пожалуйста укажите место сохранения<br>файла с помощью кнопки <b>Обзор</b></p>"),
                                QMessageBox::Ok );
        return false;
    }
    return true;
}

bool generatedialog::systemsAreEmpty()
{
    qint16 result = 0;
    if(radix10And2CheckBox->isChecked()) result+=1;
    if(radix10And8CheckBox->isChecked()) result+=1;
    if(radix10And16CheckBox->isChecked()) result+=1;
    if(radix2And8CheckBox->isChecked()) result+=1;
    if(radix2And16CheckBox->isChecked()) result+=1;
    if(radix8And16CheckBox->isChecked()) result+=1;
    if(radix10AndRandomCheckBox->isChecked()) result+=1;
    if(radixRandomAnd10CheckBox->isChecked()) result+=1;
    if(radixRandomAndRandomCheckBox->isChecked()) result+=1;

    if (result == 0) return true;
    else return false;
}

void generatedialog::writeTestToFile(QTextDocument &name, QTextDocument &ans)
{
    QString str, strAns;
    QTextStream out(&str), outAns(&strAns);
    QTextCursor cursor(&name), cursorAns(&ans);
    QTextBlockFormat textFormat;
    qint16 *arrayOfAnswers = new qint16[questionSpinBox->value()];
    qint16 *arrayOfFirstRadix = new qint16[questionSpinBox->value()];
    qint16 *arrayOfLastRadix = new qint16[questionSpinBox->value()];
    qint16 *arrayOfFormulations = new qint16[questionSpinBox->value()];

    outAns<<QString("\tОтветы.\n");
    for (int j = 0; j < variantSpinBox->value(); ++j)
    {
        out<<QString("\tВариант №")<<(j+1)<<QString("\n\n");
        outAns<<QString("\n\tВариант №")<<(j+1)<<QString("\n\n");
        generateQuestionOfNumbers(arrayOfAnswers,getRangeOfNumbersVariant());
        generateFirstAndLastRadix(arrayOfFirstRadix,arrayOfLastRadix);
        generateFormulations(arrayOfFormulations);
        for (int i = 0; i < questionSpinBox->value(); ++i)
        {
            Question ques(arrayOfAnswers[i],arrayOfFirstRadix[i],arrayOfLastRadix[i],arrayOfFormulations[i]);
            out<<(i+1)<<QString(". ")<<ques.getQuestion();
            outAns<<(i+1)<<QString(") ")<<ques.getNumberOfRightAnswer()<<QString("\n");
        }
        cursorAns.insertText(strAns);
        strAns.clear();

        cursor.insertText(str);
        textFormat.setPageBreakPolicy(QTextFormat::PageBreak_AlwaysAfter);
        cursor.setBlockFormat(textFormat);
        cursor.insertBlock();
        textFormat.setPageBreakPolicy(QTextFormat::PageBreak_Auto);
        cursor.setBlockFormat(textFormat);
        str.clear();
    }

    delete arrayOfAnswers;
    delete arrayOfFirstRadix;
    delete arrayOfLastRadix;
    return;
}

qint16 generatedialog::getRangeOfNumbersVariant()
{
    qint16 result=0;
    if (easyRangeCheckBox->isChecked()) result+=1;
    if (normalRangeCheckBox->isChecked()) result+=1;
    if (hardRangeCheckBox->isChecked()) result+=1;
    return result;
}

void generatedialog::generateFormulations(qint16 *formArray)
{
    const qint16 MAX_QUESTIONS = questionSpinBox->value();
    if (formulationHowCheckBox->isChecked() && formulationWhatCheckBox->isChecked())
    {
        for (int i = 0; i < MAX_QUESTIONS; ++i)
        {
            formArray[i] = 1;
            if (i > (MAX_QUESTIONS/2)) formArray[i] = 2;
        }
    }
    else if (formulationHowCheckBox->isChecked())
        {
            for (int i = 0; i < MAX_QUESTIONS; ++i)
            {
                formArray[i] = 1;
            }
        }
        else
        {
            for (int i = 0; i < MAX_QUESTIONS; ++i)
            {
                formArray[i] = 2;
            }
        }
    return;
}

void generatedialog::generateQuestionOfNumbers(qint16 *array, qint16 variant)
{
    const qint16 MAX_QUESTIONS = questionSpinBox->value();
    qint16 minimum, range;
    if (variant == 1)
    {
        if (easyRangeCheckBox->isChecked())
        {
            minimum = 1;
            range = 256;
        }
        if (normalRangeCheckBox->isChecked())
        {
            minimum = 257;
            range = 768;
        }
        if (hardRangeCheckBox->isChecked())
        {
            minimum = 1025;
            range = 3072;
        }
        for (int i = 0; i < MAX_QUESTIONS; ++i)
        {
            array[i]=minimum + rand() % range;
        }
    }
    if (variant == 2)
    {
        if (easyRangeCheckBox->isChecked() && normalRangeCheckBox->isChecked())
        {
            minimum = 1;
            range = 256;
            for (int i = 0; i < MAX_QUESTIONS; ++i)
            {
                if (i>(MAX_QUESTIONS/2))
                {
                    minimum = 257;
                    range = 768;
                }
                array[i] = minimum + rand() % range;
            }
        }
        if (normalRangeCheckBox->isChecked() && hardRangeCheckBox->isChecked())
        {
            minimum = 257;
            range = 768;
            for (int i = 0; i < MAX_QUESTIONS; ++i)
            {
                if (i>(MAX_QUESTIONS/2))
                {
                    minimum = 1024;
                    range = 3072;
                }
                array[i] = minimum + rand() % range;
            }
        }
        if (easyRangeCheckBox->isChecked() && hardRangeCheckBox->isChecked())
        {
            minimum = 1;
            range = 256;
        }
        for (int i = 0; i < MAX_QUESTIONS; ++i)
        {
            if (i > (MAX_QUESTIONS/2))
            {
                minimum = 1025;
                range = 3072;
            }
            array[i] = minimum + rand() % range;
        }
        for (int i = 0; i < MAX_QUESTIONS; ++i)
        {
            qint16 random = rand()%MAX_QUESTIONS;
            qint16 temp = array[i];
            array[i] = array[random];
            array[random] = temp;
        }
    }
    if (variant == 3)
    {
        minimum = 1;
        range = 256;
        for (int i = 0; i < MAX_QUESTIONS; ++i)
        {
            if (i>(MAX_QUESTIONS/3))
            {
                minimum = 257;
                range = 768;
            }
            if (i>((MAX_QUESTIONS*2)/3))
            {
                minimum = 1025;
                range = 3072;
            }
            array[i] = minimum + rand() % range;
        }
        for (int i = 0; i < MAX_QUESTIONS; ++i)
        {
            qint16 random = rand()%MAX_QUESTIONS;
            qint16 temp = array[i];
            array[i] = array[random];
            array[random] = temp;
        }
    }
    deleteDulicates(array);
    return;
}

void generatedialog::deleteDulicates(qint16 *array)
{
    for (int i = 0; i < (questionSpinBox->value()-1); ++i)
    {
        for (int j = i + 1; j < questionSpinBox->value(); ++j)
        {
            if (array[i] == array[j])
            {
                bool flag = true;
                while (flag)
                {
                    array[j]+=1;
                    flag = false;
                    for (int c = 0; c < j; ++c)
                    {
                        if (array[c] == array[j]) flag = true;
                    }
                }
            }
        }
    }
    return;
}

void generatedialog::generateFirstAndLastRadix(qint16 *firstArray, qint16 *lastArray)
{
    const qint16 MAX_QUESTIONS = questionSpinBox->value();
    bool *systems = new bool[SYSTEMS_COUNT];
    getAvailableTranslationsMethods(systems);
    qint16 type = -1;
    qint16 i = 0;
    while (i < MAX_QUESTIONS)
    {
        type = findType(systems, type);
        setFirstAndLastRadixToArray(firstArray,lastArray,type,i);
        i++;
    }
    return;
}

void generatedialog::setFirstAndLastRadixToArray(qint16* firstArray, qint16* lastArray, qint16 type, qint16 count)
{
    switch (type)
    {
        case (0):
        {
            firstArray[count] = 10;
            lastArray[count] = 2;
            break;
        }
        case (1):
        {
            firstArray[count] = 10;
            lastArray[count] = 8;
            break;
        }
        case (2):
        {
            firstArray[count] = 10;
            lastArray[count] = 16;
            break;
        }
        case (3):
        {
            firstArray[count] = 2;
            lastArray[count] = 8;
            break;
        }
        case (4):
        {
            firstArray[count] = 2;
            lastArray[count] = 16;
            break;
        }
        case (5):
        {
            firstArray[count] = 8;
            lastArray[count] = 16;
            break;
        }
        case (6):
        {
            firstArray[count] = 10;
            lastArray[count] = setRandomRadix(10);
            break;
        }
        case (7):
        {
            firstArray[count] = setRandomRadix(10);
            lastArray[count] = 10;
            break;
        }
        case (8):
        {
            firstArray[count] = setRandomRadix(10);
            lastArray[count] = setRandomRadix(firstArray[count]);
            break;
        }
        default:
        {
            QMessageBox::warning(this, tr("Что то пошло не так..."),
                                tr("<h3>Ошибка</h3><p>Проблема с установкой способа перевода чисел.<br>Начальная система счисления</p>"),
                                QMessageBox::Ok );
            break;
        }
    }
    return;
}

qint16 generatedialog::setRandomRadix(qint16 wrong)
{
    qint16 result = 0;
    bool correctRadix = false;
    while (!correctRadix)
    {
        result = 3+rand()%(MAX_NUMERIC_SYSTEM_RADIX-2);
        if (result != 10 && result != 8 && result != 16 && result != wrong)
            correctRadix = true;
    }
    return result;
}

qint16 generatedialog::findType(bool *systems, qint16 type)
{
    type++;
    if (type == SYSTEMS_COUNT) type = 0;
    while (!systems[type])
    {
        type++;
        if (type == SYSTEMS_COUNT) type = 0;
    }
    return type;
}

void generatedialog::getAvailableTranslationsMethods(bool* systems)
{
    for(int i=0;i<SYSTEMS_COUNT;++i)
    {
        systems[i] = false;
    }
    if(radix10And2CheckBox->isChecked()) systems[0] = true;
    if(radix10And8CheckBox->isChecked()) systems[1] = true;
    if(radix10And16CheckBox->isChecked()) systems[2] = true;
    if(radix2And8CheckBox->isChecked()) systems[3] = true;
    if(radix2And16CheckBox->isChecked()) systems[4] = true;
    if(radix8And16CheckBox->isChecked()) systems[5] = true;
    if(radix10AndRandomCheckBox->isChecked()) systems[6] = true;
    if(radixRandomAnd10CheckBox->isChecked()) systems[7] = true;
    if(radixRandomAndRandomCheckBox->isChecked()) systems[8] = true;
    return;
}
