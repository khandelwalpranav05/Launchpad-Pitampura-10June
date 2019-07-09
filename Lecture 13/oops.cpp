#include<bits/stdc++.h>
using namespace std;

class Car{
	int price;
public:
	char color[20];
	int speed;

	Car(){
		cout<<"constructor is called"<<endl;
	}
	Car(int s, int p, char c[20]){
		cout<<"perm constructor is called"<<endl;
		price = set_price(p);
		speed = s;
		strcpy(color,c);
	}

	Car( int p, char c[20]){
		cout<<"perm 2 constructor is called"<<endl;
		price = set_price(p);
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
	Car c;
	c.speed = 10;
	
	c.color[0] = 'R';
	c.color[1] = 'e';
	c.color[2] = 'd';
	c.set_price(1000);
	
	//c.print();
	// cout<<"price ";
	// c.get_price();
	// 	cout<<"color "<<c.color<<endl;
	// 	cout<<"speed "<<c.speed<<endl;
	char col[20] = "white";
	//Car c(100, 2000,col);
	//c.print();
	char cl[20] = "blue";
	// Car d(20000,cl);
	// d.print();
	// cout<<"---------------"<<endl;
	// Car e;
	// e = d;
	// e.print();

	c+d;
	// copy cons.
	Car A(c);
	A.print();
	c.print();
	return 0;
}





