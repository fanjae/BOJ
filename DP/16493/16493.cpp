/* 
https://www.acmicpc.net
Problem ID : 16493
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[205][25]; // dp[day][m] : m챕터까지 고려했을때 day안에 읽을 수 있는 최대 페이지 수  
int data[205][2]; 
int n,m;
int cal(int day, int index)
{
	if(index == m)
	{
		return 0;
	}
	if(day > n)
	{
		return 0;
	}
	
	int &ret = dp[day][index];
	if(ret != -1)
	{
		return ret;
	}
	
	ret = max(ret, cal(day,index+1)); // 페이지를 읽지 않고 넘김 
	if(day + data[index][0] <= n) // 남은 날짜 안에 페이지를 읽을 수 있음.  
	{
		ret = max(ret, cal(day+data[index][0],index+1) + data[index][1]);
	}
	return ret;
	
}
int main(void)
{
	scanf("%d %d",&n,&m);
	memset(dp,-1,sizeof(dp));
	for(int i=0; i<m; i++)
	{
		scanf("%d %d",&data[i][0],&data[i][1]);
	}
	printf("%d\n",cal(0,0));
}

