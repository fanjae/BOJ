/* 
https://www.acmicpc.net
Problem ID : 13702
Binary Search
*/

#include <stdio.h>
long long int n,k;
long long int data[10005];
int main(void)
{
	long long int ans = 0;
	scanf("%lld %lld",&n,&k);
	for(int i=0; i<n; i++)
	{
		scanf("%lld",&data[i]);
	}
	
	long long int left = 1;
	long long int right = 1e10;
	
	while(left <= right)
	{
		long long int mid = (left + right) / 2;
		long long int count = 0;
		for(int i=0; i<n; i++)
		{
			count += (data[i] / mid);
		}
		
		if(count < k) // k명을 나눠줄 수 없는 경우. 그 이상을 넘어가면 절대 줄 수 없음. 
		{
			right = mid - 1;
		}
		else // k명을 나눠줄수 있으면, 그 이하의 ml는 무조건 줄 수 있음. 
		{
			ans = mid;
			left = mid + 1;	
		}
	}
	printf("%lld\n",ans);
}
