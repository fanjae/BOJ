/* 
https://www.acmicpc.net
Problem ID : 15663
Backtracking
*/

#include <stdio.h>
#include <algorithm>

using namespace std;
int data[10];
int output[10];
bool visited[10];
int n,m;

void back(int cnt)
{
	bool depth[10005]={0}; // 같은 depth에서 중복 방문을 허용하지 않기 위해 변수 선언 
	if(cnt == m) // 임의의 m개를 뽑은 경우  
	{
		for(int i=0; i<m; i++) // 결과 출력 
		{
			printf("%d ",output[i]);
		}
		printf("\n");
		return ;
	}	
	
	for(int i=0; i<n; i++)
	{
		if(visited[i] == true || depth[data[i]] == true) // i번째에 방문한 적 있거나, 해당 숫자를 같은 depth에서 사용한적이 있는가? 
		{
			continue;
		}
		visited[i] = true; // 방문 체크 
		depth[data[i]] = true;
		output[cnt] = data[i];
		
		back(cnt+1); // 탐색 
		visited[i] = false; // 방문 여부 해제. 같은 depth에서 방문했던 숫자는 방문 여부 해제하지 않음에 유의 
		output[cnt] = 0;
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
	
	back(0);
}
