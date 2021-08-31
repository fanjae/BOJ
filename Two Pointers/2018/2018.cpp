/* 
https://www.acmicpc.net
Problem ID : 2018
Two Pointers
*/

#include <stdio.h>
int main(void)
{
	int n;
	int start = 1;
	int end = 1;
	int sum = 0;
	int cnt = 0;
	scanf("%d",&n);
	
	while(start <= end && end <= n) // start�� end �Ѿ�� �����鼭 end�� n���� ������ ���� 
	{
		if(sum + end < n) // n���� ������ �� ���� 
		{
			sum = sum + end;
			end++;
		}
		else if(sum + end >= n) // n���� ũ�ų� ������ �հ��� ������ 
		{
			if(sum + end == n) // ������ ������ ���� 
			{
				cnt++;
			}
			sum = sum - start;
			start++;
		}
	}
	printf("%d\n",cnt);
}
