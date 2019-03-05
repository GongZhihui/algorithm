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

#ifndef SEQ_LIST_TEST_HPP
#define SEQ_LIST_TEST_HPP

#include "TestUtils.h"
#include "../SeqList.h"

using namespace algorithm::c;
using namespace algorithm::cxx;

ALGORITHM_TEST_CASE(seq_insert_delete_c)
{
    seq_list list;
    seq_list_init(&list);
    auto ret = seq_list_insert_element(&list, 0, 2);
    if(ret == seq_list_end(&list))
    {
        std::cout<< "end" << std::endl;
    }
    seq_list_show(&list);
    seq_list_insert_element(&list, 1, 3);
    seq_list_show(&list);
    seq_list_insert_element(&list, 1, 4);
    seq_list_show(&list);
    seq_list_insert_element(&list, 2, 5);
    seq_list_show(&list);
    seq_list_insert_element(&list, 3, 7);
    seq_list_show(&list);
    int a = 0;
    ret = seq_list_delete_element(&list, 2, &a);
    seq_list_show(&list);
}

ALGORITHM_TEST_CASE(seq_pop_fornt_c)
{
    seq_list list;
    seq_list_ptr p = &list;

    seq_list_init(p);
    seq_list_push_back(p, 2);
    seq_list_push_back(p, 5);
    seq_list_push_back(p, 1);
    seq_list_push_front(p, 9);
    std::cout<<"------\n";
    for(auto it = seq_list_begin(p); it != seq_list_end(p); it++)
    {
        std::cout<< *it << " ";
    }
    std::cout<<std::endl;
    std::cout<<"------\n";
    seq_list_show(p);
    seq_list_pop_back(p);
    seq_list_show(p);
    seq_list_pop_front(p);
    seq_list_show(p);
}

ALGORITHM_TEST_CASE(seq_cxx)
{
    SequenceList<int, 20> list;
    list.push_back(1);
    list.push_back(5);
    list.push_front(50);
    list.push_back(7);
    list.push_back(10);
    std::cout<< list.to_string() << std::endl;
    list.pop_back();
    list.pop_front();
    std::cout<< list.to_string() << std::endl;
    std::cout<<*list.get(1)<<std::endl;
    list.insert(2, 4);
    std::cout<< list.to_string() << std::endl;

    std::cout<< *list.end() <<std::endl;
}

ALGORITHM_TEST_CASE(SeqList_test)
{
    ALGORITHM_EXECUTE_CASE(seq_insert_delete_c, 0);
    ALGORITHM_EXECUTE_CASE(seq_pop_fornt_c, 0);
    ALGORITHM_EXECUTE_CASE(seq_cxx, 1);
}


#endif // !SEQ_LIST_TEST_HPP