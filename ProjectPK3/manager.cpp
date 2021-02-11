#include "class.h"
#include <sstream>
#include <algorithm>

using std::vector;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class responsible for task management

// Managment constructor
Management::Management()
{
	this->Head = nullptr;
	this->Tail = nullptr;
	this->elements.clear();
}

// Managment deconstructor
Management::~Management()
{
	deletebase();
	this->elements.clear();
}

// Load a employee base from a .txt file
bool Management::loadbase()
{
	deletebase();
	std::ifstream infile;
	string line;
	char path[200];

	cout << endl;
	cout << "                            ENTERING THE DATEBASE FROM INPUT .TXT FILE \n";
	cout << "                            ENTER THE PATH TO THE INPUT .TXT FILE \n";
	cin >> path;
	infile.open(path);

	if (infile.good()) // Check if the file has been opened correct
	{
		infile.seekg(0, std::ios::end); // Set indicator on the end of the file 
		if (infile.tellg()) { // Check the length of the file to check if the file is empty 
			infile.seekg(0, std::ios::beg);  // Set indicator on the beggining of the file 
			do
			{
				while (getline(infile, line, '\n')) {
					std::stringstream sfile(line);
					while (getline(sfile, line, ';')) { // Get a line and save in string 

						elements.push_back(line); // Seperate the elements
					};
					// Save elements to relevant variables
                    addtolist();
					elements.clear();
					}
				
				} while (!infile.eof()); // Perform until end of the file 

				infile.close(); // Close input file 
			
				return true;
			}
		else {
			cout << "                            THE FILE IS EMPTY \n";
			return false;
		}
		}
		else {
			cout << "                            THE FILE COULD NOT BE OPENED \n";
			return false;
		}
	}

// Save a employee base to a .txt file
bool Management::savebase()
{
	std::ofstream outfile;
	char path[200];
	cout << endl;
	cout << "                            SAVE THE DATEBASE IN OUTPUT .TXT FILE " << endl;
	cout << "                            ENTER THE PATH TO THE OUTPUT .TXT FILE " << endl;
	cin >> path;
	outfile.open(path, std::ios::trunc); 

	if (outfile.good()) // Check if the file has been opened correctly
	{
			List * helper = Head; 
			do {
				outfile << *helper->employee;
				helper = helper->next;
			} 
			while (helper!= nullptr);

			outfile.close(); // Close input file 
			return true;
	}
	else {
		    cout << "                            THE FILE COULD NOT BE OPENED \n";
		    return false;
	}
}

// Creating a new employee base
void Management::createbase()
{
	cout << endl;
	cout << "                            CREATING A NEW BASE DATA " << endl << endl;
	deletebase();
	addemployee();
}

// Add a employee to data base
void Management::addemployee()
{
	elements.clear();
	cout << "                            ADD A EMPLOYEE DETAILS " << endl;
	kindofwork();
	int number;
	if (choice(number) == true) {
		string choice = std::to_string(number);
		elements.push_back(choice);
		check(0);
	}
}

// Delete a employee from the data base
void Management::deleteemployee()
{
	system("cls");
	if (Head == nullptr)
	{
		cout << "                            NO EMPLOYEES IN A BASE DATA " << endl;
	}
	else {
		cout << "                            DELETING A EMPLOYEE FROM THE DATEBASE " << endl;
		List* found = findemployee(2);

		if ((found == Head) && (found == Tail)) { // Only one element in a list
			Head = nullptr;
			Tail = nullptr;
			delete found;
			cout << "                            THE PERSON HAS BEEN DELETED FROM DATEBASE " << endl;
		}
		else { // More than one element in a list

			if (found == Head)
			{
				Head = found->next;
				found->next->prev = nullptr;
				delete found;
				cout << "                            THE PERSON HAS BEEN DELETED FROM DATEBASE " << endl;
			}
			else if (found == Tail)
			{
				Tail = found->prev;
				found->prev->next = nullptr;
				delete found;
				cout << "                            THE PERSON HAS BEEN DELETED FROM DATEBASE " << endl;
			}
			else {
				found->prev->next = found->next;
				found->next->prev = found->prev;
				delete found;
				cout << "                            THE PERSON HAS BEEN DELETED FROM DATEBASE " << endl;
			}
		}
	}
}

// Edit a employee details 
void Management::editemployee()
{ 
	if (Head == nullptr)
	{
		cout << "                            NO EMPLOYEES IN A BASE DATA " << endl;
	}
	else {
		cout << "                            EDITING THE EMPLOYEE DETAILS " << endl;
		List* found = findemployee(2);
		if (found != nullptr)
		{
			found->employee->employee_show();
			cout << "                            WHAT DETAIL DO YOU WANT TO EDIT ? " << endl;

			found->employee->employee_edit();
			int number = 0;
			if (choice(number) == true) {
				if (number == 1 || number == 2)
				{
					check(number);
				}
			}
			
		}
		else {
			cout << "                             " << endl;
		}
	}
}

// Find a employee by surname
List* Management::findemployee (int number)
{ 
	List* helper = Head;
	if (helper == nullptr)
	{
		cout << "                            NO EMPLOYEES IN A BASE DATA " << endl;
		return nullptr;
	}
	else {
		string surname;
		cout << "                            FIND A EMPLOYEE BY SURNAME " << endl;
		cout << "                            ENTER THE SURNAME " << endl;
		cin >> surname;
		if (stringcheck(surname) == true) {};

		do {
			const char* psurname = surname.c_str();
			const char* psurnamekey = helper->key.c_str();

			if ((_stricmp(psurname, psurnamekey) == 0))
			{
				if (number == 1) { // For showing all details
					helper->employee->employee_show();
				}
				return helper;
			}
			else
			{
				helper = helper->next;
			}
		} while (helper != nullptr);
		cout << "                            THE EMPLOYEE HASN'T BEEN FOUND IN BASE DATA" << endl;
		return nullptr;
	}
	return nullptr;
}

// Show full list of the employees 
bool Management::showemployees()
{
    List * helper = Head;
	int i = 1;
	if (helper == nullptr)
	{
		cout << "                            NO EMPLOYEES IN A BASE DATA " << endl;
		return false;
	}
	else {
		do {
			cout << i << ". " << helper->key << "  " << helper->employee->employee_Name << endl;
			helper = helper->next;
			i += 1;
		}
		while (helper != nullptr);
	}
	return true;
}

// Show list of the employees by kind of work
bool Management::showemployeesbyclass()
{
	if (Head == nullptr)
	{
		cout << "                            NO EMPLOYEES IN A BASE DATA " << endl;
		return true;
	}
	else {

		kindofwork();
		int number;
		if (choice(number) == true) {

			if ((number == 5) || (number == 4) || (number == 3) || (number == 2) || (number == 1))
			{
				system("cls");
				List* helper = Head;
				int i = 1;
				do {
					if (helper->employee->number == number) {
						cout << i << ". " << helper->key << "  " << helper->employee->employee_Name << endl;
						i += 1;
					}
					helper = helper->next;
				} while (helper != nullptr);

				return true;
			}
			else 
			{
				return false;

			}
		}
	}
}


/***********************************************************************************************************************************/
// Additional functions

// Function, which add employee do the list
void Management::addtolist()
{

      int pNumber = atoi(elements[0].c_str());
      string pName = elements[1];
      string pSurname = elements[2];
      string pDate = elements[3];
      bool pSex;
         if (elements[4] == "1") {
	     pSex = 1;
         }
         else {
	     pSex = 0;
         }
      string pPhone = elements[5];
      string pAccount = elements[6];
      string pPosition = elements[7];
      double pRate =atof(elements[8].c_str());

      switch (pNumber)
      {

      case 1: // Class supervise
      {
	  string pCSCSNo = elements[9];
	  string pCompany = elements[10];
	  string pWorkplace = elements[11];
	  int pOverseen = atoi(elements[12].c_str());
	  string pCompanyPhoneNo = elements[13];

	  List* ptr = new List(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pCSCSNo, pCompany, pWorkplace, pOverseen, pCompanyPhoneNo);

	  if (Head == nullptr) {
		Head = ptr;
		Tail = ptr;
	  }
	  else {
		 int variable = ptr->add(ptr, Head);
		switch (variable)
		{
		case 0: { Head = ptr; break; }
		case 1: { break; }
		case 2: { Tail = ptr; break; }
		}
	  }
	  break;
      }
      case 2: // Class carpenter 
      {
	  string pCSCSNo = elements[9];
	  string pCompany = elements[10];
	  string pWorkplace = elements[11];
	  int pNVQLevel = atoi(elements[12].c_str());

	  List* ptr = new List(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pCSCSNo, pCompany, pWorkplace, pNVQLevel);

	  if (Head == nullptr) {
		Head = ptr;
		Tail = ptr;
	  }
	  else {
		int variable = ptr->add(ptr, Head);
		switch (variable)
		{
		case 0: { Head = ptr; break; }
		case 1: { break; }
		case 2: { Tail = ptr; break; }
		}
	  }

	  break;
      }
      case 3: // Class manager
      {
	  string pINo = elements[9];
	  string pTaxCode = elements[10];
	  string pCompanyPhoneNo = elements[11];
	  int pQtyProjects = atoi(elements[12].c_str());
	  int pOwnCar = atoi(elements[13].c_str());


	  List* ptr = new List(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo, pQtyProjects, pOwnCar);

	  if (Head == nullptr) {
		Head = ptr;
		Tail = ptr;
	  }
	  else {
		int variable = ptr->add(ptr, Head);
		switch (variable)
		{
		case 0: { Head = ptr; break; }
		case 1: { break; }
		case 2: { Tail = ptr; break; }
		}
	  }

	  break;
      }
      case 4: // Class account
      {
	  string pINo = elements[9];
	  string pTaxCode = elements[10];
	  string pCompanyPhoneNo = elements[11];
	  string pCompany = elements[12];
	  int pOversee = atoi(elements[13].c_str());
	  List* ptr = new List(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo, pCompany, pOversee);

	  if (Head == nullptr) {
		Head = ptr;
		Tail = ptr;
	  }
	  else {
		int variable = ptr->add(ptr, Head);
		switch (variable)
		{
		case 0: { Head = ptr; break; }
		case 1: { break; }
		case 2: { Tail = ptr; break; }
		}
	  }

	  break;
      }
      case 5: // Class driver
      {
	  string pINo = elements[9];
	  string pTaxCode = elements[10];
	  string pCompanyPhoneNo = elements[11];
	  int pOwnCar = atoi(elements[12].c_str());
	  string pCategory = elements[13];
	  string pExpiryData = elements[14];

	  List* ptr = new List(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo, pOwnCar, pCategory, pExpiryData);

	  if (Head == nullptr) {
		Head = ptr;
		Tail = ptr;
	  }
	  else {
		int variable = ptr->add(ptr, Head);
		switch (variable)
		{
		case 0: { Head = ptr; break; }
		case 1: { break; }
		case 2: { Tail = ptr; break; }
		}
	  }
	  break;
      }
}
}

// Function which check the all details
void Management::check( int counter)
{
	system("cls");

	string line;
	if ((counter == 0) || (counter == 1)) {
		cout << "NAME:  ";   cin >> line;
		if (stringcheck(line) == true) { elements.push_back(line); }
		

	}
	if ((counter == 0 ) || (counter == 2)) {
		cout << "SURNAME:  ";   cin >> line;
		if (stringcheck(line) == true) { elements.push_back(line); }
	}

	if ((counter == 0) || (counter == 3)) {
		cout << "DATE OF BIRTH:  " << endl;
		int check;
		do { check = datecheck(line); } while (check != 1);
		elements.push_back(line);
	}

	if ((counter == 0) || (counter == 4)) {
	cout << "SEX (F or M):  ";  cin >> line;
	line = truecheck(line, 1);
	elements.push_back(line); 
	}

	if ((counter == 0) || (counter == 5)) {
		cout << "PHONE NUMBER:  ";  cin >> line;
		if (numbercheck(line, 10) == true) { elements.push_back(line); }
	}

	if ((counter == 0) || (counter == 6)) {
		cout << "ACCOUNT NUMBER:  ";  cin >> line;
		if (numbercheck(line, 8) == true) { elements.push_back(line); }
	}

	int number = atoi(elements[0].c_str());
	if (counter == 0) {
		switch (number)
		{
		case 1: { line = "SUPERVISE"; break; }
		case 2: { line = "CARPENTER"; break; }
		case 3: { line = "MANAGER"; break; }
		case 4: { line = "ACCOUNT"; break; }
		case 5: { line = "DRIVER"; break; }
		}
		elements.push_back(line);
	}
	if ((counter == 0) || (counter == 7)) {
		cout << "RATE:  ";  cin >> line;
		if (numbercheck(line, 1) == true) {
			elements.push_back(line);
		}
	}

	switch (number)
	{

	case 1: // Class supervise
	{
		if ((counter == 0) || (counter == 8)) {
			cout << "CSCS NUMBER:  ";  cin >> line;
			if (numbercheck(line, 8) == true) { elements.push_back(line); }
		}
		if ((counter == 0) || (counter == 9)) {
			cout << "OVERSEEN COMPANY:  ";  cin >> line;
			if (stringcheck(line) == true) { elements.push_back(line); }
		}
		cout << "WORKPLACE:  ";  cin >> line;
		if (stringcheck(line) == true) { elements.push_back(line); }

		cout << "AMOUNT OF OVERSEEN PEOPLE:  ";  cin >> line;
		if (numbercheck(line, 3) == true) { elements.push_back(line); }

		cout << "COMPANY PHONE NUMBER:  ";  cin >> line;
		if (numbercheck(line, 10) == true) { elements.push_back(line); }

		cout << endl;
		addtolist();

		break;
	}
	case 2: // Class carpenter 
	{
		cout << "CSCS NUMBER:  ";  cin >> line;
		if (numbercheck(line, 8) == true) { elements.push_back(line); }

		cout << "OVERSEEN COMPANY:  ";  cin >> line;
		if (stringcheck(line) == true) { elements.push_back(line); }

		cout << "WORKPLACE:  ";  cin >> line;
		if (stringcheck(line) == true) { elements.push_back(line); }

		cout << "NATIONAL VOCATIONAL QUALIFICATIONS LEVEL:  ";
		line = optioncheck(2);
		while (line != "0")
		{ line = optioncheck(2); }
	    elements.push_back(line);
		cout << endl;
		addtolist();

		break;
	}
	case 3: // Class manager
	{
		if ((counter == 0) || (counter == 8)) {
			cout << "INSURANCE NUMBER:  ";  cin >> line;
			if (numbercheck(line, 10) == true) { elements.push_back(line); }
		}

		if ((counter == 0) || (counter == 9)) {
			cout << "TAX CODE CHOOSE FROM THE LIST  " << endl;
			line = optioncheck(1);	elements.push_back(line);
		}

		if ((counter == 0) || (counter == 10)) {
			cout << "COMPANY PHONE NUMBER:  ";  cin >> line;
			if (numbercheck(line, 10) == true) { elements.push_back(line); }
		}

		if ((counter == 0) || (counter == 11)) {
			cout << "QUANTITY OF THE PROJECTS:  ";  cin >> line;
			if (numbercheck(line, 2) == true) { elements.push_back(line); }
		}
		if ((counter == 0) || (counter == 12)) {
			cout << "OWN CAR:  ";  cin >> line;
			line = truecheck(line, 2);
			elements.push_back(line);
		}
		if (counter == 0) {
			cout << endl;
			addtolist();
		}
		break;
	}
	case 4: // Class account
	{
		cout << "INSURANCE NUMBER:  ";  cin >> line;
		if (numbercheck(line, 10) == true) { elements.push_back(line); }

		cout << "TAX CODE CHOOSE FROM THE LIST  " << endl;
		line = optioncheck(1);
		while (line != "0")
		{ line = optioncheck(1); } 
		elements.push_back(line);   cout << endl;

		cout << "COMPANY PHONE NUMBER:  ";  cin >> line;
		if (numbercheck(line, 10) == true) { elements.push_back(line); }

		cout << "OVERSEEN COMPANY:  ";  cin >> line;
		if (stringcheck(line) == true) { elements.push_back(line); }

		cout << "AMOUNT OF OVERSEEN PEOPLE:  ";  cin >> line;
		if (numbercheck(line, 3) == true) { elements.push_back(line); }

		cout << endl;
		addtolist();

		break;
	}
	case 5: // Class driver
	{

		cout << "INSURANCE NUMBER:  ";  cin >> line;
		if (numbercheck(line, 10) == true) { elements.push_back(line); }

		cout << "TAX CODE CHOOSE FROM THE LIST  " << endl;
		line = optioncheck(1);	elements.push_back(line);

		cout << "COMPANY PHONE NUMBER:  ";  cin >> line;
		if (numbercheck(line, 10) == true) { elements.push_back(line); }

		cout << "OWN CAR (Y OR N):  ";  cin >> line;
		line = truecheck(line, 2);
		elements.push_back(line);


		cout << "DRIVING LICENCE CATEGORY:  ";  cin >> line;
		line = optioncheck(3);
		while (line != "0")
		{ line = optioncheck(3); }
		elements.push_back(line);

		cout << "DRIVING LICENCE EXPIRY DATE:  ";  cin >> line;
		int check;
		do {
			check = datecheck(line);
		} while (check != 1);
		elements.push_back(line);

		cout << endl;
		addtolist();

		break;
	}

	default: {

		system("cls");
		cout << "                            INCORRECT NUMBER. TRY AGAIN ENTRY THE NUMBER:   \n";
		addemployee();
		break;
	}
	}
	
}

// Delete a existing data base
void Management::deletebase()
{
	List* helper = Tail;
	if (Head != nullptr) {

		cout << "                            DELETING THE EXISTING DATA IN PROGRAM" << endl << endl;
		while (Tail != Head) {

			helper = Tail;
			Tail = helper->prev;
			Tail->next = nullptr;
			delete helper;
		}
		helper = Head;
		Head = nullptr;
		Tail = nullptr;
		delete helper;
	}

}

/***********************************************************************************************************************************/
// Shows help information
bool help (Management & base)
{
	cout << endl;
	cout << "                            WELCOME TO DATA BASE " << endl;
	cout << "                            AVAIABLE OPTIONS" << endl << endl;
	cout << "                            1.LOAD DATA BASE FROM TXT FILE " << endl;
	cout << "                            2.SAVE DATA BASE TO THE TXT FILE " << endl;
	cout << "                            3.CREATE NEW DATA BASE " << endl;
	cout << "                            4.ADD EMPLOYEE " << endl;
	cout << "                            5.FIND EMPLOYEE " << endl;
	cout << "                            6.DELETE EMPLOYEE " << endl;
	cout << "                            7.EDIT A EMPLOYEE DETAILS " << endl;
	cout << "                            8.SHOW FULL LIST OF EMPLOYEES " << endl;
	cout << "                            9.SHOW LIST OF EMPLOYEES BY KIND OF WORK" << endl;
	cout << "                            10.CLOSE THE PROGRAM " << endl << endl;
	cout << "                            CHOOSE A NUMBER OF THE OPTION " << endl;

	int number;
	if (choice(number) == true) {

		switch (number)
		{
		case 1:
		{
			system("cls");
			base.loadbase();
			return true;
			break;
		}
		case 2:
		{
			system("cls");
			base.savebase();
			return true;
			break;
		}
		case 3:
		{
			system("cls");
			base.createbase();
			return true;
			break;
		}
		case 4:
		{
			system("cls");
			base.addemployee();
			return true;
			break;
		}
		case 5:
		{
			system("cls");
			base.findemployee(1);
			return true;
			break;
		}
		case 6:
		{
			system("cls");
			base.deleteemployee();
			return true;
			break;
		}
		case 7:
		{
			system("cls");
			base.editemployee();
			return true;
			break;
		}
		case 8:
		{
			system("cls");
			base.showemployees();
			return true;
			break;
		}
		case 9:
		{
			system("cls");
			bool option = base.showemployeesbyclass();
			while (option != true)
			{
				cout << "                            TRY AGAIN PUT A NUMBER OF THE OPTION " << std::endl;
				option = base.showemployeesbyclass();
			}
			return true;
			break;
		}
		case 10:
		{
			system("cls");
			cout << "                            END OF THE PROGRAM" << endl;
			return false;
			break;
		}
		default: {

			system("cls");
			cout << "                            TRY AGAIN PUT A NUMBER OF THE OPTION ";
			return true;
			break;
		}
		}
	}
}

// Check if the written string is correct (contains only letters)
bool stringcheck(string & line)
{
	for (int i = 0; i < line.size(); i++)
	{
		if (!(isalpha(line[i])))
		{
			cin.clear();
			cin.ignore(std::numeric_limits <std::streamsize >::max(), '\n');
			cout << "                            ONLY LETTERS. TRY AGAIN: ";
			cin >> line;
			i = 0;
		}
	}
	transform(line.begin(), line.end(), line.begin(), ::toupper);
	return true;
}

// Check if the written date is correct and contais only digits
int datecheck (string & line)
{
	string day;
	string month;
	string year;

	cout << "DAY:  "; cin >> day;
	if (numbercheck(day, 2) == true) {};
	cout << "MONTH:  "; cin >> month;
	if (numbercheck(month, 2) == true) {};
	cout << "YEAR:  "; cin >> year;
	if (numbercheck(year, 4) == true) {};

	int nday = atoi(month.c_str());
	int nmonth = atoi(month.c_str());
	int nyear = atoi(year.c_str());

	if ((nyear < 0) || (nyear > 2019)){
		cout << "                            INCORRECT YEAR " << endl;
		return 0;
	}
	if (nmonth < 0 || nmonth > 12) {
		cout << "                            INCORRECT MONTH " << endl;
		return 0;	
	}
	if (nmonth == 2)
	{
			if (nyear % 4 == 0)
			{
				if (nday > 29 || nday < 0) {
					cout << "                            FEBRUARY IN LEAP YEAR HAS ONLY 29 DAYS " << endl;
					return 0;
				}
			}
			else
			{
				if (nday > 28 || nday < 0) {
					cout << "                            FEBRUARY HAS ONLY 28 DAYS " << endl;
					return 0;
				}
			}
	}
	else if (nmonth == 1 || nmonth == 3 || nmonth == 5 || nmonth == 7 || nmonth == 8 || nmonth == 10 || nmonth == 12){
		if (nday > 31 || nday < 0) {
			cout << "                            THAT MONTH HAS ONLY 31 DAYS " << endl;
			return 0;
		}	}
	else	{
		if (nday > 30 || nday < 0) {
			cout << "                            THAT MONTH HAS ONLY 30 DAYS  " << endl;
			return 0;
		}	}

	if (day.size() != 2) {
		day = "0" + day;
	}
	if (month.size() != 2) {
		month = "0" + month;
	}
	int i = year.size();
 
	if (i == 3) {
		year = "0" + year;
	}
	else if (i == 2) {
		year = "00" + year;
	}
	else if (i == 1) {
		year = "000" + year;
	}

	line = day + month + year;
	return 1;

}

// Check if the written string is correct (contains only digits and check if the lenght is correct)
bool numbercheck(string & line, int amount)
{
	int number = 0;
	string nline;
	if (amount == 1) 
	{
		for (int j = 0; j < line.size(); j++) {
			if ((line[j] == ',') || (line[j] == '.')) 
			{
				number = j;
				line.erase(line.begin() + number);
				break;
			}
		}
		for (int i = 0; i < line.size(); i++)
		{
			if (!(isdigit(line[i])))
			{
				cin.clear();
				cin.ignore(std::numeric_limits <std::streamsize >::max(), '\n');
				cout << "                            ONLY NUMBERS.TRY AGAIN: ";
				cin >> line;
				i = 0;
			}
		}

		for (int j = 0; j < line.size(); j++) 
		{
			if (j == number) {
				nline = nline + '.';
			}
			nline = nline + line[j];
		}
		line = nline;
		
	}
	else {

		for (int i = 0; i < line.size(); i++)
		{
			if ((line.size() != amount) || (!(isdigit(line[i]))))
			{
				cin.clear();
				cin.ignore(std::numeric_limits <std::streamsize >::max(), '\n');

				if (amount == 8) { cout << "                            ONLY NUMBERS. IT HAS TO BE EIGHT NUMBERS AGAIN: "; }
				if (amount == 10) { cout << "                            ONLY NUMBERS.IT HAS TO BE TEN NUMBERS. TRY AGAIN: "; }
				if (amount == 3) { cout << "                            ONLY NUMBERS.THE LIMIT IS THREE DIGITS. TRY AGAIN: "; }
				if (amount == 2) { cout << "                            ONLY NUMBERS.THE LIMIT IS TWO DIGITS. TRY AGAIN: "; }
				if (amount == 4) { cout << "                            ONLY NUMBERS.THE LIMIT IS FOUR DIGITS.  TRY AGAIN: "; }
				cin >> line;
				i = 0;
			}
		}
	}

	return true;
}

// Show a list of option depends of the variable
string optioncheck ( int option )
{
	switch (option) {
	case 1: {
		cout << "1.1250 L  " << endl;
		cout << "2.1250 NT  " << endl;
		cout << "3.1250 BR  " << endl;
		cout << "4.1250 D0  " << endl;
		cout << "YOUR CHOICE:   ";
		int number;
		if (choice(number) == true) {

			switch (number)
			{
			case 1:
			{   return "1250 L";
				break;
			}
			case 2:
			{   return "1250 NT";
				break;
			}
			case 3:
			{   return "1250 BR";
				break;
			}
			case 4:
			{   return "1250 D0";
				break;
			}
			default:
			{
				cout << "                            INCORRECT NUMBER. TRY AGAIN ENTRY THE NUMBER:   ";
				return "0";
				break;
			} } }
	}
	case 2: {

		string line;
		int number;
		if (choice(number) == true) {

			if ((number == 1) || (number == 2) || (number == 3) || (number == 4) || (number == 5))
			{
				line = std::to_string(number);
				return line;
			}
			else {
				cout << "                            THERE ARE ONLY 5 LEVELS OF NVQ:   " << endl;
				return "0";
			}
		}
	}
	case 3: {

		cout << "                            LIST OF EXISTING CATEGORIES OF DRIVING LICENCE" << endl;
		cout << "1.B1 " << endl;
		cout << "2.B " << endl;
		cout << "3.C1 " << endl;
		cout << "4.C " << endl;
		cout << "5.D1" << endl;
		cout << "6.D" << endl;
		cout << "7.BE" << endl;

		int number;
		if (choice(number) == true) {
	
		switch(number)
		{
			case 1:
			{   return "B1";
				break;
			}
			case 2:
			{   return "B";
				break;
			}
			case 3:
			{   return "C1";
				break;
			}
			case 4:
			{   return "C";
				break;
			}
			case 5:
			{   return "D1";
				break;
			}
			case 6:
			{   return "D";
				break;
			}
			case 7:
			{   return "BE";
				break;
			}
			default:
			{
				cout << "                            INCORRECT NUMBER. TRY AGAIN ENTRY THE NUMBER:   ";
				return "0";
				break;
			} } }
	}
	}

}

// Check if the bool answer
string truecheck(string & line, int amount)
{
	for (int i = 0; i < line.size(); i++)
	{
		if ((!(isalpha(line[i]))) || (line.size() != 1))
		{
			cin.clear();
			cin.ignore(std::numeric_limits <std::streamsize >::max(), '\n');
			if (amount == 1) {
				cout << "                            ONLY ONE LETTER. TRY AGAIN" << endl;
				cout << "                            AVAIABLE OPTIONS. F OR M:  ";
			}
			if (amount == 2) {
				cout << "                            ONLY ONE LETTER. TRY AGAIN" << endl;
				cout << "                            AVAIABLE OPTIONS. Y OR N:  ";
			}
			cin >> line;
			i = 0;
		}
	}
	transform(line.begin(), line.end(), line.begin(), ::toupper);
	if (amount == 1) {
		char sign = line[0];
		switch (sign) {
		case 'F':
		{
			return "1";
			break;
		}
		case 'M':
		{
			return "0";
			break;
		}
		default:
		{
			cout << "                            INCORRECT. THERE IS ONLY 2 OPTIONS : F OR M . TRY AGAIN : " << endl;
			cin >> line;
			line = truecheck(line, amount);
			return line;
			break;
		}
		}
	}
	if (amount == 2) {
		char sign = line[0];
		switch (sign) {
		case 'Y':
		{
			return "1";
			break;
		}
		case 'N':
		{
			return "0";
			break;
		}
		default:
		{
			cout << "                            INCORRECT. THERE IS ONLY 2 OPTIONS : Y OR N . TRY AGAIN : " << endl;
			cin >> line;
			line = truecheck(line, amount);
			return line;
			break;
		}
		}
	}
}

bool choice(int & number)
{
	cin >> number;
	while (cin.fail())
	{
		cout << "                            TRY AGAIN PUT A NUMBER OF THE OPTION " << std::endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> number;
	}
	return true;
}

void kindofwork()
{
	cout << "                            CHOSE THE KIND OF WORK " << endl;
	cout << "                            AVAIABLE OPTIONS" << endl;
	cout << "                            1.SUPERVISE" << endl;
	cout << "                            2.CARPENTER" << endl;
	cout << "                            3.MANAGER" << endl;
	cout << "                            4.ACCOUNT" << endl;
	cout << "                            5.DRIVER" << endl;
	cout << "                            ENTER THE NUMBER:  ";
}


