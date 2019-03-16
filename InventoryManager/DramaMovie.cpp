#include "DramaMovie.h"

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

DramaMovie::~DramaMovie()
{
}

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

bool DramaMovie::operator<(const DramaMovie & other) const
{
	if (this->getDirector() == other.getDirector())
	{
		return this->getTitle() < other.getTitle();
	}
	return this->getDirector() < other.getDirector();
}

std::ostream & operator<<(std::ostream & out, const DramaMovie & dramaMovie)
{
	out << "genre: drama" << std::endl;
	out << "title: " << dramaMovie.getTitle() << std::endl;
	out << "release date: " << dramaMovie.getReleaseDate() << std::endl;
	out << "distribution type: " << dramaMovie.getDistributionType() << std::endl;
	out << "director: " << dramaMovie.getDirector() << std::endl;
	return out;
}
