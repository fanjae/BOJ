#include <stdio.h>
int main()
{
	char data[105];
	while(gets(data) != NULL)
	{
		printf("%s\n",data);
	}
}
