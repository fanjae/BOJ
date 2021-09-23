/* 
https://www.acmicpc.net
Problem ID : 10971
Brute Force & Backtracking
*/

#include <stdio.h>

int n;
int min_cost = 10000005;
int cost[15][15];
int start_position = 0;
bool visited[15];
void traversal(int last_visited, int cnt, int value)
{
	if(value > min_cost) // �̹� �ּҺ���� �Ѿ��ٸ� ���� ����. 
	{
		return ;
	}
	if(cnt == n-1) // ���������� ����ġ 
	{
		if(cost[last_visited][start_position] != 0) // ������ ����ġ �� �� ������ ��Ȳ ����ó�� 
		{
			traversal(start_position,cnt+1,value + cost[last_visited][start_position]);
		}
		return ;
	}
	if(cnt == n) // ��ȸ�� �����ٸ� ��� �� 
	{
		if(value < min_cost) 
		{
			min_cost = value;
		}
		return ;
	}
	else
	{
		for(int i=1; i<=n; i++) // �� �� �ִ� �� �� ���� �湮 üũ 
		{
			if(visited[i] == true)
			{
				continue;
			}
			if(cost[last_visited][i] != 0) // �� �� �ִ� ���̶��  
			{
				visited[i] = true;
				traversal(i,cnt+1,value + cost[last_visited][i]);  // ���ǿ� ��ȸ�� ���� ���� 
				visited[i] = false;
			}
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	
	for(int i=1; i<=n; i++) // ù��° ������ 
	{
		visited[i] = true; // ������ �湮 üũ 
		start_position = i; // ������ üũ ��  
		traversal(i,0,0); // Traver
		visited[i] = false;  // �湮 üũ ���� 
		start_position = 0; // üũ ���� 
	}
	
	printf("%d\n",min_cost);
}
	
