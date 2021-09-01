  
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
	TrieNode *children[indexNode]; // 다음 노드를 가리키는 포인터 배열 
	bool finish; // 해당 노드에서 끝나는 알파벳이 있는가? 
	bool nextChild;
	
	// 생성자 
	TrieNode()
	{
		finish = nextChild = false;
		for(int i=0; i<indexNode; i++)
		{
			children[i] = NULL;
		}
		
	}
	
	// 소멸자 
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
	
	// 문자열 Key를 현재 노드부터 삽입한다.
	// 삽입 후에 해당 문자열의 일관성을 확인한다.  
	bool insert(const char *key)
	{
		if(*key == '\0')
		{
			finish = true;
			
			// 문자열이 끝나는 시점
			// 다음 자식이 존재한다면 이경우의 일관성이 없다. 
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
		
		// 트라이의 자식이 존재한다는 뜻.
		// 자식에서 일관성이 없는것을 확인하거나, 
		// finish가 true면 일관성이 없다 
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
			
			if (chk && root->insert(PHONE_NUMBER) == 0) // 일관성 여부를 확인한다. 
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
