#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include "InputUtils.h"

using namespace std;
using namespace InputUtils;

int X2mMultipication();
int X3mMultipication();

int X2mMultipication(){
    int matrixA[2][2];
    int matrixB[2][2];
    int matrixX[2][2];

    // Input loop for matrixA
    cout << "Enter matrix A\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "[" << i << "][" << j << "] ";
            cin >> matrixA[i][j];
        }
    }

    // Output loop matrixA
    cout << "\nMatrix A:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matrixA[i][j] << "  ";
        }
        cout << endl;
    }

     waitForEnter("Press Enter to exit...");

    // Input loop matrixB
    cout << "Enter matrix B\n";
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
            cout << "[" << i << "]"<< "[" << j << "]";
            cin >> matrixB[i][j];
        }
    }

    // Output loop matrixB
    cout << "\nMatrix B:\n";
    for (int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            cout << matrixB[i][j] << "  ";
        }
        cout << endl;
    }

    // matrix multiplication
    matrixX[0][0] = (matrixA[0][0] * matrixB[0][0]) + (matrixA[0][1] * matrixB[1][0]);
    matrixX[0][1] = (matrixA[0][0] * matrixB[0][1]) + (matrixA[0][1] * matrixB[1][1]);
    matrixX[1][0] = (matrixA[1][0] * matrixB[0][0]) + (matrixA[1][1] * matrixB[1][0]);
    matrixX[1][1] = (matrixA[1][0] * matrixB[0][1]) + (matrixA[1][1] * matrixB[1][1]);

     // Output loop matrixX
    cout << "\nMatrix X:\n";
    for (int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            cout << matrixX[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

int X3mMultipication(){
    const int SIZE = 3;

    int matrixA[SIZE][SIZE],matrixB[SIZE][SIZE],matrixX[SIZE][SIZE];

    // Input matrixA
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            cout << "[" << i << "]"<< "[" << j << "]";
            cin >> matrixA[i][j];
        }
    }

    // Display matrixA
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            cout << matrixA[i][j] << "  ";
        }
        cout << endl;
    }

    // Input matrixB
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            cout << "[" << i << "]"<< "[" << j << "]";
            cin >> matrixB[i][j];
        }
    }

    // Display matrixB
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            cout << matrixB[i][j] << "  ";
        }
        cout << endl;
    }

    // Matrix multiplication logic
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrixX[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) {
                matrixX[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Output matrixX
    cout << "\nMatrix X (A x B):\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrixX[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

#endif //  MATH_H