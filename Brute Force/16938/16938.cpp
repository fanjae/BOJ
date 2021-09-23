/* 
https://www.acmicpc.net
Problem ID : 16938
Brute Force & Backtracking
*/

#include <stdio.h>
int n,l,r,x;
int data[20];
int answer_cnt = 0;
bool visited[20]={0};

void back(int cnt,int pos,int sum, int min_problem, int max_problem)
{
	int before_min = min_problem; // 이전 최소 난이도 값 
	int before_max = max_problem; // 이전 최고 난이도 값 
	if(cnt >= 2) // 2개 이상인 경우 확인 
	{
		if(max_problem - min_problem >= x && sum >= l && sum <= r) // 최고 난이도와 최소 난이도 차이 및 난이도 합으로 경우의 수 확인 
		{
			answer_cnt++;
		}
		if(cnt == n) // 최대 개수만큼 골랐으면 그만 고름 
		{
			return ;
		}
	}
	
	for(int i=pos+1; i<=n; i++) // 현재 문제 이후 것을 본다. 
	{
		if(visited[i] == true) // 이미 골랐다면 넘어간다. 
		{
			continue;
		}
		
		visited[i] = true;
		if(min_problem == 0 || min_problem > data[i]) // 최소 난이도 값 갱신 
		{
			min_problem = data[i];
		}
		if(max_problem == 0 || max_problem < data[i]) // 최고 난이도 값 갱신 
		{
			max_problem = data[i];
		}
		back(cnt+1,i,sum + data[i],min_problem,max_problem); // 탐색 
		visited[i] = false; // 탐색 리셋 
		min_problem = before_min; // 최소 난이도 문제 원상태 복귀 
		max_problem = before_max; // 최고 난이도 문제 원상태 복귀 
	}
}	
int main(void)
{
	scanf("%d %d %d %d",&n,&l,&r,&x);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&data[i]);
	}
	
	back(0,0,0,0,0);
	printf("%d\n",answer_cnt);
}
