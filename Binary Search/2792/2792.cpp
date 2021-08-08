/* 
https://www.acmicpc.net
Problem ID : 2792
Binary Search
*/

#include <stdio.h>
int n,k;
int color[300005];
int cal_count(int value) // 보석을 한번에 value개 나눠주는 경우 
{
	int count = 0;
	for(int i=0; i<k; i++)
	{
		count += (color[i] / value);
		if(color[i] % value > 0) // 항상 같은 색깔만 가져가기때문에 남은 보석을 누군가에게 주어야함. 
		{
			count++;
		}
	}
	return count;
}
int main(void)
{
	int ans;
	int max_value = 0;
	scanf("%d %d",&n,&k);
	for(int i=0; i<k; i++)
	{
		scanf("%d",&color[i]);
		if(max_value < color[i])
		{
			max_value = color[i];
		}
	}
	
	int left,right,mid;
	
	left = 1;
	right = max_value;
	
	while(left <= right)
	{
		mid = (left+right) / 2;
		if(cal_count(mid) <= n) // 보석을 n명 이하에게 나눠줄수 있으면 이보다 큰 값은 고려하지 않는다. (무조건, 나눠줄 수 있다.)    
		{
			ans = mid;
			right = mid - 1;
			
		}
		else // 보석을 n명을 넘어간 경우. (보석이 남았기 때문에 1명에게 더 많은 보석을 주어야함.) 
		{
			left = mid + 1;
		}
	}
	printf("%d\n",ans);
}
	
