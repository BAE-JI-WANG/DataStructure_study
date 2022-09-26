#include <stdio.h>
#include <string.h>
#include <stdlib.h> // mac에서 malloc을 사용하기 위해선 stdlib가 필요함

typedef struct NODE {
    char szData[64];

    struct NODE* next;
} NODE;

NODE* g_pHead = NULL;

// 연결 리스트 전체 데이터 출력 함수
void PrintList(void)
{
    NODE* pHead = g_pHead;
    while (pHead != NULL)
    {
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead-> next);
        pHead = pHead->next;
    }

    putchar('\n');
}

int InsertNewNode(char* pszData)
{
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));

    strcpy(pNode->szData, pszData);

    if(g_pHead == NULL)
        g_pHead = pNode;
    else {
        pNode->next = g_pHead;
        g_pHead = pNode;
    }

    return 1;
}

void ReleaseList(void)
{
    NODE *pTmp = g_pHead;
    while(pTmp != NULL) {
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;

        printf("Delete: [%p] %s\n",pDelete, pDelete->szData);
        free(pDelete);
    }
}

int FindData(char* pszData)
{
    NODE* pTmp = g_pHead;
    while(pTmp != NULL)
    {
        if (strcmp(pTmp->szData, pszData) == 0)
            return 1;
        pTmp = pTmp->next;
    }

    return 0;
}

int DeleteData(char* pszData)
{
    NODE* pTmp = g_pHead;
    NODE* pPrev = NULL;
    while(pTmp != NULL)
    {
        if (strcmp(pTmp->szData, pszData) == 0)
        {
            printf("DeleteData(): %s\n", pTmp->szData);
            if(pPrev != NULL)
                pPrev->next = pTmp->next;
            else {
                g_pHead = pTmp->next;    
            }

            free(pTmp);
            return 1;
        }
        pPrev = pTmp;
        pTmp = pTmp->next;
    }

    return 0;
}

int main()
{
    // LIST 테스트를 위한 코드
    InsertNewNode("test01");
    PrintList();

    InsertNewNode("test02");
    PrintList();

    InsertNewNode("test03");
    PrintList();

    if(FindData("test01") == 1)
        printf("FindData(): test01 found\n");
    if(FindData("test02") == 1)
        printf("FindData(): test02 found\n");
    if(FindData("test03") == 1)
        printf("FindData(): test03 found\n");

    DeleteData("test03");
    DeleteData("test02");
    DeleteData("test01");

    ReleaseList();

    return 0;
}
