/* 
https://www.acmicpc.net
Problem ID : 2312
Sieve of Eratosthenes
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <vector>

using namespace std;
vector <int> prime;
void eratos()
{
	bool arr[100005]={0};
	for(int i=2; i<=100000; i++) // �迭 �ʱ�ȭ 
	{
		arr[i] = true;
	}
	
	for(int i=2; i<=100000; i++) // 10�������� �Ҽ� ���ϱ� 
	{
		if(arr[i] == false) // �̹� �ɷ��� ��� �������� ���� 
		{
			continue;
		}
		for(int j=i+i; j<=100000; j+=i) // i�� ��� ��� ���� 
		{
			arr[j] = false;
		}
	}
	
	for(int i=2; i<=100000; i++) // �Ҽ��� ���� ���� 
	{
		if(arr[i] == true)
		{
			prime.push_back(i);
		}
	}
}
int main(void)
{
	eratos();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int temp_n;
		int index = 0;
		scanf("%d",&n);
		
		temp_n = n;
		while(temp_n != 1)
		{
			int count = 0;
			bool find = false;
			while(temp_n % prime[index] == 0) // �ش� �Ҽ��� ���� �� ������ ���� ���� ���� ���� 
			{
				temp_n = temp_n / prime[index];
				count++;
				find = true;
			}
			if(find)
			{
				printf("%d %d\n",prime[index],count);
			}
			index++;	
		}
	}
}
