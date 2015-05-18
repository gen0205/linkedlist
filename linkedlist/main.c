#include <stdio.h>
#include "LinkedList.h"

// first data of linkedlist.
linkedlist_data first_data;

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
        add(&first_data, string);
    }
    printf("\n------------------------------------------\n");
    
    printf("readFile finish!\n");
    return 1;
}

int main(int argc, const char * argv[])
{
    
    printf("start program...\n\n");
    
    if(readFile("sample.dat") == 0)
    {
        return 0;
    }
    // 初期状態全件表示
    showAllData(&first_data);
    
    printf("\nremoveData() start\n\n");
    removeData(&first_data, 0);
    printf("\nremoveData() finish\n\n");
    
    printf("デバッグ %s\n",first_data.pString);

    
    // removeData()後全件表示
    showAllData(&first_data);
    
    printf("\nfinish program!!\n");
    return 1;
}

