/* 
https://www.acmicpc.net
Problem ID : 11723
Bitmask
*/

#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	int value = 0; // 1bit당 x 하나의 의미를 가짐. 
	cin >> T;
	while(T--)
	{
		string input;
		cin >> input;
		if(input == "add")
		{
			int temp;
			cin >> temp;
			
			value = value | (1 << temp -1); // 해당 비트에 x가 존재함을 넣는다. 
			
		}
		else if(input == "check")
		{
			int temp;
			cin >> temp;
			
			if((value & (1 << temp-1)) == 0) // 0이면 데이터가 존재하지 않음 
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << "1" << "\n";
			}
		}
		else if(input == "remove")
		{
			int temp;
			cin >> temp;
			
			value = value & ~(1 << temp-1);
		}
		else if(input == "toggle")
		{
			int temp;
			cin >> temp;
			
			value = value ^ (1 << temp-1); // XOR 연산을 이용하면, 데이터가 toggle 기능을 만들 수있다. 
		}
		else if(input == "empty")
		{
			value = 0;		
		}
		else if(input == "all")
		{
			value = value | (1 << 20) -1; // 맨끝까지 간다음 1을 빼면 모든 값이 1로 채워진다. 
		}
	}
}
