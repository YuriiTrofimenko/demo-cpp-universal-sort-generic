// demo-cpp-universal-sort-generic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
using namespace std;

const int INT_ARRAY_SIZE = 12;
template <typename T> void bubbleSort(T items[], int size, int(*compare)(T, T));
template <typename T> void bubbleSort(T items[], int size);

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

int intArrayCompareASC(int x[], int y[]) {
    return y[0] < x[0] ? 1 : -1;
}

int foo1(int x, int y);
void foo2(int x, int y, int result[]);
void foo3(int x, int y, int & sumResult, int & subResult, int & multResult);

template <typename T1, typename T2> void foo(T1 x, T2 y, int n);

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int ints[] = { 1, 20, 20, 42, -80, 0, 10, 20, 20, 20, 5, 20 };
    double doubles[] = { 1.5, 20.0, 20.01, 42.999, -80.54, 0.1, 10.0, 20.2, 20.3, 20.0, 5.5, 20.0 };
    char characters[] = { 'y', 'b',	'c',	'd',	'a', 'e',	'f',	'h',	'i',	'j',	'k',	'l',	'm',	'n',	'o',	'p',	'q',	'r',	's',	't',	'u',	'v',	'w',	'x',		'z',	'g' };
    /**
    * Вызов функции сортировки
    * с передачей ей ссылки на функцию сравнения intCompareASC
    */
    bubbleSort(ints, INT_ARRAY_SIZE, intCompareASC);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        std::cout << ints[i] << " ";
    } 
    std::cout << endl;
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

    // foo(12, 'A', 5);
    // foo(30.8, 0.99, 5);

    /* int x = 10;
    int y = x;
    x++;
    foo(x, y, 1);
    int* xPointer = &x;
    cout << *xPointer << endl;
    cout << xPointer << endl;
    (*xPointer)++;
    cout << x << endl; */
    // *xPointer++;
    // cout << xPointer << endl;
    // cout << *xPointer << endl;

    /* cout << foo1(10, 20);
    cout << endl;
    int result[3];
    foo2(2, 3, result);
    for (int i = 0; i < 3; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl; */

    /* int sumResult = 0, subResult = 0, multResult = 0;
    foo3(2, 3, sumResult, subResult, multResult);
    cout << sumResult << " " << subResult << " " << multResult << endl; */

    /* bubbleSort(characters, INT_ARRAY_SIZE);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        std::cout << characters[i] << " ";
    }
    std::cout << endl; */

    /* int coords[4][3] = {{4, 20, 25}, {1, 0, 0}, {3, 15, 20}, {2, 10, 20}};

    bubbleSort(coords, INT_ARRAY_SIZE);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        // std::cout << coords[i] << " ";
        for (int j = 0; j < 3; j++)
        {
            std::cout << coords[i][j] << " ";
        }
        std::cout << "; ";
    }
    std::cout << endl;

    // std::cout << 0.3 - 0.2 << endl;
    // printf("%.40f", 0.3 - 0.2); */
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

template <typename T> void bubbleSort(T items[], int size)
{
    bool sorted = false;
    do
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            // if (items[i] - items[i + 1] > 0)
            if (intArrayCompareASC(items[i], items[i + 1]) > 0)
            {
                swap(items[i], items[i + 1]);
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

int foo1(int x, int y)
{
    return x + y;
}

void foo2(int x, int y, int result [])
{
    result[0] = x + y;
    result[1] = x - y;
    result[2] = x * y;
}

void foo3(int x, int y, int & pSumResult, int & pSubResultPoiu, int & pMultResult)
{
    pSumResult = x + y;
    pSubResultPoiu = x - y;
    pMultResult = x * y;
}
