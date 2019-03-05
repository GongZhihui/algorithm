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

#ifndef TEST_HPP
#define TEST_HPP

#include "TestUtils.h"
#include "seq_list_test.hpp"
#include "LRUCache_test.hpp"
#include "algorithm_test.hpp"

void run_test()
{
    ALGORITHM_EXECUTE(algorithm_test, 0);
    ALGORITHM_EXECUTE(LURCache_test, 0);
    ALGORITHM_EXECUTE(SeqList_test, 1);
}

#endif // !TEST_HPP