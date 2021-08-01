#include <stdio.h>
int dp[1005];
int main(void)
{
	int i,n;
	scanf("%d",&data[i]);
	
	dp[1] = 1;
	dp[2] = 1;

	// dp[N] : 2*n 직사각형 1*2, 2*1 타일로 채우는 방법
	// n-1 : 마지막 조각을 2x1 사각형으로 채운 방법
	// n-2 : 마지막 조각을 1x2 사각형으로 채운 방법
	
	for(i = 3; i <= n; i++)
	{
		dp[i] = (dp[i-1] + dp[i-2]) % 10007;
	}
	printf("%d\n",dp[n]);
}
