#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct date{
    int d;
    int m;
    int y;
};

class customer{
    long passport_id,phone_no;
    struct namae{
        string f,l;
    }name;

    struct date dob;
    public:
    void get(){
        cout<<"enter full name\n";
        cin>>name.f>>name.l;
        cout<<"enter contact number\n";
        cin>>phone_no;
        cout<<"enter passport id\n";
        cin>>passport_id;
        cout<<"Enter you date of birth";
        cin>>dob.d>>dob.m>>dob.y;
    }

    void display(){
        cout<<"Name: "<<name.f<<name.l<<endl;
        cout<<"Contact number: "<<phone_no<<endl;
        cout<<"Passport ID: "<<passport_id<<endl;
        cout<<"Date of Birth: "<<dob.d<<dob.m<<dob.y<<endl;
    }
};

class domestic: public customer{
    int a;
    long ticket_price=3000;
    struct date dod;
    enum domestic_destinations{Pune=1,Delhi=4,Kolkata=5,Jaipur=3,Banglore=3};
    public:
    void getd(){
        get();
        cout<<"Enter where you want to go\n";
        cout<<"1.Pune\n2.Delhi\n3.Kolkata\n4.Jaipur\n5.Banglore\n";
        cin>>a;
        cout<<"Select the date of departure(DD MM YYYY):"; //show flights
        cin>>dod.d>>dod.m>>dod.y;
    }

    void calprice(){
        domestic_destinations d;
        switch(a){
            case 1: d= Pune; break;
            case 2: d= Delhi; break;
            case 3: d= Kolkata; break;
            case 4: d= Jaipur; break;
            case 5: d= Banglore; break;
            default: cout<<"Enter Valid choice";
        }

        int t;
        b: cout<<"What meals do you want to have:\n1.Veg meal\n2.Non-Veg meal\n0.None";
        cin>>t;
        switch(t){
            case 1: ticket_price += 325; break;
            case 2: ticket_price += 360; break;
            case 0: ticket_price += 0; break;
            default: cout<<"Enter valid choice"; goto b;
        }

        cout<<"Your ticket price will be:"<<ticket_price;
    }

    void displayd(){
        display();
        cout<<"Destination: "<<a<<endl;
        cout<<"Date of departure: "<<dod.d<<dod.m<<dod.y<<endl;
        cout<<"Ticket price: "<<ticket_price;
    }
};

class international: public customer{
    long a,ticket_price=10000;
    struct date dod;
    enum international_destinations{NY=5,T=3,SP=2,D=1,L=4};
    public:
    void geti(){
        get();
        cout<<"Enter where you want to go";
        cout<<"\n1.New York\n2.Tokyo\n3.Singapore\n4.Dubai\n5.London\n";
        cin>>a;
        cout<<"Select the date of departure(DD MM YYYY):"; //show flights
        cin>>dod.d>>dod.m>>dod.y;
    }

    void calprice(){
        international_destinations i;
        switch(a){
            case 1: i= D;
            case 2: i= SP;
            case 3: i= T;
            case 4: i= L;
            case 5: i= NY;
            default: cout<<"Enter valid choice";
        }
        
        ticket_price *= i;
        int t;
        here: cout<<"What meals do you want to have:\n1.Veg meal\n2.Non-Veg meal\n0.None";
        cin>>t;
        switch(t){
            case 1: ticket_price += 3250; break;
            case 2: ticket_price += 3600; break;
            case 0: ticket_price += 0; break;
            default: cout<<"Enter valid choice"; goto here;
        }
    }

    void displayi(){
        display();
        cout<<"Destination: "<<a<<endl;
        cout<<"Date of departure: "<<dod.d<<dod.m<<dod.y<<endl;
        cout<<"Ticket price: "<<ticket_price;
    }
};

int main(){
    int ch;
    cout<<"Enter choice:\n1.Domestic\n2.International";
    cin>>ch;
    switch(ch){
        case 1:{
            domestic dom;
            dom.getd();
            dom.displayd();
            break;
        }

        case 2:{
            international inte;
            inte.geti();
            inte.displayi();
            break;
        }

        default: cout<<"Enter valid choice";
    }
}