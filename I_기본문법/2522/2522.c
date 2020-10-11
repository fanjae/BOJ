#include <stdio.h>
int main(void)
{
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++) // n번째 줄까지는 별이 점차 늘어남
	{
		for(j=n;j>i;j--) // i번째 줄을 기준으로 n-i개의 공백 출력
		{
			printf(" ");
		}
		for(j=1;j<=i;j++) // i번째 줄을 기준으로 i개의 별 출력
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=1;i<n;i++) // n+1번째 줄부터 별이 점점 줄어듦
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
		for(j=1;j<=n-i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
			
