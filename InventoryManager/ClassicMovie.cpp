#include "ClassicMovie.h"

// ------------------------------------ClassicMovie-----------------------------------------------
// Description: constructor, initializes values based on movie info
// ---------------------------------------------------------------------------------------------------
ClassicMovie::ClassicMovie(std::string classicMovieData) : Movie()
{
	std::vector<std::string> vec;
	std::stringstream ss(classicMovieData);
	std::string token;
	while (std::getline(ss, token, ','))
	{
		token = trim(token);
		vec.push_back(token);
	}
	if (vec.size() != 3)
	{
		throw std::invalid_argument("Comedy movie data should contain director, title, and majorActor/releaseDate");
	}

	this->setDirector(vec[0]);
	this->setTitle(vec[1]);
	
	std::vector<std::string> vec2;
	std::stringstream ss2(vec[2]);
	while (std::getline(ss2, token, ' '))
	{
		token = trim(token);
		vec2.push_back(token);
	}
	int size = vec2.size();
	this->setReleaseYear(vec2[size - 1]);
	this->setReleaseMonth(vec2[size - 2]);
	std::string majorActor = "";
	for (int i = 0; i < size - 2; i++)
	{
		majorActor = majorActor + vec2[i] + " ";
	}
	trim(majorActor);
	this->setMajorActorName(majorActor);
	this->setReleaseDate(this->getReleaseMonth() + " " + this->getReleaseYear());
}

// ------------------------------------~ClassicMovie-----------------------------------------------
// Description: destructor, destroys dynamically allocated ClassicMovie object
// ---------------------------------------------------------------------------------------------------
ClassicMovie::~ClassicMovie()
{
}

// ------------------------------------setMajorActorName-----------------------------------------------
// Description: setter for majorActorName
// ---------------------------------------------------------------------------------------------------
void ClassicMovie::setMajorActorName(std::string majorActorName)
{
	this->majorActorName = majorActorName;
}

// ------------------------------------setReleaseMonth-----------------------------------------------
// Description: setter for releaseMonth
// ---------------------------------------------------------------------------------------------------
void ClassicMovie::setReleaseMonth(std::string releaseMonth)
{
	this->releaseMonth = releaseMonth;
}

// ------------------------------------setReleaseYear-----------------------------------------------
// Description: setter for releaseYear
// ---------------------------------------------------------------------------------------------------
void ClassicMovie::setReleaseYear(std::string releaseYear)
{
	this->releaseYear = releaseYear;
}

// ------------------------------------getMajorActorName-----------------------------------------------
// Description: getter for majorActorName
// ---------------------------------------------------------------------------------------------------
std::string ClassicMovie::getMajorActorName() const
{
	return this->majorActorName;
}

// ------------------------------------getReleaseMonth-----------------------------------------------
// Description: getter for releaseMonth
// ---------------------------------------------------------------------------------------------------
std::string ClassicMovie::getReleaseMonth() const
{
	return this->releaseMonth;
}

// ------------------------------------getReleaseYear-----------------------------------------------
// Description: getter for releaseYear
// ---------------------------------------------------------------------------------------------------
std::string ClassicMovie::getReleaseYear() const
{
	return this->releaseYear;
}

// ------------------------------------setReleaseDate-----------------------------------------------
// Description: setter for release date, also sets release month and release year
// ---------------------------------------------------------------------------------------------------
std::string ClassicMovie::getReleaseDate() const
{
	return this->getReleaseMonth() + " " + this->getReleaseYear();
}

// ------------------------------------setReleaseDate-----------------------------------------------
// Description: setter for release date, also sets release month and release year
// ---------------------------------------------------------------------------------------------------
void ClassicMovie::setReleaseDate(std::string releaseDate)
{
	this->releaseDate = releaseDate;
}

// ------------------------------------==-----------------------------------------------
// Description: performs equality comparison
// ---------------------------------------------------------------------------------------------------
bool ClassicMovie::operator==(const ClassicMovie & other) const
{
	if (this == &other)
	{
		return true;
	} else if (this->getTitle() == other.getTitle() &&
		this->getReleaseDate() == other.getReleaseDate() &&
		this->getDistributionType() == other.getDistributionType() &&
		this->getDirector() == other.getDirector() &&
		this->getMajorActorName() == other.getMajorActorName())
	{
		return true;
	}
	return false;
}

// ------------------------------------<-----------------------------------------------
// Description: performs less than comparison
// ---------------------------------------------------------------------------------------------------
bool ClassicMovie::operator<(const ClassicMovie & other) const
{
	if (this->getReleaseDate() == other.getReleaseDate())
	{
		return this->getMajorActorName() < other.getMajorActorName();
	}
	if (this->getReleaseYear() == other.getReleaseYear())
	{
		return std::stoi(this->getReleaseMonth()) < std::stoi(other.getReleaseMonth());

	}
	return std::stoi(this->getReleaseYear()) < std::stoi(other.getReleaseYear());
}

// ------------------------------------<<-----------------------------------------------
// Description: performs << overload to print to console
// ---------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & out, const ClassicMovie & classicMovie)
{
	out << "Classic" << " ";
	//out << "TITLE: " << classicMovie.getTitle() << " ";
	out << classicMovie.getReleaseDate() << " ";
	//out << "DISTRIBUTION TYPE: " << classicMovie.getDistributionType() << " ";
	//out << "DIRECTOR: " << classicMovie.getDirector() << " ";
	out << classicMovie.getMajorActorName();
	return out;
}
