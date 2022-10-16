/*

파일명 : PRACTICE_2

프로그램의 목적 및 기본기능 :
 - 파일 입력 및 데이터 통계 분석

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 09월 12일 ~ 2022년 09월 14일

*/

#include "main.h"

void main()
{
	ifstream fin;
	ofstream fout;
	int data_array[20] = { 0 };
	int num_data = 0;

	// 텍스트 파일 오픈
	fin.open(INPUT_FILE_NAME);
	
	// 입력 파일 열렸는지 확인을 위해서
	if (fin.fail())
	{
		cout << "Fail to open an input file (" << INPUT_FILE_NAME << ") \n";
		exit(1);
	}

	// 출력 파일 열렸는지 확인을 위해서
	fout.open(OUTPUT_FILE_NAME);
	if (fout.fail()) 
	{
		cout << "Fail to open an output file (" << OUTPUT_FILE_NAME << ") \n";
		exit(1);
	}

	// 함수 호출
	num_data = fileInputOutput(fin, data_array, MAX_NUM_DATA);
	getStatistics_fileOut(data_array, num_data, fout);
	
	// 파일 닫아주기.
	fin.close();
	fout.close();
}



int fileInputOutput(ifstream& fin, int* data_array, int max_num_data)
{
	int num_data = 0; //데이터 개수

	while (!fin.eof())
	{
		if (num_data >= max_num_data) 
		{
			// 20개 까지
			cout << "Fail to load : Too many numbers" << endl;
			break;
		}

		fin >> data_array[num_data];
		num_data++;
	}

	return num_data;
}



void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout)
{

	int min = 0; int max = 0;  int sum = 0; double var_sum = 0;
	double avg = 0; double var = 0; double std_dev = 0;

	for (int i = 0; i < num_data; i++) 
	{
		if (i == 0) {
			max = data_array[i];
			min = data_array[i];
		}
		else
		{
			if (min > data_array[i])
				min = data_array[i];

			if (max < data_array[i])
				max = data_array[i];
		}
		sum += data_array[i];

	}

	avg = (double)sum / num_data; 

	for (int i = 0; i < num_data; i++)
	{
		var_sum += ((double)data_array[i] - avg) * ((double)data_array[i] - avg);
	}
	var = var_sum / num_data;
	std_dev = sqrt(var); 


	// 출력
	if (fout.is_open())
	{
		fout << "Total 10 input from input data file. \n";
		fout << "Total 10 integer data : {";
		for (int i = 0; i < num_data; i++) 
		{
			fout << data_array[i] << ", ";
		}
		fout << "} \n";
		fout << "min (" << min << "), ";
		fout << "max (" << max << "), ";
		fout << "sum (" << sum << "), ";

		fout << "avg (" << avg << "), ";
		fout << "var (" << var << "), ";
		fout << "std_dev (" << std_dev << ")";
	}
}