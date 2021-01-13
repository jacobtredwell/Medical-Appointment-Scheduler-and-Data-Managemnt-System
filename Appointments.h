#include <iostream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;



class Appointment
{
public:
	Appointment();
	~Appointment();

	void welcomeMenu();
	void showMenuMV();
	void showDays();
	void checkTimeAvail();
	void makeViewAppointment();
	void printAppoinments();
	
	ofstream record;
	
	string name;
	char menuchoice;
	int DayofWeek;
	int time;
	char answer;
	int appCounter;

	
	


private:

	string AppBook[7][5];
	
	
};

Appointment::Appointment()

{


	string AppBook[7][5];

	char menuchoice = 'm';
	int day = 0;
		
}

Appointment::~Appointment()
{
}

void Appointment::welcomeMenu() 
{
	//This WELCOMES user to the APPOINTMENT module.

	cout << "\t**************************************************************************\n\t\t\tDoctor's Office Appointment Book\n\t\**************************************************************************\n\n";



}

void Appointment::showMenuMV()
{//Output the welcome menu to the user

	cout << "\n\n\tSelect from one of the following two options (Type 'm' or 'v'):\n\t\t------------------------------\n\n"
		<< "\t\tm: Make an Appointment\n"
		<< "\t\tv: View Appointment Book\n\t\t\t";
	cin >> menuchoice;
}

void Appointment::showDays() 
{//asks user to select day between Monday and Friday



	cout << "\n\t\t\tSelect one of the following days (Enter the number associated with the day:\n"
		"\t\t--------------------------------------\n\n"
		<< "\t\t0: Monday\n"
		<< "\t\t1: Tuesday\n"
		<< "\t\t2: Wedneday\n"
		<< "\t\t3: Thursday\n"
		<< "\t\t4: Friday\n\t\t\t";
	cin >> DayofWeek;

;
}



void Appointment::printAppoinments()
{
	string dayHolder;

	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
				dayHolder = "Monday";
			else if (j == 1)
				dayHolder = "Tuesday";
			else if (j == 2)
				dayHolder = "Wednesday";
			else if (j == 3)
				dayHolder = "Thursday";
			else
				dayHolder = "Friday";

			if (AppBook[i][j] != "")
			{
				if (i == 0)
					cout << AppBook[i][j] << " has an appointment at 9:00 am on " << dayHolder << "." << endl;
				else if (i == 1)
					cout << AppBook[i][j] << " has an appointment at 10:00 am on " << dayHolder << "." << endl;
				else if (i == 2)
					cout << AppBook[i][j] << " has an appointment at 11:00 am on " << dayHolder << "." << endl;
				else if (i == 3)
					cout << AppBook[i][j] << " has an appointment at 12:00 pm on " << dayHolder << "." << endl;
				else if (i == 4)
					cout << AppBook[i][j] << " has an appointment at 1:00 pm on " << dayHolder << "." << endl;
				else if (i == 5)
					cout << AppBook[i][j] << " has an appointment at 2:00 pm on " << dayHolder << "." << endl;
				else
					cout << AppBook[i][j] << " has an appointment at 3:00 pm on " << dayHolder << "." << endl;
			}
			else {

				if (i == 0)
					cout << "OPEN....Appointment at 9:00 am on " << dayHolder << " is AVAILABLE" << endl;
				else if (i == 1)
					cout << "OPEN....Appointment at 10:00 am on " << dayHolder << " is AVAILABLE" << endl;
				else if (i == 2)
					cout << "OPEN....Appointment at 11:00 am on " << dayHolder << " is AVAILABLE" << endl;
				else if (i == 3)
					cout << "OPEN....Appointment at 12:00 pm on " << dayHolder << " is AVAILABLE" << endl;
				else if (i == 4)
					cout << "OPEN....Appointment at 1:00 pm on " << dayHolder << " is AVAILABLE" << endl;
				else if (i == 5)
					cout << "OPEN....Appointment at 2:00 pm on " << dayHolder << " is AVAILABLE" << endl;
				else
					cout << "OPEN....Appointment at 3:00 pm on " << dayHolder << " is AVAILABLE" << endl;

			}


		}




	}



}

void Appointment::checkTimeAvail()
{
	int time;
	bool checkTime = false;

	do {
		cout << "\n\n\t\tEnter time for appointment:\n\t\t--------------------------\n\n"
			<< "\t\t0: 9:00 AM - 10:00 AM\n"
<< "\t\t1: 10:00 AM - 11:00 AM\n"
<< "\t\t2: 11:00 AM - 12:00 PM\n"
<< "\t\t3: 12:00 PM - 1:00 PM\n"
<< "\t\t4: 1:00 PM - 2:00 PM\n"
<< "\t\t5: 2:00 PM - 3:00 PM\n"
<< "\t\t6: 3:00 PM - 4:00 PM\n\t\t\t";

cin >> time;

if (AppBook[time][DayofWeek] == "") {
	cout << "\n\n\t\tEnter Patient Name: \n\t\t-------------------------------\n\n\t\t";
	getline(cin ,name);
	getline(cin, name);
	cout << endl;

	checkTime = true;

	AppBook[time][DayofWeek] = name;

}

else {
	cout << "\t\t--------------------------------------\n\n"
		<< "\n\n\t\tThat appointment time is unavailable!\n"
		<< "\t\t---------------------------------------\n\n";
}
	} while (checkTime == false);



	string dayHolder;

	if (DayofWeek == 0)
		dayHolder = "Monday";
	else if (DayofWeek == 1)
		dayHolder = "Tuesday";
	else if (DayofWeek == 2)
		dayHolder = "Wednesday";
	else if (DayofWeek == 3)
		dayHolder = "Thursday";
	else
		dayHolder = "Friday";


	if (time == 0) 
	{
		cout << "\n\n" << name << "  has an appointment at 9:00 am on " << dayHolder << "." << endl;
		record.open(name + ".txt", ios::_Nocreate | ios::app);
		record << name << " has an appointment at 9:00 am on " << dayHolder << "." << endl;
		record.close();
	}

	else if (time == 1)
	{
		cout << "\n\n" << name << " has an appointment at 10:00 am on " << dayHolder << "." << endl;
		record.open(name + ".txt",  ios::_Nocreate| ios_base::app);
		record << name << " -- has an appointment at 10:00 am on " << dayHolder << "." << endl;
		record.close();
	}
	else if (time == 2)
	{
		cout << "\n\n" << name << " has an appointment at 11:00 am on " << dayHolder << "." << endl;
		record.open(name + ".txt",  ios::_Nocreate |ios_base::app);
		record << name << " -- has an appointment at 11:00 am on " << dayHolder << "." << endl;
		record.close();
	}
	else if (time == 3)
	{
		cout << "\n\n" << name << " has an appointment at 12:00 pm on " << dayHolder << "." << endl;
		record.open(name + ".txt", ios::_Nocreate |ios_base::app);
		record << name << " -- has an appointment at 12:00 pm on " << dayHolder << "." << endl;
		record.close();
	}
	else if (time == 4)
	{
		cout << "\n\n" << name << " has an appointment at 1:00 pm on " << dayHolder << "." << endl;
		record.open(name + ".txt",  ios::_Nocreate |ios_base::app);
		record << name << " -- has an appointment at 1:00 pm on " << dayHolder << "." << endl;
		record.close();
	}
	else if (time == 5)
	{
		cout << "\n\n" << name << " has an appointment at 2:00 pm on " << dayHolder << "." << endl;
		record.open(name + ".txt",  ios::_Nocreate |ios_base::app);
		record << name << " -- has an appointment at 2:00 pm on " << dayHolder << "." << endl;
		record.close();
	}
	else
	{
		cout << "\n\n" << name << " has an appointment at 3:00 pm on " << dayHolder << "." << endl;
		record.open(name + ".txt",  ios::_Nocreate | ios_base::app);
		record << name << " -- has an appointment at 3:00 pm on " << dayHolder << "." << endl;
		record.close();
	}



}




void Appointment::makeViewAppointment()
{
	showMenuMV();
	

	if (menuchoice == 'm')
	{

		showDays();

		switch (DayofWeek) {
		case 0:
			checkTimeAvail();
			break;
		case 1:
			checkTimeAvail();
			break;
		case 2:
			checkTimeAvail();
			break;
		case 3:
			checkTimeAvail();
			break;
		case 4:
			checkTimeAvail();
			break;
		default:
			showMenuMV();
			break;
		}




	}
	else
	{
		int appCounter = 0;



		for (int i = 0; i < 7; i++) {

			for (int j = 0; j < 5; j++) {

				if (*(AppBook[i] + j) == "")
					appCounter += 1;
			}

		}

		

		cout << "\nThere are " << appCounter << " appointment times AVAILABLE!" << endl;
		cout << "\nNumber of appointments ALREADY BOOKED this week: " << (35 - appCounter) << "\n\n" << endl;

		printAppoinments();

	}


	

	cout << "\n\n*****\n Do you want to do something else ? ('y' or 'n')\n*****" << endl;

	cin >> answer;

	if (answer == 'y')
		makeViewAppointment();

	else
		cout << "Finished";

}



