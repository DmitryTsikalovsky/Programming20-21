#include <iostream>
#include "HashTable.h"
#include "DynamicArray.h"
#include "Queue.h"
#include "Cache.h"
#include <string>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
public:
    void Start(){
        m_StartTime = std::chrono::high_resolution_clock::now();
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
    return hash_result % table_size;
}

int idHashFunction(const int &s, int table_size, int key)
{
    return (s + key) % table_size;
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

People *genRandomPeople(int n){
    auto *line = new std::string[617];

    std::ifstream in("Names.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        int i = 0;
        while (getline(in, line[i])){
//            std::cout<< line[i]<<endl;
            i++;
        }

    }
    in.close();
    People *insertPeople = new People[n];
    for (int i = 0; i < n; ++i) {
        insertPeople[i].name = line[rand() % 616];
        insertPeople[i].number = rand() % 100;
        insertPeople[i].id = i;
    }
    return insertPeople;
}

void createArrayOfWords(){
    std::vector<std::string> words;
    std::string line;
    std::string word;
    std::ifstream in("Names.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line, ' ')){
            words.push_back(line);
        }

    }

    for (int i = 0; i < 100; ++i) {
        std::cout<<words[i]<<std::endl;
    }
    in.close();
    return;
}


int main(){
    createArrayOfWords();

//    DynamicArray<People> bigData(genRandomPeople(10000), 10000);
//    for (int i = 0; i < 10000; ++i) {
//        cout<< bigData[i].name << " "<< endl;
//    }
//    Cache<People, int> theBestCacheInTheWorld(idHashFunction, 100,10000);
//
//    for (int i = 0; i < 999; ++i) {
//        theBestCacheInTheWorld.add(bigData[i], bigData[i].id);
//    }
//
//    for (int i = 0; i < 1000; ++i) {
//        if (theBestCacheInTheWorld.search(bigData[i].id)){
//            cout<< theBestCacheInTheWorld.get(bigData[i].id).id<<  " "<<theBestCacheInTheWorld.get(bigData[i].id).name << endl;
//        }
//    }
//    std::cout<< endl;
//    std::cout<< theBestCacheInTheWorld.get(bigData[0].id).name << " "<< endl;




}