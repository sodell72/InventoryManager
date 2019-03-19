#include "Media.h"

// ------------------------------------Media-----------------------------------------------
// Description: constructor, initializes values to default values
// ---------------------------------------------------------------------------------------------------
Media::Media()
{
	this->setDistributionType('D');
}

// ------------------------------------~Media-----------------------------------------------
// Description: destructor, destroys dynamically allocated Media object
// ---------------------------------------------------------------------------------------------------
Media::~Media()
{
}

// ------------------------------------setTitle-----------------------------------------------
// Description: setter for title
// ---------------------------------------------------------------------------------------------------
void Media::setTitle(std::string title)
{
	this->title = title;
}

// ------------------------------------setDistributionType-----------------------------------------------
// Description: setter for distributionType
// ---------------------------------------------------------------------------------------------------
void Media::setDistributionType(char type)
{
	this->distributionType = type;
}

// ------------------------------------setReleaseDate-----------------------------------------------
// Description: setter for release date
// ---------------------------------------------------------------------------------------------------
void Media::setReleaseDate(std::string releaseDate)
{
	this->releaseDate = releaseDate;
}

// ------------------------------------getReleaseDate-----------------------------------------------
// Description: getter for releaseDate
// ---------------------------------------------------------------------------------------------------
std::string Media::getReleaseDate() const
{
	return this->releaseDate;
}

// ------------------------------------getTitle-----------------------------------------------
// Description: getter for title
// ---------------------------------------------------------------------------------------------------
std::string Media::getTitle() const
{
	return this->title;
}

// ------------------------------------getDistributionType-----------------------------------------------
// Description: getter for distributionType
// ---------------------------------------------------------------------------------------------------
char Media::getDistributionType() const
{
	return this->distributionType;
}

// ------------------------------------trim-----------------------------------------------
// Description: trims whitespace
// ---------------------------------------------------------------------------------------------------
std::string Media::trim(const std::string& input)
{
	if (input.empty()) return ""; // return empty string if all spaces

	size_t front = 0; // tracks front index
	size_t back = input.size() - 1; // tracks back index

	while (front < back && isspace(input[front])) front++;
	while (front < back && isspace(input[back])) back--;
	return std::string(input, front, back + 1);
}
