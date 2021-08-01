/* 
https://www.acmicpc.net
Problem ID : 14923
BFS(Breadth first search)

*/
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct my_pair 
{
	int x;
	int y;
};

int n,m;
int start_x,start_y;
int end_x,end_y;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int moving[2][1005][1005];
int data[1005][1005];

bool safe(int x, int y) // 좌표 범위 over여부 확인 
{
	if(x <= 0 || x > n)
	{
		return false;
	}
	if(y <= 0 || y > m)
	{
		return false;
	}
	return true;
}
void bfs()
{
	queue <my_pair> que;
	queue <bool> visited_que;
	que.push({start_x,start_y});
	visited_que.push(false);
	
	while(!que.empty())
	{
		int x = que.front().x;
		int y = que.front().y;
		bool visited = visited_que.front();
		
		que.pop();
		visited_que.pop();
		
		if(x == end_x && y == end_y) // 탈출 성공 
		{
			printf("%d\n",moving[visited][x][y]); 
			return ;
		}
		for(int i=0; i<4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			
			if(safe(new_x,new_y) == true) 
			{
				if(visited == true) // 마법의 지팡이를 이미 사용한 경우. 
				{	
					if(data[new_x][new_y] == 0 && moving[visited][new_x][new_y] == -1)
					{
						moving[1][new_x][new_y] = moving[1][x][y] + 1;
						que.push({new_x,new_y});
						visited_que.push(true);
					}
				}
				if(visited == false && data[new_x][new_y] == 0 && moving[0][new_x][new_y] == -1) // 마법의 지팡이를 사용하지 않고, 벽이 아닌 경우 
				{
					moving[0][new_x][new_y] = moving[0][x][y] + 1;
					que.push({new_x,new_y});
					visited_que.push(false);
				}
				if(visited == false && data[new_x][new_y] == 1 && moving[0][new_x][new_y] == -1) // 마법의 지팡이를 사용하지 않고, 벽을 만난 경우  
				{
					moving[1][new_x][new_y] = moving[0][x][y] + 1;
					que.push({new_x,new_y});
					visited_que.push(true);				
				}
					
			}
		}
	}
	// 탈출 불가능한 상황 
	printf("-1\n");
}
int main(void)
{
	scanf("%d %d",&n,&m);
	scanf("%d %d",&start_x,&start_y);
	scanf("%d %d",&end_x,&end_y);
	
	memset(moving,-1,sizeof(moving)); // -1로 배열 리셋. 
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	moving[0][start_x][start_y] = 0;
	bfs();
		
}

