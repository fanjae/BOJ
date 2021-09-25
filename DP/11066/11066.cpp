/* 
https://www.acmicpc.net
Problem ID : 11066
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <algorithm>

#define INF 987654321

using namespace std;
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int data[505];
		int dp[505][505]={0};
		int sum[505]={0};
		int n;
		
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&data[i]);
			sum[i] = sum[i-1] + data[i]; // 값 누적 
		}

		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				dp[i][j] = INF; // dp 배열 임의 초기화 
			}
		}
				
		// dp[i][i] : i번째부터 i번째 파일까지 합치는 최소 비용 = 0 
		for(int i=1; i<=n; i++)
		{
			dp[i][i] = 0;
		}
		

		for(int d=1; d<=n-1; d++) // 대각선 처리 
		{
			for(int i=1; i<=n-d; i++) // d 변수가 1이면 주 대각선의 바로 위에 있는 대각선 
			{
				int j = i + d; 
				
				// dp[i][j] = i번째부터 j번째 파일까지 합치는 최소 비용
				// dp[1][2] = min(dp[1][2],dp[1][1] + dp[2][2] + sum[2] - sum[0]);
				// dp[2][3] = min(dp[2][3],dp[2][2] + dp[3][3] + sum[3] - sum[1]);
				// dp[3][4] = min(dp[3][4],dp[3][3] + dp[4][4] + sum[4] - sum[2]);
				// dp[1][3] = min(dp[1][3],dp[1][1] + dp[2][3] + sum[3] - sum[0], dp[1][2] + dp[3][3] + sum[3] - sum[0]);
				// dp[2][4] = min(dp[2][4],dp[2][2] + dp[3][4] + sum[4] - sum[1], dp[2][3] + dp[4][4] + sum[4] - sum[1]);
				
				// 일반화 : i <= k < j
				// dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]); 
				for(int k=i; k<j; k++)
				{
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
				}
			}
		}
		
		printf("%d\n",dp[1][n]);
	}
}
