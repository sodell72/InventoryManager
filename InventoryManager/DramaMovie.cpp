#include "DramaMovie.h"

// ------------------------------------DramaMovie-----------------------------------------------
// Description: constructor, initializes values based on movie info
// ---------------------------------------------------------------------------------------------------
DramaMovie::DramaMovie(std::string dramaMovieData) : Movie()
{
	std::vector<std::string> vec;
	std::stringstream ss(dramaMovieData);
	std::string token;
	while (std::getline(ss, token, ','))
	{
		token = trim(token);
		vec.push_back(token);
	}
	if (vec.size() != 3)
	{
		throw std::invalid_argument("Drama movie data should contain director, title, and releaseDate");
	}

	this->setDirector(vec[0]);
	this->setTitle(vec[1]);
	this->setReleaseDate(vec[2]);
}

// ------------------------------------~DramaMovie-----------------------------------------------
// Description: destructor, destroys dynamically allocated DramaMovie object
// ---------------------------------------------------------------------------------------------------
DramaMovie::~DramaMovie()
{
}

// ------------------------------------==-----------------------------------------------
// Description: performs equality comparison
// ---------------------------------------------------------------------------------------------------
bool DramaMovie::operator==(const DramaMovie & other) const
{
	if (this == &other)
	{
		return true;
	} else if (this->getTitle() == other.getTitle() &&
		this->getReleaseDate() == other.getReleaseDate() &&
		this->getDistributionType() == other.getDistributionType() &&
		this->getDirector() == other.getDirector())
	{
		return true;
	}
	return false;
}

// ------------------------------------<-----------------------------------------------
// Description: performs less than comparison
// ---------------------------------------------------------------------------------------------------
bool DramaMovie::operator<(const DramaMovie & other) const
{
	if (this->getDirector() == other.getDirector())
	{
		return this->getTitle() < other.getTitle();
	}
	return this->getDirector() < other.getDirector();
}

// ------------------------------------<<-----------------------------------------------
// Description: performs << overload to print to console
// ---------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & out, const DramaMovie & dramaMovie)
{
	out << "Drama" << " ";
	out << dramaMovie.getDirector() << "  ";
	out << dramaMovie.getTitle() << " ";
	//out << "RELEASE DATE: " << dramaMovie.getReleaseDate() << " ";
	//out << "DISTRIBUTION TYPE: " << dramaMovie.getDistributionType() << " ";

	return out;
}
