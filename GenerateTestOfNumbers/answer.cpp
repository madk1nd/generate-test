/***********************************************************
                Функции класса Answer
***********************************************************/

#include "answer.h"
#include <QString>
#include <iostream>

const qint16 MAX_LENGHT_OF_ANSWER = 50;

//Конструктор класса со значениями по умолчанию
Answer::Answer( qint16 inputAnswer, qint16 inputRadix ){
    setAnswer( inputAnswer );
    setRadix( inputRadix );
}

//Передаем значение числа в класс Answer
void Answer::setAnswer( qint16 inputAnswer ){
    answer = ( inputAnswer > 0 && inputAnswer < 4097 ) ? inputAnswer : 0;
}

//Получаем значение числа из класса Answer
qint16 Answer::getAnswer() const {
    return answer;
}

//Передаем значение основания системы счисления в класс Answer
void Answer::setRadix( qint16 inputRadix ){
    radix = ( inputRadix > 0 && inputRadix < 33 ) ? inputRadix : 0;
}

//Получаем значение основания системы счисления из класса Answer
qint16 Answer::getRadix() const {
    return radix;
}

//Закрытая функция-утилита для преобразования числа в заданную систему счисления
char* Answer::translateToRadix() const {
    char *numberPtr = new char[MAX_LENGHT_OF_ANSWER];
    const char *DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    qint16 number = answer;
    qint16 outputRadix = radix;
    qint16 count, lenght = 0;
    for ( count = 0; number >= outputRadix; count++ ){
        numberPtr[count] = DIGITS[number % outputRadix];
        number /= outputRadix;
        lenght++;
    }
    numberPtr[count] = DIGITS[number];
    numberPtr[count+1] = '\0';
    for ( count = 0; count < ( (lenght + 1 ) / 2 ); count++ ){
        char temp = numberPtr[count] ;
        numberPtr[count] = numberPtr[lenght - count];
        numberPtr[lenght - count] = temp;
    }
    return numberPtr;
}

//выводим на печать ответ в заданном формате
std::ostream &operator<<( std::ostream &output, const Answer &objectAnswer ){
    output<<objectAnswer.translateToRadix()<<std::endl;
    return output;
}
