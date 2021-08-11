/* 
https://www.acmicpc.net
Problem ID : 15971
BFS(Breadth first search)
*/

#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct data // 연결된 경로 및 비용 
{
	int number;
	int cost_value;
};

vector <data> node[100005];
stack <int> path_stk;
int n, start_point, end_point;
int path[100005];
int cost[100005];
int cost2[100005];

void bfs()
{
	int max_value = 0;
	queue <int> que;
	que.push(start_point);
	cost[start_point] = 0;
	
	while(!que.empty())
	{
		int x = que.front();
		int size = node[x].size();
		que.pop();
		
		if(x == end_point) // 끝에 도달한 경우 
		{
			int target = end_point;
			while(target != start_point) // 경로 역추적. 
			{
				path_stk.push(target);
				target = path[target];
			}
			path_stk.push(start_point);
			
			while(!path_stk.empty()) // 역추적한 경로를 토대로 가장 큰 값만 제외 
			{
				if(cost2[path_stk.top()] > max_value)
				{
					max_value = cost2[path_stk.top()];
				}
				path_stk.pop();
			}
			printf("%d\n",cost[end_point] - max_value);
			return ;
		}
		
		for(int i=0; i<size; i++)
		{
			if(cost[node[x][i].number] == -1)
			{
				que.push(node[x][i].number);
				cost[node[x][i].number] = cost[x] + node[x][i].cost_value; // 해당 경로까지 가는데 드는 누적 비용 
				cost2[node[x][i].number] = node[x][i].cost_value; // 해당 경로를 갈때 들었던 순수 비용  
				path[node[x][i].number] = x; // 해당 경로를 가기 위한 최적 경로 
			}
		}
	}
}
int main(void)
{
	
	scanf("%d %d %d",&n,&start_point,&end_point);
	for(int i=0; i<n-1; i++)
	{
		int x, y, value;
		scanf("%d %d %d",&x,&y,&value);
		node[x].push_back({y,value});
		node[y].push_back({x,value});
	}
	memset(cost,-1,sizeof(cost));
	bfs();
}
