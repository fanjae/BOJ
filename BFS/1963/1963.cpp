/* 
https://www.acmicpc.net
Problem ID : 1963
BFS(Breadth first search)
*/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std; 
string start_string, end_string;
int prime[10005];
int move_count[10005]={0};
void eratos() // �����佺 �׳׽��� ü 
{
	for(int i=2; i<=9999; i++) // �迭 �ʱ�ȭ 
	{
		prime[i] = i;
	}
	
	for(int i=2; i<=9999; i++)
	{
		if(prime[i] == 0) // �̹� ���� ��� ���̻� ���� ���� 
		{
			continue;
		}
		
		for(int j=2*i; j<=9999; j+=i) // ����� �ش��ϸ� �ش� ���� �Ҽ��� �ƴ�. 
		{
			prime[j] = 0;
		}
	}
}
int main(void)
{
	int T;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	eratos();
	
	while(T--)
	{
		bool find_answer = false;
		int start_value;
		int end_value;
		cin >> start_string >> end_string;
		
		memset(move_count,-1,sizeof(move_count));
		start_value = stoi(start_string);
		end_value = stoi(end_string);		
	
		queue <int> que;
		que.push(start_value);
		move_count[start_value] = 0;
		
		while(!que.empty()) // ť�� ���� ���� ����. 
		{
			int temp = que.front();
			int after_temp = temp;
			string temp_string = to_string(temp);
			string after_temp_string = temp_string;
			que.pop();
			
			if(temp == end_value) // ���� �Ҽ��� ���� �� ���  
			{
				printf("%d\n",move_count[end_value]);
				find_answer = true;
				break;
			}
			
			for(int i=0; i<4; i++)
			{
				for(int j=0; j<=9; j++)
				{
					after_temp_string = temp_string;
					if(i == 0 && j == 0 || after_temp_string[i] == j) // �Ǿ��� 0�̰ų�, ��ȯ�Ϸ��� ���ڰ� ���� ��� 
					{
						continue;
					}
					else
					{
						after_temp_string[i] = j + '0';
						after_temp = stoi(after_temp_string);
						
						if(prime[after_temp] != 0 && move_count[after_temp] == -1) // �Ҽ��̸鼭 ������ ���� ���� �ƴ� ��� 
						{
							que.push(after_temp);
							move_count[after_temp] = move_count[temp] + 1;
						}
					}
				}
			}
		}
		if(find_answer == false) // ���� ���� ��� 
		{
			printf("Impossible\n");
		}	
	}
}
