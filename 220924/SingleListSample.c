#include <stdio.h>

struct NODE {
    int nData; // 관리될 데이터

    struct NODE* next; // 데이터 관리를 위한 포인터
} NODE;

int main()
{
    struct NODE list[5] = {0};

    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    list[3].next = &list[4];
    list[4].next = 0;

    list[0].nData = 100;
    list[1].nData = 200;
    list[2].nData = 300;
    list[3].nData = 400;
    list[4].nData = 500;

    for(int i = 0; i < 5; ++i)
        printf("list[%d]: %d\n", i, list[i].nData);

    struct NODE* pTmp = &list[0];
    
    while (pTmp != NULL)
    {
        printf("%p: %d\n", pTmp, pTmp->nData);
        pTmp = pTmp-> next;
    }

    return 0;
}