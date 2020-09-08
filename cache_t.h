#pragma once

#include <list>
#include <unordered_map>
#include <iterator>

template <typename T>
class cache {
private:
    int size;
    std :: list<T> c_list;
    typedef typename std::list<T>::iterator ListIt;
    std :: unordered_map<int, ListIt> hash_t;
public:
    cache(int c_size);
    bool full();
    bool lookup(const T *elem);
};

template <typename T>
bool cache<T>::lookup(const T *elem) {
    auto hit = hash_t.find(elem->id);
    if (hit == hash_t.end()) {
        if (cache<T>::full()) {
            T *d_el = &(c_list.back());
            hash_t.erase(d_el->id);
            c_list.pop_back();
        }
        c_list.push_front(*elem);
        hash_t[elem->id] = c_list.begin();
        return false;
    }
    auto eltit = hit->second;
    if (eltit != c_list.begin()) {
        c_list.splice(c_list.begin(), c_list, eltit);
    }
    return true;
}

template <typename T>
bool cache<T>::full() {
    if(c_list.size() >= (size_t) size) {
        return true;
    }
}

template <typename T>
cache<T>::cache(int c_size) {
    size = c_size;
}
