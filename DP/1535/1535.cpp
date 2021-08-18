/* 
https://www.acmicpc.net
Problem ID : 1535
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int human[25][2];
int dp[105][25]; // 특정 체력의 특정 인덱스에서 얻을 수 있는 기쁨 정보 
int n;
int data(int value, int index)
{
	if(index == n) // n에 도달한 경우 0을 반환 
	{
		return 0;
	}
	
	int &ret = dp[value][index]; // dp값을 가져옴 
	if(ret != -1) // -1이 아니면 이미 다녀간 전적있음. 
	{
		return ret;
	}
	
	ret = max(ret, data(value,index+1)); //인사를 받지 않음. 
	if(value - human[index][0] > 0) // 인사를 받을 수 있음(죽지 않아요) 
	{
		ret = max(ret, data(value-human[index][0], index+1) + human[index][1]); // 인사를 받는 경우 
	}
	return ret;
}
int main(void)
{
	
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i=0; i<n; i++)
	{
		scanf("%d",&human[i][0]);
	}
	for(int i=0; i<n; i++)
	{
		scanf("%d",&human[i][1]);
	}
	printf("%d\n",data(100,0));
}
