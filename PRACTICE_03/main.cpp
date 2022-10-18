/*

파일명 : PRACTICE_03

프로그램의 목적 및 기본기능 :
 - 1 ~ 32의 출력 포멧 (10진수, 8진수, 16진수, 2진수 ) 지정 및 출력

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 09월 12일 ~ 2022년 09월 14일

*/

#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

void main()
{
	for (int num = 0; num < 33; num++)
	{

		cout.setf(ios::right);
		cout.width(10); 

		// 10진수
		cout << dec << num;
		cout.width(10);

		// 8진수
		cout << showbase << oct << num; 
		cout.width(10);
		
		// 16진수 대문자
		cout << showbase << hex << uppercase << num; 
		cout.width(10);

		// 2진수
		cout << bitset<8>(num) << endl; 
	}
}