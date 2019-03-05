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

#ifndef LRUCACHE_TEST_HPP
#define LRUCACHE_TEST_HPP

#include "TestUtils.h"
#include "../LRUCache.h"

using namespace algorithm;

ALGORITHM_TEST_CASE(LURCache)
{
    LRUCache<int, std::string> cache{ 100 };
    cache.put(1, "li");
    cache.put(2, "wu");
    cache.put(3, "go");
    cache.put(4, "ho");
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(2) << std::endl;
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(4) << std::endl;
    std::cout << cache.get(3) << std::endl;
    cache.put(1, "li");
    std::cout << cache.get(4) << std::endl;
    std::cout<< "LUR" << std::endl;
}

// 执行
ALGORITHM_TEST_CASE(LURCache_test)
{
    ALGORITHM_EXECUTE_CASE(LURCache, 0);
}





#endif // !LRUCACHE_TEST_HPP