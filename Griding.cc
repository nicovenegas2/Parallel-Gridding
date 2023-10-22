#include <iostream>
#include "Lecture.h"
#include "GridTaskV1.h"
#include "GridTaskV2.h"
#include "Matrix.h"
#include <chrono>
using namespace std;

int main(int argc, char* argv[]){
    cout << "Starting program" << endl;
    string inputFile, outputFile;
    int N, chunkSize, taskNum;
    clock_t start, end;
    float deltaU;
    cout << "Starting program" << endl;

    int opt;
    int i = 0;
    while ((opt = getopt(argc, argv, "i:o:d:N:c:t:")) != -1) {
        switch (opt) {
            case 'i':
                inputFile = optarg;
                break;
            case 'o':
                outputFile = optarg;
                break;
            case 'd':
                deltaU = atof(optarg);
                break;
            case 'N':
                N = atoi(optarg);
                break;
            case 't':
                taskNum = atoi(optarg);
                break;
            case 'c':
                chunkSize = atoi(optarg);
                break;
            default:
                cout << "Invalid argument, check flags" << endl;
                return 1;
        }
        i++;
    }




    Lecture lecture(inputFile, chunkSize);
    GridTaskV1 *tasks[taskNum];
    Matrix matrix(N);
    string lines;

    // Forma 1
    start = clock();

    // 1. Crear tareas
    for (int i = 0; i < taskNum; i++){
        tasks[i] = new GridTaskV1(lecture, matrix, deltaU, N,i);
    }

    // 2. Esperar a que terminen
    for (int i = 0; i < taskNum; i++){
        delete tasks[i];
    }

    // 3. Normalizar
    matrix.normalize();
    end = clock();
    cout << "Tiempo de ejecucion Forma 1: " << (end - start) / (double)CLOCKS_PER_SEC << endl;
    lecture.write(outputFile, matrix);

    // Forma 2
    start = clock();
    GridTaskV2 *tasks2[taskNum];
    Matrix matrix2(N);
    Lecture lecture2(inputFile, chunkSize);
    // 1. Crear tareas
    for (int i = 0; i < taskNum; i++){
        tasks2[i] = new GridTaskV2(lecture2, matrix2, deltaU, N);
    }

    // 2. Esperar a que terminen
    for (int i = 0; i < taskNum; i++){
        delete tasks2[i];
    }
    // 3. Normalizar
    matrix2.normalize();
    end = clock();
    cout << "Tiempo de ejecucion Forma 2: " << (end - start) / (double)CLOCKS_PER_SEC << endl;
    cout << "Fin del programa" << endl;
    exit(0);
}