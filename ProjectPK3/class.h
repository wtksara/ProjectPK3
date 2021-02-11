#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Data base which includes employees who work in England

// Abstract class 
class Employee
{
protected:
	int number; // Number assigned to class
	string employee_Name; // Name of the employee
	string employee_Surname; // Surname of the employee
	string employee_Date; // Date of birth in format DD/MM/YYYY
	bool employee_Sex; // Sex of the employee true for Female, false for Man
	string employee_PhoneNo; // Phone number
	string employee_AccountNo; // Account number
	string employee_Position; // Position on the workplace
	double employee_Rate; // Rate per hour

public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management
	friend class List; // Declaration of friendship with a class List

	friend std::ostream& operator<<(std::ostream & outfile, const Employee & pemployee); // Declaration of friendship with operator << which is overloaded

	// Constructor
	Employee(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate);

	// Deconstructor
	virtual ~Employee() {};

	// Abstract functions
	void virtual employee_show() = 0; // Show all details
	void virtual employee_edit() = 0; // Edit employee details

	virtual std::ostream & save(std::ostream & outfile) const = 0; // Save to the file all details

	// Functions
	void employee_details(); // Show all employee details

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inheriting class 2 level
// Class which includes employees who are working on the construction site
class Construction : public Employee
{
protected:
	string con_CSCSNo; // CSCS Card number, which allows employee to work on construction site
	string con_Company; // Company for which employee is working for
	string con_Workplace; // Name of the workplace

public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management
	friend class List; // Declaration of friendship with a class List

	// Constructor
	Construction(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount,
		string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace);

	// Destruktor
	virtual ~Construction() {};

	// Abstract functions
	void virtual employee_show() = 0; // Show all details
	void virtual employee_edit() = 0; // Edit employee details

	virtual std::ostream& save(std::ostream& outfile) const = 0;  // Save to the file all details

	// Functions
	void con_details(); // Show all construction details

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inheriting class 2 level
// Class which includes employees who are working at the office 
class Office : public Employee
{
protected:
	string office_INo; // Insurance Number allow to work legally in UK
	string office_TaxCode; // Tax code    typical 1250L where 1250 is the amount tax free
	// Types of the letters on the end
	// L - Standart tax free   ;    NT - No Tax  
	// If you have more than one job
	// BR - Basic rate   ;    D0 - Higher rate
	string office_CompanyPhoneNo; // Company phone number

public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management
	friend class List; // Declaration of friendship with a class List

	// Constructor
	Office(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount,
		string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo);

	// Destruktor
	virtual ~Office() {};

	// Abstract functions
	void virtual employee_show() = 0; // Show all details
	void virtual employee_edit() = 0; // Edit employee details

	virtual std::ostream& save(std::ostream& outfile) const = 0; // Save to the file all details

   // Functions
	void office_details(); // Show all office details
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inheriting class from Construction 3 level 
class Supervise : public Construction
{
protected:
	int sup_Oversee;  // Amount of the employees overseen on the workplace
	string sup_CompanyPhoneNo; // Company phone number
	
public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management
	friend class List; // Declaration of friendship with a class List

	// Constructor
	Supervise(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount,
		string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace, int pOverseen, string pCompanyPhoneNo);

	// Destruktor
     ~Supervise() {};

	// Override functions
	void  employee_show() override; // Show all details of the employee
	void  employee_edit() override; // Edit employee details

	std::ostream& save(std::ostream& outfile) const override; // Save to the file all details
}; 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inheriting class from Construction 3 level 
class Carpenter : public Construction
{
protected:
	int carpenter_NVQLevel; // Level of the Speciality

public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management
	friend class List; // Declaration of friendship with a class List
	
	// Constructor
	Carpenter(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount,
		string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace, int pNVQLevel);

	// Destruktor
	~Carpenter() {};

	// Override functions
	void  employee_show() override; // Show all details of the employee
	void  employee_edit() override; // Edit employee details

	std::ostream& save(std::ostream& outfile) const override; // Show all details of the employee
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inheriting class from Office 3 level 
class Manager : public  Office
{
protected:
	int manager_QtyProjects; // Amount of the ongoing projects
	int manager_OwnCar; // Own Car or Comapny one

public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management
	friend class List; // Declaration of friendship with a class List

	// Constructor
	Manager(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount,
		string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, int pQtyProjects, int pOwnCar);

	// Destruktor
	~Manager() {};

	// Overide functions
	void  employee_show() override; // Show all details of the employee
	void  employee_edit() override ; // Edit employee details
	
	std::ostream& save(std::ostream& outfile) const override; // Show all details of the employee
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inheriting class from Office 3 level 
class Account : public  Office
{
protected:
	string acc_Company; // Overseen company
	int acc_Oversee; // Amount of the employees overseen 

public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management
	friend class List; // Declaration of friendship with a class List

	// Constructor
	Account(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount,
		string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, string pCompany, int pOversee);

	// Destruktor
	~Account() {};

	// Overide functions
	void  employee_show() override; // Show all details of the employee
	void  employee_edit() override ; // Edit employee details

	std::ostream& save(std::ostream& outfile) const override; // Show all details of the employee
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inheriting class from Office 3 level 
class Driver : public  Office
{
protected:
	int driver_OwnCar; // Own Car or Comapny one
	string driver_Category; // Category of the driving licence
	string driver_ExpiryData;// Expiry date of the driving licence

public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management
	friend class List; // Declaration of friendship with a class List

	// Constructor
	Driver(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount,
		string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, int pOwnCar, string pCategory, string pExpiryData);
	
	// Destruktor
	~Driver() {};

	// Overide functions
	void  employee_show() override; // Show all details of the employee
	void  employee_edit() override ; // Edit employee details

	std::ostream& save(std::ostream& outfile) const override; // Show all details of the employee
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class responsible for list of the employees in alphabetical order, where a surname is a key
class List
{
protected:
	string key; // Surname of the employee is a key
	Employee* employee; // Indicator for a object of Employee class
	List* next; // Indicator for next employee
	List* prev; // Indicator for previous employee

    public:
	// Friendship
	friend class Management; // Declaration of friendship with a class Management

	// Constructor of Supervise object
	List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace, int pOverseen, string pCompanyPhoneNo);
	// Constructor of Carpenter object
	List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace, int pNVQLevel);
	// Constructor of Menager object
	List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, int pQtyProjects, int pOwnCar);
	// Constructor of Account object
	List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, string pCompany, int pOversee);
	// Constructor of  Driver object
	List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, int pOwnCar, string pCategory, string pExpiryData);
	
	// Destruktor
	~List();

	// Functions
	int add(List* ptr, List* ptrHead); // Function which add a object to the right position
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class responsible for task management
class Management
{
protected:
	List* Head;
	List* Tail;
	vector <string> elements;

	// Additional functions
	void addtolist(); // Function, which add employee do the list
	void check( int counter); // Function which check the all details
	void deletebase(); // Delete a existing data base

public:

	// Constructor
	Management(); // Set a head and tail for nullptr

	// Deconstructor
	~Management(); // Set a head and tail for nullptr

	// Main functions 
	bool loadbase(); // Load a employee base from a .txt file
	bool savebase(); // Save a employee base to a .txt file
	void createbase(); // Creating a new employee base
	void addemployee(); // Add a employee to data base
	void deleteemployee(); // Delete a employee from the data base
	void editemployee(); // Edit a employee details 
	List* findemployee (int number); // Find a employee by surname
	bool showemployees (); // Show full list of the employees 
	bool showemployeesbyclass(); // Show list of the employees by kind of work


	// Friendship functions, which are helpful to check the inserted details 
	friend bool help ( Management & base ); // Show help information
};

// Friendship functions, which are helpful to check the inserted details 

bool help ( Management & base ); // Shows help information

bool stringcheck (string & line);  // Check if the written string is correct (contains only letters)
int datecheck(string & line); // Check if the written date is correct and contais only digits
bool numbercheck(string & line, int amount);  // Check if the written string is correct (contains only digits and check if the lenght is correct)
string optioncheck (int option); // Show a list of option depends of the variable
string truecheck(string & line, int amount); // Check if the bool answer
bool choice (int & choice);
void kindofwork();