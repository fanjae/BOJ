#include <stdio.h>

long long int n, m;
long long int data[100005];

bool cal(long long int value) // value 시간안에 m명 이상의 사람의 심사가 가능한가? 
{
	long long int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += value / data[i];
		if (count >= m)
		{
			return true;
		}
	}
	return count >= m;
}
int main(void)
{
	scanf("%lld %lld", &n, &m);
	long long int ans = 0;
	long long int low = 1;
	long long int high = 1e18;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &data[i]);
	}

	while (low <= high)
	{
		long long int mid = (low + high) / 2;
		if (cal(mid) == true) // 시간안에 충분히 심사를 모두 할 수 있다면, 그 이상의 시간은 고려하지 않아도됨. 
		{
			ans = mid;
			high = mid - 1;
		}
		else // 시간안에 충분한 심사가 불가능하면, 더 많은 시간을 필요로 함. 
		{
			low = mid + 1;
		}
	}
	printf("%lld\n", ans);
}

