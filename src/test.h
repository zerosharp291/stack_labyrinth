//
// Created by zeros on 07.04.2025.
//
#pragma once

#include "labyrinth.h"
#include <chrono>

inline void c_stack_test(const lab& l, const pos &p) {
    /*
     * Тестирование собственной реализации структуры Стек
     */

    for (auto paths = findAllPaths_c_stack(l, p); const auto &path : paths) {
        for (const auto& p:path) {
            std::cout << "(" << p.first << ", " << p.second << ") ";
        }
        std::cout << std::endl;
    }

}

inline void std_stack_test(const lab& l, const pos &p) {
    /*
     * Тестирование реализации структуры Стек в стандартной библиотеке C++
     */
    for (auto paths = findAllPaths_std_stack(l, p); const auto &path : paths) {
        for (const auto& p:path) {
            std::cout << "(" << p.first << ", " << p.second << ") ";
        }
        std::cout << std::endl;
    }
}

inline auto measure_c_stack(const lab& l, const pos &p) {
    const auto start = std::chrono::high_resolution_clock::now();
    findAllPaths_c_stack(l, p);
    const auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}
inline auto measure_std_stack(const lab& l, const pos &p) {
    const auto start = std::chrono::high_resolution_clock::now();
    findAllPaths_std_stack(l, p);
    const auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}
