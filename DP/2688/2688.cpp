/* 
https://www.acmicpc.net
Problem ID : 2688
DP(Dynamic Programming)
*/

#include <stdio.h>
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		long long int ans = 0;
		long long int dp[1005][15]={0};
		scanf("%d",&n);
		
		// dp[i][j] = i��°�ڸ��� j���ڱ��� �� �� �ִ� ����� �� 
		// 0�� �������� 2�ڸ� ���� �پ���� �ʴ� ����
		// 00,01,02....09 : �̴� ���������� �� 0���� 9���� ���� �Ͱ� ����.
		// 1�� �������� 2�ڸ� ���� �پ���� �ʴ� ����
		// 11,12,13...19 : �̴� ���������� �� 1���� 9���� ���� �Ͱ� ����;��
		
		// �Ϲ�ȭ dp[i][j] = dp[i-1][j] + dp[i-1][j+1] ~ dp[i-1][9];  
		for(int i=0; i<=9; i++)
		{
			dp[1][i] = 1;
		}
		for(int i=2; i<=n; i++)
		{
			for(int j=0; j<=9; j++)
			{
				for(int k=j; k<=9; k++)
				{
					dp[i][j] += dp[i-1][k];	
				}
			}
		}

		for(int i=0; i<=9; i++)
		{
			ans += dp[n][i];
		}
		printf("%lld\n",ans);
	}
}
