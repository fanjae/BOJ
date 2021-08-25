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
	char data[100005]; // ������ �ڸ����� 10^5 �̹Ƿ�, �Ϲ����� ���ڷ� ���� �� ����. 
	scanf("%s",data);
	str_len = strlen(data);
	
	sort(data,data+str_len,compare);
	
	// 30�� ��� = 3�� ��� && 10�� ���
	// 3�� ��� : �� �ڸ����� ���� 3�� ���������.
	// 10�� ��� : �ǳ� �ڸ��� 0�̾����. 	
	
	for(int i=0; i<str_len; i++)
	{
		sum += (data[i] - '0');
	}
	if(sum % 3 != 0 || data[str_len-1] != '0') // �� �ڸ����� ���� 3�� ����� �ƴϰų�, ���ڸ��� 0�� �ƴ�. 
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		printf("%s\n",data);
	}
	
}
