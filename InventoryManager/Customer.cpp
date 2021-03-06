/*
 * customer.cpp

 *
 *  Created on: Mar 9, 2019
 *      Author: vismohan
 */
#include "Customer.h"

//------------------------------------Customer--------------------------------------------------
// Description: Customer constructor, initializes the customer with first name, last name and ID
//----------------------------------------------------------------------------------------------
Customer::Customer(int customerid, string lastname, string firstname)
{
	this->setcustomerid(customerid);
	this->setlastname(lastname);
	this->setfirstname(firstname);
	this->head = NULL;
}
//------------------------------------Customer--------------------------------------------------
// Description: Destructor for customer object
//----------------------------------------------------------------------------------------------
Customer::~Customer()
{

}
//------------------------------------setcustomerid---------------------------------------------
// Description: setter for CustomerID
//----------------------------------------------------------------------------------------------
void Customer::setcustomerid(int customerid)
{
	if (customerid > 0)
		this->customerid = customerid;
	else
		this->customerid = 0;
}
//------------------------------------setlastname-----------------------------------------------
// Description: setter for Lastname
//----------------------------------------------------------------------------------------------
void Customer::setlastname(string lastname)
{
	this->lastname = lastname;
}
//------------------------------------setfirstname----------------------------------------------
// Description: setter for firstname
//----------------------------------------------------------------------------------------------
void Customer::setfirstname(string firstname)
{
	this->firstname = firstname;
}
//------------------------------------settransactionhead----------------------------------------------
// Description: setter for transaction head
//----------------------------------------------------------------------------------------------
void Customer::settransactionhead(transaction* head)
{
	this->head = head;
}
//------------------------------------getcustomerid---------------------------------------------
// Description: getter for CustomerID
//----------------------------------------------------------------------------------------------
int Customer::getcustomerid()
{
	return this->customerid;
}
//------------------------------------getlastname-----------------------------------------------
// Description: getter for Lastname
//----------------------------------------------------------------------------------------------
string Customer::getlastname()
{
	return this->lastname;
}
//------------------------------------getfirstname----------------------------------------------
// Description: getter for firstname
//----------------------------------------------------------------------------------------------
string Customer::getfirstname()
{
	return this->firstname;
}

//------------------------------------gettransactionhead----------------------------------------------
// Description: getter for transaction head
//----------------------------------------------------------------------------------------------
transaction* Customer::gettransactionhead()
{
	return this->head;
}

//------------------------------------AddTransactiontoaCustomer----------------------------------
// Description: add transaction to the customer
//-----------------------------------------------------------------------------------------------
void Customer::addtransaction(transaction* T)
{
	//cout<<"Inside add transaction"<<endl;

	if (this->gettransactionhead()== NULL)
	{
		this->settransactionhead(T);
		return;
	}

	transaction* temp = this->gettransactionhead();
	this->settransactionhead(T);
	T->setnext(temp);

}





