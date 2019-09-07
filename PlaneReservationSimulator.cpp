//Project Name: PlaneReservationSimulator.cpp
//Author Name: Alfonso Angeles 
//Date Created: 12/9/18 
//Last Edited by: Alfonso Angeles
//Last Edited at: 12/9/18
//Purpose: Assist users is flight reservations 
#include<iostream>
#include<iomanip>
#include<fstream> 
#include<ostream> 
#include<vector> 
#include<string>


using namespace std; 

struct valid_user{
    int id; 
    string first; 
    string last; 
    string username; 
    string password; 
};

//Prototypes for all functions in this program
void login(valid_user[], int, valid_user&); 
void populateUsers(valid_user[]); 
void populateSeatChart(string [10][7], string&);
void menu(string, string, string [10][7], string[10][7], string&); 
void seats(string [10][7]); 
void reserve(string [10][7], string [10][7]); 
string seatType(int); 
void toUpperCase(string&); 
void cancel(string [10][7], string[10][7]); 
void save(string [10][7], string&); 

void stats(string [10][7], string[10][7]); 
void help(); 
void quit(int&); 


int main(){

//Creating and populating seatchart
string seatchart[10][7]; 
string blankchart[10][7]; 
string file="chartIn.txt"; 
populateSeatChart(seatchart, file); 
populateSeatChart(blankchart, file); //This is used in the reservation function to determine placement
//Creating and populating valid_user array
valid_user users[4]; 
populateUsers(users); 

//Prompt the user for login info
//Ensure a valid username/password is entered 
//Save which user is being accessed
valid_user user1; 
login(users, 4, user1); 

//Displaying the menu to the user 
menu(user1.first, user1.last, seatchart, blankchart, file);

    return 0; 
}

//Author:Alfonso Angeles
//Date Created: 12/9/18
//Purpose: Populate the original seating chart
//Date Last Edited: 12/9/18
//Pre-Condition: file is formatted correctly
//Post Condition: The 2d string array is filled witht the data from the file 
void populateSeatChart(string arr[10][7], string& file){
ifstream inFS; 
inFS.open(file); 
for(int i=0; i<10; i++){
    for(int j=0; j<7; j++){
        inFS>>arr[i][j]; 
    }
}
inFS.close(); 
}

//Author: Alfonso Angeles
//Date Created:12/9/18
//Purpose: Populate an array with the users with the data from the file systemUser
//Date Last Edited:12/9/18
//Pre-Condition: systemUser is formatted appropriately 
//Post Condition: the valid_user array is now populated 
void populateUsers(valid_user arr[]){
ifstream inFS; 
inFS.open("systemUser.txt"); 
int i=0; 
while(!inFS.eof()){
    inFS>>arr[i].id; 
    inFS>>arr[i].first; 
    inFS>>arr[i].last; 
    inFS>>arr[i].username; 
    inFS>>arr[i].password; 
i++; 
}
inFS.close(); 
}

//Author: Alfonso Angeles
//Date Created:12/9/18
//Purpose: ensure the user has a valid username and passoword
//Date Last Edited:12/9/18
//Pre-Condition:The valid users array is populated and the user has a valid username/password
//Post Condition: The user is passed onto the actual program
void login(valid_user arr[], int size, valid_user& user1){
string username; 
string password; 
cout<<"----------------------------------------------------------------"<<endl; 
cout<<"                 WELCOME TO AIR TICKET SYSTEM                   "<<endl; 
cout<<"----------------------------------------------------------------"<<endl; 

int sentinel=0; 
while(sentinel==0){
cout<<"Please enter your username: "; 
cin>>username; 
cout<<"\n\n";
cout<<"Please enter your password: ";
cin>>password; 

int index=-1;
for(int i=0; i<size; i++){
    if(arr[i].username==username)
        index=i; 
}

    if(index!=-1 && arr[index].password==password){
        user1=arr[index];
        sentinel=1; 
    }
    else{
        cout<<"Please enter a valid username/password"<<endl;
    }
}
}

//Author:Alfonso Angeles
//Date Created:12/9/18
//Purpose:Display an interactive menu to the reader
//Date Last Edited:12/9/18
//Pre-Condition:All files and arrays are properly populated/formatted
//Post Condition: The user is able to select any of the options from the menu 
void menu(string first, string last, string arr[10][7], string blankArr[10][7], string& file){
    int sentinel=0; 
while(sentinel==0){
    int choice; 
cout<<"----------------------------------------------------------------"<<endl; 
cout<<"      WELCOME TO AIR TICKET SYSTEM - "<<first<<" "<<last<<"    "<<endl; 
cout<<"----------------------------------------------------------------"<<endl; 
cout<<"\t1.Display Seat Chart"<<endl; 
cout<<"\t2.Reserve Seat"<<endl; 
cout<<"\t3.Cancel Reservation"<<endl; 
cout<<"\t4.Save Seat Chart to File"<<endl; 
cout<<"\t5.Statistics"<<endl; 
cout<<"\t6.Help"<<endl; 
cout<<"\t7.Quit"<<endl; 
cout<<"----------------------------------------------------------------"<<endl; 
cout<<"Please Enter Your Choice (1-7) : "<<endl; 
cin>>choice;
cout<<"----------------------------------------------------------------"<<endl; 

switch(choice){
    case 1: seats(arr); 
            break; 
    case 2: reserve(arr, blankArr); 
            break; 
    case 3: cancel(arr, blankArr); 
            break; 
    case 4: save(arr, file); 
            break; 
    case 5: stats(arr, blankArr); 
            break;
    case 6: help(); 
            break; 
    case 7: quit(sentinel); 
            break; 
    default: 
            cout<<"Please enter a valid choice"<<endl; 
}
}
}

//Author: Alfonso Angeles
//Date Created: 12/9/18
//Purpose: Display the current seat chart
//Date Last Edited: 12/9/18
//Pre-Condition: The string array has been properly populated
//Post Condition: The string array is printed to the user 
void seats(string arr[10][7]){
cout<<"\tWindow\tCenter\tAisle\tAisle\tCenter\tWindow"<<endl; 
for(int i=0; i<10; i++){
    for(int j=0; j<7; j++){
        cout<<arr[i][j]<<"\t"; 
    }
    cout<<endl; 
}
}

//Author: Alfonso Angeles
//Date Created: 12/9/18
//Purpose: To allow the user to reserve a seat on the plane
//Date Last Edited: 12/9/18
//Pre-Condition: Both arrays are properly populated
//Post Condition: The user's selection is reserved when applicable 
void reserve(string arr[10][7], string blankArr[10][7]){
int row=-1; 
int col; 
int sentinel=0; 

while(sentinel==0){
string seat; 
cout<<"Please enter your seat selection: "; 
cin>>seat; 
toUpperCase(seat); 
cout<<endl; 
row=-1; 
for(int i=0; i<10; i++){
    for(int j=1; j<7; j++){
        if(blankArr[i][0]+blankArr[i][j]==seat){
            row=i; 
            col=j; 
        }
    }
}

if(row!=-1){
    if(arr[row][col]!="X"){
        arr[row][col]="X"; 
        cout<<"Your seat was reserved: "<<seat<<" "<<seatType(col)<<endl; 
        sentinel=1; 
    }
    else{
        cout<<"That seat was already reserved."<<endl;
    }
}
else{
    cout<<"That is not a valid seat"<<endl;
}
}
}

//Author: Alfonso Angeles
//Date Created: 12/9/18
//Purpose: Cancel a previously made reservation
//Date Last Edited:12/9/18
//Pre-Condition: both arrays are properly filled
//Post Condition: the user's reservation is cancelled when applicable 
void cancel(string arr[10][7], string blankArr[10][7]){
int row=-1; 
int col; 
int sentinel=0; 

while(sentinel==0){
string seat; 
cout<<"Please enter your seat selection: "; 
cin>>seat; 
toUpperCase(seat); 
cout<<endl; 
row=-1; 
for(int i=0; i<10; i++){
    for(int j=1; j<7; j++){
        if(blankArr[i][0]+blankArr[i][j]==seat){
            row=i; 
            col=j; 
        }
    }
}

if(row!=-1){
    if(arr[row][col]=="X"){
        arr[row][col]=seat.at(seat.length()-1); 
        cout<<"Your reservation was cancelled: "<<seat<<" "<<seatType(col)<<endl; 
        sentinel=1; 
    }
    else{
        cout<<"That seat was already open."<<endl;
    }
}
else{
    cout<<"That is not a valid seat"<<endl;
}
}
}

//Author: Alfonso Angeles
//Date Created: 12/9/18
//Purpose: Determines the seat type 
//Date Last Edited: 12/9/18
//Pre-Condition: The int parameter corresponds to the correct seat in question
//Post Condition: The correct seat type (window, center, aisle) is returned
string seatType(int col){
    if(col==1||col==6)
        return "Window"; 
    else if(col==2||col==5){
        return "Center";
    }
    else{
        return "Aisle"; 
    }
}

//Author: Alfonso Angeles
//Date Created:12/9/18
//Purpose:Changes the provided string to uppercase
//Date Last Edited:12/9/18
//Pre-Condition: the string is valid
//Post Condition: The strings letters are all turned to uppercase 
void toUpperCase(string& seat){
    for(int i=0; i<seat.length(); i++){
        seat.at(i)=toupper(seat.at(i)); 
    }
}

//Author: Alfonso Angeles
//Date Created: 12/9/18
//Purpose: Save the current chart into a user defined text file
//Date Last Edited: 12/9/18
//Pre-Condition: the array is properly filled and the file exists
//Post Condition: The filed is filled with the contents of the array 
void save(string arr[10][7], string& file){
    ofstream outFS; 
    cout<<"Please enter the file you wish to print to: "; 
    cin>>file; 
    cout<<endl; 
    outFS.open(file); 
for(int i=0; i<10; i++){
    string line=""; 
    for(int j=0; j<7; j++){
        if(j!=0)
            line+="\t";
        line+=arr[i][j];
    }
    outFS<<line<<endl; 
}
outFS.close();
cout<<"The file was saved successfully"<<endl;  
}

//Author: Alfonso Angeles
//Date Created:12/9/18
//Purpose:Print stats about the seating chart
//Date Last Edited: 12/9/18
//Pre-Condition: the arrays are properly filled
//Post Condition: stats are printed about the seating chart
void stats( string arr[10][7], string blankArr[10][7]){
   int numX=0; 
   string available=""; 
   string taken=""; 
    for(int i=0; i<10; i++){
        for(int j=1; j<7; j++){
            if(arr[i][j]=="X"){
                numX++; 
                taken+=(blankArr[i][0]+blankArr[i][j]+", "); 
            }
            else{
                available+=(arr[i][0]+arr[i][j]+", ");
            }
        }
    }
    cout<<"Number of available seats: "<<60-numX<<endl; 
    cout<<"Number of seats resereved: "<<numX<<endl; 
    cout<<"Percentage of seats available: "<<(60-numX)/60.0*100<<"%"<<endl; 
    cout<<"Percentage of seats taken: "<<(numX)/60.0*100<<"%"<<endl; 
    cout<<"List of available seats: "<<available<<endl; 
    cout<<"List of taken seats: "<<taken<<endl; 
    ofstream outFS; 
    outFS.open("statistics.txt"); 
    outFS<<"Number of available seats: "<<60-numX<<endl; 
    outFS<<"Number of seats resereved: "<<numX<<endl; 
    outFS<<"Percentage of seats available: "<<(60-numX)/60.0*100<<"%"<<endl; 
    outFS<<"Percentage of seats taken: "<<(numX)/60.0*100<<"%"<<endl; 
    outFS<<"List of available seats: "<<available<<endl; 
    outFS<<"List of taken seats: "<<taken<<endl; 
}

//Author: Alfonso Angeles
//Date Created:12/9/18
//Purpose: Print a help message to the user 
//Date Last Edited: 12/9/18
//Pre-Condition:None
//Post Condition: The help messages are printed
void help(){
cout<<"Option 1: Prints the current scheduled plane plans\nSimply enter 1 in the option menu."<<endl; 
cout<<"Option 2: Creates a reservation for a seat (reservations are denoted by \"X\"\nenter 2 on the"
<<" option menu, follow with the selection of the seat as one whole string Ex. 1a of 1A"<<endl; 
cout<<"Option 3: Cancels previously saved reservations, enter the desired seat cancellation in the same format as when making the"<<
" reservation"<<endl; 
cout<<"Option 4: Saves the current plane seating chart to a file declared by the user\nwhen prompted enter the name of the file you wish"<<
" to print to"<<endl; 
cout<<"Option 5: Prints the stats about the current seating chart, number of seats taken/available, percent of seats available/take"<<
" list of seats taken/available -- just select 5 in the option menu"<<endl; 
cout<<"Option 6: You clicked this option to get to this screen! This is what it does"<<endl; 
cout<<"Option 7: This function will cause the program to terminate -- select 7 in the option menu"<<endl; 
}

//Author:Alfonso Angeles
//Date Created: 12/9/18
//Purpose: To terminate the program
//Date Last Edited: 12/9/18
//Pre-Condition: the programs stopping condition is dependant on the variable sentinel
//Post Condition: the program terminates 
void quit(int& sentinel){
    sentinel++;
}
