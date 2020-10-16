#include <stdio.h>
#include <algorithm>
int dp[305]={0};
int data[305];

// dp[n] : n번째 계단에서의 최대값
// 3 이후 값부터 n번째 계단에서 발생할 수 있는 상황
// 전 계단을 밟고 온 경우 :  전전계단을 밟지 못하므로 전전전계단까지 계산 상황을 본다.
// 전 계단을 밟지 못한 경우 : 전전 계단을 밟았으므로, 전전계단까지 계산 상황을 본다. 
using namespace std;
int main(void)
{
	int n;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&data[i]);
	}
	
	dp[1] = data[1];
	dp[2] = data[1]+data[2];
	dp[3] = max(data[1]+data[3],data[2]+data[3]);
	for(int i=4; i<=n; i++)
	{
		dp[i] = max(dp[i-3]+data[i-1]+data[i],dp[i-2]+data[i]);
	}
	printf("%d",dp[n]);	
}
	
