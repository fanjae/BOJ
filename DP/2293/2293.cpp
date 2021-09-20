/* 
https://www.acmicpc.net
Problem ID : 2293
DP(Dynamic Programming)
*/

#include <stdio.h>
int main(void)
{
	int dp[10005]={0};
	int coin[105]={0};
	int n,k;
	
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&coin[i]);
	}
	
	dp[0] = 1;
	for(int i=0; i<n; i++) // ���� ���� ��ŭ ����. 
	{
		for(int j=coin[i]; j<=k; j++) // i��° coin���� k���� �ݺ��Ѵ�. 
		{
			// dp[n] = dp[n- ���� ���� ������ ũ��]; 
			dp[j] = dp[j] + dp[j-coin[i]];
			
		}
	}
	
	printf("%d\n",dp[k]); 
}
