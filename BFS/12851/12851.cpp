/* 
https://www.acmicpc.net
Problem ID : 12851
BFS(Breadth first search)
*/

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
int moving[100005];
int n,k;
int ans_time = 0;
int ans_count = 0;
int safe(int x) // 범위 초과 여부 확인 함수 
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
	que.push(n);
	
	while(!que.empty())
	{
		int point = que.front();
		que.pop();
		
		if(ans_time != 0 && ans_time < moving[point]) // 이동 횟수가 최단 거리를 넘어간 경우 모두 계산된 상태  
		{
			printf("%d\n%d\n",ans_time,ans_count);
			return ;
		}
		
		if(point == k) // 도착지점에 온 경우. 
		{
			ans_time = moving[point];
			ans_count++;
		}
		
		if(safe(point+1) == true && (moving[point+1] == -1 || moving[point+1] >= moving[point] + 1)) // +1 이동 
		{
			que.push(point+1);
			moving[point+1] = moving[point] + 1;
		}
		if(safe(point-1) == true && (moving[point-1] == -1 || moving[point-1] >= moving[point] + 1)) // -1 이동 
		{
			que.push(point-1);
			moving[point-1] = moving[point] + 1;
		}
		if(safe(point*2) == true && (moving[point*2] == -1 || moving[point*2] >= moving[point] + 1)) // *2 이동 
		{
			que.push(point*2);
			moving[point*2] = moving[point] + 1;	
		}
	}
	// 수빈이가 +1 또는 -1로 이동할 수 있기 때문에 탈출 불가능한 경우는 존재하지 않음.
	// 단, 100000 -> 0과 같은 케이스는 예외처리 필요. 
	printf("%d\n%d\n",ans_time,ans_count);
	return ;	
}
int main(void)
{
	scanf("%d %d",&n,&k);
	memset(moving,-1,sizeof(moving));
	moving[n] = 0;
	bfs();
}
