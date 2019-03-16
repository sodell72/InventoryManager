#include "ComedyMovie.h"

ComedyMovie::ComedyMovie(std::string comedyMovieData) : Movie()
{
	std::vector<std::string> vec;
	std::stringstream ss(comedyMovieData);
	std::string token;
	while (std::getline(ss, token, ','))
 	{
		token = trim(token);
		vec.push_back(token);
	}
	if (vec.size() != 3)
	{
		throw std::invalid_argument("Comedy movie data should contain director, title, and releaseDate") ;
	}

	this->setDirector(vec[0]);
	this->setTitle(vec[1]);
	this->setReleaseDate(vec[2]);
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
		return std::stoi(this->getReleaseDate()) < std::stoi(other.getReleaseDate());
	}
	return this->getTitle() < other.getTitle();
}

std::ostream & operator<<(std::ostream & out, const ComedyMovie & comedyMovie)
{
	out << "genre: comedy" << std::endl;
	out << "title: " << comedyMovie.getTitle() << std::endl;
	out << "release date: " << comedyMovie.getReleaseDate() << std::endl;
	out << "distribution type: " << comedyMovie.getDistributionType() << std::endl;
	out << "director: " << comedyMovie.getDirector() << std::endl;
	return out;
}