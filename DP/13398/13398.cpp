/* 
https://www.acmicpc.net
Problem ID : 13398
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[100005][2];
int data[100005];
int n;
int ans;
int main(void)
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&data[i]);
	}

	dp[0][0] = data[0]; // 한 개를 제거하지 않고 i번째까지의 가장 큰 연속합 
	dp[0][1] = 0; // 한 개를 제거하고 i번째까지의 가장 큰 연속 값  
	ans = data[0]; // 1개 이상의 수는 선택되어야 한다.  
	
	for(int i=1; i<n; i++)
	{
		dp[i][0] = max(data[i],dp[i-1][0] + data[i]); // 제외 안하고 계속 뽑을때는 data[i]와 이전부터 더한 값 중 더 큰 값을 가져가는게 좋다,  
		dp[i][1] = max(dp[i-1][1] + data[i],dp[i-1][0]); // 1개 제거 할때는 이전 값중 하나 제거했으면 현재값은 무조건 더해야함. 또는 이번 값을 제외하는게 좋다. 
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
	}
	
	printf("%d\n",ans);
}
