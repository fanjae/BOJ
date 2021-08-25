/* 
https://www.acmicpc.net
Problem ID : 10552
DFS(Depth-First Search)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n,m,p;
int cnt = 0;
int hate_channel[100005]={0};
bool visited[100005];
void dfs(int x)
{
	visited[x] = true; // �ش� ä�� �湮  
	int target = hate_channel[x]; // ���� ��ȣ�ϴ� ä�� Ȯ��. 
	if(target == 0) // �ش� ä���� �ƹ��� �Ⱦ����� ������ ���� ��� 
	{
		printf("%d\n",cnt);
		exit(0);
	}
	else
	{
		if(visited[target] == true) // �̹� �湮�� ���̸� -1 ��� 
		{
			printf("-1\n");
			exit(0);
		}
		else // �湮���� ���� ���̸� Ž�� 
		{
			cnt++; 
			dfs(target);
		}
	}	
}
	
int main(void)
{
	scanf("%d %d %d",&n,&m,&p);
	for(int i=1; i<=n; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(hate_channel[y] == 0) // �ƹ��� �Ⱦ����� �ʴ� ��쿡�� �켱������ ���� (���̾ ����� �ش� ä�� �Ⱦ��ϸ� ������ �ʿ�X)  
		{
			hate_channel[y] = x;
		}		
	}
	dfs(p);		
}
