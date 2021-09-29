/* 
https://www.acmicpc.net
Problem ID : 17404
DP(Dynamic Programming)
*/


#include <stdio.h>
#include <algorithm>
#define INF 1000005
int dp[1005][3];
int data[1005][3];
int ans = INF;
int n;
using namespace std;

void reset()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<3; j++)
		{
			dp[i][j] = INF;
		}
	}
}
void cal()
{
	for(int i=2; i<=n; i++)
	{
		// [i][0] : i번째 집을 빨강으로 칠할때 최소 비용
		// [i][1] : i번째 집을 초록으로 칠할때 최소 비용
		// [i][2] : i번째 집을 파랑으로 칠할때 최소 비용
		// i-1번째 값을 기준으로, 둘중에 비용이 더 작은 비용이 드는 값을 골라서 더한다.
		 
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + data[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + data[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + data[i][2];
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<3; j++)
		{
			scanf("%d",&data[i][j]);	
		}
	}
	
	reset(); // dp 배열 초기화 
	dp[1][0] = data[1][0]; // 첫번째 집을 빨간색으로 칠함. 
	cal();
	ans = min(ans,min(dp[n][1],dp[n][2])); // 마지막에 빨간색을 고르지 않은 곳 중 최소값 

	reset(); // dp 배열 초기화
	dp[1][1] = data[1][1]; // 첫번째 집을 초록색으로 칠함.
	cal();
	ans = min(ans,min(dp[n][0],dp[n][2])); // 마지막에 초록색을 고르지 않은 곳 중 최소값 

	reset(); // dp 배열 초기화
	dp[1][2] = data[1][2]; // 첫번째 집을 파랑색으로 칠함.
	cal();  
	ans = min(ans,min(dp[n][0],dp[n][1])); // 마지막에 파랑색을 고르지 않은 곳 중 최소값 

	printf("%d\n",ans);
}
