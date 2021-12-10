#include <iostream>
#include "../lab_5/HashTable.h"
#include "../lab_5/DynamicArray.h"
#include "../lab_5/Queue.h"
#include "../lab_5/Cache.h"
#include <string>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

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
            line.erase(std::remove_if(line.begin(),
                                      line.end(),
                             [](char c)
                             { return c==','||c=='.'|| c=='!'; }), line.end());
            words.push_back(line);
        }

    }
    in.close();
    unordered_map<std::string, int>HashWord;
    for (int i = 0; i < words.size(); ++i) {
        HashWord[words[i]] += 1;
    }
    vector<ItemHash<int, std::string>> wordsWithNumber;
    ItemHash<int, std::string> ItemWord;
    for (auto iter = HashWord.begin(); iter != HashWord.end(); ++iter) {
        ItemWord.key = iter->first;
        ItemWord.value = iter->second;
        wordsWithNumber.push_back(ItemWord);
    }

    sort(wordsWithNumber.begin(), wordsWithNumber.end(), [](const ItemHash<int, std::string>& n1, const ItemHash<int, std::string>& n2){return n1.value>n2.value;});

    for (auto iter = wordsWithNumber.begin(); iter != wordsWithNumber.end(); ++iter) {
        if (iter->value != 0) {
            cout << iter->value << " " << iter->key <<endl;
        }
    }
    return;
}

void lessontask(const vector<int>&A, const vector<int>&B){
    unordered_map<int, int>ImageGoodNameOfThis;
    for (int i = 0; i < A.size(); ++i) {
        ImageGoodNameOfThis[A[i]] = 1;
    }
    for (int j = 0; j < B.size(); ++j) {
        if (ImageGoodNameOfThis[B[j]] == 1) {
            ImageGoodNameOfThis[B[j]] = 3;
        } else {
            ImageGoodNameOfThis[B[j]] = 2;
        }
    }
    std::cout<< "Пересечение"<<endl;
    for (auto iter = ImageGoodNameOfThis.begin(); iter != ImageGoodNameOfThis.end(); ++iter) {
        if (iter->second == 3){
            std::cout<< iter->first << " " <<endl;
        }
    }
    std::cout<< "Обьединение"<<endl;
    for (auto iter = ImageGoodNameOfThis.begin(); iter != ImageGoodNameOfThis.end(); ++iter) {
        if (iter->second == 2 || iter->second == 1 || iter->second == 3){
            std::cout<< iter->first << " " <<endl;
        }
    }

    std::cout<< "Вычитание"<<endl;
    for (auto iter = ImageGoodNameOfThis.begin(); iter != ImageGoodNameOfThis.end(); ++iter) {
        if (iter->second == 1 || iter->second == 2){
            std::cout<< iter->first << " " <<endl;
        }
    }
}


int main(){
//    createArrayOfWords();
//
//    unordered_map<int, int>HashWord;
vector<int>A = {1, 3, 5, 7, 11};
vector<int>B = {2, 4, 5, 7, 12};
    lessontask(A,B);

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