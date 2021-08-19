/* 
https://www.acmicpc.net
Problem ID : 14728
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[105][10005];
int exam[105][2];
int n, max_time;
int data(int index, int time)
{
	if(index == n)
	{
		return 0;
	}
	
	int &ret = dp[index][time];
	if(dp[index][time] != -1)
	{
		return dp[index][time];
	}
	ret = data(index+1,time); // 해당 과목을 선택하지 않음.
	if(time - exam[index][0] >= 0) ret = max(ret, data(index+1,time-exam[index][0]) + exam[index][1]); // 시간안에 준비 할 수 있고,해당 과목 선택하고자 함. 
	
	return ret;
}
	
int main(void)
{
	scanf("%d %d",&n,&max_time);
	memset(dp,-1,sizeof(dp));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2; j++)
		{
			scanf("%d",&exam[i][j]);
		}
	}
	
	printf("%d\n",data(0,max_time));
}
