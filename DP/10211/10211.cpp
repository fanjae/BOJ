/* 
https://www.acmicpc.net
Problem ID : 10211
DP(Dynamic Programming)
*/

#include <stdio.h>
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int data[1005]={0};
		int dp[1005]={0}; // maximum subarray 
		int n;
		int max = -1000;
		
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&data[i]);
			dp[i] = data[i]; // �ʱⰪ�� �ڱ� �ڽ�. 
		}
		
		for(int i=1; i<n; i++)
		{
			dp[i] = dp[i] < (dp[i-1] + dp[i]) ? dp[i-1] + dp[i] : dp[i]; // �������� ������ ���� �ڱ� �ڽ��� ���� ū ���� ���� ū ��. 
		}
		
		for(int i=0; i<n; i++)
		{
			if(max < dp[i])
			{
				max = dp[i];
			}
		}
		printf("%d\n",max);
	}
}
