#ifndef DATE_H
#define DATE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // C++ �⺻ �������
#include <fstream> // ������� �������
#include <cstdlib> // ���������� ���� �������
#include <iomanip> // ��� ������ ���� �������

using namespace std;

#define WEEKDAY_AD01Jan01 MON // the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7
#define Secs_in_Minute 60
#define Secs_in_Hour (Secs_in_Minute * 60)
#define Secs_in_DAY (Secs_in_Hour * 24)
#define LOCAL_GMT_OFFSET_HOUR 9



// DATE Ŭ���� ����
class Date
{
public:
	Date(); // default constructor
	Date(int y, int m, int d); // constructor ������
	//~Date(); // destructor ��ü�� �Ҹ�� ��. >> ���÷� ��ü�� �����޸��Ҵ��� ������ ��, Ŭ������ �Ҹ��Բ� �Ҹ� �� �� �ְ� ��.

	void inputDate(); // ��¥ �Է�
	void printDate(); // ��¥ ���
	void fprintDate(ostream& fout); // ��¥ ���_����
	void setDate(int y, int m, int dy); // set date
	void setMonth(int m); // set month

	void setRandDateAttributes(); //setting a particular value as random

	int getYear() { return year; } 
	int getMonth() { return month; }
	int getDay() { return day; }
	int getYearDay(); // ~ ���� ��������
	//int getYearDay(int m, int d);
	int getWeekDay(); // 1�� 1�� 1�� �ʱ�ȭ
	int getElapsedDaysFromAD010101(); // 1�� 1�� 1�� ~ ���� ��������



private:
	bool isLeapYear(); // ����Ȯ��
	bool isLeapYear(int y); // ����Ȯ��
	bool isValidDate(int y, int m, int d);
	int year;
	int month;
	int day;
};





#endif