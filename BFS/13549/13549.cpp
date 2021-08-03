/* 
https://www.acmicpc.net
Problem ID : 13549
BFS(Breadth first search)
*/

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int start_point,end_point; // ���� ��ġ, ���� ��ġ 
int moving[100005]; // �����ϴµ� �ɸ� �ð� 

bool safe(int x) // ��ǥ�� ����� ��� Ȯ��. 
{
	if(x < 0 || x > 100000)
	{
		return false;
	}
	return true;
}
void bfs()
{
	queue <int> que;
	que.push(start_point);
	moving[start_point] = 0; // �ʱ� ��ġ�� 0�ʾȿ� �� ������  
	
	while(!que.empty()) // ť�� ������� ������ �ݺ� 
	{
		int point = que.front();
		que.pop();
		
		if(point == end_point)
		{
			printf("%d\n",moving[end_point]);
			return ;
		}
		if(safe(point*2) == true && moving[point*2] == -1) // �����̵��� 0�� �Ŀ� 2*x  ��ġ �̵� 
		{
			
			que.push(point*2);
			moving[point*2] = moving[point];
		}
		if(safe(point-1) == true && moving[point-1] == -1) // 1�� �Ŀ� x-1 ��ġ�� �̵� 
		{
			que.push(point-1);
			moving[point-1] = moving[point] + 1;
		}	
		if(safe(point+1) == true && moving[point+1] == -1) // 1�� �Ŀ� x+1 ��ġ�� �̵� 
		{
			que.push(point+1);
			moving[point+1] = moving[point] + 1;
		}				

	}
}
int main(void)
{
	scanf("%d %d",&start_point,&end_point);
	memset(moving,-1,sizeof(moving));
	
	bfs();
}
	
