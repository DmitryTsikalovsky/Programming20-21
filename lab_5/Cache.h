#ifndef INC_2SEMPROGA_CACHE_H
#define INC_2SEMPROGA_CACHE_H
#include "DynamicArray.h"
#include "HashTable.h"
#include "Queue.h"



template<class T> ItemQueue<T> newItem(const T& inputKey){
    ItemQueue<T> newItem;
    newItem.key = inputKey;
    newItem.timeCreate = clock();
    return newItem;
}

template<class V, class T> class Cache {
    HashTable<V,T> *hashTable;
    Queue<ItemQueue<T>> queue; // в очереди хранится другая структура с ключом и тайм при запросе будет удалять из хеш таблицы что то
    int cacheSize;
    time_t timeStemp;
public:
    Cache(int (*inputHashFunction)(const T& key, int maxSize, int hashKey),int inputCacheSize, time_t inputTimeStemp){
        cacheSize = inputCacheSize;
        timeStemp = inputTimeStemp;
        hashTable = new HashTable<V,T>(inputCacheSize, inputHashFunction);
    }

    void add(const V& data, const T& key){
        if (queue.getSize() != 0) {
            if (hashTable->getSize() == cacheSize || (clock() - queue.pop().timeCreate >= timeStemp) ){
                hashTable->remove(queue.pop().key);
                queue.remove();
            }
        }
        if (!hashTable->search(key)) {
            hashTable->add(data, key);
            queue.push(newItem(key));
        }


    }

    bool search(const T& key){
        if (queue.getSize() != 0) {
            if (hashTable->getSize() == cacheSize || (clock() - queue.pop().timeCreate >= timeStemp) ){
                hashTable->remove(queue.pop().key);
                queue.remove();
            }
        }
        return hashTable->search(key);
    }

    V& get(const T& key){
        return hashTable->get(key);
    }
};

#endif //INC_2SEMPROGA_CACHE_H
