#include "Movie.h"

Movie::Movie(std::string movieData) : Media(movieData)
{
}

Movie::~Movie()
{
}

void Movie::setDirector(std::string director)
{
	this->director = director;
}

std::string Movie::getDirector() const
{
	return this->director;
}
