#include <iostream>
#include "Money.h"

using namespace std;

Money MakeMoney(int x, int y)
{
	Money money;
	if (!money.Init(x, y))
		cout << "Wrong argument init " << endl;
	return money;
}

int main()
{
	bool result;
	Money value1(0, 0), value2(0, 0);
	double x;
	do
	{
		try
		{
			result = true;

			cout << "Enter the first value: " << endl; cin >> value1;
			cout << "\nEnter the second value: " << endl; cin >> value2;
			cout << "\nEnter the value of x: ";cin >> x;
		}
		catch (invalid_argument ex)
		{
			result = false;
			cerr << endl << ex.what() << endl << endl;
		}
		catch (nException& ex)
		{
			result = false;
			cerr << endl << ex.getMessage() << endl << endl;
		}
		catch (Exception* ex)
		{
			result = false;
			cerr << endl << ex->getMessage() << endl << endl;
		}
	} while (!result);
	
	system("cls");
	cout << "First sum = " << value1 << "\tSecond sum = " << value2 << "\tX = " << x << endl;

	Money substr(value1 - value2);
	Money mult1(value1 * x);
	Money mult2(value2 * x);
	cout << "\nfirst value - second = " << substr << endl;
	cout << "\nfirst value * x = " << mult1 << endl;
	cout << "second value * x = " << mult2 << endl;

	cout << endl;

	if (value1 == value2)
		cout << value1 << " == " << value2 << endl;
	else
		if (value1 > value2)
			cout << value1 << " > " << value2 << endl;
		else
			if (value1 < value2)
				cout << value1 << " < " << value2 << endl;

	cout << endl;
	cout << "a++ " << value1++;
	cout << "\nresult: " << value1 << endl;
	cout << "\na-- " << value1--;
	cout << "\nresult: " << value1 << endl;

	cout << "\n++a " << ++value1 << endl;
	cout << "--a " << --value1 << endl;
	
	cout << endl << endl;
	system("pause");
	return 0;
}