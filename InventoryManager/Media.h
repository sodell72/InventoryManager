// ------------------------------------------------ Media.h -------------------------------------------------------
// Sean O'Dell, CSS 502A
// Creation Date: 02/24/2019
// Date of Last Modification: 2/26/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Abstract class to provide framework for how to store data on media
// --------------------------------------------------------------------------------------------------------------------
// provies shared parameters and functions available for all media types.  A media object is created for each new
// object offered at the chain.  A media object holds information about that particular media product.
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include <string>

class Media
{

private:
	std::string releaseDate;
	std::string title;
	char distributionType; // DVD, CD, VHS, etc...

public:
	// ------------------------------------Media-----------------------------------------------
	// Description: constructor, initializes values to default values
	// ---------------------------------------------------------------------------------------------------
	Media(std::string title, char distributionType, std::string releaseDate);

	// ------------------------------------~Media-----------------------------------------------
	// Description: destructor, destroys dynamically allocated Media object
	// ---------------------------------------------------------------------------------------------------
	~Media();

	// ------------------------------------setTitle-----------------------------------------------
	// Description: setter for title
	// ---------------------------------------------------------------------------------------------------
	virtual void setTitle(std::string title);

	// ------------------------------------setDistributionType-----------------------------------------------
	// Description: setter for distributionType
	// ---------------------------------------------------------------------------------------------------
	virtual void setDistributionType(char type);

	// ------------------------------------setReleaseDate-----------------------------------------------
	// Description: setter for release date
	// ---------------------------------------------------------------------------------------------------
	virtual void setReleaseDate(std::string releaseDate);

	// ------------------------------------==-----------------------------------------------
	// Description: performs equality comparison
	// ---------------------------------------------------------------------------------------------------
	virtual bool operator==(const Media & other) const = 0;

	// ------------------------------------<-----------------------------------------------
	// Description: performs less than comparison
	// ---------------------------------------------------------------------------------------------------
	virtual bool operator<(const Media& other) const = 0;

	// ------------------------------------getReleaseDate-----------------------------------------------
	// Description: getter for releaseDate
	// ---------------------------------------------------------------------------------------------------
	virtual std::string getReleaseDate();

	// ------------------------------------getTitle-----------------------------------------------
	// Description: getter for title
	// ---------------------------------------------------------------------------------------------------
	virtual std::string getTitle();

	// ------------------------------------getDistributionType-----------------------------------------------
	// Description: getter for distributionType
	// ---------------------------------------------------------------------------------------------------
	virtual char getDistributionType();

	// ------------------------------------hash-----------------------------------------------
	// Description: hashing function, takes in object ID and outputs index
	// ---------------------------------------------------------------------------------------------------
	virtual int hash(int ID) = 0;
};