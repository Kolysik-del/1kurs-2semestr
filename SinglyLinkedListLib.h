#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <sstream>
#include <stdexcept>
#include "ListNode.h"

namespace collections {
    /**
     * @brief Класс линейного односвязного списка
     * @tparam T тип данных, хранящихся в списке
     */
    template<typename T>
    class SinglyLinkedList {
    private:
        ListNode<T>* first;
        ListNode<T>* last;
        size_t count;

        /**
         * @brief Копирует содержимое другого списка
         * @param other - список для копирования
         */
        void cloneFrom(const SinglyLinkedList<T>& other);

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        SinglyLinkedList();

        /**
         * @brief Конструктор со списком инициализации
         * @param init - список инициализации
         */
        SinglyLinkedList(const std::initializer_list<T> init);

        /**
         * @brief Конструктор копирования
         * @param other - другой список
         */
        SinglyLinkedList(const SinglyLinkedList<T>& other);

        /**
         * @brief Конструктор перемещения
         * @param other - другой список
         */
        SinglyLinkedList(SinglyLinkedList<T>&& other) noexcept;

        /**
         * @brief Деструктор
         */
        ~SinglyLinkedList();

        /**
         * @brief Оператор присваивания копированием
         * @param other - другой список
         * @return ссылка на текущий объект
         */
        SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& other);

        /**
         * @brief Оператор присваивания перемещением
         * @param other - другой список
         * @return ссылка на текущий объект
         */
        SinglyLinkedList<T>& operator=(SinglyLinkedList<T>&& other) noexcept;

        /**
         * @brief Оператор сдвига влево (вывод в поток)
         * @param os - поток вывода
         * @param list - список для вывода
         * @return ссылка на поток вывода
         */
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<U>& list);

        /**
         * @brief Оператор сдвига вправо (ввод из потока)
         * @param is - поток ввода
         * @param list - список для ввода
         * @return ссылка на поток ввода
         */
        template<typename U>
        friend std::istream& operator>>(std::istream& is, SinglyLinkedList<U>& list);

        /**
         * @brief Вставка элемента в конец списка
         * @param val - значение элемента
         */
        void push_back(const T& val);

        /**
         * @brief Вставка элемента в начало списка
         * @param val - значение элемента
         */
        void push_front(const T& val);

        /**
         * @brief Вставка элемента по индексу
         * @param index - позиция для вставки
         * @param val - значение элемента
         */
        void insert(const size_t index, const T& val);

        /**
         * @brief Удаление элемента из конца списка
         */
        void pop_back();

        /**
         * @brief Удаление элемента из начала списка
         */
        void pop_front();

        /**
         * @brief Удаление элемента по индексу
         * @param index - позиция элемента
         */
        void erase(const size_t index);

        /**
         * @brief Удаление элемента по значению (первое вхождение)
         * @param val - значение для удаления
         * @return true, если элемент найден и удален
         */
        bool remove(const T& val);

        /**
         * @brief Поиск элемента по значению
         * @param val - значение для поиска
         * @return индекс элемента или -1, если не найден
         */
        int indexOf(const T& val) const;

        /**
         * @brief Изменение элемента по индексу
         * @param index - позиция элемента
         * @param val - новое значение
         */
        void setAt(const size_t index, const T& val);

        /**
         * @brief Оператор доступа по индексу (неконстантный)
         * @param index - позиция элемента
         * @return ссылка на элемент
         */
        T& operator[](const size_t index);

        /**
         * @brief Оператор доступа по индексу (константный)
         * @param index - позиция элемента
         * @return константная ссылка на элемент
         */
        const T& operator[](const size_t index) const;

        /**
         * @brief Получение размера списка
         * @return количество элементов
         */
        size_t getCount() const;

        /**
         * @brief Проверка, пуст ли список
         * @return true, если список пуст
         */
        bool isEmpty() const;

        /**
         * @brief Очистка списка
         */
        void clear();

        /**
         * @brief Сериализация в строку
         * @return строковое представление списка
         */
        std::string asString() const;

        /**
         * @brief Получение указателя на начало списка
         * @return указатель на первый элемент списка
         */
        ListNode<T>* getFirst() const;
    };

    template<typename T>
    void SinglyLinkedList<T>::cloneFrom(const SinglyLinkedList<T>& other) {
        ListNode<T>* current = other.first;
        while (current != nullptr) {
            push_back(current->getValue());
            current = current->getNextNode();
        }
    }

    template<typename T>
    SinglyLinkedList<T>::SinglyLinkedList() : first(nullptr), last(nullptr), count(0) {}

    template<typename T>
    SinglyLinkedList<T>::SinglyLinkedList(const std::initializer_list<T> init)
        : first(nullptr), last(nullptr), count(0) {
        for (const auto& val : init) {
            push_back(val);
        }
    }

    template<typename T>
    SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other)
        : first(nullptr), last(nullptr), count(0) {
        cloneFrom(other);
    }

    template<typename T>
    SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T>&& other) noexcept
        : first(other.first), last(other.last), count(other.count) {
        other.first = nullptr;
        other.last = nullptr;
        other.count = 0;
    }

    template<typename T>
    SinglyLinkedList<T>::~SinglyLinkedList() {
        clear();
    }

    template<typename T>
    SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other) {
        if (this != &other) {
            clear();
            cloneFrom(other);
        }
        return *this;
    }

    template<typename T>
    SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList<T>&& other) noexcept {
        if (this != &other) {
            clear();
            first = other.first;
            last = other.last;
            count = other.count;
            other.first = nullptr;
            other.last = nullptr;
            other.count = 0;
        }
        return *this;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& list) {
        os << list.asString();
        return os;
    }

    template<typename T>
    std::istream& operator>>(std::istream& is, SinglyLinkedList<T>& list) {
        list.clear();
        T val;
        while (is >> val) {
            list.push_back(val);
            if (is.peek() == '\n' || is.peek() == EOF) break;
        }
        return is;
    }

    template<typename T>
    void SinglyLinkedList<T>::push_back(const T& val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            last->setNextNode(newNode);
            last = newNode;
        }
        ++count;
    }

    template<typename T>
    void SinglyLinkedList<T>::push_front(const T& val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        if (first == nullptr) {
            first = last = newNode;
        }
        else {
            newNode->setNextNode(first);
            first = newNode;
        }
        ++count;
    }

    template<typename T>
    void SinglyLinkedList<T>::insert(const size_t index, const T& val) {
        if (index > count) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        if (index == 0) {
            push_front(val);
            return;
        }
        if (index == count) {
            push_back(val);
            return;
        }

        ListNode<T>* current = first;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->getNextNode();
        }

        ListNode<T>* newNode = new ListNode<T>(val);
        newNode->setNextNode(current->getNextNode());
        current->setNextNode(newNode);
        ++count;
    }

    template<typename T>
    void SinglyLinkedList<T>::pop_back() {
        if (isEmpty()) {
            throw std::out_of_range("Список пуст");
        }

        if (count == 1) {
            delete first;
            first = last = nullptr;
        }
        else {
            ListNode<T>* current = first;
            while (current->getNextNode() != last) {
                current = current->getNextNode();
            }
            delete last;
            last = current;
            last->setNextNode(nullptr);
        }
        --count;
    }

    template<typename T>
    void SinglyLinkedList<T>::pop_front() {
        if (isEmpty()) {
            throw std::out_of_range("Список пуст");
        }

        if (count == 1) {
            delete first;
            first = last = nullptr;
        }
        else {
            ListNode<T>* temp = first;
            first = first->getNextNode();
            delete temp;
        }
        --count;
    }

    template<typename T>
    void SinglyLinkedList<T>::erase(const size_t index) {
        if (index >= count) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        if (index == 0) {
            pop_front();
            return;
        }
        if (index == count - 1) {
            pop_back();
            return;
        }

        ListNode<T>* current = first;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->getNextNode();
        }

        ListNode<T>* temp = current->getNextNode();
        current->setNextNode(temp->getNextNode());
        delete temp;
        --count;
    }

    template<typename T>
    bool SinglyLinkedList<T>::remove(const T& val) {
        int idx = indexOf(val);
        if (idx != -1) {
            erase(idx);
            return true;
        }
        return false;
    }

    template<typename T>
    int SinglyLinkedList<T>::indexOf(const T& val) const {
        ListNode<T>* current = first;
        size_t idx = 0;
        while (current != nullptr) {
            if (current->getValue() == val) {
                return static_cast<int>(idx);
            }
            current = current->getNextNode();
            ++idx;
        }
        return -1;
    }

    template<typename T>
    void SinglyLinkedList<T>::setAt(const size_t index, const T& val) {
        if (index >= count) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        ListNode<T>* current = first;
        for (size_t i = 0; i < index; ++i) {
            current = current->getNextNode();
        }
        current->setValue(val);
    }

    template<typename T>
    T& SinglyLinkedList<T>::operator[](const size_t index) {
        if (index >= count) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        ListNode<T>* current = first;
        for (size_t i = 0; i < index; ++i) {
            current = current->getNextNode();
        }
        return current->getValue();
    }

    template<typename T>
    const T& SinglyLinkedList<T>::operator[](const size_t index) const {
        if (index >= count) {
            throw std::out_of_range("Индекс выходит за пределы списка");
        }

        ListNode<T>* current = first;
        for (size_t i = 0; i < index; ++i) {
            current = current->getNextNode();
        }
        return current->getValue();
    }

    template<typename T>
    size_t SinglyLinkedList<T>::getCount() const {
        return count;
    }

    template<typename T>
    bool SinglyLinkedList<T>::isEmpty() const {
        return count == 0;
    }

    template<typename T>
    void SinglyLinkedList<T>::clear() {
        ListNode<T>* current = first;
        while (current != nullptr) {
            ListNode<T>* temp = current;
            current = current->getNextNode();
            delete temp;
        }
        first = last = nullptr;
        count = 0;
    }

    template<typename T>
    std::string SinglyLinkedList<T>::asString() const {
        std::stringstream ss;
        ss << "[";
        ListNode<T>* current = first;
        while (current != nullptr) {
            ss << current->getValue();
            if (current->getNextNode() != nullptr) {
                ss << " -> ";
            }
            current = current->getNextNode();
        }
        ss << "]";
        return ss.str();
    }

    template<typename T>
    ListNode<T>* SinglyLinkedList<T>::getFirst() const {
        return first;
    }
}
