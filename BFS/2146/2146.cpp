#include <stdio.h>
#include <queue>

using namespace std;

struct my_pair
{
	int x;
	int y;
};

int n;
int cnt = 0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int data[105][105];
bool visited[105][105]={0};
queue <my_pair> que;

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
void bfs()
{
	while(!que.empty())
	{
		int x = que.front().x;
		int y = que.front().y;
		que.pop();

		
		for(int i=0; i<4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			
			printf("%d %d\n",new_x,new_y);
			if((safe(new_x,new_y) == true) && (visited[new_x][new_y] == false) && data[new_x][new_y] == 1)
			{
				printf("%d %d\n",new_x,new_y);
				visited[new_x][new_y] = true;
				data[new_x][new_y] = cnt;
				que.push({new_x,new_y});							
			}
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d",&data[i][j]);		
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(visited[i][j] == false && data[i][j] == 1)
			{
				cnt++;
				visited[i][j] = true;
				data[i][j] = cnt;
				que.push({i,j});
				bfs();
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d",data[i][j]);
		}
		printf("\n");
	}
}
