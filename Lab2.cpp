#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool isPrime(long int prime)
{
	long int i, j;

	j = (long int)sqrt((long double)prime);

	for (i = 2; i <= j; i++)
	{
		if (prime % i == 0)
		{
			return false;
		}
	}

	return true;
}

long int greatestCommonDivisor(long int s, long int d)
{
	while (s > 0)
	{
		long int myTemp;

		myTemp = s;
		s = d % s;
		d = myTemp;
	}

	return d;
}

long int calculateS(long int d)
{
	// Выбирается целое число e ( 1 < e < d ) // взаимно простое со значением функции Эйлера (d)

	long int s;

	for (s = 2; s < d; s++)
	{
		if (greatestCommonDivisor(s, d) == 1)
		{
			return s;
		}
	}

	return -1;
}

long int calculateE(long int s, long int d)
{
	// Вычисляется число e, мультипликативно обратное к числу e по модулю ?(n), то есть число, удовлетворяющее сравнению:
	//    e ? s mod d = 1 (mod ?(n))

	long int e;
	long int k = 1;

	while (1)
	{
		k = k + d;

		if (k % s == 0)
		{
			e = (k / s);
			return e;
		}
	}

}

long int encrypt(long int i, long int s, long int n)
{
	long int current, result;

	current = i - 97;
	result = 1;

	for (long int j = 0; j < s; j++)
	{
		result = result * current;
		result = result % n;
	}

	return result;
}

long int decrypt(long int i, long int e, long int n)
{
	long int current, result;

	current = i;
	result = 1;

	for (long int j = 0; j < e; j++)
	{
		result = result * current;
		result = result % n;
	}

	return result + 97;
}


int main()
{
	setlocale(LC_ALL, "");
	long int p, q, n, d, s, e;

	long int encryptedText[100];
	memset(encryptedText, 0, sizeof(encryptedText));

	long int decryptedText[100];
	memset(decryptedText, 0, sizeof(decryptedText));

	bool flag;

	string msg;

	cout << "Алгоритм RCA" << endl << endl;

	//Cоздание открытого и секретного ключей
	//Выбираются два различных случайных простых числа p и q заданного размера

	do
	{
		cout << "Enter p :" << endl;
		cin >> p;
		flag = isPrime(p);

		if (flag == false)
		{
			cout << "\nОшибка!\n(Это число непростое!)\n" << endl;
		}
	} while (flag == false);


	do
	{
		cout << "Enter q :" << endl;
		cin >> q;
		flag = isPrime(q);

		if (flag == false)
		{
			cout << "\nОшибка!\n(Это число непростое!)\n" << endl;
		}
	} while (flag == false);

	//Вычисляется их произведение n = p ? q, которое называется модулем.
	n = p * q;
	cout << "\nРезультат вычисления: n = p*q = " << n << endl;

	//Вычисляется значение функции Эйлера от числа n
	d = (p - 1) * (q - 1);
	cout << "Результат вычисления: f(n) = d = (p-1)*(q-1) = " << d << endl;

	//Выбирается целое число e ( 1 < e < ?(n) ), взаимно простое со значением функции Эйлера (d)
	// Число e называется открытой экспонентой
	s = calculateS(d);

	//Вычисляется число e, мультипликативно обратное к числу e по модулю ?(n), то есть число, удовлетворяющее сравнению:
	//    e ? e ? 1 (mod ?(n))
	e = calculateE(s, d);

	// 6. Пара {s, n} публикуется в качестве открытого ключа RSA
	cout << "\nRSA открытый ключ (s = " << s << ", n = " << n << ")" << endl;

	// 7. Пара {d, n} играет роль закрытого ключа RSA и держится в секрете
	cout << "RSA закрытый ключ (e = " << e << ", n = " << n << ")" << endl;



	cout << "\nВведите текс для шифрования:" << endl;

	cin.ignore();

	getline(cin, msg);

	cout << msg << endl;

	// encryption
	for (long int i = 0; i < msg.length(); i++)
	{
		encryptedText[i] = encrypt(msg[i], s, n);
	}

	cout << "\nЗашифрованное сообщение:" << endl;

	for (long int i = 0; i < msg.length(); i++)
	{
		printf("%c", (char)encryptedText[i]);
	}


	//decryption
	for (long int i = 0; i < msg.length(); i++)
	{
		decryptedText[i] = decrypt(encryptedText[i], e, n);
	}

	cout << "\n\nДешифрованное сообщение:" << endl;

	for (long int i = 0; i < msg.length(); i++)
	{
		printf("%c", (char)decryptedText[i]);
	}


	cout << endl << endl;

	return 0;
}
