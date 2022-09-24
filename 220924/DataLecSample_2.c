#include <stdio.h>

// 재귀 호출
int test(int a)
{
	if (a <=0)
		return;
		
	printf("test(%d)\n", a);
	return test(a-1);
}

int main(void)
{ 
	test(5);
	return 0;
} 