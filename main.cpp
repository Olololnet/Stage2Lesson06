#include <iostream>
#include "clist.h"

int main()
{
    // Exercise: спроектировать класс двусвязного списка,
    // конструкторы (+конструктор копирования);
    // деструктор
    // методы добавления и удаления элемента
    // метод .at(index), возвращающий элемент по его номеру
    // оператор =

    CList* pSomeList = new CList();

    pSomeList->push_back(1);
    pSomeList->push_back(2);
    pSomeList->push_back(3);

    pSomeList->ShowAllElements();

    CList* pSomeNewList = new CList(*pSomeList);

    pSomeNewList->ShowAllElements();

    pSomeNewList->at(0) = 10;
    pSomeNewList->at(1) = 20;
    pSomeNewList->at(2) = 30;

    pSomeNewList->ShowAllElements();

    CList SomeAnotherList;
    SomeAnotherList = *pSomeNewList;
    SomeAnotherList.ShowAllElements();

    delete pSomeList;
    delete pSomeNewList;

    return 0;
}

