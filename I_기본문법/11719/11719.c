#include <stdio.h>
int main()
{
	int i = 0;
	char data[105][105];
	while(gets(data[i]) != NULL) // gets는 scanf와 다르게 space도 입력 받을 수 있다.
	{
		puts(data[i]); // printf와 다르게 자동 개행('\n')이 일어남.
		i++;
	}
}
