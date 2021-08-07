/* 
https://www.acmicpc.net
Problem ID : 1600
BFS(Breadth first search)
*/

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct my_set
{
	int x;
	int y;
	int horse_count;
};

int moving[35][205][205];
int data[205][205];

int k;
int k_dx[8]={-1,-2,-2,-1,1,2,2,1};
int k_dy[8]={-2,-1,1,2,-2,-1,1,2};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int w,h;

bool safe(int x, int y)
{
	if(x <= 0 || x > h)
	{
		return false;
	}
	if(y <= 0 || y > w)
	{
		return false;
	}
	return true;
}
void bfs()
{
	queue <my_set> que;
	que.push({1,1,0});

	while(!que.empty())
	{
		int x = que.front().x;
		int y = que.front().y;
		int horse_count = que.front().horse_count; // 말이 나이트처럼 이동한 횟수 
		que.pop();
		
		if(x == h && y == w)
		{
			printf("%d\n",moving[horse_count][x][y]); // 도착한 경우 
			return ;
		}
		
		int new_x, new_y;
		if(horse_count < k) // k번까지 이동안한 경우엔 나이트처럼 이동하는 경우를 고려함  
		{
			for(int i=0; i<8; i++)
			{
				new_x = x + k_dx[i];
				new_y = y + k_dy[i];
				if(safe(new_x,new_y) == true && data[new_x][new_y] == 0 && moving[horse_count+1][new_x][new_y] == -1)
				{
					moving[horse_count+1][new_x][new_y] = moving[horse_count][x][y] + 1;
					que.push({new_x,new_y,horse_count+1});
				}
			}
		}
		for(int i=0; i<4; i++) // 일반적인 인접한 칸 이동하기 
		{
			new_x = x + dx[i];
			new_y = y + dy[i];
			
			if(safe(new_x,new_y) == true && data[new_x][new_y] == 0 && moving[horse_count][new_x][new_y] == -1)
			{
				moving[horse_count][new_x][new_y] = moving[horse_count][x][y] + 1;
				que.push({new_x,new_y,horse_count});
			}
		}
	}
	// 도착 지점 도달 불가 
	printf("-1\n");
}
int main(void)
{
	scanf("%d",&k);
	scanf("%d %d",&w,&h);
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	
	memset(moving,-1,sizeof(moving));
	moving[0][1][1] = 0;
	bfs();
}
