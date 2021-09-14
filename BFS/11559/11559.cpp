  
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
bool can_destory() // 파괴할 수 있는 뿌요가 잇는가? 
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
			if(input[i][j] != '.') // 모든 뿌요를 탐색 후보로 넣는다. 
			{
				find_list.push_back({i,j});  
			}
		}
	}
	
	find_list_size = find_list.size();
	for(int i=0; i<find_list_size; i++)
	{
		vector <my_pair> clear_list; // 삭제할 뿌요리스트 
		int find_x = find_list[i].x; // 탐색하고자 하는 뿌요의 x좌표 위치 
		int find_y = find_list[i].y; // y좌표 위치 
		int count = 0; // 같은 것끼리 모인 개수 
		
		if(bfs_moving[find_x][find_y] == -1) // 해당 뿌요가 방문된 적이 없을때 queue에 넣고 탐색을 진행한다. 
		{
			que.push({find_x,find_y}); // 방문된 적없으면 해당 뿌요를 queue에 넣는다. 
			clear_list.push_back({find_x,find_y}); // 탐색을 시작 
			bfs_moving[find_x][find_y] = 0; // 
			count++; // 개수 1개 증가(자기 자신과 같으므로) 
			
			while(!que.empty())
			{
				int x = que.front().x;
				int y = que.front().y;
				que.pop();
				
				for(int i=0; i<4; i++)
				{
					int new_x = x + dx[i];
					int new_y = y + dy[i];
					
					if(safe(new_x,new_y) == true && input[x][y] == input[new_x][new_y] && bfs_moving[new_x][new_y] == -1) // 밖으로 튕겨나가지 않고  같은 뿌요이면서 방문한 적이 없는 경우 
					{
						bfs_moving[new_x][new_y] = bfs_moving[x][y] + 1; // 방문했음을 표기 
						que.push({new_x,new_y}); // 큐에 넣음 
						clear_list.push_back({new_x,new_y}); // 제거 대상에 추가함. 
						count++; // 같은 뿌요이므로 개수를 증가시킨다. 
					}
				}
			}
			
			if(count >= 4) // 같은 뿌요가 4개 모여있는 경우 해당 배열에서 뿌요를 제거한다. 
			{
				int clear_list_size = clear_list.size();
				for(int j=0; j<clear_list_size; j++)
				{
					int clear_x = clear_list[j].x;
					int clear_y = clear_list[j].y;
				
					input[clear_x][clear_y] = '.';	
				}
				can_destory = true; // 뿌요가 삭제되었으므로 연쇄 가능성을 본다. 
			}
		}
	}
	// 해당 연쇄에서 모든 탐색이 끝난 이후에 윗쪽에 남아있던 뿌요를 내려오게 만든다. 

	
	for(int i=0; i<6; i++)
	{
		for(int j=11; j>=1; j--)
		{
			if(input[j][i] == '.') // 해당 위치가 빈공간이면 가장 가까운 윗쪽 뿌요를 해당위치로 내려오게 만든다. 
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
	
	return can_destory; // 뿌요의 삭제 여부에 따라서 제거 여부를 판단한다. 
	
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
