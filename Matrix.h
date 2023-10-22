#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#define CHUNK_SIZE 3

_Mutex _Coroutine Matrix {
    private:
    float **gridR, **gridI, **gridW;
    float imag, real, weight;
    int i, j;
    int N;
    void main();


    public:
    Matrix(int N);
    ~Matrix();
    void add(int i,int j,float r,float im,float w);
    void plusMatrix(float **gridR, float **gridI, float **gridW);
    void normalize();

    float getReal(int i, int j);
    float getImaginary(int i, int j);
    int getN();
};

#endif