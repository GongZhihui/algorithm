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

#include "SeqList.h"
#include <iostream>

namespace algorithm
{

namespace c
{

/*操作结果：构造一个空的线性表*/
void seq_list_init(seq_list *L)
{
    if (L == NULL)
        return;
    L->length = 0;
    memset(L->data, 0, SEQ_LIST_MAX);
}

data_type *seq_list_begin(seq_list *L)
{
    return &L->data[0];
}

data_type *seq_list_end(seq_list *L)
{
    return &L->data[L->length];
}

data_type * seq_list_back(seq_list *L)
{
    return &L->data[L->length-1];
}
data_type * seq_list_front(seq_list *L)
{
    return seq_list_begin(L);
}

/*尾插*/
void seq_list_push_back(seq_list *L, data_type e)
{
    seq_list_insert_element(L, seq_list_length(L), e);
}
/*删除最后一个*/
void seq_list_pop_back(seq_list *L)
{
    int e = 0;
    seq_list_delete_element(L, seq_list_length(L) - 1, &e);
}
/*头插*/
void seq_list_push_front(seq_list *L, data_type e)
{
    seq_list_insert_element(L, 0, e);
}
/*删除第一个元素*/
void seq_list_pop_front(seq_list *L)
{
    int e = 0;
    seq_list_delete_element(L, 0, &e);
}


void seq_list_show(seq_list *L)
{
    for (int i = 0; i < L->length; i++)
    {
        std::cout << L->data[i] << " ";
    }

    std::cout << " | " << L->length << std::endl;
}

/*初始条件：线性表L已存在*/
/*操作结果：将L重置为空表*/
void seq_list_clear(seq_list *L)
{
    seq_list_init(L);
}

/*初始条件：线性表L已存在*/
/*操作结果：若L为空表，则返回TRUE，否则返回FALSE*/
bool seq_list_is_empty(seq_list *L)
{
    return L->length == 0;
}

/*初始条件：线性表L已存在*/
/*操作结果：返回L中数据元素个数*/
int seq_list_length(seq_list *L)
{
    return L->length;
}

/*初始条件：线性表L已存在,1≤i≤LIST_SIZE*/
/*操作结果：用e返回L中第i个数据元素的值*/
data_type *seq_list_get_element(seq_list *L, int pos)
{
    if (pos < 0 || pos > L->length - 1)
        return NULL;
    return &L->data[pos];
}

/*初始条件：线性表L已存在*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
data_type *seq_list_insert_element(seq_list *L, int pos, data_type e)
{
    if (pos < 0 || pos > L->length)
        return NULL;
    if (pos == L->length)
    {
        L->data[pos] = e;
        L->length += 1;
        return seq_list_end(L);
    }

    for (int i = L->length; i >= pos + 1; i--)
    {
        L->data[i] = L->data[i - 1];
    }
    L->data[pos] = e;
    L->length += 1;
    return &L->data[pos + 1];
}

/*初始条件：线性表L已存在*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
data_type *seq_list_delete_element(seq_list *L, int pos, data_type *e)
{
    if (pos < 0 || pos > L->length)
        return NULL;
    if (pos == L->length)
        return seq_list_end(L);

    *e = L->data[pos];
    for (int i = pos; i < L->length - 1; i++)
    {
        L->data[i] = L->data[i + 1];
    }
    L->length -=1;
    return &L->data[pos];
}

} // namespace c

namespace cxx
{

} // namespace cxx

} // namespace algorithm