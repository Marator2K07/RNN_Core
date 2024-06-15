#ifndef ACTIVATIONFUNCTIONS_H
#define ACTIVATIONFUNCTIONS_H

#include <vector>
#include <cmath>

#include "imatrix.h"
#include "matrix2d.h"
#include "matrix3d.h"

using namespace std;

///
/// \brief The LossActivationFunctions class
/// для определения функций активации
template<typename T>
class ActivationFunctions
{
private:
    ///
    /// \brief softmaxRow нахождение softmax для строки(вектора) значений
    /// \param row входящий вектор значений
    /// \return обработанный softmax вектор
    static vector<double> softmaxRow(vector<T> row);

public:
    ///
    /// \brief sigmoid гладкая монотонная возрастающая нелинейная функция,
    /// имеющая форму буквы «S» для «сглаживания» значений некоторой величины.
    /// \param matrix матрица входящих значений для сглаживания
    /// \return результирующая матрица
    static unique_ptr<IMatrix<double>> sigmoid(IMatrix<T> *matrix);
    ///
    /// \brief softmax многопеременная логистическая функция,
    /// для "сглаживания" значений в пределах (от 0, до 1),
    /// при этом увеличивая примерное соотношения чисел между собой
    /// \param matrix матрица значений для преобразования
    /// \return обработанная softmax матрица
    static unique_ptr<IMatrix<double>> softmax(const IMatrix<T> *matrix);
};

#endif // ACTIVATIONFUNCTIONS_H
