#include <iostream>
/* 
https://www.acmicpc.net
Problem ID : 1120
Brute Force 
*/

#include <cstring>
#include <string>

using namespace std;
int main(void)
{
	int answer = 55;
	int len;
	int len2;
	string a,b;
	cin >> a >> b;
	
	len = a.length();
	len2 = b.length();
	
	// �յڷ� �߰��Ǵ� ���ڵ��� ��� ��ġ�ϴٰ� �����ϸ�, �߰� �۾��� �������� �ʾƵ� �ȴ�.(���� ���� �޶����� �ʱ⶧����) 
	for(int i=0; i<=len2-len; i++)
	{
		int count = 0;
		for(int j=0; j<len; j++)
		{
			if(a[j] != b[i+j])  
			{
				count++;
			}
		}
		answer = min(answer,count);
	}
	cout << answer;
	
	
}
