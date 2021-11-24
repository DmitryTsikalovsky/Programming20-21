//
// Created by dima on 21.11.2021.
//

#ifndef GIT_HASHTABLE_H
#define GIT_HASHTABLE_H
using namespace std;

template<class V, class T> struct ItemHash {
    T key;
    V value;
    struct ItemHash<T,V> *next;
    bool isEmpty = true;
};

template<class V, class T> class HashTable {
    int size;
    int maxSize;
    int hashKey;
    ItemHash<V,T>* array;
    int (*hashFunction)(const T& key, int maxSize, int hashKey);
public:
    int getSize(){
        return size;
    }


    HashTable(int inputMaxSize, int (*inputHashFunction)(const T& key, int maxSize, int hashKey)){
        this->maxSize = inputMaxSize;
        this->hashKey = rand() % 10;
        this->hashFunction = inputHashFunction;
        array = new ItemHash<V,T>[maxSize];
        size = 0;
    }
    
    bool search(const T& key){
        ItemHash<T,V>* ptr = &array[hashFunction(key, maxSize, hashKey)];
        while (ptr != nullptr && ptr->key != key){
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    void add(const T& key, const V& value){ // и V value;
        if(!search(key)) {
            ItemHash<T,V> *ptr = &array[hashFunction(key, maxSize, hashKey)];
            if (ptr->isEmpty) {
                ptr->key = key;
                ptr->value = value;
                ptr->isEmpty = false;
            } else {
                ItemHash<T,V> *newPtr = new ItemHash<T,V>;
                newPtr->key = key;
                newPtr->value = value;
                newPtr->isEmpty = false;
                ptr->next = newPtr;
            }
            size++;
        }
    }
    void remove(const T& key){
        if(search(key)) {
            ItemHash<T,V>* ptr = &array[hashFunction(key, maxSize, hashKey)];
            ItemHash<T,V>* ptrPrev = ptr;
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
            size--;
        }
    }
    void print(void (*printTemplate)(const V& value)){ // заменим потом параметр на V, будет печатать именно value
        for (int i = 0; i < maxSize; ++i) {
            ItemHash<T,V>* ptr = &array[i];
            while (ptr != nullptr){
                if (!ptr->isEmpty) {
                    printTemplate(ptr->value);
                    std::cout<<" ";
                }
                ptr = ptr->next;
            }
        }
        std::cout<<std::endl;
    }

    V& get(const T& key) {
        if(search(key)) {
            ItemHash<T,V>* ptr = &array[hashFunction(key, maxSize, hashKey)];
            return ptr->value;
        }
    }
};

#endif //GIT_HASHTABLE_H
