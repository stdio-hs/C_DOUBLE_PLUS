#ifndef PERSON_H
#define PERSON_H

#include <iostream> // C++ 기본 헤더파일
#include <fstream> // 파일출력 헤더파일
#include <iomanip> // 출력 형식의 조작 헤더파일
#include <string> // string 데이터 타입을 만들어서 변수에 문자열을 바로 넣을 수 있음. ( 예시 : sting var1 = "HELLO"; / string var2("WORLD");

#include "Date.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#define MAX_NAME_LEN 15
#define MIN_NAME_LEN 5


class Person
{
public:
	Person() : name(string("nobody")), birthDate(Date(1, 1, 1)) { } 
	Person(string n, Date bd) : name(n), birthDate(bd) { } 
	void setName(string n) { name = n; }
	string getName() { return name; }
	void setBirthDate(Date bd) { birthDate = bd; }
	Date getBirthDate() { return birthDate; }
	void setRandPersonAttributes(); 
	void fprintPerson(ostream& fout);


private:
	Date birthDate;
	string name;
};

#endif