#include "Media.h"


Media::Media(std::string mediaData)
{
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

std::string Media::getReleaseDate() const
{
	return this->releaseDate;
}

std::string Media::getTitle() const
{
	return this->title;
}

char Media::getDistributionType() const
{
	return this->distributionType;
}
