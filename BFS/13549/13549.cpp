/* 
https://www.acmicpc.net
Problem ID : 13549
BFS(Breadth first search)
*/

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int start_point,end_point; // 수빈 위치, 동생 위치 
int moving[100005]; // 도달하는데 걸린 시간 

bool safe(int x) // 좌표를 벗어나는 경우 확인. 
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
	moving[start_point] = 0; // 초기 위치는 0초안에 갈 수있음  
	
	while(!que.empty()) // 큐가 비어있지 않으면 반복 
	{
		int point = que.front();
		que.pop();
		
		if(point == end_point)
		{
			printf("%d\n",moving[end_point]);
			return ;
		}
		if(safe(point*2) == true && moving[point*2] == -1) // 순간이동은 0초 후에 2*x  위치 이동 
		{
			
			que.push(point*2);
			moving[point*2] = moving[point];
		}
		if(safe(point-1) == true && moving[point-1] == -1) // 1초 후에 x-1 위치로 이동 
		{
			que.push(point-1);
			moving[point-1] = moving[point] + 1;
		}	
		if(safe(point+1) == true && moving[point+1] == -1) // 1초 후에 x+1 위치로 이동 
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
	
