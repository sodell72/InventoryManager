// ------------------------------------------------ main.cpp -------------------------------------------------------
// Sean O'Dell, CSS 502A
// Creation Date: 02/24/2019
// Date of Last Modification: 2/26/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Main method for executing inventory program and testing functionality.
// --------------------------------------------------------------------------------------------------------------------
// creates objects with given input text files
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Store.h"
#include "Media.h"
#include "Movie.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"
#include "ComedyMovie.h"
#include "Customer.h"
#include "Transaction.h"

using namespace std;

int main(int argc, const char* argv[])
{
	/*
	// test Comedy Movie
	string comedyMovieData = "Nora Ephron, Sleepless in Seattle, 1993";
	ComedyMovie fMovie1(comedyMovieData);
	cout << "input string to fMovie1: " << comedyMovieData << endl;
	cout << "fMovie1 contents after construction: " << endl;
	cout << "distribution Type: " << fMovie1.getDistributionType() << ", director: " << fMovie1.getDirector() << ", title: " << fMovie1.getTitle() << ", releaseDate: " << fMovie1.getReleaseDate() << endl;
	cout << endl;

	// test ClassicMovie
	string classicMovieData = "Michael Curtiz, Casablanca, Ingrid Bergman 8 1942";
	ClassicMovie cMovie1(classicMovieData);
	cout << "input string to cMovie1: " << classicMovieData << endl;
	cout << "cMovie1 contents after construction: " << endl;
	cout << "distribution Type: " << cMovie1.getDistributionType() << ", director: " << cMovie1.getDirector() << ", title: " << cMovie1.getTitle() << ", releaseDate: " << cMovie1.getReleaseDate() << 
		", majorActor: " << cMovie1.getMajorActorName() << ", releaseMonth: " << cMovie1.getReleaseMonth() << ", releaseYear: " << cMovie1.getReleaseYear() << endl;
	cout << endl;

	cout << "end test" << endl;

	*/

	// part 1
	ifstream infileCustomers("data4customers.txt");
	if (!infileCustomers)
	{
		cout << "Customers file could not be opened." << endl;
		return 1;
	}
	ifstream infileMovies("data4movies.txt");
	if (!infileMovies)
	{
		cout << "Movies file could not be opened." << endl;
		return 1;
	}

	Store s1;

	s1.addstorecustomers(infileCustomers);
	s1.displaycustomers();
	s1.addstoremovies(infileMovies);
	s1.displaystoremovies();

	ifstream infileCommands("data4commands.txt");
	if (!infileCommands)
	{
		cout << "Commands file could not be opened." << endl;
		return 1;
	}

	while (!infileCommands.eof())
	{
		string command;
		getline(infileCommands, command);
		s1.performCommand(command);
	}

	cin.get();
}
