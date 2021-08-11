/* 
https://www.acmicpc.net
Problem ID : 16564
Binary Search
*/

#include <stdio.h>
long long int data[1000005];
int n,k;
bool cal(long long int value) // 목표레벨 총합 k이하로 올릴 수 있는가? 
{
	long long int count = 0;
	for(int i=0; i<n; i++)
	{
		if(data[i] < value)
		{
			count += (value - data[i]);
		}
		if(count > k) // 총합 k를 넘어가면 더이상 확인할 필요없음.(만족하지 않음) 
		{
			return false;
		}
	}
	return count <= k;	
}
int main(void)
{
	long long int ans = 0;
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&data[i]);
	}
	
	long long int low = 1;
	long long int high = 1e18;
	
	while(low <= high)
	{
		long long int mid = (low + high) / 2;
		if(cal(mid) == true) // k이하로 올릴 수 있다면, 목표레벨을 더 높여도된다. 
		{
			ans = mid;
			low = mid + 1;	
		}
		else // k 이상으로 오른다면, 목표레벨을 낮춰야한다. 
		{
			high = mid - 1;	
		}
	}
	printf("%lld\n",ans);
}
