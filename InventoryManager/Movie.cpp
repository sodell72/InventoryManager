#include "Movie.h"

// ------------------------------------Movie-----------------------------------------------
// Description: constructor, initializes values to default values
// ---------------------------------------------------------------------------------------------------
Movie::Movie() : Media()
{
}

// ------------------------------------~Movie-----------------------------------------------
// Description: destructor, destroys dynamically allocated Movie object
// ---------------------------------------------------------------------------------------------------
Movie::~Movie()
{
}

// ------------------------------------setDirector-----------------------------------------------
// Description: setter for director
// ---------------------------------------------------------------------------------------------------
void Movie::setDirector(std::string director)
{
	this->director = director;
}

// ------------------------------------getDirector-----------------------------------------------
// Description: getter for director
// ---------------------------------------------------------------------------------------------------
std::string Movie::getDirector() const
{
	return this->director;
}
