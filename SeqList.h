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

#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include <cstring>

namespace algorithm
{

namespace c
{

#define SEQ_LIST_MAX 50

typedef int data_type;

typedef struct seq_list_t
{
    data_type data[SEQ_LIST_MAX];
    int length;
} seq_list, *seq_list_ptr;

void seq_list_show(seq_list *L);

data_type * seq_list_end(seq_list *L);
data_type * seq_list_begin(seq_list *L);

data_type * seq_list_back(seq_list *L);
data_type * seq_list_front(seq_list *L);

/*尾插*/
void seq_list_push_back(seq_list *L);
/*删除最后一个*/
void seq_list_pop_back(seq_list *L);
/*头插*/
void seq_list_push_front(seq_list *L);
/*删除第一个元素*/
void seq_list_pop_front(seq_list *L);

/*操作结果：构造一个空的线性表*/
void seq_list_init(seq_list *L);

/*初始条件：线性表L已存在*/
/*操作结果：将L重置为空表*/
void seq_list_clear(seq_list *L);

/*初始条件：线性表L已存在*/
/*操作结果：若L为空表，则返回TRUE，否则返回FALSE*/
bool seq_list_is_empty(seq_list *L);

/*初始条件：线性表L已存在*/
/*操作结果：返回L中数据元素个数*/
int seq_list_length(seq_list *L);

/*初始条件：线性表L已存在,1≤i≤LIST_SIZE*/
/*操作结果：用e返回L中第i个数据元素的值*/
data_type * seq_list_get_element(seq_list *L, int pos);

/*初始条件：线性表L已存在*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1, 并返回下一个位置的指针*/
data_type * seq_list_insert_element(seq_list *L, int pos, data_type e);

/*初始条件：线性表L已存在*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1, 并返回该位置的当前值的指针*/
data_type * seq_list_delete_element(seq_list *L, int pos, data_type *e);

} // namespace c

namespace cxx
{

template <class T, int Max>
class SequenceList
{
  public:
    using DataType = T;

    SequenceList()
        : mLength(0)
    {
        memset(mData, 0, Max);
    }

    bool empty() const { return mLength == 0; }

    void clear()
    {
        memset(mData, 0, mLength);
        mLength = 0;
    }

    int length() const { return mLength; }

    bool insert(int pos, DataType &&e)
    {
        return false;
    }

    bool get(int pos, DataType &e)
    {
        return false;
    }

    bool delet(int pos)
    {
        return false;
    }

    const DataType &cfront() const { return mData[0]; }
    DataType &front() { return mData[mLength]; }

    const DataType &cback() const { return mData[0]; }
    DataType &back() { return mData[mLength]; }

  private:
    DataType mData[Max];
    int mLength;
};

} // namespace cxx

} // namespace algorithm

#endif // !SEQ_LIST_H
