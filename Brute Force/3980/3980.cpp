/* 
https://www.acmicpc.net
Problem ID : 3980
Brute Force & Backtracking
*/

#include <stdio.h>
#include <string.h>

int data[11][11];
int ans = 0;
bool visited[11]={0};

void back(int cnt, int value)
{
	if(ans > value && ans-value >= (11-cnt)*100) // 현재까지 최댓값이 현재 값보다 크면서 남은 포지션으로 합쳐도 안되면 가망 없음 
	{
		return ;
	}
	if(cnt == 11) // 11개의 포지션 모두 뽑은 경우  
	{
		if(ans < value) // 최대값 갱신 
		{
			ans = value;
		}
		return ;
	}
	
	for(int i=0; i<11; i++)
	{
		if(visited[i] == true) // 같은 포지션에 이미 선수 있으면 해당 위치는 뽑지 않음  
		{
			continue;
		}  
		if(data[cnt][i] != 0) // 선수가 해당 포지션에서 뛸 수 있는 경우 
		{ 
			visited[i] = true;
			back(cnt+1, value + data[cnt][i]);
			visited[i] = false;
		}
	}
}
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0; i<11; i++)
		{
			for(int j=0; j<11; j++)
			{
				scanf("%d",&data[i][j]);
			}
		}
		
		back(0,0);
		printf("%d\n",ans);
		
		// 사용한 변수 초기화 
		memset(data,0,sizeof(data));
		memset(visited,false,sizeof(visited));
		ans = 0; 
	}
}
 
