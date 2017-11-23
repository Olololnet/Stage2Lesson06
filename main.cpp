#include <iostream>
#include "clist.h"

int main()
{
    // Exercise: спроектировать класс двусвязного списка,
    // конструкторы (+конструктор копирования);
    // деструктор
    // методы добавления и удаления элемента
    // метод .at(index), возвращающий элемент по его номеру
    // operator=

    CList cSomeList;

    cSomeList.push_back(1);
    cSomeList.push_back(2);
    cSomeList.push_back(3);

    cSomeList.ShowAllElements();

    CList cSomeNewList(cSomeList);

    cSomeNewList.ShowAllElements();

    cSomeNewList.at(0) = 10;
    cSomeNewList.at(1) = 20;
    cSomeNewList.at(2) = 30;

    cSomeNewList.ShowAllElements();

    CList SomeAnotherList;
    SomeAnotherList = cSomeNewList;
    SomeAnotherList.ShowAllElements();

    return 0;
}
