/* 
https://www.acmicpc.net
Problem ID : 17845 
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int dp[1005][10005];
int data[1005][2];
int n,k;
int cal(int index, int time)
{
	if(index == k)
	{
		return 0;
	}
	
	int &ret = dp[index][time]; // 해당 위치까지 뽑았을때 해당 시간까지의 최대 중요도 
	if(ret != -1)
	{
		return ret;
	}
	ret = cal(index+1,time); // 해당 과목을 선택하지 않음.
	if(time - data[index][1] >= 0) // 시간안에 들을 수 있고,해당 과목 선택하고자 함. 
	{
		ret = max(ret, cal(index+1,time-data[index][1]) + data[index][0]);
	}
	return ret;
}
int main(void)
{
	scanf("%d %d",&n,&k);
	memset(dp,-1,sizeof(dp));
	for(int i=0; i<k; i++)
	{
		scanf("%d %d",&data[i][0],&data[i][1]);
	}
	
	printf("%d\n",cal(0,n));
}
