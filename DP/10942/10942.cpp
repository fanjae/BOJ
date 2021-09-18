/* 
https://www.acmicpc.net
Problem ID : 10942
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>

int data[2005];
int palin[2005][2005]; // i��° ���������� �Ҷ�, j��°���� ���� �Ӹ���� �����ϴ°�? 

int dp(int start, int end)
{
	int &ret = palin[start][end]; // dp�� ���� 
	if(ret != -1) // �̹� ���������� ������� ���� 
	{
		return ret;	
	}
	else
	{
		if(start > end) // start�� end�� ������Ҵٸ� ��� �񱳰� ���� 
		{
			return 1;
		}
		if(data[start] != data[end]) // �������� ������ �������� �ٸ��� �Ӹ���� X 
		{
			return 0;
		}
		return ret = dp(start+1,end-1); // ������ġ�� �� 
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
		int start, end; // ������ �������� ����  
		scanf("%d %d",&start,&end);
		printf("%d\n",dp(start,end));
	}
}
