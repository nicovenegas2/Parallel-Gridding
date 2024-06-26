#include <iostream>
#include <fstream>
#include <string>
#include "Lecture.h"
using namespace std;

Lecture::Lecture(string filename, int chunkSize) : chunkSize(chunkSize) {
    file.open(filename.c_str(), ios::in);
    if (file.is_open()) {
        cout << "File opened successfully" << endl;
    }
    else {
        cout << "Unable to open file";
    }
}


void Lecture::main() {
    string line;
    int channel;
    file.open("Lecture.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (!file.eof()) {
                content += line;
                countLines++;
            }
            if(countLines < chunkSize)
                content += "\n";
            if(countLines == chunkSize || file.eof()){
                suspend();
                countLines = 0;
                content = "";
            }
        }
        suspend();
        file.close();
    }
    else {
        cout << "Unable to open file";
    }
}

string Lecture::read(){
    resume();
    return Lecture::content;
}

void Lecture::write(string filename, Matrix &matrix){
    string fileRealName = filename + "R.csv";
    string fileImaginaryName = filename + "I.csv";
    ofstream file;
    file.open(fileRealName.c_str());
    for(int i = 0; i < matrix.getN(); i++){
        for(int j = 0; j < matrix.getN(); j++){
            file << matrix.getReal(i, j) << ",";
        }
        file << "\n";
    }
    file.close();
    file.open(fileImaginaryName.c_str());
    for(int i = 0; i < matrix.getN(); i++){
        for(int j = 0; j < matrix.getN(); j++){
            file << matrix.getImaginary(i, j) << ",";
        }
        file << "\n";
    }
    file.close();
}

bool Lecture::canRead(){
    return !file.eof();
}

Lecture::~Lecture(){
    file.close();
}