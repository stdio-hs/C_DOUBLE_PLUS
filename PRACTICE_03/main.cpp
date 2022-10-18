/*

���ϸ� : PRACTICE_03

���α׷��� ���� �� �⺻��� :
 - 1 ~ 32�� ��� ���� (10����, 8����, 16����, 2���� ) ���� �� ���

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 09�� 12�� ~ 2022�� 09�� 14��

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

		// 10����
		cout << dec << num;
		cout.width(10);

		// 8����
		cout << showbase << oct << num; 
		cout.width(10);
		
		// 16���� �빮��
		cout << showbase << hex << uppercase << num; 
		cout.width(10);

		// 2����
		cout << bitset<8>(num) << endl; 
	}
}