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
	if(cnt == star_count) // ���� ��Ÿ�� ���� ä������ ���ڰ� ������ check 
	{
		// �⺻������ ��� ���� �� +1�� ����('A'�� 0�� �ƴ� 1�̱� ����)
		// 'A'�� ��� ���� �ϹǷ� 'A' * 4��ŭ ��) 
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
		
		// �� ��� ������ �����ϸ� ������Ÿ 
		find_answer = true;
		return ;
	}
	else
	{
		for(int i=0; i<12; i++)
		{
			if(check_number[i] == true) // �̹� ������� ���� ���� 
			{
				continue;
			}
			check_number[i] = true; // ���� ���ó�� 
			map[star_position[cnt].x][star_position[cnt].y] = 'A' + i; // �ش� ���� ��� 
			back(cnt+1); // Ž�� 
			if(find_answer == true) // ���� ã�� ��� ���̻� �������� ���� 
			{
				return ;
			}
			map[star_position[cnt].x][star_position[cnt].y] = 'x'; // ���� �� ������ ���� 
			check_number[i] = false; // �⺻ ��밪 ������ ���� 
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
	
