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

		//cout<<moviecode;

		if (validateMovieCode(moviecode[0]))
		{
			getline(movieinfile,inventorycount,',');
			//cout <<" "<<inventorycount;
			getline(movieinfile,moviedetails);
			//cout <<" "<<moviedetails <<endl;
			int value = atoi(inventorycount.c_str());
			Movie* movieininventory = moviefoundininventory(moviecode[0],moviedetails);

			if (movieininventory != NULL)
			{
				//cout <<"inside update inventory"<<endl;
				updateinventorycounts(moviecode[0],movieininventory,value);
				continue;
			}
			movienode* mn = new movienode();
			mn->left = NULL;
			mn->right = NULL;

			switch (moviecode[0])
			{
			case 'F':
				{
					ComedyMovie* comedymovie = new ComedyMovie(moviedetails);
					//cout <<"inside insert comedy movie"<<endl;
					insertcomedyhashtable(moviedetails, comedymovie);
					Movie* movie = comedymovie;
					mn->inventorycount = value;
					mn->moviedetails = movie;
					mn->movietype = 'F';
					addtotree(this->comedymoviehead,mn);
					break;
				}

			case 'D':
				{
					DramaMovie* dramamovie = new DramaMovie(moviedetails);
					//cout <<"inside insert drama movie"<<endl;
					insertdramahashtable(moviedetails, dramamovie);
					Movie* movie = dramamovie;
					mn->inventorycount = value;
					mn->moviedetails = movie;
					mn->movietype = 'D';
					addtotree(this->dramamoviehead,mn);
					break;
				}
			case 'C':
				{
					//cout <<"inside insert classic movie"<<endl;
					ClassicMovie* classicmovie = new ClassicMovie(moviedetails);
					//cout <<"inside after insert classic movie"<<endl;
					insertclassichashtable(moviedetails, classicmovie);
					Movie* movie = classicmovie;
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

void Store::insertcomedyhashtable(string moviedetails, ComedyMovie *comedymovie)
{
	vector<string> vec = parsemoviedetails(moviedetails);

	//cout<<"Hashkey Parameter :"<<(vec[1]+vec[2])<<endl;
	int hashkey = hashfunction(vec[1]+vec[2]);
	//cout<<"Hashkey :"<<hashkey<<endl;

	if (this->comedyhash[hashkey] == NULL)
	{
		this->comedyhash[hashkey] = comedymovie;
		return;
	}

	ComedyMovie* cur = this->comedyhash[hashkey];
	int hashcounter = 1; //counter for linear probing

	while(cur != NULL)
	{
		cur = this->comedyhash[hashkey+hashcounter];
		hashcounter++;
	}

	this->comedyhash[hashkey+hashcounter-1] = comedymovie;

	return;

}

void Store::insertdramahashtable(string moviedetails, DramaMovie* dramamovie)
{
	vector<string> vec = parsemoviedetails(moviedetails);

	//cout<<"hashkeyparameter: "<<(vec[0]+vec[1])<<endl;
	int hashkey = hashfunction(vec[0]+vec[1]);
	//cout<<"Hashkey :"<<hashkey<<endl;

	if (this->dramahash[hashkey] == NULL)
	{
		this->dramahash[hashkey] = dramamovie;
		return;
	}

	DramaMovie* cur = this->dramahash[hashkey];
	int hashcounter = 1; //counter for linear probing

	while(cur != NULL)
	{
		cur = this->dramahash[hashkey+hashcounter];
		hashcounter++;
	}

	this->dramahash[hashkey+hashcounter-1] = dramamovie;

	return;
}


void Store::insertclassichashtable(string moviedetails, ClassicMovie* classicmovie)
{
	vector<string> vec = parsemoviedetails(moviedetails);

	//cout<<"hashkeyparameter: "<<vec[2]<<endl;
	int hashkey = hashfunction(vec[2]);
	//cout<<"hashkey :"<<hashkey<<endl;

	if (this->classichash[hashkey] == NULL)
	{
		this->classichash[hashkey] = classicmovie;
		return;
	}

	ClassicMovie* cur = this->classichash[hashkey];
	int hashcounter = 1; //counter for linear probing

	while(cur != NULL)
	{
		cur = this->classichash[hashkey+hashcounter];
		hashcounter++;
	}

	this->classichash[hashkey+hashcounter-1] = classicmovie;

	return;
}

void Store::displaystoremovies()
{
	displaystorestree(this->comedymoviehead);
	displaystorestree(this->dramamoviehead);
	displaystorestree(this->classicmoviehead);
}

bool Store::updateinventorycounts(char moviecode,Movie* movieininventory,int value)
{
	switch (moviecode)
	{
		case 'F':
		{
			recursiveupdate(moviecode,this->comedymoviehead,movieininventory,value);
			break;
		}
		case 'C':
		{
			recursiveupdate(moviecode,this->classicmoviehead,movieininventory,value);
			break;
		}
		case 'D':
		{
			recursiveupdate(moviecode,this->dramamoviehead,movieininventory,value);
			break;
		}
	}

	return false;
}

void Store::recursiveupdate(char moviecode, movienode* mnode,Movie* movieininventory,int value)
{
	if (moviecode == 'F' &&
		(*(static_cast<ComedyMovie*>(mnode->moviedetails)) == *(static_cast<ComedyMovie*>(movieininventory))) &&
		mnode != NULL )
	{
		//cout<<"New inventory count : "<<(mnode->inventorycount + value)<<endl;
		if ((mnode->inventorycount + value) >=  0)
			mnode->inventorycount = mnode->inventorycount + value;
		else
		{
			mnode->inventorycount = 0;
			cout<<"You cannot borrow as stock is zero"<<*(static_cast<ComedyMovie*>(mnode->moviedetails))<<endl;
		}

		return;
	}
	else if (moviecode == 'D' &&
		(*(static_cast<DramaMovie*>(mnode->moviedetails)) == *(static_cast<DramaMovie*>(movieininventory))) &&
		mnode != NULL)
	{
		//cout<<"New inventory count : "<<(mnode->inventorycount + value)<<endl;
		if (mnode->inventorycount + value >=  0)
			mnode->inventorycount = mnode->inventorycount + value;
		else
		{
			mnode->inventorycount = 0;
			cout<<"You cannot borrow "<<*(static_cast<DramaMovie*>(mnode->moviedetails))<<"as stock is zero"<<endl;
		}
		return;
	}
	else if (moviecode == 'C' &&
			(*(static_cast<ClassicMovie*>(mnode->moviedetails)) == *(static_cast<ClassicMovie*>(movieininventory))) &&
			mnode != NULL )
	{
		//cout<<"New inventory count : "<<(mnode->inventorycount + value)<<endl;
		if (mnode->inventorycount + value >=  0)
			mnode->inventorycount = mnode->inventorycount + value;
		else
		{
			mnode->inventorycount = 0;
			cout<<"You cannot borrow "<<*(static_cast<ClassicMovie*>(mnode->moviedetails))<<"as stock is zero"<<endl;
		}
		return;
	}
	else
	{
		if (mnode->left != NULL)
			recursiveupdate(moviecode, mnode->left,movieininventory,value);
		if (mnode->right != NULL)
			recursiveupdate(moviecode, mnode->right,movieininventory,value);
	}

	return;
}



void Store::displaystorestree(movienode* head)
{
	if (head == NULL)
		return;

	displaystorestree(head->left);
	switch(head->movietype)
	{
	case 'F':
		{
			cout << "Stock Count : " << head->inventorycount << " ";
			cout << *(static_cast<ComedyMovie*>(head->moviedetails))<<endl;
			break;
		}
	case 'C':
		{
			cout << "Stock Count : " << head->inventorycount << " ";
			cout << *(static_cast<ClassicMovie*>(head->moviedetails))<<endl;
			break;
		}
	case 'D':
		{
			cout << "Stock Count : " << head->inventorycount << " ";
			cout << *(static_cast<DramaMovie*>(head->moviedetails))<<endl;
			break;
		}
	}

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
		{
			cout << "command: \"" << command << "\" is invalid"<<endl;
			return false;
		}
	}
	return true;
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

bool Store::validateActionCode(char actionCode)
{
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

Customer* Store::fetchcustomerobject(int customerid)
{
	for (pair<int, Customer*> pair : storecustomers)
	{
			if (pair.first == customerid)
				return pair.second;
	}
	return NULL;
}


bool Store::performBorrowCommand(std::string command)
{
	//cout <<"inside borrow"<< endl;
	vector<string> vec = parsecommanddetails(command);
	//cout <<"After Parse command"<<endl;
	string moviecode = vec[3];
	Movie* movieborrow;
	string moviedetails;

	//check if the movie code is valid
	if (!validateMovieCode(moviecode[0]))
	{
		cout<<"invalid movie code : "<<moviecode<<endl;
		return false;
	}

	//check if the customer id is valid
	stringstream ss(vec[1]);
	int customerid = 0;
	ss >> customerid;
	if (!validateCustomerId(customerid))
	{
		cout<<"invalid Customer Id : "<<customerid<<endl;
		return false;
	}

	Customer* cust = fetchcustomerobject(customerid);

	if (cust == NULL)
	{
		cout <<"Customer object not found for the ID : "<<customerid<<endl;
		return false;
	}

	if (moviecode == "F")
		moviedetails = vec[4]+vec[5];
	else if (moviecode == "C")
		moviedetails = vec[6]+" "+vec[7]+" "+vec[4]+" "+vec[5];
	else if (moviecode == "D")
		moviedetails = vec[4]+vec[5];


	movieborrow = moviefoundinhashtable(moviecode[0],moviedetails);

	if (movieborrow == NULL)
	{
		cout<<"You cannot borrow "<<moviedetails<<" as it is not in store"<<endl;
		return false;
	}

	/***********************************************************************************************
	 * update stock count for the borrow transaction. If the stock goes below 0, it will print a message and
	 * will not update the stock
	 ***********************************************************************************************/
	updateinventorycounts(moviecode[0],movieborrow,-1);

	//Create a new transaction
	transaction* T = new transaction("B",movieborrow);

	//add transaction to the customer
	cust->addtransaction(T);

	return true;
}

bool Store::validateifcustomerborrowedtheitem(Customer* cust,Movie* movie)
{
	//cout<<"inside validate transactions"<<endl;

	transaction* cur = cust->gettransactionhead();

	int borrowcount = 0;
	int returncount = 0;

	while (cur != NULL)
	{
		//cout<<"inside validate transactions linkedlist loop"<<endl;

		if (cur->gettransactiontype() == "B" && cur->getmovie() == movie)
			borrowcount++;
		else if (cur->gettransactiontype() == "R" && cur->getmovie() == movie)
			returncount++;

		//cout<<"end of loop iteration"<<endl;
		//cout<<"Borrow Count : "<<borrowcount<<endl;
		//cout<<"return Count : "<<returncount<<endl;
		cur=cur->getnext();
	}

	//verifying if the borrow transaction count is greater than return
	if (borrowcount > returncount)
		return true;


	return false;
}

bool Store::performReturnCommand(std::string command)
{
	//cout <<"inside return"<< endl;
	vector<string> vec = parsecommanddetails(command);
	//cout <<"After Parse command"<<endl;
	string moviecode = vec[3];
	Movie* moviereturn;
	string moviedetails;

	//check if the movie code is valid
	if (!validateMovieCode(moviecode[0]))
	{
		cout<<"invalid movie code : "<<moviecode<<endl;
		return false;
	}

	//check if the customer id is valid
	stringstream ss(vec[1]);
	int customerid = 0;
	ss >> customerid;
	if (!validateCustomerId(customerid))
	{
		cout<<"invalid Customer Id : "<<customerid<<endl;
		return false;
	}

	Customer* cust = fetchcustomerobject(customerid);

	if (cust == NULL)
	{
		cout <<"Customer object not found for the ID : "<<customerid<<endl;
		return false;
	}

	if (moviecode == "F")
		moviedetails = vec[4]+vec[5];
	else if (moviecode == "C")
		moviedetails = vec[6]+" "+vec[7]+" "+vec[4]+" "+vec[5];
	else if (moviecode == "D")
		moviedetails = vec[4]+vec[5];

	moviereturn = moviefoundinhashtable(moviecode[0],moviedetails);

	if (moviereturn == NULL)
	{
		cout<<"You cannot return "<<moviedetails<<" as it was never part of the store"<<endl;
		return false;
	}


	//validate of the customer has an outstanding borrowed movie
	if (!validateifcustomerborrowedtheitem(cust,moviereturn))
	{
		cout<<"Doesn't look like customer id "<<customerid<<" has borrow "<<moviedetails<<endl;
		return false;
	}

	/***********************************************************************************************
	 * update stock count for the return transaction.
	 ***********************************************************************************************/
	updateinventorycounts(moviecode[0],moviereturn,1);

	//Create a new transaction
	transaction* T = new transaction("R",moviereturn);

	//add transaction to the customer
	cust->addtransaction(T);

	return true;
}

bool Store::performInventoryCommand(std::string command)
{
	displaystoremovies();
	return true;
}

bool Store::performHistoryCommand(std::string command)
{
	int customerId = stoi(command.substr(2));
	for (pair<int, Customer*> pair : storecustomers)
	{
		if (pair.first == customerId)
		{
			transaction* currentTransaction = pair.second->gettransactionhead();
			while (currentTransaction != nullptr)
			{
				cout << currentTransaction->gettransactiontype();
				currentTransaction = currentTransaction->getnext();
				if (currentTransaction != nullptr)
				{
					cout << ", ";
				}
			}
			return true;
		}
	}
	return false;
}

Movie* Store::moviefoundininventory(char moviecode, string moviedetails)
{
	vector<string> vec = parsemoviedetails(moviedetails);

	if (moviecode == 'F')
		return moviefoundinhashtable(moviecode,vec[1]+vec[2]);
	else if (moviecode == 'C')
		return moviefoundinhashtable(moviecode,vec[2]);
	else if (moviecode == 'D')
		return moviefoundinhashtable(moviecode,vec[0]+vec[1]);

	return NULL;
}


vector<string> Store::parsemoviedetails(string moviedetails)
{
		stringstream ss(moviedetails);
		vector<string> vec;
		string token;
		while (std::getline(ss, token, ','))
		{
			token = trim(token);
			vec.push_back(token);
		}

		if (vec.size() != 3)
		{
			throw std::invalid_argument("Movie data doesn't have the required attributes") ;
		}

		return vec;
}

vector<string> Store::parsecommanddetails(string command)
{
		stringstream ss(command);
		vector<string> vec;
		string token;
		for (int i = 0; i < 10; i++)
		{
			if (i < 4)
				getline(ss, token, ' ');
			else if (vec[3] == "F" || vec[3] == "D" )
				getline(ss, token, ',');
			else if (vec[3] == "C")
				getline(ss, token, ' ');

			token = trim(token);
			if (token != "")
				vec.push_back(token);
		}

		return vec;
}

Movie* Store::moviefoundinhashtable(char moviecode, string moviedetails)
{
	int hashkey = 0;

	hashkey = hashfunction(moviedetails);

	//cout<<"Hashkey :"<<hashkey<<" Movie Details: "<<moviedetails<<endl;

	if (moviecode == 'F')
	{
			if (this->comedyhash[hashkey] == NULL)
				return NULL;

			//cout<<*this->comedyhash[hashkey]<<endl;
			ComedyMovie* cur = this->comedyhash[hashkey];
			int hashcounter = 1; //counter for linear probing

			while(cur != NULL)
			{
				//cout<<"Hash Comparisons : "<<trim(cur->getTitle())+trim(cur->getReleaseDate());
				//cout<<"   "<<moviedetails<<endl;
				if (trim(cur->getTitle())+trim(cur->getReleaseDate()) == moviedetails)
					return cur;

				cur = this->comedyhash[hashkey+hashcounter];
				hashcounter++;
			}
			return NULL;
	}
	else if (moviecode == 'C')
	{
			if (this->classichash[hashkey] == NULL)
					return NULL;

			ClassicMovie* cur = this->classichash[hashkey];
			int hashcounter = 1; //counter for linear probing

			while(cur != NULL)
			{
				//cout<<"Hash Comparisons : "<<trim(cur->getMajorActorName())+" "+trim(cur->getReleaseDate());
				//cout<<"   "<<moviedetails<<endl;
				if (trim(cur->getMajorActorName())+" "+trim(cur->getReleaseDate()) == moviedetails)
					return cur;

				cur = this->classichash[hashkey+hashcounter];
				hashcounter++;
			}

			return NULL;
	}
	else if (moviecode == 'D')
	{
		if (this->dramahash[hashkey] == NULL)
			return NULL;

		DramaMovie* cur = this->dramahash[hashkey];
		int hashcounter = 1; //counter for linear probing

		while(cur != NULL)
		{
			//cout<<"Hash Comparisons : "<<trim(cur->getDirector())+trim(cur->getTitle());
			//cout<<"   "<<moviedetails<<endl;
			if (trim(cur->getDirector())+trim(cur->getTitle()) == moviedetails)
				return cur;

			cur = this->dramahash[hashkey+hashcounter];
			hashcounter++;
		}

		return NULL;
	}

	return NULL;

}


int Store::hashfunction(string moviedetails)
{
	int sum = 0;

	for (int i = 0; i < (int)moviedetails.length(); i++)
		 sum += moviedetails[i];

	//cout<<"Sum :"<<sum<<" "<<"ArrayMax :"<<ARRAYMAX<<" sum%ARRAYMAX :"<<sum%ARRAYMAX<<endl;

	return (sum%ARRAYMAX);
}

std::string Store::trim(const std::string& input)
{
	if (input.empty()) return ""; // return empty string if all spaces

	size_t front = 0; // tracks front index
	size_t back = input.size() - 1; // tracks back index

	while (front < back && isspace(input[front])) front++;
	while (front < back && isspace(input[back])) back--;
	return std::string(input, front, back + 1);
}

void Store::executestorecommands(ifstream& infileCommands)
{
	string command;
	for (;;)
	{
		if (infileCommands.eof())
			break;

		getline(infileCommands,command);
		performCommand(command);
	}
}

