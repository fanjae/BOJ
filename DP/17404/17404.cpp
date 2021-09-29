/* 
https://www.acmicpc.net
Problem ID : 17404
DP(Dynamic Programming)
*/


#include <stdio.h>
#include <algorithm>
#define INF 1000005
int dp[1005][3];
int data[1005][3];
int ans = INF;
int n;
using namespace std;

void reset()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<3; j++)
		{
			dp[i][j] = INF;
		}
	}
}
void cal()
{
	for(int i=2; i<=n; i++)
	{
		// [i][0] : i��° ���� �������� ĥ�Ҷ� �ּ� ���
		// [i][1] : i��° ���� �ʷ����� ĥ�Ҷ� �ּ� ���
		// [i][2] : i��° ���� �Ķ����� ĥ�Ҷ� �ּ� ���
		// i-1��° ���� ��������, ���߿� ����� �� ���� ����� ��� ���� ��� ���Ѵ�.
		 
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + data[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + data[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + data[i][2];
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<3; j++)
		{
			scanf("%d",&data[i][j]);	
		}
	}
	
	reset(); // dp �迭 �ʱ�ȭ 
	dp[1][0] = data[1][0]; // ù��° ���� ���������� ĥ��. 
	cal();
	ans = min(ans,min(dp[n][1],dp[n][2])); // �������� �������� ���� ���� �� �� �ּҰ� 

	reset(); // dp �迭 �ʱ�ȭ
	dp[1][1] = data[1][1]; // ù��° ���� �ʷϻ����� ĥ��.
	cal();
	ans = min(ans,min(dp[n][0],dp[n][2])); // �������� �ʷϻ��� ���� ���� �� �� �ּҰ� 

	reset(); // dp �迭 �ʱ�ȭ
	dp[1][2] = data[1][2]; // ù��° ���� �Ķ������� ĥ��.
	cal();  
	ans = min(ans,min(dp[n][0],dp[n][1])); // �������� �Ķ����� ���� ���� �� �� �ּҰ� 

	printf("%d\n",ans);
}
