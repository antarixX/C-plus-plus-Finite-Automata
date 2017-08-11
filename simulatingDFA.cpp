// Program for simulating DFA with two input alphabets
// This program uses _getch() to get the data hence pressing enter is not needed at some points
// such as when entering input alphabet.
// Make sure to enter only capital letters for the transition table (pressing enter is not needed here)

#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

struct dnode				//DFA state
{
	int data;
	struct dnode *link;
	struct dnode *tz;		//transition on input 0	
	struct dnode *to;		//transition on input 1
};

struct node
{
	char data;
	struct node*link;
};

struct dnode y;			//not null value

void d_append(struct dnode **q, int s)
{
	struct dnode *temp, *m = *q;
	temp = new dnode;
	temp->data = s;
	temp->link = NULL;
	temp->tz = NULL;
	temp->to = NULL;
	if ((*q) == NULL)
		*q = temp;
	else
	{
		while (m->link != NULL)
			m = m->link;
		m->link = temp;
	}
}

void append(struct node**q, char f)
{
	struct node *temp, *m = *q;
	temp = new node;
	temp->data = f;
	temp->link = NULL;
	if ((*q) == NULL)
		*q = temp;
	else
	{
		while (m->link != NULL)
			m = m->link;
		m->link = temp;
	}
}

void del_o(struct node**q)	//deletes one node for backspace
{
	struct node*t = *q, *pt;
	while (t->link != NULL)
	{
		pt = t;
		t = t->link;
	}
	if ((*q)->link == NULL)
		*q = NULL;
	else
		pt->link = NULL;
	delete t;
}

void del_w(struct node**q) //delete the whole link list
{
	struct node*t, *pt;
	while ((*q)->link != NULL)
	{
		t = *q;
		while (t->link != NULL)
		{
			pt = t;
			t = t->link;
		}
		pt->link = NULL;
		delete t;
	}
	delete *q;
	*q = NULL;
}

void transit(struct dnode *q, char w, char x)
{
	char ck;
	int st;
	struct dnode  *m = q, *trav;
	cout << "\n  Enter 'Y' if transition exists otherwise enter 'X'.\n\n  Transitions of the DFA :\n" << endl;
	cout << "  " << left << setw(10) << "State" << "Input " << w << "   Input " << x << endl;
	for (int i = 0; m != NULL; i++)
	{
		cout << "  q" << setw(6) << left << (m->data) << right;
		ck = _getch();
		if (ck == 'y' || ck == 'Y')
			m->tz = &y;
		cout << setw(10) << ck;
		ck = _getch();
		if (ck == 'y' || ck == 'Y')
			m->to = &y;
		cout << setw(10) << ck << endl;
		m = m->link;
	}
	m = q;
	cout << endl << "  Enter the transitions on given input :" << endl;

	for (int i = 0; m != NULL; i++)
	{
		cout << endl << "  State q" << i << " :" << endl;
		cout << "  Input " << w << " => State ";
		if (m->tz != NULL)
		{
			cout << "q";
			cin >> st;
			trav = q;
			while (trav->data != st)
				trav = trav->link;
			m->tz = trav;
		}
		else
			cout << "X" << endl;	//no transition

		cout << "  Input " << x << " => State ";
		if (m->to != NULL)
		{
			cout << "q";
			cin >> st;
			trav = q;
			while (trav->data != st)
				trav = trav->link;
			m->to = trav;
		}
		else
			cout << "X" << endl;	//no transition

		m = m->link;
	}

}

int finalsc(struct node*q, int s) //check if DFA is in final state
{
	while (q != NULL)
	{
		if (q->data == s)
			return 1;
		q = q->link;
	}
	return 0;
}

void dfa_ck(struct dnode*d, struct node*s, struct node*f, char w, char x)
{
	struct dnode *sptr = d;

	while (s != NULL)
	{
		if (s->data == w)
			sptr = sptr->tz;
		else if (s->data == x)
			sptr = sptr->to;

		if (sptr == NULL)
		{
			cout << "\n  String is Rejected!" << endl;	//no transition from given input
			return;
		}

		s = s->link;
	}

	if (finalsc(f, sptr->data))
	{
		cout << "\n  String is Accepted." << endl;	//final state
		return;
	}

	cout << "\n  String is Rejected!" << endl;		//non final state
}

void main()
{
	int nf, ns, f;
	char a1, a2, c;
	y.data = 13;
	struct node *fs = NULL, *is = NULL;
	struct dnode *dfa = NULL;
	cout << endl << "\t\t\t\tDFA\n" << endl;
	cout << "  Input Alphabet = {";
	a1 = _getch();
	cout << a1 << ",";
	a2 = _getch();
	cout << a2 << "}	Initial State = q0\n\n  Enter the number of states in the DFA (Q) : "; cin >> ns;
	for (int i = 0; i<ns; i++)
	{
		d_append(&dfa, i);
	}
	transit(dfa, a1, a2);
	cout << endl << "  Enter the number of final states : "; cin >> nf;
	cout << "\n  Enter the final states (A):\n";
	for (int i = 0; i<nf; i++)
	{
		cout << "  q";
		cin >> f;
		append(&fs, f);
	}

	do {
		cout << endl << "  Input String : ";
		while ((c = _getch()) != 13)	//enter key
		{
			cout << c;
			if (c == 8 && is != NULL)		//backspace key
			{
				del_o(&is);
				cout << " " << c;
				continue;
			}
			else if (c != a1 && c != a2)
			{
				cout << endl << "  Invalid Input!" << endl;
				c = 1;
				if (is != NULL)
					del_w(&is);
				break;
			}
			else
				append(&is, c);
		}
		if (c == 1)
			continue;
		else if (is == NULL)
		{
			if (finalsc(fs, 0))
			{
				cout << "^\n  String is Accepted." << endl;	//final state is q0 for NULL string
				continue;
			}
			else
			{
				cout << "^\n  String is Rejected!" << endl;		//non final state for NULL string
				continue;
			}
		}
		dfa_ck(dfa, is, fs, a1, a2);
		del_w(&is);
		cout << "  ";
		c = _getch();
	} while (c != 'x' || c != 'X');
	cout << endl << "  Program Ended!";
	_getch();
}