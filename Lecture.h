#ifndef LECTURE_H
#define LECTURE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#define CHUNK_SIZE 5

_Mutex _Coroutine Lecture {
    private:
    int countLines = 0;
    int chunkSize = CHUNK_SIZE;
    string content = "";
    void main();
    public:
    string read();
};

#endif