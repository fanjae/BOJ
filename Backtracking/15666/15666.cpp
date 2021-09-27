/* 
https://www.acmicpc.net
Problem ID : 15666
Backtracking
*/

#include <stdio.h>
#include <algorithm>

using namespace std;
int data[10];
int output[10];
int n,m;

void back(int cnt, int last)
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
		if(depth[data[i]] == true) // 해당 숫자를 같은 depth에서 사용한적이 있는가? 
		{
			continue;
		}
		if(last > data[i]) // 다음 숫자가 이전보다 커야한다. (비내림차순) 
		{
			continue;
		}
		depth[data[i]] = true;
		output[cnt] = data[i];
		
		back(cnt+1,data[i]); // 탐색 
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
	
	back(0,0);
}
