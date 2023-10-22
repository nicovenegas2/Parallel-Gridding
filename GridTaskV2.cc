#include "GridTaskV2.h"

void GridTaskV2::main(){
    yield( rand() % 100 ); 
    int countLines = 0;
    float u,v,w,real,imag,weight,freq;
    string uStr,vStr,wStr,realStr,imagStr,weightStr,freqStr;
    string line;
    // CICLO: para todas las lineas
        // pasas a variables
        // transformar a long. onda
        // calcular punto en grilla
        // sumas a las grillas
    // normalizas peso
    while(lecture.canRead()){
        content = lecture.read();
        std::stringstream ss(content);

        while(getline(ss, line, '\n') && line != ""){
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
            matrix.add(i, j, real, imag, weight);
            countLines++;
        }
    }
    cout << "countLines: " << countLines << endl;
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