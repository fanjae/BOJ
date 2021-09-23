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
	if(value > min_cost) // 이미 최소비용을 넘었다면 가망 없음. 
	{
		return ;
	}
	if(cnt == n-1) // 마지막으로 원위치 
	{
		if(cost[last_visited][start_position] != 0) // 마지막 원위치 할 때 못가는 상황 예외처리 
		{
			traversal(start_position,cnt+1,value + cost[last_visited][start_position]);
		}
		return ;
	}
	if(cnt == n) // 순회가 끝났다면 비용 비교 
	{
		if(value < min_cost) 
		{
			min_cost = value;
		}
		return ;
	}
	else
	{
		for(int i=1; i<=n; i++) // 갈 수 있는 곳 한 곳씩 방문 체크 
		{
			if(visited[i] == true)
			{
				continue;
			}
			if(cost[last_visited][i] != 0) // 갈 수 있는 곳이라면  
			{
				visited[i] = true;
				traversal(i,cnt+1,value + cost[last_visited][i]);  // 외판원 순회를 위해 들어간다 
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
	
	for(int i=1; i<=n; i++) // 첫번째 시작점 
	{
		visited[i] = true; // 시작점 방문 체크 
		start_position = i; // 시작점 체크 용  
		traversal(i,0,0); // Traver
		visited[i] = false;  // 방문 체크 해제 
		start_position = 0; // 체크 해제 
	}
	
	printf("%d\n",min_cost);
}
	
