#include <iostream>
#include <string>

using namespace std;

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

	char B[1001];
	strncpy_s(B, b.c_str(), sizeof(B));
	B[sizeof(B) - 1] = 0;


	int AB[1002];

	int ostatok = ((A[la - 1] - 48) + (B[lb - 1] - 48)) % 10;
	AB[0] = ostatok;
	
	int perenos = ((A[la - 1] - 48) + (B[lb - 1] - 48)) / 10;
	int minlength = min(la, lb);

	for (int i = 1; i <= (minlength-1); i++) 
	{
		ostatok = (((A[la-i-1] - 48) + (B[lb-i-1] - 48)) + perenos) % 10;
		AB[i] = ostatok;
		perenos = (((A[la - i - 1] - 48) + (B[lb - i - 1] - 48)) + perenos) / 10;

	}

	if (minlength == lb)
	{

		for (int i = lb; i <= la-1; i++) 
		{
			ostatok = ((A[la - i - 1] - 48) + perenos) % 10;
			AB[i] = ostatok;
			perenos = ((A[la - i - 1] - 48) + perenos) / 10;
		}
		AB[la] = perenos;
	}
	else 
	{
		for (int i = la; i <= lb-1; i++)
		{
			ostatok = ((B[lb - i - 1] - 48) + perenos) % 10;
			AB[i] = ostatok;
			perenos = ((B[lb - i - 1] - 48) + perenos) / 10;
		}
		AB[lb] = perenos;
	}

	int maxlength = max(la, lb);

	for (int x = maxlength; x >= 0; x--) 
	{
		if (AB[x] == 0) 
		{
			continue;
		}
		cout << AB[x];
	}







	return 0;
}