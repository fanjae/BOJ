#include <stdio.h>
int main(void)
{
	int i,n;
	scanf("%d",&n);

	for(i = 1; i <= 9; i++) // 1단 부터 9단 까지 출력
	{
		printf("%d * %d = %d\n",n,i,n*i);
	}
	return 0;
}
