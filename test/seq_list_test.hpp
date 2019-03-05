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

ALGORITHM_TEST_CASE(seq_insert_delete)
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

ALGORITHM_TEST_CASE(seq_pop_fornt)
{

}

ALGORITHM_TEST_CASE(SeqList_test)
{
    ALGORITHM_EXECUTE_CASE(seq_insert_delete, 1);
    ALGORITHM_EXECUTE_CASE(seq_pop_fornt, 1);
}


#endif // !SEQ_LIST_TEST_HPP