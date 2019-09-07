//Project Name: Angeles_Project1 
//Author Name: Alfonso Angeles 
//Date Created: 10/19/18 
//Last Edited by: Alfonso Angeles
//Last Edited at: 10/22/18
//Purpose: Assist the user in living a healthier lifestyle 
//**********************************************************************************************//
#include <iostream> 
#include<string> 
#include<iomanip> 
#include<cmath> 

using namespace std; 

void createId(string&); 

int main(){ 
//instantiating varibles necessary for algorithm execution
string buffer; 
int sentinel=0; 
//instantiating and declaring user names
string user1= "User1"; 
string user2= "User2"; 
string user3= "User3"; 

//instantiating and declaring user passwords
string password1= "password1"; 
string password2= "password2"; 
string password3= "password3"; 

//instantiating and declaring user unique IDs

string uniq1, uniq2, uniq3;
    createId(uniq1);
    createId(uniq2);
    createId(uniq3);


//instantiating variables corresponding to user input 
string login; 
string password; 
string userID; 
string firstName; 
string middleName; 
string lastName; 
double weight; 
double height; 
int month; 
int day; 
int year; 
string famHistory; 
string diseases; 
char gender; 

//instantiating variable which will contain the results of calculations 
int age; 
double bmi; 
string largeBMI; 
string subBMI; 
string message; 
string actionPlan; 

//printing welcom message to user
cout<<"Welcome! "<<endl; 

//prompt the user to enter their user name 
//confirm that the input is a valid user name
//rerun if the the input is not a valid username
while(sentinel==0){ 
    cout<< "\nPlease enter your user name: " <<endl; 
    cin>>login; 
    if( (login==user1) || (login==user2) || (login==user3) ){
        sentinel=1;
    }
    else{ 
        cout<< "\nThat's not a vaild user name" <<endl; 
    }
}
sentinel=0; 

//prompt the user to enter their password
cout<< "\nPlease enter your password: " <<endl; 
cin>> password; 

//confirm that the input is a valid password 
//and corresponds to the given username 
while(sentinel==0){
    if( (login==user1) && (password==password1) ){
        sentinel=1; 
    }
    else if( (login==user2) && (password==password2)){
        sentinel=1; 
    }
    else if( (login==user3) && (password==password3)){
        sentinel=1; 
    }
    else{
        cout<< "\nThat is not the correct password"<<endl; 
        cout<< "\nPlease enter your password: " <<endl; 
        cin>>password; 
    }
}
sentinel=0; 

//prompt the user to input their first, middle, and last names 
//Ensure that the first index of each name is not a number
//assign this input to their corresponding variables 
while
(sentinel==0){
cout<< "\nPlease enter your full name (First Middle Last)" <<endl; 
cin>> firstName >> middleName >> lastName;  

if( (((int)(firstName.at(0))>=65) && ((int)(firstName.at(0))<=90)) ||
     (((int)(firstName.at(0))>=97) && ((int)(firstName.at(0))<=122)) ){
    if( (((int)(middleName.at(0))>=65) && ((int)(middleName.at(0))<=90)) ||
     (((int)(middleName.at(0))>=97) && ((int)(middleName.at(0))<=122)) ){
        if( (((int)(lastName.at(0))>=65) && ((int)(lastName.at(0))<=90)) ||
     (((int)(lastName.at(0))>=97) && ((int)(lastName.at(0))<=122)) ){
            sentinel=1; 
        }
        else
        cout<<"Please enter valid names"<<endl; 
    }
    else
    cout<<"Please enter valid names"<<endl; 
}
else
cout<<"Please enter valid names"<<endl; 
}
sentinel=0; 

//prompt the user to input their weight 
//assign this input to the corresponding variable 
while(sentinel==0){
cout<< "\nPlease enter your weight (in lbs): " <<endl; 
cin>> weight; 
if(weight>0){
sentinel=1; 
}
}
sentinel=0; 

//prompt the user to input their height 
//assign this input to the corresponding variable
while(sentinel==0){
cout<< "\nPlease enter your height (in inches): " <<endl; 
cin>> height; 
if(height>0){
    sentinel=1; 
}
}
sentinel=0; 

//prompt the user to input their date of birth 
//assign this input the their corresponding variables 
cout<< "\nPlease enter your date of birth (Month Day Year): " <<endl; 
cin>> month >> day >> year; 

//ask the user if their family has a history of disease 
//rerun when invalid input is entered, until valid input is entered
//declare variable corresponding to disease to the appropriate value 
while(sentinel==0){
cout<<"\nAre there any known genetic diseases in your family? (yes or no)"<<endl; 
cin>> famHistory;

if(famHistory=="yes"){
    cout<<"\nPlease enter the known diseases (each separated by a coma): "<<endl;  
    cin >> buffer; 
    getline(cin, diseases); 
    sentinel=1;
}
else if(famHistory=="no"){
    diseases="None"; 
    sentinel=1; 
}
else{
    cout<<"\nThat was not a valid input."<<endl;     
}
}
sentinel=0; 

//prompt the user to enter a character corresponding to their gender 
//store this input in the corresponding variable
cout<<"\nPlease enter your gender (use a single character): "<<endl; 
cin>>gender; 

//calculate the user's BMI (mass(kg)/height(m)^2)
bmi=((weight/2.2)/(pow((height*0.0254),2))); 
//round bmi to three demical places 
bmi=((int)(bmi*1000.0))/1000.0;

//calculate category 1 bmi value 
if(bmi<18.5){
    largeBMI="Underweight"; 
}
else if(bmi<25){
    largeBMI="Normal"; 
}
else{
    largeBMI="Overweight"; 
}

//calculate category 2 bmi value 
if(bmi<15){
    subBMI="Very severely underweight";
    message= "Try eating more often";
    actionPlan= "Eat more than three meals a day"; 
}
else if(bmi<16){
    subBMI="Severely underweight";
    message= "Increase portion sizes";
    actionPlan= "Order/Make more food when eating"; 
}
else if(bmi<18.5){
    subBMI="Underweight";
    message= "Start bringing snacks with you";
    actionPlan= "Increase protein intake"; 
}
else if(bmi<25){
    subBMI="Normal";
    message= "You're very healthy";
    actionPlan= "Keep doing what you're doing"; 
}
else if(bmi<30){
    subBMI="Overweight";
    message= "Some exercise is necessary";
    actionPlan= "Go to the gym 3 days a week "; 
}
else if(bmi<35){
    subBMI="Obese class 1 (Moderately obese)";
    message= "Decrease portion sizes";
    actionPlan= "Eat slightly smaller meals";
}
else if(bmi<40){
    subBMI="Obese class 2 (Severely obese)";
    message= "Start watching how many carbs are being consumed";
    actionPlan= "Slowly remove some heavy startches from your diet"; 
}
else{
    subBMI="Obese class 3 (Very severely obese)";
    message= "Your diet could use some work";
    actionPlan= "Remove food stuff containing large sums of sugar/high fructose corn syrup"; 
}

//calculating the user's age from the given date of birth 
if(((month-10)<0)||(((month-10)==0)&&((day-22)<=0))){
    age=2018-year; 
}
else {
    age=2017-year; 
}

if(login=="User1"){
    userID=uniq1;
}
else if(login=="User2"){
    userID=uniq2; 
}
else{
    userID=uniq3; 
}

//printing out user output menu 

cout<< "\n\nID: " << userID << endl; 
cout<< "Name: "<< lastName <<", "<< middleName.at(0) << ", "<<firstName<<endl; 
cout<< "Age: " << age << endl; 
cout<< "Sex/Gender: " << gender << endl; 
cout<< "Weight:\t"<<fixed<<setprecision(2)<<weight<<"lbs\t"<<(weight/2.2)<<"kg"<<endl; 
cout<< "Height:\t"<<setprecision(2)<<height<<"in\t\t"<<(height*0.0254)<<"m"<<endl; 
cout<< "Disease: "<< famHistory << " - "<< buffer<< " "<<diseases<<endl; 
cout<< "BMI:\t"<<setprecision(3)<<bmi<<" "<<"BMI Category- "<<largeBMI<< " \n\tBMI Sub-category: "<<subBMI<<"\n\t"<<message<<endl; 

//Printing a personalized report for the user
//Details how to acheive a normal BMI 
cout<< "Report: ";   
if(bmi>25){
    cout<<"Try to lose "<< weight-((pow(height*0.0254,2))*25*2.2) <<"lbs\n"<<"\t"<<actionPlan<<endl; 
}
else if(bmi<18.5){
    cout<<"Try to gain "<< ((pow(height*.0254,2))*18.5*2.2)-weight <<"lbs\n"<<"\t"<<actionPlan<<endl; 
}
else{
    cout<<"Try to stay at the same weight. "<<actionPlan<<"\n"<<endl; 
}

//printing exit message 
cout<<"Thank you for using this program. We hope you reach your goal!\n\n"<<endl; 
    return 0; 
}

//Creates a random Id consisting of 4 integers 0-9 and a character a-z 
void createId(string& id){
    //resets id
    id ="";
    //creates a random seed based on internal clock
    srand(time(NULL));
    //fills in the first four digits of id with random integers 0-9
    for(int i=0; i<4; i++){
        id= id+((char)(rand()%10+48));
    }
    //appends a random character a-z to the end of id
    id=id + ((char)(rand()%26+97));
}
