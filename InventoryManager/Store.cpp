#include "Store.h"

Store::Store()
{
	this->comedymoviehead = NULL;
	this->dramamoviehead = NULL;
	this->classicmoviehead = NULL;

	for (int i = 0; i < ARRAYMAX; i++)
	{
		comedyhash[i] = NULL;
		dramahash[i] = NULL;
		classichash[i] = NULL;
	}
}

Store::~Store()
{
}

void Store::addstorecustomers(ifstream& customerinfile)
{
	int customerid;
	string customerlastname;
	string customerfirstname;

	for (;;)
	{
		customerinfile >>customerid>>customerlastname>>customerfirstname;

		if (customerinfile.eof())
			break;

		Customer* c = new Customer(customerid,customerlastname, customerfirstname);

		this->storecustomers.push_back(make_pair(customerid,c));
	}
}

void Store::displaycustomers()
{
	for (int i = 0; i < (int)this->storecustomers.size();i++)
	{
			cout << this->storecustomers[i].first<<" ";
			cout << (this->storecustomers[i].second)->getlastname()<<" ";
			cout << (this->storecustomers[i].second)->getfirstname()<<endl;
	}
}

void Store::addstoremovies(ifstream& movieinfile)
{
	string moviecode;
	string inventorycount;
	string moviedetails;

	for(;;)
	{
		if (movieinfile.eof())
			break;

		getline(movieinfile,moviecode,',');

		if (validateMovieCode(moviecode[0]))
		{
			getline(movieinfile,inventorycount,',');
			getline(movieinfile,moviedetails);
			int value = atoi(inventorycount.c_str());
			movienode* mn = new movienode();
			mn->left = NULL;
			mn->right = NULL;

			switch (moviecode[0])
			{
			case 'F':
				{
					Movie* movie = new ComedyMovie(moviedetails);
					mn->inventorycount = value;
					mn->moviedetails = movie;
					mn->movietype = 'F';
					addtotree(this->comedymoviehead,mn);
					break;
				}

			case 'D':
				{
					Movie* movie = new DramaMovie(moviedetails);
					mn->inventorycount = value;
					mn->moviedetails = movie;
					mn->movietype = 'D';
					addtotree(this->dramamoviehead,mn);
					break;
				}
			case 'C':
				{
					Movie* movie = new ClassicMovie(moviedetails);
					mn->inventorycount = value;
					mn->moviedetails = movie;
					mn->movietype = 'C';
					addtotree(this->classicmoviehead,mn);
					break;
				}
			}
		}
		else if(!validateMovieCode(moviecode[0]))
		{
			if (moviecode != "")
			{
				cout<<"Invalid Movie code..not creating movie";
				getline(movieinfile,moviedetails);
				cout<<moviedetails<<endl;
			}
		}
	}
}

void Store::displaystoremovies()
{
	displaystorestree(this->comedymoviehead);
	displaystorestree(this->dramamoviehead);
	displaystorestree(this->classicmoviehead);
}

void Store::displaystorestree(movienode* head)
{
	if (head == NULL)
		return;

	displaystorestree(head->left);
	cout<<head->moviedetails->getDirector()<<endl;
	displaystorestree(head->right);

	return;
}

void Store::addtotree(movienode* &root, movienode* &m)
{
	if (root == NULL)
	{
		root = m;
		return;
	}

	cout<<"inside addition"<<endl;

	movienode* cur = root;

	while (true)
	{
		if (root->movietype == 'F')
		{
			if (*(static_cast<ComedyMovie*>(cur->moviedetails)) < *(static_cast<ComedyMovie*>(m->moviedetails)))
			{
				if (cur->right == NULL)
				{
					cur->right = m;
					return;
				}
				cur = cur->right;
			}
			else
			{
				if (cur->left == NULL)
				{
					cur->left = m;
					return;
				}
				cur = cur->left;
			}

		}
		else if (root->movietype == 'D')
		{
			if (*(static_cast<DramaMovie*>(cur->moviedetails)) < *(static_cast<DramaMovie*>(m->moviedetails)))
			{
				if (cur->right == NULL)
				{
					cur->right = m;
					return;
				}
				cur = cur->right;
			}
			else
			{
				if (cur->left == NULL)
				{
					cur->left = m;
					return;
				}
				cur = cur->left;
			}
		}
		else if (root->movietype == 'C')
		{
			if (*(static_cast<ClassicMovie*>(cur->moviedetails)) < *(static_cast<ClassicMovie*>(m->moviedetails)))
			{
				if (cur->right == NULL)
				{
					cur->right = m;
					return;
				}
				cur = cur->right;
			}
			else
			{
				if (cur->left == NULL)
				{
					cur->left = m;
					return;
				}
				cur = cur->left;
			}
		}
	}

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

bool Store::validateCustomerId(int id)
{
	for (int i = 0; i < (int)this->storecustomers.size();i++)
	{
		if (this->storecustomers[i].first == id)
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

bool Store::movieFound(char moviecode, string moviedetails)
{
	stringstream ss(moviedetails);
	vector<string> vec;
	string token;

	if (moviecode == 'F')
	{
		while (std::getline(ss, token, ','))
		{
			//token = trim(token);
			vec.push_back(token);
		}

		if (vec.size() != 3)
		{
			throw std::invalid_argument("Comedy movie data should contain director, title, and releaseDate") ;
		}

		int hashkey = hashfunction(vec[1]+vec[2]);

		if (this->comedyhash[hashkey] == NULL)
			return false;

		ComedyMovie* cur = this->comedyhash[hashkey];
		int hashcounter = 1; //counter for linear probing

		while(cur != NULL)
		{
			if (cur->getTitle() == vec[1] && cur->getReleaseDate() == vec[2])
				return true;

			cur = this->comedyhash[hashkey+hashcounter];
			hashcounter++;
		}
		return false;
	}
	else if (moviecode == 'C')
	{
		while (std::getline(ss, token, ','))
		{
			//token = trim(token);
			vec.push_back(token);
		}

		if (vec.size() != 3)
		{
			throw std::invalid_argument("Comedy movie data should contain director, title, and releaseDate") ;
		}

		int hashkey = hashfunction(vec[1]+vec[2]);

		if (this->comedyhash[hashkey] == NULL)
			return false;

		ComedyMovie* cur = this->comedyhash[hashkey];
		int hashcounter = 1; //counter for linear probing

		while(cur != NULL)
		{
			if (cur->getTitle() == vec[1] && cur->getReleaseDate() == vec[2])
				return true;

			cur = this->comedyhash[hashkey+hashcounter];
			hashcounter++;
		}
		return false;
	}

	return false;
}



int Store::hashfunction(string moviedetails)
{
	int sum = 0;

	for (int i = 0; i < (int)moviedetails.length(); i++)
		 sum += moviedetails[i];

	return sum%ARRAYMAX;
}

