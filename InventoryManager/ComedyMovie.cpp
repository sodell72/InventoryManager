#include "ComedyMovie.h"

ComedyMovie::ComedyMovie(std::string comedyMovieData) : Movie(comedyMovieData)
{
}

ComedyMovie::~ComedyMovie()
{
}

bool ComedyMovie::operator==(const ComedyMovie & other) const
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

bool ComedyMovie::operator<(const ComedyMovie & other) const
{
	if (this->getTitle() == other.getTitle())
	{
		return std::stoi(this->getReleaseDate) < std::stoi(other.releaseDate);
	}
	return this->getTitle() < other.getTitle();
}
