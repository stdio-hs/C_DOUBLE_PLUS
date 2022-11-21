#ifndef DATE_H
#define DATE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // C++ 기본 헤더파일
#include <fstream> // 파일출력 헤더파일
#include <cstdlib> // 난수생성을 위한 헤더파일
#include <iomanip> // 출력 형식의 조작 헤더파일

using namespace std;

#define WEEKDAY_AD01Jan01 MON // the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7
#define Secs_in_Minute 60
#define Secs_in_Hour (Secs_in_Minute * 60)
#define Secs_in_DAY (Secs_in_Hour * 24)
#define LOCAL_GMT_OFFSET_HOUR 9



// DATE 클래스 구현
class Date
{
public:
	Date(); // default constructor
	Date(int y, int m, int d); // constructor 생성자
	//~Date(); // destructor 객체가 소멸될 때. >> 예시로 객체가 동적메모리할당후 해제할 때, 클리스도 소멸함께 소멸 될 수 있게 함.

	void inputDate(); // 날짜 입력
	void printDate(); // 날짜 출력
	void fprintDate(ostream& fout); // 날짜 출력_파일
	void setDate(int y, int m, int dy); // set date
	void setMonth(int m); // set month

	void setRandDateAttributes(); //setting a particular value as random

	int getYear() { return year; } 
	int getMonth() { return month; }
	int getDay() { return day; }
	int getYearDay(); // ~ 몇일 지났는지
	//int getYearDay(int m, int d);
	int getWeekDay(); // 1년 1월 1일 초기화
	int getElapsedDaysFromAD010101(); // 1년 1월 1일 ~ 몇일 지났는지



private:
	bool isLeapYear(); // 윤년확인
	bool isLeapYear(int y); // 윤년확인
	bool isValidDate(int y, int m, int d);
	int year;
	int month;
	int day;
};





#endif