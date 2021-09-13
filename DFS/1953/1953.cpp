/* 
https://www.acmicpc.net
Problem ID : 1953
DFS(Depth-First Search)
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n;
bool hate[105][105]={0};
int team[105]={0};
vector <int> blue;
vector <int> white;

void dfs(int target, int team_color)
{
	for(int i=1; i<=n; i++)
	{
		if(hate[target][i] == true && team[i] == 0)
		{
			team[i] = team_color * -1;
			dfs(i, team_color * -1); 	
		}
	}
}
void create_team()
{
	for(int i=1; i<=n; i++)
	{
		int white_size = white.size();
		if(white_size == 0 && i == n)
		{
			white.push_back(i);
			break;
		}
		
		if(team[i] == 1)
		{
			blue.push_back(i);
		}
		else if(team[i] == -1)
		{
			white.push_back(i);
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int value;
		scanf("%d",&value);
		for(int j=0; j<value; j++)
		{
			int temp;
			scanf("%d",&temp);
			hate[i][temp] = true;
			hate[temp][i] = true;
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		if(team[i] == 0)
		{
			team[i] = 1;
			dfs(i,1);
		}
	}
	create_team();
	
	int blue_size = blue.size();
	int white_size = white.size();

	printf("%d\n",blue_size);
	for(int i=0; i<blue_size; i++)
	{
		printf("%d ",blue[i]);
	}
	printf("\n%d\n",white_size);
	for(int i=0; i<white_size; i++)
	{
		printf("%d ",white[i]);
	}
}
