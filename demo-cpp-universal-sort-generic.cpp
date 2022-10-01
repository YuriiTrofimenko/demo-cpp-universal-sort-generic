// demo-cpp-universal-sort-generic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
using namespace std;

const int INT_ARRAY_SIZE = 12;
template <typename T> void bubbleSort(T items[], int size, int(*compare)(T, T));

/**
* Функция сравнения двух целых чисел для сортировки по возрастанию
*/
int intCompareASC(int x, int y) {
    return x - y;
}
/**
* Функция сравнения двух целых чисел для сортировки по убыванию
*/
int intCompareDESC(int x, int y) {
    return y - x;
}
/**
* Функция сравнения двух дробных чисел для сортировки по возрастанию
*/
int doubleCompareASC(double x, double y) {
    return y < x ? 1 : -1;
}
/**
* Функция сравнения двух дробных чисел для сортировки по убыванию
*/
int doubleCompareDESC(double x, double y) {
    return x < y ? 1 : -1;
}

template <typename T1, typename T2> void foo(T1 x, T2 y, int n);

int main()
{
    int ints[] = { 1, 20, 20, 42, -80, 0, 10, 20, 20, 20, 5, 20 };
    double doubles[] = { 1.5, 20.0, 20.01, 42.999, -80.54, 0.1, 10.0, 20.2, 20.3, 20.0, 5.5, 20.0 };
    /**
    * Вызов функции сортировки
    * с передачей ей ссылки на функцию сравнения intCompareASC
    */
    /* bubbleSort(ints, INT_ARRAY_SIZE, intCompareASC);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        std::cout << ints[i] << " ";
    } 
    std::cout << endl; */
    /**
    * Вызов функции сортировки
    * с передачей ей ссылки на функцию сравнения doubleCompareASC
    */
    /* bubbleSort(doubles, INT_ARRAY_SIZE, doubleCompareASC);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        std::cout << doubles[i] << " ";
    }
    std::cout << endl << endl; */
    /**
    * Вызов функции сортировки с передачей ей ссылки на функцию сравнения intCompareDESC
    */
    /* bubbleSort(ints, INT_ARRAY_SIZE, intCompareDESC);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        std::cout << ints[i] << " ";
    }
    std::cout << endl; */
    /**
    * Вызов функции сортировки
    * с передачей ей ссылки на функцию сравнения doubleCompareDESC
    */
    /* bubbleSort(doubles, INT_ARRAY_SIZE, doubleCompareDESC);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        std::cout << doubles[i] << " ";
    }
    std::cout << endl; */

    foo(12, 'A', 5);
    foo(30.8, 0.99, 5);
}
/**
* Реализация функции сортировки с передачей ей ссылки на функцию сравнения, которая должна принимать два параметра целого типа и возвращать результат целого типа
*/
template <typename T> void bubbleSort(T items[], int size, int(*compare)(T, T))
{
    bool sorted = false;
    do
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            if (compare(items[i], items[i + 1]) > 0)
            {
                T temp = items[i];
                items[i] = items[i + 1];
                items[i + 1] = temp;
                sorted = false;
            }
        }
    } while (!sorted);
}

template <typename T1, typename T2> void foo(T1 x, T2 y, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "x = " << x << "; y = " << y << endl;
    }
}