
#ifndef HASHMAP
#define HASHMAP
#include <vector>
#include <forward_list>
#include <utility>
#include <stdexcept>

template <typename Data>
class HashMap
{
	private:
	std::vector<std::forward_list<std::pair<int, Data>>> table;
	int tableSize;
	int cap;
	//hashing function
	int hashFunction(int key) {
		return key % cap;
	}
	//resizing/rehashing
	void resize();
	public:
	HashMap(): cap{7}, tableSize{}, table{7} {};
	bool insert(const int, const Data&);
	Data search(const int);
	bool remove(int);	
	int size() const {return tableSize;}
	int capasity() const {return cap;}
};

template <typename Data>
bool HashMap<Data>::insert(const int key, const Data& data) {
	resize();
	int index{hashFunction(key)};
	for (auto& it: table[index]) {
		if (it.first == key) {
			it.second = data;
			++tableSize;
			return true;
		}
	}
	table[index].push_front(std::make_pair(key, data));
	++tableSize;
	return true;
}

template <typename Data>
Data HashMap<Data>::search(const int key) {
	int index{hashFunction(key)};
	for (auto& it :table[index]) {
		if(it.first == key) {
			return it.second;
		}
	}
	throw std::runtime_error("Element not found"); // Throw an exception for "not found"
}
template <typename Data>
bool HashMap<Data>::remove(int key) {
	int index{hashFunction(key)};
	std::forward_list<std::pair<int, Data>>& current{table[key]};
	auto prevNode{current.before_begin()};
	for (auto it = current.begin(); it != current.end(); ++it) {
		if (it->first == key) {
			current.erase_after(prevNode);
			--tableSize;
			return true;
		}
		++prevNode;
	}
	
	throw std::runtime_error("Element doesn't exists");
}

template <typename Data> 
void HashMap<Data>::resize(){
	//checking if resize is needed
	if( (tableSize / cap) < 1) {
		return;
	}
	//find the second simple number
	++cap;
	while (true) {
		for (int i{2}; i < cap; ++i) {
			bool stop{false};
			cap % i ? stop : stop = true;
			if (stop) {
				++cap;
				continue;
			}
		}
		break;
	}
	//move all the elements to the new table	
	std::vector<std::forward_list<std::pair<int, Data>>> tmp(cap);
	for (auto& it : table) {
		for (auto& i :it) {
			int index{hashFunction(i.first)};
			tmp[index].push_front(i);
		}	
	}			
	table.clear();
	table = tmp;
	std::cout << "New cap: " << cap << std::endl;
}
	
#endif
