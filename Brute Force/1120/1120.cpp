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
	
	// 앞뒤로 추가되는 문자들이 모두 일치하다고 가정하면, 추가 작업을 진행하지 않아도 된다.(차이 값이 달라지지 않기때문에) 
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
