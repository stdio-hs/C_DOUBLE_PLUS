/*

���ϸ� : PRACTICE_04

���α׷��� ���� �� �⺻��� :
 - ��ü�������α׷����� �̿��Ͽ�, ������ ����϶�.

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 09�� 15��

*/



#include <iostream> // C++ ������� ���� �⺻ �������
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> // �ð��� ���� �������
#include <string> // string ������ Ÿ���� ���� ������ ���ڿ��� �ٷ� ���� �� ����. ( ���� : sting var1 = "HELLO"; / string var2("WORLD");

#include "Date.h"
#include "Person.h"

#define NUM_PERSON 10

using namespace std;
// C++ ���� �پ��� namespace �� ����.
// �̷��� �پ��� namespace ���� ���� �̸��� ���� �Լ��� ������ �� ����.
// ���� �̸��� ���� �Լ��� �������� namespace�� �����ϴ� ��� �浹�� �Ͼ.
// ���� �Լ��� ����� ���� � namespace �� �ִ� �Լ��� ȣ���ϴ����� ������־�� ��.
// std = standard = C++ǥ�ذ���
// std ��� �̸������� ����ϰڴٴ� �ǹ�.


int main()
{ 
	// ��� ���� ����
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

	ofstream fout;
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Error in opening output.txt !!" << endl;
		exit;
	}

	// #1
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

	Date AD010101(1, 1, 1);

	int year, month, day;
	int daysToChristmas;
	time_t currentTime;
	struct tm* time_and_date;
	time(&currentTime);
	time_and_date = localtime(&currentTime);


	year = time_and_date->tm_year + 1900;
	month = time_and_date->tm_mon + 1;
	day = time_and_date->tm_mday;
	

	Date newYearDay(year, 1, 1), today(year, month, day), christmas(year, 9, 16);
	

	// ���� ���
	cout << "AD Jan. 1, 1 is ";
	AD010101.fprintDate(fout);
	fout << endl;
	fout << "Today is ";
	today.fprintDate(fout);
	fout << endl;
	fout << "New year's day of this year was ";
	newYearDay.fprintDate(fout);
	fout << endl;
	fout << "Christmas of this year is ";
	christmas.fprintDate(fout);
	fout << endl;
	
	// ũ�������� ���� Ȯ�� �� ���
	if (today.getMonth() == christmas.getMonth() &&
		today.getDay() == christmas.getDay())
	{
		fout << "Today is Christmas! Happy Christmas to you all !!\n";
	}
	else
	{
		fout << " Sorry, today is not Christmas!\n";
		daysToChristmas =
			christmas.getElapsedDaysFromAD010101() - today.getElapsedDaysFromAD010101();
		fout << " You must wait " << daysToChristmas << " day(s) to Christmas !" << endl;
	}
	fout << endl;


	// #2
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

	Person p1(string("Hong, Gil-Dong"), Date(2000, 1, 1)), p2;
	fout << "Person p1 : " << endl;
	p1.fprintPerson(fout);
	fout << endl;
	fout << "Person p2 : " << endl;
	p2.setName(string("Lee, Soo - Jeong"));
	p2.setBirthDate(Date(2018, 9, 1));
	p2.fprintPerson(fout);
	fout << endl;
	fout << endl << "Generating array of persons ... " << endl;
	Person* persons;
	persons = (Person*) new Person[NUM_PERSON];
	for (int i = 0; i < NUM_PERSON; i++)
	{
		persons[i].setRandPersonAttributes();
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	fout << endl;
	delete[] persons;
	fout.close();
	return 0;

}