#include "CppUnitTest.h"
#include "../ParallelepipedLib/Parallelepiped.h"
#include "../ParallelepipedLib/Point.h"
#include <sstream>
#include <cmath>
#include <memory>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace geometry;

namespace Tests
{
    TEST_CLASS(PointTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(DefaultConstructor_Success)
        {
            // Arrange & Act
            Point p;

            // Assert
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
            Assert::AreEqual(0.0, p.getZ());
        }

        // 2. Тест конструктора с параметрами
        TEST_METHOD(ParameterizedConstructor_Success)
        {
            // Arrange
            double x = 3.5;
            double y = 7.2;
            double z = 1.8;

            // Act
            Point p(x, y, z);

            // Assert
            Assert::AreEqual(x, p.getX());
            Assert::AreEqual(y, p.getY());
            Assert::AreEqual(z, p.getZ());
        }

        // 3. Тест метода distanceTo
        TEST_METHOD(DistanceTo_Success)
        {
            // Arrange
            Point p1(0, 0, 0);
            Point p2(3, 4, 0);
            double expected1 = 5.0;

            Point p3(1, 2, 2);
            Point p4(4, 6, 10);
            double expected2 = std::sqrt(89.0);

            // Act
            double dist1 = p1.distanceTo(p2);
            double dist2 = p3.distanceTo(p4);

            // Assert
            Assert::AreEqual(expected1, dist1, 1e-6);
            Assert::AreEqual(expected2, dist2, 1e-6);
        }

        // 4. Тест оператора ==
        TEST_METHOD(EqualityOperator_Success)
        {
            // Arrange
            Point p1(2.5, 3.5, 4.5);
            Point p2(2.5, 3.5, 4.5);
            Point p3(2.5, 4.0, 4.5);

            // Act & Assert
            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        // 5. Тест оператора !=
        TEST_METHOD(InequalityOperator_Success)
        {
            // Arrange
            Point p1(2.5, 3.5, 4.5);
            Point p2(2.5, 3.5, 4.5);
            Point p3(2.5, 4.0, 4.5);

            // Act & Assert
            Assert::IsFalse(p1 != p2);
            Assert::IsTrue(p1 != p3);
        }

        // 6. Тест оператора вывода <<
        TEST_METHOD(OutputStreamOperator_Success)
        {
            // Arrange
            Point p(3.14, 2.71, 1.41);
            std::stringstream ss;

            // Act
            ss << p;
            std::string result = ss.str();

            // Assert
            Assert::IsTrue(result.find("(") != std::string::npos);
            Assert::IsTrue(result.find(")") != std::string::npos);
        }

        // 7. Тест оператора ввода >>
        TEST_METHOD(InputStreamOperator_Success)
        {
            // Arrange
            Point p;
            std::stringstream ss("(15.5, 20.3, 25.7)");
            double expectedX = 15.5;
            double expectedY = 20.3;
            double expectedZ = 25.7;

            // Act
            ss >> p;

            // Assert
            Assert::AreEqual(expectedX, p.getX());
            Assert::AreEqual(expectedY, p.getY());
            Assert::AreEqual(expectedZ, p.getZ());
        }
    };

    TEST_CLASS(ParallelepipedTests)
    {
    public:
        // 8. Тест конструктора по умолчанию
        TEST_METHOD(DefaultConstructor_Success)
        {
            // Arrange & Act
            Parallelepiped p;

            // Assert
            Assert::IsTrue(true);
        }

        // 9. Тест конструктора с вершиной и сторонами
        TEST_METHOD(ConstructorWithBaseAndSides_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            double a = 2.0;
            double b = 3.0;
            double c = 4.0;
            double expectedSurface = 2.0 * (a * b + b * c + a * c);
            double expectedVolume = a * b * c;

            // Act
            Parallelepiped p(basePoint, a, b, c);

            // Assert
            Assert::AreEqual(expectedSurface, p.getSurfaceArea(), 1e-6);
            Assert::AreEqual(expectedVolume, p.getVolume(), 1e-6);
        }

        // 10. Тест конструктора с диагональю
        TEST_METHOD(ConstructorWithDiagonal_Success)
        {
            // Arrange
            Point diagonalStart(0, 0, 0);
            Point diagonalEnd(3, 4, 5);
            double expectedSurface = 2.0 * (3 * 4 + 4 * 5 + 3 * 5);
            double expectedVolume = 3 * 4 * 5;

            // Act
            Parallelepiped p(diagonalStart, diagonalEnd);

            // Assert
            Assert::AreEqual(expectedSurface, p.getSurfaceArea(), 1e-6);
            Assert::AreEqual(expectedVolume, p.getVolume(), 1e-6);
        }

        // 11. Тест конструктора копирования
        TEST_METHOD(CopyConstructor_Success)
        {
            // Arrange
            Point basePoint(1, 2, 3);
            Parallelepiped original(basePoint, 2.0, 3.0, 4.0);

            // Act
            Parallelepiped copy(original);

            // Assert
            Assert::IsTrue(original == copy);
        }

        // 12. Тест оператора присваивания
        TEST_METHOD(AssignmentOperator_Success)
        {
            // Arrange
            Point basePoint(1, 2, 3);
            Parallelepiped original(basePoint, 2.0, 3.0, 4.0);
            Parallelepiped assigned;

            // Act
            assigned = original;

            // Assert
            Assert::IsTrue(original == assigned);
        }

        // 13. Тест оператора ==
        TEST_METHOD(EqualityOperator_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            Parallelepiped p1(basePoint, 2.0, 3.0, 4.0);
            Parallelepiped p2(basePoint, 2.0, 3.0, 4.0);
            Parallelepiped p3(basePoint, 1.0, 2.0, 3.0);

            // Act & Assert
            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        // 14. Тест оператора !=
        TEST_METHOD(InequalityOperator_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            Parallelepiped p1(basePoint, 2.0, 3.0, 4.0);
            Parallelepiped p2(basePoint, 2.0, 3.0, 4.0);
            Parallelepiped p3(basePoint, 1.0, 2.0, 3.0);

            // Act & Assert
            Assert::IsFalse(p1 != p2);
            Assert::IsTrue(p1 != p3);
        }

        // 15. Тест getSurfaceArea
        TEST_METHOD(GetSurfaceArea_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            Parallelepiped p(basePoint, 2.0, 3.0, 4.0);
            double expected = 2.0 * (2 * 3 + 3 * 4 + 2 * 4);

            // Act
            double result = p.getSurfaceArea();

            // Assert
            Assert::AreEqual(expected, result, 1e-6);
        }

        // 16. Тест getVolume
        TEST_METHOD(GetVolume_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            Parallelepiped p(basePoint, 2.0, 3.0, 4.0);
            double expected = 2.0 * 3.0 * 4.0;

            // Act
            double result = p.getVolume();

            // Assert
            Assert::AreEqual(expected, result, 1e-6);
        }

        // 17. Тест метода ToString
        TEST_METHOD(ToString_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            Parallelepiped p(basePoint, 2.0, 3.0, 4.0);

            // Act
            std::string result = p.ToString();

            // Assert
            Assert::IsTrue(result.find("Parallelepiped") != std::string::npos);
            Assert::IsTrue(result.find("a=") != std::string::npos);
            Assert::IsTrue(result.find("b=") != std::string::npos);
            Assert::IsTrue(result.find("c=") != std::string::npos);
        }

        // 18. Тест отрицательной стороны (исключение)
        TEST_METHOD(NegativeSide_ThrowsException)
        {
            // Act
            auto func = []() {
                Point basePoint(0, 0, 0);
                Parallelepiped p(basePoint, -1.0, 3.0, 4.0);
                };

            // Assert
            Assert::ExpectException<std::invalid_argument>(func);
        }

        // 19. Тест нулевой стороны (исключение)
        TEST_METHOD(ZeroSide_ThrowsException)
        {
            // Act
            auto func = []() {
                Point basePoint(0, 0, 0);
                Parallelepiped p(basePoint, 0.0, 3.0, 4.0);
                };

            // Assert
            Assert::ExpectException<std::invalid_argument>(func);
        }

        // 20. Тест полиморфизма
        TEST_METHOD(Polymorphism_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            Parallelepiped p(basePoint, 2.0, 3.0, 4.0);
            double expectedSurface = 2.0 * (2 * 3 + 3 * 4 + 2 * 4);

            // Act
            RegularSolid* solid = &p;
            double result = solid->getSurfaceArea();

            // Assert
            Assert::AreEqual(expectedSurface, result, 1e-6);
        }

        // 21. Тест getVertices
        TEST_METHOD(GetVertices_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            Parallelepiped p(basePoint, 2.0, 3.0, 4.0);

            // Act
            std::vector<Point> verts = p.getVertices();

            // Assert
            Assert::AreEqual(size_t(8), verts.size());
        }

        // 22. Тест getSideA, getSideB, getSideC
        TEST_METHOD(GetSides_Success)
        {
            // Arrange
            Point basePoint(0, 0, 0);
            Parallelepiped p(basePoint, 5.0, 6.0, 7.0);

            // Act & Assert
            Assert::AreEqual(5.0, p.getSideA(), 1e-6);
            Assert::AreEqual(6.0, p.getSideB(), 1e-6);
            Assert::AreEqual(7.0, p.getSideC(), 1e-6);
        }
    };
}
