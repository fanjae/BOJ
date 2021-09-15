#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

map <string, bool> string_map;
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
	
	if(str_length == 6)
	{
		if(string_map.find(key) == string_map.end())
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
		
		if(safe(new_x,new_y) == true)
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
	
	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=5; j++)
		{
			temp = data[i][j] + '0';
			dfs(i,j,0,temp);
		}
	}
	printf("%d\n",answer);
}
