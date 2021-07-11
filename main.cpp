#include <iostream>
#include "modular_aritmetics.h"

using namespace std;

int main() {
	cout << "\tMenu:" << endl;
	cout << "0. End the program." << endl;
	cout << "1. Showing the remainders of a modul." << endl;
	cout << "2. Addition of two numbers by a modul." << endl;
	cout << "3. Subtraction of two numbers by a modul." << endl;
	cout << "4. Multiplication of two numbers by a modul." << endl;
	cout << "5. Showing the remainders of a modul and their reciprocal elements." << endl;
	cout << "6. Choosing a number from the remainders of a modul and showing its reciprocal element." << endl;
	cout << "7. Choosing a number from the remainders of a modul and showing its reciprocal element estimated with the bezout " << endl << " coeficients." << endl;
	cout << "8. Devision of two elements chosen from the remainders of a modul that will give a value of -1 if the devision is not " << endl << " possible." << endl;
	cout << "9. The fast grading of a number by a modul with the first approach." << endl;
	cout << "10. The fast grading of a number by a modul with the second approach." << endl;
	cout << "11. Is a given number a prime root in Zn." << endl;
	cout << "14. Tells you if a residual ring is a residual field or not." << endl;

	int menu;
	unsigned n; 
	cout << endl << "Please enter the modul: ";
	cin >> n;
	
	int* ring = new int[n];
	fillArray(ring, n);

	int** isDivisor = nullptr;
	isDivisor = new int* [2];
	for (unsigned i = 0; i < 2; i++)
	{
		isDivisor[i] = new int[n] {0};
	}

	int* prime = new int[n];

	do {
		cout << endl;
		cout << "Choose one option from the menu: ";
		cin >> menu;

		//1
		if (menu == 1) 
		{
			cout << "The set of the residual ring of modul " << n << " is: ";
			printRing(ring, n);
		}

		//2
		if (menu == 2) 
		{
			int a, b;
			cout << "Please enter a number for the operation: ";
			cin >> a;
			cout << "Please enter the secont number needed for the operation: ";
			cin >> b;
			cout << "The addition of " << a << " and " << b << " by modul " << n << " is: ";
			cout << add(n, a, b) << endl;
		}

		//3
		if (menu == 3) 
		{
			int a, b;
			cout << "Please enter a number for the operation: ";
			cin >> a;
			cout << "Please enter the secont number needed for the operation: ";
			cin >> b;
			cout << "The subtraction of " << a << " and " << b << " by modul " << n << " is: ";
			cout << sub(n, a, b) << endl;
		}

		//4
		if (menu == 4) 
		{
			int a, b;
			cout << "Please enter a number for the operation: ";
			cin >> a;
			cout << "Please enter the secont number needed for the operation: ";
			cin >> b;
			cout << "The multiplication of " << a << " and " << b << " by modul " << n << " is: ";
			cout << multiply(n, a, b) << endl;
		}

		//5
		if (menu == 5) 
		{
			recNumbers(isDivisor, n);
			printRecNum(isDivisor, n);
		}

		//6
		if (menu == 6) 
		{
			recNumbers(isDivisor, n);
			int rel;
			do
			{
				cout << "Please enter a whole number ranging from 0 to the modul you have chosen: ";
				cin >> rel;
			} while (rel < 0 || rel > n);
			cout << "The reciprocal element of the number " << rel << " from the residual ring of modul " << n << " is: ";
			recElement(isDivisor, n, rel);
			cout << endl;
		}

		//7
		if (menu == 7) 
		{
			int _rel;
			do
			{
				cout << "Please enter a whole number ranging from 0 to the modul you have chosen: ";
				cin >> _rel;
			} while (_rel < 0 || _rel > n);
			cout << "The reciprocal element of the number " << _rel << " from the residual ring of modul " << n << " estimated with the bezout coeficient is: ";
			cout << endl << bezoutCoeficient(n, _rel) << endl;
		}

		//8
		if (menu == 8) 
		{
			int a, b;
			recNumbers(isDivisor, n);
			cout << "Please enter a number for the devision: ";
			cin >> a;
			cout << "Please enter one more number for the devision: ";
			cin >> b;
			cout << "The answer is: ";
			cout << Division(isDivisor, n, a, b) << endl;
		}

		//9
		if (menu == 9) 
		{
			unsigned base, pow;
			cout << "Please enter a number for the base: ";
			cin >> base;
			cout << "Please enter a number for power of the power: ";
			cin >> pow;
			cout << "The first approach for the fast grading of number " << base << " with the power " << pow << " is: ";
			cout << fastPower1(n, base, pow) << endl;
		}

		//10
		if (menu == 10) 
		{
			unsigned base, pow;
			cout << "Please enter a number for the base: ";
			cin >> base;
			cout << "Please enter a number for power of the power: ";
			cin >> pow;
			cout << "The second approach for the fast grading of number " << base << " with the power " << pow << " is: ";
			cout << fastPower2(n, base, pow) << endl;
		}

		//11
		if (menu == 11) 
		{
			int g;
			do 
			{
				cout << "Please give a number smaller than the modul: ";
				cin >> g;
			} while (g < 1 || g >= n);
			isPrimRoot(prime, n, g);
		}

		//14
		if (menu == 14) 
		{
			residualField(n);
		}

	} while (menu != 0);

	if (prime != nullptr) 
	{
		delete[] prime;
		prime = nullptr;
	}

	for (unsigned i = 0; i < n; i++)
	{
		delete[] isDivisor[i];
	}
	delete[] isDivisor;
	isDivisor = nullptr;

	if (ring != nullptr)
	{
		delete[] ring;
		ring = nullptr;
	}

	return 0;
}
