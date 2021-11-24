#include <iostream>
#include "HashTable.h"
#include "Queue.h"
#include "Cache.h"
#include <string>

int hashFunction(const std::string& s, int table_size, int key)
{
    int hash_result = 0;
    for (int i = 0; s[i] != s[s.length()]; ++i)
        hash_result += key * s[i];
    return hash_result % table_size;;
}

class People {
public:
    std::string name;
    int number;
};
void printPeople(const People &data){
    std::cout<< data.number;
}

bool searchPeopleByName(const People& data, const std::string& key){
    if(data.name == key){return true;}else{return false;}
}


int main(){

    //Проверка хеш таблицы
//    HashTable<std::string, People> testTable(10, 5,&hashFunction);
    People John;
    People Jame;
    People David;
    John.name = "John";
    John.number = 1234567;
    Jame.name = "Jame";
    Jame.number = 7654321;
    David.name = "David";
    David.number = 89101112;
//
//    testTable.add(John.name, John);
//    testTable.add(Jame.name, Jame);
//    testTable.add(David.name, David);
//    testTable.print(printPeople);

    //Проверка очереди
//    Queue<ItemQueue<std::string>> testQueue;
//    testQueue.push(newItem(John.name));
//    testQueue.push(newItem(Jame.name));
//    testQueue.push(newItem(David.name));
//    People Out;
//
//    for (int i = 0; i < 3; ++i) {
//        cout<<testQueue.pop().key<< " ";
//        testQueue.remove();
//    }
    //Проверка динамик аррея
    DynamicArray<People, std::string> testArray;
    testArray.append(Jame);
    testArray.append(John);
    testArray.append(David);
//    for (int i = 0; i < 3; ++i) {
//        cout<< testArray[i].number << " ";
//    }
//    cout<<endl;
//    People result = testArray.search(Jame.name,searchPeopleByName);
//    cout<< result.name << " ";

    Cache<std::string, People> testCache(testArray,hashFunction, 3, 5000);
    People Georgy;
    Georgy.name = "Georgy";
    Georgy.number = 1991;
    testCache.add(Georgy);
    testCache.add(Georgy);

}