#include <vector>
#include <iostream>
#include <list>

class MyHashMap {
private:
    std::vector<std::list<std::pair<int, int>>> data;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap(): data(base) {}
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        auto iter = data[h].begin();
        for (; iter != data[h].end(); iter++) {
            if (iter->first == key) {
                iter->second = value;
                return;
            }
        }
        data[h].push_back(std::make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        auto iter = data[h].begin();
        for (; iter != data[h].end(); iter++) {
            if (iter->first == key) {
                return iter->second;
            }
        }
        return  -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        auto iter = data[h].begin();
        for (; iter != data[h].end(); iter++) {
            if (iter->first == key) {
                data[h].erase(iter);
            }
        }
    }
};

int main() {

	return 0;
}