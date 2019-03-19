#include "ComedyMovie.h"

// ------------------------------------CommedyMovie-----------------------------------------------
// Description: constructor, initializes values based on movie info
// ---------------------------------------------------------------------------------------------------
ComedyMovie::ComedyMovie(std::string comedyMovieData) : Movie()
{
	std::vector<std::string> vec;
	std::stringstream ss(comedyMovieData);
	std::string token;
	while (std::getline(ss, token, ','))
 	{
		token = trim(token);
		vec.push_back(token);
	}
	if (vec.size() != 3)
	{
		throw std::invalid_argument("Comedy movie data should contain director, title, and releaseDate") ;
	}

	this->setDirector(vec[0]);
	this->setTitle(vec[1]);
	this->setReleaseDate(vec[2]);
}

// ------------------------------------~CommedyMovie-----------------------------------------------
// Description: destructor, destroys dynamically allocated ComedyMovie object
// ---------------------------------------------------------------------------------------------------
ComedyMovie::~ComedyMovie()
{
}

// ------------------------------------==-----------------------------------------------
// Description: performs equality comparison
// ---------------------------------------------------------------------------------------------------
bool ComedyMovie::operator==(const ComedyMovie & other) const
{
	if (this == &other)
		return true;
	else if (this->getTitle() == other.getTitle() && this->getReleaseDate() == other.getReleaseDate())
		return true;
	else
	    return false;
}

// ------------------------------------<-----------------------------------------------
// Description: performs less than comparison
// ---------------------------------------------------------------------------------------------------
bool ComedyMovie::operator<(const ComedyMovie & other) const
{
	if (this->getTitle() == other.getTitle())
	{
		return std::stoi(this->getReleaseDate()) < std::stoi(other.getReleaseDate());
	}
	return this->getTitle() < other.getTitle();
}

// ------------------------------------<<-----------------------------------------------
// Description: performs << overload to print to console
// ---------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & out, const ComedyMovie & comedyMovie)
{
	out << "Comedy" << " ";
	out << comedyMovie.getTitle() << " ";
	out << comedyMovie.getReleaseDate() << " ";
	//out << "DISTRIBUTION TYPE: " << comedyMovie.getDistributionType() << " ";
	//out << "DIRECTOR: " << comedyMovie.getDirector() << std::endl;
	return out;
}
