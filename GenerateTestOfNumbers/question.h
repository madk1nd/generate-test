/**************************************************************
                        Класс Question
    Класс формирует вопрос и четыре варианта ответа,
    только один из которых правильный.

    Входных параметра четыре:
    само число, которое нужно перевести в др. систему счисления
    начальная система счисления(2-32)
    конечная система счисления(2-32)
    тип формулировки вопроса(1-4)

    Создан для программы генерации тестов по информатике
    на тему системы счисления.
**************************************************************/
#ifndef QUESTION_H
#define QUESTION_H
#include "answer.h"
#include <QString>

class Question {
    public:
        Question( qint16 = 0, qint16 = 0, qint16 = 0, qint16 = 0 );
        void setNumber( qint16 );
        void setFirstRadix( qint16 );
        void setLastRadix( qint16 );
        void setSecondAnswer( qint16 );
        void setThirdAnswer( qint16 );
        void setFourthAnswer( qint16 );
        void setTypeOfQuestion ( qint16 );
        void setNumberOfRightAnswer( qint16 );
        qint16 getNumber() const;
        qint16 getFirstRadix() const;
        qint16 getLastRadix() const;
        qint16 getNumberOfRightAnswer() const;
        QString getQuestion();
    private:
        qint16 generateWrongAnswer() const;
        QString translateToRussian(bool variant);
        void shuffleAnswers();
        void changeRepeatedWrongAnswers();
        qint16 number;
        qint16 firstRadix;
        qint16 lastRadix;
        qint16 numberOfRightAnswer;
        qint16 typeOfQuestion;
        Answer first;
        Answer second;
        Answer third;
        Answer fourth;
};

#endif // QUESTION_H
