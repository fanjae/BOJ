#include <stdio.h>
#include <algorithm>
int dp[1000005]={0};
using namespace std;
int main(void)
{
	int n;
	scanf("%d",&n);
	dp[1] = 0; // 이미 1이므로 연산 필요 X
	dp[2] = 1; // 2로 나누면 바로 1. 
	dp[3] = 1; // 3으로 나누면 바로 1. 
	
	for(int i=4; i<=n; i++)
	{
		dp[i] = dp[i-1] + 1; // 1 뺀 경우는 이전값에 연산횟수 +1을 한것과 같음. 
		if(i % 2 == 0) // 2로 나눌 수 있는 경우는 /2를 계산한 값에 연산횟수 +1을 한것과 같음. 
		{
			dp[i] = min(dp[i],dp[i/2]+1);
		}
		if(i % 3 == 0) // 2로 나눌 수 있는 경우는 /3를 계산한 값에 연산횟수 +1을 한것과 같음. 
		{
			dp[i] = min(dp[i],dp[i/3]+1);
		}
	}
	printf("%d\n",dp[n]);
}
	
