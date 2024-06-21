#ifndef LSTMLAYER_H
#define LSTMLAYER_H

#include "ineuralnetworklayer.h"

class LSTMLayer : public INeuralNetworkLayer
{
private:
    int _hiddenSize;
    int _outputSize;
    int _vocabSize;
    double _weightScale; // точность весов
    Matrix2d<double> _startH; // стартовое состояние слоя
    Matrix2d<double> _startC; // стартовое состояние ячейки/узла
    bool _firstStep; // флаг начальной реализации
    QList<LSTMNode> _cells; // ячейки с нейронными узлами
    QMap<QString, QMap<QString, Matrix2d<double>>> _params;

public:
    LSTMLayer(int hiddenSize, int outputSize, double weightScale = 0.01);

public:
    // INeuralNetworkLayer interface
    void initParams(const Matrix3d<double> initMatrix) override;
    void clearGradients() override;
    Matrix3d<double> forward(Matrix3d<double> xSequenceIn) override;
    Matrix3d<double> backward(Matrix3d<double> xSequenceOutGrad) override;
    //

};

#endif // LSTMLAYER_H