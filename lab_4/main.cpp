#include <iostream>
#include "lab4.h"
#include <fstream>
#include "Sort.h"

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

int *genintRandomArray(int n){
    int *A = new int[n];
    for (int i = 0; i < n; ++i) {
        A[i] = (rand() % 1000 - 1);
    }
    return A;
}

bool intcomp(const int& a, const int& b) {
    if (a > b){
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

//void ArrayTestTime(int sorttype, int points, int times, string filename)
//{
//    Timer timer;
//    double_t averagetime = 0;
//
//    ofstream out("bubble.txt"); // поток для записи
//    if (out.is_open())
//    {
//        cout << 1;
//        int testdata = 1000;
//        for (int i = 0; i < points; ++i) {
//            for (int j = 0; j < times; ++j) {
//                auto A = new DynamicArray<int>;
//                for (int i = 0; i < testdata; ++i) {
//                    A->append(rand() % 1000 - 1);
//                }
//                timer.Start();
////                A->sort(&intcomp, sorttype);
//                averagetime += timer.GetDuration();
//                delete A;
//            }
//            out <<testdata <<endl;
//            averagetime = 0;
//            testdata += 10000;
//        }
//    }
//    out.close();
//}


int main() {
    cout<< "1"<< endl;

    DynamicArray<int> Array(genintRandomArray(10), 10);
        cout<< Array[0]<< " ";
        cout<< Array[1] << " ";
        cout<< Array[2] << " ";
        cout<< Array[3] << " ";
        cout<< Array[4]<< " ";
        cout<< Array[5] << " ";
        cout<< Array[6] << " ";
        cout<< Array[7] << " ";
        cout<< Array[8] << " ";
        cout<< Array[9] << " " << endl;

    Sort<DynamicArray<int>, int>::sort(&Array,&intcomp,4);
    cout<< Array[0]<< " ";
    cout<< Array[1] << " ";
    cout<< Array[2] << " ";
    cout<< Array[3] << " ";
    cout<< Array[4]<< " ";
    cout<< Array[5] << " ";
    cout<< Array[6] << " ";
    cout<< Array[7] << " ";
    cout<< Array[8] << " ";
    cout<< Array[9] << " " << endl;
//    LinkedList<int> B = *A;

//    B.sort(&intcomp, 3);
//    cout<< B[0] << " ";
//    cout<< B[1] << " ";
//    cout<< B[2] << " ";
//    cout<< B[3] << " ";
//    cout<< B[4] << " ";

//ArrayTestTime(1, 2, 1, "bubble.txt");


    return 0;
}
