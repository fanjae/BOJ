/* 
https://www.acmicpc.net
Problem ID : 1563
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

#define MOD 1000000 
using namespace std;
int data[1005][4][4];
int n;
int dp(int index, int tardy, int absent, bool con)
{
	if(tardy >= 2 || absent >= 3) // ���̿� �����ϱ� ���� �ش� ������ ���� ���� ��� 
	{
		return 0;
	}
	
	if(index == n) // ��¥�� �����Ͽ� ����Ȯ�� 
	{
		if(tardy >= 2)
		{
			return 0;	
		}
		if(absent >= 3)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	int &ret = data[index][tardy][absent];
	if(ret != -1)
	{
		return ret;
	}
	
	ret = 0;
	if(con == false) // ���� �Ἦ ���� Ȯ��. 
	{
		ret += dp(index+1, tardy, 0, false) % 1000000; // �⼮�� 
		ret += dp(index+1, tardy+1, 0, false) % 1000000; // ������ 
		ret += dp(index+1, tardy, 1, true) % 1000000; // ���ӰἮ�� �ƴ����� �׳� �Ἦ��. 
	}
	else
	{
		ret += dp(index+1, tardy, 0, false) % 1000000; // �⼮��. 
		ret += dp(index+1, tardy+1, 0, false) % 1000000; // ������. 
		ret += dp(index+1, tardy, absent+1, true) % 1000000; // ���ӰἮ��. 
	}
	
	return ret % 1000000;
	
		
}
int main(void)
{
	scanf("%d",&n);
	memset(data,-1,sizeof(data));
	printf("%d\n",dp(0,0,0,false));
	
}
