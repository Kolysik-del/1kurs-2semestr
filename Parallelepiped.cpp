#define _USE_MATH_DEFINES
#include "Parallelepiped.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <limits>

namespace geometry {
    Parallelepiped::Parallelepiped(const Point& p1, const Point& p2, const Point& p3) {
        // Вычисляем длины сторон из трех вершин
        a = p1.distanceTo(p2);
        b = p1.distanceTo(p3);

        // Для упрощения считаем, что третья сторона c определяется как расстояние
        // Предполагаем прямоугольный параллелепипед, ориентированный по осям
        double dx = std::abs(p2.getX() - p1.getX());
        double dy = std::abs(p2.getY() - p1.getY());
        double dz = std::abs(p2.getZ() - p1.getZ());

        a = std::max({ dx, dy, dz });

        dx = std::abs(p3.getX() - p1.getX());
        dy = std::abs(p3.getY() - p1.getY());
        dz = std::abs(p3.getZ() - p1.getZ());

        b = std::max({ dx, dy, dz });

        // Для третьей стороны берем среднее или предполагаем куб
        c = a; // По умолчанию делаем куб

        if (a <= 0 || b <= 0 || c <= 0) {
            throw std::invalid_argument("Стороны параллелепипеда должны быть положительными числами");
        }

        calculateVertices(p1);

        if (!isValidParallelepiped()) {
            throw std::invalid_argument("Некорректные вершины для параллелепипеда");
        }
    }

    Parallelepiped::Parallelepiped(const Point& basePoint, double sideA, double sideB, double sideC) {
        if (sideA <= 0 || sideB <= 0 || sideC <= 0) {
            throw std::invalid_argument("Стороны параллелепипеда должны быть положительными числами");
        }

        a = sideA;
        b = sideB;
        c = sideC;

        calculateVertices(basePoint);

        if (!isValidParallelepiped()) {
            throw std::invalid_argument("Некорректные параметры для параллелепипеда");
        }
    }

    Parallelepiped::Parallelepiped(const Point& diagonalStart, const Point& diagonalEnd) {
        // Вычисляем длины сторон из диагонали
        a = std::abs(diagonalEnd.getX() - diagonalStart.getX());
        b = std::abs(diagonalEnd.getY() - diagonalStart.getY());
        c = std::abs(diagonalEnd.getZ() - diagonalStart.getZ());

        if (a <= 0 || b <= 0 || c <= 0) {
            throw std::invalid_argument("Стороны параллелепипеда должны быть положительными числами");
        }

        calculateVertices(diagonalStart);

        if (!isValidParallelepiped()) {
            throw std::invalid_argument("Некорректная диагональ для параллелепипеда");
        }
    }

    Parallelepiped::Parallelepiped(const Parallelepiped& other)
        : vertices(other.vertices), a(other.a), b(other.b), c(other.c) {
    }

    Parallelepiped& Parallelepiped::operator=(const Parallelepiped& other) {
        if (this != &other) {
            vertices = other.vertices;
            a = other.a;
            b = other.b;
            c = other.c;
        }
        return *this;
    }

    void Parallelepiped::calculateVertices(const Point& basePoint) {
        vertices.clear();
        vertices.reserve(VERTEX_COUNT);

        // Вычисляем 8 вершин параллелепипеда
        // Предполагаем, что параллелепипед ориентирован по осям координат
        double x0 = basePoint.getX();
        double y0 = basePoint.getY();
        double z0 = basePoint.getZ();

        // 8 вершин параллелепипеда
        vertices.push_back(Point(x0, y0, z0));           // 0
        vertices.push_back(Point(x0 + a, y0, z0));       // 1
        vertices.push_back(Point(x0, y0 + b, z0));       // 2
        vertices.push_back(Point(x0 + a, y0 + b, z0));   // 3
        vertices.push_back(Point(x0, y0, z0 + c));       // 4
        vertices.push_back(Point(x0 + a, y0, z0 + c));   // 5
        vertices.push_back(Point(x0, y0 + b, z0 + c));   // 6
        vertices.push_back(Point(x0 + a, y0 + b, z0 + c)); // 7
    }

    bool Parallelepiped::isValidParallelepiped() const {
        if (vertices.size() != VERTEX_COUNT) {
            return false;
        }

        if (a <= 0 || b <= 0 || c <= 0) {
            return false;
        }

        return true;
    }

    double Parallelepiped::getSurfaceArea() const {
        // Поверхность параллелепипеда: 2(ab + bc + ac)
        return 2.0 * (a * b + b * c + a * c);
    }

    double Parallelepiped::getVolume() const {
        // Объем параллелепипеда: abc
        return a * b * c;
    }

    std::string Parallelepiped::ToString() const {
        std::stringstream ss;
        ss << "Parallelepiped: ";
        ss << "a=" << a << ", b=" << b << ", c=" << c;
        ss << ", SurfaceArea=" << getSurfaceArea();
        ss << ", Volume=" << getVolume();
        ss << ", Vertices: ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            ss << "v" << (i + 1) << "=" << vertices[i];
            if (i < vertices.size() - 1) {
                ss << ", ";
            }
        }
        return ss.str();
    }

    void Parallelepiped::read(std::istream& is) {
        double x, y, z;
        double sideA, sideB, sideC;

        char bracket, comma1, comma2;
        is >> bracket >> x >> comma1 >> y >> comma2 >> z >> bracket;
        is >> sideA >> sideB >> sideC;

        if (sideA <= 0 || sideB <= 0 || sideC <= 0) {
            throw std::invalid_argument("Стороны параллелепипеда должны быть положительными числами");
        }

        Point basePoint(x, y, z);
        a = sideA;
        b = sideB;
        c = sideC;

        calculateVertices(basePoint);

        if (!isValidParallelepiped()) {
            throw std::invalid_argument("Некорректные параметры параллелепипеда при чтении");
        }
    }

    bool Parallelepiped::operator==(const Parallelepiped& other) const {
        if (vertices.size() != other.vertices.size()) {
            return false;
        }

        for (size_t i = 0; i < vertices.size(); ++i) {
            if (vertices[i] != other.vertices[i]) {
                return false;
            }
        }
        return true;
    }

    bool Parallelepiped::operator!=(const Parallelepiped& other) const {
        return !(*this == other);
    }

    std::vector<Point> Parallelepiped::getVertices() const {
        return vertices;
    }

    double Parallelepiped::getSideA() const {
        return a;
    }

    double Parallelepiped::getSideB() const {
        return b;
    }

    double Parallelepiped::getSideC() const {
        return c;
    }

    std::string Parallelepiped::ToString(const Parallelepiped& parallelepiped) {
        return parallelepiped.ToString();
    }

    Parallelepiped Parallelepiped::readFromStream(std::istream& is) {
        Parallelepiped parallelepiped;
        parallelepiped.read(is);
        return parallelepiped;
    }
}
