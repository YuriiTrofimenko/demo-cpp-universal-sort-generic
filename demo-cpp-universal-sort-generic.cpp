// demo-cpp-universal-sort-generic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
using namespace std;

const int INT_ARRAY_SIZE = 12;
void bubbleSort(int integers[], int size, int(*compare)(int, int));

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

int main()
{
    int ints[] = { 1, 20, 20, 42, -80, 0, 10, 20, 20, 20, 5, 20 };
    /**
    * Вызов функция сортировки
    * с передачей ей ссылки на функцию сравнения intCompareASC
    */
    bubbleSort(ints, INT_ARRAY_SIZE, intCompareASC);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        std::cout << ints[i] << " ";
    }
    std::cout << endl;
    /**
    * Вызов функция сортировки с передачей ей ссылки на функцию сравнения intCompareDESC
    */
    bubbleSort(ints, INT_ARRAY_SIZE, intCompareDESC);
    for (int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        std::cout << ints[i] << " ";
    }
}
/**
* Реализация функции сортировки с передачей ей ссылки на функцию сравнения, которая должна принимать два параметра целого типа и возвращать результат целого типа
*/
void bubbleSort(int integers[], int size, int(*compare)(int, int))
{
    bool sorted = false;
    do
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            if (compare(integers[i], integers[i + 1]) > 0)
            {
                int temp = integers[i];
                integers[i] = integers[i + 1];
                integers[i + 1] = temp;
                sorted = false;
            }
        }
    } while (!sorted);
}
