/*

파일명 : PRACTICE_01

프로그램의 목적 및 기본기능 : 
 - 난수를 생성하여 학생의 정보를 생성
 - 생성된 학생들의 정보를 정렬
 - 정렬된 학생들의 정보를 출력 _ 텍스트파일에 출력
 - 학생들의 정보에서 정보추출 _ 이진탐색


프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 09월 06일 ~ 2022년 09월 08일

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Student.h"
#include "BigRand.h"

using namespace std;
#define NUM_STUDENTS 5000
#define NUM_SEARCH 5
#define NUM_FIRST_LAST_BLOCK 100



void main()
{
	ofstream fout;
	int* student_ids;
	Student* students, * pSt;
	int student_search[NUM_SEARCH] = { 1, 123, 999, 2500, 4999 };


	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Error in opening output.txt" << endl;
		exit;
	}


	students = (Student*)calloc(NUM_STUDENTS, sizeof(Student));
	student_ids = genBigRandArray(NUM_STUDENTS, 0);
	initStudents(students, student_ids, NUM_STUDENTS);
	
	// 학생 정보 출력 및 정렬
	/*ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ */
	// 학생 생성 & 출력
	fout << endl << endl;
	fout << "Initialized array of students : " << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	
	// 학생 정보 정렬 ( ID에 따른 오름차순 )
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	
	// 학생 정보 정렬 ( GPA에 따른 내림차순 )
	fout << endl << endl;
	fout << "Sorting array of students by (decreasing order of GPA, increasing order of ID) : " << endl;
	sortStudentsByGPA_ID(students, NUM_STUDENTS); // non-increasing order
	fprintBigArrayOfStudent_GPA_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	/*ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ */


	// 학생 정보 출력(정렬후) 및 정보탐색
	/*ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ */
	// 학생 정보 정렬 ( ID에 따른 오름차순 )
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	
	// 학생정보에서 탐색 후 출력
	fout << endl << endl;
	fout << "Searching student with student_ID : " << endl;

	for (int i = 0; i < NUM_SEARCH; i++)
	{
		pSt = searchStudentByID(students, NUM_STUDENTS, student_search[i]);
		fout << "Student search by ID (" << setw(4) << student_search[i] << ") : ";
		if (pSt != NULL)
			fprintStudent(fout, pSt);
		else
			fout << "NULL - student was not found !!";
		fout << endl;
	}
	/*ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ */
	
	
	free(student_ids);
	free(students);
	fout.close();
}