/* 
https://www.acmicpc.net
Problem ID : 7579
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <algorithm>
using namespace std; 

int n,m;
int dp[105][10005]; // 해당 index까지 해당 cost를 담았을때 최대 바이트를 담음 
int main(void)
{
	int byte[105];
	int cost[105];
	int sum = 0;
	scanf("%d %d",&n,&m);
	
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&byte[i]);
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&cost[i]);
		sum += cost[i];
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<=sum; j++)
		{
			dp[i][j] = dp[i-1][j]; // 이전값까지 정보를 담아둠 
			if(j - cost[i] >= 0) // 해당 비용까지 담을 수 있는 경우 
			{
				dp[i][j] = max(dp[i][j],byte[i] + dp[i-1][j-cost[i]]); // 이전값까지 담을 수 있는 바이트와 새로운 앱을 비활성화 시켰을때,
				// 확보할 수 있는 byte 값중 어느쪽이 더 큰가?  
			}
		}
	}
	
	for(int i=0; i<=sum; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(dp[j][i] >= m) // m바이트 이상 확보 가능한 경우, 해당 비용이 최소 비용이 된다. 
			{
				printf("%d\n",i);
				return 0;
			}
		}
	}
}
