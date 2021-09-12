/* 
https://www.acmicpc.net
Problem ID : 1107
Brute Force 
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
bool number[15];

using namespace std;
int cal_value(int target) // 숫자 버튼 만으로 이동하면 몇번 눌러야 하는가? 
{
	int count = 0;
	int temp;
	
	if(target == 0) // 처음부터 0이었던 경우 
	{
		if(number[0] == true)
		{
			return 0;
		}
		else
		{
			count++;
		}
	}
	while(target != 0)
	{
		temp = target % 10;
		if(number[temp] == true) // 하나라도 누르지 못하면 해당 채널로 갈 수 없음 
		{
			return 0;
		}
		else
		{
			count++;
		}
		target /= 10;
	}
	return count;
	
}
int main(void)
{
	int n;
	int m;
	int temp;
	int answer = 0;
	
	cin >> n;
	cin >> m;
	for(int i=0; i<m; i++)
	{
		cin >> temp;
		number[temp] = true;
	}
	
	answer = abs(n-100); // 100에서 +,- 버튼만으로 바로 이동한 경우 
	if(m == 10) // 모든 숫자 버튼이 고장난 경우 
	{
		printf("%d\n",answer);
		return 0;
	}
	else
	{
		for(int i=0; i<=1000000; i++) // 숫자버튼으로 0부터 1,000,000을 만들 수 있는가? (0번에서 500,000번까지가 채널의 최대이나, 1,000,000번에서 -버튼만 눌러서 이동하는 경우도 고려 필요) 
		{
			int count = 0;
			if((count = cal_value(i)) > 0) // 숫자버튼으로 이동이 가능한가? (0번을 넘어가면 가능함) 
			{
				answer = min(answer, abs(i-n) + count); // 해당 채널로 가기 위해 누른 숫자버튼 횟수 + 목표지점 까지의 거리로 최소 몇번 눌러야 하는지 구함 
			}
			else
			{
				continue;
			}
		}
	}
	printf("%d\n",answer);	
}
