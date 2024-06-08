#include <QObject>
#include <QtTest/QtTest>

#include "matrix2d.h"
#include "matrix2d.cpp"
#include "matrix3d.h"
#include "matrix3d.cpp"

class TestMatrix: public QObject
{
    Q_OBJECT

private slots:
    ///
    /// \brief testMatrix2dSameShapeMatrix3d
    /// попытка сломать код, сравнивая матрицы с разными измерениями
    void testMatrix2dSameShapeMatrix3d();
    ///
    /// \brief testMatrix2dSameShapeMatrix2d
    /// тест на полное соотвествие 2d матриц по размерам
    void testMatrix2dSameShapeMatrix2d();
    ///
    /// \brief testMatrix3dSameShapeMatrix3d
    /// тест на полное соотвествие 3d матриц по размерам
    void testMatrix3dSameShapeMatrix3d();
    ///
    /// \brief testMatrix2dAddMatrix2d
    /// тест на сложение двумерных матриц
    void testMatrix2dAddMatrix2d();
    ///
    /// \brief testMatrix3dAddMatrix3d
    /// тест на сложение трехмерных матриц
    void testMatrix3dAddMatrix3d();
    ///
    /// \brief testMatrix2dAddNum
    /// тест на простое сложение матрицы с числом
    void testMatrix2dAddNum();
    ///
    /// \brief testMatrix3dAddNum
    /// тест на сложение 3д матрицы и числа
    void testMatrix3dAddNum();
    ///
    /// \brief testMatrix2dSubtrMatrix2d
    /// тест разности матриц
    void testMatrix2dSubtrMatrix2d();
    ///
    /// \brief testMatrix3dSubtrMatrix3d
    /// тест разности трехмерных матриц
    void testMatrix3dSubtrMatrix3d();
    ///
    /// \brief testMatrix2dSubtrNumReverseAndDirectOrder
    /// тест разности матрицы и числа, числа и матрицы
    void testMatrix2dSubtrNumDirectAndReverseOrder();
    ///
    /// \brief testMatrix3dSubtrNumDirectAndReverseOrder
    /// тест разности 3d матрицы и числа, числа и матрицы 3d
    void testMatrix3dSubtrNumDirectAndReverseOrder();
    ///
    /// \brief testMatrix2dSimplMultMatrix2d
    /// тест упрощенного поэлеметного умножения матриц
    void testMatrix2dSimplMultMatrix2d();
    ///
    /// \brief testMatrix3dSimplMultMatrix3d
    /// тест упрощенного поэлеметного умножения трехмерных матриц
    void testMatrix3dSimplMultMatrix3d();
    ///
    /// \brief testMatrix2dMultNumber
    /// умножение матрицы на число
    void testMatrix2dMultNumber();
    ///
    /// \brief testMatrix3dMultNumber
    /// тест умножения трехмерной матрицы на число
    void testMatrix3dMultNumber();
    ///
    /// \brief testFloorMatrix2dAndMatrix3d
    /// тест округления 2д и 3д матриц
    void testFloorMatrix2dAndMatrix3d();
    ///
    /// \brief testMatrix2dAndMatrix3dClip
    /// тестирование обрезки 3д и 2д матриц по границам
    void testMatrix2dAndMatrix3dClip();
    ///
    /// \brief testMatrix2dAndMatrix3dLogn
    /// тестирование нахождение матриц с алгоритмами их элементов
    void testMatrix2dAndMatrix3dLogn();
    ///
    /// \brief testMatrix2dAnd3dTotalSum
    /// тестовое нахождение всех элементов 2д и 3д матриц
    void testMatrix2dAnd3dTotalSum();

    ///
    /// \brief testMatrix2dCanMultMatrix2d
    /// тест на возможность перемножения матриц
    void testMatrix2dCanMultMatrix2d();    
    ///
    /// \brief test1Matrix2dMultMatrix2d
    /// первое тестовое матричное умножение
    void test1Matrix2dMultMatrix2d();
    ///
    /// \brief test2Matrix2dMultMatrix2d
    /// усложенная версия матричного умножения
    void test2Matrix2dMultMatrix2d();
    ///
    /// \brief test3Matrix2dMultMatrix2d
    /// версия для плохого случая матричного умножения
    void test3Matrix2dMultMatrix2d();
};

void TestMatrix::testMatrix2dSameShapeMatrix3d()
{
    // инициализация
    Matrix2d<double> matrix2d{{1,2,3},
                              {4,7,7},
                              {9,3,0}};
    Matrix3d<double> matrix3d{{{2,7,7},
                               {4,1,1},
                               {2,3,5}},
                              {{2,7,7},
                               {4,1,1},
                               {2,3,5}}};
    // результаты
    try {
        // matrix3d.sameShape(&matrix2d);
        // matrix2d.sameShape(&matrix3d);
    } catch (const MatrixException &e) {
        cout << e.what() << endl;
    }
}

void TestMatrix::testMatrix2dSameShapeMatrix2d()
{
    // инициализация
    Matrix2d<double> matrixA {{1,2,3},
                             {4,7,7},
                             {9,3,0}};
    Matrix2d<double> matrixB {{6,2,3},
                             {2,2,0},
                             {6,1,7}};
    Matrix2d<double> matrixC {{1,1,1},
                             {2,2,2}};
    // результаты
    bool resultFlag1 = matrixA.sameShape(&matrixB);
    bool resultFlag2 = matrixB.sameShape(&matrixC);

    QCOMPARE(resultFlag1, true);
    QCOMPARE(resultFlag2, false);
}

void TestMatrix::testMatrix3dSameShapeMatrix3d()
{
    // инициализация
    Matrix3d<double> matrixA {{{1,2,3}, {4,7,7}, {9,3,0}},
                              {{1,2,3}, {4,7,7}, {9,3,0}},
                              {{1,2,3}, {4,7,7}, {9,3,0}}};
    Matrix3d<double> matrixB {{{1,2,3}, {4,7,7}, {9,3,0}},
                              {{1,2,3}, {4,7,7}, {9,3,0}},
                              {{1,2,3}, {4,7,7}, {9,3,0}}};
    Matrix3d<double> matrixC {{{1,2,3}, {4,7,7}, {9,3,0}},
                              {{1,2,3}, {4,7,7}, {9,3,0}}};
    Matrix3d<double> matrixD {{{1,2,3}, {4,7,7}},
                              {{1,2,3}, {4,7,7}},
                              {{1,2,3}, {4,7,7}}};
    // результаты
    bool resultFlag1 = matrixA.sameShape(&matrixB);
    bool resultFlag2 = matrixB.sameShape(&matrixC);
    bool resultFlag3 = matrixB.sameShape(&matrixC);
    bool resultFlag4 = matrixA.sameShape(&matrixD);

    QCOMPARE(resultFlag1, true);
    QCOMPARE(resultFlag2, false);
    QCOMPARE(resultFlag3, false);
    QCOMPARE(resultFlag4, false);
}

void TestMatrix::testMatrix2dAddMatrix2d()
{
    // инициализация
    Matrix2d<double> matrixA {{1,2,3},
                             {4,7,7},
                             {9,3,0}};
    Matrix2d<double> matrixB {{6,2,3},
                             {2,2,0},
                             {6,1,7}};
    Matrix2d<double> matrixD {{1,2,3},
                             {4,7,7},
                             {9,3,0}};
    Matrix2d<double> matrixC {{6,2,3},
                             {2,2,0}};

    QCOMPARE(matrixA == matrixD, true);
    QCOMPARE(matrixA == matrixB, false);

    // плохой случай
    try {
        auto resultMatrix2 = matrixA.addition(&matrixC);
    } catch (const MatrixException &e) {
        cout << e.what() << endl;
    }
    // нормальный случай
    auto resultMatrix = matrixA.addition(&matrixB);
    Matrix2d<double> properMatrix {{7,4,6},
                                  {6,9,7},
                                  {15,4,7}};

    QCOMPARE(resultMatrix->data(), properMatrix.data());
}

void TestMatrix::testMatrix3dAddMatrix3d()
{
    qRegisterMetaType<Matrix2d<double>>();
    // инициализация
    Matrix3d<double> matrixA {{{1,2,3}, {1,2,8}, {1,5,1}},
                             {{1,1,5}, {3,1,4}, {1,1,4}},
                             {{7,7,7}, {1,1,1}, {1,1,1}}};
    Matrix3d<double> matrixB {{{1,1,1}, {1,3,0}, {1,1,3}},
                             {{1,8,6}, {1,1,1}, {11,1,1}},
                             {{1,1,1}, {1,1,1}, {1,7,2}}};
    Matrix3d<double> matrixC {{{1,2,3}, {4,7,7}, {9,3,0}},
                             {{1,2,3}, {4,7,7}, {9,3,0}}};
    // плохой случай
    try {
        auto resultMatrix2 = matrixB.addition(&matrixC);
    } catch (const MatrixException &e) {
        cout << e.what() << endl;
    }
    // нормальный случай
    Matrix3d<double> resultMatrix(matrixA.addition(&matrixB)->data());
    Matrix3d<double> properMatrix {{{2,3,4}, {2,5,8}, {2,6,4}},
                                  {{2,9,11}, {4,2,5}, {12,2,5}},
                                  {{8,8,8}, {2,2,2}, {2,8,3}}};

    QCOMPARE(resultMatrix == properMatrix, true);
}

void TestMatrix::testMatrix2dAddNum()
{
    // инициализация
    Matrix2d<double> matrixA {{1,2,3},
                             {4,7,7},
                             {9,3,0}};
    Matrix2d<double> matrixB {{6,2,3},
                             {2,2,0},
                             {6,1,7}};
    double numA = 3.33;
    double numB = 4.44;

    // результаты
    auto resultMatrix1 = matrixA.addition(numA);
    Matrix2d<double> properMatrix1 {{4.33,5.33,6.33},
                                   {7.33,10.33,10.33},
                                   {12.33,6.33,3.33}};
    auto resultMatrix2 = matrixB.addition(numB);
    Matrix2d<double> properMatrix2 {{7,4,6},
                                   {6,9,7},
                                   {15,4,7}};

    QCOMPARE(resultMatrix1->data() == properMatrix1.data(), true);
    QCOMPARE(resultMatrix2->data() == properMatrix2.data(), false);
}

void TestMatrix::testMatrix3dAddNum()
{
    // инициализация
    Matrix3d<double> matrixA {{{1,2,3}, {1,2,8}, {1,5,1}},
                             {{1,1,5}, {3,1,4}, {1,1,4}},
                             {{7,7,7}, {1,1,1}, {1,1,1}}};
    Matrix3d<double> matrixB {{{1,1,1}, {1,3,0}, {1,1,3}},
                             {{1,8,6}, {1,1,1}, {11,1,1}},
                             {{1,1,1}, {1,1,1}, {1,7,2}}};
    double numA = 3.33;
    double numB = 4.44;

    // результаты
    Matrix3d<double> resultMatrix1(matrixA.addition(numA)->data());
    Matrix3d<double> properMatrix1 {{{4.33,5.33,6.33},{4.33,5.33,11.33},{4.33,8.33,4.33}},
                                   {{4.33,4.33,8.33},{6.33,4.33,7.33},{4.33,4.33,7.33}},
                                   {{10.33,10.33,10.33},{4.33,4.33,4.33},{4.33,4.33,4.33}}};
    Matrix3d<double> resultMatrix2(matrixB.addition(numB)->data());
    Matrix3d<double> properMatrix2 {{{1,2,3}, {1,2,8}, {1,5,1}},
                                   {{1,1,5}, {3,1,4}, {1,1,4}},
                                   {{7,7,7}, {1,1,1}, {1,1,1}}};

    QCOMPARE(resultMatrix1 == properMatrix1, true);
    QCOMPARE(resultMatrix2 == properMatrix2, false);
}

void TestMatrix::testMatrix2dSubtrMatrix2d()
{
    // инициализация
    Matrix2d<double> matrixA {{1,2,3},
                             {4,7,7},
                             {9,3,0}};
    Matrix2d<double> matrixB {{6,2,3},
                             {2,2,0},
                             {6,1,7}};
    // результаты
    auto resultMatrix = matrixA.subtraction(&matrixB);
    Matrix2d<double> properMatrix {{-5,0,0},
                                  {2,5,7},
                                  {3,2,-7}};

    QCOMPARE(resultMatrix->data(), properMatrix.data());
}

void TestMatrix::testMatrix3dSubtrMatrix3d()
{
    qRegisterMetaType<Matrix2d<double>>();
    // инициализация
    Matrix3d<double> matrixA {{{1,2,3}, {1,2,8}, {1,5,1}},
                             {{1,1,5}, {3,1,4}, {1,1,4}},
                             {{7,7,6}, {1,1,1}, {1,1,1}}};
    Matrix3d<double> matrixB {{{1,1,1}, {1,3,0}, {1,1,3}},
                             {{1,8,6}, {1,1,1}, {11,1,1}},
                             {{1,1,1}, {1,1,1}, {1,7,2}}};
    // результаты
    Matrix3d<double> resultMatrix(matrixA.subtraction(&matrixB)->data());
    Matrix3d<double> properMatrix {{{0,1,2}, {0,-1,8}, {0,4,-2}},
                                  {{0,-7,-1}, {2,0,3}, {-10,0,3}},
                                  {{6,6,5}, {0,0,0}, {0,-6,-1}}};

    QCOMPARE(resultMatrix == properMatrix, true);
}

void TestMatrix::testMatrix2dSubtrNumDirectAndReverseOrder()
{
    // инициализация
    Matrix2d<double> matrix {{1,2,3},
                            {7,3,5},
                            {9,3,1}};
    // результаты
    auto resultMatrixDirect = matrix.subtraction(2);
    Matrix2d<double> properMatrixDirect {{-1,0,1},
                                        {5,1,3},
                                        {7,1,-1}};
    auto resultMatrixReverse = matrix.subtraction(2, true);
    Matrix2d<double> properMatrixReverse {{1,0,-1},
                                         {-5,-1,-3},
                                         {-7,-1,1}};

    QCOMPARE(resultMatrixDirect->data(), properMatrixDirect.data());
    QCOMPARE(resultMatrixReverse->data(), properMatrixReverse.data());
}

void TestMatrix::testMatrix3dSubtrNumDirectAndReverseOrder()
{
    // инициализация
    Matrix3d<double> matrixA {{{1,2,3}, {1,2,8}, {1,5,1}},
                             {{1,1,5}, {3,1,4}, {1,1,4}},
                             {{7,7,6}, {1,1,1}, {1,1,1}}};
    // результаты
    Matrix3d<double> resultMatrixDirect (matrixA.subtraction(5)->data());
    Matrix3d<double> properMatrixDirect {{{-4,-3,-2},{-4,-3,3},{-4,0,-4}},
                                        {{-4,-4,0},{-2,-4,-1},{-4,-4,-1}},
                                        {{2,2,1},{-4,-4,-4},{-4,-4,-4}}};
    Matrix3d<double> resultMatrixReverse (matrixA.subtraction(2.5, true)->data());
    Matrix3d<double> properMatrixReverse {{{1.5,0.5,-0.5},{1.5,0.5,-5.5},{1.5,-2.5,1.5}},
                                         {{1.5,1.5,-2.5},{-0.5,1.5,-1.5},{1.5,1.5,-1.5}},
                                         {{-4.5,-4.5,-3.5},{1.5,1.5,1.5},{1.5,1.5,1.5}}};

    QCOMPARE(resultMatrixDirect == properMatrixDirect, true);
    QCOMPARE(resultMatrixReverse == properMatrixReverse, true);
}

void TestMatrix::testMatrix2dSimplMultMatrix2d()
{
    // инициализация
    Matrix2d<double> matrixA {{1,2},
                             {3,9}};
    Matrix2d<double> matrixB {{7,4},
                             {2,6}};
    Matrix2d<double> matrixC {{1,6,2},
                             {3,2,2}};
    // плохой случай
    try {
        auto resultMatrix = matrixB.simplifiedMult(&matrixC);
    } catch (const MatrixException& e) {
        cout << e.what() << endl;
    }
    // результаты
    auto resultMatrixAB = matrixA.simplifiedMult(&matrixB);
    Matrix2d<double> properMatrixAB {{7,8},
                                    {6,54}};

    QCOMPARE(resultMatrixAB->data(), properMatrixAB.data());
}

void TestMatrix::testMatrix3dSimplMultMatrix3d()
{
    // инициализация
    Matrix3d<double> matrixA {{{1,2,3}, {1,2,8}},
                             {{8,5,5}, {3,1,4}},
                             {{7,7,6}, {1,1,1}}};
    Matrix3d<double> matrixB {{{3,5,3}, {1,3,0}},
                             {{1,8,6}, {0,3,1}},
                             {{1,2,3}, {2,2,8}}};
    // результаты
    Matrix3d<double> resultMatrix(matrixA.simplifiedMult(&matrixB)->data());
    Matrix3d<double> properMatrix {{{3,10,9},{1,6,0}},
                                  {{8,40,30},{0,3,4}},
                                  {{7,14,18},{2,2,8}}};

    QCOMPARE(resultMatrix == properMatrix, true);
}

void TestMatrix::testMatrix2dMultNumber()
{
    // инициализация
    Matrix2d<double> matrix {{1,2,3},
                            {7,3,5},
                            {9,3,1}};
    // результаты
    auto resultMatrix = matrix.multiplication(2.5);
    Matrix2d<double> properMatrix {{2.5,5,7.5},
                                  {17.5,7.5,12.5},
                                  {22.5,7.5,2.5}};

    QCOMPARE(resultMatrix->data(), properMatrix.data());
}

void TestMatrix::testMatrix3dMultNumber()
{
    // инициализация
    Matrix3d<double> matrix {{{1,2,3}, {1,2,8}},
                            {{8,5,5}, {3,1,4}},
                            {{7,7,6}, {1,1,1}}};
    // результаты
    Matrix3d<double> resultMatrix(matrix.multiplication(3.34)->data());
    Matrix3d<double> properMatrix {{{3.34,6.68,10.02},{3.34,6.68,26.72}},
                                  {{26.72,16.7,16.7},{10.02,3.34,13.36}},
                                  {{23.38,23.38,20.04},{3.34,3.34,3.34}}};

    QCOMPARE(resultMatrix == properMatrix, true);
}

void TestMatrix::testFloorMatrix2dAndMatrix3d()
{
    // инициализация
    Matrix3d<double> matrix3d {{{1.5346,2.7651,3.8931},{1.1111,2.6957,8.5894}},
                              {{8.9888,5.5555,5.5555},{3.5894,1.2352,4.4567}},
                              {{7.7777,7.7777,6.5352},{1.1234,1.5654,1.5657}}};
    Matrix2d<double> matrix2d {{1.5365,2.2345,3.6767},
                              {7.7777,3.3333,5.5555},
                              {9.8888,3.3676,1.1111}};
    // результаты
    matrix3d.floorM(3);
    matrix2d.floorM(3);
    Matrix3d<double> properMatrix3d {{{1.534,2.765,3.893},{1.111,2.695,8.589}},
                                    {{8.988,5.555,5.555},{3.589,1.235,4.456}},
                                    {{7.777,7.777,6.535},{1.123,1.565,1.565}}};
    Matrix2d<double> properMatrix2d {{1.536,2.234,3.676},
                                    {7.777,3.333,5.555},
                                    {9.888,3.367,1.111}};

    QCOMPARE(matrix3d == properMatrix3d, true);
    QCOMPARE(matrix2d == properMatrix2d, true);
}

void TestMatrix::testMatrix2dAndMatrix3dClip()
{
    // инициализация
    Matrix2d<double> matrix2d {{1,0.42,0.22},
                              {0.642,0.33,0}};
    Matrix3d<double> matrix3d {{{1,0.42,0.22},{0.642,0.33,0}},
                              {{1,0.42,0.22},{0.642,0.33,0}}};
    double leftBorder = 1e-9;
    double rightBorder = 1-leftBorder;
    // результаты
    auto resultMatrix2d = matrix2d.clipM(leftBorder,rightBorder);
    resultMatrix2d->floorM(9); // 'совпадает' с 1e-9
    Matrix2d<double> properMatrix2dReal(resultMatrix2d->data());
    Matrix2d<double> properMatrix2d {{1-(1e-9),0.42,0.22},
                                    {0.642,0.33,1e-9}};
    auto resultMatrix3d = matrix3d.clipM(leftBorder,rightBorder);
    resultMatrix3d->floorM(9); // 'совпадает' с 1e-9
    Matrix3d<double> properMatrix3dReal(resultMatrix3d->data());
    Matrix3d<double> properMatrix3d {{{1-(1e-9),0.42,0.22}, {0.642,0.33,1e-9}},
                                    {{1-(1e-9),0.42,0.22}, {0.642,0.33,1e-9}}};

    QCOMPARE(properMatrix2dReal == properMatrix2d, true);
    QCOMPARE(properMatrix3dReal == properMatrix3d, true);
}

void TestMatrix::testMatrix2dAndMatrix3dLogn()
{
    // инициализация
    Matrix2d<double> matrix {{0.33,0.12,0.777},
                            {0.642,0.33,0.123}};
    Matrix3d<double> matrix3d {{{0.955,0.42,0.22},{0.642,0.33,0.111}},
                              {{0.343,0.42,0.22},{0.642,0.33,0.111}}};
    // результаты
    auto matrixResult2d = matrix.lognM();
    matrixResult2d->floorM(3); // округляем для сравнения
    Matrix2d<double> properMatrix2d {{-1.109,-2.121,-0.253},
                                    {-0.444,-1.109,-2.096}};

    auto resultMatrix3d = matrix3d.lognM();
    resultMatrix3d->floorM(3); // округляем для сравнения
    Matrix3d<double> properMatrix3dReal(resultMatrix3d->data());
    properMatrix3dReal.print();
    Matrix3d<double> properMatrix3d {{{-0.047,-0.868,-1.515},{-0.444,-1.109,-2.199}},
                                    {{-1.071,-0.868,-1.515},{-0.444,-1.109,-2.199}}};

    QCOMPARE(matrixResult2d->data(), properMatrix2d.data());
    QCOMPARE(properMatrix3dReal == properMatrix3d, true);
}

void TestMatrix::testMatrix2dAnd3dTotalSum()
{
    // инициализация
    Matrix2d<double> matrix {{0.33,0.12,0.777},
                            {0.642,0.33,0.123}};
    Matrix3d<double> matrix3d {{{0.955,0.42,0.22},{0.642,0.33,0.111}},
                              {{0.343,0.42,0.22},{0.642,0.33,0.111}}};
    // результаты
    double resultSum2d = matrix.totalSum();
    double properSum2d = 2.322;
    double resultSum3d = matrix3d.totalSum();
    double properSum3d = 4.744;

    QCOMPARE(resultSum2d, properSum2d);
    QCOMPARE(resultSum3d, properSum3d);
}

void TestMatrix::testMatrix2dCanMultMatrix2d()
{
    // инициализация
    vector<vector<double>> matrixA {{1,2},
                                    {4,7},
                                    {9,3}};
    vector<vector<double>> matrixB {{6,2,3,7},
                                    {2,2,0,1}};
    vector<vector<double>> matrixC {{1,1,1},
                                    {2,2,2},
                                    {3,3,3}};
    // итоговые результаты
    bool resultFlag1
        = Matrix2d<double>::canMult(matrixA, matrixB);
    bool resultFlag2
        = Matrix2d<double>::canMult(matrixA, matrixC);

    QCOMPARE(resultFlag1, true);
    QCOMPARE(resultFlag2, false);
}

void TestMatrix::test1Matrix2dMultMatrix2d()
{
    // инициализация
    vector<vector<double>> matrixA {{1,2,3},
                                    {3,4,5},
                                    {6,8,2}};
    vector<vector<double>> matrixB {{1,6,2},
                                    {3,2,2},
                                    {2,2,8}};
    // итоговый и ожидаемый результаты
    vector<vector<double>> resultMatrix
        = Matrix2d<double>::multiplication(matrixA, matrixB);
    vector<vector<double>> properMatrix {{13,16,30},
                                         {25,36,54},
                                         {34,56,44}};

    QCOMPARE(resultMatrix, properMatrix);
}

void TestMatrix::test2Matrix2dMultMatrix2d()
{
    // инициализация
    vector<vector<double>> matrixA {{1,2},
                                    {3,4},
                                    {7,7},
                                    {9,3}};
    vector<vector<double>> matrixB {{1,6,2},
                                    {3,2,2}};
    // итоговый и ожидаемый результаты
    vector<vector<double>> resultMatrix
        = Matrix2d<double>::multiplication(matrixA, matrixB);
    vector<vector<double>> properMatrix {{7,10,6},
                                         {15,26,14},
                                         {28,56,28},
                                         {18,60,24}};

    QCOMPARE(resultMatrix, properMatrix);
}

void TestMatrix::test3Matrix2dMultMatrix2d()
{
    // инициализация
    vector<vector<double>> matrixA {{1},
                                    {3}};
    vector<vector<double>> matrixB {{1,6,2},
                                    {3,2,2}};
    // результаты
    try {
        vector<vector<double>> resultMatrix
            = Matrix2d<double>::multiplication(matrixA, matrixB);

        // Т.к. код до сюда не дойдет, тест будет пройден
        QCOMPARE(resultMatrix, matrixB);
    } catch (const MatrixException& e) {
        e.what();
    }
}

QTEST_MAIN(TestMatrix)
#include "testmatrix.moc"
