//
// customer.h
//  Created on: Feb 24, 2019
//      Author: vismohan
//
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementable Customer class that holds information about customers and a reference to a list of
// transactions associated with a customer.
// --------------------------------------------------------------------------------------------------------------------
// Customer class stores customer id, first name, last name. It also holds reference to latest transaction
// associated with it in the attribute Head. Each transaction in turn holds reference to the next transaction.
// --------------------------------------------------------------------------------------------------------------------

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#pragma once
#include <string>
#include "transaction.h"
using namespace std;

class Customer
{
private:
	int customerid; //customer ID
	string lastname; //customer last name
	string firstname; //customer first name
	transaction* head; // Head to the list of transactions associated to a customer

public:
	//------------------------------------Customer--------------------------------------------------
	// Description: Customer constructor, initializes the customer with first name, last name and ID
	//----------------------------------------------------------------------------------------------
	Customer(int customerid, string lastname, string firstname);
	//------------------------------------Customer--------------------------------------------------
	// Description: Destructor for customer object
	//----------------------------------------------------------------------------------------------
	~Customer();
	//------------------------------------setcustomerid---------------------------------------------
	// Description: setter for CustomerID
	//----------------------------------------------------------------------------------------------
	void setcustomerid(int customerid);
	//------------------------------------setlastname-----------------------------------------------
	// Description: setter for Lastname
	//----------------------------------------------------------------------------------------------
	void setlastname(string lastname);
	//------------------------------------setfirstname----------------------------------------------
	// Description: setter for firstname
	//----------------------------------------------------------------------------------------------
	void setfirstname(string firstname);
	//------------------------------------settransactionhead----------------------------------------------
	// Description: setter for transaction head
	//----------------------------------------------------------------------------------------------
	void settransactionhead(transaction* head);
	//------------------------------------getcustomerid---------------------------------------------
	// Description: getter for CustomerID
	//----------------------------------------------------------------------------------------------
	int getcustomerid();
	//------------------------------------getlastname-----------------------------------------------
	// Description: getter for Lastname
	//----------------------------------------------------------------------------------------------
	string getlastname();
	//------------------------------------getfirstname----------------------------------------------
	// Description: getter for firstname
	//----------------------------------------------------------------------------------------------
	string getfirstname();
	//------------------------------------gettransactionhead----------------------------------------------
	// Description: getter for transaction head
	//----------------------------------------------------------------------------------------------
	transaction* gettransactionhead();
	//------------------------------------AddTransactiontoaCustomer----------------------------------
	// Description: add transaction to the customer
	//-----------------------------------------------------------------------------------------------
	void addtransaction(transaction* T);

};

#endif /* CUSTOMER_H_ */
