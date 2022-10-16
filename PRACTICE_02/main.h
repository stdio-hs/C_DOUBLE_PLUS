#ifndef MAIN_H
#define MAIN_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#define MAX_NUM_DATA 100
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#define MAX_NUM_DATA 20

int fileInputOutput(ifstream& fin, int* data_array, int max_num_data); 
void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout);

#endif