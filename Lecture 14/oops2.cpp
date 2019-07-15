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
		int length = strlen(c);
		color = new char[length+1];
		strcpy(color,c);
	}
	// deep copy
	Car(Car &X){
		cout<<"inside deep copy constructor"<<endl;
		price = set_price(X.price);
		speed = X.speed;
		int length = strlen(X.color);
		color = new char[length+1];
		strcpy(color,X.color);
	}

	Car( int p, char* c){
		cout<<"perm 2 constructor is called"<<endl;
		price = set_price(p);
		int length = strlen(c);
		color = new char[length+1];
		strcpy(color,c);
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
	Car A(1000, 5000, "Yellow");
	//Car A;
	// A.speed = 3000;
	// A.set_price(9000);
	// A.color = "Blue";
	cout<<"----Car A----------"<<endl;
	A.print();
	cout<<"-----Car audi---------"<<endl;
	Car audi(A);
	audi.print();
	audi.color[1] ='O';
	cout<<"-----Car audi---------"<<endl;
	audi.print();
	cout<<"----Car A----------"<<endl;
	A.print();

	
	return 0;
}