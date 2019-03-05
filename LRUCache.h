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

#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include <list>

namespace algorithm
{

// 缓存机制：最近最少使用策略，用map+list
template<class Key,
    class Value,
    class Hash = std::hash<Key>,
    class KeyEq = std::equal_to<Key>>
class LRUCache
{
public:
    using KeyType = Key;
    using ValueType = Value;

public:
    explicit LRUCache(int maxSize): mMaxSize(maxSize){}
    
    // 禁止默认构造和拷贝构造
    LRUCache() = delete;
    LRUCache(const LRUCache &) = delete;
    LRUCache(LRUCache &&) = default;

    void put(KeyType key, ValueType &&value);
    ValueType get(KeyType key);

private:
    struct Node;
    using Cache = std::list<Node>; 
    using CacheIterator = typename Cache::iterator;
    using KeyCache = std::unordered_map<KeyType, CacheIterator, Hash, KeyEq>;

    // 保存key和value
    Cache cache;
    // 保存链表中key对应的iterator
    KeyCache keyCache;
    // 该缓存能保存的kv对的最大数量
    int mMaxSize;
};

template<class Key,
    class Value,
    class Hash,
    class KeyEq>
struct LRUCache<Key, Value, Hash, KeyEq>::Node
{
    KeyType mKey;
    ValueType mValue;
    Node(KeyType key, ValueType && value)
        : mKey(key)
        , mValue(std::move(value))
    {
    }
};

template<class Key,
    class Value,
    class Hash,
    class KeyEq>
void LRUCache<Key, Value, Hash, KeyEq>::put(KeyType key, ValueType &&value)
{
    auto it = keyCache.find(key);
    // 如何key在map中
    if(it != keyCache.end())
    {
        auto cacheIt = keyCache[key];
        // 在map中删除当前list的it
        keyCache.erase(it);

        // 在链表头插入node
        cache.emplace_front(key, std::move(value));
        // 将该node在list中的it放入map中
        keyCache[key] = cache.begin();
    }
    else
    {
        if(cache.size() == mMaxSize)
        {
            keyCache.erase(cache.back().mKey);
            cache.pop_back();
        }
        cache.emplace_front(key, std::move(value));
        keyCache[key] = cache.begin();
    }
}
 
template<class Key,
    class Value,
    class Hash,
    class KeyEq>
typename LRUCache<Key, Value, Hash, KeyEq>::ValueType 
LRUCache<Key, Value, Hash, KeyEq>::get(KeyType key)
{
    auto it = keyCache.find(key);
    if(it != keyCache.end())
    {
        auto cacheIt = keyCache[key];
        cache.emplace_front(key, std::move(cacheIt->mValue));
        keyCache[key] = cache.begin();
        cache.erase(cacheIt);
        return cache.begin()->mValue;
    }
    else
    {
        return ValueType{}; 
    }
}

} //!algorithm

#endif //!LRU_CACHE_H