#include <iostream>
#include <fstream>
#include <string>
#include "Lecture.h"
using namespace std;

void Lecture::main() {
    fstream file;
    string line;
    int channel;
    file.open("Lecture.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            content += line;
            countLines++;
            if(countLines != chunkSize)
                content += "\n";
            if(countLines == chunkSize || file.eof()){
                suspend();
                countLines = 0;
                content = "";
            }

        }
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