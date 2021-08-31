/* 
https://www.acmicpc.net
Problem ID : 2668
DFS(Depth-First Search)
*/

#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> get_data;
int data[105];
bool visited[105];
bool maked[105];

void dfs(int i)
{
	visited[i] = true; 
	int target = data[i]; // 다음 타켓  
	
	if(visited[target] == false) // 해당 타겟 방문 사례 없으면 검색 
	{
		dfs(target);
	}
	else
	{
		if(maked[target] == false) // 해당 타겟에 방문 사례 있으나, 모두 확인 안됬으면  사이클 확인 
		{
			get_data.push_back(i);
			for(int j=target; j!=i; j=data[j]) // 사이클까지의 모든 노드 확인 
			{
				get_data.push_back(j);
			}
		}
	}
	maked[i] = true; // 해당 위치의 모든 탐색 확인 
}
int main(void)
{
	int n;
	int data_len;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&data[i]);
	}
	
	for(int i=1; i<=n; i++)
	{
		if(visited[i] == false)
		{
			dfs(i);			
		}
	}
	
	data_len = get_data.size();
	printf("%d\n",data_len);
	sort(get_data.begin(),get_data.end()); // 방문 경로 정렬 
	for(int i=0; i<get_data.size(); i++)
	{
		printf("%d\n",get_data[i]);
	}
}
	
