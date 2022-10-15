#include "BigRand.h"

// 난수 발생
int* genBigRandArray(int bigRandArraySize, int offset)
{
	int* pBigRandArray;
	int idx1, idx2;
	int temp;
	pBigRandArray = (int*)calloc(bigRandArraySize, sizeof(int));
	
	// 값을 모두 넣어준다.
	for (int i = 0; i < bigRandArraySize; i++)
	{
		pBigRandArray[i] = i + offset;
	} 
	
	// INDEX를 생성해서 섞어준다.
	// 15비트 밀어내서 32767보다 크게 생성시켜준다.
	for (int i = 0; i < bigRandArraySize; i++)
	{
		idx1 = (((long)rand() << 15) | rand()) % bigRandArraySize; 
		idx2 = (((long)rand() << 15) | rand()) % bigRandArraySize;
		if (idx1 == idx2) 
		{
			continue;
		}
		else 
		{
			temp = pBigRandArray[idx1];
			pBigRandArray[idx1] = pBigRandArray[idx2];
			pBigRandArray[idx2] = temp;
		}
	}
	return pBigRandArray;
}


// 난수 출력
void fPrintBigRandArray(ofstream& fout, int* bigRand, int num_rands)
{
	int count = 0;
	int num_lines = 5;

	if (num_rands < BIG_SIZE)
	{
		num_lines = num_rands / LINESIZE;
	}

	for (int i = 0; i < num_lines; i++)
	{
		for (int j = 0; j < LINESIZE; j++)
		{
			if (count == num_rands)
				break;
			fout << setw(7) << bigRand[count];
			count++;
		}
		fout << endl;
	}

	if (num_rands >= BIG_SIZE)
	{
		fout << ". . . . . . . ." << endl;
		count = num_rands - (LINESIZE * num_lines);

		for (int i = 0; i < num_lines; i++)
		{
			for (int j = 0; j < LINESIZE; j++)
			{
				fout << setw(7) << bigRand[count];	//출력
				count++;
			}
			fout << endl;
		}
		fout << endl;
	}
}
