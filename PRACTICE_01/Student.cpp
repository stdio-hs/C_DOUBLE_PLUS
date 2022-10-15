#include "Student.h"

#define BIG_SIZE 300
#define LINESIZE 10

// �л� ���� �ʱ�ȭ
void initStudents(Student students[], int st_ids[], int num_students)
{
	srand(time(NULL));

	for (int i = 0; i < num_students; i++)
	{

		// ���̼��� ( ���� : �̸����̴� 5~15 )
		int nameLength = rand() % 10 + 5;
		int deptLength = rand() % 2 + 3;  

		// ù���� �빮�� ���� ( �̸� )
		for (int j = 0; j < nameLength; j++)
		{
			if (j == 0)
				students[i].name[j] = rand() % 26 + 'A';
			else
				students[i].name[j] = rand() % 26 + 'a';
		}
		students[i].name[nameLength] = '\0'; //���鹮��

		// �а�/�й�/�г�/����
		for (int j = 0; j < deptLength; j++)
		{
			students[i].dept[j] = rand() % 26 + 'A';
		}
		students[i].dept[deptLength] = '\0'; // ����

		students[i].st_id = st_ids[i];	
		students[i].grade = rand() % 8 + 1;
		students[i].gpa = ((rand() % 10000) / 100.0); 
	}
}


// ������� _ ����
void fprintStudent(ostream& fout, Student* pSt)
{

	fout.setf(ios::fixed); // �����Ҽ���
	fout.setf(ios::showpoint); // �Ҽ���ǥ��
	fout.precision(2); // �Ҽ��� 2�ڸ��� ǥ��

	fout << "Student(ID: " << setw(4) << pSt->st_id << ", "; // �й�
	fout << "Name: " << setw(16) << pSt->name << ", "; // �̸�
	fout << "Dept: " << setw(5) << pSt->dept << ", "; // �а�
	fout << "Grade: " << pSt->grade << ", "; // �г�
	fout << "GPA: " << setw(5) << pSt->gpa;	// ����
}

// �������
void fprintStudentIDs(ostream& fout, Student students[])
{
	fout << setw(7) << students->st_id;
}

// �������
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{
	Student* pSt;
	int count = 0;
	if (num_students <= num_first_last * 2)
	{
		for (int i = 0; i < num_students; i++)
		{
			pSt = &students[i];
			fout << setw(6) << pSt->st_id;
			count++;
			if ((count % 20) == 0)
				fout << endl;
		}
		return;
	}
	for (int i = 0; i < num_first_last; i++)
	{
		pSt = &students[i];
		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << " . . . . . " << endl;
	for (int i = num_students - num_first_last; i < num_students; i++)
	{
		pSt = &students[i];
		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
}

// �������
void fprintStudentGPA_ID(ostream& fout, Student* pSt)
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.precision(2);

	fout << "(" << setw(5) << pSt->gpa << ", " << setw(5) << pSt->st_id << ") ";
}

// �������
void fprintBigArrayOfStudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{
	int count = 0;
	int num_lines = num_first_last / LINESIZE;
	Student* pSt = NULL;

	if (num_students < BIG_SIZE)
	{
		num_lines = num_students / LINESIZE;
	}

	for (int i = 0; i < num_lines; i++)
	{
		for (int j = 0; j < LINESIZE; j++)	// 10���� ���
		{
			pSt = &students[count];
			if (count == num_students)		// ���� ��������� Ż��
				break;
			fprintStudentGPA_ID(fout, pSt);	//���
			count++;
		}
		fout << endl;
	}

	if (num_students >= BIG_SIZE)
	{
		fout << ". . . . . . . ." << endl;
		count = num_students - (LINESIZE * num_lines);

		for (int i = 0; i < num_lines; i++)
		{
			for (int j = 0; j < LINESIZE; j++)
			{
				pSt = &students[count];
				fprintStudentGPA_ID(fout, pSt);	// ���
				count++;
			}
			fout << endl; // ���� ����
		}
		fout << endl;
	}
}

// �й����� �����ϱ�.
void sortStudentsByID(Student students[], int num_students)
{
	Student temp;
	int min_index = 0;
	int sort_index = 0;

	while (true)
	{
		if (sort_index == num_students) // �������� �����ϸ� ����
			break;
		temp = students[sort_index]; // �ε��� ����
		min_index = sort_index; //�ּҰ� ������Ʈ 

		for (int i = sort_index; i < num_students; i++)
		{
			if (temp.st_id > students[i].st_id) //�� ���� ���� �����ϸ�
			{
				temp = students[i]; //���� ������Ʈ
				min_index = i;
			}
		}
		//��ü
		students[min_index] = students[sort_index];
		students[sort_index] = temp;
		sort_index++;
	}

}

// �������� �����ϱ�.
void sortStudentsByGPA_ID(Student students[], int num_students)
{
	Student temp;
	int max_index = 0;
	int sort_index = 0;
	//int min_ID_index = 0;

	sortStudentsByID(students, num_students);

	while (true)
	{
		if (sort_index == num_students)	 // �������� �����ϸ� ����
			break;
		temp = students[sort_index];// �ε��� ����
		max_index = sort_index;	// �ִ밪 ������Ʈ

		for (int i = sort_index; i < num_students; i++)
		{
			if (temp.gpa < students[i].gpa)	 // ������ �� ũ��
			{
				temp = students[i];	//������ ������Ʈ
				max_index = i;
			}
			else if (temp.gpa == students[i].gpa) //���� �����̶�� �й���
			{
				if (temp.st_id < students[i].st_id)
				{
					temp = students[i]; //���� ������Ʈ
					max_index = i;
				}
			}
		}
		//����
		students[max_index] = students[sort_index];
		students[sort_index] = temp;
		sort_index++;
	}
}


// �й����� Ž��
Student* searchStudentByID(Student students[], int num_students, int st_ID)  //�й����� �����˻�
{
	int first = 0;  //ó�� 
	int last = num_students - 1;//��
	int mid; //�߰�

	if ((st_ID > students[num_students - 1].st_id) || (st_ID < students[0].st_id))
		return NULL;	// ���� ���� ���� ���� ��� NULL�� ��ȯ

	while (first <= last)
	{
		mid = (first + last) / 2;				// mid ã��
		if (st_ID == students[mid].st_id)	// ���� �߰��̸� �ٷ� ��ȯ
			return &students[mid];
		else if (st_ID < students[mid].st_id)		//ã�� ���� �߰����� ������
			last = mid - 1;		// �ִ븦 �߰����� �ϳ� ���������� ����
		else
			first = mid + 1;	//�ּҸ� �߰����� ����
	}
}