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
	visited[x] = true; // 해당 채널 방문  
	int target = hate_channel[x]; // 다음 선호하는 채널 확인. 
	if(target == 0) // 해당 채널을 아무도 싫어하지 않으면 개수 출력 
	{
		printf("%d\n",cnt);
		exit(0);
	}
	else
	{
		if(visited[target] == true) // 이미 방문한 곳이면 -1 출력 
		{
			printf("-1\n");
			exit(0);
		}
		else // 방문하지 않은 곳이면 탐색 
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
		if(hate_channel[y] == 0) // 아무도 싫어하지 않는 경우에만 우선적으로 넣음 (나이어린 사람이 해당 채널 싫어하면 움직일 필요X)  
		{
			hate_channel[y] = x;
		}		
	}
	dfs(p);		
}
