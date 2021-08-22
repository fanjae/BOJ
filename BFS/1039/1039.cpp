/* BOJ : 1039 수정 필요 */ 

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int count[1000005];
string n_value;
int n,k;
int str_len;
int max_value;

void bfs()
{
	queue <int> que;
	n = stoi(n_value);
	que.push(n);
	count[n] = 0;
	
	while(!que.empty())
	{
		int que_n = que.front();
		string temp = to_string(que_n);
		string temp2 = temp;
		int n_temp;
		
		if(count[que_n] == k)
		{
			if(max_value < que_n)
			{
				max_value = que_n;
			}
		}
		else if(count[que_n] > k)
		{
			break;
		}
		que.pop();
		
		for(int i=0; i<str_len-1; i++)
		{
			for(int j=i+1; j<str_len; j++)
			{
				temp2 = temp;
				if(i == 0 && temp[j] == 0)
				{
					continue;
				}
				char set = temp2[i];
				temp2[i] = temp2[j];
				temp2[j] = set;
				cout << temp2 << "\n";
				n_temp = stoi(temp2);
				
				if(n_temp >= 1000001)
				{
					continue;
				}
				if(count[n_temp] == -1)
				{
					count[n_temp] = count[que_n] + 1;
					que.push(n_temp);
				}
				
			}
		}
	}
	for(int i=1000000; i>=1; i--)
	{
		if(count[i] == -1)
		{
			continue;
		}
		if(k % 2 == 0)
		{
			if(count[i] % 2 == 0 && k % 2 == 0)
			{
				printf("%d\n",i);
				return ;
			}
		}
		else
		{
			if(count[i] % 2 == 1 && k % 2 == 1)
			{
				printf("%d\n",i);
				return ;
			}	
		}
	}
	printf("-1\n");
}
	
int main(void)
{
	cin >> n_value >> k;
	str_len = n_value.length();
	
	memset(count,-1,sizeof(count));
	max_value = stoi(n_value);
	bfs();
	
}
