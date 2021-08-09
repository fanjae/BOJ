#include <stdio.h>

long long int n, m;
long long int data[100005];

bool cal(long long int value) // value �ð��ȿ� m�� �̻��� ����� �ɻ簡 �����Ѱ�? 
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
		if (cal(mid) == true) // �ð��ȿ� ����� �ɻ縦 ��� �� �� �ִٸ�, �� �̻��� �ð��� ������� �ʾƵ���. 
		{
			ans = mid;
			high = mid - 1;
		}
		else // �ð��ȿ� ����� �ɻ簡 �Ұ����ϸ�, �� ���� �ð��� �ʿ�� ��. 
		{
			low = mid + 1;
		}
	}
	printf("%lld\n", ans);
}

