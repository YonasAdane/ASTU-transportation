#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct bus{
    string driver;
    int distance;
    int plate;
    string destination;
    bus* next;
};
bus* head=NULL;
void add_bus(){
	char choice;
	do{
        bus* nwbus=new bus;
        nwbus->next=NULL;
        string name,dest;
        int tar ,d;
        cout<<"enter driver's name : "<<endl;
        cin>>name;
        cout<<"enter destination   : "<<endl;
        cin>>dest;
        cout<<"enter the distance  : "<<endl;
        cin>>d;
        cout<<"enter plate number  : "<<endl;
        cin>>tar;
        nwbus->driver=name;
        nwbus->distance=d;
        nwbus->destination=dest;
        nwbus->plate=tar;
        if (head==NULL)
        {
            head=nwbus;
            nwbus->next=NULL;
        }
        else
        {
            nwbus->next=head;
            head=nwbus;
        }
    cout << "do you want to continue y/n: ";
    cin >> choice;
	}while(choice=='y');

}
void del_bus(){
    bus* temp=new bus;
    temp= head;
    if(head==NULL)
        cout<<"empty bus"<<endl;
    else {
        int n;
        cout<<"delete which buss : ";
        cin>>n;
        for(int i=2; i<n; i++) {
        if(temp->next!=NULL) {
            temp = temp->next;
    }
}
        temp->next = temp->next->next;
}
}
void display(){
    system("cls");
    char choice;
    do{
        bus *temp=new bus;
        temp=head;
        while(temp!=NULL){
            cout<<"driver's name : "<<temp->driver<<endl;
            cout<<"destination   : "<<temp->destination<<endl;
            cout<<"plate number  : "<<temp->plate<<endl;
            cout<<"distance      : "<<temp->distance<<endl<<endl;
            temp=temp->next;
        }
        cout <<"press m to return to menu: ";
        cin>> choice;
    }while(choice=='!');

}
void about(){
    system("cls");
    char choice;
    do{
        
        cout << "///////////////////////////////////////////////////////////////////////" <<endl;
        cout <<"_____________________________ABOUT THE SYSTEM___________________________" <<endl;
        cout << "///////////////////////////////////////////////////////////////////////" <<endl;
        cout<<"This is the ASTU Transportation System, made for bus drivers, administrators,"<<endl;
        cout<<" and staff of ASTU. Employees are transported to their residences by busses from"<<endl;
        cout<<"the university.This system assists staff members in choosing the bus that "<<endl;
        cout<<"travels along their routes.Administrators also can use it to delete buses from"<<endl;
        cout <<"the system and add new ones, as well as update bus information like driver changes."<<endl<<endl;
        cout <<"press m to return to menu: ";
        cin>> choice;
    }while(choice=='!');

}
void loadfile(){
    fstream myfile;
    myfile.open("transport.txt", ios::in) ; //read from data
    //checking whether the file is open.
    if(myfile.is_open()){
        int tar,d;
        string name,dest,sts,sttar ;
        while(myfile>>name>>sts>>sttar>>dest){
        stringstream strm(sts);
        strm>>d;               //String to int conversion
        stringstream st(sttar);
        st>>tar;
        bus* nwbus=new bus;    //creating new bus(node)
                nwbus->next=NULL;          //
                nwbus->driver=name;
                nwbus->distance=d;         // assigning new value
                nwbus->destination=dest;         //to it
                nwbus->plate=tar;          //
                if (head==NULL)
                    {                      //
                        head=nwbus;
                        nwbus->next=NULL;       //Adding created node
                    }                      //
                else
                {
                    nwbus->next=head;
                    head=nwbus;                       //
                }
        }
    }
}
void savefile(){
      fstream saver;
      saver.open("transport.txt", ios::out) ; //write on the data
      bus *temp=new bus;
      temp=head;
      if(saver.is_open()){
    while(temp!=NULL){
        saver<<temp->driver<<" ";
        saver<<temp->distance<<" ";
        saver<<temp->plate<<" ";
        saver<<temp->destination<<"\n";
        temp=temp->next;
    }
    saver.close();
      }
}
void edit_bus(){
    bus* temp=new bus;
    temp= head;
    if(head==NULL)
        cout<<"empty bus"<<endl;
    else {
        int n;
        cout<<"edit which buss : ";
        cin>>n;
        for(int i=0;i<n-1;i++){
        if(temp->next!=NULL) {
            temp = temp->next;
    }
        }
    string name,dest;
    int tar ,d;
    cout<<"enter driver's name : "<<endl;
    cin>>name;
    cout<<"enter destination   : "<<endl;
    cin>>dest;
    cout<<"enter the distance  : "<<endl;
    cin>>d;
    temp->driver=name;
    temp->distance=d;
    temp->destination=dest;
    }

}
void serch(){
    bus* temp=new bus;
    temp = head;
    int k,i=1;
    cout<<"where to go"<<endl;
    while(temp){
        cout<<i<<" "<<temp->destination<<endl;
        temp=temp->next;
        i++;
    }
    cin>>k;
      bus* nw=new bus;
      nw = head;
    for(int i=1;i<k;i++)
        nw=nw->next;
        cout<<"driver's name : "<<nw->driver<<endl;
        cout<<"destination   : "<<nw->destination<<endl;
        cout<<"plate number  : "<<nw->plate<<endl;
        cout<<"distance      : "<<nw->distance<<endl<<endl;
}
void service(){
   system("cls");
    char choice;
    do{
bus *temp=new bus;
    temp=head;
    while(temp!=NULL){
        cout<<"destination   : "<<temp->destination<<endl;
        temp=temp->next;
    }
    cout <<"press m to return to menu: ";
        cin>> choice;
    }while(choice=='!');
}
void sch(){
    char choice;
    do{
        string place;
        int x=0;
        cout<<"enter the the place you want to go ";
        cin>>place;
        bus *temp=new bus;
        temp=head;
        while(temp!=NULL){
            if(temp->destination==place){
                   x=1;
                cout<<"driver's name : "<<temp->driver<<endl;
                cout<<"destination   : "<<temp->destination<<endl;
                cout<<"plate number  : "<<temp->plate<<endl;
                cout<<"distance      : "<<temp->distance<<endl<<endl;
            }
            temp=temp->next;
        }
        if(x==0)
            cout<<" not found"<<endl;
        cout <<"press m to return to menu: ";
        cin>> choice;
    }while(choice=='!');


}
int main()
{
    loadfile();
    while(1){
            a:
            system("cls");
    cout << "///////////////////////////////////////////////////////////////" <<endl;
    cout <<"_____________ASTU TRANSPORT OFFICE MANAGEMENT SYSTEM____________" <<endl;
    cout << "///////////////////////////////////////////////////////////////" <<endl;
    int x;
    cout<<"                           enter a number"<<endl;
    cout<<"                      1 to add a new buse"<<endl;
    cout<<"                      2 to remove"<<endl;
    cout<<"                      3 to get information"<<endl;
    cout<<"                      4 to edit buses"<<endl;
    cout<<"                      5 to see destinations"<<endl;
    cout<<"                      6 search "<<endl;
    cout<<"                      7 About"<<endl;
    cout<<"                      8 to exit"<<endl;
    cin>>x;
    switch(x){
    case 1:
        add_bus();
        break;
    case 2:
        del_bus();
        break;
    case 3:
        display();
        break;
    case 4:
        edit_bus();
        break;
    case 5:
        service();
        break;
    case 6:
        sch();
        break;
    case 7:
        about();
        break;
    case 8:
        savefile();
        return 0;
        break;
    default:
        goto a;
        break;
    }}
    savefile();
    return 0;
}
