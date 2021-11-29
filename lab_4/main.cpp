#include <iostream>
#include "lab4.h"
#include <fstream>
#include "Sort.h"
#include <chrono>
#include <ctime>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
public:
    void Start(){
        m_StartTime = chrono::high_resolution_clock::now();
    }

    double_t GetDuration(){
        chrono::duration<double_t> duration = chrono::high_resolution_clock::now() - m_StartTime;
        return duration.count();
    }
};

//class Timer
//{
//public:
//    void start()
//    {
//        m_StartTime = std::chrono::system_clock::now();
//        m_bRunning = true;
//    }
//
//    void stop()
//    {
//        m_EndTime = std::chrono::system_clock::now();
//        m_bRunning = false;
//    }
//
//    double elapsedMilliseconds()
//    {
//        std::chrono::time_point<std::chrono::system_clock> endTime;
//
//        if(m_bRunning)
//        {
//            endTime = std::chrono::system_clock::now();
//        }
//        else
//        {
//            endTime = m_EndTime;
//        }
//
//        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
//    }
//
//    double elapsedSeconds()
//    {
//        return elapsedMilliseconds() / 1000.0;
//    }
//
//private:
//    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
//    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
//    bool                                               m_bRunning = false;
//};
class Animal {
public:
    int age;
    string name;
};

int *genintRandomArray(int n){
    int *A = new int[n];
    for (int i = 0; i < n; ++i) {
        A[i] = (rand() % 1000 - 1);
    }
    return A;
}

bool Animalcomp(const Animal& a, const Animal& b) {

    if (a.age > b.age){
        return true;
    } else {
        return false;
    }
}

bool intcomp(const int& a, const int& b) {
    if (a < b){
        return true;
    } else {
        return false;
    }
}

//void ListTestTime(int sorttype, int points, int times, string filename)
//{
//    Timer timer;
//    double_t averagetime = 0;
//
//    std::ofstream out; // поток для записи
//    out.open(filename); // окрываем файл для записи
//    if (out.is_open())
//    {
//        int testdata = 1000;
//        for (int i = 0; i < points; ++i) {
//            for (int j = 0; j < times; ++j) {
//                auto A = new LinkedList<int>;
//                for (int i = 0; i < testdata; ++i) {
//                    A->append(rand() % 1000 - 1);
//                }
//                timer.Start();
////                A->sort(&intcomp, sorttype);
//                averagetime += timer.GetDuration();
//                delete A;
//            }
//            out <<testdata <<" "<<averagetime/times <<endl;
//            averagetime = 0;
//            testdata += 10000;
//        }
//    }
//
//
//
//}

void TestTime(int sortType, int times) {
    Timer timerVector;
    Timer timerList;
    double_t timeVector;
    double_t timeList;
    cout << "Elements  Vector  List" << endl;
    for (int elements  = 100000; elements  <= 100000; elements+=1000 ) {
        timeVector = 0;
        timeList = 0;
        for (int i = 0; i < times; ++i) {
            vector<int> Vector(elements);
            list <int> mylist;
            int a;
            for (int j = 0; j < elements; ++j) {
                a = rand() % 10000;
                Vector[j] = a;
                mylist.push_back(a);
            }

            timerVector.Start();
            std::sort(Vector.begin(), Vector.end(), &intcomp);
            timeVector += timerVector.GetDuration();



        }
        timeVector = timeVector/times;
        cout << elements << " " << timeVector << " " <<endl;
    }


}
int main() {
    TestTime(3, 5);
//    list <int> mylist;
//
//    for (int i = 0; i < 10; i++) {
//        mylist.push_back(rand() % 1000 - 1); // добавили 10 элементов
//    }
//
//    copy (mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
//    cout << endl;
//    mylist.sort();
//    copy (mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
//    cout << endl;
//
//    mylist.unique();  // удалили все дубликаты
//    list <int> :: iterator it;
//    cout<< "Бабл"<< endl;
//
//    for (it = mylist.begin(); it != mylist.end(); it++) {
//        cout << (*it) << " ";
//    }
//
//    for (it = mylist.begin(); it != mylist.end(); it++) {
//        cout << (*it) << " ";
//    }
//
//    for (int j = 0; j < 10; ++j) {
//        cout<< Vector[j] << endl;
//
//    }



    cout<< "Бабл"<< endl;
//    std::sort(Vector.begin(),  Vector.end(), &intcomp);
//    for (int j = 0; j < 10; ++j) {
//        cout<< Vector[j] << endl;
//
//    }

//    TestTime(1, 2);
//    cout<< "Слиянием"<< endl;
//    TestTime(3, 3);
//    cout<< "Быстрая"<< endl;
//    TestTime(4, 3);

//    Animal *a = genAnimalRandomArray(10);
//    for (int i = 0; i < 10; ++i) {
//        cout<< a[i].age<< " "<< a[i].name<< endl;
//    }
//    cout<< "СОРТИРОВКА"<< endl;
//    double_t timeArray;
//    DynamicArray<Animal> Array(a, 10);
//    Timer timerArray;
//    timerArray.Start();
//    Sort<DynamicArray<Animal>, Animal>::sort(&Array,&Animalcomp,3);
//    timeArray = timerArray.GetDuration();
//    for (int i = 0; i < 10; ++i) {
//        cout<< Array[i].age<< " "<< Array[i].name<< endl;
//    }


    return 0;
}
