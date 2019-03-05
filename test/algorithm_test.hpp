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

#ifndef ALGORITHM_TEST_HPP
#define ALGORITHM_TEST_HPP

#include "TestUtils.h"
#include "../algorithm.h"

using namespace algorithm;

struct B
{
    int n = 0;
    B(int n_, int n2):n(n_){}
    friend bool operator<(const B &lhs, const B &rhs);
    friend bool operator>(const B &lhs, const B &rhs);
};
bool operator<(const B &lhs, const B &rhs)
{
    return lhs.n < rhs.n;
}

bool operator>(const B &lhs, const B &rhs)
{
    return lhs.n > rhs.n;
}

struct A
{
    A& operator=(const A&) = default; 
    int n = 0;
    A(int n_):n(n_){}
    friend bool operator<(const A &lhs, const A &rhs);
    friend bool operator>(const A &lhs, const A &rhs);
};
bool operator<(const A &lhs, const A &rhs)
{
    return lhs.n < rhs.n;
}

bool operator>(const A &lhs, const A &rhs)
{
    return lhs.n > rhs.n;
}

ALGORITHM_TEST_CASE(ShellSort)
{
    std::vector<A> ac = {592, 401, 874, 141, 348, 72, 911, 887, 820, 283, 11};
   
    ShellSort(ac);
    for(std::size_t i = 0; i<ac.size(); i++)
    {
        std::cout<< ac[i].n << " ";
    }
    std::cout<< std::endl;
}

// 执行
ALGORITHM_TEST_CASE(algorithm_test)
{
    ALGORITHM_EXECUTE_CASE(ShellSort, 0);
}






#endif // !ALGORITHM_TEST_HPP