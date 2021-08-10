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
		
		if(count < k) // k���� ������ �� ���� ���. �� �̻��� �Ѿ�� ���� �� �� ����. 
		{
			right = mid - 1;
		}
		else // k���� �����ټ� ������, �� ������ ml�� ������ �� �� ����. 
		{
			ans = mid;
			left = mid + 1;	
		}
	}
	printf("%lld\n",ans);
}
