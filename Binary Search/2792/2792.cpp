/* 
https://www.acmicpc.net
Problem ID : 2792
Binary Search
*/

#include <stdio.h>
int n,k;
int color[300005];
int cal_count(int value) // ������ �ѹ��� value�� �����ִ� ��� 
{
	int count = 0;
	for(int i=0; i<k; i++)
	{
		count += (color[i] / value);
		if(color[i] % value > 0) // �׻� ���� ���� �������⶧���� ���� ������ ���������� �־����. 
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
		if(cal_count(mid) <= n) // ������ n�� ���Ͽ��� �����ټ� ������ �̺��� ū ���� ������� �ʴ´�. (������, ������ �� �ִ�.)    
		{
			ans = mid;
			right = mid - 1;
			
		}
		else // ������ n���� �Ѿ ���. (������ ���ұ� ������ 1���� �� ���� ������ �־����.) 
		{
			left = mid + 1;
		}
	}
	printf("%d\n",ans);
}
	
