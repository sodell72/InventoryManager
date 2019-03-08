#include "DramaMovie.h"

DramaMovie::DramaMovie(std::string dramaMovieData) : Movie(dramaMovieData)
{
}

DramaMovie::~DramaMovie()
{
}

bool DramaMovie::operator==(const DramaMovie & other) const
{
	return false;
}

bool DramaMovie::operator<(const DramaMovie & other) const
{
	if (this->getDirector() == other.getDirector())
	{
		return this->getTitle() < other.getTitle();
	}
	return this->getDirector() < other.getDirector();
}
