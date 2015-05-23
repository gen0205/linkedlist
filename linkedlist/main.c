#include <stdio.h>
#include "LinkedList.h"

// head of linkedlist.
linkedlist_data list_head;

// ファイル読み込み
int readFile(char* fileName)
{
    FILE *pFile;
    char string[512];
    
    printf("readFile() start...\n");
    
    pFile = fopen(fileName, "r");
    if(pFile == NULL)
    {
        printf("readFile() failed...\n");
        return 0;
    }
    
    // pData = &first_data;
    printf("------------------------------------------\n");
    while( fgets( string, 100, pFile ) != NULL ){
        printf( "%s", string );
        add(&list_head, string);
    }
    printf("\n------------------------------------------\n");
    
    printf("readFile finish!\n");
    return 1;
}

int main(int argc, const char * argv[])
{
    
    printf("start program...\n\n");
    
    if(create(&list_head) == 0)
    {
        printf("failed create() ...\n");
        return 0;
    }
    
    if(readFile("sample.dat") == 0)
    {
        return 0;
    }
    // 初期状態全件表示
    showAllData(&list_head);
    
    printf("\nremoveData() start\n\n");
    removeData(&list_head, 0);
    printf("\nremoveData() finish\n\n");
    
    // removeData()後全件表示
    showAllData(&list_head);
    
    printf("\nfinish program!!\n");
    return 1;
}

