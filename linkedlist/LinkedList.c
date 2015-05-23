#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

int g_count = 0;

int create(linkedlist_data *pHead)
{
    linkedlist_data *pFirstData;
    
//    pHead = (linkedlist_data*) malloc(sizeof(linkedlist_data));
//    if(pHead == NULL)
//    {
//        return 0;
//    }
    pFirstData = (linkedlist_data*) malloc(sizeof(linkedlist_data));
    if(pFirstData == NULL)
    {
        return 0;
    }
    pHead -> pNextData = pFirstData;
    // data of first index
    pHead -> pNextData -> pString = NULL;
    pHead -> pNextData -> pNextData = NULL;
    return 1;
}

// ========================================= //
// 受け取ったリスト要素にデータを挿入する。
// 成功した場合は1を返す。
// ========================================= //
int add(linkedlist_data *pHead, char *pString)
{
    linkedlist_data *pCurrent = pHead->pNextData;
    // next data
    linkedlist_data *pNext;
    int length = (int) strlen(pString) + 1;
    
    while(1)
    {
        if(pCurrent -> pString == NULL)
        {
            break;
        }
        pCurrent = pCurrent -> pNextData;
    }
    pNext= (linkedlist_data*) malloc(sizeof(linkedlist_data));
    if(pNext== NULL)
    {
        return 0;
    }
    pCurrent->pString = (char*) malloc(length);
    if(pCurrent->pString == NULL)
    {
        return 0;
    }
    // set data
    pCurrent -> idx = g_count++;
    strcpy(pCurrent -> pString, pString);
    pCurrent -> pNextData = pNext;
    // next element
    pCurrent -> pNextData -> pString = NULL;
    pCurrent -> pNextData -> pNextData = NULL;
    
    return 1;
}

// ========================================= //
// 本関数を呼ぶ事で連結リスト内に格納されている全てのデータを表示する。
// ========================================= //
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
    return 1;
}

int insert(linkedlist_data *pHead, char *string, int index)
{
    
    return 0;
}

int removeData(linkedlist_data *pHead, int index)
{
    int i = 0;
    // 前方要素を保持するポインタ
    linkedlist_data *pPrevious = pHead;
    linkedlist_data *pCurrent = pHead -> pNextData;
    
    if(index < 0)
    {
        printf("failed removeData(), index value is invalid...\n");
        return 0;
    }
    
    // 削除対象の要素を取得します。
    while(1)
    {
        if(i == index)
        {
            break;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent -> pNextData;
        i++;
    }
    // 前方要素が保持している次の要素内容を置き換える。
    pPrevious -> pNextData = pCurrent -> pNextData;
    free(pCurrent);
    
    return 1;
}


