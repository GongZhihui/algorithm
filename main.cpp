#include "algorithm.h"
#include <iostream>
#include <algorithm>
#include "TestUtils.h"
#include "LRUCache.h"
#include <string>

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
    // //std::cout<< add() << std::endl;   
    // std::array<int, 4> a = {1, 5, 7, 11};
    // int ret = 0;
    // ret = BinarySearch(7, a);
    // std::cout<< "sd "<<ret << std::endl;
    
    // std::vector<int> a2 = {1, 5, 7, 11};
    // B b(2, 3);

    // // ret = BinarySearch(b, a2);
    // // std::cout<< "sd "<<ret << std::endl;

    // A a5(3,3);
    // std::vector<B> aa = {{1, 1}, {3,3}, {2,2}, {4,3}};
    // ret = BinarySearch(a5, aa);
    // std::cout<< ret << std::endl;

    // int cc[7] = {1, 5, 3, 11, 50, 18, 2};
    // InsertSort(aa);
    // for(int i = 0; i<aa.size();i++)
    // {
    //     std::cout<< aa[i].n << " ";
    // }
    // std::cout<< std::endl;

    // InsertSort(cc, 7);
    // for(int i = 0; i<7; i++)
    // {
    //     std::cout<< cc[i] << " ";
    // }
    // std::cout<< std::endl;
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
    std::cout << cache.get(1) <<std::endl;
    std::cout << cache.get(2) << std::endl;
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(4) << std::endl;
    std::cout << cache.get(3) << std::endl;
    cache.put(1, "li");
    std::cout << cache.get(4) << std::endl;
    std::cout<< "LUR" << std::endl;
}

int main()
{
    ALGORITHM_EXECUTE_CASE(ShellSort, 1);
    ALGORITHM_EXECUTE_CASE(LURCache, 1);
    std::cin.get();

    return 0;
}






























// #include <iostream>
// #include <random>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <iomanip>
// #include "SHAMap.h"
// #include <assert.h>

// //#include "GZHMap.h"

// class sequential
// {
//     unsigned long long count_ = 0;
// public:
//     unsigned long long
//         operator()()
//     {
//         return count_++;
//     }
// };

// class sequential256
// {
//     unsigned long long count_[4] = { 0 };
//     unsigned p_ = 0;
// public:
//     unsigned long long
//         operator()()
//     {
//         if (p_ == 4)
//         {
//             count_[0]++;
//             p_ = 0;
//         }
//         return count_[p_++];
//     }
// };

// class sequential256_backwards
// {
//     unsigned long long count_[4] = { 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF,
//         0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF };
//     unsigned p_ = 4;
// public:
//     unsigned long long
//         operator()()
//     {
//         if (p_ == 0)
//         {
//             count_[0]--;
//             p_ = 4;
//         }
//         return count_[--p_];
//     }
// };

// uint256
// make_key()
// {
//     static std::mt19937_64 eng{ 5 };
//     //static sequential eng{};
//     //static sequential256 eng{};
//     //static sequential256_backwards eng{};
//     uint256 a;
//     for (unsigned i = 0; i < 4; ++i)
//     {
//         auto u = eng();
//         for (unsigned j = 0; j < 8; ++j)
//         {
//             a[i * 8 + j] = u & 0xFF;
//             u >>= 8;
//         }
//     }
//     return a;
// }

// std::string string2hex(const std::uint8_t *data, int len)
// {
//     std::string result;
//     std::string tmp;
//     std::stringstream ss;
//     for (int i = 0; i < len; i++)
//     {
//         int r = int(data[i]);
//         ss << std::hex << std::setw(2)
//             << std::setfill('0') << r << std::endl;
//         ss >> tmp;
//         result += tmp;
//     }
//     return result;
// }

// std::string string2hex(const std::string &data)
// {
//     return string2hex((std::uint8_t*)data.data(), data.size());
// }

// std::string string2hex(const std::int8_t *data, int len)
// {
//     return string2hex((std::uint8_t*)data, len);
// }

// std::string string2hex(const std::vector<std::uint8_t> data)
// {
//     return string2hex(data.data(), data.size());
// }



// int main()
// {
 

//     std::cout << "s" <<std::dec << std::string(2, ' ')<<"2" << std::endl;

//     std::vector<uint256> keys;
//     for (int i = 0; i < 200; ++i)
//        keys.push_back(make_key());
//     std::cout << keys.size() << std::endl;
//     for(const auto &i : keys)
//     {
//        std::cout<<string2hex(i.data(), i.size())<<std::endl;
//     }


//     SHAMap m;
//     std::size_t sz = 0;
//     for (auto const& k : keys)
//     {
//        m.insert({ 0 }, { k,{} });
//        m.invariants();
//        ++sz;
//        assert(std::distance(m.begin(), m.end()) == sz);
//     }

//     m.display(std::cout);
//     std::cout << '\n';
    
//     for (auto i = m.begin(); i != m.end(); ++i)
//     {
//        auto j = m.upper_bound(i->key());
//        assert(std::next(i) == j);
//     }


//     for (unsigned i = 0; i < keys.size(); ++i)
//     {
//        auto k = make_key();
//        if (std::find(keys.begin(), keys.end(), k) != keys.end())
//        {
//            assert(false);
//            continue;
//        }
//        auto j = m.upper_bound(k);
//        for (auto h = m.begin(); h != j; ++h)
//            assert(h->key() < k);
//        for (auto h = j; h != m.end(); ++h)
//            assert(h->key() > k);
//     }
//     for (auto const& k : keys)
//     {
//        auto i = m.findKey(k);
//        assert(i != m.end());
//        assert(i->key() == k);
//        auto j = i;
//        ++j;
//        i = m.erase(std::move(i));
//        m.invariants();
//        --sz;
//        assert(std::distance(m.begin(), m.end()) == sz);
//        assert(i == j);
//        /*m.display(std::cout);
//        std::cout << '\n';*/
//     }


// }
