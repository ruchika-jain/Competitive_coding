/*

Link : https://leetcode.com/problems/lru-cache/

Problem Statement :
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

*/

//Solution :

class LRUCache {
public:
    list<int> recent;
    unordered_map<int, int> cache;
    //list is doubly linked list implemented STL in C++
    unordered_map<int, list<int>::iterator> position;
    void use(int key) {
        if(position.count(key)) {
            recent.erase(position[key]);
        } else if(recent.size() >= capacity_) {
            int old = recent.back();
            recent.pop_back();
            cache.erase(old);
            position.erase(old);
        }
        recent.push_front(key);
        position[key] = recent.begin();
    }
    
    int capacity_;
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            use(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
