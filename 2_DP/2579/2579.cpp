#include <stdio.h>
#include <algorithm>
int dp[305]={0};
int data[305];

// dp[n] : n��° ��ܿ����� �ִ밪
// 3 ���� ������ n��° ��ܿ��� �߻��� �� �ִ� ��Ȳ
// �� ����� ��� �� ��� :  ��������� ���� ���ϹǷ� ��������ܱ��� ��� ��Ȳ�� ����.
// �� ����� ���� ���� ��� : ���� ����� ������Ƿ�, ������ܱ��� ��� ��Ȳ�� ����. 
using namespace std;
int main(void)
{
	int n;
	scanf("%d",&n);
	
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&data[i]);
	}
	
	dp[1] = data[1];
	dp[2] = data[1]+data[2];
	dp[3] = max(data[1]+data[3],data[2]+data[3]);
	for(int i=4; i<=n; i++)
	{
		dp[i] = max(dp[i-3]+data[i-1]+data[i],dp[i-2]+data[i]);
	}
	printf("%d",dp[n]);	
}
	
