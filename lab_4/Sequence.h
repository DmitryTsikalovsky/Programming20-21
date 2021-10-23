

#ifndef CPP_SEQUENCE_H
#define CPP_SEQUENCE_H

// для простых типов передавать как конст не надо
//по ссылке если внутри функци
// указатель и ссылка
// у ссылки нет нулла
//указатель на указатель адрес на адрес
// арифметика указателей есть
//попробовать мув семантику в сортивках
// написать сортировку выбором САМОСТОЯТЕЛЬНО ПРОВЕРЯТ
// сделать приватными внутренние функции
// посмотреть про итераторы
// созавать копии данных для сортирови и передавать в лист и в масссив одинаково
template<class T> class sequence {
public:
    virtual T& operator[](const int index) = 0; // Переопределение квадратных скобок необходимо для получения элемента по индексу способом Class[index]
    virtual void set(int index, T value) = 0; // Занесение значения по заданному индексу
    virtual void subSequence(const int startIndex, const int endIndex,  sequence<T>* Sub) = 0; // Выделение подпоследовательности по заданным индексам, путём создания нового объёкта класса и дальнейшим копированием в него необходимых элементов
    virtual void concat(sequence<T>* Sub) = 0; // Объёдинение данных двух одинаковых классов
    virtual void deleteOne(int index) = 0; // Удаление элемента по Заданному индексу
    virtual void map(T (*function)(T data, int option), int option) = 0; // Функция map, Применяющая данную ей функцию для каждого элмента
    virtual void where(bool (*function)(T data, int option), int option) = 0;// Функция where, с помощью переданной в неё функции фильтрующая элементы, удаляя те, для которых из функции возвращён false
    virtual void append(T data) = 0; // Добавление нового элемента в конец
    virtual void prepend(T data) = 0; // Добавление нового в начало
    virtual T getLast() = 0; // Получение данных, находящихся в последнем элементе
    virtual int getSize() = 0; // Получение количества заполненных элементов
    virtual T getFirst() = 0;// Получение данных, находящихся в первом элементе

    virtual void sort(bool (*function)(T data1, T data2), int type) = 0; // Сортировка
    // передавать конст сыллку чтобы не создавать копии
    //посмотреть enum
    // 1- bubble 2 - insert 3 - merge 4 - quick

    virtual ~sequence() = 0;
};
// выражение, необходимое для корректного создания виртуального деструктора
template<class T> sequence<T>::~sequence(){};
#endif //CPP_SEQUENCE_H
