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
class ActivationFunctions
{
public:
    ///
    /// \brief softmax многопеременная логистическая функция
    /// \param prediction вектор вероятностей(прогнозов)
    /// \return обработанный вектор
    static vector<double> softmax(const vector<double> prediction);
};

#endif // ACTIVATIONFUNCTIONS_H
