/* 
https://www.acmicpc.net
Problem ID : 2343
Binary Search
*/

#include <stdio.h>
int n,m;
int data[100005];
bool cal(int value) // ��緹���� ���̰� value�϶�, ���� �� �ִ°�? 
{
	int count = 1;
	int sum = 0;
	
	for(int i=0; i<n; i++)
	{
		if(data[i] > value)
		{
			return false; // ��緹�� ũ�⺸�� �� ū ���� �����ϸ� ������ �Ұ��� 
		}
		if(sum + data[i] <= value) // value �����϶��� ��ħ. 
		{
			sum += data[i];
		}
		else // value�� �Ѿ ��� ���ο� ��緹�̸� ����. 
		{
			count++;
			sum = 0;
			sum += data[i];
		}
			
	}
	return count <= m; // ��緹���� ������ m�� �����ΰ�?  
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
		if(cal(mid) == true) // �ش� ���̷� m�� ���ϸ� ���� �� �ִٸ�, ��緹�� ũ�Ⱑ ��� ��� ���� �� �ִ�. 
		{
			ans = mid;
			right = mid - 1;
		}
		else // m���� �Ѿ ��� ��緹���� ũ�⸦ �� �÷�����. 
		{
			left = mid + 1;
		}
	}
	printf("%d\n",ans);
}
