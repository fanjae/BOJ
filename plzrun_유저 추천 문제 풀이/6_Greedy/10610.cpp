/* 
https://www.acmicpc.net
Problem ID : 10610
Greedy
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool compare(char a, char b)
{
	return a>b;
}
int main(void)
{
	int str_len;
	int sum = 0; 
	char data[100005]; // 숫자의 자리수가 10^5 이므로, 일반적인 숫자로 담을 수 없음. 
	scanf("%s",data);
	str_len = strlen(data);
	
	sort(data,data+str_len,compare);
	
	// 30의 배수 = 3의 배수 && 10의 배수
	// 3의 배수 : 각 자리수의 합이 3의 배수여야함.
	// 10의 배수 : 맨끝 자리가 0이어야함. 	
	
	for(int i=0; i<str_len; i++)
	{
		sum += (data[i] - '0');
	}
	if(sum % 3 != 0 || data[str_len-1] != '0') // 각 자리수의 합이 3의 배수가 아니거나, 끝자리가 0이 아님. 
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		printf("%s\n",data);
	}
	
}
