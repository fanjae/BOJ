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
int cal_value(int target) // ���� ��ư ������ �̵��ϸ� ��� ������ �ϴ°�? 
{
	int count = 0;
	int temp;
	
	if(target == 0) // ó������ 0�̾��� ��� 
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
		if(number[temp] == true) // �ϳ��� ������ ���ϸ� �ش� ä�η� �� �� ���� 
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
	
	answer = abs(n-100); // 100���� +,- ��ư������ �ٷ� �̵��� ��� 
	if(m == 10) // ��� ���� ��ư�� ���峭 ��� 
	{
		printf("%d\n",answer);
		return 0;
	}
	else
	{
		for(int i=0; i<=1000000; i++) // ���ڹ�ư���� 0���� 1,000,000�� ���� �� �ִ°�? (0������ 500,000�������� ä���� �ִ��̳�, 1,000,000������ -��ư�� ������ �̵��ϴ� ��쵵 ��� �ʿ�) 
		{
			int count = 0;
			if((count = cal_value(i)) > 0) // ���ڹ�ư���� �̵��� �����Ѱ�? (0���� �Ѿ�� ������) 
			{
				answer = min(answer, abs(i-n) + count); // �ش� ä�η� ���� ���� ���� ���ڹ�ư Ƚ�� + ��ǥ���� ������ �Ÿ��� �ּ� ��� ������ �ϴ��� ���� 
			}
			else
			{
				continue;
			}
		}
	}
	printf("%d\n",answer);	
}
