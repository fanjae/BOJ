#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int n,m;
bool red = true;
bool is_answer = true;
short visited[20005];
vector <int> vec[20005];

void dfs(int x)
{
	int connect_size = vec[x].size(); 
	for(int i=0; i<connect_size; i++)
	{
		if(visited[vec[x][i]] == -1)
		{
			visited[vec[x][i]] = red;
			red = !red;
			dfs(vec[x][i]);
		}
		else if(visited[x] == visited[vec[x][i]] && is_answer == true)
		{
			is_answer = false;
			printf("NO\n");
			return ;
		}
	}
}
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(visited,-1,sizeof(visited));
		scanf("%d %d",&n,&m);
		
		for(int i=1; i<=n; i++)
		{
			vec[i].clear();
		}
		for(int i=1; i<=m; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		
		for(int i=1; i<=n; i++)
		{
			if(visited[i] == -1)
			{
				visited[i] = red;
				red = !red;
				dfs(i);
				
				if(is_answer == false)
				{
					break;
				}
			}
		}
		
		if(is_answer == true)
		{
			printf("YES\n");	
		}
		
		is_answer = true;
	}
}
