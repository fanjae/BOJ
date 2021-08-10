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
			printf("%d\n",x[x_value]); // 연산을 하는 횟수의 최솟값 출력 
			if(n == 1) // n이 1인 경우, 방법은 딱 1밖에 존재하지 않음. 
			{
				printf("1");
			}
			else
			{
				path_stk.push(1); // 1을 스택에 넣음 
				int target = path[1]; // 1번 이전에 진행했던 연산을 받아옴. 
				while(target != n) // n이 아닐때 까지 반복 하면서 역추적 
				{
					path_stk.push(target);
					target = path[target]; // path에 저장되어있는 값을 계속 받아옴 
				}
				path_stk.push(n); // n값만 스택에 받음. 
				
				while(!path_stk.empty()) // 스택에 저장된 내용 출력 
				{
					printf("%d ",path_stk.top());
					path_stk.pop();
				}
			}
			return ;	
		}
		if(x_value % 3 == 0 && x[x_value / 3] == -1) // 3으로 나눠 떨어지면 3으로 나눈다. 
		{
			x[x_value / 3] = x[x_value] + 1;
			path[x_value / 3] = x_value;
			que.push(x_value / 3);
		}
		if(x_value % 2 == 0 && x[x_value / 2] == -1) // 2로 나눠 떨어지면 2로 나눈다. 
		{
			x[x_value / 2] = x[x_value] + 1;
			path[x_value / 2] = x_value;
			que.push(x_value / 2);			
		}
		if(x[x_value - 1] == -1) // 1을 뺀다. 
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
	
