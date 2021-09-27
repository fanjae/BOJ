/* 
https://www.acmicpc.net
Problem ID : 11049
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <algorithm>
#include <limits.h>
int d[505];
int dp[505][505];
int cnt = 0;
int n;

using namespace std;
int main(void)
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		d[cnt++] = x; // 각 행렬에 행 부분 가져옴 
		if(i == n-1) // 마지막에 한해서 열 부분을 저장함. 
		{
			d[cnt++] = y;
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) 
		{
			dp[i][j] = INT_MAX-1; // 배열 초기화 int의 최대값(2^32-1)로 변경 
		}
	}
	
	for(int i=1; i<=n; i++) // dp[i][i] 
	{
		dp[i][i] = 0;
	}
	
	for(int diagonal=1; diagonal <=n-1; diagonal++) // 대각선 처리 
	{
		for(int i=1; i<=n-diagonal; i++)
		{
			int j = i+diagonal;
			
			// dp[i][j] = i번째부터 j번째까지 행렬 곱할때 최소 연산 횟수
			// dp[1][2] = min(dp[1][2],dp[1][1] + dp[2][2] + (d0*d1*d2);
			// dp[2][3] = min(dp[2][3],dp[2][2] + dp[3][3] + (d1*d2*d3);
			// dp[1][3] = min(dp[1][3],dp[1][1] + dp[2][3] + (d0*d1*d3), dp[1][2] + dp[3][3] + (d0*d2*d3);
			
			// 일반화 : i <= k < j
			// dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (d[i-1] * d[k] * d[j]));
			 
			for(int k=i; k<j; k++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + (d[i-1] * d[k] * d[j]));
			}
		}
	}
	
	printf("%d\n",dp[1][n]);
}
