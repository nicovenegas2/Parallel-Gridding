#ifndef GRIDTASKV1_H
#define GRIDTASKV1_H

#include <string>
#include <fstream>
#include <iostream>
#include "Lecture.h"
#include "Matrix.h"
#include <sstream>
#include <cmath>
using namespace std;

#define SPEED_LIGHT 300000000

_Task GridTaskV1 {
    Lecture &lecture;
    Matrix &matrix;
    float deltaU;
    int N;
    float** gridR, **gridI, **gridW;
    string content = "";
    void main();

    public:
    GridTaskV1(Lecture &lecture, Matrix &matrix, float deltaX, int N);
    void printGrid();
    int getN();
    string getContent();
};



#endif