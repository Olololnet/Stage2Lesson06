#include "clist.h"

CList::CList()
:m_pStartNode(NULL)
,m_pEndNode(NULL)
{

}

CList::CList(const CList& clBaseList)
{
    if (!clBaseList.m_pStartNode && !clBaseList.m_pEndNode)
    {
        m_pStartNode = NULL;
        m_pEndNode   = NULL;
        return;
    }

    if (clBaseList.m_pStartNode == clBaseList.m_pEndNode)
    {
        m_pStartNode = new CDoubleLinkedStruct(*clBaseList.m_pStartNode);
        m_pStartNode->m_pNextNode = NULL;
        m_pStartNode->m_pPrevNode = NULL;
        return;
    }

    m_pStartNode = new CDoubleLinkedStruct(*clBaseList.m_pStartNode);
    m_pStartNode->m_pNextNode = NULL;
    m_pStartNode->m_pPrevNode = NULL;

    CDoubleLinkedStruct* pCurNode = clBaseList.m_pStartNode->m_pNextNode;
    CDoubleLinkedStruct* pCurNewPrevElement = m_pStartNode;
    CDoubleLinkedStruct* pCurNewElement = NULL;

    while (pCurNode)
    {
        pCurNewElement = new CDoubleLinkedStruct(*pCurNode);

        if (pCurNewPrevElement)
        {
            pCurNewElement->m_pPrevNode = pCurNewPrevElement;
            pCurNewPrevElement->m_pNextNode = pCurNewElement;
        }
        else
            pCurNewElement->m_pPrevNode = NULL;

        pCurNode = pCurNode->m_pNextNode;
        pCurNewPrevElement = pCurNewElement;
    }
}

CList::~CList()
{
    CDoubleLinkedStruct* pCurFlushNode = m_pStartNode;

    while (pCurFlushNode)
    {
        CDoubleLinkedStruct* pNextNode = pCurFlushNode->m_pNextNode;

        std::cout << "remove " << pCurFlushNode->m_iData << std::endl;
        delete pCurFlushNode;

        pCurFlushNode = pNextNode;
    }
}

void CList::push_back(const int& iData)
{
    if (!m_pStartNode)
    {// no element
        CDoubleLinkedStruct* pNewElement = new CDoubleLinkedStruct(iData); // указатели 0 0
        m_pStartNode = pNewElement;
        m_pEndNode   = pNewElement;
    }
    else
    {
        if (m_pStartNode == m_pEndNode)
        {
            CDoubleLinkedStruct* pNewElement = new CDoubleLinkedStruct(iData, m_pStartNode); // указатель на предыдущий - стартовый

            m_pStartNode->m_pNextNode = pNewElement;
            m_pEndNode = pNewElement;
        }
        else
        { // есть как минимум 1 стартовый и 1 конечный
            CDoubleLinkedStruct* pNewElement = new CDoubleLinkedStruct(iData, m_pEndNode); // указатель на предыдущий - конечный текущий
            m_pEndNode->m_pNextNode = pNewElement;

            m_pEndNode = pNewElement; // обновление последнего
        }
    }
}

// удаление элементов - приравнивать стартовый к конечному, сброс начального если -1. удаление если элементов нет

void CList::RecursiveShowAllElements(CDoubleLinkedStruct* pCurNode)
{
    std::cout << pCurNode->m_iData << std::endl;

    CDoubleLinkedStruct* pNextNode = pCurNode->m_pNextNode;

    if (pNextNode)
        RecursiveShowAllElements(pNextNode);
}

void CList::ShowAllElements()
{
    if (m_pStartNode)
    {
        std::cout << "New show all elements:" << std::endl;
        RecursiveShowAllElements(m_pStartNode);
    }
}

void CList::EraseLastElement()
{
    if (!m_pStartNode) // 0
        return;

    if (m_pStartNode == m_pEndNode) // 1
    {
        delete m_pStartNode;
        m_pStartNode = NULL;
        m_pEndNode = NULL;
    }
    else // 2+
    {
        CDoubleLinkedStruct* pPrevNode = m_pEndNode->m_pPrevNode;
        delete m_pEndNode;

        m_pEndNode = pPrevNode;
        pPrevNode->m_pNextNode = NULL;
    }
}

void CList::EraseByIndex(const int& iElementNum)
{
    int iCurIndex = 0;

    CDoubleLinkedStruct* curStruct = m_pStartNode;

    if (!curStruct)
        return;

    while (curStruct)
    {
        if (iCurIndex == iElementNum)
            break;

        curStruct = curStruct->m_pNextNode;
        ++iCurIndex;
    }

    CDoubleLinkedStruct* pNextNode = curStruct->m_pNextNode;
    CDoubleLinkedStruct* pPrevNode = curStruct->m_pPrevNode;

    if (!pPrevNode)
    {
        if (!pNextNode)
        {
            m_pStartNode = NULL;
            m_pEndNode   = NULL;
        }
        else
        {
            pNextNode->m_pPrevNode = NULL;
            m_pStartNode = pNextNode;
        }
    }
    else
    {
        if (!pNextNode)
        {
            m_pEndNode = pPrevNode;
            pPrevNode->m_pNextNode = NULL;
        }
        else
        {
            pNextNode->m_pPrevNode = pPrevNode;
            pPrevNode->m_pNextNode = pNextNode;
        }
    }

    delete curStruct;
}

const int& CList::at(const int& iElementNum) const
{
    int iCurIndex = 0;

    CDoubleLinkedStruct* curStruct = m_pStartNode;

    while (curStruct)
    {
        if (iCurIndex == iElementNum)
            return curStruct->m_iData;

        curStruct = curStruct->m_pNextNode;
        ++iCurIndex;
    }
}

int& CList::at(const int& iElementNum)
{
    int iCurIndex = 0;

     CDoubleLinkedStruct* curStruct = m_pStartNode;

     while (curStruct)
     {
         if (iCurIndex == iElementNum)
             return curStruct->m_iData;

         curStruct = curStruct->m_pNextNode;
         ++iCurIndex;
     }
}

CList& CList::operator=(const CList& clBaseList)
{
    CList* pNewList = new CList(clBaseList);
    return *pNewList;
}
