#pragma once

#include <iostream>

namespace util {
template <typename MapType> auto printMap(const MapType &x) -> void {
    std::cout << "=====Map=====" << std::endl;
    for (auto it = x.begin(); it != x.end(); it++) {
        std::cout << it->first << ":" << it->second << std::endl;
    }
    std::cout << "=====End=====" << std::endl;
}
} // namespace util
