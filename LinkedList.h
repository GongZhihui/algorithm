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

/**双向链表*/
typedef struct list
{
    data_type value;
    list *prev;
    list *next;
} list, *list_ptr;
typedef list_ptr list_node;

// 初始化
void single_list_init(single_list *L);

void list_init(list *L);
// 长度
// 是否为空
// 输出链表
// 指定位置插入
// 头插
// 尾插
// 查找指定位置的值
// 更新指定位置的值
// 返回指定元素的第一个节点
// 删除指定位置的节点
// 反转链表

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

public:
    SingleList() = default;

    // 长度
    // 是否为空
    // 输出链表
    // 指定位置插入
    // 头插
    // 尾插
    // 查找指定位置的值
    // 更新指定位置的值
    // 返回指定元素的第一个节点
    // 删除指定位置的节点
    // 反转链表
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

public:
    List() = default;

    // 长度
    // 是否为空
    // 输出链表
    // 指定位置插入
    // 头插
    // 尾插
    // 查找指定位置的值
    // 更新指定位置的值
    // 返回指定元素的第一个节点
    // 删除指定位置的节点
    // 反转链表
private:
    value_type value;
    pointer prev = nullptr;
    pointer next = nullptr;
};

} // namespace cxx

} // namespace algorithm

#endif //!LINKED_LIST_H