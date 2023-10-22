#ifndef LECTURE_H
#define LECTURE_H

#include <string>
#include <fstream>
#include <iostream>
#include "Matrix.h"
#include <uC++.h>
using namespace std;


_Mutex _Coroutine Lecture {
    private:
    int countLines = 0;
    int chunkSize = CHUNK_SIZE;
    string content = "";
    fstream file;
    void main();


    public:
    Lecture();
    Lecture(string filename, int chunkSize);
    ~Lecture();
    string read();
    _Nomutex bool canRead();
    void write(string filename, Matrix &matrix);
};

#endif