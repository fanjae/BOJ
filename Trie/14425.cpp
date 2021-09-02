#include <iostream>
#include <cstring>

using namespace std;

const int ALPHABETS_NUM = 26;

int ALPHABET_INDEX(char ch)
{
	return ch - 'a';
}

struct TrieNode
{
	TrieNode *children[ALPHABETS_NUM]; // 다음 노드를 가리키는 포인터 배열 
	bool finish; // 해당 노드에서 끝나는 알파벳이 있는가? 
	
	
	// 생성자 
	TrieNode()
	{
		finish = false;
		for(int i=0; i<ALPHABETS_NUM; i++)
		{
			children[i] = NULL;
		}
	}
	
	// 소멸자 
	~TrieNode()
	{
		for(int i=0; i<ALPHABETS_NUM; i++)
		{
			if(children[i])
			{
				delete children[i];
			}
		}	
	}
	
	// 문자열 Key를 현재 노드부터 삽입한다.
	void insert(string &str, int i)
	{
		if(str.size() == i)
		{
			finish = true;
		}
		else
		{
			int nextNode = ALPHABET_INDEX(str[i]);
			if(children[nextNode] == NULL)
			{
				children[nextNode] = new TrieNode();
			}
			children[nextNode]->insert(str, i + 1);
		}
	}
	
	bool find(string& str, int i)
	{
		if(str.size() == i)
		{
			return finish;
		}
		
		int nextNode = str[i] - 'A';
		
		if(children[nextNode] == NULL)
		{
			return false;
		}
		
		return children[nextNode]->find(str,i+1);
	}
};
	
int main(void)
{
		
}
