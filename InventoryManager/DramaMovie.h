// ------------------------------------------------ DramaMovie.h -------------------------------------------------------
// Sean O'Dell, CSS 502A
// Creation Date: 02/24/2019
// Date of Last Modification: 2/26/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementable movie class that holds information about drama movies
// --------------------------------------------------------------------------------------------------------------------
// Subclass of Media, and Movie which provide shared parameters that are available in all media and movie types 
// respectively. DramaMovie class stores and allows access to information about a drama movie.
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Movie.h"

class DramaMovie : public Movie
{
	friend std::ostream & operator<<(std::ostream & out, const DramaMovie& dramaMovie);

private:

public:
	// ------------------------------------DramaMovie-----------------------------------------------
	// Description: constructor, initializes values based on movie info
	// ---------------------------------------------------------------------------------------------------
	DramaMovie(std::string dramaMovieData);

	// ------------------------------------~DramaMovie-----------------------------------------------
	// Description: destructor, destroys dynamically allocated DramaMovie object
	// ---------------------------------------------------------------------------------------------------
	~DramaMovie();

	// ------------------------------------==-----------------------------------------------
	// Description: performs equality comparison
	// ---------------------------------------------------------------------------------------------------
	virtual bool operator==(const DramaMovie & other) const;

	// ------------------------------------<-----------------------------------------------
	// Description: performs less than comparison
	// ---------------------------------------------------------------------------------------------------
	virtual bool operator<(const DramaMovie& other) const;

	// ------------------------------------hash-----------------------------------------------
	// Description: hashing function, takes in object ID and outputs index
	// ---------------------------------------------------------------------------------------------------
	//virtual int hash(int ID);
};
