// ------------------------------------------------ ClassicMovie.h -------------------------------------------------------
// Sean O'Dell, CSS 502A
// Creation Date: 02/24/2019
// Date of Last Modification: 2/26/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementable movie class that holds information about classic movies
// --------------------------------------------------------------------------------------------------------------------
// Subclass of Media, and Movie which provide shared parameters that are available in all media and movie types 
// respectively.  ClassicMovie class stores and allows access to information about a classic movie.
// --------------------------------------------------------------------------------------------------------------------
#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H
#include "Movie.h"

class ClassicMovie : public Movie
{

	// ------------------------------------<<-----------------------------------------------
	// Description: performs << overload to print to console
	// ---------------------------------------------------------------------------------------------------
	friend std::ostream & operator<<(std::ostream & out, const ClassicMovie& classicMovie);

private:

	std::string majorActorName; // stores the major Actor's from the classic movie
	std::string releaseMonth; // stores the release month of the classic movie
	std::string releaseYear; // stores the release year of the classic movie

	std::vector<std::string> majorActors;

public:
	// ------------------------------------ClassicMovie-----------------------------------------------
	// Description: constructor, initializes values based on movie info
	// ---------------------------------------------------------------------------------------------------
	ClassicMovie(std::string classicMovieData);

	// ------------------------------------~ClassicMovie-----------------------------------------------
	// Description: destructor, destroys dynamically allocated ClassicMovie object
	// ---------------------------------------------------------------------------------------------------
	~ClassicMovie();

	// ------------------------------------setMajorActorName-----------------------------------------------
	// Description: setter for majorActorName
	// ---------------------------------------------------------------------------------------------------
	void setMajorActorName(std::string majorActorName);

	// ------------------------------------setReleaseMonth-----------------------------------------------
	// Description: setter for releaseMonth
	// ---------------------------------------------------------------------------------------------------
	void setReleaseMonth(std::string releaseMonth);

	// ------------------------------------setReleaseYear-----------------------------------------------
	// Description: setter for releaseYear
	// ---------------------------------------------------------------------------------------------------
	void setReleaseYear(std::string releaseYear);

	// ------------------------------------setReleaseDate-----------------------------------------------
	// Description: setter for release date, also sets release month and release year
	// ---------------------------------------------------------------------------------------------------
	void setReleaseDate(std::string releaseDate) override;

	// ------------------------------------getMajorActorName-----------------------------------------------
	// Description: getter for majorActorName
	// ---------------------------------------------------------------------------------------------------
	std::string getMajorActorName() const;

	// ------------------------------------getReleaseMonth-----------------------------------------------
	// Description: getter for releaseMonth
	// ---------------------------------------------------------------------------------------------------
	std::string getReleaseMonth() const;

	// ------------------------------------getReleaseYear-----------------------------------------------
	// Description: getter for releaseYear
	// ---------------------------------------------------------------------------------------------------
	std::string getReleaseYear() const;

	// ------------------------------------getReleaseDate-----------------------------------------------
	// Description: getter for releaseDate, overrides parent function, combines release month and year to
	// provide a release date.
	// ---------------------------------------------------------------------------------------------------
	virtual std::string getReleaseDate() const override;

	// ------------------------------------==-----------------------------------------------
	// Description: performs equality comparison
	// ---------------------------------------------------------------------------------------------------
	virtual bool operator==(const ClassicMovie& other) const;

	// ------------------------------------<-----------------------------------------------
	// Description: performs less than comparison
	// ---------------------------------------------------------------------------------------------------
	virtual bool operator<(const ClassicMovie& other) const;

	// ------------------------------------containsMajorActor-----------------------------------------------
	// Description: determines if ClassicMovie object already recognizes given actor as major actor
	// ---------------------------------------------------------------------------------------------------
	bool containsMajorActor(std::string actor);

	// ------------------------------------getMajorActors-----------------------------------------------
	// Description: returns all major actors for this classic movie
	// ---------------------------------------------------------------------------------------------------
	std::vector<std::string> getMajorActors();

	// ------------------------------------addMajorActor-----------------------------------------------
	// Description: adds major actor to list of recognized major actors
	// ---------------------------------------------------------------------------------------------------
	void addMajorActor(std::string actor);
};
#endif

//give major actor, check if it's contained
//get major actor, returns vector os strings
// add major actor string