/* 
https://www.acmicpc.net
Problem ID : 1039
BFS(Breadth first search)
*/

#include <iostream>
#include <string.h>
#include <queue>
#include <map>

using namespace std;

struct my_pair
{
	string data;
	int count;
};

map <string, bool> visited[15]; // k번 연산했을때 해당 문자를 만들 수 있는가 조회 
string n;
int k;
int answer = -1;
void bfs()
{
	int n_value;
	int str_size;
	int now_swap_count = 0;
	
	string n_str;
	queue <my_pair> que;
	que.push({n,0});
	str_size = n.length();

	while(!que.empty() && now_swap_count < k) // queue가 비어있거나, k번 횟수를 넘어가지 않을때 까지 반복 
	{
		n_value = stoi(que.front().data);
		n_str = que.front().data;
		now_swap_count = que.front().count;
		
		if(now_swap_count > k)
		{
			break;
		}
		que.pop();
		
		for(int i=0; i<str_size-1; i++)
		{
			int new_temp;
			for(int j=i+1; j<str_size; j++)
			{
				if(i == 0 && n_str[j] == '0') // 맨 앞자리가 0이 되는 경우는 없음. 
				{
					continue;
				}
				else
				{
					if(now_swap_count < k)
					{
						swap(n_str[i],n_str[j]);
						new_temp = stoi(n_str);
						
						if(visited[now_swap_count+1].find(n_str) == visited[now_swap_count+1].end()) // k번 연산을 했을때 해당 숫자를 이미 방문한 적이 있는지 확인 
						{
							visited[now_swap_count+1][n_str] = true;
							que.push({n_str,now_swap_count+1});	
							
							
							if((now_swap_count+1) % 2 == (k % 2)) // k번 이하에서 k와 나머지가 같다면(둘다 짝수거나 둘다 홀수라면) 연산을 k번해서 만들 수 있다. 
							{	
								if(new_temp > answer) 
								{
									answer = new_temp;
								}
							}
						}
						swap(n_str[i],n_str[j]);
					}
				}
			}
		}	
	}
	
	if(answer == -1)
	{
		cout << "-1\n";
	}
	else
	{
		cout << answer << "\n";
	}
}	
int main(void)
{
	/* C++ 입출력 속도  
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	*/
	
	cin >> n >> k;
	
	if(n.length() == 1 || (n.length() == 2 && n[1] == '0')) // 1자리거나 2자리인데 맨뒤가 0인경우 교환 성립 불가 
	{
		cout << "-1\n";
		return 0;
	}
	bfs();
}
