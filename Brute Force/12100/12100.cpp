/* 
https://www.acmicpc.net
Problem ID : 12100
Brute Force 
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector <int>> vec;
int n;
int answer = 0;
int before[25][25];
vec data;

// 배열 상태값을 받아서 이동 시키는 것을 기본으로 하되,
// 아래와 같은 규칙을 지킨다.
// 타겟을 기준으로 비교할 숫자와 같으면 해당 두 숫자를 합친다. (이때, 최고 값을 갱신한다.) 
// 만약 타겟이 0이면 비교할 숫자를 0쪽으로 가지고 온다.
// 위 2조건을 모두 한 이후 비교할 숫자가 0이 아니면 다음 값 비교를 시작한다. 
vec move(vec data, int type)
{
	if(type == 1) // up
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n-1; j++)
			{
				for(int k=j+1; k<n; k++) 
				{
					if(data[j][i] != 0 && data[j][i] == data[k][i]) 
					{
						data[j][i] += data[k][i];
						answer = max(answer,data[j][i]);
						data[k][i] = 0;
						break;
					}
					else if(data[j][i] == 0)
					{
						data[j][i] = data[k][i];
						data[k][i] = 0;
						continue;
					}
					else if(data[k][i] != 0) 
					{
						break;
					}
				}

			}
		}
	}
	if(type == 2) // down
	{
		for(int i=0; i<n; i++)
		{
			for(int j=n-1; j>=1; j--)
			{
				for(int k=j-1; k>=0; k--)
				{
					if(data[j][i] != 0 && data[j][i] == data[k][i])
					{
						data[j][i] += data[k][i];
						answer = max(answer,data[j][i]);
						data[k][i] = 0;
						break;
					}
					else if(data[j][i] == 0)
					{
						data[j][i] = data[k][i];
						data[k][i] = 0;
						continue;
					}	
					else if(data[k][i] != 0)
					{
						break;
					}
				}

			}
		}
	}
	if(type == 3) // left
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n-1; j++)
			{
				for(int k=j+1; k<n; k++)
				{
					if(data[i][j] != 0 && data[i][j] == data[i][k])
					{
						data[i][j] += data[i][k];
						answer = max(answer,data[i][j]);
						data[i][k] = 0;
						break;
					}
					else if(data[i][j] == 0)
					{
						data[i][j] = data[i][k];
						data[i][k] = 0;
						continue;
					}
					else if(data[i][k] != 0)
					{
						break;
					}
				}
			}
		}
	}
	if(type == 4) // right
	{
		for(int i=0; i<n; i++)
		{
			for(int j=n-1; j>=1; j--)
			{
				for(int k=j-1; k>=0; k--)
				{
					if(data[i][j] != 0 && data[i][j] == data[i][k])
					{
						data[i][j] += data[i][k];
						answer = max(answer,data[i][j]);
						data[i][k] = 0;
						break;
					}
					else if(data[i][j] == 0)
					{
						data[i][j] = data[i][k];
						data[i][k] = 0;
						continue;
					}
					else if(data[i][k] != 0)
					{
						break;
					}
				}
			}
		}
	}	
	

	return data;
}
void solve(vec data, int cnt) // 벡터에 담은 배열 상태값을 이동시켜가면서 상태 이동을 확인한다. 
{
	if(cnt == 5)
	{
		return ;
	}
	for(int i=1; i<=4; i++) // 1부터 up,down,left,right순서  
	{
		solve(move(data,i),cnt+1);
	}
}
int main(void)
{
	scanf("%d",&n);
	int value_temp;
	for(int i=0; i<n; i++)
	{
		vector<int> temp;
		for(int j=0; j<n; j++)
		{
			scanf("%d",&value_temp);
			temp.push_back(value_temp);
			
			answer = max(answer,value_temp);
		}
		data.push_back(temp);
	}
	solve(data,0); 
	printf("%d\n",answer);
}
	
