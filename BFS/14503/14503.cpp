/* 
https://www.acmicpc.net
Problem ID : 14503
BFS(Breadth first search)
*/

#include <stdio.h>
#include <iostream>
#include <stdbool.h>

int ans = 0;
int n,m;
int robot_x,robot_y,robot_direction;
int data[55][55];

int dx[4]={-1,0,1,0}; // ����(��,��,��,��) 
int dy[4]={0,1,0,-1};

bool safe(int x, int y)
{
	if(x < 0 && x >= n)
	{
		return false;
	}
	if(y < 0 && y >= m)
	{
		return false;
	}
	return true;
}
void clean(int x, int y, int direction)
{
	// û�� ���� 
	if(data[x][y] == 0)
	{
		data[x][y] = 2;
		ans++;
	}
	
	// ���ʺ��� Ž�� ���� 
	for(int i=0; i<4; i++)
	{
		int new_x = x + dx[(direction + 3 - i) % 4];
		int new_y = y + dy[(direction + 3 - i) % 4];
		
		if(safe(new_x,new_y) == false)
		{
			continue;
		}
		
		if(data[new_x][new_y] == 0) // ���� û�� ���� ���� �׹��� ȸ�� 
		{
			clean(new_x,new_y,(direction + 3 - i) % 4);
		}
	}
	
	// 4���� ��� û�� �Ǿ�����. ����.  
	int new_x = x + dx[(direction + 2) % 4]; 
	int new_y = y + dy[(direction + 2) % 4];
	if(data[new_x][new_y] == 1) // ���� ��� ���� �Ұ� ����. 
	{
		printf("%d\n",ans);
		exit(0);
	}
	clean(new_x,new_y,direction);
}
int main(void)
{
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&robot_x,&robot_y,&robot_direction);
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	
	clean(robot_x,robot_y,robot_direction);
}
