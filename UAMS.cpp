#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;
 void Register();
 bool login();
 void Header();
 void Menu();

 int loadFromFile(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[]);
 void saveToFile(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[], int indx);

 int addstudent(string name[],string Cnic[],float Matric[],float Fsc[],float ECAT[] , float Merit[], int num,int indx);
 int update(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[], int indx);
 void View(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[], int &indx);
 void merit(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[], int indx);
 void Delete(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[], int &indx);
 string getfield(string record, int field);
 void readData(string names[], string passwords[], int &indx);
 int isPresent(string name, string password, string names[], string passwords[], int idx);

 string getfield(string record, int field)
 {
  int commaCount = 1;
  string item = "";
  for(size_t x = 0; x < record.length(); x++)
  {
    if (record[x] == ',')
        {
            commaCount = commaCount + 1;
            continue;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
      }
      return item;
 }
  void readData(string names[], string passwords[], int &indx)
  {
    indx = 0;
    ifstream file("UAMS(Pass).txt");
    if(!file.is_open())
    {
      return;
    }
    string record;
    while(getline (file, record))
    {
      names[indx] = getfield (record, 1);
      passwords[indx] = getfield(record, 2);
      indx++;

      if(indx >= 100)  break;
    }
    file.close();
  }

  int main()
{   
  system("cls");
  int ch;
  bool loggedin = false;

   while (!loggedin){
    system("cls");
    cout<<" #========================================#"<<endl;
    cout<<" # University Admission Management System #"<<endl;
    cout<<" #========================================#\n"<<endl;                 

    cout<< "1. Register User"<< endl;
    cout<< "2. Login"<< endl;

    cout<< "Choose option: ";
    cin>>ch;

    if (ch == 1){
      Register();
    }
    else if (ch == 2){
      if (login()){
        cout<< "\033[32mLogin successfull welcome!\033[0m " <<endl;
        loggedin = true;
        cout<< "Press Any Key To Continue To Menu...." << endl;
        getch();
        break;
      }
      else {
        cout<< "\033[31mInvalid username or password! (Access Denied....)\033[0m" << endl;
        cout<< "Press Any Key To Try Again....."<< endl;
        getch();
      }
    } 
    else {
      cout<< "Invalid Option."<< endl;
      getch();
    }
   }

   string name[100], Cnic[100];
   float Matric[100], Fsc[100], ECAT[100], Merit[100];
   int indx = 0;
   indx = loadFromFile(name, Cnic, Matric, Fsc, ECAT, Merit);

   int op;
   int num;

   while(true){
    Header ();
    Menu();
    cout<<"\033[32mCHOOSE AN OPTION FROM MENU\033[0m: ";
    cin>>op;

    if (op == 1) {

    
         cout<< "How many students you want to Add: ";
         cin>> num;
         indx = addstudent(name , Cnic , Matric ,  Fsc ,  ECAT , Merit , num , indx);
         saveToFile(name, Cnic, Matric, Fsc, ECAT, Merit, indx);
         cout<< "\n\033[32mStudents Added Successfully!\033[0m\n";
         
    }
    
  
    else if (op == 2){
    
    
    cout<<"You Have Entered Option:2"<<endl;
    update(name , Cnic , Matric ,  Fsc ,  ECAT , Merit , indx);
    saveToFile(name, Cnic, Matric, Fsc, ECAT, Merit, indx);
    }
      else if(op == 3){
    
     
     cout<<"You Have Entered Option:3"<<endl;
     merit(name , Cnic , Matric ,  Fsc ,  ECAT , Merit ,indx);
     saveToFile(name, Cnic, Matric, Fsc, ECAT, Merit, indx);
     
}
 else if(op == 4){

   cout<<"You have entered option :4"<< endl;
   Delete(name, Cnic, Matric, Fsc, ECAT, Merit , indx);
   saveToFile(name, Cnic, Matric, Fsc, ECAT, Merit, indx);
   

   }
    else if(op == 5){

     
     cout<<"You Have Entered Option:5"<<endl;
     View(name , Cnic , Matric ,  Fsc ,  ECAT , Merit , indx);
     
}
  
    else if(op == 6){
      cout<< "\033[33mExiting Program.....\033[30m\n";
      return 0;
     }
      else
           {
          cout<< "Invalid Option. Try again.\n";
    }
     cout<<"Press Any Key To Continue......";
     getch();
     system("cls");
} 
}
  int loadFromFile(string name[], string Cnic[], float  Matric[], float Fsc[], float ECAT[], float Merit[])
{
    ifstream fin("Student Credentials.txt");
    int i = 0;

    if(!fin) return 0;

    while(getline(fin,name[i], '|') && getline(fin, Cnic[i], '|') && fin >> Matric[i] && fin.ignore() && fin>> Fsc[i] && fin.ignore() && fin >> ECAT[i] && fin.ignore() && fin >> Merit[i])
    {
        fin.ignore();
        i++;
    }
    return i;
}

 void saveToFile(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[], int indx)
 {
     ofstream fout("Student Credentials.txt");

    for(int i = 0; i < indx; i++){
        fout << name[i] << "|" << Cnic[i] << "|" << Matric[i] << "|" << Fsc[i] << "|" << ECAT[i] << "|" << Merit[i] << endl;
    }
    }
 
    
void Register()
{
   system("cls");
   cout << " |==============================================|" <<endl;
   cout<<  " |<<<<<<<<<<<<  USER Registeration  >>>>>>>>>>>>|" <<endl;
   cout << " |==============================================|\n" <<endl;


 string user,pass;

 cout<<"Enter new username: ";
 cin>>user;
 cout<<"Enter new password:";
 cin>>pass;

 ofstream file("UAMS(Pass).txt" , ios::app);
 if(!file.is_open()){
  cout<< " Error opening UAMS(Pass).txt for writing " <<endl;
  return;
 }
 file << user <<  "," << pass << endl;
 file.close();

 cout<< "\033[32mUser Registered Successfully!\033[0m" <<endl;
 cout<<"Press any key to continue login..." <<endl;
 getch();

}
bool login()
{
  system("cls");
  cout<<"#*****************************************************#          "<<endl;
  cout<<"#==================== UAMS LOGIN =====================#          "<<endl; 
  cout<<"#*****************************************************#\n          "<<endl; 
  
  
    string username, password,user, pass;
    

     cout<< "Enter Username: ";
     cin>> username;
     cout<< "Enter Password: ";
     cin>>password;

     ifstream file("UAMS(Pass).txt");
     if(!file.is_open()){
      return false;
     } 
       string record;
     while (getline(file, record))
     {
      user = getfield(record, 1);
      pass = getfield(record, 2);
     
     
      if(user == username && pass == password){
         file.close();
         return true;
     } 
    }
    file.close();
    return false;
  } 
   int isPresent(string name, string password, string names[], string passwords[], int idx)
   {
     int index = -1;
     for(int x = 0; x < idx; idx++)
     {
      if(name == names[x] && password == passwords[x])
      index = x;
     }
     return index;
   }
     

    void Header() {
    system("cls");
    cout<<"#========================================#"<<endl;
    cout<<"# University Admission Management System #"<<endl;
    cout<<"#========================================#\n"<<endl;
}
  


    void Menu() {

    cout<<"      #=======================#  "<<endl;
    cout<<"      ##<<<<<<   MENU  >>>>>>##  "<<endl;
    cout<<"      #=======================# \n"<<endl;
   
    cout<<"1 - Add Students."<<endl;
    cout<<"2 - Update record."<<endl;
    cout<<"3 - Calculate Merit."<<endl;
    cout<<"4 - Delete Student."<<endl;
    cout<<"5 - View."<<endl;
    cout<<"6 - Exit. "<<endl;
}



 int addstudent(string name[],string Cnic[],float Matric[],float Fsc[],float ECAT[] , float Merit[], int num,int indx) {    
      cout<<"*============== ADDING STUDENT ============*\n"<<endl; 
  

  ofstream fout("Student Credentials.txt" , ios::app);

  if(!fout) {
      cout<<" Error opening file!" <<endl;
      return indx;
  }
     cin.ignore(); 
    
   for(int idx = indx; idx < indx + num; idx++){
    cout<<" \nEnter the Name: ";
    getline(cin,name[idx]);
    cout<<"Enter the CNIC:";
    cin>>Cnic[idx];
    cout<<"Enter the Matric Marks (Out of 1100): ";
    cin>>Matric[idx];
    cout<<"Enter the FSC Marks (out of 1200): ";
    cin>>Fsc[idx];
    cout<<"Enter the ECAT Marks:";
    cin>>ECAT[idx];
    cin.ignore();


    fout << name[idx] << "," << Cnic[idx] << "," << Matric[idx] << "," << Fsc[idx] << "," << ECAT[idx] << endl;
  
  }
       fout.close();

      return indx + num;
}

    
  int update(string name[],string Cnic[],float Matric[],float Fsc[],float ECAT[] , float Merit[], int indx) {    
    cout<<"*=============== UPDATING STUDENT ===============*\n                    "<<endl;
   if (indx == 0) {
    cout<< "NO records available to update .\n";
    return indx;
   }
   string searchCnic;  
   int i = -1;
   View(name, Cnic , Matric , Fsc , ECAT , Merit , indx);
   cout << "Enter Student CNIC to update: ";
   cin >> searchCnic;

   for(int j = 0; j < indx; j++){
    if(Cnic[j] == searchCnic){
      i = j;
      break;
    }
   }

   if(i >= 0 && i < indx) {
    cin.ignore();
    cout<< "Enter New Student Name: ";
    getline(cin , name[i]);
    cout<< "Enter New CNIC: ";
    cin>>Cnic[i];
     cout<< "Enter New Matric marks:";
     cin >> Matric[i];
     cout << "Enter New FSC Marks: ";
     cin >> Fsc[i];
     cout << "Enter New ECAT Marks: ";
     cin >> ECAT[i];
     cin.ignore();
   
     cout<< "Student Updated Successfully.\n";
     return indx;
   }
     else {
      cout << "Student Not Found. \n";
      return indx;
     }
    }

     void merit(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[], int indx){
     if (indx == 0){
    cout << "No students to calculate merit for.\n";
     return;
  }
      
  
    for(int i = 0; i < indx; i++){
     float a =(Matric[i]/1100)*100;
     float b =(Fsc[i]/1200)*100;
     float c =(ECAT[i]/400)*100;
     Merit[i] = (a * 0.10) + (b * 0.40) + (c * 0.50);

}
   
cout<< "Calculated Merit: \n";
for (int i = 0; i < indx; i++){
  cout<< name[i] << " -> Merit : " << Merit[i] << endl;
   }
 }
 void Delete(string name[],string Cnic[],float Matric[],float Fsc[],float ECAT[] , float Merit[], int &indx) {    
    cout<<"   |*Delete Student*|\n   "            <<endl;
    
   if (indx == 0) {
    cout<< "NO records available to Delete .\n";
    return;
   }
     
   int i;
   View(name, Cnic , Matric , Fsc , ECAT , Merit , indx);
   cout << "Enter student number to Delete: ";
   cin >> i;
   i--;

   if(i >= 0 && i < indx) {
    cin.ignore();
    for( int a = i; a < indx - 1; a++){
      name[a] = name[a + 1];
      Cnic[a] = Cnic[a + 1];
      Matric[a] = Matric[a + 1];
      Fsc[a] = Fsc[a + 1];
      ECAT[a] = ECAT[a + 1];
      Merit[a] = Merit[a + 1];
    }
     indx--;
     
     cout<< "\033[32mStudent deleted Successfully.\033[0m\n";
   }
     else {
      cout << "\033[31mInvalid Student number.\033[0m \n";
     }
    }
 void View(string name[], string Cnic[], float Matric[], float Fsc[], float ECAT[], float Merit[], int &indx){
  
    

  if (indx == 0) {
    cout<< "No students record to view.\n";
    return;
  }

   cout<< "           \033[33m*<<<<========= STUDENTS RECORD ==========>>>*\n\033[0m                "<<endl;
    cout << left << setw(5) << "No." << left << setw(25) << "Name" << left << setw(25) << "CNIC" << left << setw(15) <<"Matric" << left << setw(15) << "FSC" << left << setw(15) << "ECAT" << left << setw(15) << "Merit" <<endl;

   for(int i = 0; i < indx; i++){

    cout << left << setw(5) << i + 1 << left << setw(25) << name[i] << left << setw(25) << Cnic[i] << left << setw(15) << Matric[i] << left << setw(15) << Fsc[i] << left << setw(15) << ECAT[i] << left << setw(15) << Merit[i] <<endl;

   }
 }
 


   
