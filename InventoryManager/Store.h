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
	Movie* moviefoundininventory(char moviecode,string moviedetails);
	Movie* moviefoundinhashtable(char moviecode, string moviedetails);
	void insertcomedyhashtable(string moviedetails, ComedyMovie *comedymovie);
	void insertclassichashtable(string moviedetails, ClassicMovie* classicmovie);
	void insertdramahashtable(string moviedetails, DramaMovie* dramamovie);
	vector<string> parsemoviedetails(string moviedetails);
	vector<string> parsecommanddetails(string command);
	Customer* fetchcustomerobject(int customerid);
	bool validateifcustomerborrowedtheitem(Customer* cust,Movie* moviereturn);

	bool performBorrowCommand(string command);
	bool performReturnCommand(string command);
	bool performInventoryCommand(string command);
	bool performHistoryCommand(string command);

	void displaystorestree(movienode* head);
	void comedymoviehash(string moviedetails);
	int hashfunction(string moviedetails);
	bool updateinventorycounts(char moviecode, Movie* m,int v);
	void recursiveupdate(char moviecode, movienode* mnode,Movie* movieininventory,int value);

	std::string trim(const std::string& input);

	void deleteSubTree(movienode* subTreeTop);


};
