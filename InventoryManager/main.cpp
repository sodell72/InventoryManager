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
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infileMovies("data4movies.txt");
	if (!infileMovies)
	{
		cout << "File could not be opened." << endl;
		return 1;
	}

	Store s1;

	s1.displaystoremovies();
	cout << "TESTING addstorecustomers:" << endl;
	s1.addstorecustomers(infileCustomers);
	cout << endl;

	cout << "TESTING displaycustomers:" << endl;
	s1.displaycustomers();
	cout << endl;

	cout << "TESTING addstoremovies:" << endl;
	s1.addstoremovies(infileMovies);
	cout << endl;

	cout << "TESTING displaystoremovies:" << endl;
	s1.displaystoremovies();
	cout << endl;

	cout << "TESTING Borrow:" << endl;
	string testborrow1 = "B 8000 D F You've Got Mail, 1998";
	string testborrow2 = "B 1000 D D Barry Levinson, Good Morning Vietnam,";
	/*string testborrow3 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow4 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow5 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow6 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow7 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow8 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow9 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow10 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow11 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow12 = "B 1000 D C 5 1940 Katherine Hepburn";
	string testborrow13 = "B 1000 D C 5 1940 Katherine Hepburn";*/
	s1.performCommand(testborrow1);
	s1.performCommand(testborrow2);
	/*s1.performCommand(testborrow3);
	s1.performCommand(testborrow4);
	s1.performCommand(testborrow5);
	s1.performCommand(testborrow6);
	s1.performCommand(testborrow7);
	s1.performCommand(testborrow8);
	s1.performCommand(testborrow9);
	s1.performCommand(testborrow10);
	s1.performCommand(testborrow11);
	s1.performCommand(testborrow12);
	s1.performCommand(testborrow13);*/

	cout << "TESTING displaystoremovies:" << endl;
	s1.displaystoremovies();

	cout << "TESTING Return:" << endl;
	string testreturn1 = "R 8000 D F You've Got Mail, 1998";
	string testreturn2 = "R 1000 D D Barry Levinson, Good Morning Vietnam,";
	string testreturn3 = "R 1000 D C 5 1940 Katherine Hepburn";
	string testreturn4 = "R 5000 D C 3 1971 Ruth Gordon";
	s1.performCommand(testreturn1);
	s1.performCommand(testreturn2);
	s1.performCommand(testreturn3);
	s1.performCommand(testreturn4);
	s1.displaystoremovies();

	/*string testhistory1 = "H 1000";
	string testhistory2 = "H 8000";
	s1.performCommand(testhistory1);
	s1.performCommand(testhistory2);*/


	ifstream infileCommands("data4commands.txt");
	if (!infileCommands)
	{

			return 1;
	}

	//cout << "TESTING performCommand:" << endl;
	//while (!infileCommands.eof())
	//{
	//		string command;
	//}
}



