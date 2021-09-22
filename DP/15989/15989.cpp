/* 
https://www.acmicpc.net
Problem ID : 15989
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
		int value[3]={1,2,3};
		int dp[10005]={0};
		
		dp[0] = 1;
		
		scanf("%d",&n);
		for(int i=0; i<3; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(j - value[i] >= 0) // j�� i��° ���� �Ἥ ���� �� �ִ°�? 
				{
					// dp[j] = dp[j-���� ���� �� ��]�� ������ 
					dp[j] = dp[j] + dp[j - value[i]];
				}
			}
		}	
		printf("%d\n",dp[n]);
	}

}
