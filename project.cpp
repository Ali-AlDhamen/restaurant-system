#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// making structure for orders and dishs
struct dishs {
    string name;
    double price;
};

struct dish {
    string dish;
    int amount;
    double price;
};

struct order {
    dish orders[10];
    double total;
    string name;
    int quantity;
};

void intro (){
    
	cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|                                                                                                                    |"<<endl;
	cout<<"|                                          Welcome To The infinte abyess                                             |"<<endl;
	cout<<"|                                                                                                                    |"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
}

void mangermenu (){
    cout<<endl;
        cout<<"Please choose the desired task: "<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"| 1 | Add new food                       |"<<endl;
        cout<<"| 2 | Update food price/name             |"<<endl;
        cout<<"| 3 | change account infomation          |"<<endl;
        cout<<"| 4 | Delete an existing food            |"<<endl;
        cout<<"| 5 | Display food menu                  |"<<endl;
        cout<<"| 6 | Display & Sort orders information  |"<<endl;
        cout<<"| 7 | Go back to coustmer serivce        |"<<endl;
        cout<<"| 8 | to display all time customers      |"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"Enter \"999\" to exit"<<endl;
        
        cout<<endl;
}
// initial menu for Resturant
void dishsmenu(dishs foods[]){
    foods[0].name = "burger";
    foods[0].price = 5.5;
    foods[1].name = "soft drinks";
    foods[1].price = 4.5;
    foods[2].name = "fries";
    foods[2].price = 5.5;
    foods[3].name = "cheese burger";
    foods[3].price = 8.5;

}

// function add spaces depends on length of the word
string spaces (string name){
    long len = name.length();
    string spaces;
    for (int i=0; i<16-len; i++) {
        spaces += " ";
    }
    return spaces;
}
// both functions to save and display customers
void savefile (string filename , string name , int qunatity , double bill){
    ofstream outfile;
    outfile.open(filename , ios::app);
    if (outfile.is_open())
    {
        
        outfile << name << "," << qunatity <<","<< bill <<  endl;
        outfile.close();
    }
    else
         cout<<"file could not be opened"<<endl;
}

void displayfile (string filename) {
    string name; 
    string quantity;
    string bill;
    ifstream inFile;
    int counter =1;
     inFile.open(filename , ios::in);
     if (inFile.is_open()){
         getline(inFile , name , ',');
         getline(inFile , quantity , ',');
         getline(inFile , bill);
  
     while (!inFile.eof())
     {
        cout<<"----------------------------------"<<endl;
        cout<<"|NO.|   Name   | Quantity | Bill |"<<endl;
        cout<<"| "<<counter<<" | "<<name<<" | "<<quantity<<" | "  <<bill<<"$ |"<<endl;
        cout<<"----------------------------------"<<endl;
         getline(inFile , name , ',');
         getline(inFile, quantity , ',');
         getline(inFile, bill);
         counter++;
     }
     inFile.close();
     }
     else
         cout<<"file could not be opened"<<endl;
}

// function to display food menu for customer
void customermenu(dishs arr [] , int size){
    cout<<endl;
    cout<<"enter number to order any dish: "<<endl;
    string space;
    cout<<"-------------------------------"<<endl;
    cout<<"| N | Dish name       | Price |"<<endl;
        for (int i=0; i<size; i++) {
            space = spaces(arr[i].name);
                        cout<<"-------------------------------"<<endl;
                        cout<<"| "<<i<<" | "<<arr[i].name<<space<<" | "<<arr[i].price<<"$"<<" | "<<endl;
                        cout<<"-------------------------------"<<endl;
        }
}

// function to check if admin info is correct
void check (string username , string password){
    string pass,user;
    do {
    cout<<endl;
    cout<<"Username: ";
        cin>>user;
    cout<<endl;
    cout<<"Password: ";
        cin>>pass;
        cout<<endl;
    if (user == username && pass == password ) {
        cout<<"you successfully logged into manger account "<<endl;
        break;
    }
    else {
        cout<<"wrong password or username, Try again! "<<endl;
    }
    }while(1>0);
}

// function to add new dishs to menu
void add ( dishs foods [] , int &size){
    size++;
    string name;
    double price;
    cout<<"enter new dish name: ";
    cin.ignore(30,'\n');
    getline(cin,name);
    cout<<"enter "<<name<<" price: ";
    cin>>price;
    foods[size-1].name = name;
    foods[size-1].price = price;
    cout<<"you have successfully added "<<name<<" to the menu "<<endl;
    mangermenu();
}

// function to display food menu
void display (dishs arr [] , int size){
    cout<<endl;
    string space;
    cout<<"-------------------------------"<<endl;
    cout<<"| N | Dish name       | Price |"<<endl;
        for (int i=0; i<size; i++) {
            space = spaces(arr[i].name);
                        cout<<"-------------------------------"<<endl;
                        cout<<"| "<<i+1<<" | "<<arr[i].name<<space<<" | "<<arr[i].price<<"$"<<" | "<<endl;
                        cout<<"-------------------------------"<<endl;
        }
        mangermenu();
}
// function to change admin acc info
void accinfo(string &username , string &password ){
    char ch;
    string pass , user;
    cout<<"Enter (U) to change username and (P) to change password: ";
    cin>>ch;
    cout<<endl;
    if (ch == 'P' || ch == 'p' ){
        cout<<"Enter your new password: ";
        cin.ignore(30,'\n');
        getline(cin,pass);
        password = pass;
        cout<<endl;
        cout<<"you have changed your password successfully "<<endl;
    }
    else if (ch == 'U' || ch == 'u' ){
        cout<<"enter your new username: ";
        cin.ignore(30,'\n');
        getline(cin,user);
        username = user;
        cout<<"you have changed your username successfully "<<endl;
    }
    else {
        cout<<"entered wrong letter! "<<endl;
    }
    mangermenu();
}
// function to change dishs name or price
void changedish(dishs arr [] , int size){
    string dish;
    char ch;
    double price;
    string name;
    int found = false;
    cout<<"enter name of dish that you want to change its name or price: ";
    cin.ignore(30,'\n');
    getline(cin,dish);
    cout<<"(P) to change price and (N) to change name: ";
    cin>>ch;
    for (int i=0; i<size; i++) {
        if (ch=='P' || ch == 'p') {
            if (arr[i].name == dish) {
                found = true;
                cout<<"enter new price for "<<arr[i].name<<": ";
                cin>>price;
                arr[i].price = price;
                cout<<endl;
                cout<<arr[i].name<<" price has been changed to "<<arr[i].price<<"$"<<endl;
                break;
            }
        }
        else if (ch =='N' || ch == 'n') {
              if (arr[i].name == dish) {
                  found = true;
                cout<<"enter new name for "<<arr[i].name<<": ";
                  cin.ignore(30,'\n');
                  getline(cin,name);
                  cout<<endl;
                  cout<<arr[i].name<<" name has been changed to "<<name<<endl;
                arr[i].name = name;
                  break;
            }
        }
        
        
    }
    if (!found)
        {
            cout<<"item not found, try again"<<endl;
        }
    mangermenu();
}

// function to order food
void ordering (string name , order arr [] , dishs foods [] , int size , int &orderno ){
    if (orderno >=size) {
        cout<<"there's not enough size for more orders! "<<endl;
        return;
    }
    else {
    int count=0;
    int order , counter =0;
    char ch;
    cout<<"welcome "<<name<<" what do you like to order: ";
    customermenu(foods, size);
    do {
        do {
            
            cin>>order;
            if (order>=size) {
                cout<<"wrong number try again! "<<endl;
                customermenu(foods, size);
            }
        } while (order>=size);
        arr[orderno].orders[counter].dish = foods[order].name;
        cout<<"how many of "<<arr[orderno].orders[counter].dish<<" do you want: ";
        cin>>arr[orderno].orders[counter].amount;
        
        arr[orderno].orders[counter].price = arr[orderno].orders[counter].amount * foods[order].price;
        count += arr[orderno].orders[counter].amount;
        counter++;
        
        
        cout<<"do you want to order something else? (Y) to continue (N) to exit "<<endl;;
        cin>>ch;
        customermenu(foods, size);
        }while (ch !='N' && ch != 'n' );
    
    cout<<endl;
    double total=0;
    cout<<"the bill: "<<endl;
    for (int i=orderno; i<orderno+1;i++ ) {
        for (int j=0; j<counter; j++) {
            cout<<arr[i].orders[j].dish<<" X "<<arr[i].orders[j].amount<<" = "<<arr[i].orders[j].price<<"$"<<endl;
            total += arr[i].orders[j].price;
        }
        
    }
    arr[orderno].quantity = count;
    arr[orderno].name = name;
    arr[orderno].total = total;
    savefile("project.txt", name , count , total );
    cout<<"your total bill = "<<total<<"$"<<endl;
    cout<<endl;
    cout<<"thank you "<<name<<" for visiting us! "<<endl;
    orderno++;
    }
}

// function to sort all orders depends on bill
void Sorting(order arr[],int size , int orderno)  {
    
    if (orderno<=1) {
        cout<<"there is nothing to sort! "<<endl;
        return;
    }
    
    int choice;
    cout<<"Do you want to sort in descending '0' or ascending order '1'?"<<endl;
    cin>>choice;
    if(choice==1)
    {
       for (int i=0; i<size-1; i++)
       {
           for(int j=0 ; j<size-1;j++)
       
    {
        if (arr[j].total>arr[j+1].total)
        {
            order temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
       }
    }
    if(choice==0)
    {
        for(int i=0 ; i<size-1 ;i++){
        
        for(int j=0 ; j<size-1;j++){
                if(arr[j].total<arr[j+1].total)
                {
                 order temp;
                 temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
                    
                }
            }
        }
         }
    cout<< "your records have been sorted "<< endl;

    }
    
// function to display customers info
void bills (order arr[] , int size) {
    string name; 
    double total;
    int count;
    int counter=1;
    for (int i=0; i<size; i++) {
        if (arr[i].total >= 1) {
        
        name = arr[i].name;
        total = arr[i].total;
        count = arr[i].quantity;
        
        cout<<"----------------------------------"<<endl;
        cout<<"|NO.|   Name   | Quantity | Bill |"<<endl;
        cout<<"| "<<counter<<" | "<<name<<" | "<<count<<" | "  <<total<<"$ |"<<endl;
        cout<<"----------------------------------"<<endl;
            counter++;
        }
    }
    
    mangermenu();
}
// function to get customers names
string getname (){
    string name;
    cout<<"welcome sir, what is your name please: ";
    cin.ignore(30,'\n');
    getline(cin,name);
    cout<<endl;
    return name;
}

//function to delete dishs
void deletedish(dishs arr [] , int &size){
    string key;
    int index = -1;
    cout<<"Enter dish name you want to delete from menu: ";
    cin>>key;
    
    
    for(int i = 0; i < size; i++)
    {
        if(arr[i].name == key)
        {
            index = i;
            break;
        }
    }

    if(index != -1)
    {
        //shift all the element from index+1 by one position to the left
        for(int i = index; i < size - 1; i++){
            arr[i].name = arr[i+1].name;
            arr[i].price = arr[i+1].price;
        }
        size--;
        
        cout<<key<<" has been deleted successfully "<<endl;
    }
    else
        cout<<"Element Not Found\n";
        mangermenu();
}
// prototype for customer function
void customer (string &username , string &password , int &size , dishs foods [], order arr[], int &orderno , int orders );

// manger function to show manger menu and choose operation
void manger (string &username , string &password , int &size , dishs foods [], order arr[], int &orderno , int orders){
    check(username , password);
    mangermenu();
    int choice;
    do{
    cin>>choice;
    switch (choice) {
        case 1:
            add(foods , size);
            break;
        case 2:
            changedish(foods , size);
            break;
        case 3:
            accinfo(username , password);
            break;
        case 4:
            deletedish(foods, size);
            break;
        case 5:
            display(foods , size);
            break;
        case 6:
            Sorting(arr, orders , orderno);
            bills(arr, orders);
            break;
        case 7:
            customer(username , password , size , foods , arr , orderno , orders);
            mangermenu();
            break;
        case 8:
            displayfile("project.txt");
            mangermenu();
            break;
        default:
            if (choice!=999) {
                cout<<"invaild input! "<<endl;
                mangermenu();
                break;
            }
            
    }
     }while(choice != 999);


}
// final function to start the app
void start (string &username , string &password , int &size , dishs foods [], order arr[], int &orderno , int orders){
    dishsmenu(foods);
    char menutype;
    cout<<"good morning sir, choose your menu (C for customer and M for manger): ";
    cin>>menutype;
    if (menutype == 'M' || menutype == 'm') {
        manger(username , password , size , foods , arr , orderno , orders);
    }
    else if (menutype == 'C' || menutype == 'c') {
        
        customer(username , password , size , foods , arr , orderno , orders);
    }
    else {
        cout<<"Invalid input! "<<endl;
    }
}

int main() {
    const string filename = "project.txt";
    string username = "Admin";
    string password = "Admin12345";
    int size =4 , orders;
    dishs foods[size];
    int orderno =0;
    intro();
    cout<<"Enter The maximum number of orders: ";
    cin>>orders;
    cout<<endl;
    order arr[orders];

    start(username , password , size , foods , arr , orderno , orders);
    
    return 0;
}


void customer (string &username , string &password , int &size , dishs foods [], order arr[], int &orderno , int orders ){
    char ch;
    do {
        string name = getname();
        ordering(name ,arr, foods, size , orderno);
        cout<<"do you want to order again? (Y) for yes and (N) for no"<<endl;
        cin>>ch;
    }while (ch!= 'N' && ch!= 'n');
    
    char switcho;
    cout<<"do you want quit program or switch to manger menu (Q) to quit and (M) for manger menu: ";
    cin>>switcho;
    if (switcho == 'M' || switcho == 'm') {
        manger(username , password , size , foods , arr , orderno , orders);
    }

}
