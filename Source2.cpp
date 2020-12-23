#include <iostream>
#include <time.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;


// генерация массива
void Gen(int* Arr, const int n) {


	srand(time(0)); //точка отсчёта рандома - системное время

	for (int i = 0; i != n; i++) { //генерируем случайный массив

		Arr[i] = rand() % 198 - 99;
	}


}


//сортировки
double* SortT(int* Arr, const int n) {

	int SortArr[100];

	double SortTime[5];

	int Left = 0;
	int Right = n - 1;
	bool Flag = true;

	double Factor = 1.2473309;
	int Step = n - 1;



	for (int i = 0; i != n; i++) //пузырьковая
	{
		SortArr[i] = Arr[i];
	}

	clock_t t1 = clock();
	for (int i = 0; i < n; i++) {
		for (int j = (n - 1); j >= (i + 1); j--) {
			if (SortArr[j] < SortArr[j - 1]) {
				swap(SortArr[j], SortArr[j - 1]);
			}
		}
	}
	clock_t t2 = clock();

	SortTime[0] = (t2 - t1 + .0) / CLOCKS_PER_SEC;


	for (int i = 0; i != n; i++) //шейкер
	{
		SortArr[i] = Arr[i];
	}

	t1 = clock();
	while (Left <= Right && Flag != false)
	{
		Flag = false;
		for (int i = Left; i < Right; i++) {

			if (SortArr[i] > SortArr[i + 1]) {

				swap(SortArr[i], SortArr[i + 1]);
				Flag = true;
			}
		}
		Right--;
		for (int i = Right; i > Left; i--) {

			if (SortArr[i - 1] > SortArr[i]) {

				swap(SortArr[i], SortArr[i - 1]);
				Flag = true;
			}
		}
		Left++;
	}
	t2 = clock();

	SortTime[1] = (t2 - t1 + .0) / CLOCKS_PER_SEC;


	for (int i = 0; i != n; i++) //расчёска
	{
		SortArr[i] = Arr[i];
	}

	t1 = clock();
	while (Step >= 1)
	{
		for (int i = 0; i + Step < n; i++)
		{
			if (SortArr[i] > SortArr[i + Step])
			{
				swap(SortArr[i], SortArr[i + Step]);
			}
		}
		Step /= Factor;
	}
	t2 = clock();

	SortTime[2] = (t2 - t1 + .0) / CLOCKS_PER_SEC;


	for (int i = 0; i != n; i++) //вставками
	{
		SortArr[i] = Arr[i];
	}

	t1 = clock();
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && SortArr[j - 1] > SortArr[j]; j--)
		{
			swap(SortArr[j], SortArr[j - 1]);
		}
	}
	t2 = clock();

	SortTime[3] = (t2 - t1 + .0) / CLOCKS_PER_SEC;


	return SortTime;
}


//рекурсивная qsort
void qSortT(int* Arr, int n) {



	int First = 0;
	int Last = n - 1;
	int Mid = Arr[n / 2];

	do {
		while (Arr[First] < Mid) {
			First++;
		}
		while (Arr[Last] > Mid) {
			Last--;
		}

		if (First <= Last) {
			swap(Arr[Last], Arr[First]);

			First++;
			Last--;
		}
	} while (First <= Last);


	if (Last > 0) {
		qSortT(Arr, Last + 1);
	}
	if (First < n) {
		qSortT(&Arr[First], n - First);
	}

}


//вывод массива на экран
void Print(int* ArrUS, int* Arr, const int n) {

	int Yax = 4;

	system("cls");
	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	printf("Here is a random-generated massive: \n \n         Unsorted                         Sorted\n_____________________________________________________________\n");

	for (int i = 0; i != n; i++) {

		if (i > 0 && i % 5 == 0) {
			printf("|\n");
		}
		if (ArrUS[i] >= 0) {
			cout << " ";
		}
		if (ArrUS[i] >= 0 && ArrUS[i] < 10) {
			cout << " ";
		}
		if (ArrUS[i] < 0 && ArrUS[i] > -10) {
			cout << " ";
		}


		cout << ArrUS[i] << "   ";
	}


	position.X = 31;
	position.Y = Yax;
	SetConsoleCursorPosition(hConsole, position);
	Yax++;

	for (int i = 0; i != n; i++) {

		if (i > 0 && i % 5 == 0) {
			printf("|");
			position.X = 31;
			position.Y = Yax;
			SetConsoleCursorPosition(hConsole, position);
			Yax++;
		}
		if (Arr[i] >= 0) {
			cout << " ";
		}
		if (Arr[i] >= 0 && Arr[i] < 10) {
			cout << " ";
		}
		if (Arr[i] < 0 && Arr[i] > -10) {
			cout << " ";
		}


		cout << Arr[i] << "   ";
	}

	position.X = 30;
	position.Y = 23;
	SetConsoleCursorPosition(hConsole, position);
	cout << "|";
	position.X = 61;
	position.Y = 23;
	SetConsoleCursorPosition(hConsole, position);
	cout << "|";
	position.X = 0;
	position.Y = 24;
	SetConsoleCursorPosition(hConsole, position);
	cout << "--------------------------------------------------------------\n\n";
}


//поиск минимального и максимального
void MinMax(int* ArrUS, int* Arr, const int n) {
	int Min = 100;
	int Max = -100;
	int Menu;

again:
	clock_t t1 = clock();
	for (int i = 0; i != n; i++) {
		if (ArrUS[i] < Min) {
			Min = ArrUS[i];
		}
		if (ArrUS[i] > Max) {
			Max = ArrUS[i];
		}
	}
	clock_t t2 = clock();

	clock_t t3 = clock();
	for (int i = 0; i != n; i++) { //можно просто Min = Arr[0]; Max = Arr[n-1]; ???
		if (Arr[i] < Min) {
			Min = Arr[i];
		}
		if (Arr[i] > Max) {
			Max = Arr[i];
		}
	}
	clock_t t4 = clock();

	system("cls");

	cout << "The Min value is: " << Min << "\nThe Max value is: " << Max << "\n\nIt has taken " << (t2 - t1 + .0) / CLOCKS_PER_SEC << " sec to find it in unsorted array" << "\nIt has taken " << (t4 - t3 + .0) / CLOCKS_PER_SEC << " sec to find it in sorted array\n\nPress 1 to exit\n";
	cin >> Menu;
	switch (Menu)
	{
	case 1: break;
	default: printf("\nWrong Symbol! Try again"); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); goto again;
	}
}


//ищем среднее
void Avrg(int* Arr, const int n) {

	int counter = 0;
	int AvrgV = (Arr[0] + Arr[n - 1]) / 2;
	bool check = false;
	int Menu;
	system("cls");
	cout << "The averege between min and max values is: " << AvrgV;

	for (int i = 0; i != n; i++) {
		if (AvrgV == Arr[i]) {
			counter++;
			check = true;
		}
	}
again:
	if (check) {
		cout << "\nThere are " << counter << " equal values in the array\nAnd their indexes are: ";
		for (int i = 0; i != n; i++) {
			if (AvrgV == Arr[i]) {
				cout << i << " ";
			}
		}
	}
	else {
		cout << "\nThere are no equal values in the array";
	}

	cout << "\n\nPress 1 to exit\n";

	cin >> Menu;
	switch (Menu)
	{
	case 1: break;
	default: printf("\nWrong Symbol! Try again"); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); goto again;
	}
}


//поиск элементов относительно пользовательских данных
void ABStuff(int* Arr, const int n) {
	int a, b;
	int counterA = 0;
	int counterB = 0;
	int Menu;
again:
	system("cls");
	printf("You want to find number of values less than: ");
	cin >> a;
	printf("\nYou want to find number of values greater than: ");
	cin >> b;
	for (int i = 0; i != n; i++) {
		if (Arr[i] < a) {
			counterA++;
		}
		if (Arr[i] > b) {
			counterB++;
		}
	}
	if (counterA == 0) {
		cout << "\nThere are no values less than " << a;
	}
	else {
		cout << "\nThere are " << counterA << " values less than " << a;
	}
	if (counterB == 0) {
		cout << "\nThere are no values greater than " << b;
	}
	else {
		cout << "\nThere are " << counterB << " values greater than " << b;
	}
	counterB = 0;
	counterA = 0;
	cout << "\n\nPress 1 to exit\nPress 2 to try again\n";

	cin >> Menu;
	switch (Menu)
	{
	case 1: break;
	case 2: goto again;
	default: printf("\nWrong Symbol! Try again"); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); goto again;
	}
}


//бинарный поиск и поиск перебором
void Search(int* Arr, const int n) {

	int Num;
	bool check = false;
	int index;


	int Left = 0;
	int Right = n - 1;
	int Mid;
	bool flag = false;

	int Menu;
	int Menu2;

	double time1;

	clock_t t1, t2;
again2:
	system("cls");

	printf("Enter a number you want to find in the array: ");
	cin >> Num;

again:
	printf("Which method do u want to use?\n\nDefault    -- 1\nBinary     -- 2");

	cin >> Menu;
	switch (Menu) {
	case 1: { // поиск перебором
		t1 = clock();
		for (int i = 0; i != n; i++) {
			if (Arr[i] == Num) {
				check = true;
				index = i;
			}
		}
		t2 = clock();
		break;
	}

	case 2: {	// бинарный поиск
		t1 = clock();
		while ((flag != true) && (Left <= Right)) {
			Mid = (Left + Right) / 2;

			if (Num > Arr[Mid]) {
				Left = Mid + 1;
			}
			else if (Num < Arr[Mid]) {
				Right = Mid - 1;
			}
			else {
				check = true;
				index = Mid;
				flag = true;
			}
		}
		t2 = clock();
		break;
	}
	default: printf("\nWrong Symbol! Try again"); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); goto again;

	}
	if (check) {
		cout << "\n\nThe array include your number " << Num << ". And it's index is " << index;
		check = false;
	}
	else {
		cout << "\n\nThe array does not include your number " << Num;
	}

	cout << "\n\nIt has taken " << (t2 - t1 + .0) / CLOCKS_PER_SEC << " sec to find it out";

	cout << "\n\nPress 1 to exit\nPress 2 to try again\n";

	cin >> Menu2;
	switch (Menu2)
	{
	case 1: break;
	case 2: goto again2;
	default: printf("\nWrong Symbol! Try again"); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); goto again;
	}
}


//обмен
void Exchange(int* Arr, const int n) {
	int index1, index2;

	int Menu;
	int NewArr[100];

	int counter[9];


again:

	for (int i = 0; i != 9; i++) {
		counter[i] = 0;
	}

	for (int i = 0; i != n; i++) {
		NewArr[i] = Arr[i];
	}

	system("cls");

	printf("Exchange 2 numbers                         -- 1\nSum every current and next value           -- 2\nMix every number                           -- 3\nAmount of elements that can be divided     -- 4\nExit        -- 5\n");

	cin >> Menu;

	switch (Menu)
	{
	case 1:

		system("cls");
		printf("Enter 2 indexes of a numbers you  want to exchange: ");
		cin >> index1 >> index2;

		swap(Arr[index1], Arr[index2]);
		break;

	case 2:

		for (int i = 0; i != (n - 1); i++) {
			Arr[i] = NewArr[i] + NewArr[i + 1];
		}
		Arr[n - 1] = NewArr[n - 1] + NewArr[0];
		break;

	case 3:

		srand(time(0));
		for (int i = 0; i != n; i++) {
			Arr[i] = NewArr[0 + rand() % 99];
		}

		break;

	case 4:
		for (int i = 0; i != n; i++) {
			if (NewArr[i] % 1 == 0) {
				counter[0]++;
			}
			if (NewArr[i] % 2 == 0) {
				counter[1]++;
			}
			if (NewArr[i] % 3 == 0) {
				counter[2]++;
			}
			if (NewArr[i] % 4 == 0) {
				counter[3]++;
			}
			if (NewArr[i] % 5 == 0) {
				counter[4]++;
			}
			if (NewArr[i] % 6 == 0) {
				counter[5]++;
			}
			if (NewArr[i] % 7 == 0) {
				counter[6]++;
			}
			if (NewArr[i] % 8 == 0) {
				counter[7]++;
			}
			if (NewArr[i] % 9 == 0) {
				counter[8]++;
			}
		}
		system("cls");
		for (int i = 0; i != 9; i++) {
			cout << "There are " << counter[i] << " values that can be devided by " << i + 1 << endl;
		}
		printf("\nPress any key to return to main menu\n");
		system("pause");
		break;
	case 5: break;
	default: printf("\nWrong Symbol! Try again"); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); goto again;  break;

	}
}




int main() {

	const int n = 100;
	int Arr[n];
	int ArrUS[n];
	double* SortTime;

	int Menu;



reg:

	Gen(Arr, n);

	for (int i = 0; i != n; i++) {
		ArrUS[i] = Arr[i];
	}


	SortT(Arr, n);
	clock_t t1 = clock();
	qSortT(Arr, n);
	clock_t t2 = clock();
again:
	Print(ArrUS, Arr, n);






	SortTime = SortT(Arr, n);
	SortTime[4] = (t2 - t1 + .0) / CLOCKS_PER_SEC;




	cout << "Time taken for...\nBubble sort: " << SortTime[0] << " sec\nShaker sort: " << SortTime[1] << " sec\nComb sort: " << SortTime[2] << " sec\nInsert sort: " << SortTime[3] << " sec\nQuick sort: " << SortTime[4] << " sec\n\n\n";
	printf("Menu:\n\nMin and Max value                  -- 1\nAvrg value                         -- 2\nThe A and B stuff                  -- 3\nFind your number in the array      -- 4\nExchange numbers                   -- 5\nRegenerate                         -- 6\nExit                               -- 7\n");

	cin >> Menu;

	switch (Menu) {
	case 1: MinMax(ArrUS, Arr, n); goto again;
	case 2: Avrg(Arr, n);  goto again;
	case 3: ABStuff(Arr, n);  goto again;
	case 4: Search(Arr, n); goto again;
	case 5: Exchange(Arr, n); goto again;
	case 6: goto reg;
	case 7: goto stop;
	default: printf("\nWrong Symbol! Try again"); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); goto again;
	}




stop:
	return 0;
}

