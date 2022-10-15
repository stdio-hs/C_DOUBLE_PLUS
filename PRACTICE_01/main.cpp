/*

���ϸ� : PRACTICE_01

���α׷��� ���� �� �⺻��� : 
 - ������ �����Ͽ� �л��� ������ ����
 - ������ �л����� ������ ����
 - ���ĵ� �л����� ������ ��� _ �ؽ�Ʈ���Ͽ� ���
 - �л����� �������� �������� _ ����Ž��


���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 09�� 06�� ~ 2022�� 09�� 08��

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
	
	// �л� ���� ��� �� ����
	/*�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� */
	// �л� ���� & ���
	fout << endl << endl;
	fout << "Initialized array of students : " << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	
	// �л� ���� ���� ( ID�� ���� �������� )
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	
	// �л� ���� ���� ( GPA�� ���� �������� )
	fout << endl << endl;
	fout << "Sorting array of students by (decreasing order of GPA, increasing order of ID) : " << endl;
	sortStudentsByGPA_ID(students, NUM_STUDENTS); // non-increasing order
	fprintBigArrayOfStudent_GPA_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	/*�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� */


	// �л� ���� ���(������) �� ����Ž��
	/*�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� */
	// �л� ���� ���� ( ID�� ���� �������� )
	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID : " << endl;
	sortStudentsByID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	
	// �л��������� Ž�� �� ���
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
	/*�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� */
	
	
	free(student_ids);
	free(students);
	fout.close();
}