//------------------------------------------------------------------------------
/*
This file is part of algorithm: https://github.com/gongzhihui/algorithm
Copyright (c) 2019 GongZhihui. blog: http://www.acshy.com
Permission to use, copy, modify, and/or distribute this software for any
purpose  with  or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.
THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#include "algorithm.h"

namespace algorithm
{

int BinarySearch(int key, int *array, int len)
{
    int left = 0;
    int right = len - 1; 
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

void SelectionSort(int *array, int len)
{
    int min = 0;
    for(int i = 0; i < len; ++i)
    {
        min = i;
        for(int j = i + 1; j < len; ++j)
        {
            if(array[min] > array[j])
            {
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}

void InsertSort(int *array, int len)
{
    for(int i = 1; i < len; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void ShellSort(int *array, int len)
{
    //step 增量
    int step = len / 2;
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
            for(int i = step + x; i < len; i += step)
            {
                //j = step*0 + x = x;
                for(int j = x; j < i; j += step)
                {
                    if(array[i] < array[j])
                    {
                        int temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
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