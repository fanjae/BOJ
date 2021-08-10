/* 
https://www.acmicpc.net
Problem ID : 7795
Binary Search
*/

#include <stdio.h>
#include <algorithm>

using namespace std;
int my_upper_bound(int arr[], int target, int size) // �ڽź��� ū �� ��ġ ã�� �Լ� 
{
	int start = 0;
	int end = size-1;
	int mid;
	
	while(start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] >= target) // �� ���������� ���� ��쿩�� �ڽź��� ū �� ��ġ�� ������(ũ�Ⱑ ���� ���̸� ����) 
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
		sort(A,A+n); // A�� �� ����  
		for(int i=0; i<m; i++)
		{
			scanf("%d",&B[i]);
		}
		sort(B,B+m); // B�� �� ����  
		
		for(int i=0; i<n; i++)
		{
			ans += (my_upper_bound(B,A[i],m) + 1); // ��ġ�� ���� ������ �ִ� ���� ���� 
		}
		printf("%d\n",ans);
	}
}
