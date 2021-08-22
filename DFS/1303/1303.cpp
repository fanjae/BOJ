/* 
https://www.acmicpc.net
Problem ID : 1303
DFS(Depth-First Search)
*/

#include <stdio.h>
char data[105][105];
bool visited[105][105];
int W_team;
int B_team;
int n,m;
int sum = 0;
int count = 0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool safe(int x, int y) // 충돌 여부 확인 
{
	if(x < 0 || x >= m)
	{
		return false;
	}
	if(y < 0 || y >= n)
	{
		return false;
	}
	return true;
}
void dfs(int x, int y, char last)
{
	count++;
	for(int i=0; i<4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		
		if(safe(new_x,new_y) == true && visited[new_x][new_y] == false && last == data[new_x][new_y]) // 방문한적 없으면서, 같은 팀 병사가  모여있는 경우 
		{
			visited[new_x][new_y] = true;
			dfs(new_x,new_y,data[new_x][new_y]); 
		}
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
	{
		scanf("%s",data[i]);
	}
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if((data[i][j] == 'W' || data[i][j] == 'B') && visited[i][j] == false)
			{
				visited[i][j] = true;
				dfs(i,j,data[i][j]);		
				if(data[i][j] == 'W') // 흰색 병사 
				{
					W_team += count * count;
				}
				else // 검은색 병사 
				{
					B_team += count * count;
				}
				count = 0;
			}
		}
	}
	printf("%d %d\n",W_team,B_team);
}
