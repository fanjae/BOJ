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
	for(int i=2; i<=LIMIT; i++) // 배열 초기화 
	{
		arr[i] = true;
	}
	
	for(int i=2; i<=LIMIT; i++) // 130만까지의 소수 구하기 
	{
		if(arr[i] == false) // 이미 걸러진 경우 진입 X 
		{
			continue;
		}
		for(int j=i+i; j<=LIMIT; j+=i) // i의 배수 모두 제거 
		{
			arr[j] = false;
		}
	}
	
	for(int i=2; i<=LIMIT; i++) // 소수만 따로 담음 
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
			if(prime[i] == n) // 소수인 경우 0 출력 
			{
				printf("0\n");
				flag = true;
			}
			if(prime[i] > n) // n보다 큰 소수 값 구함 
			{
				index = i;
				break;
			}
		}
		if(flag == false)
		{
			printf("%d\n",prime[index]-prime[index-1]); // 소수와 소수사이의 수열 길이 출력 
		}
	}
}
	
	
