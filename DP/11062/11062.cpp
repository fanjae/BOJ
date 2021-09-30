/* 
https://www.acmicpc.net
Problem ID : 11062
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[2][1005][1005];
int data[1005];
int n;

int cal(int start, int end,bool geunwoo)
{
	int &ret = dp[geunwoo][start][end]; // geunwoo : true(근우 턴), false 명우 턴.
	// 고를 수 있는 범위가 start ~ end까지일때, 나올 수 있는 근우의 점수.  
	if(ret != -1)
	{
		return ret;
	}
	
	if(start == end)
	{
		if(geunwoo == true)
		{
			return ret = data[start];
		}
		else
		{
			return ret = 0;
		}
	}
	
	if(geunwoo == true) // 근우 턴일 때는 최대한 근우의 점수를 크게 만들어야한다.  
	{
		// 
		int value =  max(cal(start+1,end,false) + data[start], cal(start,end-1,false) + data[end]);
		return ret = value;
	}
	else // 명우 턴일때는 근우의 점수를 작게 만들어야한다.  
	{
		int value = min(cal(start+1,end,true),cal(start,end-1,true));
		return ret = value;
	}
	
}
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		for(int i=0; i<n; i++)
		{
			scanf("%d",&data[i]);	
		}
		
		printf("%d\n",cal(0,n-1,true));
	}
}
