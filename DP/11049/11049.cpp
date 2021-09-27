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
		d[cnt++] = x; // �� ��Ŀ� �� �κ� ������ 
		if(i == n-1) // �������� ���ؼ� �� �κ��� ������. 
		{
			d[cnt++] = y;
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) 
		{
			dp[i][j] = INT_MAX-1; // �迭 �ʱ�ȭ int�� �ִ밪(2^32-1)�� ���� 
		}
	}
	
	for(int i=1; i<=n; i++) // dp[i][i] 
	{
		dp[i][i] = 0;
	}
	
	for(int diagonal=1; diagonal <=n-1; diagonal++) // �밢�� ó�� 
	{
		for(int i=1; i<=n-diagonal; i++)
		{
			int j = i+diagonal;
			
			// dp[i][j] = i��°���� j��°���� ��� ���Ҷ� �ּ� ���� Ƚ��
			// dp[1][2] = min(dp[1][2],dp[1][1] + dp[2][2] + (d0*d1*d2);
			// dp[2][3] = min(dp[2][3],dp[2][2] + dp[3][3] + (d1*d2*d3);
			// dp[1][3] = min(dp[1][3],dp[1][1] + dp[2][3] + (d0*d1*d3), dp[1][2] + dp[3][3] + (d0*d2*d3);
			
			// �Ϲ�ȭ : i <= k < j
			// dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (d[i-1] * d[k] * d[j]));
			 
			for(int k=i; k<j; k++)
			{
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + (d[i-1] * d[k] * d[j]));
			}
		}
	}
	
	printf("%d\n",dp[1][n]);
}
