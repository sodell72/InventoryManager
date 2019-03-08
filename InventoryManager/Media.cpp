#include "Media.h"


Media::Media(std::string title, char distributionType, std::string releaseDate)
{
	setTitle(title);
	setDistributionType(distributionType);
	setReleaseDate(releaseDate);
}

Media::~Media()
{
}

void Media::setTitle(std::string title)
{
	this->title = title;
}

void Media::setDistributionType(char type)
{
	this->distributionType = type;
}

void Media::setReleaseDate(std::string releaseDate)
{
	this->releaseDate = releaseDate;
}

std::string Media::getReleaseDate()
{
	return this->releaseDate;
}

std::string Media::getTitle()
{
	return this->title;
}

char Media::getDistributionType()
{
	return this->distributionType;
}
