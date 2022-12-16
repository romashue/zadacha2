#include <iostream>
#include <string>

using namespace std;



int* NUMBERxFIGURE(char number[1002], int size, int figure, int natural) 
{
	int pr[1002];
	int result[2002];

	int ostatokk = ((number[size-1]) * figure) % 10;
	pr[0] = ostatokk;
	int perenoss = ((number[size - 1]) * figure) / 10;
	
	for (int i = 1; i < size; i++) 
	{
		ostatokk = ((number[size - i - 1]) * figure + perenoss) % 10;
		pr[i] = ostatokk;
		perenoss = ((number[size - i - 1]) * figure + perenoss) / 10;
	}
	pr[size] = perenoss;
	for (int i = 0; i < (2002 - size - natural); i++) 
	{
		result[i] = 0;
	}
	int j = size;
	for (int i = (2002 - size - natural - 1); i < (2002 - natural); i++)
	{
		result[i] = pr[j];
		j--;
	}
	for (int i = 2002 - natural; i < 2002; i++) 
	{
		result[i] = 0;
	}
	
	return result;
}

int main()
{
	setlocale(LC_ALL, "ru");

	string a;
	string b;

	cout << "Число a: ";
	cin >> a;
	cout << "Число b: ";
	cin >> b;

	int la = a.length();
	int lb = b.length();

	char A[1001];
	strncpy_s(A, a.c_str(), sizeof(A));
	A[sizeof(A) - 1] = 0;

	for (int i = 0; i < la; i++) 
	{
		A[i] -= 48;
	}

	char B[1001];
	strncpy_s(B, b.c_str(), sizeof(B));
	B[sizeof(B) - 1] = 0;

	for (int i = 0; i < lb; i++)
	{
		B[i] -= 48;
	}

	int AB[2002];
	
	int maxlength = max(la, lb);
	int minlength = min(la, lb);

	int sumelements[2002];

	if (maxlength == la) 
	{
		int* R1 = NUMBERxFIGURE(A, la, B[lb - 1], 0);
		for (int j = 0; j < 2002; j++)
		{
			sumelements[j] = R1[j];
		}
		for (int i = 1; i < minlength; i++)
		{
			int* Ri = NUMBERxFIGURE(A, la, B[lb - i - 1], i);
			for (int j = 0; j < 2002; j++) 
			{
				sumelements[j] += Ri[j];
			}
		}
	}
	else 
	{
		int* R1 = NUMBERxFIGURE(B, lb, A[la - 1], 1);
		for (int j = 0; j < 2002; j++)
		{
			sumelements[j] = R1[j];
		}
		for (int i = 1; i < minlength; i++)
		{
			int* Ri = NUMBERxFIGURE(B, lb, A[la - i - 1], i);
			for (int j = 0; j <= 2002; j++)
			{
				sumelements[j] += Ri[j];
			}
		}
	}

	
	int ostatok = (sumelements[2001]) % 10;
	AB[2001] = ostatok;
	int perenos = (sumelements[2001]) / 10;
	for (int i = 2000; i >= 1;i--) 
	{
		ostatok = (sumelements[i] + perenos) % 10;
		AB[i] = ostatok;
		perenos = (sumelements[i] + perenos) / 10;
	}

	AB[0] = perenos;

	if (AB[2002 - (la + lb)] != 0) 
	{
		cout << AB[2002 - (la + lb)];
	}

	for (int i = (2002 - (la + lb) + 1); i < 2002; i++)
	{
		cout << AB[i];
	}

	cout << endl << endl;

	return 0;
}