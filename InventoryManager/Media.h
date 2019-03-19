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
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <iostream>

class Media
{

protected:
	std::string releaseDate;
	std::string title;
	char distributionType; // DVD, CD, VHS, etc...

public:
	// ------------------------------------Media-----------------------------------------------
	// Description: constructor, initializes values to default values
	// ---------------------------------------------------------------------------------------------------
	Media();

	// ------------------------------------~Media-----------------------------------------------
	// Description: destructor, destroys dynamically allocated Media object
	// ---------------------------------------------------------------------------------------------------
	~Media();

	// ------------------------------------setReleaseDate-----------------------------------------------
	// Description: setter for release date
	// ---------------------------------------------------------------------------------------------------
	virtual void setReleaseDate(std::string releaseDate);

	// ------------------------------------setTitle-----------------------------------------------
	// Description: setter for title
	// ---------------------------------------------------------------------------------------------------
	void setTitle(std::string title);

	// ------------------------------------setDistributionType-----------------------------------------------
	// Description: setter for distributionType
	// ---------------------------------------------------------------------------------------------------
	void setDistributionType(char type);

	// ------------------------------------getReleaseDate-----------------------------------------------
	// Description: getter for releaseDate
	// ---------------------------------------------------------------------------------------------------
	virtual std::string getReleaseDate() const;

	// ------------------------------------getTitle-----------------------------------------------
	// Description: getter for title
	// ---------------------------------------------------------------------------------------------------
	virtual std::string getTitle() const;

	// ------------------------------------getDistributionType-----------------------------------------------
	// Description: getter for distributionType
	// ---------------------------------------------------------------------------------------------------
	virtual char getDistributionType() const;

	// ------------------------------------trim-----------------------------------------------
	// Description: trims whitespace
	// ---------------------------------------------------------------------------------------------------
	std::string trim(const std::string& input);

};
