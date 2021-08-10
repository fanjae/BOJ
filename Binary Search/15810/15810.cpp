/* 
https://www.acmicpc.net
Problem ID : 15810
Binary Search
*/

#include <stdio.h>
long long int n,m;
long long int data[1000005];
bool cal(long long int value) // value �ð��ȿ� ���� �� �ִ� ǳ�� ������ ���ϱ� 
{
	long long int count = 0;
	for(int i=0; i<n; i++)
	{
		count += (value / data[i]); 	
	}
	return count >= m; // m���� ǳ���� ���� �� �ִ°�? 
}
int main(void)
{
	long long int ans = 0;
	scanf("%lld %lld",&n,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%lld",&data[i]);
	}
	
	long long int left = 0;
	long long int right = 1e18;
	
	while(left <= right)
	{
		long long int mid = (left + right) / 2;
		if(cal(mid) == true) // �ð��ȿ� m���� ǳ���� ���� �� �ִٸ�, �� �̻��� �ð��̸� ��� ���� �� ����. 
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	printf("%lld\n",ans);
}
