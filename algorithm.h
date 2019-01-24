#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <array>
#include <vector>
#include <iostream>

namespace algorithm
{

// ------------------- 二分查找 -------------------------------

// 二分查找，待查找的数组必须是有序的，可用std::sort();

/** 模板类型T::value_type需要重载 operator< 和 operator>
    class T 应为std::vector<VT> 或者 std::array<VT, MAX>等
    class ValueType = VT = typename T::value_type
 */
template<class T, class ValueType = typename T::value_type>
std::size_t BinarySearch(const ValueType &key, const T &array);

// c/c++指针版本
int BinarySearch(int key, int *array, int len);

// ------------------- 选择排序 -------------------------------

/** 模板类型T::value_type需要重载 operator< 和 operator>
    class T 应为std::vector<VT> 或者 std::array<VT, MAX>等
 */
template<class T>
void SelectionSort(T &array);

// c/c++指针版本
void SelectionSort(int *array, int len);

//-------------------- 插入排序 -------------------------------

/** 模板类型T::value_type需要重载 operator< 和 operator>
    class T 应为std::vector<VT> 或者 std::array<VT, MAX>等
 */
template<class T>
void InsertSort(T &array);
// c/c++指针版本
void InsertSort(int *array, int len);

//-------------------- 希尔排序 -------------------------------

/** 对应关系      
            i = step * y + x
            i            对应 插入排序第一层循环的i
            step         希尔排序的增量
            x            对应的是某个增量step下的第x个组
            y            对应的是某个增量step下的第x个组的地y个元素 

            其实就是 数组下标的映射  
            step =  5 时
            xy| 0   1   2
            ---------------------
            0 | 0   5   10      
            1 | 1   6   11    
            1 | 2   7        
            3 | 3   8         
            4 | 4   9   
*/

/** 模板类型T::value_type需要重载 operator< 和 operator>
    class T 应为std::vector<VT> 或者 std::array<VT, MAX>等
 */
template<class T>
void ShellSort(T &array);
// c/c++指针版本
void ShellSort(int *array, int len);

//------------------------------------------------------------
template<class T, class ValueType>
std::size_t BinarySearch(const ValueType &key, const T &array)
{
    int left = 0;
    int right = array.size() - 1;
    while(left <= right)
    {
        int mid = (right + left) / 2;
        if(key < array[mid])
            right = mid - 1;
        else if(key > array[mid])
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

template<class T>
void SelectionSort(T &array)
{
    int min = 0;
    for(int i = 0; i < array.size(); ++i)
    {
        min = i;
        for(int j = i + 1; j < array.size(); ++j)
        {
            if(array[min] > array[j])
            {
                min = j;
            }
        }
        std::swap(array[min], array[i]);
    }
}

template<class T>
void InsertSort(T &array)
{
    for(int i = 1; i < array.size(); ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(array[i] < array[j])
            {
                std::swap(array[i], array[j]);
            }
        }
    }
}

template<class T>
void ShellSort(T &array)
{
    //step 增量
    int step = array.size() / 2;
    // 增量到1，执行完后退出循环
    while(step > 0)
    {
        // 一共有0-step个组需要进行插入排序
        for(int x = 0; x < step; ++x)
        {
        /**
        {   这一段 是 插入排序 对应关系 i = step * y + x
        */
            //  i = step*1 + x = step + x;
            for(std::size_t i = step + x; i < array.size(); i += step)
            {
                //j = step*0 + x = x;
                for(std::size_t j = x; j < i; j += step)
                {
                    if(array[i] < array[j])
                    {
                        std::swap(array[i], array[j]);
                    }
                }
            }
        /**  
        }
        */
        }
        // 此处选取其他好的计算增量的算法
        step = step / 2;
    }
}

} // !algorithm
#endif //!ALGORITHM_H