/* 
https://www.acmicpc.net
Problem ID : 16953
BFS(Breadth first search)
*/

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
struct my_pair
{
	long long int point;
	int count;
};

long long int start_point,end_point;
void bfs()
{
	queue <my_pair> que;
	que.push({start_point,1}); // 처음 가능횟수는 1  
	
	while(!que.empty())
	{
		long long int x = que.front().point;
		int cur_count = que.front().count;
		
		if(x == end_point) // B에 도달한 경우  
		{
			printf("%d\n",que.front().count);
			return ;
		}
		
		que.pop();
		if(x * 2 <= end_point) // 2곱했을때 B이하인 경우   
		{
			que.push({x*2,cur_count+1});
		}
		if(x * 10 + 1 <= end_point) // 오른쪽 1 추가했을 때  B이하인 경우   
		{
			que.push({x*10+1,cur_count+1});
		}
	}
	// 만들 수 없는 경우 
	printf("-1\n");
}
int main(void)
{
	scanf("%d %d",&start_point,&end_point);
	bfs();	
}

