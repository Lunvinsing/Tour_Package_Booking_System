#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

//For Admin
void AMenu();
void Create_new_packages();
void View_all_packages();
void Update_packages();
void Delete_packages();

//For User
void UMenu();
void View_all_packages1();
void Create_a_new_booking();
void View_packages();
void Delete_packages1();


int main(){
    int choice;

    string lightGreen = "\033[92m"; 
   do{
    cout<< R"(⠀⠀⠀⣖⠲⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠉⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠸⡆⠹⡀⣠⢤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⡧⢤⡄⠀⠀⠀⠀⠀
⠀⠀⠀⠀⡧⢄⣹⣅⣜⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⠀⢹⠚⠃⠀⠀⠀⠀⠀
⠀⣀⠴⢒⣉⡹⣶⣤⣀⡉⠉⠒⠒⠒⠤⠤⣀⣀⣀⠇⠀⠀⢸⠠⣄⠀⠀⠀⠀⠀
⠀⠈⠉⠁⠀⠀⠀⠉⠒⠯⣟⣲⠦⣤⣀⡀⠀⠀⠈⠉⠉⠉⠛⠒⠻⢥⣀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣲⡬⠭⠿⢷⣦⣤⢄⣀⠀⠀⠚⠛⠛⠓⢦⡀
⠀⠀⠀⠀⠀⠀⠀⢀⣀⠤⠴⠚⠉⠁⠀⠀⠀⠀⣀⣉⡽⣕⣯⡉⠉⠉⠑⢒⣒⡾
⠀⠀⣀⡠⠴⠒⠉⠉⠀⢀⣀⣀⠤⡤⢶⣶⣋⠉⠉⠀⠀⠀⠈⠉⠉⠉⠉⠉⠁⠀
⣖⣉⣁⣠⠤⠶⡶⡶⢍⡉⠀⠀⠀⠙⠒⠯⠜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠁⠀⠀⠀⠀⠑⢦⣯⠇)"<<endl;
    cout<< lightGreen << "Welcome to Tour Package Booking System\n";

    cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
    cout<< "[1] Administrator\n";
    cout<< "[2] User\n";
    cout<< "[3] Exit\n";
     cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
    cin>>choice;

    switch (choice){
        case 1:
           AMenu();
           break;
        case 2:
           UMenu();
        break;
        case 3:
           cout<< "Exiting the Program.";
           break;
        defualt:
           cout<< "Invalid choice.\n";
        }
    }while(choice != 3);
}

void AMenu(){
    int choice;
    string password;
    cout<< "Enter the password to continue:";
    cin>>password;

    if(password == "123"){
    ofstream("createanew.csv");
   do{ 
    cout<< R"(─────────────────୨ৎ──────────────────)"<<endl;
    
    cout<< "[1] Create new packages\n";
    
    cout<< "[2] View all packages\n";
    cout<< "[3] Update packages\n";
    cout<< "[4] Delete packages\n";
    cout<< "[5] Exit\n";
  cout<< R"(─────────────────୨ৎ──────────────────)"<<endl;
    cin>>choice;
  cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
    switch (choice){
        case 1:
            Create_new_packages();
            break;
        case 2:
             View_all_packages();
             break;
        case 3:
            Update_packages();
            break;
        case 4:
            Delete_packages();
            break;
        case 5:
            cout<< "Back to the first Menu.\n";
            cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
            break;
        default:
           cout<< "Invalid choice.\n";
    }
}while(choice != 5);}else{
    cout<< "Access denied";
}
}

void UMenu(){
    int choice;
   do{
    cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
    cout<< "[1] View all packages\n";
    cout<< "[2] Create a new booking\n";
    cout<< "[3] View packages that you booked\n";
    cout<< "[4] Delete packages that you booked\n";
    cout<< "[5] Exit\n";
    cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
   cin>> choice;
    cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
    switch (choice){
       case 1:
           View_all_packages1();
           break;
        case 2:
            Create_a_new_booking();
            break;
        case 3:
            View_packages();
            break;
        case 4:
            Delete_packages1();
            break;
        case 5:
            cout<< "Back to the first Menu.\n";
           cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
            break;
        default:
        cout<< "Invalid choice.\n";
    }
    }while(choice != 5);
}

void Create_new_packages(){
    ofstream New("packages.csv");

    int idnum,id,duration;
    string package,destination;
    double price;
    cout << "Enter the amount of package:";
    cin >>idnum;

    cout << "Enter the ID of packages:"<<"ID, Package name, Price($), Duration(Day), Destination"<<endl;
    for(int i = 0; i < idnum; i++){
        cin>>id
           >>package
           >>price
           >>duration
           >>destination;

      New<<id<<","
         <<package<<","
         <<price<<","
         <<duration<<","
         <<destination<<"\n";
}
    New.close();
}

void View_all_packages(){
    ifstream New("packages.csv");
    vector<string>row;
    string line,word;

    cout<< "All packages\n";

    while(getline(New,line)){
        row.clear();

        stringstream s(line);

        while(getline(s, word,',')){
            row.push_back(word);
        }
cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
        cout<< "ID           :" <<row[0]<<"\n";
        cout<< "Package name :" <<row[1]<<"\n";
        cout<< "Price($)     :" <<row[2]<<"/Person"<<"\n";
        cout<< "Duration(Day):" <<row[3]<<"\n";
        cout<< "Destination  :" <<row[4]<<"\n";
cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
    }
    New.close();
}

void Update_packages(){
    ifstream fin("packages.csv");
    ofstream fout("packagesnew.csv");

    int idnum, id2,count = 0, newprice, newduration;
    string line,word;
    string newpackage,newdestination;

    vector<string>row;

    cout<< "Enter the ID of package to be updated:";
    cin>>idnum;
cin.ignore();
    cout<< "Enter new data for Package name:";
    getline(cin , newpackage);
    

    cout<< "Enter new data for Destination:";
    getline(cin, newdestination);

    cout<< "Enter new data for Price:";
    cin>>newprice;

    cout<< "Enter new data for Duration:";
    cin>>newduration;

    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')){
            row.push_back(word);
        }
        id2 = stoi(row[0]);
        int row_size = row.size();
        
        if (id2 == idnum){
            count = 1;
            row[1] = newpackage;
            row[4] = newdestination; 

            row[2] = to_string(newprice);
            row[3] = to_string(newduration);
        }
        for(int i = 0; i <row_size - 1; i++){
            fout<<row[i] <<", ";
        }
        fout<<row[row_size - 1]<< "\n";

    }
        fin.close();
        fout.close();
        remove("packages.csv");
        rename("packagesnew.csv", "packages.csv");

    if (count == 0){
        cout<< "Record not found\n";
    }else{
        cout<< "Package updated successfully!\n";
    }
    
}

void Delete_packages(){
    ifstream fin("packages.csv");
    ofstream fout("packagesnew.csv");

    int idnum, id2, count = 0;
    string line;
    vector<string> row;
    cout<< "Enter the ID of package to be deleted:";
    cin>>idnum;

    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        string word;
        while(getline(s, word, ',')){
            row.push_back(word);

        }
        id2 = stoi(row[0]);
         if (id2 != idnum) {
            for (size_t i = 0; i < row.size() - 1; i++) {
                fout << row[i] << ", ";
            }
            fout << row.back() << "\n";
        } else {
            count = 1;
        }

    }
     if (count == 1) {
        cout << "Record deleted\n";
    } else {
        cout << "Record not found\n";
    }
    fin.close();
    fout.close();

    remove("packages.csv");
    rename("packagesnew.csv", "packages.csv");
}

void Create_a_new_booking(){
    ifstream fin("packages.csv");
    ofstream fout("bookings.csv");
    int idnum, id2, count = 0;
    char sub;
    vector<string> row;
    string line, word;

    cout << "Enter ID of package to book: ";
    cin >> idnum;

    while(getline(fin, line)){
        row.clear();
        stringstream s(line);

        while(getline(s, word, ',')){
            row.push_back(word);
        }

        id2 = stoi(row[0]);

        if(id2 == idnum){
            count = 1;
            cout<< "\nPackage Found:\n";
            cout<< "ID          :" << row[0] << endl;
            cout<< "Package name:" << row[1] << endl;
            cout<< "Price($)    :" << row[2] <<"/Person"<< endl;
            cout<< "Duration    :" << row[3] << " days" << endl;
            cout<< "Destination :" << row[4] << endl;

            cout << "\nEnter Y to confirm booking: ";
            cin >> sub;

            if(sub == 'Y' || sub == 'y'){
                cin.ignore();
                string username,phone,paymentM;
                double totalprice,PricePerPerson;
                int people;

                cout<< "Enter your name:";
                getline(cin, username);

                cout<< "Enter your phone number:";
                getline(cin, phone);

                cout<< "Enter number of people:";
                cin>>people;
                cin.ignore();

                PricePerPerson = stod(row[2]);
                totalprice = people * PricePerPerson;

                cout<< "Total amunt to pay:"<< totalprice <<"$"<<endl;


                cout<< "Enter payment method (Cash/Card/Online):";
                getline(cin, paymentM);



                fout << row[0] << "," 
                << row[1] << "," 
                << row[2] << "," 
                << row[3] << "," 
                << row[4] <<","
                <<username<<","
                <<phone<<","
                <<people<<","
                <<paymentM<<","
                <<totalprice<<"\n";
                cout << "Booking successful! Saved\n";
            } else {
                cout << "Booking cancelled.\n";
            }
            break;
        }
    }

    if(count == 0){
        cout << "Record not found\n";
    }

    fin.close();
    fout.close();
}


void View_all_packages1(){
    ifstream New("packages.csv");
    vector<string>row;
    string line,word;

    cout<< "All packages\n";

    while(getline(New,line)){
        row.clear();

        stringstream s(line);

        while(getline(s, word,',')){
            row.push_back(word);
        }
cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
        cout<< "ID           :" <<row[0]<<"\n";
        cout<< "Package name :" <<row[1]<<"\n";
        cout<< "Price($)     :" <<row[2]<<"/Person"<<"\n";
        cout<< "Duration(Day):" <<row[3]<<"\n";
       cout<< "Destination  :" <<row[4]<<"\n";
       cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
    
    }
    New.close();
}

void View_packages(){
    ifstream New("bookings.csv");
    vector<string>row;
    string line,word;

    cout<< "[Package that you booked]\n";

    while(getline(New,line)){
        row.clear();

        stringstream s(line);

        while(getline(s, word,',')){
            row.push_back(word);
        }

        cout<< "ID            :" <<row[0]<<"\n";
        cout<< "Package name  :"<<row[1]<<"\n";
        cout<< "Price($)      :"<<row[2]<<"/Person"<<"\n";
        cout<< "Duration(Day) :"<<row[3]<<"\n";
        cout<< "Destination   :"<<row[4]<<"\n";
        cout<< "Name          :"<<row[5] << "\n";
        cout<< "Phone         :"<<row[6] << "\n";
        cout<< "People        :"<<row[7] << "\n";
        cout<< "Payment Method:"<<row[8] <<"\n";
        cout<< "Total Price   :"<<row[9] <<"\n";
        cout<< R"(─────────────── ⋆⋅☆⋅⋆ ────────────────)"<<endl;
        break;  
    }
    New.close();
}

void Delete_packages1(){
    ifstream fin("bookings.csv");
    ofstream fout("bookingsnew.csv");

    int idnum, id2, count = 0;
    string line;
    vector<string> row;
    cout<< "Enter the ID of package to be deleted:";
    cin>>idnum;

    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        string word;
        while(getline(s, word, ',')){
            row.push_back(word);

        }
        id2 = stoi(row[0]);
         if (id2 != idnum) {
            for (size_t i = 0; i < row.size() - 1; i++) {
                fout << row[i] << ", ";
            }
            fout << row.back() << "\n";
        } else {
            count = 1;
        }

    }
     if (count == 1) {
        cout << "Record deleted\n";
    } else {
        cout << "Record not found\n";
    }
    fin.close();
    fout.close();

    remove("bookings.csv");
    rename("bookingsnew.csv", "bookings.csv");
}