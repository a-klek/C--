// CppFirst.cpp: определяет точку входа для консольного приложения.
//
/*

Реализовать внутренности функции (каждому по 1) в среде разработки Microsoft Visual C++.
Описания функций брать в Microsoft Solution Developers Network(MSDN).

ultoa

*/
#include "stdafx.h"
#include "iostream"
//#include "stdlib.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	char str[40];
	int i;
	int r;
	char *s;
	std::cout << "input number: ";
	std::cin >> i;
	std::cout << "input radix: ";
	std::cin >> r;
	s = ultoa(i, str, r);
	std::cout << s;
	std::cin>>i;
	
	return 0;	
}

char* ultoa(unsigned long value, char strBufer[], int radix){
	int i;
	int j;
	int l=0;
	int k=0;
	if (radix - 10){
		k = 65;
	}
	strBufer[0] = NULL;
	char ch;
	while (value >= radix){
		i = value%radix;
		ch = i + 48;
		if (i >= 10){
			ch = i-10 + k;
		}
		l++;
		for (j = l; j >= 0; j--){
			strBufer[j + 1] = strBufer[j];
		}
		strBufer[0] = ch;
		value = value / radix;
	}
	if (value >= 10){
		ch = value - 10 + k;
	}
	else{
		ch = value + 48;
	}
	for (j = l; j >= 0; j--){
		strBufer[j + 1] = strBufer[j];
	}
	strBufer[0] = ch;

	return strBufer;
}

