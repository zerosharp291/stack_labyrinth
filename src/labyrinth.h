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
#include <unordered_set>

using lab = std::vector<std::vector<bool> >;
using pos = std::pair<unsigned int, unsigned int>;

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
    std::unordered_set<pos> visited; // маркировка пройденных координат
};
