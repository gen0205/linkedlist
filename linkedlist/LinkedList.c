#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

int g_count = 0;

// ========================================= //
// 受け取ったリスト要素にデータを挿入する。
// 成功した場合は1を返す。
// ========================================= //
int add(linkedlist_data *pData, char *pString)
{
    // next data
    linkedlist_data *l_pNextData;
    
    if(pData->pString != NULL)
    {
        // 既にデータが格納されていた場合は次の連結データに格納
        add(pData->pNextData, pString);
        return 1;
    }
    
    l_pNextData= (linkedlist_data*) malloc(sizeof(linkedlist_data));
    if(l_pNextData== NULL)
    {
        return 0;
    }
    
    pData->pString = (char*) malloc(sizeof(pString));
    if(pData->pString == NULL)
    {
        return 0;
    }
    
    // set data
    pData->idx = g_count++;
    strcpy(pData->pString, pString);
    pData->pNextData = l_pNextData;
    
    return 1;
}

// ========================================= //
// 本関数を呼ぶ事で連結リスト内に格納されている全てのデータを表示する。
// ========================================= //
int showAllData(linkedlist_data *pFirstData)
{
    printf("showAllData() start...\n");
    linkedlist_data *l_pData = pFirstData;

    while(1)
    {
        printf("\n========================================\n");
        printf("pData -> %p \n", l_pData);
        printf("index -> %d , string -> %s \n", l_pData->idx, l_pData->pString);
        printf("pNextData -> %p \n", l_pData->pNextData);
        printf("========================================\n");

        if(l_pData->pNextData->pString == NULL)
        {
            break;
        }
        l_pData = l_pData->pNextData;
    }
    printf("\nshowAllData() finish!\n");
    return 1;
}

int insert(linkedlist_data *pFirstData, char *string, int index)
{
    
    return 0;
}

int removeData(linkedlist_data *pFirstData, int index)
{
    int i = 0;
    // 前方要素を保持するポインタ
    linkedlist_data *l_pPreviousData = NULL;
    linkedlist_data *l_pData = pFirstData;
    
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
        l_pPreviousData = l_pData;
        l_pData = l_pData -> pNextData;
        i++;
    }
    
    // 前方データがNULLということはリストの先頭データを指す。
    if(l_pPreviousData == NULL)
    {
        // 先頭要素をその次の要素に上書きする。
        pFirstData = pFirstData->pNextData;
        printf("デバッグ %s\n",pFirstData->pString);
        return 1;
    }
    // 前方要素が保持している次の要素内容を置き換える。
    l_pPreviousData->pNextData = l_pData->pNextData;
    free(l_pData);
    
    return 1;
}


