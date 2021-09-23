/* 
https://www.acmicpc.net
Problem ID : 3980
Brute Force & Backtracking
*/

#include <stdio.h>
#include <string.h>

int data[11][11];
int ans = 0;
bool visited[11]={0};

void back(int cnt, int value)
{
	if(ans > value && ans-value >= (11-cnt)*100) // ������� �ִ��� ���� ������ ũ�鼭 ���� ���������� ���ĵ� �ȵǸ� ���� ���� 
	{
		return ;
	}
	if(cnt == 11) // 11���� ������ ��� ���� ���  
	{
		if(ans < value) // �ִ밪 ���� 
		{
			ans = value;
		}
		return ;
	}
	
	for(int i=0; i<11; i++)
	{
		if(visited[i] == true) // ���� �����ǿ� �̹� ���� ������ �ش� ��ġ�� ���� ����  
		{
			continue;
		}  
		if(data[cnt][i] != 0) // ������ �ش� �����ǿ��� �� �� �ִ� ��� 
		{ 
			visited[i] = true;
			back(cnt+1, value + data[cnt][i]);
			visited[i] = false;
		}
	}
}
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0; i<11; i++)
		{
			for(int j=0; j<11; j++)
			{
				scanf("%d",&data[i][j]);
			}
		}
		
		back(0,0);
		printf("%d\n",ans);
		
		// ����� ���� �ʱ�ȭ 
		memset(data,0,sizeof(data));
		memset(visited,false,sizeof(visited));
		ans = 0; 
	}
}
 
