/*

파일명 : PRACTICE_04

프로그램의 목적 및 기본기능 :
 - 객체지향프로그래밍을 이용하여, 문단을 출력하라.

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 09월 15일

*/



#include <iostream> // C++ 입출력을 위한 기본 헤더파일
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h> // 시간을 위한 헤더파일
#include <string> // string 데이터 타입을 만들어서 변수에 문자열을 바로 넣을 수 있음. ( 예시 : sting var1 = "HELLO"; / string var2("WORLD");

#include "Date.h"
#include "Person.h"

#define NUM_PERSON 10

using namespace std;
// C++ 에는 다양한 namespace 가 존재.
// 이러한 다양한 namespace 에는 같은 이름을 가진 함수가 존재할 수 있음.
// 같은 이름을 가진 함수가 여러개의 namespace에 존재하는 경우 충돌이 일어남.
// 따라서 함수를 사용할 때는 어떤 namespace 에 있는 함수를 호출하는지를 명시해주어야 함.
// std = standard = C++표준공간
// std 라는 이름공간을 사용하겠다는 의미.


int main()
{ 
	// 출력 파일 열기
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
	

	// 문단 출력
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
	
	// 크리스마스 여부 확인 및 출력
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