/*
https://www.acmicpc.net
Problem ID : 1806
Two Pointers
*/
#include <stdio.h>
long long int data[100005];
int main(void)
{
	long long int N,S;
	long long int sum = 0;
	scanf("%lld %lld",&N,&S);
	
	for(int i=0; i<N; i++)
	{
		scanf("%lld",&data[i]);
	}
	int start = 0;
	int end = 0;
	int ans_len = 0;
	while(start <= end && end <= N-1) // start�� end ���� �̸鼭 end�� n-1���� 
	{
		if(sum + data[end] < S) // S�����̸� end�� �߰� 
		{
			sum = sum + data[end];
			end++;
		}
		else if(sum + data[end] >= S) // S�̻��̸� �ش� ���Ӽ� ���� ����
		{
			if(ans_len == 0 || ans_len > end - start + 1)
			{
				ans_len = end - start + 1;
			}
			sum = sum - data[start]; // (�ּұ����̹Ƿ�, ���� start���� ���� ���� ������)
			start++;
		}
	}
	printf("%d\n",ans_len);
}
