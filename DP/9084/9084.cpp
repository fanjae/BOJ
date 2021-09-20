/* 
https://www.acmicpc.net
Problem ID : 9084
DP(Dynamic Programming)
*/
#include <stdio.h>
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,value;
		int coin[25]={0};
		int dp[10005]={0};
		dp[0] = 1;
		
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&coin[i]);
		}
		scanf("%d",&value);
		
		for(int i=0; i<n; i++) // ���� ���� ��ŭ ����. 
		{
			for(int j=coin[i]; j<=value; j++) // i��° coin���� k���� �ݺ��Ѵ�. 
			{
				// dp[n] = dp[n- ���� ���� ������ ũ��];
				dp[j] = dp[j] + dp[j-coin[i]];
			}
		}
		printf("%d\n",dp[value]);
	}
}
	
