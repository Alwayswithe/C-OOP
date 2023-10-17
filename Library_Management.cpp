#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;



class BACSIC_INFORMATION_READER
{
public:
	void enter_basic_information()
	{
		cout << "\nEnter full name: ";
		cin.ignore();
		getline(cin, full_name);

		cout << "\nEnter the card day: ";
		cin.ignore();
		getline(cin, card_date);

		cout << "\nEnter the card' expiration: ";
		cin >> card_expiration;
	}
	void export_basic_information()
	{
		cout << "\nFull name: " << full_name;
		cout << "\nThe card date: " << card_date;
		cout << "\nCard's expiration: " << card_expiration;
	}

	BACSIC_INFORMATION_READER();
	~BACSIC_INFORMATION_READER();

protected:
	string full_name;
	string card_date;
	float card_expiration;

};

BACSIC_INFORMATION_READER::BACSIC_INFORMATION_READER()
{
}

BACSIC_INFORMATION_READER::~BACSIC_INFORMATION_READER()
{
}



class CHILDREN : public BACSIC_INFORMATION_READER
{
public:
	void enter_information_CHILDEN()
	{
		BACSIC_INFORMATION_READER::enter_basic_information();
		cout << "\nRepresentative: ";
		cin.ignore();
		getline(cin, representative);
	}
	void export_informaiton_CHILDEN()
	{
		BACSIC_INFORMATION_READER::export_basic_information();
		cout << "\nRepresentative: " << representative;
	}
	float cost_card_CHILDREN()
	{
		return card_expiration * 5000;
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



class ADULT : public BACSIC_INFORMATION_READER
{
public:
	void enter_information_ADULT()
	{
		BACSIC_INFORMATION_READER::enter_basic_information();
		cout << "\nEnter ID: ";
		cin >> ID;
	}
	void export_information_ADULT()
	{
		BACSIC_INFORMATION_READER::export_basic_information();
		cout << "\nID: " << ID;
	}
	float cost_card_ADULT()
	{
		return card_expiration * 10000;
	}

	ADULT();
	~ADULT();

private:
	int ID;
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
	void Input();
	void Output();
	double Total_cost_card();

	CLIBRARY();
	~CLIBRARY();

private:
	vector<CHILDREN *> List_of_reader_CHILDREN;
	vector<ADULT *> List_of_reader_ADULT;
};

CLIBRARY::CLIBRARY()
{
}

CLIBRARY::~CLIBRARY()
{
}

void CLIBRARY::Input()
{
	int option;

	while (true)
	{
		system("cls");

		cout << "\n\t\tMANAGEMENT PROGRAM";
		cout << "\n1. Enter information of reader CHILDREN";
		cout << "\n2. Enter information of reader ADULT";

		cout << "\n0. Exit the program";
		cout << "\n\t\t\tEND";

		cout << "\nEnter your option: ";
		cin >> option;

		if (option == 1)
		{
			cout << "\n\t\tENTER THE INFORMATION OF CHILDREN CARD";
			CHILDREN* children_card = new CHILDREN();
			children_card->enter_information_CHILDEN();

			List_of_reader_CHILDREN.push_back(children_card);
		}
		else if (option == 2)
		{
			cout << "\n\t\tENTER THE INFORMATION OF ADULT CARD";
			ADULT* adult_card = new ADULT();
			adult_card->enter_information_ADULT();

			List_of_reader_ADULT.push_back(adult_card);
		}
		else if (option == 0)
		{
			cout << "\n\t\tEND PROGRAM";
			break;
		}
		else
		{
			cout << "\nYour option is not valid";
			cout << endl;
			system("pause");
		}
	}
}

void CLIBRARY::Output()
{
	system("cls");

	cout << "\n\t\tEXPORT ALL OF READER'S CARD";
	cout << "\nCHILDREN CARD";
	for (size_t i = 0; i < List_of_reader_CHILDREN.size(); i++)
	{
		cout << "\n\tChildren card " << i + 1 << endl;
		List_of_reader_CHILDREN[i]->export_informaiton_CHILDEN();
		cout << "\nThe cost: " << (size_t)List_of_reader_CHILDREN[i]->cost_card_CHILDREN();
		cout << endl;
	}

	cout << "\n\tADULT CARD";
	for (size_t i = 0; i < List_of_reader_ADULT.size(); i++)
	{
		cout << "\nAdult " << i + 1 << endl;
		List_of_reader_ADULT[i]->export_information_ADULT();
		cout << "\nThe cost: " << (size_t)List_of_reader_ADULT[i]->cost_card_ADULT();
		cout << endl;
	}

	cout << "\n\tTOTAL COST OF ALL CARD";
	cout << "\nThe cost: " << (size_t)Total_cost_card();
}

double CLIBRARY::Total_cost_card()
{
	double sum = 0;

	for (int i = 0; i < List_of_reader_CHILDREN.size(); i++)
	{
		sum += List_of_reader_CHILDREN[i]->cost_card_CHILDREN();
	}
	for (int i = 0; i < List_of_reader_ADULT.size(); i++)
	{
		sum += List_of_reader_ADULT[i]->cost_card_ADULT();
	}

	return sum;
}


int main() {

	CLIBRARY* Library = new CLIBRARY();

	Library->Input();
	Library->Output();

	cout << endl;
	return 0;
}