#include "Media.h"


Media::Media()
{
	this->setDistributionType('D');
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

std::string Media::trim(const std::string& input)
{
	if (input.empty()) return ""; // return empty string if all spaces

	size_t front = 0; // tracks front index
	size_t back = input.size() - 1; // tracks back index

	while (front < back && isspace(input[front])) front++;
	while (front < back && isspace(input[back])) back--;
	return std::string(input, front, back + 1);
}
