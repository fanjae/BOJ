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
int moving[100005]; // 도달하는데 걸린 시간 
int path[100005]; // 최적의 시간으로 해당 경로에 도달하기 위한 이전값 경로 
stack <int> path_stk;

bool safe(int x) // 좌표 범위 초과여부 확인 함수 
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
	path[start_point] = start_point; // path 시작점  
	while(!que.empty())
	{
		int point = que.front();
		que.pop();
		
		if(point == end_point)
		{
			int x = point;
			path_stk.push(x); // 끝지점을 stack에 넣음 
				
			if(start_point != end_point)
			{
				while(path[x] != start_point) // 시작지점이 될때까지 반복 
				{
					path_stk.push(path[x]); // 최적 경로를 stack에 넣음. 
					x = path[x]; // 역순 추적을 위해 다음값을 가져옴. 
				}
				path_stk.push(start_point);	// 시작점을 넣음 
			}
			
			printf("%d\n",moving[point]);
			while(!path_stk.empty()) // stack에 저장된 경로 출력. 
			{
				printf("%d ",path_stk.top());
				path_stk.pop();
			}
			return ;
		}

		if(safe(point-1) == true && moving[point-1] == -1) // 1시간 이후 -1 지점 이동  
		{
			que.push(point-1);
			moving[point-1] = moving[point] + 1;
			path[point-1] = point;
		}	
		if(safe(point+1) == true && moving[point+1] == -1) // 1시간 이후 +1 지점 이동  
		{
			que.push(point+1);
			moving[point+1] = moving[point] + 1;
			path[point+1] = point;
		}				
		if(safe(point*2) == true && moving[point*2] == -1) // 1시간 이후 *2 지점 이동  
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
	
