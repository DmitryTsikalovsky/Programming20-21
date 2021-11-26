#include <iostream>
#include "HashTable.h"
#include "Queue.h"
#include "Cache.h"
#include <string>
#include <chrono>
#include <cmath>

//class Timer {
//    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
//public:
//    void Start(){
//        m_StartTime = std::chrono::high_resolution_clock::now();
//    }
//
//    double_t GetDuration(){
//        chrono::duration<double_t> duration = chrono::high_resolution_clock::now() - m_StartTime;
//        return duration.count();
//    }
//};

int hashFunction(const std::string& s, int table_size, int key)
{
    int hash_result = 0;
    for (int i = 0; s[i] != s[s.length()]; ++i)
        hash_result += key * s[i];
    return hash_result % table_size;
}

int idHashFunction(const int &s, int table_size, int key)
{
    return (s * key) % table_size;
}

class People {
public:
    std::string name;
    int number;
    int id;
};
void printPeople(const People &data){
    std::cout<< data.number;
}

bool searchPeopleByName(const People& data, const std::string& key){
    if(data.name == key){return true;}else{return false;}
}

bool searchPeopleById(const People& data, const int &key){
    if(data.id == key){return true;}else{return false;}
}


int main(){

    //Проверка хеш таблицы
//    HashTable<People, std::string> testTable(10,&hashFunction);
    People John;
    People Jame;
    People David;
    John.name = "John";
    John.number = 1234567;
    John.id = 1;
    Jame.name = "Jame";
    Jame.id = 2;
    Jame.number = 7654321;
    David.name = "David";
    David.id = 3;
    David.number = 89101112;

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
    DynamicArray<People, int> testArray;
    testArray.append(Jame);
    testArray.append(John);
    testArray.append(David);
//    for (int i = 0; i < 3; ++i) {
//        cout<< testArray[i].number << " ";
//    }
//    cout<<endl;
//    People result = testArray.search(Jame.name,searchPeopleByName);
//    cout<< result.name << " ";

    Cache<People,int> testCache(idHashFunction, 3, 5000);
    People Georgy;
    Georgy.name = "Georgy";
    Georgy.number = 1991;
    Georgy.id = 4;
    testCache.add(Georgy, Georgy.id);
    testCache.add(Jame, Jame.id);
    testCache.add(John, John.id);
    testCache.add(David, David.id);

//    Timer timer;
//    timer.Start();
//    cout<< testCache.get(Georgy.name, &searchPeopleByName).name << " " << timer.GetDuration() << endl;
      cout<< testCache.get(Georgy.id).name << " "<< endl;
      cout<< testCache.get(Jame.id).name << " "<< endl;

      cout<< testCache.get(John.id).name << " "<< endl;

//    timer.Start();
//    cout<< testCache.get(Georgy.name, &searchPeopleByName).name << " " << timer.GetDuration()<< endl;




}