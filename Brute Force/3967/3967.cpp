/* 
https://www.acmicpc.net
Problem ID : 3967
Brute Force & Backtracking
*/

#include <stdio.h>
#include <queue>

using namespace std;

struct star_x
{
	int x;
	int y;
};
star_x star_position[12];
int star_count = 0;
bool find_answer = false;
bool check_number[12]={0};
char map[5][10];

void back(int cnt)
{
	if(cnt == star_count) // 매직 스타를 위해 채워야할 숫자가 같으면 check 
	{
		// 기본적으로 모든 수에 각 +1을 더함('A'가 0이 아닌 1이기 때문)
		// 'A'를 모두 빼야 하므로 'A' * 4만큼 뺌) 
		if((map[0][4] + map[1][3] + map[2][2] + map[3][1]) + 4 - ('A' * 4) != 26)
		{
			return ;
		}
		if((map[0][4] + map[1][5] + map[2][6] + map[3][7]) + 4 - ('A' * 4) != 26)
		{
			return ;
		}
		if((map[1][1] + map[1][3] + map[1][5] + map[1][7]) + 4 - ('A' * 4) != 26)
		{ 
			return ;
		}
		if((map[1][1] + map[2][2] + map[3][3] + map[4][4]) + 4 - ('A' * 4) != 26)
		{
			return ;
		}
		if((map[1][7] + map[2][6] + map[3][5] + map[4][4]) + 4 - ('A' * 4) != 26)
		{
			return ;
		}
		if((map[3][1] + map[3][3] + map[3][5] + map[3][7]) + 4 - ('A' * 4) != 26)
		{
			return ;
		}
		
		// 위 모든 조건을 만족하면 매직스타 
		find_answer = true;
		return ;
	}
	else
	{
		for(int i=0; i<12; i++)
		{
			if(check_number[i] == true) // 이미 사용중인 숫자 생략 
			{
				continue;
			}
			check_number[i] = true; // 숫자 사용처리 
			map[star_position[cnt].x][star_position[cnt].y] = 'A' + i; // 해당 숫자 사용 
			back(cnt+1); // 탐색 
			if(find_answer == true) // 답을 찾은 경우 더이상 진입하지 않음 
			{
				return ;
			}
			map[star_position[cnt].x][star_position[cnt].y] = 'x'; // 기존 값 원상태 복구 
			check_number[i] = false; // 기본 사용값 원상태 복구 
		}
	}
	
}
int main(void)
{
	for(int i=0; i<5; i++)
	{
		scanf("%s",map[i]);
	}
	
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(map[i][j] == 'x')
			{
				star_position[star_count] = {i,j};
				star_count++;
			}
			else if(map[i][j] != '.')
			{
				check_number[map[i][j] - 'A'] = true;	
			}
		}
	}
	
	back(0);
	
	for(int i=0; i<5; i++)
	{
		printf("%s\n",map[i]);
	}
}
	
