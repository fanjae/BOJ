#include <stdio.h>
int main()
{
	int i = 0;
	char data[105][105];
	while(gets(data[i]) != NULL)
	{
		printf("%s\n",data[i]);
		i++;
	}
}
