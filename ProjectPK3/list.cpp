#include "class.h"

// Constructor of Supervise object
List::List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace, int pOverseen, string pCompanyPhoneNo)
{
	key = pSurname;
	employee = new Supervise(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pCSCSNo, pCompany, pWorkplace, pOverseen, pCompanyPhoneNo);
	List* next = nullptr;
	List* prev = nullptr;
}
// Constructor of Carpenter object
List::List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pCSCSNo, string pCompany, string pWorkplace, int pNVQLevel)
{
	key = pSurname;
	employee = new Carpenter(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pCSCSNo, pCompany, pWorkplace, pNVQLevel);
	List* next = nullptr;
	List* prev = nullptr;
}
// Constructor of Menager object
List::List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, int pQtyProjects, int pOwnCar)
{
	key = pSurname;
	employee = new Manager(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo, pQtyProjects, pOwnCar);
	List* next = nullptr;
	List* prev = nullptr;

}
// Constructor of Account object
List::List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, string pCompany, int pOversee)
{
	key = pSurname;
	employee = new Account(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo, pCompany, pOversee);
	List* next = nullptr;
	List* prev = nullptr;

}
// Constructor of Driver object
List::List(string pName, string pSurname, string pDate, char pSex, string pPhone, string pAccount, string pPosition, double pRate, string pINo, string pTaxCode, string pCompanyPhoneNo, int pOwnCar, string pCategory, string pExpiryData)
{
	key = pSurname;
	employee = new Driver(pName, pSurname, pDate, pSex, pPhone, pAccount, pPosition, pRate, pINo, pTaxCode, pCompanyPhoneNo, pOwnCar, pCategory, pExpiryData);
	List* next = nullptr;
	List* prev = nullptr;
}
// Destruktor
List::~List()
{
	this->prev = nullptr;
	this->next = nullptr;
	delete employee;
}

// Function which add a object to the right position
int List::add(List* ptr, List* ptrHead)
{
	const char* pCKey = ptr->key.c_str();
	const char* pCHeadKey = ptrHead->key.c_str();

	if (_stricmp(pCKey, pCHeadKey) == 0) // If the key from new object if equal to key from head, the new object is going to be added after the existing one
	{
		if (ptrHead->next == nullptr)
		{
			ptr->prev = ptrHead;
			ptrHead->next = ptr;
			return 2; // Change the tail
		}
		else
		{
			ptr->add(ptr, ptrHead->next);
		}
	}
	else if (strcoll(pCKey, pCHeadKey) < 0) // If the key from new object is first in alphabetical order
	{
		if (ptrHead->prev == nullptr ) { // That element is a Head

			ptr->next = ptrHead;
			ptrHead->prev = ptr;
			return 0; // The actual head should be changed
		}
		else { 

			ptr->prev = ptrHead->prev;
			ptr->next = ptrHead;
			ptrHead->prev->next = ptr;
			ptrHead->prev = ptr;
			return 1; // Head is still the same
		}
	}
	else if (strcoll(pCKey, pCHeadKey) > 0) // If the key from new object is after head 
	{
		if (ptrHead->next == nullptr) { // It is the last object in the list

			ptr->prev = ptrHead;
			ptrHead->next = ptr;
			return 2; //  Change the tail

		}
		else {

			ptr->add(ptr, ptrHead->next);
		}
	}



}





