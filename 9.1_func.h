#pragma once

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

void menu();
void task7_1();
void task5_3();
void task7_2();
void initArray(vector<bool> array);
void printArray(vector<int> array);

float calculateTrace(vector<vector<float>> A, int size);
float calculateTrace(vector<float> A, int size);
vector<vector<float>> multMatrix(vector<vector<float>> A, int size);
vector<float> multMatrix(vector<float> A, int size);
void initMatrix(vector<vector<float>>& A, int size);
void initMatrix(vector<float>& A, int size);
void printMatrix(vector<vector<float>> A, int size);
void printMatrix(vector<float> A, int size);