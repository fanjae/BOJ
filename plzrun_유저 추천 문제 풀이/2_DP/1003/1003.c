#include <stdio.h>
int main(void)
{
	int i,j;
	int T;
	int value;
	int dp[45][2]={{1,0},{0,1}};  
	// dp[i][0] : i번째 피보나치수가 fibonacci(0)을 호출한 횟수.
	// dp[i][1] : i번째 피보나치수가 fibonacci(1)을 호출한 횟수. 
	for(i=1; i<=45; i++)
	{
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}
	scanf("%d",&T);
	while(T--)
	{
		printf("%d %d\n",dp[n][0],dp[n][1]);
	}
	return 0; 
}
