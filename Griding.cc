#include <iostream>
#include "Lecture.h"
using namespace std;

void uMain::main(){
    Lecture lecture;
    string lines;

    lines = lecture.read();
    cout << lines << endl;

    lines = lecture.read();
    cout << lines << endl;


    exit(0);
}