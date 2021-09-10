/* 
https://www.acmicpc.net
Problem ID : 10570
Implementation
*/
#include <stdio.h>
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int data[1005]={0}; // 쪽지에 적힌 수 
		int max_value = 0; // 선택된 최대 개수 
		int answer = 0; // 선택된 수 
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			int temp;
			scanf("%d",&temp);
			data[temp]++; // temp번째 수가 적힌 수를 증가 
		}
		
		
		
		for(int i=1; i<=1000; i++)
		{
			if(max_value < data[i]) // 선택된 개수가 가장 크면 해당 값으로 교체 
			{
				max_value = data[i];
				answer = i;
			}
		}
		printf("%d\n",answer);
	}
}
			
