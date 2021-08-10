/* 
https://www.acmicpc.net
Problem ID : 7795
Binary Search
*/

#include <stdio.h>
#include <algorithm>

using namespace std;
int my_upper_bound(int arr[], int target, int size) // 자신보다 큰 값 위치 찾는 함수 
{
	int start = 0;
	int end = size-1;
	int mid;
	
	while(start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] >= target) // 이 문제에서는 같은 경우여도 자신보다 큰 값 위치로 봐야함(크기가 작은 먹이만 먹음) 
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return end;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans = 0;
		int A[20005];
		int B[20005];
		int n,m;
		
		scanf("%d %d",&n,&m);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&A[i]);		
		}
		sort(A,A+n); // A의 수 정렬  
		for(int i=0; i<m; i++)
		{
			scanf("%d",&B[i]);
		}
		sort(B,B+m); // B의 수 정렬  
		
		for(int i=0; i<n; i++)
		{
			ans += (my_upper_bound(B,A[i],m) + 1); // 위치를 토대로 먹을수 있는 쌍을 누적 
		}
		printf("%d\n",ans);
	}
}
