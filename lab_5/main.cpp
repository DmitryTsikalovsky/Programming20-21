#include <iostream>
#include "HashTable.h"
#include "Queue.h"
#include "Cache.h"
#include <string>
#include <chrono>
#include <cmath>
#include <fstream>

class Timer {
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
public:
    void Start(){
        m_StartTime = chrono::high_resolution_clock::now();
    }

    double_t GetDuration(){
        chrono::duration<double_t> duration = chrono::high_resolution_clock::now() - m_StartTime;
        return duration.count();
    }
};

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

DynamicArray<People, std::string>& genRandomPeople(int n){
    DynamicArray<People, std::string> randomArray(n);
    auto *line = new std::string[617];

    std::ifstream in("/home/dima/CLionProjects/git/Programming20-21/lab_5/Names.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        int i = 0;
        while (getline(in, line[i])){
//            std::cout<< line[i]<<endl;
            i++;
        }

    }
    in.close();
    People insertPeople;
    for (int i = 0; i < n; ++i) {
        insertPeople.name = line[rand() % 617];
        insertPeople.number = rand() % 100;
        randomArray.append(insertPeople);
    }

}


int main(){

    //Проверка хеш таблицы
//    HashTable<People, std::string> testTable(10,&hashFunction);
//    People John;
//    People Jame;
//    People David;
//    John.name = "John";
//    John.number = 1234567;
//    Jame.name = "Jame";
//    Jame.number = 7654321;
//    David.name = "David";
//    David.number = 89101112;

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
//    DynamicArray<People, std::string> testArray;
//    testArray.append(Jame);
//    testArray.append(John);
//    testArray.append(David);
//    for (int i = 0; i < 3; ++i) {
//        cout<< testArray[i].number << " ";
//    }
//    cout<<endl;
//    People result = testArray.search(Jame.name,searchPeopleByName);
//    cout<< result.name << " ";

//    Cache<std::string, People> testCache(testArray,hashFunction, 3, 5000);
//    People Georgy;
//    Georgy.name = "Georgy";
//    Georgy.number = 1991;
//    testCache.add(Georgy);
//    testCache.add(Georgy);
//
//    Timer timer;
//    timer.Start();
//    cout<< testCache.get(Georgy.name, &searchPeopleByName).name << " " << timer.GetDuration() << endl;
//    timer.Start();
//    cout<< testCache.get(Georgy.name, &searchPeopleByName).name << " " << timer.GetDuration()<< endl;


// Тест генерации рандомных имен
    genRandomPeople(10);



}