//
// Created by zeros on 07.04.2025.
//
#pragma once


#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include "../include/c_stack.h"
#include <functional>

using lab = std::vector<std::vector<bool> >; // алиас для лабиринта
using pos = std::pair<unsigned int, unsigned int>; // алиас для хранения позиции

template<>
struct std::hash<pos> {
    size_t operator()(const pos &p) const noexcept {
        return hash<unsigned>{}(p.first) ^ hash<unsigned>{}(p.second) << 1;
    }
};

inline lab labyrinth_from_file(std::ifstream &l) {
    // функция транслирует лабиринт из файла в vector<vector<bool>> (alias lab)
    lab v;

    if (!l.is_open()) {
        return v; // возвращаем пустой вектор, если файл не открыт
    }

    // считываем файл построчно, каждую строку записываем в вектор
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
    // функция для печати всего лабиринта
    for (const auto &i: v) {
        for (const auto &j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

// Структура описывающая текущее состояние
struct State {
    pos p; // координаты x, y
    std::vector<pos> path; // пройденный путь
    std::unordered_set<int> visited; // маркировка пройденных координат
};

std::vector<pos> findAllPathsStack(
    const lab &grid,
    pos start,
    pos end
) {
    const int N = grid.size();
    const int M = grid[0].size();

    std::vector<std::vector<pos> > all_paths;
    c_stack<State> stack;
    stack.push({start, {start},});
}
