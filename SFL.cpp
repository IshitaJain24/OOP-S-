#include<iostream>
using namespace std;

class passenger{
	string name;
	int age;
	string ticket_number;
	
	public:
		passenger(string name,int age,string ticket_number): name(name),age(age),ticket_number(ticket_number){}
    
	    void diplay_passenger_details(){
 	cout<<" passenger name"<<name<<endl;
 	cout<<" passenger age"<<age<<endl;
 	cout<<" passenger ticket_number"<<ticket_number<<endl;}
};
int main()
{
	passenger p1("cba",19,"a137473");
	passenger p2("abc",20,"a123856");
	p1.display_passenger_details();
	p2.diplay_passenger_details();
	
	return 0;
}
