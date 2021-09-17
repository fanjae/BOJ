/* 
https://www.acmicpc.net
Problem ID : 12865
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
int weight[105];
int value[105];
int dp[105][100005]; 

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d",&weight[i],&value[i]);
	}
	
	// n : 물건의 개수
	// k : 최대 무게 
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<=k; j++)
		{
			dp[i][j] = dp[i-1][j]; // dp[i][j]는 현재 무게에서 이전값까지 고려한 정보를 담아둔다. 
			if(j - weight[i] >= 0)
			{
				dp[i][j] = max(dp[i][j],value[i] + dp[i-1][j-weight[i]]);
				// 무게 j까지 고려했을때 이전 상황. 즉, (i-1)번째 상황과
				// 이번 물건을 담았을때, 이전 상황에서, 담았을 물건의 최대 가치 정보를 가져온다. 
			}
		}
	}

	printf("%d\n",dp[n][k]);
				
}
