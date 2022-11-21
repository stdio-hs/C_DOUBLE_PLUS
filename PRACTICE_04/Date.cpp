#include "Date.h"
enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };

// default constructor
Date::Date()
{
	year = 0; month = 0; day = 0;
}

// constructor
Date::Date(int y, int m, int d)
{
	setMonth(m);
	setDate(y, m, d);
}

// set month
void Date::setMonth(int newMonth) 
{
	if ((newMonth >= 1) && (newMonth <= 12))
		month = newMonth;
	else
	{
		cout << "Illegal month value! Program aborted.\n";
		exit(1);
	}
	day = 1;
}

// set date
void Date::setDate(int y, int m, int d)
{
	year = y;
	if ((m >= 1) && (m <= 12))
		month = m;
	else
	{
		cout << "Illegal month value! Program aborted.\n";
		exit(1);
	}
	if ((d >= 1) && (d <= 31))
		day = d;
	else
	{
		cout << "Illegal day value!! Program aborted.\n";
		exit(1);
	}
}

void Date::setRandDateAttributes()
{
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	year = rand() % 2000 + 1000;
	month = rand() % 12 + 1;
	if (isLeapYear(year) && month == 2)
		days_month[2] = 29;
	day = rand() % days_month[month] + 1;
}

// ����Ȯ��
bool Date::isLeapYear(int y)
{
	if (y % 4 == 0)
	{
		if ((y % 100 == 0) && (y % 400 == 0))
			return true;
	}
	else
	{
		return false;
	}
}

// ����Ȯ��
bool Date::isLeapYear()
{
	if (isLeapYear(year))
		return true;
	else
		return false;

}

// ~ ���� ��������
int Date::getYearDay() 
{
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int yearDay = 0;
	if (isLeapYear())
		days_month[2] = 29;
	for (int m = 1; m < month; m++)
		yearDay += days_month[m];
	yearDay += day;
	return yearDay;
}

// 1�� 1�� 1�� ~ ���� ��������
int Date::getElapsedDaysFromAD010101()
{
	int yearDay;
	int elpsDay = 0;
	for (int y = 1; y < year; y++)
	{
		elpsDay += 365;
	}
	yearDay = getYearDay();
	elpsDay += yearDay;
	return elpsDay;
}

// 1�� 1�� 1�� �ʱ�ȭ
int Date::getWeekDay()
{
	int weekDay_AD010101 = MON;
	// AD Jan. 1, 1 was Monday
	int yearDay = 1;
	int weekDay = 1;
	int elapsedDays = 0;

	return weekDay;
}

// ��¥ �Է�
void Date::inputDate()
{
	int y, m, d;
	cout << "Enter date in year month day : ";
	cin >> y >> m >> d;
	if (isValidDate(y, m, d))
	{
		year = y;
		month = m;
		day = d;
	}
	else {
		cout << "Ilegal date! Program aborted.\n";
		exit(1);
	}
}

bool Date::isValidDate(int y, int m, int d)
{
	int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(y))
		days_month[2] = 29;
	if ((m >= 1) && (m <= 12) &&
		(d >= 1) && (d <= days_month[m]))
	{
		return true;
	}
	else
	{
		cout << "Ilegal date! (" << m << ", "
			<< d << ") ==> Program aborted.\n";
		return false;
	}
}

// ��¥ ���
void Date::printDate()
{
	const char* weekDayName[7] = { "Sunday",
	"Monday", "Tuesday", "Wednesday",
	"Thursday", "Friday", "Saturday" };
	const char* monthName[13] = { "", "January",
	"February", "March", "April", "May",
	"June", "July", "August", "September",
	"October", "November", "December" };
	int yearDay = 0;
	int weekDay;
	char todayWeekDayName[10];
	if ((month >= 1) && (month <= 12))
		cout << string(monthName[month]);
	cout << " " << day << ", " << year;
	yearDay = getYearDay();
	weekDay = getWeekDay();
	cout << " ("
		<< string(weekDayName[weekDay])
		<< ")";
}

// ��¥���_����
void Date::fprintDate(ostream& fout)
{
	const char* weekDayName[7] = { "Sunday",
	"Monday", "Tuesday", "Wednesday",
	"Thursday", "Friday", "Saturday" };
	const char* monthName[13] = { "", "January",
	"February", "March", "April", "May",
	"June", "July", "August", "September",
	"October", "November", "December" };
	int yearDay = 0;
	int weekDay;
	char todayWeekDayName[10];
	if ((month >= 1) && (month <= 12))
		fout << setw(10) << string(monthName[month]);
	else
		fout << string("something wrong!!");
	fout << " " << setw(2) << day << ", " << setw(4) << year;
	yearDay = getYearDay();
	weekDay = getWeekDay();
	fout << " ("
		<< string(weekDayName[weekDay])
		<< ")";
}