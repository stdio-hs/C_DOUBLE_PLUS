#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdbool.h>
using namespace std;

// 구조체 선언
typedef struct
{
	int st_id; // ID
	char name[16]; // NAME
	char dept[16]; // DEPT
	int grade; // GRADE
	double gpa; // GPA
} Student;


void initStudents(Student students[], int st_ids[], int num_students); // 학생 정보 초기화

void fprintStudent(ostream& fout, Student* pSt);  // 파일출력 _ 정보
void fprintStudentIDs(ostream& fout, Student students[]); // 파일출력 _ 학점
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last); // 학번으로 출력하기.
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last); // 성적과 학번 출력


void sortStudentsByID(Student students[], int num_students); // 학번으로 정렬하기.
void sortStudentsByGPA_ID(Student students[], int num_students); // 학점으로 정렬하기.



Student* searchStudentByID(Student students[], int num_students, int st_ID); // 학번으로 탐색