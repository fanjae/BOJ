/* 
https://www.acmicpc.net
Problem ID : 9466
DFS(Depth-First Search)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool visited[100005];
bool maked[100005];
int data[100005];
int cnt = 0;

void dfs(int i)
{
	visited[i] = true;
	int target = data[i]; // ���� Ÿ��  
	
	if(visited[target] == false) // �ش� Ÿ�ٿ� �湮��ʰ� ������ Ž��. 
	{
		dfs(target);
	}
	else
	{
		if(maked[target] == false) // �ش� Ÿ�ٿ� �湮 ��ʰ� ������ ����Ŭ ���� Ȯ�� 
		{
			for(int j=target; j != i; j=data[j])
			{
				cnt++;
			}
			cnt++; // �ڱ� �ڽ� 
		}
	}
	maked[i] = true; // �� Ž���� ��� ��������, �ش� �ο��� ���� ������ ����(���� ���ο� �������) 
}
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		memset(visited,false,sizeof(visited));
		memset(maked,false,sizeof(maked));
		memset(data,0,sizeof(data));
		
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&data[i]);
		}
		
		for(int i=1; i<=n; i++)
		{
			if(visited[i] == false)
			{
				dfs(i);
			}
		}
		printf("%d\n",n-cnt);
		cnt = 0;
	}
}

