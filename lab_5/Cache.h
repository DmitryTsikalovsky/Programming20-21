//
// Created by Dmitry Tsikalovsky on 24.11.2021.
//

#ifndef INC_2SEMPROGA_CACHE_H
#define INC_2SEMPROGA_CACHE_H
#include "DynamicArray.h"
#include "HashTable.h.h"

struct ItemQueue<class V> {
    V key;
    int timeStemp;
};

template<class T, class V> class Cache {
    DynamicArray<V> *bigData;
    HashTable<T,V> *hashTable;
    //queue дописать из динамик аррей
    // в очереди хранится другая структура с ключом и тайм при запросе будет удалять из хеш таблицы что то
    int cacheSize;
    int timeStemp;
public:
    Cache(DynamicArray<V>& inputArray, int inputCacheSize, int inputTimeStemp){

    }

    void add(V& key, T& data){

    }

    void remove(V& key, T& data){

    }

    T& get(V& key, T& data){
        // дописать в хеш таблицу гет
    }
};

#endif //INC_2SEMPROGA_CACHE_H
