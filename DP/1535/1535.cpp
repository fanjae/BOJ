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
int dp[105][25]; // Ư�� ü���� Ư�� �ε������� ���� �� �ִ� ��� ���� 
int n;
int data(int value, int index)
{
	if(index == n) // n�� ������ ��� 0�� ��ȯ 
	{
		return 0;
	}
	
	int &ret = dp[value][index]; // dp���� ������ 
	if(ret != -1) // -1�� �ƴϸ� �̹� �ٳణ ��������. 
	{
		return ret;
	}
	
	ret = max(ret, data(value,index+1)); //�λ縦 ���� ����. 
	if(value - human[index][0] > 0) // �λ縦 ���� �� ����(���� �ʾƿ�) 
	{
		ret = max(ret, data(value-human[index][0], index+1) + human[index][1]); // �λ縦 �޴� ��� 
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
