#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdbool.h>
using namespace std;

// ����ü ����
typedef struct
{
	int st_id; // ID
	char name[16]; // NAME
	char dept[16]; // DEPT
	int grade; // GRADE
	double gpa; // GPA
} Student;


void initStudents(Student students[], int st_ids[], int num_students); // �л� ���� �ʱ�ȭ

void fprintStudent(ostream& fout, Student* pSt);  // ������� _ ����
void fprintStudentIDs(ostream& fout, Student students[]); // ������� _ ����
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last); // �й����� ����ϱ�.
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last); // ������ �й� ���


void sortStudentsByID(Student students[], int num_students); // �й����� �����ϱ�.
void sortStudentsByGPA_ID(Student students[], int num_students); // �������� �����ϱ�.



Student* searchStudentByID(Student students[], int num_students, int st_ID); // �й����� Ž��