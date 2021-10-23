#include<iostream>
#include <string.h>
#include <ctime>
#include <chrono>
using namespace std;
// найти самую длинную последовательность средди ааббббаабабабабааа
void stringmax() {
    // найти самую длинную последовательность средди ааббббаабабабабааа
    string string1;
    cin >> string1;
    int k = 1;
    int kmax;
    char max;
    char current;
    current = string1[0];
    for (int i = 1; i < string1.size(); ++i) {
        if(current == string1[i]) {
            k++;
            if (k>=kmax){
                kmax = k;
                max = current;
            }
        } else {
            current = string1[i];
            k = 1;
        }
    }
    for (int i = 0; i < kmax; ++i) {
        cout << current;
    }
    cout << endl;
}

void insertionSort(int data[], int len) {
    int key = 0;
    int i = 0;
    for(int j = 1;j<len;j++){
        key = data[j];
        i = j-1;
        while(i>=0 && data[i]>key){
            data[i+1] = data[i];
            i = i-1;
            data[i+1]=key;
        }
    }
    for (int j = 0; j < len; ++j) {
        cout << data[j];
    }
    cout << endl;
}




struct Item {
    int data;
    struct Item *next;
};

struct List {
    Item *head;
    Item *tail;
};

void append(int data, List* list)  {
    Item *ptr = (Item *) calloc(1, sizeof(Item));
    if (!ptr) {
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (!list->head) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        list->tail->next = ptr;
        list->tail = ptr;
    }
    return;
}

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

void appendinsert(int data, List* list, int n)  {
    Item *ptr;
    Item *prev;
    ptr = list->head;
    prev = ptr;
    for (int i = 0; i < n; n--) {
        if(ptr->next){
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if (n == 0){
        Item *newptr = (Item *) calloc(1, sizeof(Item));
        newptr->data = data;
        if (ptr == list->head){
            list->head->next = newptr;
            newptr->next = list->head;
        }
        if(ptr == list->tail){
            list->tail->next = newptr;
            newptr->next = NULL;
        }else {
            newptr->next = ptr;
            prev->next = newptr;
        }


    }
    return;
}

void printlist(List* list){
    Item *ptr = list->head;
    while(ptr) {
        cout << ptr->data;
        ptr = ptr->next;
    }
    cout << endl;
}

void printArray(int* a, int n){
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout<<endl;
}

void printlistreserve(Item* item){
     if(item->next) printlistreserve(item->next);
     cout << item->data;
}

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node *node, int value) {
    if (node == NULL) {
        node = new Node();
        node->data = value;
        return node;
    } else if (value< node->data) {
        node->left = insert(node->left, value);
    } else if (value >= node->data) {
        node->right = insert(node->right, value);
    } return node;
}

void LNR(Node **node)
{
    if( *node != nullptr)
    {
        LNR( &( (*node)->left ) );
        cout << "data : " << (*node)->data << endl;

        LNR( &( (*node)->right) );
    }
}

int LNRcount(Node **node, int* result)
{
    int i1= 0 ,i2 = 0;
    if( *node != nullptr)
    {
        i1 += LNRcount( &( (*node)->left ),result );
        i2 += LNRcount( &( (*node)->right),result );
    }
    *result = i1+i2;
    if ((*node)){
        if ((*node)->right != NULL && (*node)->left != NULL){
            return 1;
        } else {
            return 0;
        }
    }

}

void binsearch(int n, int a[], int b){
    int middle;
    int left = 0;
    int right = n - 1;
    while (right - left > 1) {
        middle = (left + right) / 2;
        if (a[middle] >= b) {
            right = middle;
        }else {
            left = middle;
        }
    }
    if (a[right] == b) {
        cout << right<< endl;
    } else {
        cout << -1 << endl;
    }
}

void linesearch(int n, int a[], int b){
    for (int i = 0; i < n; ++i) {
        if (a[i] == b){
            cout << right<< endl;
        }
    }
    cout << -1 << endl;
};
int* genarray(int n){
    int* a = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100 - 1;
    }
    return a;
}

void choicesSort(int* array, int length) // сортировка выбором
{
    for (int repeat_counter = 0; repeat_counter < length; repeat_counter++)
    {
        int temp = array[0]; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length; element_counter++)
        {
            if (array[repeat_counter] > array[element_counter])
            {
                temp = array[repeat_counter];
                array[repeat_counter] = array[element_counter];
                array[element_counter] = temp;
            }
        }
    }
}

//функция, сливающая массивы
void Merge(int *A, int first, int last) {
    int middle, start, final, j;
    int *mas = new int[100];
    middle = (first + last) / 2;  //вычисление среднего элемента
    start = first;                //начало левой части
    final = middle + 1;           //начало правой части
    for (j = first; j <= last; j++)  //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        } else {
            mas[j] = A[final];
            final++;
        }
    //возвращение результата в список
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
};
//рекурсивная процедура сортировки
void MergeSort(int *A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);  //сортировка левой части
        MergeSort(A, (first + last) / 2 + 1, last);  //сортировка правой части
        Merge(A, first, last);  //слияние двух частей
    }
}

//int main() {
////    stringmax();
////
////    int a[] = {4,3,2,6,8,5};
////    insertionSort(a,6);
//
////    List* list = (List*) calloc(1, sizeof(List));
////    list->head = NULL;
////    list->tail = NULL;
////
////    append(1, list);
////    append(2, list);
////    append(3, list);
////    append(4, list);
////    append(5, list);
////
////    appendinsert(9,list,3);
////
////    printlist(list);
////    printlistreserve(list->head);
//
////Node *node = (Node*)calloc(1, sizeof (Node));
////node = insert(node, 3);
////node = insert(node, 2);
////node = insert(node, 1);
////node = insert(node, 4);
////
////LNR(&node);
////int* result = (int*)calloc(1, sizeof(int));
////LNRcount(&node, result);
////cout << *result << endl;
////free(node);
//
//int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//int b = 4;
//
//    int* c = (int*)calloc(20, sizeof(int));
//    c = genarray(20);
//    printArray(c, 20);
//    choicesSort(c,20);
//    printArray(c, 20);
//
//    int* d = (int*)calloc(20, sizeof(int));
//    d = genarray(20);
//    printArray(d, 20);
//
//    printArray(d, 20);
//
//    Timer ti;
//    ti.Start();
//binsearch(10, a, b);
//MergeSort(d,0,19);
//cout<< ti.GetDuration() << endl;
//
//
//
//
//
//return 0;
//}
