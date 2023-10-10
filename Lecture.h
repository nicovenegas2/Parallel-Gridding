#ifndef LECTURE_H
#define LECTURE_H

#include <string>
#include <fstream>
#include <iostream>
#include "Matrix.h"
using namespace std;

#define CHUNK_SIZE 3

_Mutex _Coroutine Lecture {
    private:
    int countLines = 0;
    int chunkSize = CHUNK_SIZE;
    string content = "";
    fstream file;
    void main();


    public:
    Lecture();
    Lecture(string filename);
    ~Lecture();
    string read();
    bool canRead();
    void write(string filename, Matrix &matrix);
};

#endif