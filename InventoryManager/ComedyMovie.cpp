#include "ComedyMovie.h"

ComedyMovie::ComedyMovie(std::string comedyMovieData) : Movie(comedyMovieData)
{
}

ComedyMovie::~ComedyMovie()
{
}

bool ComedyMovie::operator==(const ComedyMovie & other) const
{
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
