#include <stdio.h>
#include <string.h>
int main(void)
{
	int n;
	int index[35]={0};
	int len[35]={0};
	
	bool alphabet[27]={0};
	char data[35][105];
	
	scanf("%d",&n);
	getchar();
	for(int i=0; i<n; i++)
	{
		gets(data[i]);
		len[i] = strlen(data[i]);
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<len[i]; j++)
		{
			if(data[i][j] >= 'a' && data[i][j] <= 'z')
			{
				if(alphabet[data[i][j]-'a'] == false)
				{
					index[i] = j;
					alphabet[data[i][j]-'a'] = true;
					break;	
				}
			}
			else if(data[i][j] >= 'A' && data[i][j] <= 'Z')
			{
				if(alphabet[data[i][j]-'A'] == false)
				{
					index[i] = j;
					alphabet[data[i][j]-'A'] = true;
					break;	
				}				
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<len[i]; j++)
		{
			if(index[i] == j)
			{
				printf("[");
				printf("%c",data[i][j]);
				printf("]");
			}
			else
			{
				printf("%c",data[i][j]);
			}
		}
		printf("\n");
	}
		
}
