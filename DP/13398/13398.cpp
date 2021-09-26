/* 
https://www.acmicpc.net
Problem ID : 13398
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[100005][2];
int data[100005];
int n;
int ans;
int main(void)
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&data[i]);
	}

	dp[0][0] = data[0]; // �� ���� �������� �ʰ� i��°������ ���� ū ������ 
	dp[0][1] = 0; // �� ���� �����ϰ� i��°������ ���� ū ���� ��  
	ans = data[0]; // 1�� �̻��� ���� ���õǾ�� �Ѵ�.  
	
	for(int i=1; i<n; i++)
	{
		dp[i][0] = max(data[i],dp[i-1][0] + data[i]); // ���� ���ϰ� ��� �������� data[i]�� �������� ���� �� �� �� ū ���� �������°� ����,  
		dp[i][1] = max(dp[i-1][1] + data[i],dp[i-1][0]); // 1�� ���� �Ҷ��� ���� ���� �ϳ� ���������� ���簪�� ������ ���ؾ���. �Ǵ� �̹� ���� �����ϴ°� ����. 
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
	}
	
	printf("%d\n",ans);
}
