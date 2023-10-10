#include "GridTaskV2.h"

void GridTaskV2::main(){
    yield( rand() % 100 ); 
    float u,v,w,real,imag,weight,freq;
    string uStr,vStr,wStr,realStr,imagStr,weightStr,freqStr;
    string line;
    content = lecture.read();
    cout << "content: " << endl << content << endl;

    std::stringstream ss(content);
    // CICLO: para todas las lineas
        // pasas a variables
        // transformar a long. onda
        // calcular punto en grilla
        // sumas a las grillas
    // normalizas peso

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

        cout << "Real: " << real << " Imag: " << imag << " Weight: " << weight << " Freq: " << freq << endl;
        cout << "Transformar a long. onda" << endl;
        // Transformar a long. onda
        cout << "|u: " << u << " v: " << v << "|-->|";
        u = u * (freq / SPEED_LIGHT);
        v = v * (freq / SPEED_LIGHT);
        cout << "u: " << u << " v: " << v << "|" << endl;

        cout << "Calcular punto en grilla" << endl;
        // Calcular punto en grilla
        int i = (int) (u / deltaU) + (N / 2);
        int j = (int) (v / deltaU) + (N / 2);
        cout << u << "," << v << " -> " << i << "," << j << endl;

        cout << "Sumar a las grillas" << endl;
        // Sumar a las grillas
        matrix.add(i, j, real, imag, weight);
    }
}

GridTaskV2::GridTaskV2(Lecture &lecture, Matrix &matrix, float deltaX, int N) : lecture(lecture), matrix(matrix), N(N) {
    deltaX = deltaX * (M_PI / 180);
    deltaU = 1/(deltaX * N);
    cout << "deltaU: " << deltaU << endl;
}

int GridTaskV2::getN(){
    return N;
}

string GridTaskV2::getContent(){
    return content;
}