#include <stdio.h>
int main()
{
	char data[105]; // 문자 배열(문자열) 선언
	while(gets(data) != NULL) // 입력 개수가 나오지 않았으므로 NULL 만큼 반복할 것
	{
		printf("%s\n",data); // %s는 입력값이 NULL 직전까지 출력함.
	}
}
