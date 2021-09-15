/* 
https://www.acmicpc.net
Problem ID : 2784
Brute Force 
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <algorithm>

using namespace std;
string data[6];
string temp[3];

bool find_all_str()
{
	bool count[6]={0};
	for(int i=0; i<6; i++) // 6개의 단어를 모두 각각 찾을수 있는가? 
	{
		bool is_find = false;
		bool find_value = false;
		string temp_value = "";
		
		for(int j=0; j<3; j++) // 가로 
		{
			if(data[i].compare(temp[j]) == 0 && count[j] == false) // 가로에서 발견할 수 있는가? 
			{
				is_find = true;
				count[j] = true;
				break;
			}
		}
		
		if(is_find == false)
		{
			for(int j=0; j<3; j++) // 세로 
			{
				temp_value = "";
				for(int k=0; k<3; k++) 
				{
					temp_value += temp[k][j];
				}	
				if(data[i].compare(temp_value) == 0 && count[3+j] == false) // 세로에서 발견할 수 있는가? 
				{
					is_find = true;
					count[3+j] = true;
					break;
				}
			}
		}

		if(is_find == false) // 발견 못한 경우 퍼즐을 만들 수 없다. 
		{
			return false;
		}
	}
	
	return true;
}
bool str_compare(string a, string b)
{
	return a < b;
}
int main(void)
{

	for(int i=0; i<6; i++)
	{
		cin >> data[i];
	}
	
	sort(data,data+6,str_compare);
	
	for(int i=0; i<6; i++)
	{
		temp[0] = "";
		temp[1] = "";
		temp[2] = "";
		for(int j=0; j<6; j++)
		{
			if(i == j)
			{
				continue;
			}
			for(int k=0; k<6; k++)
			{
				if(i == k || j == k) // 같은 위치에 문자열 받지 않도록 처리 
				{
					continue;
				}
				temp[0] = data[i]; 
				temp[1] = data[j];
				temp[2] = data[k];
				
				if(find_all_str() == true) // 모든 문자열이 들어있는지 확인 
				{
					for(int i=0; i<3; i++)
					{
						cout << temp[i] << "\n";
					}
					exit(0);
				}
			}
		}
	}
	printf("0\n");
}
	 
