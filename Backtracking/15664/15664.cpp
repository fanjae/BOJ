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
	if(cnt == m) // m�� ������� ��� 
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
		if(visited[i] == true) // �̹� �湮������ ���� 
		{
			continue;
		}
		if(last <= data[i]) // ���� ���� ���ڴ� ������ ũ�ų� ���ƾ� �Ѵ�. 
		{
			if(depth[data[i]] == false) // �ش� ��ġ�� �ش� ���ڰ� ���� ���� ���� ��� 
			{
				visited[i] = true; // �湮 ó�� 
				choose[cnt] = data[i]; // �ش� �� ���� 
				depth[data[i]] = true; // �ش� ��ġ�� �ش� ���� ���Դٴ� ��ʵ� �湮 ó��  
				back(cnt+1,data[i]);	
				visited[i] = false; // �湮 ó�� ���� 
				choose[cnt] = 0; // �ش� �� ������ �� ��� 
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
	
