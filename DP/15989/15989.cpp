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
				if(j - value[i] >= 0) // j를 i번째 값을 써서 만들 수 있는가? 
				{
					// dp[j] = dp[j-현재 값을 뺀 값]을 누적함 
					dp[j] = dp[j] + dp[j - value[i]];
				}
			}
		}	
		printf("%d\n",dp[n]);
	}

}
