/* 
https://www.acmicpc.net
Problem ID : 15665
Backtracking
*/

#include <stdio.h>
#include <algorithm>

using namespace std;
int n,m;
int data[10];
int choose[10];
void back(int cnt)
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
		if(depth[data[i]] == false) // 해당 위치에 해당 숫자가 나온 적이 없는 경우 
		{
			choose[cnt] = data[i]; // 해당 값 선택 
			depth[data[i]] = true; // 해당 위치에 해당 숫자 나왔다는 사례도 방문 처리  
			back(cnt+1);	
			choose[cnt] = 0; // 해당 값 선택한 것 취소 
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
	back(0);
}
	
