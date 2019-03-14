#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
}

bool Store::performCommand(std::string command)
{
	char commandType = command[0];

	switch (commandType)
	{
	case 'B': return performBorrowCommand(command);
		break;
	case 'R': return performReturnCommand(command);
		break;
	case 'I': return performInventoryCommand(command);
		break;
	case 'H': return performHistoryCommand(command);
	default:
		cout << "command: \"" << command << "\" is invalid";
		return false;
	}
	return false;
}

bool Store::validateMovieCode(char videoCode)
{
	videoCode = std::toupper(videoCode);
	if (this->validMovieCodes.find(videoCode) != validMovieCodes.end())
	{
		return true;
	}
	return false;
}

bool Store::performBorrowCommand(std::string command)
{
	return false;
}

bool Store::performReturnCommand(std::string command)
{
	return false;
}

bool Store::performInventoryCommand(std::string command)
{
	return false;
}

bool Store::performHistoryCommand(std::string command)
{
	return false;
}
