/* 
https://www.acmicpc.net
Problem ID : 2668
DFS(Depth-First Search)
*/

#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> get_data;
int data[105];
bool visited[105];
bool maked[105];

void dfs(int i)
{
	visited[i] = true; 
	int target = data[i]; // ���� Ÿ��  
	
	if(visited[target] == false) // �ش� Ÿ�� �湮 ��� ������ �˻� 
	{
		dfs(target);
	}
	else
	{
		if(maked[target] == false) // �ش� Ÿ�ٿ� �湮 ��� ������, ��� Ȯ�� �ȉ�����  ����Ŭ Ȯ�� 
		{
			get_data.push_back(i);
			for(int j=target; j!=i; j=data[j]) // ����Ŭ������ ��� ��� Ȯ�� 
			{
				get_data.push_back(j);
			}
		}
	}
	maked[i] = true; // �ش� ��ġ�� ��� Ž�� Ȯ�� 
}
int main(void)
{
	int n;
	int data_len;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&data[i]);
	}
	
	for(int i=1; i<=n; i++)
	{
		if(visited[i] == false)
		{
			dfs(i);			
		}
	}
	
	data_len = get_data.size();
	printf("%d\n",data_len);
	sort(get_data.begin(),get_data.end()); // �湮 ��� ���� 
	for(int i=0; i<get_data.size(); i++)
	{
		printf("%d\n",get_data[i]);
	}
}
	
