#pragma once
#include "Media.h"
#include "Movie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "ClassicMovie.h"
#include "Customer.h"
#include "transaction.h"
#include <map>
#include <vector>
#include <string>
#include <regex>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

const int ARRAYMAX = 97; //Prime Number for Hashing

class Store
{

public:

	// ------------------------------------Store-----------------------------------------------
	// Description: constructor, initializes values to null
	// ---------------------------------------------------------------------------------------------------
	Store();

	// ------------------------------------~Store-----------------------------------------------
	// Description: destructor, destroys dynamically allocated Store object, deletes all dynamically allocated
	// objects contained within the Store object too (Transaction, Movie, Customer)
	// ---------------------------------------------------------------------------------------------------
	~Store();

	// ------------------------------------executestorecommands-----------------------------------------------
	// Description: takes commands file parses it and passes it to the execute command function
	// ---------------------------------------------------------------------------------------------------
	void executestorecommands(ifstream& infileCommands);

	// ------------------------------------addstorecustomers-----------------------------------------------
	// Description: takes customer file parses it and creates appropriate customer objects
	// ---------------------------------------------------------------------------------------------------
	void addstorecustomers(ifstream& customerinfile);

	// ------------------------------------addstoremovies-----------------------------------------------
	// Description: takes movie file parses it and creates appropriate movie files and initializes inventory counts
	// places movienodes in correct location in the correct sorted tree
	// ---------------------------------------------------------------------------------------------------
	void addstoremovies(ifstream& movieinfile);

	// ------------------------------------displaycustomers-----------------------------------------------
	// Description: dispays customers
	// ---------------------------------------------------------------------------------------------------
	void displaycustomers();  //test method for testing

	// ------------------------------------displaystoremovies-----------------------------------------------
	// Description: dispays movies contained in store
	// ---------------------------------------------------------------------------------------------------
	void displaystoremovies();

private:

	//vector of pairs containing customer ID and pointer to customer object
	vector<pair<int,Customer*>> storecustomers;

	unordered_set<char> validMovieCodes = { 'C', 'D', 'F' };
	
	// Movies hashed, placed into an index based on their hashed value.  Then stores pointer to the movie 
	// object in the array index location or next available index  (implements closed hashing)
	ComedyMovie* comedyhash[ARRAYMAX]; // contains hashed list of comedyMovies
	DramaMovie* dramahash[ARRAYMAX];  // contains hashed list of dramaMovies
	ClassicMovie* classichash[ARRAYMAX];  // contains hashed list of classicMovies

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

	// ------------------------------------validateMovieCode-----------------------------------------------
	// Description: validates movie code is one of approved movie codes
	// ---------------------------------------------------------------------------------------------------
	bool validateMovieCode(char videoCode);

	// ------------------------------------validateActionCode-----------------------------------------------
	// Description: validates action code is one of approved action codes
	// ---------------------------------------------------------------------------------------------------
	bool validateActionCode(char actionCode);

	// ------------------------------------validateCustomerId-----------------------------------------------
	// Description: validates customer id associated with command is a valid customer
	// ---------------------------------------------------------------------------------------------------
	bool validateCustomerId(int id);

	Movie* moviefoundininventory(char moviecode,string moviedetails);
	Movie* moviefoundinhashtable(char moviecode, string moviedetails);
	void insertcomedyhashtable(string moviedetails, ComedyMovie *comedymovie);
	void insertclassichashtable(string moviedetails, ClassicMovie* classicmovie);
	void insertdramahashtable(string moviedetails, DramaMovie* dramamovie);
	vector<string> parsemoviedetails(string moviedetails);
	vector<string> parsecommanddetails(string command);
	Customer* fetchcustomerobject(int customerid);
	bool validateifcustomerborrowedtheitem(Customer* cust,Movie* moviereturn);

	// ------------------------------------performBorrowCommand-----------------------------------------------
	// Description: performs borrow command.  updates inventory and customer transactions
	// ---------------------------------------------------------------------------------------------------
	bool performBorrowCommand(string command);

	// ------------------------------------performReturnCommand-----------------------------------------------
	// Description: performs return command.  updates inventory and customer transactions
	// ---------------------------------------------------------------------------------------------------
	bool performReturnCommand(string command);

	// ------------------------------------performInventoryCommand-----------------------------------------------
	// Description: displays inventory
	// ---------------------------------------------------------------------------------------------------
	bool performInventoryCommand(string command);

	// ------------------------------------performHistoryCommand-----------------------------------------------
	// Description: displays given customer's transaction history
	// ---------------------------------------------------------------------------------------------------
	bool performHistoryCommand(string command);

	// ------------------------------------performCommand-----------------------------------------------
	// Description: takes command and passes it on the the correct perform***command function
	// ---------------------------------------------------------------------------------------------------
	bool performCommand(std::string command);

	// ------------------------------------displaystorestree-----------------------------------------------
	// Description: displays movie details of each item in the store's given tree
	// ---------------------------------------------------------------------------------------------------
	void displaystorestree(movienode* head);

	// ------------------------------------hashfunction-----------------------------------------------
	// Description: hashes movie object
	// ---------------------------------------------------------------------------------------------------
	int hashfunction(string moviedetails);

	// ------------------------------------updateinventorycounts-----------------------------------------------
	// Description: updates given movie's inventory count, passes functionality on to recursiveupdate function
	// ---------------------------------------------------------------------------------------------------
	bool updateinventorycounts(char moviecode, Movie* m,int v);

	// ------------------------------------recursiveupdate-----------------------------------------------
	// Description: updates given movie's inventory count
	// ---------------------------------------------------------------------------------------------------
	void recursiveupdate(char moviecode, movienode* mnode,Movie* movieininventory,int value);

	// ------------------------------------trim-----------------------------------------------
	// Description: trims whitespace
	// ---------------------------------------------------------------------------------------------------
	std::string trim(const std::string& input);

	// ------------------------------------deleteSubTree-----------------------------------------------
	// Description: deletes all items in a given subtree, given the head of the subtree movienode.
	// ---------------------------------------------------------------------------------------------------
	void deleteSubTree(movienode* subTreeTop);


};
