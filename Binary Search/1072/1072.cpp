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
	
	if(value == 99 || value == 100) // 99% �̰ų� 100%�ΰ�� �·��� ������ �� ����. (���̻� ������ ���� �Ұ�����) 
	{
		printf("-1");
		return 0;
	}
	
	low = 1; // �ּ� ���� Ƚ�� 
	high = 1000000000; // �ִ� ���� Ƚ�� 
	
	while(low <= high)  
	{
		long long int mid = (low + high) / 2;
		long long int new_x = (x + mid);  // ���� Ƚ�� 
		long long int new_y = (y + mid); // �̱� Ƚ�� 
		long long int new_value = new_y * 100 / new_x;
		
		if(value < new_value) // ���� �·��� ������ �߻��� ���� �ش� Ƚ�� �̻��϶� ������ �·��� �������� ������. 
		{
			ans = mid;
			high = mid - 1;	
		}
		else //  ���� �·��� ������ ���� ��� �ش� Ƚ�� �̸��϶� �·��� �������� ����.  
		{
			low = mid + 1;
		}
	}
	printf("%lld\n",ans);
}
