#pragma once
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"
#include "Customer.h"
#include "Transaction.h"
#include <map>
#include <vector>
#include <string>


class Store
{


private:


	bool validateVideoCode(char videoCode);
	bool validateActionCode(char actionCode);
	bool validateCustomerId(int id);

	bool performBorrowCommand(std::string command);
	bool performReturnCommand(std::string command);
	bool performInventoryCommand(std::string command);
	bool performHistoryCommand(std::string command);



public:

	Store();

	bool performCommand(std::string command);




};