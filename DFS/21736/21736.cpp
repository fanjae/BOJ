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
bool safe(int x, int y) // 캠퍼스 안쪽 여부 확인함수 
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
		
		// 캠퍼스 밖으로 나가거나, 이미 방문한 곳이거나, 벽이 아닌 경우만 이동 
		if(safe(new_x,new_y) == true && visited[new_x][new_y] == false && data[new_x][new_y] != 'X')
		{
			visited[new_x][new_y] = true;
			if(data[new_x][new_y] == 'P') // 사람을 만난 경우 cnt 증가 
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
			if(data[i][j] == 'I') // 도연이의 위치 설정 
			{
				start_x = i;
				start_y = j;
			}
		}
	}
	visited[start_x][start_y] = true; // 도연이의 위치 방문 확인 
	dfs(start_x,start_y); 
	
	if(cnt == 0) // 아무도 만나지 못한 경우 
	{
		printf("TT\n");
	}
	else
	{
		printf("%d\n",cnt);
	}
}
