/*
https://www.acmicpc.net
Problem ID : 1806
Two Pointers
*/
#include <stdio.h>
long long int data[100005];
int main(void)
{
	long long int N,S;
	long long int sum = 0;
	scanf("%lld %lld",&N,&S);
	
	for(int i=0; i<N; i++)
	{
		scanf("%lld",&data[i]);
	}
	int start = 0;
	int end = 0;
	int ans_len = 0;
	while(start <= end && end <= N-1) // start가 end 이하 이면서 end가 n-1까지 
	{
		if(sum + data[end] < S) // S이하이면 end값 추가 
		{
			sum = sum + data[end];
			end++;
		}
		else if(sum + data[end] >= S) // S이상이면 해당 연속수 길이 측정
		{
			if(ans_len == 0 || ans_len > end - start + 1)
			{
				ans_len = end - start + 1;
			}
			sum = sum - data[start]; // (최소길이이므로, 기존 start값은 없앤 이후 재측정)
			start++;
		}
	}
	printf("%d\n",ans_len);
}
