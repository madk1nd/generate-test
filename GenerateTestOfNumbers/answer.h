/**************************************************************
                        Класс Answer
**************************************************************/
#ifndef ANSWER_H
#define ANSWER_H

#include <QString>
#include <iostream>

class Answer {
    friend std::ostream &operator<<( std::ostream&, const Answer&);
    public:
        Answer( qint16 = 0, qint16 = 0 );
        void setAnswer( qint16 );
        void setRadix( qint16 );
        qint16 getAnswer() const;
        qint16 getRadix() const;
    private:
        char* translateToRadix() const;
        qint16 answer;
        qint16 radix;
};

#endif // ANSWER_H
