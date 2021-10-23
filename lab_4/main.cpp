#include <iostream>
#include "lab4.h"
#include <fstream>

class Timer {
    std::chrono::time_point<std::chrono::steady_clock> m_StartTime;
public:
    void Start(){
        m_StartTime = std::chrono::high_resolution_clock::now();
    }

    double_t GetDuration(){
        std::chrono::duration<double_t> duration = std::chrono::high_resolution_clock::now() - m_StartTime;
        return duration.count();
    }
};

DynamicArray<int> *genintRandomArray(int n){
    auto *A = new DynamicArray<int>;
    for (int i = 0; i < n; ++i) {
        A->append(rand() % 1000 - 1);
    }
    return A;
}
LinkedList<int> *genintRandomList(int n){
    auto *A = new LinkedList<int>;
    for (int i = 0; i < n; ++i) {
        A->append(rand() % 1000 - 1);
    }
    return A;
}

bool intcomp(int a, int b) {
    if (a > b){
        return true;
    } else {
        return false;
    }
}

void ListTestTime(int sorttype, int points, int times, string filename)
{
    Timer timer;
    double_t averagetime = 0;

    std::ofstream out; // поток для записи
    out.open(filename); // окрываем файл для записи
    if (out.is_open())
    {
        int testdata = 1000;
        for (int i = 0; i < points; ++i) {
            for (int j = 0; j < times; ++j) {
                auto A = new LinkedList<int>;
                for (int i = 0; i < testdata; ++i) {
                    A->append(rand() % 1000 - 1);
                }
                timer.Start();
                A->sort(&intcomp, sorttype);
                averagetime += timer.GetDuration();
                delete A;
            }
            out <<testdata <<" "<<averagetime/times <<endl;
            averagetime = 0;
            testdata += 10000;
        }
    }



}

void ArrayTestTime(int sorttype, int points, int times, string filename)
{
    Timer timer;
    double_t averagetime = 0;

    ofstream out("bubble.txt"); // поток для записи
    if (out.is_open())
    {
        cout << 1;
        int testdata = 1000;
        for (int i = 0; i < points; ++i) {
            for (int j = 0; j < times; ++j) {
                auto A = new DynamicArray<int>;
                for (int i = 0; i < testdata; ++i) {
                    A->append(rand() % 1000 - 1);
                }
                timer.Start();
                A->sort(&intcomp, sorttype);
                averagetime += timer.GetDuration();
                delete A;
            }
            out <<testdata <<endl;
            averagetime = 0;
            testdata += 10000;
        }
    }
    out.close();
}


int main() {
    cout<< "1"<< endl;
//    LinkedList<int> *A = genintRandomList(5);
//    LinkedList<int> B = *A;
//    cout<< B[0] << " ";
//    cout<< B[1] << " ";
//    cout<< B[2] << " ";
//    cout<< B[3] << " ";
//    cout<< B[4] << " " << endl;
//    B.sort(&intcomp, 3);
//    cout<< B[0] << " ";
//    cout<< B[1] << " ";
//    cout<< B[2] << " ";
//    cout<< B[3] << " ";
//    cout<< B[4] << " ";

ArrayTestTime(1, 2, 1, "bubble.txt");


    return 0;
}
