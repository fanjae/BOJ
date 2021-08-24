/* 
https://www.acmicpc.net
Problem ID : 1958
DP(Dynamic Programming)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int dp[105][105][105]={0}; // i��° ����, j��° ����, k��° ���ڱ��� ������� �� �ִ� LCS�� ���� 
int main(void)
{
	int str_len,str2_len,str3_len;
	char str[105],str2[105],str3[105];
	
	scanf("%s",str);
	scanf("%s",str2);
	scanf("%s",str3);
	
	str_len = strlen(str);
	str2_len = strlen(str2);
	str3_len = strlen(str3);
	for(int i=1; i<=str_len; i++)
	{
		for(int j=1; j<=str2_len; j++)
		{
			for(int k=1; k<=str3_len; k++)
			{
				if(str[i-1] == str2[j-1] && str2[j-1] == str3[k-1]) // �� ������ ���̰� ������ LCS[i-1][j-1][k-1] + 1 
				{
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				}
				else // �ٸ� ��� 3���� LCS ���� ���� ū ���� �����;���.  
				{
					dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
				}
			}
		}
	}
	
	printf("%d\n",dp[str_len][str2_len][str3_len]);
}
	
	
