//
// Created by zeros on 07.04.2025.
//

#ifndef C_STACK_H
#define C_STACK_H
#include <iostream>

// узел
template<typename T>
struct node {
    T info; // содержимое узла
    node *next; // ссылка не следующий узел

    explicit node(T x) : info(x), next(nullptr) {
    }

    ~node() = default;
};

template<typename T>
class c_stack {
    /* Реализация структуры данных Стек
     * запись и удаление элементов только из одного конца линейного списка
     * "стопка тарелок"
     */
public:
    c_stack() {
        top = nullptr;
        count = 0;
    }

    ~c_stack() {
        // поочередный перебор с удалением каждого элемента
        node<T> *tmp = nullptr;
        while (top != nullptr) {
            tmp = top;
            top = top->next;
            delete tmp;
        }
    }

    void push(T x) {
        // добавление элементов в очередь
        node<T> *tmp = new node(x);
        if (top == nullptr) {
            // случай пустого стека
            top = tmp;
        } else {
            tmp->next = top; // сохраняем ссылку на предыдущий верх стека
            top = tmp; // теперь tmp это новый верх
        }
        count++; // подсчет количества элементов в очереди
    }

    T pop() {
        if (top == nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        node<T> *tmp = top;
        T value = tmp->info;
        top = top->next;
        delete tmp;
        count--; // уменьшить счетчик
        return value;
    }

    T &get_top() const {
        return top->info;
    }

    [[nodiscard]] bool empty() const {
        return count == 0;
    }

    [[nodiscard]] int get_count() const { return count; }

private:
    node<T> *top; // верх стека
    int count; // число элементов в стеке
};


#endif //C_STACK_H
