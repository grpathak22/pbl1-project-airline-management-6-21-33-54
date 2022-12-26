#include <bits/stdc++.h>
using namespace std;

class customer{
public:
    int  passport_id,phone_no;
    string name;
    struct date{
        int d;
        int m;
        int y;
    }date;
public:
    virtual void get(){
        cout<<"enter full name\n";
        cin>>name;
        cout<<"enter contact number\n";
        cin>>phone_no;
        cout<<"enter passport id\n";
        cin>>passport_id;
    }    
};

void showseats(list<int> t,int check){
    char a='A';
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

void display(list<int> head, int n){
    for(auto element : head){
        cout<<element<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> h[6];

    while(1){
        int ch;
        cout<<"Enter your choice\n";
        cout<<"1.Book a ticket\n2.Cancel Booking\n3.Exit";
        cin>>ch;
        switch(ch){
            case 1:{
                char r; int c;
                cout<<"Enter the seat number you want to book(eg A 7)";
                cin>>r>>c;

                if(h[r-'A'].empty()){h[r-'A'].push_back(c);}

                else if(h[r-'A'].front() > c){h[r-'A'].push_front(c);}

                else{
                    int flag = 0;
                    list<int> :: iterator iter;
                    for(iter=h[r-'A'].begin();iter!=h[r-'A'].end();iter++){
                        if(*iter == c){cout<<"Seat already booked"; break;}
                        else if(*iter > c){
                            iter--; 
                            h[r-'A'].insert(iter,c);
                            break;
                        }
                        else{flag=1;}
                    }
                    if(flag==1){h[r-'A'].push_back(c);}
                }
                break;
            }
            case 2:{
                char r; int c;
                cout<<"Enter the seat number you booked(eg B 7)";
                cin>>r>>c;

                if(h[r-'A'].empty()){cout<<"Seat number not found";}

                else{
                    int temp = h[r-'A'].size();
                    h[r-'A'].remove(c);
                    if(temp == h[r-'A'].size()){cout<<"Seat number not found";}
                }
                break;
            }
            case 5:{
                for(int i=0;i<6;i++){
                    if(i==2 || i==3){showseats(h[i],1);}
                    else{showseats(h[i],2);}
                }
                cout<<endl;
                break;
            }
            case 3: exit(1); break;
            default: cout<<"Enter valid choice"<<endl;
        }
    }

    for(int i=0;i<6;i++){
        display(h[i],i);
    }
}
