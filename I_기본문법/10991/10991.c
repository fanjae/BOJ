#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n-i; j++) // i번째 줄에 대해서 n-i개의 공백 출력
		{
			printf(" ");
		}
		for(int j=1; j<=i; j++) // i번째 줄에 대해 i개의 별 출력 및 띄어쓰기 한개 
		{
			printf("* ");
		}
		printf("\n");
	}
}
