/* 
https://www.acmicpc.net
Problem ID : 16173
BFS(Breadth first search)
*/

// 16174번 문제와 동일한 풀이 방법이므로 자세한 주석 생략합니다. // 
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
struct my_pair
{
	int x;
	int y;
};
int n;
int move_count[70][70];
int data[70][70];

bool safe(int x, int y)
{
	if(x > n || y > n)
	{
		return false;
	}
	return true;
}
void bfs()
{
	queue <my_pair> que;
	que.push({1,1});
	move_count[1][1] = 1;
	
	while(!que.empty())
	{
		int x = que.front().x;
		int y = que.front().y;
		que.pop();
		
		if(x == n && y == n) // 도착지점에 도달한 경우 
		{
			printf("HaruHaru\n");
			return ;
		}
		int new_x = x + data[x][y];
		int new_y = y + data[x][y];
		
		if(safe(new_x,y) == true && move_count[new_x][y] == -1) // 아래로 내려갈 수 있는 경우 
		{
			move_count[new_x][y] = 1;
			que.push({new_x,y});
		}
		if(safe(x,new_y) == true && move_count[x][new_y] == -1) // 오른쪽으로 이동할 수 있는 경우 
		{
			move_count[x][new_y] = 1;
			que.push({x,new_y});
		}
	}
	//도착지점에 도달하지 못한 경우 
	printf("Hing\n");
}
int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	memset(move_count,-1,sizeof(move_count));
	bfs();
}
