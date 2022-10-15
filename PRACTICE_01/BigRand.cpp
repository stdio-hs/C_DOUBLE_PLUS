#include "BigRand.h"

// ���� �߻�
int* genBigRandArray(int bigRandArraySize, int offset)
{
	int* pBigRandArray;
	int idx1, idx2;
	int temp;
	pBigRandArray = (int*)calloc(bigRandArraySize, sizeof(int));
	
	// ���� ��� �־��ش�.
	for (int i = 0; i < bigRandArraySize; i++)
	{
		pBigRandArray[i] = i + offset;
	}
	
	// INDEX�� �����ؼ� �����ش�.
	// 15��Ʈ �о�� 32767���� ũ�� ���������ش�.
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


// ���� ���
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
				fout << setw(7) << bigRand[count];	//���
				count++;
			}
			fout << endl;
		}
		fout << endl;
	}
}
