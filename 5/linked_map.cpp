#include<bits/stdc++.h>

struct Value 
{
	std::string key;
	std::string value;
	Value* next;
	Value* linked_next;
	Value* linked_prev;
	Value(std::string key, std::string value, Value* prev, Value* next) : next(nullptr), key(key), value(value), linked_prev(prev), linked_next(next) {}
};

struct LinkedMap
{
	int maxSize = 100000;
	std::vector<Value*> table;
	
	Value* header;
	Value* linked_next;
	Value* linked_prev;
	
	
	LinkedMap()
	{
		linked_next = nullptr;
		linked_prev = nullptr;
		header = new Value("none", "none", nullptr, nullptr);
		header -> linked_prev = header;
		header -> linked_next = header;
		table.resize(maxSize);
	}
	
	
	int hash(std::string& str)
	{
		int p = 33;
		int hash = 0;
		for(int i = 0;  i < str.size(); i++)
		{
			hash= (hash * p + str[i]) % maxSize;
		}
		return hash;
	}
	
	void put(std::string& key, std::string& value)
	{
		Value* x = search(key);
		if(x != nullptr)
		{
			x -> value = value;
			return;
		}
		
		int h = hash(key);
		Value* node = new Value(key, value, header->linked_prev, header);
		header -> linked_prev -> linked_next = node;
		node -> next = table[h];
		table[h] = node;
		header -> linked_prev = node;
	}
	
	std::string next(std::string &key)
	{
		Value* node = search(key);
		return node == nullptr ? "none" : node -> linked_next -> value;
	}
	
	std::string prev(std::string& key)
	{
		Value* node = search(key);
		return node == nullptr? "none" : node -> linked_prev -> value;
	}
	
	Value* search(std::string& key)
	{
		Value* node = table[hash(key) % maxSize];
		while(node!= nullptr)
		{
			if(node->key == key)
			{
				return node;
			}
			node = node -> next;
		}
		return nullptr;
	}
	
	std::string get(std::string& key)
	{
		Value* node = search(key);
		return node == nullptr? "none" : node -> value;
	}
	
	void deleteVal(std::string& key)
	{
		int h = hash(key);
		Value* node = table[h];
		Value* prev_node = nullptr;
		while(node != nullptr)
		{
			if(node -> key == key)
			{
				node -> linked_next -> linked_prev = node -> linked_prev;
				node -> linked_prev -> linked_next = node -> linked_next;
				if(prev_node == nullptr)
				{
					table[h] = node -> next;
				}
				else
				{
					prev_node -> next = node -> next;
					node -> next = nullptr;
				}
				return;
			}
			prev_node = node;
			node = node -> next;
		}
	}	
};

int main()
{
	std::ifstream input("linkedmap.in");
	std::ofstream output("linkedmap.out");
	LinkedMap linkedmap;
	while(!input.eof())
	{
		std::string str;
		std::string key;
		input >> str >> key;
		if(str == "put")
		{
			std::string value;
			input >> value;
			linkedmap.put(key, value);
		}
		if(str == "delete")
		{
			linkedmap.deleteVal(key);
		}
		if(str == "get")
		{
			output << linkedmap.get(key) << std::endl;
		}
		if(str == "prev")
		{
			output << linkedmap.prev(key) << std::endl;
		}
		if(str == "next")
		{
			output << linkedmap.next(key) << std::endl;
		}
	}
}
