#include <bits/stdc++.h>
#include <fstream>
using namespace std;
char a = 'A';

void showseats(list<int> t,int check){
    cout<<"\n";
    list<int> :: iterator i;
    i = t.begin();
    cout<<a<<"  ";
    if(check==1){
        cout<<" ";
        for(int j=1;j<16;j++){
            if(*i==j){cout<<"X "; i++;}
            else{cout<<"O ";}
            if(j==2||j==6||j==13){cout<<" | ";}
            else if(j==15){cout<<"| ";}
        }
    }
    else{
        for(int j=1;j<14;j++){
            if(*i==j){cout<<"X "; i++;}
            else{cout<<"O ";}
            if(j==2||j==6||j==13){cout<<" | ";}
        }
    }
    a++;
}

class date{
    public:
    int d,m,y;

    friend ostream &operator<<(ostream &o, date &x){
        cout<<x.d<<" "<<x.m<<" "<<x.y;
        return o;
    }

    friend istream &operator>>(istream &i, date &x){
        cin>>x.d>>x.m>>x.y;
        return i;
    }
};

class flights{
    public:
    long price;
    struct date dof;
    string ini, fin;

    void data_insertion_dom(){
        ofstream o("domFlights.txt",ios::app);
        cout<<"Initial flight position: ";
        cin>>ini;
        o<<ini<<"    ";
        cout<<"Final flight position: ";
        cin>>fin;
        o<<fin<<"    ";
        cout<<"Price: ";
        cin>>price;
        o<<price<<"    ";
        cout<<"Date of flight: ";
        cin>>dof.d>>dof.m>>dof.y;
        o<<dof.d<<" "<<dof.m<<" "<<dof.y<<endl;
        o.close();
    }

    void data_insertion_int(){
        ofstream o("intFlights.txt",ios::app);
        cout<<"Initial flight position: ";
        cin>>ini;
        o<<ini<<"    ";
        cout<<"Final flight position: ";
        cin>>fin;
        o<<fin<<"    ";
        cout<<"Price: ";
        cin>>price;
        o<<price<<"    ";
        cout<<"Date of flight: ";
        cin>>dof.d>>dof.m>>dof.y;
        o<<dof.d<<" "<<dof.m<<" "<<dof.y<<endl;
        o.close();
    }
};

class customer{
    long long passport_id,phone_no;
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
        cin>>dob;
    }

    void writecustfiled(){
        ofstream cust("domesticdata.txt",ios::app);
        cust<<name.f<<"   "<<name.l<<"   "<<phone_no<<"   "<<passport_id<<"   "<<dob.d<<"   "<<dob.m<<"   "<<dob.y<<"   ";
        cust.close();
    }
    
    void writecustfilei(){
        ofstream cust("internationaldata.txt",ios::app);
        cust<<name.f<<"   "<<name.l<<"   "<<phone_no<<"   "<<passport_id<<"   "<<dob.d<<"   "<<dob.m<<"   "<<dob.y<<"   ";
        cust.close();
    }

    void display(){
        cout<<"Name: "<<name.f<<name.l<<endl;
        cout<<"Contact number: "<<phone_no<<endl;
        cout<<"Passport ID: "<<passport_id<<endl;
        cout<<"Date of Birth: "<<dob<<endl;
    }
};

class domestic: public customer{
    list<int> domh[6];
    int c;
    char r;
    flights k;
    long ticket_price;
    public:
    friend void showseats(list<int>,int);

    domestic(){
        ticket_price = 300;
        ifstream i;
        string check;
        i.open("domesticdata.txt");
        while(getline(i,check)){
            c = check[check.size()-1] - '0';
            r = check[check.size()-3];

            if(domh[r-'A'].empty()){domh[r-'A'].push_back(c);}
            else if(domh[r-'A'].front() > c){domh[r-'A'].push_front(c);}

            else{
                int flag = 0;
                list<int> :: iterator iter;
                for(iter=domh[r-'A'].begin();iter!=domh[r-'A'].end();iter++){
                    if(*iter == c){cout<<"Seat already booked"; break;}
                    else if(*iter > c){
                        iter--; 
                        domh[r-'A'].insert(iter,c);
                        break;
                    }
                    else{flag=1;}
                }
            if(flag==1){domh[r-'A'].push_back(c);}
            }
        }
        i.close();
    }

    void getd(){
        int flch;
        ifstream i;
        int count=1;
        cout<<"Enter which flight you wanna choose: ";
        cin>>flch;
        i.open("domFlights.txt");
        string check;
        while(flch-- && count++){
            cout<<count<<endl;
            i>>k.ini>>k.fin>>ticket_price>>k.dof.d>>k.dof.m>>k.dof.y;           
        }
        i.close();
    }

    void calcseat(){
        a = 'A';
        for(int i=0;i<6;i++){
            if(i==2 || i==3){showseats(domh[i],1);}
            else{showseats(domh[i],2);}
        }

        cout<<"Enter the seat number you want to book(eg A 7)";
        cin>>r>>c;

        if(domh[r-'A'].empty()){domh[r-'A'].push_back(c);}
        else if(domh[r-'A'].front() > c){domh[r-'A'].push_front(c);}

        else{
            int flag = 0;
            list<int> :: iterator iter;
            for(iter=domh[r-'A'].begin();iter!=domh[r-'A'].end();iter++){
                if(*iter == c){cout<<"Seat already booked\n"; break;}
                else if(*iter > c){
                    iter--; 
                    domh[r-'A'].insert(iter,c);
                    break;
                }
                else{flag=1;}
            }
            if(flag==1){domh[r-'A'].push_back(c);}
        }
    }

    void calprice(){
        int t;
        cout<<"What meals do you want to have:\n1.Veg meal\n2.Non-Veg meal\n0.None";
        cin>>t;
        switch(t){
            case 1: ticket_price += 625; break;
            case 2: ticket_price += 660; break;
            case 0: break;
            default: cout<<"Enter valid choice"; 
        }

        cout<<"Your ticket price will be:"<<ticket_price;
    }

    void writeinfiledom(){
        ofstream o("domesticdata.txt",ios::app);
        writecustfiled();
        o<<k.ini<<"   "<<k.fin<<"   "<<ticket_price<<"   "<<r<<" "<<c;
        o.close();
    }

    void displayd(){
        display();
        cout<<"Destination: "<<k.fin<<endl;
        cout<<"Date of departure: "<<k.dof<<endl;
    }
};

class international: public customer{
    list<int> inth[6];
    char r;
    int c;
    long ticket_price;
    flights k;
    date dod;
    enum international_destinations{NY=5,T=3,SP=2,D=1,L=4};
    public:

    international(){
        ifstream i;
        string check;
        i.open("internationaldata.txt");
        while(getline(i,check)){
            c = check[check.size()-1] - '0';
            r = check[check.size()-3];

            if(inth[r-'A'].empty()){inth[r-'A'].push_back(c);}
            else if(inth[r-'A'].front() > c){inth[r-'A'].push_front(c);}

            else{
                int flag = 0;
                list<int> :: iterator iter;
                for(iter=inth[r-'A'].begin();iter!=inth[r-'A'].end();iter++){
                    if(*iter == c){cout<<"Seat already booked"; break;}
                    else if(*iter > c){
                        iter--; 
                        inth[r-'A'].insert(iter,c);
                        break;
                    }
                    else{flag=1;}
                }
            if(flag==1){inth[r-'A'].push_back(c);}
            }
        }
        i.close();
    }
    
    void geti(){
        int flch;
        ifstream i;
        cout<<"Enter your choice of flight";
        cin>>flch;
        i.open("intFlights.txt");
        while(flch--){
            i>>k.ini>>k.fin>>ticket_price>>k.dof.d>>k.dof.m>>k.dof.y;
        }
        i.close();
    }

    void calcseat(){
        a = 'A';
        for(int i=0;i<6;i++){
            if(i==2 || i==3){showseats(inth[i],1);}
            else{showseats(inth[i],2);}
        }

        cout<<"Enter the seat number you want to book(eg A 7)";
        cin>>r>>c;

        if(inth[r-'A'].empty()){inth[r-'A'].push_back(c);}
        else if(inth[r-'A'].front() > c){inth[r-'A'].push_front(c);}

        else{
            int flag = 0;
            list<int> :: iterator iter;
            for(iter=inth[r-'A'].begin();iter!=inth[r-'A'].end();iter++){
                if(*iter == c){cout<<"Seat already booked"; break;}
                else if(*iter > c){
                    iter--; 
                    inth[r-'A'].insert(iter,c);
                    break;
                }
                else{flag=1;}
            }
            if(flag==1){inth[r-'A'].push_back(c);}
        }
    }

    void calprice(){
        int t;
        here: cout<<"What meals do you want to have:\n1.Veg meal\n2.Non-Veg meal\n0.None";
        cin>>t;
        switch(t){
            case 1: ticket_price += 3250; break;
            case 2: ticket_price += 3900; break;
        }
    }

    void writeinfileint(){
        ofstream o("internationaldata.txt",ios::app);
        writecustfilei();
        o<<k.ini<<"   "<<k.fin<<"   "<<ticket_price<<"   "<<r<<" "<<c;
        o.close();
    }

    void displayi(){
        display();
        cout<<"Destination: "<<a<<endl;
        cout<<"Date of departure: "<<k.dof<<endl;
        cout<<"Ticket price: "<<ticket_price;
    }
};

void showflights(char ch){
    string check;
    int c=1;
    ifstream i;
    if(ch=='d')
        i.open("domFlights.txt");
    else
        i.open("intFlights.txt");

    flights fl;
    cout<<"Sr.No|Initial | Final | Price | Date of flight\n";
    cout<<"---------------------------------------\n";
    while(getline(i,check)){
        cout<<c<<" : "<<check<<endl;
        c++;
    }
    i.close();
    cout<<endl;
}
int main(){
    int ch,admin;
    fstream f;
    jump:
        while(admin!=3){
        cout<<"\n1. For Admin mode\n2.For Customer mode\n3.Exit\n";
        cin>>admin;
        switch(admin){
            case 2:{
                while(1){
                    cout<<"Enter choice:\n1.Domestic\n2.International\n3.EXIT";
                    cin>>ch;
                    switch(ch){
                        case 1:{
                            domestic dom;
                            dom.get();
                            showflights('d');
                            dom.getd();
                            char check='n';
                            while(check=='n'){
                                dom.displayd();
                                cout<<"Check whether you have entered the right details(y/n)\n";
                                cin>>check;
                                if(check=='n'){
                                    cout<<"Re-enter the data please";
                                    dom.getd();
                                }
                            }
                            dom.calcseat();
                            dom.calprice();
                            dom.writeinfiledom();
                            break;
                        }

                        case 2:{
                            international inte;
                            inte.get();
                            showflights('i');
                            inte.geti();
                            char check='n';
                            while(check=='n'){
                                inte.displayi();
                                cout<<"Check whether you have entered the right details(y/n)\n";
                                cin>>check;
                                if(check=='n'){
                                    cout<<"Renter the data please";
                                    inte.geti();
                                }
                            }
                            inte.calcseat();
                            inte.calprice();
                            inte.writeinfileint();
                            break;
                        }

                        case 3: exit(1);

                        default: cout<<"Enter valid choice";
                    }
                }
                break;
            }

            case 1:{
                string pass;
                int count_pass=0;
                bool flag=0;
                while(count_pass!=3){
                cout<<"Enter password:";
                cin>>pass;
                try{
                    if(pass=="enough69"){
                        flag=1;
                        break;
                    }
                    else{
                        throw pass;
                    }
                }
                catch(string x){
                    cout<<"Wrong Password \n";
                    count_pass++;
                }
                }
                if(flag==0){
                    cout<<"Multiple Unsuccessful Attempts... Program Terminated\n";
                    exit(1);
                }
                flights fl;
                while(1){
                    int ch;
                    cout<<"Enter choice:\n";
                    cout<<"1. Enter domestic Flight details\n2. Enter international Flight details\n4.EXIT\n";
                    cin>>ch;
                    switch(ch){
                        case 1:{
                            fl.data_insertion_dom();
                            break;
                        }
                        case 2:{
                            fl.data_insertion_int();
                            break;
                        }
                        case 4: goto jump ;
                        default: cout<<"Please enter valid choice";
                    }
                }
            }
            default: cout<<"Enter valid choice";
        }
        }
}