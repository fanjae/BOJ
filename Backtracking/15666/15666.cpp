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
		if(depth[data[i]] == true) // �ش� ���ڸ� ���� depth���� ��������� �ִ°�? 
		{
			continue;
		}
		if(last > data[i]) // ���� ���ڰ� �������� Ŀ���Ѵ�. (�񳻸�����) 
		{
			continue;
		}
		depth[data[i]] = true;
		output[cnt] = data[i];
		
		back(cnt+1,data[i]); // Ž�� 
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
