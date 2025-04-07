//
// Created by zeros on 07.04.2025.
//
#pragma once


#include <vector>
#include <fstream>
#include <sstream>
#include <codecvt>
#include <iostream>


#include <vector>
#include <fstream>
#include <sstream>
#include <string>


using lab = std::vector<std::vector<int>>;
using pos = std::pair<unsigned int, unsigned int>;

inline  lab translator(std::ifstream &l) {
    lab v;

    if (!l.is_open()) {
        return v; // возвращаем пустой вектор, если файл не открыт
    }

    std::string line;
    while (std::getline(l, line)) {
        std::vector<bool> row;
        std::stringstream ss(line);
        int num;

        while (ss >> num) {
            row.push_back(static_cast<bool>(num));
        }

        if (!row.empty()) {
            v.push_back(row);
        }
    }

    return v;
}

inline void print_labyrinth(lab &v) {
    for (const auto &i: v) {
        for (const auto &j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

