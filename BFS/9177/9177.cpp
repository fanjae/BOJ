/* 
https://www.acmicpc.net
Problem ID : 9177
BFS(Breadth first search)
*/

#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
string first;
string second;
string answer;

int first_length;
int second_length;
int answer_length = 0;
bool visited[205][205]={0}; // 각각 해당 단어의 글자 사용했는지 여부 체크 
bool find_answer = false;

struct data
{
	string str_data;
	int index;
	int index2;
};

void bfs()
{
	queue <data> que;
	que.push({"",0,0});
	
	while(!que.empty())
	{
		int x = que.front().index;
		int y = que.front().index2;
		int sum = x + y;
		string temp_str = que.front().str_data;
		que.pop();
		
		if(sum == answer_length && temp_str == answer) // 정답과 같으면 답을 찾음. 
		{
			find_answer = true;
			return ;	
		}
		else if(sum > answer_length) // 글자의 합을 넘어가면 더이상 가지 않음(답 찾기 불가능) 
		{
			return ;
		}
		
		if(x < first_length && answer[sum] == first[x] && visited[x+1][y] == false) // 첫번째 글자 사용 
		{
			visited[x+1][y] = true;
			que.push({temp_str + first[x],x+1,y});
		}
		if(y < second_length && answer[sum] == second[y] && visited[x][y+1] == false) // 두번째 글자 사용 
		{
			visited[x][y+1] = true;
			que.push({temp_str + second[y],x,y+1});
		}
	}
	return ;
}
int main(void)
{
	int T;
	int i=1;
	// C++ 입출력 속도 높이기 

	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> T;
	while(i <= T)
	{
		cin >> first >> second >> answer;
		first_length = first.length();
		second_length = second.length();
		answer_length = answer.length();
		
		bfs();
		if(find_answer == true)
		{
			cout << "Data set " << i++ << ": yes" << "\n";
		}
		else
		{
			cout << "Data set " << i++ << ": no" << "\n";
		}
		memset(visited,false,sizeof(visited));
		find_answer = false;
	}
	
}
