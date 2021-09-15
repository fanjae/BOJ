/* 
https://www.acmicpc.net
Problem ID : 2210
DFS(Depth-First Search)
*/

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

map <string, bool> string_map; // 가능한 여섯자리의 수를 담을 맵  
int data[6][6];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int answer = 0;
bool safe(int x, int y)
{
	if(x < 1 || x > 5)
	{
		return false;
	}
	if(y < 1 || y > 5)
	{
		return false;
	}
	return true;
}

void dfs(int x, int y, int length, string key)
{
	int str_length = key.length();
	string temp = key;
	
	if(str_length == 6) // 길이가 6이 되면, 해당 값이 나왔었는지 확인한다. 
	{
		if(string_map.find(key) == string_map.end()) // 없었으면 가능한 경우의 수 증가 
		{
			string_map[key] = true;
			answer++;
		}
		return ;	
	}
	for(int i=0; i<4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		
		if(safe(new_x,new_y) == true) // 벽으로 넘어가지 않았으면 dfs로 추가 탐색 
		{
			temp = key + (char) (data[new_x][new_y] + '0');
			dfs(new_x,new_y,length+1,temp);	
		}
	}
}
int main(void)
{
	string temp;
	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=5; j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	
	for(int i=1; i<=5; i++) // 하나씩 확인하러 들어간다. 
	{
		for(int j=1; j<=5; j++) 
		{
			temp = data[i][j] + '0';
			dfs(i,j,0,temp);
		}
	}
	printf("%d\n",answer);
}
