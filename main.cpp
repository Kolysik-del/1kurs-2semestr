#include <iostream>
#include <vector>
#include <memory>
#include "Parallelepiped.h"
#include <clocale>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#endif

/**
* @brief точка входа в программу
* @return 0, если программа выполнена успешно
*/
int main(void) {
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "=== Демонстрация работы с классами RegularSolid и Parallelepiped ===\n\n";

        std::cout << "1. Создание параллелепипеда через три вершины:\n";
        geometry::Point p1(0, 0, 0);
        geometry::Point p2(3, 0, 0);
        geometry::Point p3(0, 4, 0);
        geometry::Parallelepiped parallelepiped1(p1, p2, p3);
        std::cout << "Параллелепипед 1: " << parallelepiped1 << "\n";
        std::cout << "Площадь поверхности: " << parallelepiped1.getSurfaceArea() << "\n";
        std::cout << "Объем: " << parallelepiped1.getVolume() << "\n\n";

        std::cout << "2. Создание параллелепипеда через вершину и стороны:\n";
        geometry::Point basePoint(1, 1, 1);
        geometry::Parallelepiped parallelepiped2(basePoint, 2.0, 3.0, 4.0);
        std::cout << "Параллелепипед 2: " << parallelepiped2 << "\n";
        std::cout << "Площадь поверхности: " << parallelepiped2.getSurfaceArea() << "\n";
        std::cout << "Объем: " << parallelepiped2.getVolume() << "\n\n";

        std::cout << "3. Создание параллелепипеда через две вершины диагонали:\n";
        geometry::Point diagonalStart(0, 0, 0);
        geometry::Point diagonalEnd(5, 6, 7);
        geometry::Parallelepiped parallelepiped3(diagonalStart, diagonalEnd);
        std::cout << "Параллелепипед 3: " << parallelepiped3 << "\n";
        std::cout << "Площадь поверхности: " << parallelepiped3.getSurfaceArea() << "\n";
        std::cout << "Объем: " << parallelepiped3.getVolume() << "\n\n";

        std::cout << "4. Коллекция объектов базового типа:\n";
        std::vector<std::unique_ptr<geometry::RegularSolid>> solids;
        solids.push_back(std::make_unique<geometry::Parallelepiped>(parallelepiped1));
        solids.push_back(std::make_unique<geometry::Parallelepiped>(parallelepiped2));
        solids.push_back(std::make_unique<geometry::Parallelepiped>(parallelepiped3));

        std::cout << "Итерация по коллекции:\n";
        for (size_t i = 0; i < solids.size(); ++i) {
            std::cout << "Объект " << (i + 1) << ": " << *solids[i] << "\n";
            std::cout << "  Площадь поверхности: " << solids[i]->getSurfaceArea() << "\n";
            std::cout << "  Объем: " << solids[i]->getVolume() << "\n\n";
        }

        std::cout << "5. Демонстрация операторов сравнения:\n";
        geometry::Parallelepiped parallelepiped4 = parallelepiped2;
        geometry::Parallelepiped parallelepiped5 = parallelepiped3;

        std::cout << "parallelepiped2 == parallelepiped4: " << (parallelepiped2 == parallelepiped4 ? "истина" : "ложь") << "\n";
        std::cout << "parallelepiped2 == parallelepiped3: " << (parallelepiped2 == parallelepiped5 ? "истина" : "ложь") << "\n";
        std::cout << "parallelepiped2 != parallelepiped3: " << (parallelepiped2 != parallelepiped5 ? "истина" : "ложь") << "\n\n";

        std::cout << "6. Демонстрация статического метода ToString:\n";
        std::cout << geometry::Parallelepiped::ToString(parallelepiped1) << "\n\n";

        std::cout << "7. Демонстрация конструктора копирования:\n";
        geometry::Parallelepiped parallelepiped6(parallelepiped1);
        std::cout << "Скопированный параллелепипед: " << parallelepiped6 << "\n\n";

        std::cout << "8. Демонстрация оператора присваивания:\n";
        geometry::Parallelepiped parallelepiped7;
        parallelepiped7 = parallelepiped1;
        std::cout << "Присвоенный параллелепипед: " << parallelepiped7 << "\n\n";

        std::cout << "9. Попытка создания некорректного параллелепипеда (ожидается исключение):\n";
        try {
            geometry::Parallelepiped invalidParallelepiped(basePoint, -1.0, 3.0, 4.0);
        }
        catch (const std::exception& e) {
            std::cout << "Исключение: " << e.what() << "\n";
        }

        std::cout << "\n10. Попытка создания параллелепипеда с нулевой стороной:\n";
        try {
            geometry::Parallelepiped invalidParallelepiped2(basePoint, 0.0, 3.0, 4.0);
        }
        catch (const std::exception& e) {
            std::cout << "Исключение: " << e.what() << "\n";
        }

        std::cout << "\n11. Получение вершин параллелепипеда:\n";
        std::vector<geometry::Point> verts = parallelepiped2.getVertices();
        for (size_t i = 0; i < verts.size(); ++i) {
            std::cout << "Вершина " << (i + 1) << ": " << verts[i] << "\n";
        }

        std::cout << "\n12. Получение длин сторон:\n";
        std::cout << "Сторона a: " << parallelepiped2.getSideA() << "\n";
        std::cout << "Сторона b: " << parallelepiped2.getSideB() << "\n";
        std::cout << "Сторона c: " << parallelepiped2.getSideC() << "\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nПрограмма завершена успешно.\n";
#ifdef _WIN32
    system("pause");
#endif
    return 0;
}
