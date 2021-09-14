  
/* 
https://www.acmicpc.net
Problem ID : 11559
BFS(Breadth first search)
*/

#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
struct my_pair
{
	int x;
	int y;
};
string input[12];
int bfs_moving[12][10];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool safe(int x, int y)
{
	if(x < 0 || x > 11)
	{
		return false;
	}
	if(y < 0 || y > 5)
	{
		return false;
	}
	return true;
}
bool can_destory() // �ı��� �� �ִ� �ѿ䰡 �մ°�? 
{
	memset(bfs_moving,-1,sizeof(bfs_moving));
	queue <my_pair> que;
	vector <my_pair> find_list;
	int find_list_size;
	
	bool can_destory = false;
	
	for(int i=11; i>=0; i--)
	{
		for(int j=0; j<6; j++)
		{
			if(input[i][j] != '.') // ��� �ѿ並 Ž�� �ĺ��� �ִ´�. 
			{
				find_list.push_back({i,j});  
			}
		}
	}
	
	find_list_size = find_list.size();
	for(int i=0; i<find_list_size; i++)
	{
		vector <my_pair> clear_list; // ������ �ѿ丮��Ʈ 
		int find_x = find_list[i].x; // Ž���ϰ��� �ϴ� �ѿ��� x��ǥ ��ġ 
		int find_y = find_list[i].y; // y��ǥ ��ġ 
		int count = 0; // ���� �ͳ��� ���� ���� 
		
		if(bfs_moving[find_x][find_y] == -1) // �ش� �ѿ䰡 �湮�� ���� ������ queue�� �ְ� Ž���� �����Ѵ�. 
		{
			que.push({find_x,find_y}); // �湮�� �������� �ش� �ѿ並 queue�� �ִ´�. 
			clear_list.push_back({find_x,find_y}); // Ž���� ���� 
			bfs_moving[find_x][find_y] = 0; // 
			count++; // ���� 1�� ����(�ڱ� �ڽŰ� �����Ƿ�) 
			
			while(!que.empty())
			{
				int x = que.front().x;
				int y = que.front().y;
				que.pop();
				
				for(int i=0; i<4; i++)
				{
					int new_x = x + dx[i];
					int new_y = y + dy[i];
					
					if(safe(new_x,new_y) == true && input[x][y] == input[new_x][new_y] && bfs_moving[new_x][new_y] == -1) // ������ ƨ�ܳ����� �ʰ�  ���� �ѿ��̸鼭 �湮�� ���� ���� ��� 
					{
						bfs_moving[new_x][new_y] = bfs_moving[x][y] + 1; // �湮������ ǥ�� 
						que.push({new_x,new_y}); // ť�� ���� 
						clear_list.push_back({new_x,new_y}); // ���� ��� �߰���. 
						count++; // ���� �ѿ��̹Ƿ� ������ ������Ų��. 
					}
				}
			}
			
			if(count >= 4) // ���� �ѿ䰡 4�� ���ִ� ��� �ش� �迭���� �ѿ並 �����Ѵ�. 
			{
				int clear_list_size = clear_list.size();
				for(int j=0; j<clear_list_size; j++)
				{
					int clear_x = clear_list[j].x;
					int clear_y = clear_list[j].y;
				
					input[clear_x][clear_y] = '.';	
				}
				can_destory = true; // �ѿ䰡 �����Ǿ����Ƿ� ���� ���ɼ��� ����. 
			}
		}
	}
	// �ش� ���⿡�� ��� Ž���� ���� ���Ŀ� ���ʿ� �����ִ� �ѿ並 �������� �����. 

	
	for(int i=0; i<6; i++)
	{
		for(int j=11; j>=1; j--)
		{
			if(input[j][i] == '.') // �ش� ��ġ�� ������̸� ���� ����� ���� �ѿ並 �ش���ġ�� �������� �����. 
			{
				for(int k=j-1; k>=0; k--)
				{
					if(input[k][i] != '.')
					{
						input[j][i] = input[k][i];
						input[k][i] = '.';
						break;
					}
				}
			}
			else
			{
				continue;
			}
		}
	}
	
	return can_destory; // �ѿ��� ���� ���ο� ���� ���� ���θ� �Ǵ��Ѵ�. 
	
}
int main(void)
{
	int answer = 0;
	for(int i=0; i<12; i++)
	{
		cin >> input[i];
	}
	
	while(can_destory() == true)
	{
		answer++;
	}
	printf("%d\n",answer);
	
}
