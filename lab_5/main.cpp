#include <iostream>
#include "HashTable.h"
#include <string>

int hashFunction(const std::string& s, int table_size, int key)
{
    int hash_result = 0;
    for (int i = 0; s[i] != s.size(); ++i)
        hash_result = (key * hash_result + s[i]) % table_size;
    hash_result = (hash_result * 2 + 1) % table_size;
    return hash_result;
}

void printString(const std::string &data){
    std::cout<< data << " ";
}

int main(){
    HashTable<std::string> testTable(10, 5,&hashFunction);
    std::string str  = "John";
    std::string str1  = "Jame";
    testTable.add(str);
    testTable.add(str1);
    testTable.print(&printString);
}