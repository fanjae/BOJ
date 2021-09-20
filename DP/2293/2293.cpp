/* 
https://www.acmicpc.net
Problem ID : 2293
DP(Dynamic Programming)
*/

#include <stdio.h>
int main(void)
{
	int dp[10005]={0};
	int coin[105]={0};
	int n,k;
	
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&coin[i]);
	}
	
	dp[0] = 1;
	for(int i=0; i<n; i++) // 동전 개수 만큼 돈다. 
	{
		for(int j=coin[i]; j<=k; j++) // i번째 coin부터 k까지 반복한다. 
		{
			// dp[n] = dp[n- 현재 동전 종류의 크기]; 
			dp[j] = dp[j] + dp[j-coin[i]];
			
		}
	}
	
	printf("%d\n",dp[k]); 
}
