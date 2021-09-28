/* 
https://www.acmicpc.net
Problem ID : 15664
Backtracking
*/

#include <stdio.h>
#include <algorithm>

using namespace std;
int n,m;
int data[10];
bool visited[10];
int choose[10];
void back(int cnt, int last)
{
	bool depth[10005]={0};
	if(cnt == m) // m개 골랐으면 출력 
	{
		for(int i=0; i<m; i++)
		{
			printf("%d ",choose[i]);
		}
		printf("\n");
		return ;
	}
	
	for(int i=0; i<n; i++)
	{
		if(visited[i] == true) // 이미 방문됬으면 생략 
		{
			continue;
		}
		if(last <= data[i]) // 다음 나올 숫자는 무조건 크거나 같아야 한다. 
		{
			if(depth[data[i]] == false) // 해당 위치에 해당 숫자가 나온 적이 없는 경우 
			{
				visited[i] = true; // 방문 처리 
				choose[cnt] = data[i]; // 해당 값 선택 
				depth[data[i]] = true; // 해당 위치에 해당 숫자 나왔다는 사례도 방문 처리  
				back(cnt+1,data[i]);	
				visited[i] = false; // 방문 처리 해제 
				choose[cnt] = 0; // 해당 값 선택한 것 취소 
			}
		}
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&data[i]);	
	}
	
	sort(data,data+n);
	back(0,0);
}
	
