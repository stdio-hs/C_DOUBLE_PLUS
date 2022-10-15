#ifndef BIGRAND_H
#define BIGRAND_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdbool.h>
using namespace std;

#define RANDOMIZE() srand((unsigned int)time(NULL))
#define BIG_SIZE 500
#define LINESIZE 20


int* genBigRandArray(int num_rands, int offset); // 난수발생
void fPrintBigRandArray(ofstream& fout, int* bigRand, int num_rands); // 난수출력


#endif