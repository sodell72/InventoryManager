/*
 * transaction.h
 *
 *  Created on: Feb 24, 2019
 *      Author: vismohan
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include<string>
#include"Movie.h"
using namespace std;

// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementable Transaction class that holds information about different transactions including
// Rent, Borrow, Buy etc. In future this class can be used for hold attributes associated with a transaction
// such as rental due date, rental price etc.
// --------------------------------------------------------------------------------------------------------------------
// Customer class holds reference to latest transaction associated with it in the attribute Head.
// Each transaction holds reference to the next transaction. This will support the chronological display
// of all transactions associated with the customer.
// --------------------------------------------------------------------------------------------------------------------

class transaction
{
private:
	string transactiontype; //will hold value values of the type of transaction such as Borrow, Return, Buy etc.
	transaction* next; //reference to the next transaction in the list of transactions associated to a customer
	Movie* m; //Pointer to the Movie object associated with the transaction
	//string transactionDate; //can be used in future to hold the transaction date when the transaction happened
	//string due date can be used in future to set attributes such as due date of borrow transaction

public:
	//------------------------------------Transaction-----------------------------------------------
	// Description: Transaction constructor, initializes with transaction type
	//----------------------------------------------------------------------------------------------
	transaction(char transactiontype, Movie* m);
	//------------------------------------Transaction-----------------------------------------------
	// Description: Destructor for transaction object
	//----------------------------------------------------------------------------------------------
	~transaction();
	//------------------------------------settransactiontype----------------------------------------
	// Description: setter for transaction type
	//----------------------------------------------------------------------------------------------
	void settransactiontype(char transactiontype);
	//------------------------------------setnexttransaction----------------------------------------
	// Description: setter for next transaction for a given transaction in the list
	//----------------------------------------------------------------------------------------------
	void setnext(transaction* next);
	//------------------------------------gettransactiontype----------------------------------------
	// Description: getter for transaction type for a transaction
	//----------------------------------------------------------------------------------------------
	string gettransactiontype();
	//------------------------------------getnexttransaction----------------------------------------
	// Description: getter for transaction next transaction from the transaction list
	//----------------------------------------------------------------------------------------------
	transaction* getnext();
};




#endif /* TRANSACTION_H_ */
