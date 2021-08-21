/* 
https://www.acmicpc.net
Problem ID : 16493
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[205][25]; // dp[day][m] : mé�ͱ��� ��������� day�ȿ� ���� �� �ִ� �ִ� ������ ��  
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
	
	ret = max(ret, cal(day,index+1)); // �������� ���� �ʰ� �ѱ� 
	if(day + data[index][0] <= n) // ���� ��¥ �ȿ� �������� ���� �� ����.  
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

