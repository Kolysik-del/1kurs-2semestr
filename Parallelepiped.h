#pragma once
#include "RegularSolid.h"
#include "Point.h"
#include <vector>

namespace geometry {
    /**
    * @brief класс Параллелепипед
    */
    class Parallelepiped : public RegularSolid {
    private:
        /**
        * @brief VERTEX_COUNT - постоянное количество вершин параллелепипеда
        */
        static const int VERTEX_COUNT = 8;

        /**
        * @brief вершины параллелепипеда
        */
        std::vector<Point> vertices;

        /**
        * @brief длины сторон параллелепипеда
        */
        double a, b, c;

        /**
        * @brief проверяет корректность параллелепипеда
        * @return true, если стороны положительны
        */
        bool isValidParallelepiped() const;

        /**
        * @brief вычисляет все 8 вершин по базовой точке и сторонам
        * @param basePoint - базовая вершина
        */
        void calculateVertices(const Point& basePoint);

    public:
        /**
        * @brief конструктор по умолчанию
        */
        Parallelepiped();

        /**
        * @brief конструктор, создающий параллелепипед по трем вершинам
        * @param p1 - первая вершина (базовая)
        * @param p2 - вторая вершина (определяет сторону a)
        * @param p3 - третья вершина (определяет сторону b)
        */
        Parallelepiped(const Point& p1, const Point& p2, const Point& p3);

        /**
        * @brief конструктор, создающий параллелепипед по вершине и двум сторонам
        * @param basePoint - базовая вершина
        * @param sideA - длина стороны a
        * @param sideB - длина стороны b
        * @param sideC - длина стороны c
        */
        Parallelepiped(const Point& basePoint, double sideA, double sideB, double sideC);

        /**
        * @brief конструктор, создающий параллелепипед по двум вершинам главной диагонали
        * @param diagonalStart - начало диагонали
        * @param diagonalEnd - конец диагонали
        */
        Parallelepiped(const Point& diagonalStart, const Point& diagonalEnd);

        /**
        * @brief конструктор копирования
        * @param other - копируемый параллелепипед
        */
        Parallelepiped(const Parallelepiped& other);

        /**
        * @brief оператор присваивания
        * @param other - присваиваемый параллелепипед
        * @return ссылка на текущий объект
        */
        Parallelepiped& operator=(const Parallelepiped& other);

        /**
        * @brief расчет площади поверхности параллелепипеда
        * @return площадь поверхности
        */
        double getSurfaceArea() const override;

        /**
        * @brief расчет объема параллелепипеда
        * @return объем
        */
        double getVolume() const override;

        /**
        * @brief сериализация в строку
        * @return строковое представление параллелепипеда
        */
        std::string ToString() const override;

        /**
        * @brief метод чтения из стандартного потока ввода
        * @param is - входной поток
        */
        void read(std::istream& is) override;

        /**
        * @brief оператор сравнения на равенство
        * @param other - другой параллелепипед
        * @return true, если параллелепипеды равны
        */
        bool operator==(const Parallelepiped& other) const;

        /**
        * @brief оператор сравнения на неравенство
        * @param other - другой параллелепипед
        * @return true, если параллелепипеды не равны
        */
        bool operator!=(const Parallelepiped& other) const;

        /**
        * @brief получение вершин параллелепипеда
        * @return вектор вершин
        */
        std::vector<Point> getVertices() const;

        /**
        * @brief получение длины стороны a
        * @return длина стороны a
        */
        double getSideA() const;

        /**
        * @brief получение длины стороны b
        * @return длина стороны b
        */
        double getSideB() const;

        /**
        * @brief получение длины стороны c
        * @return длина стороны c
        */
        double getSideC() const;

        /**
        * @brief статический метод сериализации в строку
        * @param parallelepiped - параллелепипед
        * @return строковое представление
        */
        static std::string ToString(const Parallelepiped& parallelepiped);

        /**
        * @brief статический метод чтения из стандартного потока ввода
        * @param is - входной поток
        * @return созданный параллелепипед
        */
        static Parallelepiped readFromStream(std::istream& is);
    };
}