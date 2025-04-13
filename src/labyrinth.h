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
#include <stack>

using lab = std::vector<std::vector<bool> >; // алиас для лабиринта
using pos = std::pair<int, int>; // алиас для хранения позиции

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
    std::unordered_set<pos> visited; // маркировка пройденных координат
};

inline std::vector<std::vector<pos> > findAllPaths_c_stack(
    const lab &grid,
    pos start
) {
    /*
     * Функция поиска всех возможных путей в лабиринте
     * const lab &grid - лабиринт
     * pos start - координаты начала поиска
     */
    const unsigned N = grid.size();
    const unsigned M = grid[0].size();
    std::vector<std::vector<pos> > allPaths;

    c_stack<State> stack;
    stack.push({start, {start}, {start}});

    // Смещения для 4 направлений (вверх, вниз, влево, вправо)
    constexpr int dx[] = {-1, 1, 0, 0};
    constexpr int dy[] = {0, 0, -1, 1};

    while (!stack.empty()) {
        State current = stack.get_top();
        stack.pop();

        bool hasUnvisitedNeighbors = false;
        const int x = current.p.first;
        const int y = current.p.second;

        // Проверяем всех соседей
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || grid[nx][ny] == 1)
                continue;

            pos p = {nx, ny};
            if (current.visited.contains(p))
                continue; // уже посещали

            // Создаем следующее состояние так как нашли непосещенного соседа
            hasUnvisitedNeighbors = true;
            State next = current;
            next.p = p;
            next.path.emplace_back(p);
            next.visited.insert(p);

            stack.push(next);
        }
        if (!hasUnvisitedNeighbors && current.path.size() > 1) {
            allPaths.push_back(current.path);
        }
    }

    return allPaths;
}

inline std::vector<std::vector<pos> > findAllPaths_std_stack(
    const lab &grid,
    pos start
) {
    /*
     * Функция поиска всех возможных путей в лабиринте
     * const lab &grid - лабиринт
     * pos start - координаты начала поиска
     */
    const unsigned N = grid.size();
    const unsigned M = grid[0].size();
    std::vector<std::vector<pos> > allPaths;

    std::stack<State> stack;
    stack.push({start, {start}, {start}});

    // Смещения для 4 направлений (вверх, вниз, влево, вправо)
    constexpr int dx[] = {-1, 1, 0, 0};
    constexpr int dy[] = {0, 0, -1, 1};

    while (!stack.empty()) {
        State current = stack.top();
        stack.pop();

        bool hasUnvisitedNeighbors = false;
        const int x = current.p.first;
        const int y = current.p.second;

        // Проверяем всех соседей
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || grid[nx][ny] == 1)
                continue;

            pos p = {nx, ny};
            if (current.visited.contains(p))
                continue; // уже посещали

            // Создаем следующее состояние так как нашли непосещенного соседа
            hasUnvisitedNeighbors = true;
            State next = current;
            next.p = p;
            next.path.emplace_back(p);
            next.visited.insert(p);

            stack.push(next);
        }
        if (!hasUnvisitedNeighbors && current.path.size() > 1) {
            allPaths.push_back(current.path);
        }
    }

    return allPaths;
}

