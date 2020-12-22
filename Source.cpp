#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std; //���������� ���������

//����������� � ������������ ��������� ��� ������� �����, ����� ������� �������.
enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

//������� ������ ������ ������ � ������, ����������� ������ ����� ������.
void PrintSizeof() {

	const int DataTypeAmount = 12;

	COORD position; //�������������� ������� ��������� ��������� ������� �� �����������.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //�������������� ������� ����������� �������.

	SetConsoleTextAttribute(hConsole, (WORD)((Magenta << 4) | White)); //������ ��� � ����� � ����� �����.

	for (int i = 0; i != DataTypeAmount; i++) {

		switch (i) {

		case 0: cout << "int:                " << sizeof(int) << endl; break;
		case 1: cout << "unsigend int:       " << sizeof(unsigned int) << endl; break;
		case 2: cout << "short:              " << sizeof(short) << endl; break;
		case 3: cout << "unsigned short:     " << sizeof(unsigned short) << endl; break;
		case 4: cout << "long:               " << sizeof(long) << endl; break;
		case 5: cout << "unsigned long:      " << sizeof(unsigned long) << endl; break;
		case 6: cout << "float:              " << sizeof(float) << endl; break;
		case 7: cout << "double:             " << sizeof(double) << endl; break;
		case 8: cout << "long double:        " << sizeof(long double) << endl; break;
		case 9: cout << "char:               " << sizeof(char) << endl; break;
		case 10: cout << "unsigned char:      " << sizeof(unsigned char) << endl; break;
		case 11: cout << "bool:               " << sizeof(bool) << endl; break;
		}
	}

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White)); //���������� ���� � ������������ � ������ ����� �������.

	for (int i = 0; i != (DataTypeAmount + 1); i++) {

		position.X = 21;
		position.Y = i;
		SetConsoleCursorPosition(hConsole, position);
		cout << " |";
	}

	position.X = 0;
	position.Y = 12;
	SetConsoleCursorPosition(hConsole, position);
	cout << "______________________" << endl;


}


int main() {

	int Action, SubAction; //���������� ���������� ��� ���������� switch
	int joker = 0; //������� ������������ �������� � ����

	int value_int; //�������� ���

	union { //�������� �����. ������� ������ ����� ��������� ����� int ���������� � ����� union. 
		float value_float;
		int float_tool;
	};

	union { //�������� ����. ������� ������ ����� ��������� ����� ��� int ���������� ����������� � ������ � ����� union.
		double value_double;
		int double_tool[2]; //��������� ������ ������� � 2 ��� ���������� (4+4 = 8 ����)
	};

	unsigned int order = 32; //���������� ��������.
	unsigned int mask = 1 << (order - 1); //����� ���������� ���������.

	int intArr[32];
	int floatArr[32];
	int doubleArr[64];
	int changeNum = 0;
	bool check = true;

restart: //����� �������� � ������� ����.

	system("cls"); //������� �������

	PrintSizeof(); //�������� ������� ��������� �����

	printf("The amount of an occupated memory for each of data types is displayed upwards.\n\nWhat would you like to do?\n\nDisplay the binary representation of an integer           --  1\nDisplay the binary representation of a float type         --  2\nDisplay the binary representation of a double float type  --  3\n\nExit  --  4\n");

	cin >> Action; //���������� ��� ������ ������ ����

	switch (Action) {
	case 1:
	return1: //����� �������� ��� ���������� �����.
		system("cls");

		printf("Enter the integer value that you wanna represent.\n");
		cin >> value_int; //�������� int ��� ��������� �������������.




		for (int i = 0; i != order; i++) // ���������� ��������� ������������� � ������
		{
			if (value_int & mask)
			{
				intArr[i] = 1;
			}
			else {
				intArr[i] = 0;
			}
			value_int <<= 1;
		}

	ret1:
		system("cls");
		cout << "Here is binary representation of an integer number " << value_int << "\n\n";

		for (int i = 1; i != 33; i++) {
			cout << intArr[i - 1];
			if (i % 8 == 0) //���������� ����� ��� ��������
			{
				printf(" ");
			}
			if (i % order - 1 == 0)
			{
				printf(" ");
			}

		}




		printf("\n\nTry another number    --  1\nChange some bits      -- 2\nExit to main menu     --  Any\n");
		cin >> SubAction; //����� ��������� ���� � ����� ������

		switch (SubAction) {
		case 1:

			goto return1;
			break;

		case 2:
			printf("Enter a number of bit u wanna change: ");

			cin >> changeNum;
			if (changeNum < 33 && changeNum > 0) {
				if (intArr[changeNum - 1] == 1) {
					intArr[changeNum - 1] = 0;
				}
				else {
					intArr[changeNum - 1] = 1;
				}
				goto ret1;
				break;
			}
			else {
				printf("\n\nThere are no bits in this position");
				Sleep(1500);
				goto ret1;
				break;
			}

		default:

			goto restart;
			break;

		}

		joker = 0; // ��������� �������� ������������ ������
		break;
	case 2:

	return2: //������ ��������
		system("cls");

		printf("Enter the float value that you wanna represent.\n");
		cin >> value_float; //�������� �������� �������� �� ������������

		for (int i = 0; i != order; i++)
		{
			if (float_tool & mask)
			{
				floatArr[i] = 1;
			}
			else {
				floatArr[i] = 0;
			}
			float_tool <<= 1;
		}

	ret2:

		system("cls");

		cout << "Here is binary representation of a float number " << value_float << "\n\n";

		for (int i = 1; i != 33; i++)
		{
			cout << floatArr[i - 1];

			if (i % 8 == 0)
			{
				printf(" ");
			}
			if (i % order - 1 == 0)
			{
				printf(" ");
			}
		}

		printf("\n\nTry another number    --  1\nChange some bits      -- 2\nExit to main menu     --  Any\n");
		cin >> SubAction;

		switch (SubAction) {
		case 1:

			goto return2;
			break;
		case 2:
			printf("Enter a number of bit u wanna change: ");

			cin >> changeNum;
			if (changeNum < 33 && changeNum > 0) {
				if (floatArr[changeNum - 1] == 1) {
					floatArr[changeNum - 1] = 0;
				}
				else {
					floatArr[changeNum - 1] = 1;
				}
				goto ret2;
				break;
			}
			else {
				printf("\n\nThere are no bits in this position");
				Sleep(1500);
				goto ret2;
				break;
			}
		default:

			goto restart;
			break;

		}

		joker = 0;
		break;
	case 3:

	return3:
		system("cls");

		printf("Enter the double float value that you wanna represent.\n");
		cin >> value_double;

		for (int i = 0; i != order; i++) // ���������� ������ 32 ����
		{
			if (double_tool[0] & mask)
			{
				doubleArr[i] = 1;
			}
			else {
				doubleArr[i] = 0;
			}
			double_tool[0] <<= 1;
		}
		for (int i = 32; i != 64; i++) // ���������� ��������� 32 ����
		{
			if (double_tool[1] & mask)
			{
				doubleArr[i] = 1;
			}
			else {
				doubleArr[i] = 0;
			}
			double_tool[1] <<= 1;
		}

	ret3:

		system("cls");

		cout << "Here is binary representation of a double float number " << value_double << "\n\n";

		for (int i = 1; i != 65; i++) // ������� ������� ������������� �����
		{
			cout << doubleArr[i - 1];

			if (i % 8 == 0)
			{
				printf(" ");
			}
			if (i % order - 1 == 0 && check)
			{
				printf(" ");
				check = false; // �������� �� ��, ��� �� ������ ����� ��������� ���� �������� ��������� ( 1 ��� )
			}
		}
		check = true;
		printf("\n\nTry another number    --  1\nChange some bits      -- 2\nExit to main menu     --  Any\n");
		cin >> SubAction;

		switch (SubAction) {
		case 1:

			goto return3;
			break;
		case 2:
			printf("Enter a number of bit u wanna change: ");

			cin >> changeNum;
			if (changeNum < 65 && changeNum > 0) {
				if (doubleArr[changeNum - 1] == 1) {
					doubleArr[changeNum - 1] = 0;
				}
				else {
					doubleArr[changeNum - 1] = 1;
				}
				goto ret3;
				break;
			}
			else {
				printf("\n\nThere are no bits in this position");
				Sleep(1500);
				goto ret2;
				break;
			}


		default:

			goto restart;
			break;

		}


		joker = 0;
		break;
	case 4:
		exit(0); //����� �� ���������.
		break;

	default:
		if (joker < 3) { //���������, ������� ��� ���� ������� ������������ ��������.
			printf("\nWrong symbol. Try again."); //����� ��������� �� ������.
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(500);

			++joker; //��������� �������� ������������ ������.
		}
		else {
			printf("\n?)\naM i A jOkE tO YoU??? THAT's a WRONG symbol.\nTry again."); //�������������� ������
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");
			Sleep(3000);

			joker = 0; //�������� ������� ������������ ��������.
		}
		break;
	}


	system("cls");
	goto restart;

	return 0;
}