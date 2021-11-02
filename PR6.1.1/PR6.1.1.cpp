#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int n, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < n - 1)
		Create(a, n, Low, High, i + 1);
}

void Print(int* a, const int n, int i)
{
	cout << setw(4) << a[i];
	if (i < n - 1)
		Print(a, n, i + 1);
	else
		cout << endl;
}

int Count(int* a, const int n, int i, int count)
{
	if (a[i] > 0 && abs(a[i]) % 5 != 0)
		count++;
	if (i < n - 1)
		return Count(a, n, i + 1, count);
	else
		return count;
}

void Zero(int* a, const int n, int i)
{
	if (a[i] > 0 && abs(a[i]) % 5 != 0)
	a[i] = 0;
	if (i < n - 1)
		return Zero(a, n, i + 1);
}

int Sum(int* a, const int n, int i, int S)
{
	if (a[i] > 0 && abs(a[i]) % 5 != 0)
		S += a[i];
	if (i < n - 1)
		return Sum(a, n, i + 1, S);
	else
		return S;
}

int main()
{
	srand((unsigned)time(NULL)); 

	const int n = 20;
	int a[n];

	int Low = -20;
	int High = 50;

	Create(a, n, Low, High, 0);
	Print(a, n, 0);

	cout << "S = " << Sum(a, n, 0, 0) << endl;
	cout << "Count = " << Count(a, n, 0, 0) << endl;

	Zero(a, n, 0);
	Print(a, n, 0);

	return 0;
}