/*
https://www.acmicpc.net
Problem ID : 4179
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
queue <my_pair> fire_que;

int r,c;
int f_x,f_y;
int j_x,j_y;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int fire_moving[1005][1005];
int jihoon_moving[1005][1005];
char data[1005][1005];

bool out(int x, int y) // �ٱ����� �������  
{
	if(x <= 0 || x > r)
	{
		return true;
	}
	if(y <= 0 || y > c)
	{
		return true;
	}
	return false;
}
void fire_bfs()
{
	while(!fire_que.empty())
	{
		int x,y;
		x = fire_que.front().x;
		y = fire_que.front().y;	
		fire_que.pop();
		
		for(int i=0; i<4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];	
			
			// ���� ��� �ٱ����� ���� ���� ������� ����. �����̰� �ִ� ��ġ�� �̵��� �� �ִ� ���� ������ �� �ִ°��� Ȯ����. (���� �������� ��쿡 ���� ����� �ʿ���) 
			if(out(new_x,new_y) == false && (data[new_x][new_y] == '.' || data[new_x][new_y] == 'J') && (fire_moving[new_x][new_y] == -1 || fire_moving[new_x][new_y] > fire_moving[x][y] + 1))
			{
				fire_moving[new_x][new_y] = fire_moving[x][y] + 1;
				fire_que.push({new_x,new_y});
			}
		}
	}
}

void jihoon_bfs()
{
	queue <my_pair> jihoon_que;
	jihoon_que.push({j_x,j_y});
	jihoon_moving[j_x][j_y] = 0;
	
	while(!jihoon_que.empty())
	{
		int x,y;
		x = jihoon_que.front().x;
		y = jihoon_que.front().y;	
		jihoon_que.pop();
		
		for(int i=0; i<4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];	
			
			// �����̴� Ż���� �ʿ��� 
			if(out(new_x,new_y) == true)
			{
				printf("%d\n",jihoon_moving[x][y] + 1);
				return ;
			}
			// Ż���� ������ �ʴ� ���ų�, ����ġ�δ� �̵��� �� ����. ���� �ƿ� ���� ��쵵 ����� �ؾ���. 
			if(out(new_x,new_y) == false && (data[new_x][new_y] == '.') && jihoon_moving[new_x][new_y] == -1 && (fire_moving[new_x][new_y] == -1 || jihoon_moving[x][y] < fire_moving[new_x][new_y] - 1))
			{
				jihoon_moving[new_x][new_y] = jihoon_moving[x][y] + 1;
				jihoon_que.push({new_x,new_y});
			}
		}
	}
	printf("IMPOSSIBLE\n");
}
int main(void)
{
	scanf("%d %d",&r,&c);
	memset(fire_moving,-1,sizeof(fire_moving));
	memset(jihoon_moving,-1,sizeof(jihoon_moving));
	getchar();
	for(int i=1; i<=r; i++)
	{
		for(int j=1; j<=c+1; j++)
		{
			scanf("%c",&data[i][j]);
			if(data[i][j] == 'F') // ���� �������� ��Ȳ�� ����Ͽ� ó�� 
			{
				f_x = i;
				f_y = j;
				fire_que.push({f_x,f_y}); 
				fire_moving[f_x][f_y] = 0;
			}
			if(data[i][j] == 'J') // �����̴� 1�� 
			{
				j_x = i;
				j_y = j;
			}
		}
	}
	
	fire_bfs();

	jihoon_bfs();

	
	
}
