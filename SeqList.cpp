#include "SeqList.h"
#include <iostream>

namespace algorithm
{

namespace c
{

/*操作结果：构造一个空的线性表*/
void init_seq_list(seq_list *L)
{
    if(L == NULL) 
        return;
    L->length = 0;
    memset(L->data, 0, SEQ_LIST_MAX);
}

void show_seq_list(seq_list *L)
{
    for(int i = 0; i<L->length; i++)
    {
        std::cout<< L->data[i]<< " ";
    }

    std::cout<<" | " << L->length <<std::endl;
}

/*初始条件：线性表L已存在*/
/*操作结果：将L重置为空表*/
void clear_seq_list(seq_list *L)
{
    init_seq_list(L);
}

/*初始条件：线性表L已存在*/
/*操作结果：若L为空表，则返回TRUE，否则返回FALSE*/
bool seq_list_is_empty(seq_list *L)
{
    return L->length == 0;
}

/*初始条件：线性表L已存在*/
/*操作结果：返回L中数据元素个数*/
int get_seq_list_length(seq_list *L)
{
    return L ? L->length : -1;
}

/*初始条件：线性表L已存在,1≤i≤LIST_SIZE*/
/*操作结果：用e返回L中第i个数据元素的值*/
bool get_seq_list_element(seq_list *L, int pos, date_type *e)
{
    if(!L || pos < 0)
        return false;
    if(pos > L->length)
        return false;
    *e = L->data[pos];
    return true;
}

/*初始条件：线性表L已存在*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
bool insert_seq_list_element(seq_list *L, int pos, date_type e)
{
    if(!L || pos < 0 || L->length == SEQ_LIST_MAX)
        return false;
    if(pos > L->length)
        return false;
    if(pos == L->length) 
    {
        L->data[pos] = e;
        L->length += 1;
        return true;
    }
    std::cout<< "======" << std::endl;
    // 5     len 1
    for(int i = L->length; i == pos; i--)
    {
        L->data[i] = L->data[i - 1];
        std::cout<< "--"<<L->data[i]<<"--" <<L->data[i - 1]<<std::endl;
    }
    L->data[pos] = e;
    L->length += 1;
    return true;
}

/*初始条件：线性表L已存在*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
bool delete_seq_list_element(seq_list *L, int pos, date_type e)
{
    return false;
}

} // namespace c

namespace cxx
{

} // namespace cxx

} // namespace algorithm