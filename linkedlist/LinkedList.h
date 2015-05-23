#include <stdio.h>

#ifndef __linkedlist__LinkedList__
#define __linkedlist__LinkedList__

// ========================================= //
// 構造体
// リストの一つ分の要素
// ========================================= //
typedef struct _linkedlist_data
{
    int idx;
    char *pString;
    // 次の要素を示すポインタ
    struct _linkedlist_data* pNextData;
}linkedlist_data;

// ========================================= //
// リストを生成。
// 成功した場合は1を返す。
// ========================================= //
int create(linkedlist_data *pHead);

// ========================================= //
// 受け取ったリスト要素にデータを挿入する。
// 成功した場合は1を返す。
// ========================================= //
int add(linkedlist_data *pHead, char *string);

// ========================================= //
// 本関数を呼ぶ事で連結リスト内に格納されている全てのデータを表示する。
// ========================================= //
int showAllData(linkedlist_data *pHead);

// ========================================= //
// 本関数を呼ぶ事で連結リスト内の任意のインデックスに要素を挿入する。
// 処理失敗または存在しないインデックスの場合は0を返す。
// ========================================= //
int insert(linkedlist_data *pHead, char *string, int index);

// ========================================= //
// 本関数を呼ぶ事で連結リスト内の指定したインデックス番号のデータを削除する。
// 処理に失敗した場合は0を返す。
// ========================================= //
int removeData(linkedlist_data *pHead, int index);

#endif /* defined(__linkedlist__LinkedList__) */
