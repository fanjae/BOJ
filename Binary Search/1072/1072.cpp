/* 
https://www.acmicpc.net
Problem ID : 1072
Binary Search
*/

#include <stdio.h>
int main(void)
{
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	
	long long int value = y * 100 / x;
	long long int low,high;
	long long int ans = 0;
	
	if(value == 99 || value == 100) // 99% 이거나 100%인경우 승률이 변동될 수 없다. (더이상 오르는 것이 불가능함) 
	{
		printf("-1");
		return 0;
	}
	
	low = 1; // 최소 게임 횟수 
	high = 1000000000; // 최대 게임 횟수 
	
	while(low <= high)  
	{
		long long int mid = (low + high) / 2;
		long long int new_x = (x + mid);  // 게임 횟수 
		long long int new_y = (y + mid); // 이긴 횟수 
		long long int new_value = new_y * 100 / new_x;
		
		if(value < new_value) // 게임 승률에 변동이 발생한 경우는 해당 횟수 이상일땐 무조건 승률이 변동됨을 보장함. 
		{
			ans = mid;
			high = mid - 1;	
		}
		else //  게임 승률에 변동이 없는 경우 해당 횟수 미만일때 승률이 변동되지 않음.  
		{
			low = mid + 1;
		}
	}
	printf("%lld\n",ans);
}
