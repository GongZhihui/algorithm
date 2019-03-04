#include "algorithm.h"
#include <iostream>
#include <algorithm>
#include "TestUtils.h"
#include "LRUCache.h"
#include <string>
#include "SeqList.h"

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

ALGORITHM_TEST_CASE(SeqList)
{
    using namespace c;
    seq_list list;
    init_seq_list(&list);
    insert_seq_list_element(&list, 0, 2);
    show_seq_list(&list);
    insert_seq_list_element(&list, 1, 3);
    show_seq_list(&list);
    insert_seq_list_element(&list, 1, 4);
    show_seq_list(&list);
    insert_seq_list_element(&list, 2, 5);
    show_seq_list(&list);
    insert_seq_list_element(&list, 3, 7);
    show_seq_list(&list);
    
}

int main()
{
    ALGORITHM_EXECUTE_CASE(ShellSort, 0);
    ALGORITHM_EXECUTE_CASE(LURCache, 0);
    ALGORITHM_EXECUTE_CASE(SeqList, 1);
    std::cin.get();

    return 0;
}