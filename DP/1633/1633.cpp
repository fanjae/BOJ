/* 
https://www.acmicpc.net
Problem ID : 1633
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int white[1005];
int black[1005];
int dp[1005][16][16];
int i;
int data(int index, int w, int b)
{
	if(index == i)
	{
		return 0;
	}
	
	if (dp[index][w][b] != -1)
	{
		return dp[index][w][b];
	}
	
	if (w > 0) // 흰색 선택 
	{
		dp[index][w][b] = max(dp[index][w][b], data(index+1,w-1,b) + white[index]);
	}
	if (b > 0) // 검은색 선택  
	{
		dp[index][w][b] = max(dp[index][w][b], data(index+1,w,b-1) + black[index]);
	}
	
	dp[index][w][b] = max(dp[index][w][b], data(index+1,w,b)); // 아무것도 선택 x 
	
	return dp[index][w][b];
}
	
	
int main(void)
{
	memset(dp,-1,sizeof(dp));
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF)
	{
		white[i] = a;
		black[i] = b;
		i++;
	}
	printf("%d",data(0,15,15));
	return 0;
	
		
}
