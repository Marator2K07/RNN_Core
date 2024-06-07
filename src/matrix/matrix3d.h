#ifndef MATRIX3D_H
#define MATRIX3D_H

#include "matrix2d.h"

///
/// \brief The Matrix3d class
/// частный случай - трехмерная матрица
/// важное замечание, данный класс является
/// надстройкой над классом Matrix2d
template<typename T>
class Matrix3d : public IMatrix<T>
{
private:
    vector<Matrix2d<T>> _data;

public:
    Matrix3d();
    Matrix3d(QVariant data);
    Matrix3d(vector<Matrix2d<T>> data);
    Matrix3d(initializer_list<initializer_list<initializer_list<T>>> list);

public:
    void print();
    bool operator==(Matrix3d<T> &other);

    // IMatrix interface
    QVariant data() const override;
    vector<int> sizes() const override;
    bool sameShape(const IMatrix<T> *other) override;
    std::unique_ptr<IMatrix<T>> addition(const IMatrix<T> *other) override;
};

#endif // MATRIX3D_H
