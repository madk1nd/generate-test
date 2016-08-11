/**************************************************************
                        Класс Answer
**************************************************************/
#ifndef ANSWER_H
#define ANSWER_H

#include <iostream>

class Answer {
    friend std::ostream &operator<<( std::ostream&, const Answer&);
    public:
        Answer( int = 0, int = 0 );
        void setAnswer( int );
        void setRadix( int );
        int getAnswer() const;
        int getRadix() const;
    private:
        char* translateToRadix() const;
        int answer;
        int radix;
};

#endif // ANSWER_H
