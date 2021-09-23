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
	int before_min = min_problem; // ���� �ּ� ���̵� �� 
	int before_max = max_problem; // ���� �ְ� ���̵� �� 
	if(cnt >= 2) // 2�� �̻��� ��� Ȯ�� 
	{
		if(max_problem - min_problem >= x && sum >= l && sum <= r) // �ְ� ���̵��� �ּ� ���̵� ���� �� ���̵� ������ ����� �� Ȯ�� 
		{
			answer_cnt++;
		}
		if(cnt == n) // �ִ� ������ŭ ������� �׸� �� 
		{
			return ;
		}
	}
	
	for(int i=pos+1; i<=n; i++) // ���� ���� ���� ���� ����. 
	{
		if(visited[i] == true) // �̹� ����ٸ� �Ѿ��. 
		{
			continue;
		}
		
		visited[i] = true;
		if(min_problem == 0 || min_problem > data[i]) // �ּ� ���̵� �� ���� 
		{
			min_problem = data[i];
		}
		if(max_problem == 0 || max_problem < data[i]) // �ְ� ���̵� �� ���� 
		{
			max_problem = data[i];
		}
		back(cnt+1,i,sum + data[i],min_problem,max_problem); // Ž�� 
		visited[i] = false; // Ž�� ���� 
		min_problem = before_min; // �ּ� ���̵� ���� ������ ���� 
		max_problem = before_max; // �ְ� ���̵� ���� ������ ���� 
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
