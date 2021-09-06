/* 
https://www.acmicpc.net
Problem ID : 4883
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <cstring>
#include <algorithm>

#define INF 123456789

using namespace std;
long long int data[100005][4];
long long int dp[100005][4];

int main(void)
{
	int T = 1;
	while(1)
	{
		int n;
		scanf("%d",&n);
		
		if(n == 0)
		{
			break;
		}	
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++)
			{
				scanf("%lld",&data[i][j]);
			}
		}
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++)
			{
				dp[i][j] = INF; // 초기값 설정 
			}
		}
		
		dp[1][1] = INF;
		dp[1][2] = data[1][2]; // 시작지점 
		dp[1][3] = data[1][2] + data[1][3]; // 왼쪽으로는 이동할 수 없기 때문에 이 값은 시작점에서 무조건 오른쪽 값 
		
		for(int i=2; i<=n; i++) 
		{
			dp[i][1] = min(dp[i-1][1], dp[i-1][2]) + data[i][1]; // 첫번째 열은 위쪽 값과 오른쪽 대각선위에서옴 
			dp[i][2] = min({dp[i-1][1],dp[i-1][2],dp[i-1][3],dp[i][1]}) + data[i][2]; // 두번째 열은 이전 열과 윗행의 3개의 대각선에서 내려옴 
			dp[i][3] = min({dp[i-1][2],dp[i-1][3],dp[i][2]}) + data[i][3]; // 세번째 열은 이전열과 위쪽 값과 왼쪽 대각선 위에서옴 
		}
		
		printf("%d. %lld\n",T,dp[n][2]);
		T++;
	}
	
}
