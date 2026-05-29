#pragma once

namespace collections {
    /**
     * @brief Класс узла односвязного списка
     * @tparam T тип данных, хранящихся в узле
     */
    template<typename T>
    class ListNode {
    private:
        T value;
        ListNode<T>* nextNode;

    public:
        /**
         * @brief Конструктор узла
         * @param val - значение для хранения в узле
         */
        explicit ListNode(const T& val) : value(val), nextNode(nullptr) {}

        /**
         * @brief Получение значения узла
         * @return значение
         */
        T getValue() const {
            return value;
        }

        /**
         * @brief Установка значения узла
         * @param val - новое значение
         */
        void setValue(const T& val) {
            value = val;
        }

        /**
         * @brief Получение указателя на следующий узел
         * @return указатель на следующий узел
         */
        ListNode<T>* getNextNode() const {
            return nextNode;
        }

        /**
         * @brief Установка указателя на следующий узел
         * @param node - указатель на следующий узел
         */
        void setNextNode(ListNode<T>* node) {
            nextNode = node;
        }
    };
}
