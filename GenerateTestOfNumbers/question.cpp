/***********************************************************
                Функции класса Question
***********************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <QString>
#include "Question.h"
#include "answer.h"

const qint16 MAX_ANSWERS = 4;
const qint16 MAX_LENGHT_OF_QUESTION = 100;
const qint16 RANGE_OF_WRONG_ANSWERS = 20;

//Конструктор класса со значениями по умолчанию
//и заданием неправильных ответов в три из четырех объектов Answer
Question::Question( qint16 inputNumber, qint16 inputFirstRadix,
                    qint16 inputLastRadix, qint16 inputType )
    : 	first 	( inputNumber, inputLastRadix ),
        second 	( inputNumber, inputLastRadix ),
        third	( inputNumber, inputLastRadix ),
        fourth 	( inputNumber, inputLastRadix ) {
    setNumber( inputNumber );
    setFirstRadix( inputFirstRadix );
    setLastRadix( inputLastRadix );
    setTypeOfQuestion( inputType );

    //неправильные ответы
    setSecondAnswer( generateWrongAnswer() );
    setThirdAnswer( generateWrongAnswer() );
    setFourthAnswer( generateWrongAnswer() );

    //Избавляемся от повторяющихся ответов
    changeRepeatedWrongAnswers();

    //номер правильного ответа
    setNumberOfRightAnswer(1);

    //перемешиваем ответы(меняем местами)
    shuffleAnswers();
}

//Задаем значение номеру правильного ответа
void Question::setNumberOfRightAnswer( qint16 inputNumberOfRightAnswer ){
    numberOfRightAnswer = ( inputNumberOfRightAnswer > 0 && inputNumberOfRightAnswer < 5 ) ? inputNumberOfRightAnswer : 0 ;
}

//Задаем нужное число для операций в объекте Question
void Question::setNumber( qint16 inputNumber ){
    number = ( inputNumber > 0 && inputNumber < 4097 ) ? inputNumber : 0 ;
}

//Задаем исходное основание системы счисления в объекте Question
void Question::setFirstRadix( qint16 inputFirstRadix ){
    firstRadix = ( inputFirstRadix > 1 && inputFirstRadix < 33 ) ? inputFirstRadix : 0 ;
}

//Задаем конечное основание системы счисления в объекте Question
void Question::setLastRadix( qint16 inputLastRadix ){
    lastRadix = ( inputLastRadix > 1 && inputLastRadix < 33 ) ? inputLastRadix : 0 ;
}

//Задаем значение типу формулировки вопроса
void Question::setTypeOfQuestion( qint16 inputType ){
    typeOfQuestion = ( inputType > 0 && inputType < 4 ) ? inputType : 0;
}

//Задаем значение второму объекту Answer в объекте Question
void Question::setSecondAnswer( qint16 inputAnswer ){
    second.setAnswer( inputAnswer );
}

//Задаем значение третьему объекту Answer в объекте Question
void Question::setThirdAnswer( qint16 inputAnswer ){
    third.setAnswer( inputAnswer );
}

//Задаем значение четвертому объекту Answer в объекте Question
void Question::setFourthAnswer( qint16 inputAnswer ){
    fourth.setAnswer( inputAnswer );
}

//Закрытая функция-утилита для генерации случайных неправильных ответов
qint16 Question::generateWrongAnswer() const {

    //случайное значение в диапазоне +/-(RANGE_OF_WRONG_ANSWERS/2)
    //от правильного значения
    qint16 result = ( number + ( rand() % ( RANGE_OF_WRONG_ANSWERS + 1 ) ) ) -( RANGE_OF_WRONG_ANSWERS / 2 );

    //обеспечивается невозможность генерации отрицательного
    //значения или значения совпадающего с правильным
    while ( result < 0 || result == number ) {
        result = ( number + ( rand() % ( RANGE_OF_WRONG_ANSWERS + 1 ) ) ) -( RANGE_OF_WRONG_ANSWERS / 2 );
    }

    return result;
}

//получить номер правильного ответа
qint16 Question::getNumberOfRightAnswer() const {
    return numberOfRightAnswer;
}

//Закрытая функция-утилита перемешивает ответы
//(меняет местами закрытые данные объектов Answer)
//а также ищет и записывает номер правильного ответа
//в элемент numberOfRightAnswer
void Question::shuffleAnswers() {

    //Создаем массив из ответов и инициализируем его элементы
    Answer *ans[MAX_ANSWERS];
    ans[0]=&first;
    ans[1]=&second;
    ans[2]=&third;
    ans[3]=&fourth;

    //цикл осуществляет перемешивание данных(ответов) в массиве
    for ( qint16 count = 0; count < MAX_ANSWERS; count++ ){
        qint16 temp = ans[count]->getAnswer();
        qint16 random = ( rand() % MAX_ANSWERS );
        ans[count]->setAnswer( ans[random]->getAnswer() );
        ans[random]->setAnswer( temp );
    }

    //цикл ищет правильный ответ и запоминает номер этого ответа
    //нужно для последующего вывода списка только правильных ответов
    for ( qint16 count = 0; count < MAX_ANSWERS; count++ ){
        if ( ans[count]->getAnswer() == number ) {
            numberOfRightAnswer = count + 1;
            return;
        }
    }
}

//Закрытая функция утилита изменяет значение ответа
//если он повторяется
void Question::changeRepeatedWrongAnswers(){

    //проверяем не повторяется ли второй ответ с другими
    //неправильными или с правильным
    while ( second.getAnswer() == third.getAnswer() || second.getAnswer() == fourth.getAnswer() || second.getAnswer() == number ) {
        second.setAnswer( second.getAnswer() + 1 );
    }

    //проверяем не повторяется ли третий ответ с другими
    //неправильными или с правильным
    while ( third.getAnswer() == second.getAnswer() || third.getAnswer() == fourth.getAnswer() || third.getAnswer() == number ) {
        third.setAnswer( third.getAnswer() + 1 );
    }

    //четвертый ответ не проверяется так как он не может
    //повторяться ни с неправильными (после выполненных выше проверок)
    //ни с правильным (обеспечено в функции generateWrongAnswer() )
}

QString Question::getQuestion() const{
    QString questionHow;
    QString answers;
    if (typeOfQuestion == 1)
    {
        questionHow = QString("Как представлено число %1 с основанием %2 "
                            "в системе счисления с основанием %3?\n")
                            .arg(number,0,firstRadix)
                            .arg(firstRadix)
                            .arg(lastRadix);
        answers = QString("   1) %1\n   2) %2\n   3) %3\n   4) %4\n")
                            .arg(first.getAnswer(),0,lastRadix)
                            .arg(second.getAnswer(),0,lastRadix)
                            .arg(third.getAnswer(),0,lastRadix)
                            .arg(fourth.getAnswer(),0,lastRadix);
        questionHow.append(answers);
    }
    if (typeOfQuestion == 2)
    {
        questionHow = QString("Чему равно число %1 с основанием %2 "
                            "в системе счисления с основанием %3?\n")
                            .arg(number,0,firstRadix)
                            .arg(firstRadix)
                            .arg(lastRadix);
        QString answers;
        answers = QString("   1) %1\n   2) %2\n   3) %3\n   4) %4\n")
                            .arg(first.getAnswer(),0,lastRadix)
                            .arg(second.getAnswer(),0,lastRadix)
                            .arg(third.getAnswer(),0,lastRadix)
                            .arg(fourth.getAnswer(),0,lastRadix);
        questionHow.append(answers);
    }

    return questionHow;
}
