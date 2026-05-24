#pragma once

namespace collections {
    /**
     * @brief Класс узла односвязного списка
     * @tparam T тип данных, хранящихся в узле
     */
    template<typename T>
    class ListNode {
    public:
        T value;
        ListNode<T>* nextNode;

        /**
         * @brief Конструктор узла
         * @param val - значение для хранения в узле
         */
        explicit ListNode(const T& val) : value(val), nextNode(nullptr) {}
    };
}