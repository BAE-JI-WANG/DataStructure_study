#include <stdio.h>

// 함수 호출 규약 default == _cdecl
int test(int a)
{
	printf("test(): Hello world\n");
	return 0;
}

int main(void)
{
	int (*pfTest)(int) = test;
	pfTest(5);
	return 0;
} 