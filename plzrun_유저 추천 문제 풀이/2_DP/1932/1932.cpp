#include <stdio.h>
#include <algorithm>
long long int dp[505][505];
int data[505][505];

using namespace std; 

// dp[i][j] = 대각선상의 왼쪽 혹은 오른쪽을 뽑았을때 나올수 있는 최대값.
// dp[i][1] = 무조건 자신의 대각선상 위쪽(배열상으론 위쪽 값만 뽑아올 수 있음) 
int main(void)
{
	int n;
	long long max_value = 0;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			scanf("%lld",&data[i][j]);
		}
	}
	
	dp[1][1] = data[1][1];
	for(int i=2; i<=n; i++) // 자신의 윗값이 자신이 가질 수 있는 최대값. 
	{
		dp[i][1] = dp[i-1][1] + data[i][1];
	}


	for(int i=2; i<=n; i++)
	{
		for(int j=2; j<=i; j++)
		{
			dp[i][j] = max(data[i][j]+dp[i-1][j-1],data[i][j]+dp[i-1][j]); // 대각선상 왼쪽 혹은 대각선상 오른쪽 데이터중 최대값과 계산 
			if(i == n)
			{
				max_value = max(max_value,dp[i][j]);
			}
		}
	}
	printf("%lld\n",max_value);
}
		
