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
    friend std::ostream &operator<<( std::ostream&, const Question& );
    public:
        Question( int = 0, int = 0, int = 0, int = 0 );
        void setNumber( int );
        void setFirstRadix( int );
        void setLastRadix( int );
        void setSecondAnswer( int );
        void setThirdAnswer( int );
        void setFourthAnswer( int );
        void setTypeOfQuestion ( int );
        void setNumberOfRightAnswer( int );
        int getNumber() const;
        int getFirstRadix() const;
        int getLastRadix() const;
        int getNumberOfRightAnswer() const;
        QString getQuestionTypeHow() const;
    private:
        char* generateQuestion() const;
        int generateWrongAnswer() const;
        void shuffleAnswers();
        void changeRepeatedWrongAnswers();
        int number;
        int firstRadix;
        int lastRadix;
        int numberOfRightAnswer;
        int typeOfQuestion;
        Answer first;
        Answer second;
        Answer third;
        Answer fourth;
};

#endif // QUESTION_H
