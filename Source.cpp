#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include"Appointments.h"
#include"patientModule.h"
//#include "Menus.h"

using namespace std;

void home_page();
void main_menu();
void login_menu();
void registration_menu();
void patient_menu();
void appointment_menu();

int main()
{
    //cout << setfill('-');
   // cout << setw(50);
    //cout << 77 << endl;


    home_page();
};


void home_page() {
    
    char user_option;
    bool valid_option = false;
    while (valid_option == false) {
        cout << setw(0); cout << "***********************************" << endl;
        cout << setw(0); cout << "Medical Patient Information System" << endl;
        cout << setw(0); cout << "***********************************" << endl;
        cout << setw(29); cout << "Welcome to the Home Page" << endl<<endl<<endl;
        cout << setw(0); cout << "a. Log In" << endl;
        cout << setw(8); cout << "b. Create Account" << endl;
        cout << setw(0); cout << "c. Exit" << endl<<endl<<endl;
        cout << setw(0); cout << "Please select an option: ";
        cin >> user_option; cout << endl<<endl;

        if (user_option == 'a') {
            login_menu();
            valid_option = true;
        }
        else if (user_option == 'b') {
            registration_menu();
            valid_option = true;
        }
        else if (user_option == 'c')
        {
            valid_option = true;
            cout << "Logging Out" << endl;
            cout << "Goodbye";
            exit;
        }
        else
        {
            cout << "Invalid option, please try again" << endl;
        }
    }
}

void registration_menu() {

    fstream in_file;

    in_file.open("users.txt");
    if (!in_file)
    {
        cerr << "Problem opening file" << endl;
        //return 1;
    }
    cout << "Preparing for Registration..." << endl;

    int arraySize = 0;
    while (!in_file.eof())
    {
        string name;
        in_file >> name;
        arraySize++;
    }
    //cout << arraySize;
    in_file.close();

    in_file.open("users.txt");
    vector <string> accounts(arraySize);

    int i = 0;
    while (!in_file.eof())
    {
        in_file >> accounts[i];
        i++;
    }

    in_file.close();


    string username, password;
    bool good_username = false;
    bool data_validation = false;

    cout << "Create Username: ";
    cin.ignore();
    getline(cin, username);

    while (good_username == false || data_validation == false)
    {
        while (data_validation == false) {
            size_t found = username.find(" ");
            if (found != string::npos) {
                cout << "There cannot be a space in your username." << found << endl;
                cout << "Re-enter Username: ";
                getline(cin, username);
            }
            else if (username.size() > 10) {
                cout << "Username is " << username.size() << " characters, username should be less than 10" << endl;
                cout << "Re-enter Username: ";
                getline(cin, username);
            }
            else {
                data_validation = true;
            }
        }
        for (i = 0; i < arraySize; i++) {

            if (accounts[i] == username) {
                cout << "Username is taken, please try another: ";

                getline(cin, username);
                i = 0;
                data_validation = false;
            }
        }

        good_username = true;
    }

    ofstream out_file{ "users.txt", ios::app };
    if (!out_file)
    {
        cerr << "error creating file" << endl;
        //return 1;
    }

    cout << "Create Password: ";
    getline(cin, password);

    bool password_validation = false;
    while (password_validation == false) {
        size_t found = password.find(" ");
        if (found != string::npos) {
            cout << "There cannot be a space in your password." << found << endl;
            cout << "Re-enter Password: ";
            getline(cin, password);
        }
        else {
            password_validation = true;
        }
    }

    out_file << username << " ";
    out_file << password << endl;
    cout << "New user " << username << " has been created successfully" << endl;
    main_menu();
}

void login_menu()
{
    string username, password;
    bool valid_login = false;

    fstream in_file;

    in_file.open("users.txt");
    if (!in_file)
    {
        cerr << "Problem opening file" << endl;
        //return 1;
    }
    cout << "Preparing for Log In..." << endl;

    int arraySize = 0;
    while (!in_file.eof())
    {
        string name;
        in_file >> name;
        arraySize++;
    }
    //cout << arraySize;
    in_file.close();

    in_file.open("users.txt");
    vector <string> accounts(arraySize);

    int i = 0;
    while (!in_file.eof())
    {
        in_file >> accounts[i];
        i++;
    }

    in_file.close();

    while (valid_login == false)
    {
        cout << "Please Enter Your Username: ";
        cin.ignore();
        getline(cin, username);
        cout << "Please Enter Your Password: ";
        getline(cin, password);

        for (int i = 0; i < arraySize; i++)
        {
            if (accounts[i] == username && accounts[i + 1] == password) {
                cout << username << " has been successfully logged in" << endl;

                valid_login = true;
            }
            else {
                i++;
            }
        }
        if (valid_login == false)
        {
            cout << "username and password incorrect, please try again" << endl;
        }
    }
    main_menu();
};
void main_menu()
{
    system("cls"); 
    char menu_option;
    bool valid_menu = false;
    cout << "\n";
    cout << setw(29); cout << "Welcome to the main menu\n\n";
    while (valid_menu == false)
    {
        cout << "a. Patient data" << endl;
        cout << "b. Appointment data" << endl;
        cout << "c. Issue Reciept " << endl;
        cout << "d. Log Out" << endl<<endl<<endl;
        cout << "\n";
        cout << "Please select desired submenu: ";
        cin >> menu_option;
        if (menu_option == 'a')
        {
            patient_menu();
            valid_menu = true;
        }
        else if (menu_option == 'b')
        {
            appointment_menu();
            valid_menu = true;
        }
        else if (menu_option == 'c')
        {
            system("cls"); updateModule uM; uM.records(); main_menu();
            valid_menu = true;
        }
        else if (menu_option == 'd')
        {
            valid_menu = true;
            cout << "User Logged Out" << endl;
            cout << "\n\n\n";
            home_page();
        }
        else
        {
            cout << menu_option << " is not a valid option. Please try again" << endl;
        }
    }
};
void patient_menu()
{
    system("cls"); 
    cout << setw(29); cout << "Welcome to the Patient Menu" << endl<<endl;
    string c;
    cout << "a. Record New Patient " << endl;
    cout << "b. Update Patient info  " << endl;
    cout << "c. Issue Reciept " << endl;
    cout << "d. Go Back" << endl<<endl;
    cout << "Enter desired option: ";
    getline(cin, c);
    getline(cin, c);
    if (c == "a") { system("cls"); patientModule pM; pM.records(); main_menu(); }
    else if (c == "b") { system("cls"); updateModule uM; uM.update(); main_menu(); }
    else if (c == "c") { system("cls"); updateModule uM; uM.records(); main_menu(); }
    else if (c == "d") { system("cls"); main_menu(); }
};
void appointment_menu()
{
   // cout << "Welcome to the Appointment Menu";

    Appointment A;

    A.welcomeMenu();

    A.makeViewAppointment();
    main_menu();
};