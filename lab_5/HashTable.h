//
// Created by dima on 21.11.2021.
//

#ifndef GIT_HASHTABLE_H
#define GIT_HASHTABLE_H
using namespace std;

template<class T> struct Item {
    T data;
    struct Item<T> *next;
};

template<class T> class HashTable {
    int maxSize;
    int key;
    Item<T>* array;
    int (*hashFunction)(const T& data, int maxSize, int key);
public:

    HashTable(int inputMaxSize, int inputKeyHash, int (*inputHashFunction)(const T& data, int maxSize, int key)){
        this->maxSize = inputMaxSize;
        this->key = inputKeyHash;
        this->hashFunction = inputHashFunction;
        array = new Item<T>[maxSize];
    }
    
    bool search(const T& data){
        Item<T>* ptr = &array[hashFunction(data, maxSize, key)];

        while (ptr != nullptr && ptr->data != data){
            ptr = ptr->next;
        }
    }

    void add(const T& data){
        if(!search(data)) {
            int index = hashFunction(data, maxSize, key);
            Item<T> *ptr = &array[index];
            Item<T> *newPtr = new Item<T>;
            ptr->data = data;
            newPtr->data = data;
            newPtr->next = ptr->next;
            ptr->next = newPtr;
        }
    }
    void remove(const T& data){
        if(!search(data)) {
            int index = hashFunction(data, maxSize, key);
            Item<T>* ptr = &array[index];
            Item<T>* ptrPrev = ptr;
            if(ptr->data == data) {
                array[index] = nullptr;
                delete ptr;
            }
            while (ptr->data != data && ptr != nullptr){
                ptrPrev = ptr;
                ptr = ptr->next;
            }
            if(ptr->next) ptrPrev->next = ptr->next;
            delete ptr;
        }
    }
    void print(void (*printTemplate)(const T& data)){
        for (int i = 0; i < maxSize; ++i) {
            Item<T>* ptr = &array[i];
            while (ptr != nullptr){
                printTemplate(ptr->data);
                ptr = ptr->next;
            }
        }
        std::cout<<std::endl;
    }
};

#endif //GIT_HASHTABLE_H
