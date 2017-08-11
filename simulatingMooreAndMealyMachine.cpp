// Static program to implement a Moore and an equivalent Mealy Machine for Parity Checker

#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

void main()
{
	char mealy[5][4];
	char moore[5][3];
	int i, j;
	char curr_state, out;
	string a;

	cout << "\n\t\t\tMealy Machine for Odd Parity Checker";

	// Initializing the mealy machine

	mealy[0][0] = 'X'; mealy[0][1] = 'I'; mealy[0][2] = 'O'; mealy[0][3] = 'T';
	mealy[1][0] = 'p'; mealy[1][1] = '0'; mealy[1][2] = 'n'; mealy[1][3] = 'p';
	mealy[2][0] = 'p'; mealy[2][1] = '1'; mealy[2][2] = 'y'; mealy[2][3] = 'q';
	mealy[3][0] = 'q'; mealy[3][1] = '0'; mealy[3][2] = 'y'; mealy[3][3] = 'q';
	mealy[4][0] = 'q'; mealy[4][1] = '1'; mealy[4][2] = 'n'; mealy[4][3] = 'p';

	// Displaying Transition Table for the Mealy Machine.

	cout << endl << endl << "  The Transition Table for the Mealy Machine is as follows: ";
	cout << endl << endl;
	for (i = 0; i <= 4; i++)
	{
		cout << "  ";
		for (j = 0; j <= 3; j++)
			cout << mealy[i][j] << "\t";
		cout << endl << endl;
	}
	cout << endl << endl << "  Enter the binary no: ";
	cin >> a;

	// Performing Computation

	cout << endl << endl << "  Mealy Machine Odd Parity Checker proceeds as follows: ";
	cout << endl << endl;
	curr_state = 'p';
	cout << "  ---> " << curr_state;
	for (i = 0; i <= a.size() - 1; i++)
	{
		if (curr_state == 'p')
		{
			if (a[i] == mealy[1][1])
			{
				curr_state = 'p';
				out = 'n';
			}
			if (a[i] == mealy[2][1])
			{
				curr_state = 'q';
				out = 'y';
			}
		}
		else if (curr_state == 'q')
		{
			if (a[i] == mealy[3][1])
			{
				curr_state = 'q';
				out = 'y';
			}
			if (a[i] == mealy[4][1])
			{
				curr_state = 'p';
				out = 'n';
			}
		}
		cout << " -(" << a[i] << "/" << out << ")-> " << curr_state;
	}
	if (curr_state == 'q')
	{
		cout << endl << "\n  Output : y" << endl << "  The binary number " << a << " is ACCEPTED by the odd parity checker.";
	}
	else
	{
		cout << endl << "\n  Output : n" << endl << "  The binary number " << a << " is REJECTED by the odd parity checker.";
	}

	cout << endl << endl << endl << "\t\t\tMoore Machine for Odd Parity Checker";
	// Initializing the Moore Machine

	moore[0][0] = 'X'; moore[0][1] = 'I'; moore[0][2] = 'T';
	moore[1][0] = 'p'; moore[1][1] = '0'; moore[1][2] = 'p';
	moore[2][0] = 'p'; moore[2][1] = '1'; moore[2][2] = 'q';
	moore[3][0] = 'q'; moore[3][1] = '0'; moore[3][2] = 'q';
	moore[4][0] = 'q'; moore[4][1] = '1'; moore[4][2] = 'p';

	// Displaying Transition Table for the Moore Machine.

	cout << endl << endl << "  The Transition Table for the Moore Machine is as follows: ";
	cout << endl << endl;
	for (i = 0; i <= 4; i++)
	{
		cout << "  ";
		for (j = 0; j <= 2; j++)
			cout << moore[i][j] << "\t";
		cout << endl << endl;
	}
	cout << endl << endl << "  Enter the binary no: ";
	cin >> a;

	// Performing Computation

	cout << endl << endl << "  Moore Machine Odd Parity Checker proceeds as follows: ";
	cout << endl << endl;
	curr_state = 'p';
	cout << "  --> " << curr_state;
	for (i = 0; i <= a.size() - 1; i++)
	{
		if (curr_state == 'p')
		{
			if (a[i] == moore[1][1])
			{
				curr_state = 'p';
			}
			else if (a[i] == moore[2][1])
			{
				curr_state = 'q';
			}
		}
		else if (curr_state == 'q')
		{
			if (a[i] == moore[3][1])
			{
				curr_state = 'q';
			}
			else if (a[i] == moore[4][1])
			{
				curr_state = 'p';
			}
		}
		cout << " -(" << a[i] << ")-> " << curr_state;
	}
	if (curr_state == 'q')
	{
		cout << endl << "\n  Output : y" << endl << "  The binary number " << a << " is ACCEPTED by the odd parity checker.";
	}
	else
	{
		cout << endl << "\n  Output : n" << endl << "  The binary number " << a << " is REJECTED by the odd parity checker.";
	}
	getch();
}

