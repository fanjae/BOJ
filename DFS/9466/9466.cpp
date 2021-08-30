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
	int target = data[i]; // 다음 타겟  
	
	if(visited[target] == false) // 해당 타겟에 방문사례가 없으면 탐색. 
	{
		dfs(target);
	}
	else
	{
		if(maked[target] == false) // 해당 타겟에 방문 사례가 있으면 사이클 길이 확인 
		{
			for(int j=target; j != i; j=data[j])
			{
				cnt++;
			}
			cnt++; // 자기 자신 
		}
	}
	maked[i] = true; // 위 탐색을 모두 마쳤으면, 해당 인원은 팀이 결정된 상태(속함 여부와 상관없음) 
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

