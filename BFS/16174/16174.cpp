/* 
https://www.acmicpc.net
Problem ID : 16174
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
int n;
int move_count[70][70]; // �ش� ��ġ�� ���� �� �� �ִ°�? 
int data[70][70]; // �ش� ĭ�� �����ִ� �̵� Ƚ�� 

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
		
		if(x == n && y == n) // ���������� ������ ��� 
		{
			printf("HaruHaru\n");
			return ;
		}
		int new_x = x + data[x][y]; // ���� �ش� ��ġ�� �ִ�ĭ ��ŭ �̵��Ѵ�. 
		int new_y = y + data[x][y]; // ���� �ش� ��ġ�� �ִ� ĭ ��ŭ �̵��Ѵ�. 
		
		if(safe(new_x,y) == true && move_count[new_x][y] == -1) // �Ʒ��� ������ �� �ִ� ��� 
		{
			move_count[new_x][y] = 1;
			que.push({new_x,y});
		}
		if(safe(x,new_y) == true && move_count[x][new_y] == -1) // ���������� �̵��� �� �ִ� ��� 
		{
			move_count[x][new_y] = 1;
			que.push({x,new_y});
		}
	}
	//���������� �������� ���� ��� 
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
