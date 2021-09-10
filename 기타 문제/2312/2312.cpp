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
	for(int i=2; i<=100000; i++) // 배열 초기화 
	{
		arr[i] = true;
	}
	
	for(int i=2; i<=100000; i++) // 10만까지의 소수 구하기 
	{
		if(arr[i] == false) // 이미 걸러진 경우 진입하지 않음 
		{
			continue;
		}
		for(int j=i+i; j<=100000; j+=i) // i의 배수 모두 제거 
		{
			arr[j] = false;
		}
	}
	
	for(int i=2; i<=100000; i++) // 소수만 따로 담음 
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
			while(temp_n % prime[index] == 0) // 해당 소수로 나눌 수 있으면 나눈 이후 개수 증가 
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
