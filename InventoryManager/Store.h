#pragma once
#include "Media.h"
#include "Movie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"
#include "Customer.h"
#include "Transaction.h"
#include <map>
#include <vector>
#include <string>
#include <regex>
#include <unordered_set>
#include <iostream>
#include <fstream>
using namespace std;

const int ARRAYMAX = 97; //Prime Number for Hashing

class Store
{

public:
	Store();
	~Store();
	bool performCommand(std::string command);
	void addstorecustomers(ifstream& customerinfile);
	void addstoremovies(ifstream& movieinfile);
	void displaycustomers();  //test method for testing
	void displaystoremovies();

private:

	//vector of pairs containing customer ID and pointer to customer object
	vector<pair<int,Customer*>> storecustomers;

	unordered_set<char> validMovieCodes = { 'C', 'D', 'F' };

	ComedyMovie* comedyhash[ARRAYMAX];
	DramaMovie* dramahash[ARRAYMAX];
	ClassicMovie* classichash[ARRAYMAX];

	struct movienode
	{
		char movietype;
		int inventorycount;
		Movie* moviedetails;
		movienode* left;
		movienode* right;
	};

	movienode* comedymoviehead;
	movienode* dramamoviehead;
	movienode* classicmoviehead;


	void addtotree(movienode* &root, movienode* &m);
	bool validateMovieCode(char videoCode);
	bool validateActionCode(char actionCode);
	bool validateCustomerId(int id);
	bool movieFound(char moviecode,string moviedetails);

	bool performBorrowCommand(string command);
	bool performReturnCommand(string command);
	bool performInventoryCommand(string command);
	bool performHistoryCommand(string command);

	void displaystorestree(movienode* head);
	void comedymoviehash(string moviedetails);
	int hashfunction(string moviedetails);



};
