#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=2*n-1; i++) // 1부터 2*n-1 줄 만큼 반복
	{
		if(i <= n) // n까지는 별의 개수가 점차 많아짐 
		{
			for(int j=1; j<=2*n; j++) 
			{
				if(j <= i || j > 2*n-i)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
		}
		else // n+1 이후 부터는 별의 개수가 점차 줄어듬
		{
			for(int j=1; j<=2*n; j++)
			{
				if(j > 2 * n - i && j <= i) 
				{
					printf(" ");
				}
				else
				{
					printf("*");
				}
			}
		}		
		printf("\n");
	}
}
