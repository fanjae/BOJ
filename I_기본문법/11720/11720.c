#include <stdio.h>
int main(void)
{
	int T;
	int sum = 0;
	scanf("%d",&T);
	while(T--)
	{
		int value;
		scanf("%1d",&value); // 숫자 1자리만 입력 받음.
		sum = sum + value;
	}
	printf("%d\n",sum);
}


