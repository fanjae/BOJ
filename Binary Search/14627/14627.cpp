/* 
https://www.acmicpc.net
Problem ID : 14627
Binary Search
*/

#include <stdio.h>
int n,k;
int data[1000005];
bool cal(long long int value) // 파 길이가 value일때 몇개의 파닭을 만들 수 있는가를 구하는 함수 
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
		if(cal(mid) == true) // 만족하는 경우 파닭 하나당 더 많은 파를 넣을 수 잇음 
		{
			ans = mid;
			low = mid + 1;
		}
		else // 더 적은 파를 넣어야함. 
		{
			high = mid - 1;
		}
	}
	
	printf("%lld\n",sum - ans * k);
	  
		
}
