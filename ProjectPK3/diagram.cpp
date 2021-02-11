#include "class.h"
#include <array>

// Abstract class constructor
Employee::Employee(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate)
{
	employee_Name = pName;
	employee_Surname = pSurname;
	employee_Date = pDate;
	employee_Sex = pSex;
	employee_PhoneNo = pPhone;
	employee_AccountNo = pAccount;
	employee_Position = pPosition;
	employee_Rate = pRate;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function which shows all employee details
void Employee::employee_details()

{
	cout << endl;
	cout << "EMPLOYEE DETAILS " << endl << endl << endl;

	cout << "NAME: " << this->employee_Name << endl << endl;

	cout << "SURNAME: " << this->employee_Surname << endl << endl;

	cout << "DATE OF BIRTH: " << this->employee_Date[0] << this->employee_Date[1] << "." << this->employee_Date[2] << this->employee_Date[3] << ".";
	for (int i = 4; i < 8; i++)
	{
		cout << this->employee_Date[i];
	}
	cout << endl << endl;

	cout << "SEX: ";
	if (this->employee_Sex == 1) {
		cout << "FEMALE";
	}
	else {
		cout << "MALE";
	}
	cout << endl << endl;

	cout << "PHONE NUMBER: " << this->employee_PhoneNo << endl << endl;

	cout << "ACCOUNT NUMBER: "<< this->employee_AccountNo << endl << endl;

	cout << "POSITION: " << this->employee_Position << endl << endl;

	cout << "RATE: " << this->employee_Rate << endl << endl;



}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constuction class constructor
Construction::Construction(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace)
	:Employee(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate)
{
    con_CSCSNo = pCSCSNo;
	con_Company = pCompany;
	con_Workplace = pWorkplace;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function which shows all construction details
void Construction::con_details()
{
	cout << "CSCS NUMBER: "<< this->con_CSCSNo << endl << endl;
	cout << "COMPANY: " << this->con_Company << endl << endl;
	cout << "WORKPLACE: " << this->con_Company << endl << endl;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Office class constructor
Office::Office(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo)
	:Employee(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate)
{
	office_INo = pINo;
	office_TaxCode = pTaxCode;
	office_CompanyPhoneNo = pCompanyPhoneNo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function which shows all office details
void Office::office_details()
{
	cout << "INSURANCE NUMBER: " << this->office_INo << endl << endl;
	cout << "TAX CODE: " << this->office_TaxCode << endl << endl;
	cout << "COMPANY PHONE NUMBER: "<< this->office_CompanyPhoneNo << endl << endl;
}


/***********************************************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Supervise class constructor
Supervise::Supervise(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace, int pOverseen, string pCompanyPhoneNo) :
	Construction(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pCSCSNo, pCompany, pWorkplace)
{
	number = 1;
	sup_Oversee = pOverseen;
	sup_CompanyPhoneNo = pCompanyPhoneNo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function which shows all details
void Supervise::employee_show()
{
	this->employee_details();
	this->con_details();

	cout << "OVERSEEN AMOUNT ON WORKPLACE: " << this->sup_Oversee << endl << endl;
	cout << "COMPANY PHONE NUMBER: " << this->sup_CompanyPhoneNo << endl << endl;

}

void Supervise::employee_edit()
{
	cout << "1. NAME  " << endl;
	cout << "2. SURNAME  " << endl;
	cout << "3. DATE OF BIRTH  " << endl;
	cout << "4. SEX  " << endl;
	cout << "5. PHONE NUMBER  " << endl;
	cout << "6. ACCOUNT NUMBER  " << endl;
	cout << "7. RATE " << endl;
	cout << "8. CSCS NUMBER  " << endl;
	cout << "9. OVERSEEN COMPANY  " << endl;
	cout << "10. WORKPLACE " << endl;
	cout << "11. AMOUNT OF OVERSEEN PEOPLE  " << endl;
	cout << "12. COMPANY PHONE NUMBER  " << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Save to the file all details
std::ostream& Supervise::save(std::ostream& outfile) const
{
	outfile << con_CSCSNo << ";" << con_Company << ";" + con_Workplace << ";" + std::to_string(sup_Oversee) << ";" << sup_CompanyPhoneNo << ";";
	return outfile;
}

//-----------------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Carpenter class constructor
Carpenter::Carpenter(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace, int pNVQLevel)
	: Construction(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pCSCSNo, pCompany, pWorkplace)
{
	number = 2;
	carpenter_NVQLevel = pNVQLevel;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function which shows all details
void Carpenter::employee_show()
{
	this->employee_details();
	this->con_details();
	cout << "NVQ LEVEL: " << this->carpenter_NVQLevel << endl << endl;
}

void Carpenter::employee_edit()
{
	cout << "1. NAME  " << endl;
	cout << "2. SURNAME  " << endl;
	cout << "3. DATE OF BIRTH  " << endl;
	cout << "4. SEX  " << endl;
	cout << "5. PHONE NUMBER  " << endl;
	cout << "6. ACCOUNT NUMBER  " << endl;
	cout << "7. RATE " << endl;
	cout << "8. CSCS NUMBER  " << endl;
	cout << "9. OVERSEEN COMPANY  " << endl;
	cout << "10. WORKPLACE  " << endl;
	cout << "11. NATIONAL VOCATIONAL QUALIFICATIONS LEVEL " << endl;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Save to the file all details
std::ostream& Carpenter::save(std::ostream& outfile) const
{
	outfile << con_CSCSNo << ";" << con_Company << ";" << con_Workplace << ";" << std::to_string(carpenter_NVQLevel) << ";";
	return outfile;
}

//-----------------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Manager class constructor
Manager::Manager(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, int pQtyProjects, int pOwnCar)
	:Office (pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo)
{
	number = 3;
	manager_QtyProjects = pQtyProjects;
	manager_OwnCar = pOwnCar;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function which shows all details
void Manager::employee_show()
{

	this->employee_details();
	this->office_details();
	cout << "QUANTITY OF ONGOING PROJECTS: " << this->manager_QtyProjects << endl << endl;
	cout << "OWN CAR: ";
	if (this->manager_OwnCar == 1) {
		cout << "YES" << endl << endl;
	}
	else {
		cout << "NO" << endl << endl;
	}
}

void Manager::employee_edit()
{
	cout << "1. NAME  " << endl;
	cout << "2. SURNAME  " << endl;
	cout << "3. DATE OF BIRTH  " << endl;
	cout << "4. SEX  " << endl;
	cout << "5. PHONE NUMBER  " << endl;
	cout << "6. ACCOUNT NUMBER  " << endl;
	cout << "7. RATE " << endl;
	cout << "8. INSURANCE NUMBER" << endl;
	cout << "9. TAX CODE  " << endl;
	cout << "10. COMPANY PHONE NUMBER  " << endl;
	cout << "11. QUANTITY OF THE PROJECTS  " << endl;
	cout << "12. OWN CAR:  " << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Save to the file all details
std::ostream& Manager::save(std::ostream& outfile) const
{
	outfile << office_INo << ";" << office_TaxCode << ";" << office_CompanyPhoneNo << ";" << std::to_string(manager_QtyProjects) << ";" << std::to_string(manager_OwnCar) << ";";
	return outfile;
}

//-----------------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Account class constructor
Account::Account(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, string pCompany, int pOversee)
	:Office(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo)
{
	number = 4;
	acc_Company = pCompany;
	acc_Oversee = pOversee;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function which shows all details
void Account::employee_show()
{
	this->employee_details();
	this->office_details();
	cout << "OVERSEEN COMPANY: " << this->acc_Company << endl << endl;
	cout << "OVERSEEN AMOUNT OF PEOPLE: " << this->acc_Oversee << endl << endl;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Edit a employee details
void Account::employee_edit()
{
	cout << "1. NAME  " << endl;
	cout << "2. SURNAME  " << endl;
	cout << "3. DATE OF BIRTH  " << endl;
	cout << "4. SEX  " << endl;
	cout << "5. PHONE NUMBER  " << endl;
	cout << "6. ACCOUNT NUMBER  " << endl;
	cout << "7. RATE " << endl;
	cout << "8. INSURANCE NUMBER" << endl;
	cout << "9. TAX CODE  " << endl;
	cout << "10. COMPANY PHONE NUMBER  " << endl;
	cout << "11. OVERSEEN COMPANY  " << endl;
	cout << "12. AMOUNT OF OVERSEEN PEOPLE " << endl;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Save to the file all details
std::ostream& Account::save(std::ostream& outfile) const
{
	outfile << office_INo << ";" << office_TaxCode << ";" << office_CompanyPhoneNo << ";" << acc_Company << ";" << std::to_string(acc_Oversee) << ";";
	return outfile;
}

//-----------------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Driver class constructor
Driver::Driver(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, int pOwnCar, string pCategory, string pExpiryData)
	:Office(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo)
{
	number = 5;
	driver_OwnCar = pOwnCar;
	driver_Category = pCategory;
    driver_ExpiryData = pExpiryData;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function which shows all details
void Driver::employee_show()
{
	this->employee_details();
	this->office_details();

	cout << "OWN CAR: ";
	if (driver_OwnCar == 1) {
		cout << "YES" << endl << endl;
	}
	else {
		cout << "NO" << endl << endl;
	}

	cout << "DRIVING LICENCE CATEGORY: " << this->driver_Category << endl << endl;

	cout << "EXPIRY DATE " << this->driver_ExpiryData[0] << this->driver_ExpiryData[1] << "." << this->driver_ExpiryData[2] << this->driver_ExpiryData[3] << ".";
	for (int i = 4; i < 8; i++)
	{
		cout << this->driver_ExpiryData[i];
	}
	cout << endl << endl;

}

void Driver::employee_edit()
{
	cout << "1. NAME  " << endl;
	cout << "2. SURNAME  " << endl;
	cout << "3. DATE OF BIRTH  " << endl;
	cout << "4. SEX  " << endl;
	cout << "5. PHONE NUMBER  " << endl;
	cout << "6. ACCOUNT NUMBER  " << endl;
	cout << "7. RATE " << endl;
	cout << "8. INSURANCE NUMBER" << endl;
	cout << "9. TAX CODE  " << endl;
	cout << "10. COMPANY PHONE NUMBER  " << endl;
	cout << "11. OWN CAR  " << endl;
	cout << "12. DRIVING LICENCE CATEGORY " << endl;
	cout << "13. DRIVING LICENCE EXPIRY DATE " << endl;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Save to the file all details
std::ostream& Driver::save(std::ostream& outfile) const
{
	outfile << office_INo << ";" << office_TaxCode << ";" << office_CompanyPhoneNo << ";" << std::to_string(driver_OwnCar) << ";" + driver_Category << ";" << driver_ExpiryData << ";";
	return outfile;
}



//-----------------------------------------------------------------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Overloaded operator << which saves all employee details to the file

std::ostream& operator<<(std::ostream& outfile, const Employee & pemployee)
{
	outfile << pemployee.number << ";"<< pemployee.employee_Name << ";" << pemployee.employee_Surname << ";" << pemployee.employee_Date << ";";
	if (pemployee.employee_Sex == 1) {
				outfile << "true";
			}
	else {
				outfile << "false";
			}
	outfile << ";";
	outfile << pemployee.employee_PhoneNo << ";" << pemployee.employee_AccountNo << ";"<< pemployee.employee_Position << ";" << pemployee.employee_Rate << ";";	
	
	pemployee.save(outfile);
	outfile << endl;
	
	return outfile;
}

