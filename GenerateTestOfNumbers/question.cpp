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

const int MAX_ANSWERS = 4;
const int MAX_LENGHT_OF_QUESTION = 100;
const int RANGE_OF_WRONG_ANSWERS = 10;

//Конструктор класса со значениями по умолчанию
//и заданием неправильных ответов в три из четырех объектов Answer
Question::Question( int inputNumber, int inputFirstRadix,
                    int inputLastRadix, int inputType )
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
void Question::setNumberOfRightAnswer( int inputNumberOfRightAnswer ){
    numberOfRightAnswer = ( inputNumberOfRightAnswer > 0 && inputNumberOfRightAnswer < 5 ) ? inputNumberOfRightAnswer : 0 ;
}

//Задаем нужное число для операций в объекте Question
void Question::setNumber( int inputNumber ){
    number = ( inputNumber > 0 && inputNumber < 4097 ) ? inputNumber : 0 ;
}

//Задаем исходное основание системы счисления в объекте Question
void Question::setFirstRadix( int inputFirstRadix ){
    firstRadix = ( inputFirstRadix > 1 && inputFirstRadix < 33 ) ? inputFirstRadix : 0 ;
}

//Задаем конечное основание системы счисления в объекте Question
void Question::setLastRadix( int inputLastRadix ){
    lastRadix = ( inputLastRadix > 1 && inputLastRadix < 33 ) ? inputLastRadix : 0 ;
}

//Задаем значение типу формулировки вопроса
void Question::setTypeOfQuestion( int inputType ){
    typeOfQuestion = ( inputType > 0 && inputType < 4 ) ? inputType : 0;
}

//Задаем значение второму объекту Answer в объекте Question
void Question::setSecondAnswer( int inputAnswer ){
    second.setAnswer( inputAnswer );
}

//Задаем значение третьему объекту Answer в объекте Question
void Question::setThirdAnswer( int inputAnswer ){
    third.setAnswer( inputAnswer );
}

//Задаем значение четвертому объекту Answer в объекте Question
void Question::setFourthAnswer( int inputAnswer ){
    fourth.setAnswer( inputAnswer );
}

//Закрытая функция-утилита для генерации случайных неправильных ответов
int Question::generateWrongAnswer() const {

    //случайное значение в диапазоне +/-(RANGE_OF_WRONG_ANSWERS/2)
    //от правильного значения
    int result = ( number + ( rand() % ( RANGE_OF_WRONG_ANSWERS + 1 ) ) ) -( RANGE_OF_WRONG_ANSWERS / 2 );

    //обеспечивается невозможность генерации отрицательного
    //значения или значения совпадающего с правильным
    while ( result < 0 || result == number ) {
        result = ( number + ( rand() % ( RANGE_OF_WRONG_ANSWERS + 1 ) ) ) -( RANGE_OF_WRONG_ANSWERS / 2 );
    }

    return result;
}

//получить номер правильного ответа
int Question::getNumberOfRightAnswer() const {
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
    for ( int count = 0; count < MAX_ANSWERS; count++ ){
        int temp = ans[count]->getAnswer();
        int random = ( rand() % MAX_ANSWERS );
        ans[count]->setAnswer( ans[random]->getAnswer() );
        ans[random]->setAnswer( temp );
    }

    //цикл ищет правильный ответ и запоминает номер этого ответа
    //нужно для последующего вывода списка только правильных ответов
    for ( int count = 0; count < MAX_ANSWERS; count++ ){
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

//Генерируем строку для вывода вопроса
char* Question::generateQuestion() const{

    //указатель на возвращаемую строку с вопросом
    char *questionPtr = new char[MAX_LENGHT_OF_QUESTION];

    //формируем строку для вопроса типа 1
    if ( typeOfQuestion == 1 ) {
        questionPtr = strcpy( questionPtr, "Как представлено число " );
        char *symbol = new char[MAX_LENGHT_OF_QUESTION];
        itoa( number, symbol, firstRadix );
        questionPtr = strcat( questionPtr, symbol );
        questionPtr = strcat( questionPtr, " с основанием " );
        itoa( firstRadix, symbol, 10 );
        questionPtr = strcat( questionPtr, symbol );
        questionPtr = strcat( questionPtr, " в системе счисления с основанием " );
        itoa( lastRadix, symbol, 10 );
        questionPtr = strcat( questionPtr, symbol );
        questionPtr = strcat( questionPtr, " ?\n" );
    }
    else{ //иначе формируем сообщение о ошибке
        questionPtr = strcpy( questionPtr, "Неправильно задан тип вопроса!!!\n" );
    }

    //возвращаем строку с вопросом или ошибкой
    return questionPtr;
}

//вывод объекта Question целиком, через перегрузку операции "<<"
//сначала выводится сам вопрос, а затем четыре варианта ответа вперемешку
std::ostream &operator << (std::ostream &output, const Question &inputQuestion){

    //вывод вопроса
    output<<inputQuestion.generateQuestion();

    //вывод ответов
    output<<"1) "<<inputQuestion.first;
    output<<"2) "<<inputQuestion.second;
    output<<"3) "<<inputQuestion.third;
    output<<"4) "<<inputQuestion.fourth;

    //Обеспечиваем возможность сцепленных вызовов
    return output;
}

QString Question::getQuestionTypeHow() const{
    QString questionHow = generateQuestion();
    questionHow += "\n1) ";
    char symbol[MAX_LENGHT_OF_QUESTION];
    questionHow += QString(itoa(first.getAnswer(),symbol,lastRadix));
    questionHow +="\n2) ";
    questionHow +=QString(itoa(second.getAnswer(),symbol,lastRadix));
    questionHow +="\n3) ";
    questionHow +=QString(itoa(third.getAnswer(),symbol,lastRadix));
    questionHow +="\n4) ";
    questionHow +=QString(itoa(fourth.getAnswer(),symbol,lastRadix));
    /*char *questionPtr = new char[MAX_LENGHT_OF_QUESTION];
    questionPtr = strcpy( questionPtr, generateQuestion() );
    questionPtr = strcat( questionPtr, "\n1) " );
    char *symbol = new char[MAX_LENGHT_OF_QUESTION];
    char *p;
    p=itoa(first.getAnswer(),symbol,lastRadix);
    questionPtr = strcat( questionPtr, p);
    questionPtr = strcat( questionPtr, "\n2) " );
    p=itoa(second.getAnswer(),symbol,lastRadix);
    questionPtr = strcat( questionPtr, p);
    questionPtr = strcat( questionPtr, "\n3) " );
    p=itoa(third.getAnswer(),symbol,lastRadix);
    questionPtr = strcat( questionPtr, p);
    questionPtr = strcat( questionPtr, "\n4) " );
    p=itoa(fourth.getAnswer(),symbol,lastRadix);
    questionPtr = strcat( questionPtr, p);*/

    return questionHow;
}
