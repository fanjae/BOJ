/* 
https://www.acmicpc.net
Problem ID : 1541
Parsing 
*/

#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;
stack <int> value;
int cal()
{
	int sum = 0;
	int temp;
	int set = 1;
	temp = value.top();
	while(!value.empty())
	{
		temp = value.top() * set;
		set *= 10;
		sum = sum + temp;
		value.pop();
	}
	return sum;
}
int main(void)
{
	int len;
	int ans = 0;
	
	bool isMinus = false;
	char data[105];
	scanf("%s",data);
	len = strlen(data);
	
	for(int i=0; i<len; i++)
	{
		if(data[i] >= '0' && data[i] <= '9') // ���� ó�� 
		{
			value.push(data[i]-'0');
		}
		if(data[i] == '+' || data[i] == '-' || i == len-1)
		{
			int cal_value = cal();
			if(!isMinus) // MINUS�� �������� ������ ����  
			{
				ans += cal_value;
			}
			else // MINUS�� �������� ������ ��. 
			{
				ans -= cal_value;
			}
			
			if(data[i] == '-') // MINUS���� ��� ���� ���� ��� MINUS�� ������ (�ּҷ� ����� ���ؼ�) 
			{
				isMinus = true;
			}
		}
	}
	printf("%d\n",ans);
}
