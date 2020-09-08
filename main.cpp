#include <iostream>
#include <cassert>

#include "cache_t.h"

struct elem {
    int id;
};

int main()
{
    int m, n, id;
    elem *i_el;

    std::cin >> n >> m;
    cache <elem> mycache(m);
    for(int i = 0; i < n; i++) {
        std::cin >> id;
        i_el = new elem {id};
        std::cout << mycache.lookup(i_el) << "\n";
    }
    return 0;
}
