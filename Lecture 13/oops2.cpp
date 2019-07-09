#include<bits/stdc++.h>
using namespace std;

class Car{
	int price;
public:
	char* color;
	int speed;

	Car(){
		cout<<"constructor is called"<<endl;
	}
	Car(int s, int p, char* c){
		cout<<"perm constructor is called"<<endl;
		price = set_price(p);
		speed = s;
		int l  = strlen(c);
        color = new char[l+1];
		strcpy(color,c);
	}

	Car( int p, char* c){
		cout<<"perm 2 constructor is called"<<endl;
		price = set_price(p);
		int l  = strlen(c);
        color = new char[l+1];
		strcpy(color,c);
	}
	   Car(Car &X){
       // cout<<"Making a Copy of Car";
        price = X.price;
        speed = X.speed;
        int l = strlen(X.color);
        color = new char[l+1];
        strcpy(color,X.color);
    }

	void print(){
		cout<<"price "<<price<<endl;
		cout<<"color "<<color<<endl;
		cout<<"speed "<<speed<<endl;
	}

	int set_price(int p){
		if(p>100){
			price=p;
		}
		return p;
	}
	void get_price(){
		cout<<price<<endl;
	}

	void operator=(Car &A){
		cout<<"= is overloaded"<<endl;
		speed = A.speed;
		price = A.price;
		strcpy(color, A.color);
	}
	void operator()(Car &A){
		cout<<"= is overloaded"<<endl;
		speed = A.speed;
		price = A.price;
		for (int i = 0; i < strlen(A.color); ++i)
		{
			color[i] = A.color [i];
		}
	}

	void operator+(Car &B){
		cout<<B.speed<<" is speed of B and "<<speed<<" is speed of current car"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	Car D(1000,2000,"BMW");
	D.print();

	Car E(D);
	E.print();
	E.color[1] = 'o';
	E.print();
	D.print();
	return 0;
}
