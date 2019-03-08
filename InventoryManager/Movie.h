// ------------------------------------------------ Movie.h -------------------------------------------------------
// Sean O'Dell, CSS 502A
// Creation Date: 02/24/2019
// Date of Last Modification: 2/26/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Abstract class to provide framework for how to store data on movies
// --------------------------------------------------------------------------------------------------------------------
// Subclass of Media, which provides shared parameters that are available in all media types.  Movie class provides
// outline for how to store info specific to a movie.
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Media.h"

class Movie : public Media
{

private:
	std::string director; // stores the director of the Movie's name

public:
	// ------------------------------------Movie-----------------------------------------------
	// Description: constructor, initializes values to default values
	// ---------------------------------------------------------------------------------------------------
	Movie(std::string title, char distributionType, std::string releaseDate, std::string director);

	// ------------------------------------~Movie-----------------------------------------------
	// Description: destructor, destroys dynamically allocated Movie object
	// ---------------------------------------------------------------------------------------------------
	~Movie();

	// ------------------------------------setDirector-----------------------------------------------
	// Description: setter for director
	// ---------------------------------------------------------------------------------------------------
	void setDirector(std::string director);

	// ------------------------------------getDirector-----------------------------------------------
	// Description: getter for director
	// ---------------------------------------------------------------------------------------------------
	std::string getDirector();

};