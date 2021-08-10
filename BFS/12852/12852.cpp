/* 
https://www.acmicpc.net
Problem ID : 12852
BFS(Breadth first search)
*/

#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

stack <int> path_stk;

int x[1000005];
int path[1000005];
int n;

void bfs()
{
	queue <int> que;
	que.push(n);
	x[n] = 0;
	
	while(!que.empty())
	{
		int x_value = que.front();
		que.pop();
		
		if(x_value == 1) 
		{
			printf("%d\n",x[x_value]); // ������ �ϴ� Ƚ���� �ּڰ� ��� 
			if(n == 1) // n�� 1�� ���, ����� �� 1�ۿ� �������� ����. 
			{
				printf("1");
			}
			else
			{
				path_stk.push(1); // 1�� ���ÿ� ���� 
				int target = path[1]; // 1�� ������ �����ߴ� ������ �޾ƿ�. 
				while(target != n) // n�� �ƴҶ� ���� �ݺ� �ϸ鼭 ������ 
				{
					path_stk.push(target);
					target = path[target]; // path�� ����Ǿ��ִ� ���� ��� �޾ƿ� 
				}
				path_stk.push(n); // n���� ���ÿ� ����. 
				
				while(!path_stk.empty()) // ���ÿ� ����� ���� ��� 
				{
					printf("%d ",path_stk.top());
					path_stk.pop();
				}
			}
			return ;	
		}
		if(x_value % 3 == 0 && x[x_value / 3] == -1) // 3���� ���� �������� 3���� ������. 
		{
			x[x_value / 3] = x[x_value] + 1;
			path[x_value / 3] = x_value;
			que.push(x_value / 3);
		}
		if(x_value % 2 == 0 && x[x_value / 2] == -1) // 2�� ���� �������� 2�� ������. 
		{
			x[x_value / 2] = x[x_value] + 1;
			path[x_value / 2] = x_value;
			que.push(x_value / 2);			
		}
		if(x[x_value - 1] == -1) // 1�� ����. 
		{
			x[x_value - 1] = x[x_value] + 1;
			path[x_value - 1] = x_value;
			que.push(x_value - 1);					
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	memset(x,-1,sizeof(x));	
	bfs();
}
	
