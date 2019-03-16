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

	// test << for ClassicMovie
	cout << cMovie1;

	cout << "end test" << endl;

	//ifstream infileCustomers("data4customers.txt");
	//if (!infileCustomers)
	//{
	//	cout << "Customers file could not be opened." << endl;
	//	return 1;
	//}
	//ifstream infileMovies("data4movies.txt");
	//if (!infileMovies)
	//{
	//	cout << "Movies file could not be opened." << endl;
	//	return 1;
	//}
	//ifstream infileCommands("data4commands.txt");
	//if (!infileCommands)
	//{
	//	cout << "Commands file could not be opened." << endl;
	//	return 1;
	//}

	//Store myStore(infileCustomers, infileMovies);
	//while (!infileCommands.eof())
	//{
	//	string command;
	//	getline(infileCommands, command);
	//	myStore.performCommand(command);
	//}

	cin.get();
}