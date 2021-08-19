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
	
	int &ret = dp[index][time]; // �ش� ��ġ���� �̾����� �ش� �ð������� �ִ� �߿䵵 
	if(ret != -1)
	{
		return ret;
	}
	ret = cal(index+1,time); // �ش� ������ �������� ����.
	if(time - data[index][1] >= 0) // �ð��ȿ� ���� �� �ְ�,�ش� ���� �����ϰ��� ��. 
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
