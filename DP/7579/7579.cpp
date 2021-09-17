/* 
https://www.acmicpc.net
Problem ID : 7579
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <algorithm>
using namespace std; 

int n,m;
int dp[105][10005]; // �ش� index���� �ش� cost�� ������� �ִ� ����Ʈ�� ���� 
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
			dp[i][j] = dp[i-1][j]; // ���������� ������ ��Ƶ� 
			if(j - cost[i] >= 0) // �ش� ������ ���� �� �ִ� ��� 
			{
				dp[i][j] = max(dp[i][j],byte[i] + dp[i-1][j-cost[i]]); // ���������� ���� �� �ִ� ����Ʈ�� ���ο� ���� ��Ȱ��ȭ ��������,
				// Ȯ���� �� �ִ� byte ���� ������� �� ū��?  
			}
		}
	}
	
	for(int i=0; i<=sum; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(dp[j][i] >= m) // m����Ʈ �̻� Ȯ�� ������ ���, �ش� ����� �ּ� ����� �ȴ�. 
			{
				printf("%d\n",i);
				return 0;
			}
		}
	}
}
