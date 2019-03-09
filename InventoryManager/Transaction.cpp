/*
 * transaction.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: vismohan
 */
#include "transaction.h"
//------------------------------------Transaction-----------------------------------------------
// Description: Transaction constructor, initializes with transactiontype and Movie
//----------------------------------------------------------------------------------------------
transaction::transaction(string transactiontype, Movie* m)
{
	this->settransactiontype(transactiontype);
	this->m = m;
}
//------------------------------------Transaction-----------------------------------------------
// Description: Destructor for transaction object
//----------------------------------------------------------------------------------------------
transaction::~transaction()
{

}
//------------------------------------settransactiontype----------------------------------------
// Description: setter for transactiontype
//----------------------------------------------------------------------------------------------
void transaction::settransactiontype(string transactiontype)
{
	if (transactiontype == 'B' || transactiontype == 'R')
		this->transactiontype = transactiontype;
}
//------------------------------------settransactiontype----------------------------------------
// Description: setter for next transaction for a given transaction in the list
//----------------------------------------------------------------------------------------------
void transaction::setnext(transaction* next)
{
	this->next = next;
}
//------------------------------------settransactiondate----------------------------------------
// Description: getter for transaction type for a transaction
//----------------------------------------------------------------------------------------------
string transaction::gettransactiontype()
{
	return this->transactiontype;
}
//------------------------------------settransactiondate----------------------------------------
// Description: getter for transaction next transaction from the transaction list
//----------------------------------------------------------------------------------------------
transaction* transaction::getnext()
{
	return this->next;
}





