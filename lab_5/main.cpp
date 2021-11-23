#include <iostream>
#include "HashTable.h"
#include <string>

int hashFunction(const std::string& s, int table_size, int key)
{
    int hash_result = 0;
    for (int i = 0; s[i] != s[s.length()]; ++i)
        hash_result += key * s[i];
    return hash_result % table_size;;
}

void printString(const std::string &data){
    std::cout<< data;
}

int main(){
    HashTable<std::string, int> testTable(10, 5,&hashFunction);
    std::string str  = "John";
    std::string str1  = "Jame";
    std::string str2  = "David";
    std::string str3  = "David";
    testTable.add(str);
    testTable.add(str2);
    testTable.add(str1);
//    testTable.remove(str3);
    testTable.print(&printString);
}