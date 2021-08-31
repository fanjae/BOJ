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
	
	while(start <= end && end <= n) // start가 end 넘어가지 않으면서 end가 n보다 작을때 까지 
	{
		if(sum + end < n) // n보다 작으면 더 더함 
		{
			sum = sum + end;
			end++;
		}
		else if(sum + end >= n) // n보다 크거나 같으면 앞값은 빼야함 
		{
			if(sum + end == n) // 같을땐 가지수 증가 
			{
				cnt++;
			}
			sum = sum - start;
			start++;
		}
	}
	printf("%d\n",cnt);
}
