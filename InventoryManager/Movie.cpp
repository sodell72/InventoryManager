#include "Movie.h"

Movie::Movie(std::string title, char distributionType, std::string releaseDate, std::string director) : Media(title, distributionType, releaseDate)
{
	setDirector(director);
}

Movie::~Movie()
{
}

void Movie::setDirector(std::string director)
{
	this->director = director;
}

std::string Movie::getDirector()
{
	return this->director;
}
