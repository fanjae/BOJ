/* 
https://www.acmicpc.net
Problem ID : 11441
Sieve of Eratosthenes
*/

#include <stdio.h>
#include <vector>

#define LIMIT 1300000

using namespace std;
vector <int> prime;
bool arr[2000005];

void eratos()
{
	for(int i=2; i<=LIMIT; i++) // �迭 �ʱ�ȭ 
	{
		arr[i] = true;
	}
	
	for(int i=2; i<=LIMIT; i++) // 130�������� �Ҽ� ���ϱ� 
	{
		if(arr[i] == false) // �̹� �ɷ��� ��� ���� X 
		{
			continue;
		}
		for(int j=i+i; j<=LIMIT; j+=i) // i�� ��� ��� ���� 
		{
			arr[j] = false;
		}
	}
	
	for(int i=2; i<=LIMIT; i++) // �Ҽ��� ���� ���� 
	{
		if(arr[i] == true)
		{
			prime.push_back(i);
		}
	}
}

int main(void)
{
	int T;
	eratos();
	scanf("%d",&T);
	while(T--)
	{
		int n;
		bool flag = false;
		int index = 0;
		scanf("%d",&n);
		for(int i=0; ; i++)
		{
			if(prime[i] == n) // �Ҽ��� ��� 0 ��� 
			{
				printf("0\n");
				flag = true;
			}
			if(prime[i] > n) // n���� ū �Ҽ� �� ���� 
			{
				index = i;
				break;
			}
		}
		if(flag == false)
		{
			printf("%d\n",prime[index]-prime[index-1]); // �Ҽ��� �Ҽ������� ���� ���� ��� 
		}
	}
}
	
	
