// Static program for simulating Mealy Machine
// for adding two binary numbbers 

#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;

void main()
{
	char mealy[9][5];
	int i, j;
	char curr_state, out;
	string a, b;
	vector <char> ans;

	// Initializing the mealy machine

	mealy[0][0] = 'X';
	for (i = 1; i <= 4; i++)
		mealy[i][0] = 'n';
	for (i = 5; i <= 8; i++)
		mealy[i][0] = 'c';
	mealy[0][1] = 'A';
	mealy[1][1] = '0';
	mealy[2][1] = '0';
	mealy[3][1] = '1';
	mealy[4][1] = '1';
	mealy[5][1] = '0';
	mealy[6][1] = '0';
	mealy[7][1] = '1';
	mealy[8][1] = '1';
	mealy[0][2] = 'B';
	mealy[1][2] = '0';
	mealy[2][2] = '1';
	mealy[3][2] = '0';
	mealy[4][2] = '1';
	mealy[5][2] = '0';
	mealy[6][2] = '1';
	mealy[7][2] = '0';
	mealy[8][2] = '1';
	mealy[0][3] = 'T';
	mealy[1][3] = 'n';
	mealy[2][3] = 'n';
	mealy[3][3] = 'n';
	mealy[4][3] = 'c';
	mealy[5][3] = 'n';
	mealy[6][3] = 'c';
	mealy[7][3] = 'c';
	mealy[8][3] = 'c';
	mealy[0][4] = 'O';
	mealy[1][4] = '0';
	mealy[2][4] = '1';
	mealy[3][4] = '1';
	mealy[4][4] = '0';
	mealy[5][4] = '1';
	mealy[6][4] = '0';
	mealy[7][4] = '0';
	mealy[8][4] = '1';

	// Displaying Transition Table for the Mealy Machine.

	cout << "\n\t\t\t\tMealy Machine\n\n  The Transition Table for the Mealy Machine is as follows: ";
	cout << endl << endl;
	for (i = 0; i <= 8; i++)
	{
		cout << "  ";
		for (j = 0; j <= 4; j++)
			cout << mealy[i][j] << "\t";
		cout << endl << endl;
	}
	cout << endl << endl << "  Enter the first binary no: ";
	cin >> a;
	cout << endl << endl << "  Enter the second binary no (same length as the previous): ";
	cin >> b;

	// Performing Computation

	cout << endl << endl << "  Mealy Machine Computation proceeds as follows: ";
	cout << endl << endl;
	curr_state = 'n';
	cout << "  ---> " << curr_state;
	for (i = a.size() - 1; i >= 0; i--)
	{
		if (curr_state == 'n')
		{
			if (a[i] == mealy[1][1] && b[i] == mealy[1][2])
			{
				curr_state = 'n';
				ans.push_back(mealy[1][4]);
				out = mealy[1][4];
			}
			else if (a[i] == mealy[2][1] && b[i] == mealy[2][2])
			{
				curr_state = 'n';
				ans.push_back(mealy[2][4]);
				out = mealy[2][4];
			}
			else if (a[i] == mealy[3][1] && b[i] == mealy[3][2])
			{
				curr_state = 'n';
				ans.push_back(mealy[3][4]);
				out = mealy[3][4];
			}
			else if (a[i] == mealy[4][1] && b[i] == mealy[4][2])
			{
				curr_state = 'c';
				ans.push_back(mealy[4][4]);
				out = mealy[4][4];
			}
		}
		else
			if (curr_state == 'c')
			{
				if (a[i] == mealy[5][1] && b[i] == mealy[5][2])
				{
					curr_state = 'n';
					ans.push_back(mealy[5][4]);
					out = mealy[5][4];
				}
				if (a[i] == mealy[6][1] && b[i] == mealy[6][2])
				{
					curr_state = 'c';
					ans.push_back(mealy[6][4]);
					out = mealy[6][4];
				}
				if (a[i] == mealy[7][1] && b[i] == mealy[7][2])
				{
					curr_state = 'c';
					ans.push_back(mealy[7][4]);
					out = mealy[7][4];
				}
				if (a[i] == mealy[8][1] && b[i] == mealy[8][2])
				{
					curr_state = 'c';
					ans.push_back(mealy[8][4]);
					out = mealy[8][4];
				}
			}
		cout << " -(" << a[i] << b[i] << "/" << out << ")-> " << curr_state;
	}
	if (curr_state == 'c')
		ans.push_back('1');

	// Reversing the ans vector
	std::reverse(ans.begin(), ans.end());
	cout << endl << endl << "  The result of binary addition is: ";
	for (i = 0; i <= ans.size() - 1; i++)
		cout << ans[i];
	_getch();
}