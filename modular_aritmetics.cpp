#include "modular_aritmetics.h"
#include <iostream>

//1
int fillArray(int* arr, unsigned n)
{
	for (unsigned i = 0; i < n; i++) 
	{
		arr[i] = i;
	}
	return 0;
}

//2
int add(unsigned n, int a, int b)
{
	return (a + b) % n;
}

//3
int sub(unsigned n, int a, int b)
{
	const unsigned remainder_a = a % n;
	const unsigned remainder_b = b % n;
	return (remainder_a + (n - remainder_b)) % n;
}

//4
int multiply(unsigned n, int a, int b)
{
	return (a * b) % n;
}

int printRing(int* arr, unsigned n)
{
	for (unsigned i = 0; i < n; i++) 
	{
		std::cout << arr[i];
		if (i < n-1) 
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
	return 0;
}

//5
int recNumbers(int** arr, unsigned n)
{
	int res = 0;
	for (unsigned i = 0; i < n; i++)
	{
		arr[0][i] = i;
		for (unsigned j = 0; j < n; j++)
		{
			res = (i * j) % n;
			if (res == 1) 
			{
				arr[1][i] = j;
			}
			
		}	
	}
	return 0;
}

void printRecNum(int** arr, unsigned n)
{
	std::cout << "The residual ring and its reciprocal elements: " << std::endl;
	for (unsigned i = 0; i < 2; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//6
int recElement(int** arr, unsigned n, int elem)
{
	std::cout << arr[1][elem];
	return 0;
}

//7
unsigned bezoutCoeficient(unsigned n, int elem)
{
	long long s1 = 1;
	long long t1 = 0;
	long long s2 = 0;
	long long t2 = 1;
	long long r1 = elem;
	long long r2 = n;
	while (r2 != 0) 
	{
		long long q = r1 / r2;
		long long temp = r2;
		r2 = r1 - q * r2;
		r1 = temp;
		temp = s2;
		s2 = s1 - q * s2;
		s1 = temp;
		temp = t2;
		t2 = t1 - q * t2;
		t1 = temp;
	}
	const long long m = n;
	const long long y = (s1 < 0) ? (m + s1) : s1;
	return y % m;
}

//8
int Division(int** arr,unsigned n, int a, int b)
{
	int p = arr[1][b];
	if (p == 0) 
	{
		std::cout << -1;
	}
	return (a * p) % n;
}

//9 
int fastPower1(unsigned n, unsigned base, unsigned pow)
{
	int k = 0;
	int res = 1;
	for (unsigned i = 1; i < pow; i++) 
	{
		res = (res * base) % n;
		if (res == 1)
		{
			k = i;
			break;
		}
	}
	const unsigned r = (k == 0) ? pow : pow % k;
	for (unsigned i = 0; i < r; i++) 
	{
		res = (res * base) % n;
	}
	return res;
}

//10
int fastPower2(unsigned n, unsigned base, unsigned pow)
{
	unsigned res = 0;
	unsigned pow_res = base;
	unsigned i = 1;
	while (i < pow)
	{
		if ((pow & i) == 1) 
		{
			res += pow_res;
		}
		pow_res = multiply(n, pow_res, pow_res);
		i = i << 1;
	}
	return pow_res;
}

//11
int isPrimRoot(int* arr, unsigned n, int g)
{
	unsigned cnt = 0;
	int tmp;
	for (unsigned i = 1; i < n; i++) 
	{
		tmp = pow(g, i);
		arr[i] = tmp % n;
	}
	for (unsigned i = 1; i < n; i++) 
	{
		for (unsigned j = i + 1; j < n; j++) 
		{
			if (arr[i] == arr[j])
			{
				cnt++;
			}
		}
	}
	if (cnt == 0) 
	{
		std::cout << "The number " << g << " is a prime root." << std::endl;
	}
	else 
	{
		std::cout << "The number " << g << " is not a prime root." << std::endl;
	}
	return  0;
}

//14
int residualField(unsigned n)
{
	unsigned cnt = 0;
	for (unsigned i = 2; i < n; i++) 
	{
		if ((n % i) != 0) 
		{
			cnt++;
		}
	}
	if (cnt == (n - 2)||n == 1) 
	{
		std::cout << "The residual ring of " << n << " is a residual field." << std::endl;
	}
	else 
	{
		std::cout << "The residual ring of " << n << " is not a residual field." << std::endl;
	}
	return 0;
}



