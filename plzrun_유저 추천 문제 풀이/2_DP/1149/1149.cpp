#include <stdio.h>
#include <algorithm>

using namespace std;
int data[1005][1005]={0};
int dp[1005][1005] ={0};
// dp[n][0] : n번째 집이 빨강색으로 칠했을때 최소 비용
// dp[n][1] : n번째 집이 초록으로 칠했을때 최소 비용
// dp[n][2] : n번째 집이 파랑으로 칠했을때 최소 비용 
int main(void)
{
	int i,j;
	int n;
	int min_value;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=3; j++)
		{
			scanf("%d",&data[i][j]);
			if(i == 1)
			{
				dp[i][j] = data[i][j];
			}
		}
	}

	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=3; j++)
		{
			if(j == 1) // i번째 집이 빨강을 선택했으면, 이전 집은 초록 혹은 파랑을 선택해야한다. (이때 이전 값은 dp[i-1][2]와 dp[i-1][3]에 계산) 
			{	
				dp[i][j] = min(dp[i-1][2]+data[i][j],dp[i-1][3]+data[i][j]); 
			}
			if(j == 2) // // i번째 집이 초록을 선택했으면, 이전 집은 빨강 혹은 파랑을 선택해야한다. (이때 이전 값은 dp[i-1][1]와 dp[i-1][3]에 계산) 
			{
				dp[i][j] = min(dp[i-1][1]+data[i][j],dp[i-1][3]+data[i][j]);
			}
			if(j == 3) // i번째 집이 파랑을 선택했으면, 이전 집은 빨강 혹은 초록을 선택해야한다. (이때 이전 값은 dp[i-1][1]와 dp[i-1][2]에 계산) 
			{
				dp[i][j] = min(dp[i-1][1]+data[i][j],dp[i-1][2]+data[i][j]);
			}
		}
	}
	min_value = dp[n][1];
	for(int i=1; i<=3; i++)
	{
		min_value = min(min_value,dp[n][i]);
	}
	printf("%d\n",min_value);

}		
