#include <stdio.h>
#include <math.h>
int main(void)
{
	int su=0;
	int n;
	int i,j;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		su = (i-1)*2 + 1; // i번째 줄의 별 개수는 (i-1)*2 + 1개이다.
		for(j=i;j<=n-1;j++)
		{
			printf(" ");
		}
		for(j=1;j<=su;j++)
		{
			printf("*");
		}
		su++;
		printf("\n");
	}
}
