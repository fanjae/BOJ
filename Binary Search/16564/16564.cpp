/* 
https://www.acmicpc.net
Problem ID : 16564
Binary Search
*/

#include <stdio.h>
long long int data[1000005];
int n,k;
bool cal(long long int value) // ��ǥ���� ���� k���Ϸ� �ø� �� �ִ°�? 
{
	long long int count = 0;
	for(int i=0; i<n; i++)
	{
		if(data[i] < value)
		{
			count += (value - data[i]);
		}
		if(count > k) // ���� k�� �Ѿ�� ���̻� Ȯ���� �ʿ����.(�������� ����) 
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
		if(cal(mid) == true) // k���Ϸ� �ø� �� �ִٸ�, ��ǥ������ �� �������ȴ�. 
		{
			ans = mid;
			low = mid + 1;	
		}
		else // k �̻����� �����ٸ�, ��ǥ������ ������Ѵ�. 
		{
			high = mid - 1;	
		}
	}
	printf("%lld\n",ans);
}
