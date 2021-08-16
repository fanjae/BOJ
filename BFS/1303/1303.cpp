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
bool safe(int x, int y)
{
	if(x < 0 || x >= n)
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
	for(int i=0; i<4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		
		if(safe(new_x,new_y) == true && visited[new_x][new_y] == false && last == data[new_x][new_y])
		{
			visited[new_x][new_y] = true;
			count++;
			dfs(new_x,new_y,data[new_x][new_y]); 
		}
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%s",data[i]);
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(data[i][j] == 'W' || data[i][j] == 'B' && visited[i][j] == false)
			{
				visited[i][j] = true;
				count++;
				dfs(i,j,data[i][j]);		
				if(data[i][j] == 'W')
				{
					W_team += count * count;
				}
				else
				{
					B_team += count * count;
				}
				count = 0;
			}
		}
	}
	printf("%d %d\n",W_team,B_team);
}
