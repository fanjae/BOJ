/* 
https://www.acmicpc.net
Problem ID : 1388
BFS(Breadth first search)
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

string data[105];
int cnt = 0;
int n,m;
int target_x, target_y;
bool visited[105][105];

struct my_pair
{
	int x;
	int y;
};


bool safe(int x, int y) // 충돌 여부 판단 
{
	if(x < 0 || x >= n)
	{
		return false;
	}
	if(y < 0 || y >= m)
	{
		return false;
	}
	return true;
}

void bfs()
{
	queue <my_pair> que;
	que.push({target_x,target_y}); // 큐에 넣음 
	
	while(!que.empty())
	{
		int x = que.front().x;
		int y = que.front().y;
		que.pop();
		
		if(data[x][y] == '-') // -일때는 같은행인지 확인 
		{
			int new_y = y + 1;
			if(safe(x,new_y) == true && data[x][new_y] == '-')
			{
				visited[x][new_y] = true;
				que.push({x,new_y});
			}
		}
		else if(data[x][y] == '|') // |일때는 같은 열인지 확인 
		{
			int new_x = x + 1;
			if(safe(new_x,y) == true && data[new_x][y] == '|')
			{
				visited[new_x][y] = true;
				que.push({new_x,y});
			}
		}
	}
}
int main(void)
{
	
	
	// C++ 입출력 속도 높이기 
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> data[i];
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(visited[i][j] == false)
			{
				visited[i][j] = true;
				target_x = i;
				target_y = j;
				cnt++; // 같은 종류 개수 증가 
				
				bfs();	
				
			}
		}
	}
	cout << cnt << "\n";
}
