#include <stdio.h>
#include <string.h>
int main()
{
	char data[105];
	int i,len;
	scanf("%s",data);
	
	len = strlen(data); // ���ڿ��� ���̸� �����ִ� �Լ�. 
	for(i=0; i<len; i++)
	{
		printf("%c",data[i]);
		if(i % 10 == 9) // i�� 10���� ���� �������� 9�̸� 10��° �Է��̵�(0,1,2,3,4,5,6,7,8,9)
		{
			printf("\n");
		}
	}
}
