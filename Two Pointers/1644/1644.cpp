#include <iostream>
#include <vector>
using namespace std;
#define LIMIT 4000000
int n;
bool arr[4000005];
vector <int> prime;  
void eratos() // 에라토스테네스의 체 
{
	for(int i=1; i<=LIMIT; i++) // 배열 초기화 
	{
		arr[i] = true;
	}
 
	for(int i=2; i<=LIMIT; i++) 
	{
		if(arr[i] == false) continue;
		for(int j=i+i; j<=LIMIT; j+=i) // 
		{
			arr[j] = false;
		}
	}
	for(int i=2; i<=LIMIT; i++) // 소수인 수만 따로 담음 
	{
		if(arr[i] == true)
		{
			prime.push_back(i);
		}
	}
}
int main() 
{
	int start,end;
	int cnt = 0;
	int sum = 0;
	int prime_size;
	start = end = 0;
 
	scanf("%d",&n);
	if(n == 1)
	{
		printf("0");
		return 0;
	}
	eratos();
 
	prime_size = prime.size(); // 소수가 담긴 벡터 사이즈를 구해둠 
	while(start < prime_size && end < prime_size && start <= end && prime[start] <= n)
	{
		if(sum + prime[end] < n) // n보다 작으면 끝값 추가. 
		{
			sum = sum + prime[end];
			end++;
		}
		else if(sum + prime[end] == n) // n과 같으면 연속합 만족 개수 1개 추가 후 시작점을 한칸 당기고 처음부터 다시시작. 
		{
			sum = 0;
			start++;
			end = start;
			cnt++;
		}
		else if(sum + prime[end] > n) // n보다 크면 맨 앞값 삭제 
		{
			sum = sum - prime[start];
			start++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
