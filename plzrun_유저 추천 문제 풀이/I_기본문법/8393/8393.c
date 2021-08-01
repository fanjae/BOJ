#include <stdio.h>
int main(void)
{
	int i,n;
	int sum = 0;
	scanf("%d",&n);
	
	for(int i = 1; i <= n; i++)
	{
		sum = sum + i; // (sum + i)가 먼저 연산되어, sum에 대입됨. 
	}
	printf("%d",sum);
}
