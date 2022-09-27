#include<bits/stdc++.h>
using namespace std;

struct Value
{
	string key;
	string value;
	Value* next;
	Value(string key, string value) : key(key), value(value), next(nullptr){}
};

struct Map
{
	int maxSize = 100000;
	vector<Value*>table;
	
	Map()
	{
		table.resize(maxSize);
	}
	
	int hash(string& str)
	{
		int p = 33;
		int hash = 0;
		for(int i = 0; i < str.size(); i++)
		{
			hash = (hash * p + str[i]) % maxSize;
		}
		return hash;
	}
	
	void put(string& key, string& value)
	{
		Value* x = search(key);
		if(x!=nullptr)
		{
			x->value = value;
			return;
		}			
		int h = hash(key);
		Value* node = new Value(key, value);
		node -> next = table[h];
		table[h] = node;
	}
	
	Value* search(string& key)
	{
		Value* node = table[hash(key)];
		while(node != nullptr)
		{
			if(node->key == key)
			{
				return node;
			}
			node = node -> next;
		}
		return nullptr;
	}
	
	void deleteKey(string& key)
	{
		int h = hash(key);
		Value* node = table[h];
		Value* prevNode = nullptr;
		
		while(node!=nullptr)
		{
			if(node -> key == key)
			{
				if(prevNode == nullptr)
				{
					table[h] = node -> next;
				}
				else
				{
					prevNode -> next = node -> next;
					node -> next = nullptr;
				}
				return;
			}
			prevNode = node;
			node = node -> next;
		}
	}
	
	std::string get(string& key)
	{
		Value* node = search(key);
		return((node == nullptr)? "none" : node -> value);
	}
};

int main()
{
	ifstream input("map.in");
	ofstream output("map.out");
	Map hashMap;
	
	while(!input.eof())
	{
		string str, key, value;
		input >> str;
		if(str == "put")
		{
			input >> key >> value;
			hashMap.put(key, value);			
		}
		else if(str == "get")
		{
			input >> key;
			output << hashMap.get(key) << endl;
		}
		else if(str == "delete")
		{
			input >> key;
			hashMap.deleteKey(key);
		}
	}
	return 0;
}
