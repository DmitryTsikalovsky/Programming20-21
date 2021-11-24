//
// Created by Dmitry Tsikalovsky on 24.11.2021.
//

#ifndef INC_2SEMPROGA_CACHE_H
#define INC_2SEMPROGA_CACHE_H
#include "DynamicArray.h"
#include "HashTable.h"
#include "Queue.h"



template<class T> ItemQueue<T> newItem(T& inputKey){
    ItemQueue<T> newItem;
    newItem.key = inputKey;
    newItem.timeCreate = clock();
    return newItem;
}

template<class T, class V> class Cache {
    DynamicArray<V,T> *bigData;
    HashTable<V,T> *hashTable;
    Queue<ItemQueue<T>> queue; // в очереди хранится другая структура с ключом и тайм при запросе будет удалять из хеш таблицы что то
    int cacheSize;
    time_t timeStemp;
public:
    Cache(DynamicArray<V,T>& inputArray, int (*inputHashFunction)(const T& key, int maxSize, int hashKey),int inputCacheSize, time_t inputTimeStemp){
        bigData = new DynamicArray<V,T>(inputArray);
        cacheSize = inputCacheSize;
        timeStemp = inputTimeStemp;
        hashTable = new HashTable<V,T>(inputCacheSize, inputHashFunction);
    }

    void add(V& data){
        bigData->append(data);
    }

    void remove(T& key, V& data){
        hashTable->remove(key);
        bigData->remove(data);
    }

    V& get(T& key, bool (*searchFunction)(const T& key)){
        if (hashTable->search(key)){
            return hashTable->get(key);
        } else {
            V result = bigData->search(key, searchFunction);
            if (hashTable->getSize() >= cacheSize || (queue.pop().timeCreate + timeStemp < clock()) ){
                hashTable->remove(queue.pop().key);
                queue.remove();
            }
            hashTable->add(key, result);
            queue.push(newItem(key));
        }
    }
};

#endif //INC_2SEMPROGA_CACHE_H
