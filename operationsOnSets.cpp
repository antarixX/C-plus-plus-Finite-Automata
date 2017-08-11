//  Operations on sets

#include<iostream>
#include<conio.h>
using namespace std;

const int MAX=20;

class set {
	int ele[MAX];
	int card;
public:
	set() {
		card=0;
	}

	void getdata() {
		cout<<"  Enter the cardinality of the set : ";cin>>card;
		cout<<"  Enter the elemnts of the set one by one : "<<endl;

		for(int i=0;i<card;i++) {
			cout<<"  ";cin>>ele[i];
		}
		cout<<endl;
	}

	void display() {
		cout<<"{ ";
		for(int i=0;i<card;i++) {
			if(i==card-1)
				cout<<ele[i]<<" }"<<endl;
			else
			cout<<ele[i]<<",";
		}
		cout<<endl;
	}

	set uni(set&A) {
		set t=*this;
		int ck=0;
		for(int i=0;i<A.card;i++) {
			for(int j=0;j<this->card;j++) {
				if(this->ele[j]==A.ele[i]) {
					ck++;
					break;
				}
			}
			if(ck==0) {
				t.ele[t.card]=A.ele[i];
				t.card++;
			}
			else
				ck=0;
		}
		return t;
	}

	set intersect(set&A) {
		set t;
		int ck=0;
		for(int i=0;i<A.card;i++) {
			for(int j=0;j<this->card;j++) {
				if(this->ele[j]==A.ele[i]) {
					ck++;
					break;
				}
			}
			if(ck!=0) {
				t.ele[t.card]=A.ele[i];
				t.card++;
				ck=0;
			}
		}
		return t;
	}

	set setdiff(set&A) {
		set t;
		int ck=0;
		for(int i=0;i<this->card;i++) {
			for(int j=0;j<A.card;j++) {
				if(this->ele[i]==A.ele[j]) {
					ck++;
					break;
				}
			}
			if(ck==0) {
				t.ele[t.card]=this->ele[i];
				t.card++;
			}
			else
				ck=0;
		}
		return t;
	}
};

void main() {
	set A,B,C;
	int opt;
	cout<<"\t\t\t\tSET OPERATIONS\n"<<endl;

	do {
		cout<<"  Select an option : "<<endl;
		cout<<"  1.Union 2.Intersection 3.Set Difference 4.Symetric Difference 5.Exit"<<endl<<"  ";
		cin>>opt;
		switch(opt) {
			case 1: {	
					cout<<endl<<"  Enter data of set A :-"<<endl;
					A.getdata();
					cout<<"  Enter data of set B : "<<endl;
					B.getdata();
					C=A.uni(B);
					cout<<"  A = ";A.display();
					cout<<"  B = ";B.display();
					cout<<"  A union B = ";
					C.display();
					cout<<endl;
					break;
				}
			case 2: {
					cout<<endl<<"  Enter data of set A :-"<<endl;
					A.getdata();
					cout<<"  Enter data of set B : "<<endl;
					B.getdata();
					C=A.intersect(B);
					cout<<"  A = ";A.display();
					cout<<"  B = ";B.display();
					cout<<"  A intersection B = ";
					C.display();
					cout<<endl;
					break;
				}
			case 3: {
					cout<<endl<<"  Enter data of set A :-"<<endl;
					A.getdata();
					cout<<"  Enter data of set B : "<<endl;
					B.getdata();
					cout<<"  A = ";A.display();
					cout<<"  B = ";B.display();
					cout<<"  A - B = ";
					C=A.setdiff(B);
					C.display();
					cout<<"  B - A = ";
					C=B.setdiff(A);
					C.display();
					cout<<endl;
					break;
				}
			case 4: {
					cout<<endl<<"  Enter data of set A :-"<<endl;
					A.getdata();
					cout<<"  Enter data of set B : "<<endl;
					B.getdata();
					cout<<"  A = ";A.display();
					cout<<"  B = ";B.display();
					C=(A.setdiff(B)).uni(B.setdiff(A));
					cout<<"  A + B = ";
					C.display();
					cout<<endl;
					break;
				}
			case 5: {
					cout<<endl<<"  Program Ended!"<<endl;
					break;
				}
			default: {
					cout<<"\nInvalid Option!\n"<<endl;
				}
		}
	}while(opt!=5);
	_getch();
}
