#include "GridTaskV1.h"

void GridTaskV1::main(){
    
    yield( rand() % 100 ); 
    float u,v,w,real,imag,weight,freq;
    string uStr,vStr,wStr,realStr,imagStr,weightStr,freqStr;
    string line;
    while(lecture.canRead()){
        content = lecture.read();
        cout << content << endl;
        std::stringstream ss(content);

        while(getline(ss, line, '\n')){
            istringstream iss(line);
            getline(iss, uStr, ',');
            getline(iss, vStr, ',');
            getline(iss, wStr, ',');
            getline(iss, realStr, ',');
            getline(iss, imagStr, ',');
            getline(iss, weightStr, ',');
            getline(iss, freqStr, ',');
            u = stof(uStr);
            v = stof(vStr);
            w = stof(wStr);
            real = stof(realStr);
            imag = stof(imagStr);
            weight = stof(weightStr);
            freq = stof(freqStr);
            // Transformar a long. onda
            u = u * (freq / SPEED_LIGHT);
            v = v * (freq / SPEED_LIGHT);
            // Calcular punto en grilla y redondear
            int i = round((u / deltaU) + (N / 2));
            int j = round((v / deltaU) + (N / 2));
            // Sumar a las grillas
            if (i < 0 || i >= N || j < 0 || j >= N){
                continue;
            }
            gridR[i][j] += real * weight;
            gridI[i][j] += imag * weight;
            gridW[i][j] += weight;
        }

        // cout << "********************************" << endl;
    }
        matrix.plusMatrix(gridR, gridI, gridW);
}

GridTaskV1::GridTaskV1(Lecture &lecture, Matrix &matrix, float deltaX, int N, int id) : lecture(lecture), matrix(matrix), N(N), id(id) {
    deltaX = deltaX * (M_PI / 180);
    deltaU = 1/(deltaX * N);
    
    gridR = new float*[N];
    gridI = new float*[N];
    gridW = new float*[N];
    for(int i = 0; i < N; i++){
        gridR[i] = new float[N];
        gridI[i] = new float[N];
        gridW[i] = new float[N];

        for(int j = 0; j < N; j++){
            gridR[i][j] = 0;
            gridI[i][j] = 0;
            gridW[i][j] = 0;
        }
    }
}

void GridTaskV1::printGrid(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << i << "," << j << ":" << gridR[i][j] << endl; 
        }
    }
}

int GridTaskV1::getN(){
    return N;
}

string GridTaskV1::getContent(){
    return content;
}