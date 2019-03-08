#include "ClassicMovie.h"

ClassicMovie::ClassicMovie(std::string classicMovieData) : Movie(classicMovieData)
{
}

ClassicMovie::~ClassicMovie()
{
}

void ClassicMovie::setMajorActorName(std::string majorActorName)
{
	this->majorActorName = majorActorName;
}

void ClassicMovie::setReleaseMonth(std::string releaseMonth)
{
	this->releaseMonth = releaseMonth;
}

void ClassicMovie::setReleaseYear(std::string releaseYear)
{
	this->releaseYear = releaseYear;
}

std::string ClassicMovie::getMajorActorName() const
{
	return this->majorActorName;
}

std::string ClassicMovie::getReleaseMonth() const
{
	return this->releaseMonth;
}

std::string ClassicMovie::getReleaseYear() const
{
	return this->releaseYear;
}

std::string ClassicMovie::getReleaseDate() const
{
	return this->getReleaseMonth + " " + this->getReleaseYear;
}

void ClassicMovie::setReleaseDate(std::string releaseDate)
{
	this->releaseDate = releaseDate;
}

bool ClassicMovie::operator==(const ClassicMovie & other) const
{
	return false;
}

bool ClassicMovie::operator<(const ClassicMovie & other) const
{
	if (this->getReleaseDate == other.getReleaseDate())
	{
		return this->getMajorActorName() < other.getMajorActorName();
	}
	if (this->getReleaseYear() == other.getReleaseYear())
	{
		return std::stoi(this->getReleaseMonth()) < std::stoi(other.getReleaseMonth());

	}
	return std::stoi(this->getReleaseYear()) < std::stoi(other.getReleaseYear());
}
