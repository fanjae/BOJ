#include <stdio.h>
int main(void)
{
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) // 1부터 n번째 줄까지 반복
	{
		for(j=1;j<=n-i;j++) // i번째 줄에 n-i개 만큼의 공백이 나와야함.
		{
			printf(" ");
		}
		for(j=1;j<=i;j++) // i번째 줄에 i개 만큼의 *이 나와야함
		{
			printf("*");
		}
		printf("\n");
	}
}
