#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

int setIndex(linkedlist_data *pHead);

// ========================================= //
// set index of elements
// note that this function must be called after list controll (add,insert,remove...)
// ========================================= //
int setIndex(linkedlist_data *pHead)
{
    linkedlist_data *pCurrent = pHead -> pNextData;
    int indexNumber = 0;
    while(1)
    {
        pCurrent -> idx = indexNumber;
        if(pCurrent -> pNextData == NULL)
        {
            break;
        }
        indexNumber++;
        pCurrent = pCurrent -> pNextData;
    }
    return SUCCESS;
}

int create(linkedlist_data *pHead)
{
    linkedlist_data *pFirstData;

    pFirstData = (linkedlist_data*) malloc(sizeof(linkedlist_data));
    if(pFirstData == NULL)
    {
        return FAILURE;
    }
    pHead -> pNextData = pFirstData;
    // data of first index
    pHead -> idx = 0;
    pHead -> pNextData -> pString = NULL;
    pHead -> pNextData -> pNextData = NULL;
    return SUCCESS;
}

int add(linkedlist_data *pHead, char *pString)
{
    linkedlist_data *pCurrent = pHead->pNextData;
    // next data
    linkedlist_data *pNext;
    int length = (int) strlen(pString) + 1;
    int index = 0;
    
    while(1)
    {
        if(pCurrent -> pString == NULL)
        {
            break;
        }
        pCurrent = pCurrent -> pNextData;
        index++;
    }
    pNext= (linkedlist_data*) malloc(sizeof(linkedlist_data));
    if(pNext== NULL)
    {
        return FAILURE;
    }
    pCurrent->pString = (char*) malloc(length);
    if(pCurrent->pString == NULL)
    {
        return FAILURE;
    }
    // set data
    pCurrent -> idx = index;
    strcpy(pCurrent -> pString, pString);
    pCurrent -> pNextData = pNext;
    // next element
    pCurrent -> pNextData -> pString = NULL;
    pCurrent -> pNextData -> pNextData = NULL;
    
    return SUCCESS;
}

int showAllData(linkedlist_data *pHead)
{
    printf("showAllData() start...\n");
    linkedlist_data *pCurrent = pHead -> pNextData;
    
    while(1)
    {
        printf("\n========================================\n");
        printf("pData -> %p \n", pCurrent);
        printf("index -> %d , string -> %s \n", pCurrent -> idx, pCurrent -> pString);
        printf("pNextData -> %p \n", pCurrent -> pNextData);
        printf("========================================\n");
        
        if(pCurrent -> pNextData -> pString == NULL)
        {
            break;
        }
        pCurrent = pCurrent -> pNextData;
    }
    printf("\nshowAllData() finish!\n");
    return SUCCESS;
}

int insert(linkedlist_data *pHead, char *string, int index)
{
    
    return FAILURE;
}

int removeData(linkedlist_data *pHead, int index)
{
    // 前方要素を保持するポインタ
    linkedlist_data *pPrevious = pHead;
    linkedlist_data *pCurrent = pHead -> pNextData;
    if(index < 0)
    {
        printf("failed removeData(), index value is invalid...\n");
        return FAILURE;
    }
    // 削除対象の要素を取得します。
    while(1)
    {
        if(pCurrent -> idx == index)
        {
            break;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent -> pNextData;
    }
    // 前方要素が保持している次の要素内容を置き換える。
    pPrevious -> pNextData = pCurrent -> pNextData;
    free(pCurrent);
    setIndex(pHead);
    return SUCCESS;
}


