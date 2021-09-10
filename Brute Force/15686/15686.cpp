/* 
https://www.acmicpc.net
Problem ID : 15686
Brute Force 
*/
#include <stdio.h>
#include <cmath>
#include <stdbool.h>
#include <vector>

using namespace std;
struct my_pair
{
	int x;
	int y;	
};
int data[55][55];
int arr[5]={1,2,3,4,5};
int n,m;
int chicken_house_size;
int house_size;
long long int ans_value = 125000;

bool selected[20];

vector <my_pair> chicken_house;
vector <my_pair> house;

void cal()
{
	long long int sum = 0;
	for(int i=0; i<house_size; i++)
	{
		long long int temp_value = 0;
		long long int min_value = 0;
		for(int j=0; j<chicken_house_size; j++) // ġŲ�� ������ŭ ��� ġŲ �Ÿ��� �����. 
		{
			if(selected[j] == true)
			{
				my_pair temp;
				temp.x = chicken_house[j].x;
				temp.y = chicken_house[j].y;
				temp_value = abs(temp.x - house[i].x) + abs(temp.y - house[i].y); // ġŲ������ �Ÿ� ���. 
				if(min_value == 0 || temp_value < min_value) // ġŲ �Ÿ� 
				{
					min_value = temp_value;
				}
			}
		}
		sum += min_value;
	}
	if(ans_value > sum)
	{
		ans_value = sum;
	}
}
void combination(int value, int cnt) // M���� ������ ġŲ���� �����Ѵ�. 
{
	if(cnt == m) // m���� �����ߴٸ� ����� �����Ѵ�.  
	{
		cal();
		return ;	
	}
	
	for(int i=value; i<chicken_house_size; i++)
	{
		if(selected[i] == true) continue;
		selected[i]=true;
		
		combination(i,cnt+1);
		selected[i]=false;
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			my_pair temp;
			scanf("%d",&data[i][j]);
			if(data[i][j] == 1) // �� 
			{
				temp.x = i;
				temp.y = j;
				house.push_back(temp); 
			}
			else if(data[i][j] == 2) // ġŲ�� 
			{
				temp.x = i;
				temp.y = j;
				chicken_house.push_back(temp);
			}
		}
	}
	chicken_house_size = chicken_house.size();
	house_size = house.size();
	combination(0,0); 
	
	printf("%lld\n",ans_value);
}
