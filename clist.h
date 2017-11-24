#ifndef CLIST_H
#define CLIST_H

#include <iostream>

struct CDoubleLinkedStruct
{
    int m_iData;
    CDoubleLinkedStruct* m_pNextNode;
    CDoubleLinkedStruct* m_pPrevNode;

    CDoubleLinkedStruct(const int& iData, CDoubleLinkedStruct* pPrevNode = NULL)
    :m_iData(iData)
    ,m_pNextNode(NULL)
    ,m_pPrevNode(pPrevNode)
    {

    }
};

class CList
{
public:
    CList();
    CList(const CList& clBaseList);
    ~CList();
    void push_back(const int& iData);
    void ShowAllElements();
    void EraseLastElement();
    void EraseStruct(CDoubleLinkedStruct* pCurStruct);
    void EraseByIndex(const int& iElementNum);

    const int& at(const size_t& uElementNum) const;
    int& at(const size_t& uElementNum);

private:
    CDoubleLinkedStruct* m_pStartNode;
    CDoubleLinkedStruct* m_pEndNode;

    void RecursiveShowAllElements(CDoubleLinkedStruct* pCurNode);
};

#endif
