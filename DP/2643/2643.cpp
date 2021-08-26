/* 
https://www.acmicpc.net
Problem ID : 2643
DP(Dynamic Programming)
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
struct paper
{
	int x;
	int y;
};

struct paper data[105]; // ������ ũ�� 
int dp[105]; // dp[x] : x��°���� ���� �� �ִ� �ִ� ������ ��� 
int ans;
int n;
bool compare(const struct paper &dat1, const struct paper &dat2) // ���� �� �Լ� 
{
	if(dat1.x != dat2.x)
	{
		return dat1.x > dat2.x;
	}
	else
	{
		return dat1.y > dat2.y;
	}
}

int cal(int index)
{
	int &ret = dp[index];
	if(ret != -1)
	{
		return ret;
	}
	
	int value = 0;
	for(int i=0; i<=n; i++)
	{
		if(index == i) // �ڱ� �ڽŰ� ������ ���� 
		{
			continue;
		}
		
		if((data[index].x >= data[i].x && data[index].y >= data[i].y) || (data[index].x >= data[i].y && data[index].y >= data[i].x)) // ���� ���̸� ���� �� �ִ°�?  
		{
			value = max(value,cal(i));
		}
	}
	if(value == 0) // 1���� ���� �� ���� ���(���θ� ���� �� ����) => 1 
	{
		return ret = 1;
	}
	else // 1�� �̻� ���� �� �ִ� ��� (������ �����Ͽ� +1�� ����) 
	{
		return ret = value + 1;
	}
}
int main(void)
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	data[0].x = 1000; // ���Ƿ� 1000¥�� ���̸� ��Ҵٰ� ������. 
	data[0].y = 1000;
	
	for(int i=1; i<=n; i++) 
	{
		int x, y;
		scanf("%d %d",&x,&y);
		data[i].x = x;
		data[i].y = y;
	}
	
	sort(data,data+n+1,compare); // �������� ���� 
	cal(0);
	
	for(int i=1; i<=n; i++)
	{
		ans = max(ans,dp[i]);
	}
	printf("%d\n",ans); 
}

	
		
