//
// Created by dima on 21.11.2021.
//

#ifndef GIT_HASHTABLE_H
#define GIT_HASHTABLE_H
using namespace std;

template<class T, class V> struct Item {
    T key;
    V value;
    struct Item<T,V> *next;
    bool isEmpty = true;
};

template<class T, class V> class HashTable {
    int maxSize;
    int hashKey;
    Item<T,V>* array;
    int (*hashFunction)(const T& key, int maxSize, int hashKey);
public:

    HashTable(int inputMaxSize, int inputHashKey, int (*inputHashFunction)(const T& key, int maxSize, int hashKey)){
        this->maxSize = inputMaxSize;
        this->hashKey = inputHashKey;
        this->hashFunction = inputHashFunction;
        array = new Item<T,V>[maxSize];
    }
    
    bool search(const T& key){
        Item<T,V>* ptr = &array[hashFunction(key, maxSize, hashKey)];
        while (ptr != nullptr && ptr->key != key){
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    void add(const T& key){ // и V value;
        if(!search(key)) {
            Item<T,V> *ptr = &array[hashFunction(key, maxSize, hashKey)];
            if (ptr->isEmpty) {
                ptr->key = key;
                ptr->isEmpty = false;
            } else {
                Item<T,V> *newPtr = new Item<T,V>;
                newPtr->key = key;
                newPtr->isEmpty = false;
                ptr->next = newPtr;
            }
        }
    }
    void remove(const T& key){
        if(search(key)) {
            Item<T,V>* ptr = &array[hashFunction(key, maxSize, hashKey)];
            Item<T,V>* ptrPrev = ptr;
            if(ptr->key == key) {
                if (ptr->next != nullptr) {
                    ptr->key = ptr->next->key;
                    ptrPrev = ptr->next;
                    ptr->next = ptrPrev->next;
                    delete ptrPrev;
                } else {
                    ptr->isEmpty = true;
                }
            } else {
                while (ptr->key != key && ptr != nullptr){
                    ptrPrev = ptr;
                    ptr = ptr->next;
                }
                if(ptr->next) ptrPrev->next = ptr->next;
                delete ptr;
            }
        }
    }
    void print(void (*printTemplate)(const T& key)){ // заменим потом параметр на V, будет печатать именно value
        for (int i = 0; i < maxSize; ++i) {
            Item<T,V>* ptr = &array[i];
            while (ptr != nullptr){
                if (!ptr->isEmpty) {
                    printTemplate(ptr->key);
                    std::cout<<" ";
                }
                ptr = ptr->next;
            }
        }
        std::cout<<std::endl;
    }
};

#endif //GIT_HASHTABLE_H
