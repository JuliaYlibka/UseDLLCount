// UseDLLCount.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	HMODULE hDll;
	int(*Add)(int);
	int (*Sub)(int);
	int* pCount;

	hDll = LoadLibrary("C:\\Users\\acer\\source\\repos\\Dll_Bexmternykh\\x64\\\Debug\\Dll_Bexmternykh.dll");
	if (!hDll)
	{
		cerr << "Load library failed." << endl;
		return GetLastError();
	}
	pCount = (int*)GetProcAddress(hDll, MAKEINTRESOURCE(1));
	if (!pCount) 
	{
		cerr << "Get variable address failed." << endl;
		return GetLastError();
	}
	cout << "Initial count = " << (*pCount) << endl;
	Add = (int(*)(int)) GetProcAddress(hDll, MAKEINTRESOURCE(2));
	Sub = (int(*)(int)) GetProcAddress(hDll, MAKEINTRESOURCE(3));
	if (!Add || !Sub) 
	{
		cerr << "GEt procedure address failled." << endl;
		return GetLastError();
	}
	cout << "count = " << Add(20) << endl;
	cout << "count = " << Sub(15) << endl;
	if(!FreeLibrary(hDll))
	{
		cerr << "Free library failed." << endl;
		return GetLastError();
	}
	cout << "Press any key to exit";
	return 0;
}
