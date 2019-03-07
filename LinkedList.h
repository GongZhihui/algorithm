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

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>

namespace algorithm
{

namespace c
{

/**单链表*/
typedef int data_type;
typedef struct single_list
{
    data_type value;
    single_list *next;
} single_list, *single_list_ptr;
typedef single_list_ptr single_list_node;
typedef single_list_ptr single_list_position;

/**双向链表*/
typedef struct list
{
    data_type value;
    list *prev;
    list *next;
} list, *list_ptr, *position;
typedef list_ptr list_node;
typedef list_ptr list_position;

// 初始化
void single_list_init(single_list *L);
void list_init(list *L);

// 长度
int single_list_length(single_list *L);
int list_length(list *L);

// 是否为空
bool single_list_is_empty(single_list *L);
bool list_is_empty(list *L);

// 输出链表
void single_list_show(single_list *L);
void list_show(list *L);

// 指定位置后插入
void single_list_insert_element(single_list *L, 
    single_list_position pos, data_type e);
void list_insert_element(list *L,
    list_position pos, data_type e);

// 头插
void single_list_push_front(single_list *L, data_type e);
void list_push_front(list *L, data_type e);

// 尾插
void single_list_push_back(single_list *L, data_type e);
void list_push_back(list *L, data_type e);

// 返回指定元素的第一个节点
single_list_node single_list_find_node(single_list *L, data_type e);
list_node list_find_node(list *L, data_type e);

// 删除指定的节点
void single_list_erase_node(single_list *L, single_list_node node);
void list_erase_node(list *L, list_node node);

// 反转链表
void single_list_reverse(single_list *L);
void list_reverse(list *L);

} // namespace c

namespace cxx
{

/**单链表*/
template <class T>
class SingleList
{
public:
    using value_type = T;
    using value_pointer = value_type *;
    using value_cpointer = const value_type *;
    using value_reference = value_type &;
    using value_creference = const value_type &;

    using pointer = std::shared_ptr<SingleList>;
    using node = pointer;
public:
    SingleList() = default;

    // 长度
    int length() const;
    
    // 是否为空
    bool empty() const;

    // to_string
    std::string to_string() const;

    // 头插
    void push_front(value_type && e);

    // 尾插
    void push_back(value_type && e);
    
    // 返回指定元素的第一个节点
    node find(value_creference e) const; 

    // 清除除链表
    void clear();
    
    // 反转链表
    void reverse();
private:
    value_type value;
    pointer next = nullptr;
};

/**双向链表*/
template <class T>
class List
{
public:
    using value_type = T;
    using value_pointer = value_type *;
    using value_cpointer = const value_type *;
    using value_reference = value_type &;
    using value_creference = const value_type &;

    using pointer = std::shared_ptr<List>;
    using node = pointer;

public:
    List() = default;

    // 长度
    int length() const;
    
    // 是否为空
    bool empty() const;

    // to_string
    std::string to_string() const;

    // 头插
    void push_front(value_type && e);

    // 尾插
    void push_back(value_type && e);
    
    // 返回指定元素的第一个节点
    node find(value_creference e) const; 

    // 清除除链表
    void clear();
    
    // 反转链表
    void reverse();
    
private:
    value_type value;
    pointer prev = nullptr;
    pointer next = nullptr;
};

} // namespace cxx

} // namespace algorithm

#endif //!LINKED_LIST_H