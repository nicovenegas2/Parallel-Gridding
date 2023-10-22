#include "Matrix.h"

Matrix::Matrix(int N){
    this->N = N;
    gridR = new float*[N];
    gridI = new float*[N];
    gridW = new float*[N];
    for (int i = 0; i < N; i++){
        gridR[i] = new float[N];
        gridI[i] = new float[N];
        gridW[i] = new float[N];

        for (int j = 0; j < N; j++){
            gridR[i][j] = 0;
            gridI[i][j] = 0;
            gridW[i][j] = 0;
        }
    }
}


Matrix::~Matrix(){
    for (int i = 0; i < N; i++){
        delete gridR[i];
        delete gridI[i];
        delete gridW[i];
    }
    delete gridR;
    delete gridI;
    delete gridW;
}

void Matrix::main(){
    // Sumar a las grillas
    for(;;){
        _Accept(~Matrix){
            break;
        } _Else {
            // check if in correct range
            if ((i >= 0) && (i < N) && (j = 0) && (j < N)){
                gridR[i][j] += real * weight;
                gridI[i][j] += imag * weight;
                gridW[i][j] += weight;
            }
            suspend();
        }
    }
}


void Matrix::add(int i, int j, float r, float im, float w){
    this->i = i;
    this->j = j;
    imag = im;
    real = r;
    weight = w;
    resume();
}

void Matrix::plusMatrix(float **gridR, float **gridI, float **gridW){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            this->gridR[i][j] += gridR[i][j];
            this->gridI[i][j] += gridI[i][j];
            this->gridW[i][j] += gridW[i][j];
        }
    }
}

void Matrix::normalize(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(gridW[i][j] == 0){
                continue;
            }

            gridR[i][j] = gridR[i][j] / gridW[i][j];
            gridI[i][j] = gridI[i][j] / gridW[i][j];
        }
    }
}


float Matrix::getReal(int i, int j){
    return gridR[i][j];
}

float Matrix::getImaginary(int i, int j){
    return gridI[i][j];
}

int Matrix::getN(){
    return N;
}