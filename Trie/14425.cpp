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
	TrieNode *children[ALPHABETS_NUM]; // ���� ��带 ����Ű�� ������ �迭 
	bool finish; // �ش� ��忡�� ������ ���ĺ��� �ִ°�? 
	
	
	// ������ 
	TrieNode()
	{
		finish = false;
		for(int i=0; i<ALPHABETS_NUM; i++)
		{
			children[i] = NULL;
		}
	}
	
	// �Ҹ��� 
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
	
	// ���ڿ� Key�� ���� ������ �����Ѵ�.
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
