/* 
https://www.acmicpc.net
Problem ID : 10942
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>

int data[2005];
int palin[2005][2005]; // i번째 시작점으로 할때, j번째까지 가면 팰린드롬 만족하는가? 

int dp(int start, int end)
{
	int &ret = palin[start][end]; // dp값 참조 
	if(ret != -1) // 이미 계산되있으면 계산하지 않음 
	{
		return ret;	
	}
	else
	{
		if(start > end) // start가 end를 따라잡았다면 모두 비교가 끝남 
		{
			return 1;
		}
		if(data[start] != data[end]) // 시작점과 끝점을 기준으로 다르면 팰린드롬 X 
		{
			return 0;
		}
		return ret = dp(start+1,end-1); // 다음위치값 비교 
	}
}
int main(void)
{
	int n;
	int query;
	memset(palin,-1,sizeof(palin));
	
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&data[i]);
	}
	scanf("%d",&query);
	for(int i=1; i<=query; i++)
	{
		int start, end; // 질의의 시작점과 끝점  
		scanf("%d %d",&start,&end);
		printf("%d\n",dp(start,end));
	}
}
