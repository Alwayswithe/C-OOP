#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;



class READER
{
public:
	virtual void enter_information_reader()
	{
		cout << "\nEnter full name: ";
		cin.ignore();
		getline(cin, full_name);
		
		cout << "\nEnter the date card: ";
		getline(cin, date_card);

		cout << "\nEnter used time: ";
		cin >> used_time;
	}
	virtual void export_information_reader()
	{
		cout << "\nFull name: " << full_name;
		cout << "\nThe date card: " << date_card;
		cout << "\nUsed time: " << used_time;
	}
	virtual int cost_card() = 0;

	READER();
	~READER();

protected:
	string full_name;
	string date_card;
	int used_time;
};

READER::READER()
{
}

READER::~READER()
{
}



class CHILDREN : public READER
{
public:
	void enter_information_reader()
	{
		READER::enter_information_reader();
		cout << "\nEnter the representative: ";
		cin.ignore();
		getline(cin, representative);
	}
	void export_information_reader()
	{
		READER::export_information_reader();
		cout << "\nThe representative: " << representative;
	}
	int cost_card()
	{
		return used_time * 5000;
	}

	CHILDREN();
	~CHILDREN();

private:
	string representative;
};

CHILDREN::CHILDREN()
{
}

CHILDREN::~CHILDREN()
{
}



class ADULT : public READER
{
public:
	void enter_information_reader()
	{
		READER::enter_information_reader();
		cout << "\nEnter the ID: ";
		cin >> ID;
	}
	void export_information_reader()
	{
		READER::export_information_reader();
		cout << "\nThe ID: " << ID;
	}
	int cost_card()
	{
		return used_time * 10000;
	}

	ADULT();
	~ADULT();

private:
	string ID;
};

ADULT::ADULT()
{
}

ADULT::~ADULT()
{
}



class CLIBRARY
{
public:
	void INPUT();
	void OUTPUT();
	double Tota_income();

	CLIBRARY();
	~CLIBRARY();

private:
	vector<READER *> List_of_READERs;
};

void CLIBRARY::INPUT()
{
	int option;

	while (true)
	{
		system("cls");

		cout << "\n\t\tENTER INFORMATION OF READER";
		cout << "\n1. Children";
		cout << "\n2. Adult";
		cout << "\n0. END PROGRAM";
		cout << "\n\t\tEND";

		cout << "\nEnter the option: ";
		cin >> option;

		if (option == 1)
		{
			READER* reader_CHILDREN = new CHILDREN;
			cout << "\n\t\tENTER FORMATION OF CHILDREN READER";

			reader_CHILDREN->enter_information_reader();
			List_of_READERs.push_back(reader_CHILDREN);

		}
		else if (option == 2)
		{
			READER* reader_ADULT = new ADULT();
			cout << "\n\t\tENTER FORMATION OF ADULT READER";

			reader_ADULT->enter_information_reader();
			List_of_READERs.push_back(reader_ADULT);
		}
		else if (option == 0)
		{
			cout << "\nPROGRAM END" << endl;
			break;
			system("pause");
		}
		else
		{
			cout << "\nYour option is not valid" << endl;
			system("pause");
		}
	}
}

void CLIBRARY::OUTPUT()
{
	cout << "\n\t\tEXPORT INFORMATION OF ALL READERS";

	
	for (int i = 0; i < List_of_READERs.size(); i++)
	{
		cout << "\nReader " << i + 1 << endl;
		List_of_READERs[i]->export_information_reader();
		cout << "\nThe cost: " << (size_t)List_of_READERs[i]->cost_card();
		cout << endl;
	}

	cout << "\n\t\tTOTAL INCOME";
	cout << "\nThe cost: " << (size_t)Tota_income();
}

double CLIBRARY::Tota_income()
{
	double sum = 0;

	for (int i = 0; i < List_of_READERs.size(); i++)
	{
		sum += List_of_READERs[i]->cost_card();
	}

	return sum;
}

CLIBRARY::CLIBRARY()
{
}

CLIBRARY::~CLIBRARY()
{
}



int main() {

	CLIBRARY* reader = new CLIBRARY();

	reader->INPUT();
	reader->OUTPUT();
	

	delete reader;
	cout << endl;
	return 0;
}