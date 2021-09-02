/* 
https://www.acmicpc.net
Problem ID : 21736
DFS(Depth-First Search)
*/

#include <stdio.h>
char data[605][605];
bool visited[605][605];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int start_x, start_y;
int n,m;
int cnt = 0;
bool safe(int x, int y) // ķ�۽� ���� ���� Ȯ���Լ� 
{
	if(x <= 0 || x > n)
	{
		return false;
	}
	if(y <= 0 || y > m)
	{
		return false;
	}
	return true;
}
void dfs(int x, int y)
{
	for(int i=0; i<4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		
		// ķ�۽� ������ �����ų�, �̹� �湮�� ���̰ų�, ���� �ƴ� ��츸 �̵� 
		if(safe(new_x,new_y) == true && visited[new_x][new_y] == false && data[new_x][new_y] != 'X')
		{
			visited[new_x][new_y] = true;
			if(data[new_x][new_y] == 'P') // ����� ���� ��� cnt ���� 
			{
				cnt++;
			}
			dfs(new_x,new_y);	
		}
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		getchar();
		for(int j=1; j<=m; j++)
		{
			scanf("%c",&data[i][j]);
			if(data[i][j] == 'I') // �������� ��ġ ���� 
			{
				start_x = i;
				start_y = j;
			}
		}
	}
	visited[start_x][start_y] = true; // �������� ��ġ �湮 Ȯ�� 
	dfs(start_x,start_y); 
	
	if(cnt == 0) // �ƹ��� ������ ���� ��� 
	{
		printf("TT\n");
	}
	else
	{
		printf("%d\n",cnt);
	}
}
