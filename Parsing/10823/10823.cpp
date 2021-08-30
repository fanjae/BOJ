/* 
https://www.acmicpc.net
Problem ID : 10823
Parsing 
*/

#include <stdio.h>
#include <stack>

using namespace std;

stack <int> value;

int cal()
{
	int cal = 1;
	int sum = 0;
	int temp;
	if(value.empty()) // 스택이 비면 0으로 임의로 더함 
	{
		return 0;
	}
	while(!value.empty()) // 스택이 비어있지 않으면 자릿수 처리 
	{
		temp = value.top();
		sum = sum + temp * cal;
		cal *= 10;
		value.pop();	
	}
	return sum;
}
int main(void)
{
	char data[20005];
	char temp;
	int len = 0;
	int sum = 0;
	while((temp = getchar()) != EOF) // EOF까지 계속 받음 
	{
		data[len] = temp;
		len++;
	}
	
	for(int i=0; i<len; i++)
	{
		if(data[i] >= '0' && data[i] <= '9') // 숫자 처리 
		{
			value.push(data[i]-'0');
		}
		else if(data[i] == ',' || i == len-1) // 입력이 ','이거나 끝이면 그전까지 스택에 담긴 내용 모두 더함 
		{
			sum += cal();	
		}
	}
	printf("%d\n",sum);
}
