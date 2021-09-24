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
	bool depth[10005]={0}; // ���� depth���� �ߺ� �湮�� ������� �ʱ� ���� ���� ���� 
	if(cnt == m) // ������ m���� ���� ���  
	{
		for(int i=0; i<m; i++) // ��� ��� 
		{
			printf("%d ",output[i]);
		}
		printf("\n");
		return ;
	}	
	
	for(int i=0; i<n; i++)
	{
		if(visited[i] == true || depth[data[i]] == true) // i��°�� �湮�� �� �ְų�, �ش� ���ڸ� ���� depth���� ��������� �ִ°�? 
		{
			continue;
		}
		visited[i] = true; // �湮 üũ 
		depth[data[i]] = true;
		output[cnt] = data[i];
		
		back(cnt+1); // Ž�� 
		visited[i] = false; // �湮 ���� ����. ���� depth���� �湮�ߴ� ���ڴ� �湮 ���� �������� ������ ���� 
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
