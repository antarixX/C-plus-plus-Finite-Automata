// Static program for simulating a Turing Machine
// Turing Machine for multiplication of two unary numbers

#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

const int MAX = 50;
const int TRAN = 19;

void print() {
	for (int j = 0; j<55; j++)
		cout << "-";
	cout << endl;
}

void main() {
	char trans[TRAN][5], cur, ck, nl = 30;
	int hd, sc, i;
	/*
	0 => current state
	1 => input
	2 => output
	3 => move
	4 => next state
	*/
	//	Current State	Input		Output		Move		Next State
	//q0
	trans[0][0] = 'i';	trans[0][1] = 30;	trans[0][2] = 30;	trans[0][3] = 'R';	trans[0][4] = '1';
	//q1
	trans[1][0] = '1';	trans[1][1] = '1';	trans[1][2] = 30;	trans[1][3] = 'R';	trans[1][4] = '2';
	trans[2][0] = '1';	trans[2][1] = '0';	trans[2][2] = 30;	trans[2][3] = 'R';	trans[2][4] = '8';
	//q2
	trans[3][0] = '2';	trans[3][1] = '1';	trans[3][2] = '1';	trans[3][3] = 'R';	trans[3][4] = '2';
	trans[4][0] = '2';	trans[4][1] = '0';	trans[4][2] = '0';	trans[4][3] = 'R';	trans[4][4] = '3';
	//q3
	trans[5][0] = '3';	trans[5][1] = '1';	trans[5][2] = 'X';	trans[5][3] = 'R';	trans[5][4] = '4';
	trans[6][0] = '3';	trans[6][1] = '0';	trans[6][2] = '0';	trans[6][3] = 'L';	trans[6][4] = '6';
	//q4
	trans[7][0] = '4';	trans[7][1] = '1';	trans[7][2] = '1';	trans[7][3] = 'R';	trans[7][4] = '4';
	trans[8][0] = '4';	trans[8][1] = '0';	trans[8][2] = '0';	trans[8][3] = 'R';	trans[8][4] = '4';
	trans[9][0] = '4';	trans[9][1] = 30;	trans[9][2] = '1';	trans[9][3] = 'L';	trans[9][4] = '5';
	//q5
	trans[10][0] = '5';	trans[10][1] = '1';	trans[10][2] = '1';	trans[10][3] = 'L';	trans[10][4] = '5';
	trans[11][0] = '5';	trans[11][1] = '0';	trans[11][2] = '0';	trans[11][3] = 'L';	trans[11][4] = '5';
	trans[12][0] = '5';	trans[12][1] = 'X';	trans[12][2] = 'X';	trans[12][3] = 'R';	trans[12][4] = '3';
	//q6
	trans[13][0] = '6';	trans[13][1] = 'X';	trans[13][2] = '1';	trans[13][3] = 'L';	trans[13][4] = '6';
	trans[14][0] = '6';	trans[14][1] = '0';	trans[14][2] = '0';	trans[14][3] = 'L';	trans[14][4] = '7';
	//q7
	trans[15][0] = '7';	trans[15][1] = '1';	trans[15][2] = '1';	trans[15][3] = 'L';	trans[15][4] = '7';
	trans[16][0] = '7';	trans[16][1] = 30;	trans[16][2] = 30;	trans[16][3] = 'R';	trans[16][4] = '1';
	//q8
	trans[17][0] = '8';	trans[17][1] = '1';	trans[17][2] = 30;	trans[17][3] = 'R';	trans[17][4] = '8';
	trans[18][0] = '8';	trans[18][1] = '0';	trans[18][2] = 30;	trans[18][3] = 'S';	trans[18][4] = '0';


	cout << "\n\t\tTuring Machine For Multiplication\n" << endl << "  \tTransition Table :\n\n  \t";
	print();
	cout << left << "  \t" << setw(15) << "Current St" << setw(10) << "Input" << setw(10) << "Output" << setw(10) << "Move" << setw(10) << "Next St" << endl << "  \t";
	print();
	for (i = 0; i<TRAN; i++) {
		cout << left << "  \tq" << setw(14) << trans[i][0] << setw(10) << trans[i][1] << setw(10) << trans[i][2] << setw(10) << trans[i][3] << "q" << setw(9) << trans[i][4] << endl << "  \t";
		print();
	}
	cout << endl << "  Note : 1) The tape should contain two Unary numbers seperated by a 0.\n         2) The whole Input string must end with 0." << endl;
	do {
		char tape[MAX];
		cur = 'i';
		hd = 0;
		sc = 0;
		cout << "\n  Tape Input : ";

		for (i = 0; i<MAX; i++) {
			tape[i] = 30;
		}
		for (i = 1; i<MAX; i++) {
			nl = _getch();
			if (nl == 13)
				break;
			cout << nl << " ";
			tape[i] = nl;
		}
		cout << endl;
		while (sc<TRAN) {
			if (cur == trans[sc][0] && tape[hd] == trans[sc][1]) {
				tape[hd] = trans[sc][2];
				cur = trans[sc][4];
				if (trans[sc][3] == 'R') {
					hd++;
				}
				else if (trans[sc][3] == 'L') {
					hd--;
				}
				sc = -1;
			}
			if (sc == -1)
				sc = 0;
			else
				sc++;
		}
		if (cur == '0') {
			cout << endl << "  Computation Complete! Turing Machine is in Halting State." << endl;
			cout << "\n  Output on tape :\n" << endl;
			for (int i = 0; i<MAX; i++) {
				if (tape[i] != 30)
					cout << "  " << tape[i] << " ";
				else
					continue;
			}
			cout << endl;
		}
		else {
			cout << endl << "  Invalid Input!\n\n  Turing Machine is Stuck at state q" << cur << endl;
		}
		ck = _getch();
	} while (ck != 'x');
	_getch();
}