#include "Movie.h"

Movie::Movie() : Media()
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
