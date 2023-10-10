#ifndef GRIDTASKV2_H
#define GRIDTASKV2_H

#include <string>
#include <fstream>
#include <iostream>
#include "Lecture.h"
#include "Matrix.h"
#include <sstream>
#include <cmath>
using namespace std;

#define SPEED_LIGHT 300000000

_Task GridTaskV2 {
    Lecture &lecture;
    Matrix &matrix;
    float deltaU;
    int N;
    string content = "";
    void main();

    public:
    GridTaskV2(Lecture &lecture, Matrix &matrix, float deltaX, int N);
    int getN();
    string getContent();
};



#endif