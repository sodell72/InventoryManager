// ------------------------------------------------ ComedyMovie.h -------------------------------------------------------
// Sean O'Dell, CSS 502A
// Creation Date: 02/24/2019
// Date of Last Modification: 2/26/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementable movie class that holds information about commedy movies
// --------------------------------------------------------------------------------------------------------------------
// Subclass of Media, and Movie which provide shared parameters that are available in all media and movie types 
// respectively.  CommedyMovie class stores and allows access to information about a commedy movie.
// --------------------------------------------------------------------------------------------------------------------
#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H
#include "Movie.h"

class ComedyMovie : public Movie
{

	// ------------------------------------<<-----------------------------------------------
	// Description: performs << overload to print to console
	// ---------------------------------------------------------------------------------------------------
	friend std::ostream & operator<<(std::ostream & out, const ComedyMovie& comedyMovie);

private:


public:

	// ------------------------------------CommedyMovie-----------------------------------------------
	// Description: constructor, initializes values based on movie info
	// ---------------------------------------------------------------------------------------------------
	ComedyMovie(std::string comedyMovieData);

	// ------------------------------------~CommedyMovie-----------------------------------------------
	// Description: destructor, destroys dynamically allocated ComedyMovie object
	// ---------------------------------------------------------------------------------------------------
	~ComedyMovie();

	// ------------------------------------==-----------------------------------------------
	// Description: performs equality comparison
	// ---------------------------------------------------------------------------------------------------
	virtual bool operator==(const ComedyMovie & other) const;

	// ------------------------------------<-----------------------------------------------
	// Description: performs less than comparison
	// ---------------------------------------------------------------------------------------------------
	virtual bool operator<(const ComedyMovie& other) const;
};
#endif