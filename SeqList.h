#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include <cstring>

namespace algorithm
{

namespace c
{

#define SEQ_LIST_MAX 50

typedef int date_type;

typedef struct seq_list_t
{
    date_type data[SEQ_LIST_MAX];
    int length;
} seq_list, *seq_list_ptr;

void show_seq_list(seq_list *L);

/*操作结果：构造一个空的线性表*/
void init_seq_list(seq_list *L);

/*初始条件：线性表L已存在*/
/*操作结果：将L重置为空表*/
void clear_seq_list(seq_list *L);

/*初始条件：线性表L已存在*/
/*操作结果：若L为空表，则返回TRUE，否则返回FALSE*/
bool seq_list_is_empty(seq_list *L);

/*初始条件：线性表L已存在*/
/*操作结果：返回L中数据元素个数*/
int get_seq_list_length(seq_list *L);

/*初始条件：线性表L已存在,1≤i≤LIST_SIZE*/
/*操作结果：用e返回L中第i个数据元素的值*/
bool get_seq_list_element(seq_list *L, int pos, date_type *e);

/*初始条件：线性表L已存在*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
bool insert_seq_list_element(seq_list *L, int pos, date_type e);

/*初始条件：线性表L已存在*/
/*操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
bool delete_seq_list_element(seq_list *L, int pos, date_type e);

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
