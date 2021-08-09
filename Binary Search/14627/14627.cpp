/* 
https://www.acmicpc.net
Problem ID : 14627
Binary Search
*/

#include <stdio.h>
int n,k;
int data[1000005];
bool cal(long long int value) // �� ���̰� value�϶� ��� �Ĵ��� ���� �� �ִ°��� ���ϴ� �Լ� 
{
	int count = 0;
	for(int i=0; i<k; i++)  
	{
		count += data[i] / value;
	}
	
	return count >= k;
}
int main(void)
{
	long long int ans = 0;
	long long int max_scallion = 0;
	long long int sum = 0;
	
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&data[i]);
		sum += data[i];
		if(max_scallion < data[i])
		{
			max_scallion = data[i];
		}
	}

	long long int low = 1;
	long long int high = max_scallion;
	
	while(low <= high)
	{
		long long int mid = (low + high) / 2;
		if(cal(mid) == true) // �����ϴ� ��� �Ĵ� �ϳ��� �� ���� �ĸ� ���� �� ���� 
		{
			ans = mid;
			low = mid + 1;
		}
		else // �� ���� �ĸ� �־����. 
		{
			high = mid - 1;
		}
	}
	
	printf("%lld\n",sum - ans * k);
	  
		
}
