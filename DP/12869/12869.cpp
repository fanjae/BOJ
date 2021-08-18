/* 
https://www.acmicpc.net
Problem ID : 12869
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int dp[65][65][65];
int data(int a, int b, int c)
{
	// 음수로 내려가는 경우 처리 
	if(a < 0) a = 0;
	if(b < 0) b = 0;
	if(c < 0) c = 0;
	
	if(a == 0 && b == 0 && c == 0)
	{
		return 0;
	}
	
	int &ret = dp[a][b][c]; // 기존 저장된 dp값을 가져옴 
	if(ret != -1)
	{
		return ret;
	}
	ret = 1e9;
	ret = min(ret, data(a-9,b-3,c-1) + 1); // 각각 9,3,1로 데미지 받은 경우,
	ret = min(ret, data(a-9,b-1,c-3) + 1); // 각각 9,1,3로 데미지 받은 경우,
	ret = min(ret, data(a-3,b-9,c-1) + 1); // 각각 3,9,1로 데미지 받은 경우,
	ret = min(ret, data(a-3,b-1,c-9) + 1); // 각각 3,1,9로 데미지 받은 경우,
	ret = min(ret, data(a-1,b-9,c-3) + 1); // 각각 1,9,3로 데미지 받은 경우,
	ret = min(ret, data(a-1,b-3,c-9) + 1); // 각각 1,3,9로 데미지 받은 경우,
	
	return ret; 
}
int main(void)
{
	int n;
	int scv[3]={0};
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&scv[i]);
	}
	printf("%d",data(scv[0],scv[1],scv[2]));
}
