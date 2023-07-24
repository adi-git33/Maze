// ----- Code by: Moran Sinai ID: 206402281 and Adi Levi ID: 316116052

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <exception>
#include <vector>
#include <iterator>
#include <fstream>
#include <cstring>

using namespace std;

class DuplicateKey : public exception
{
public:
    const string what() { return "DuplicateKeyException"; };
};

class NotExistObject : public exception
{
public:
    const string what() { return "ObjectNotExistException"; };
};

// File Exceptions

class FileNotOpen : public exception
{
public:
    const string what() { return "Couldn't Open File"; };
};

class FileNotRead : public exception
{
public:
    const string what() { return "Couldn't read File until the end"; };
};

template <class K, class V>
class CacheMemory
{
private:
    map<K, shared_ptr<V>> m_Memory;
    map<K, weak_ptr<V>> m_Cache;

public:
    // Constractor
    CacheMemory(){};
    // Destractor
    ~CacheMemory()
    {
        m_Memory.clear();
        m_Cache.clear();
    };

    // Funcs

    void add(const K &addKey, const V &addValue)
    {
        DuplicateKey dupErr;
        if (m_Memory.find(addKey) != m_Memory.end())
            throw(dupErr);
        else
        {
            m_Memory.insert(pair<K, shared_ptr<V>>(make_pair(addKey, make_shared<V>(addValue))));
        }
    };

    void erase(const K &deletedKey)
    {
        NotExistObject notExistingErr;
        if (m_Memory.find(deletedKey) == m_Memory.end())
            throw(notExistingErr);
        else
            m_Memory.erase(deletedKey);
    };

    shared_ptr<V> get(const K &key)
    {
        if (m_Cache.find(key) == m_Cache.end())
        {
            if (m_Memory.find(key) == m_Memory.end())
                return nullptr;
            else
            {
                m_Cache.insert(pair<K, weak_ptr<V>>(make_pair(key, weak_ptr<V>(m_Memory.find(key)->second))));
                return m_Memory.find(key)->second;
            }
        }
        else
        {
            if (m_Cache.find(key)->second.expired() == true)
            {
                m_Cache.erase(key);
                return nullptr;
            }
            else
                return m_Memory.find(key)->second;
        }
        return nullptr;
    };

    vector<V> getCacheValues()
    {
        vector<V> CacheValues;

        if (m_Cache.empty() != true)
        {
            for (auto it = m_Cache.begin(); it != m_Cache.end(); ++it)
            {
                auto ptr = it->second.lock();
                CacheValues.push_back(*ptr);
            }
        }
        return CacheValues;
    };


};
