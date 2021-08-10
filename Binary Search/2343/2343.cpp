/* 
https://www.acmicpc.net
Problem ID : 2343
Binary Search
*/

#include <stdio.h>
int n,m;
int data[100005];
bool cal(int value) // 블루레이의 길이가 value일때, 만들 수 있는가? 
{
	int count = 1;
	int sum = 0;
	
	for(int i=0; i<n; i++)
	{
		if(data[i] > value)
		{
			return false; // 블루레이 크기보다 더 큰 것이 존재하면 성립이 불가능 
		}
		if(sum + data[i] <= value) // value 이하일때는 합침. 
		{
			sum += data[i];
		}
		else // value를 넘어간 경우 새로운 블루레이를 만듦. 
		{
			count++;
			sum = 0;
			sum += data[i];
		}
			
	}
	return count <= m; // 블루레이의 개수가 m개 이하인가?  
}
int main(void)
{
	int ans = 0;
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&data[i]);
	}
	
	int left = 1;
	int right = 1e9;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(cal(mid) == true) // 해당 길이로 m개 이하를 만들 수 있다면, 블루레이 크기가 길면 모두 만들 수 있다. 
		{
			ans = mid;
			right = mid - 1;
		}
		else // m개를 넘어간 경우 블루레이의 크기를 더 늘려야함. 
		{
			left = mid + 1;
		}
	}
	printf("%d\n",ans);
}
