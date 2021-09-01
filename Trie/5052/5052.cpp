  
/* 
https://www.acmicpc.net
Problem ID : 5052
Trie
*/

#include <iostream>
#include <cstring>

using namespace std;

const int indexNode = 10;

struct TrieNode
{
	TrieNode *children[indexNode]; // ���� ��带 ����Ű�� ������ �迭 
	bool finish; // �ش� ��忡�� ������ ���ĺ��� �ִ°�? 
	bool nextChild;
	
	// ������ 
	TrieNode()
	{
		finish = nextChild = false;
		for(int i=0; i<indexNode; i++)
		{
			children[i] = NULL;
		}
		
	}
	
	// �Ҹ��� 
	~TrieNode()
	{
		for(int i=0; i<indexNode; i++)
		{
			if(children[i])
			{
				delete children[i];
			}
		}	
	}
	
	// ���ڿ� Key�� ���� ������ �����Ѵ�.
	// ���� �Ŀ� �ش� ���ڿ��� �ϰ����� Ȯ���Ѵ�.  
	bool insert(const char *key)
	{
		if(*key == '\0')
		{
			finish = true;
			
			// ���ڿ��� ������ ����
			// ���� �ڽ��� �����Ѵٸ� �̰���� �ϰ����� ����. 
			if(nextChild)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		
		int next_value = *key - '0';
		
		if(!children[next_value])
		{
			children[next_value] = new TrieNode;
		}
		
		nextChild = true;
		
		// Ʈ������ �ڽ��� �����Ѵٴ� ��.
		// �ڽĿ��� �ϰ����� ���°��� Ȯ���ϰų�, 
		// finish�� true�� �ϰ����� ���� 
		bool get = children[next_value]->insert(key + 1);
		
		return !finish && get;
	}

};
	
int main(void)
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		int n;
		scanf("%d",&n);
		
		TrieNode *root = new TrieNode;
		bool chk = true;
		
		for(int i=0; i<n; i++)
		{
			char PHONE_NUMBER[15];
			scanf("%s",PHONE_NUMBER);
			
			if (chk && root->insert(PHONE_NUMBER) == 0) // �ϰ��� ���θ� Ȯ���Ѵ�. 
			{
				chk = false;
			}
		}
		
		if(chk == true)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		
		delete root;
	}
	
	return 0;
}
