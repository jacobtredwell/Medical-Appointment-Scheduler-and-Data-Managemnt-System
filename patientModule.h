#pragma once
#pragma once
#include <string>
#include<iostream>
#include<fstream>
#include <stdlib.h>
using namespace std;

class patientModule
{
public:
	string c, name, PEC, ICD, symptoms, sex, birthdate, insuranceType, income, app; int opt = 0; char opt2 = 'n';
	ofstream record; ifstream read;
public:
	patientModule();
	virtual void records();
	void ICDcode();

};
patientModule::patientModule() {}

void patientModule::records()
{
	for (int i = 2; i > 1; i++) {
		cout << "Enter patient module Full Name : "; getline(cin, name); cout << endl;
		record.open(name + ".txt", ios::_Noreplace); //if ((dir = opendir ("c:\\src\\")) != NULL)
		if (record.fail()) {
			cout << "Unable to record patient, name already exits. ";  cout << "Must enter different patient name or identifier " << endl;; system("pause"); system("cls"); break;
		}



		else {
			i = 0;
			cout << "Enter patient Birthdate (mm/dd/yyyy): "; getline(cin, birthdate); cout << endl;
			cout << "Enter patient Sex: ";  getline(cin, sex); cout << endl;
			cout << "Enter patient pre-existing conditions in ICD code "<<endl<<"(input 'r' for a reference list):  "; getline(cin, PEC); cout << endl; if (PEC == "r") {
				ICDcode(); cout << " Pre existing conditions: "; getline(cin, PEC);
			}


			cout << "Enter patient symptoms in IDC code"<<endl<<" (input 'r' for a reference list): "; getline(cin, symptoms); cout << endl; if (symptoms == "r") {
				ICDcode(); cout << " Symptoms: "; getline(cin, symptoms);
			}
			//if (ICD == "r") { refrence(); cin >> symptoms; }
			cout << "Enter patient Income: $"; cin >> income; cout << endl;
			cout << "Enter patient Insurance type: "; cin >> insuranceType; cout << endl<<endl<<endl;
			cout << "New patient Added! " << endl; system("pause");
		}
	}


	//record.open(name + ".txt", ios::_Noreplace);
	//if (record.fail()) { cout << "Unable to record patient, name already exits "; }

	record << name << endl << birthdate << endl << sex << endl << PEC << endl << symptoms << endl << income << endl << insuranceType<<endl;
	record.close();


}

class updateModule : public patientModule
{


public:


	updateModule();
	void update();

	void records();
};




updateModule::updateModule() {}
void updateModule::update()
{
	for (int y = 3; y > 2; y++) {
		cout << "Enter patient Name you would like to update: "; getline(cin, name); cout << endl;      //Has to input with underscore instead of spaces



		read.open(name + ".txt", ios::_Nocreate);
		if (read.fail())
		{
			cout << "Error Opening File in Input" << endl;
			system("pause");
			exit(1);
		}

		getline(read, name);
		getline(read, birthdate);
		getline(read, sex);
		getline(read, PEC);
		getline(read, symptoms);
		getline(read, income);
		getline(read, insuranceType);

		read.close();
		cout << "Options " << endl;
		cout << " 1       Patient Name: " << name; cout << endl;
		cout << " 2       Patient Birthdate: " << birthdate; cout << endl;
		cout << " 3       Patient Sex: " << sex; cout << endl;
		cout << " 4       Patient pre-existing conditions in ICD code (input 'r' for a reference list):  " << PEC; cout << endl;

		//if (ICD == "r") { refrence(); cin >> PEC; }

		//cout << "Enter patient symptoms in IDC code (input 'r' for a reference list)"; cin >> symptoms; cout << endl;
		//if (ICD == "r") { refrence(); cin >> symptoms; }

		cout << " 5       Patient Income: $ " << income; cout << endl;
		cout << " 6       Patient Insurance type: " << insuranceType; cout << endl<<endl;
		cout << " The patient's last recorded symptoms : " << symptoms; cout << endl << "Press 7 to replace with latest Symptoms" << endl<<endl<<endl;
		cout << "Which option would you like to update: (0 to exit) "; cin >> opt;
		if (opt != 0) { opt2 = 'y'; }
		else if (opt == 0) { break; }
		while (opt2 == 'y') {

			if (opt == 1) {
				cout << "Patient name to update info for: "; cin >> name; cout << endl;
				//cout << "enter y to update another option, else to stop"; cin >> opt2;
			}
			else if (opt == 2) {
				cout << "Enter patient Birthdate: "; cin >> birthdate; cout << endl;
				//cout << "enter y to update another option, else to stop"; cin >> opt2;
			}
			else if (opt == 3) {
				cout << "Enter patient Sex: "; cin >> sex; cout << endl;
				//cout << "enter y to update another option, else to stop"; cin >> opt2;
			}
			else if (opt == 4) {
				cout << "Enter patient pre-existing conditions in ICD code (input 'r' for a reference list):  "; getline(cin, PEC); cout << endl;
				//cout << "enter y to update another option, else to stop"; cin >> opt2;
			}
			else if (opt == 5) {
				cout << "Enter patient Income: $"; cin >> income; cout << endl;
				//cout << "enter y to update another option, else to stop"; cin >> opt2;
			}
			else if (opt == 6) {
				cout << "Enter patient Insurance type: "; cin >> insuranceType; cout << endl;
				//cout << "enter y to update another option, else to stop"; cin >> opt2;

			}
			else if (opt == 7) {
				cout << "New Symptoms: "; getline(cin, symptoms); getline(cin, symptoms); cout << endl;
			}
			else
			{
				cout << "No option inputed" << endl;
			}
			cout << "enter letter y to update another option, anything else to stop: "; cin >> opt2;
			if (opt2 == 'y') { cout << "Which option would you like to update: "; cin >> opt; }
		}

		record.open(name + ".txt");
		record << name << endl << birthdate << endl << sex << endl << PEC << endl << symptoms << endl << income << endl << insuranceType;
		record.close();



		y = 0;
	}

}

void patientModule::ICDcode() {
	string ICDL = "ICDList";
	ICDL = "notepad \"" + ICDL + "\"";
	system(ICDL.c_str());
}
void updateModule::records()
{
	for (int y = 3; y > 2; y++) {
		cout << "Enter patient Name you would like to issue reciept : "; getline(cin, name); getline(cin, name); cout << endl;      //Has to input with underscore instead of spaces



		read.open(name + ".txt", ios::_Nocreate);
		if (read.fail())
		{
			cout << "Error reading from file create reciept" << endl;
			system("pause");
			exit(1);
		}

		getline(read, name);
		getline(read, birthdate);
		getline(read, sex);
		getline(read, PEC);
		getline(read, symptoms);
		getline(read, income);
		getline(read, insuranceType);
		getline(read, app);

		read.close();


		record.open(name + "_Reciept.txt");
		record << "                                            =============================" << endl
			<< " ||                             Patient name: " << name << "                                                                   " << endl
			<< " ||                             Patient birthdate: " << birthdate << "                                                           " << endl
			<< " ||                             Patient sex: " << sex << "                                                                    " << endl
			//<<""<< PEC <<endl
			<< " ||                             Reason for visit: " << symptoms << "                                                                      " << endl<<endl<<endl<<app;
		//<<""<< income << endl 
		//<<""<< insuranceType;
		record.close();
		cout << "Reciept issued.." << endl; system("pause");



		y = 0;
	}
}
