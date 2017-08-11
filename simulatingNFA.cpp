// Static program for simulating a NFA
// Regular Expression of the NFA (b+ab)^+

#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
using namespace std;

int main() {
	char nfa[4][3];
	string input;
	char a = 'P', b = 'Q', c = 'R', curr_state, ck;
	int st = 0;
	cout << "\n\t\t\t\tNFA\n\n  Initial State: p\tIntermediate State: q\tfinal state: r ";
	cout << endl;
	nfa[0][0] = 'X';
	nfa[1][0] = a;
	nfa[2][0] = b;
	nfa[3][0] = c;
	nfa[0][1] = 'a';
	nfa[0][2] = 'b';
	nfa[1][1] = b;
	nfa[1][2] = c;
	nfa[2][1] = '$';
	nfa[2][2] = c;
	nfa[3][1] = b;
	nfa[3][2] = c;

	cout << "\n  Transition Table : " << endl << endl;
	for (int i = 0; i <= 3; i++) {
		cout << "  ";
		for (int j = 0; j <= 2; j++)
			cout << nfa[i][j] << "\t";
		cout << endl << endl;
	}

	do {
		cout << "  Enter the string to be tested : ";
		cin >> input;
		curr_state = a;
		cout << "\n  Transition : \n\n  -(^)-> " << a;
		for (int i = 0; i <= (input.size() - 1); i++) {
			if (input[i] == nfa[0][1]) {
				if (curr_state == a) {
					curr_state = nfa[1][1];
				}
				else if (curr_state == b) {
					curr_state = nfa[2][1];
					cout << " -(" << nfa[0][1] << ")-> " << curr_state;
					cout << "\n\n  NFA gets stuck! Hence string is Rejected!\n" << endl;
					st = 1;
					break;
				}
				else if (curr_state == c) {
					curr_state = nfa[3][1];
				}
				cout << " -(" << nfa[0][1] << ")-> " << curr_state;
			}
			else if (input[i] == nfa[0][2]) {
				if (curr_state == a) {
					curr_state = nfa[1][2];
				}
				else if (curr_state == b) {
					curr_state = nfa[2][2];
				}
				else if (curr_state == c) {
					curr_state = nfa[3][2];
				}
				cout << " -(" << nfa[0][2] << ")-> " << curr_state;
			}
		}
		if (curr_state == nfa[3][0] && st != 1) {
			cout << endl << endl << "  NFA reaches final state " << nfa[3][0] << "\n  Hence String is Accepted.\n" << endl;
		}
		else if (curr_state == nfa[3][0] && st != 1) {
			cout << endl << endl << "  NFA does not reach final state " << nfa[3][0] << "\n  Hence String is Rejected.\n" << endl;
		}
		st = 0;
		ck = _getch();
	} while (ck != 'x' || ck != 'X');
	_getch();
	return 0;
}

