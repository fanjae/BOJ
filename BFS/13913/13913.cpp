/* 
https://www.acmicpc.net
Problem ID : 13913
BFS(Breadth first search)
*/

#include <stdio.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int start_point,end_point;
int moving[100005]; // �����ϴµ� �ɸ� �ð� 
int path[100005]; // ������ �ð����� �ش� ��ο� �����ϱ� ���� ������ ��� 
stack <int> path_stk;

bool safe(int x) // ��ǥ ���� �ʰ����� Ȯ�� �Լ� 
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
	que.push(start_point); //  
	moving[start_point] = 0; // 
	path[start_point] = start_point; // path ������  
	while(!que.empty())
	{
		int point = que.front();
		que.pop();
		
		if(point == end_point)
		{
			int x = point;
			path_stk.push(x); // �������� stack�� ���� 
				
			if(start_point != end_point)
			{
				while(path[x] != start_point) // ���������� �ɶ����� �ݺ� 
				{
					path_stk.push(path[x]); // ���� ��θ� stack�� ����. 
					x = path[x]; // ���� ������ ���� �������� ������. 
				}
				path_stk.push(start_point);	// �������� ���� 
			}
			
			printf("%d\n",moving[point]);
			while(!path_stk.empty()) // stack�� ����� ��� ���. 
			{
				printf("%d ",path_stk.top());
				path_stk.pop();
			}
			return ;
		}

		if(safe(point-1) == true && moving[point-1] == -1) // 1�ð� ���� -1 ���� �̵�  
		{
			que.push(point-1);
			moving[point-1] = moving[point] + 1;
			path[point-1] = point;
		}	
		if(safe(point+1) == true && moving[point+1] == -1) // 1�ð� ���� +1 ���� �̵�  
		{
			que.push(point+1);
			moving[point+1] = moving[point] + 1;
			path[point+1] = point;
		}				
		if(safe(point*2) == true && moving[point*2] == -1) // 1�ð� ���� *2 ���� �̵�  
		{
			que.push(point*2);
			moving[point*2] = moving[point] + 1;
			path[point*2] = point;
		}
	}
}
int main(void)
{
	scanf("%d %d",&start_point,&end_point);
	memset(moving,-1,sizeof(moving));
	bfs();
}
	
