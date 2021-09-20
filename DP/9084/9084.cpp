/* 
https://www.acmicpc.net
Problem ID : 9084
DP(Dynamic Programming)
*/
#include <stdio.h>
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,value;
		int coin[25]={0};
		int dp[10005]={0};
		dp[0] = 1;
		
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&coin[i]);
		}
		scanf("%d",&value);
		
		for(int i=0; i<n; i++) // 동전 개수 만큼 돈다. 
		{
			for(int j=coin[i]; j<=value; j++) // i번째 coin부터 k까지 반복한다. 
			{
				// dp[n] = dp[n- 현재 동전 종류의 크기];
				dp[j] = dp[j] + dp[j-coin[i]];
			}
		}
		printf("%d\n",dp[value]);
	}
}
	
