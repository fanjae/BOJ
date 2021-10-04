/* 
https://www.acmicpc.net
Problem ID : 2688
DP(Dynamic Programming)
*/

#include <stdio.h>
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		long long int ans = 0;
		long long int dp[1005][15]={0};
		scanf("%d",&n);
		
		// dp[i][j] = i번째자리에 j숫자까지 들어갈 수 있는 경우의 수 
		// 0을 기준으로 2자리 수의 줄어들지 않는 수는
		// 00,01,02....09 : 이는 이전까지의 수 0부터 9까지 더한 것과 동일.
		// 1을 기준으로 2자리 수의 줄어들지 않는 수는
		// 11,12,13...19 : 이는 이전까즈이 수 1부터 9까지 더한 것과 동ㅇ;ㄹ
		
		// 일반화 dp[i][j] = dp[i-1][j] + dp[i-1][j+1] ~ dp[i-1][9];  
		for(int i=0; i<=9; i++)
		{
			dp[1][i] = 1;
		}
		for(int i=2; i<=n; i++)
		{
			for(int j=0; j<=9; j++)
			{
				for(int k=j; k<=9; k++)
				{
					dp[i][j] += dp[i-1][k];	
				}
			}
		}

		for(int i=0; i<=9; i++)
		{
			ans += dp[n][i];
		}
		printf("%lld\n",ans);
	}
}
