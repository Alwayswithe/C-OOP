#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;



class READER
{
public:
	void enter_information()
	{
		cout << "\nEnter full name: ";
		cin.ignore();
		getline(cin, full_name);

		cout << "\nEnter date card: ";
		getline(cin, date_card);

		cout << "\nEnter used time: ";
		cin >> used_time;
	}
	void export_information()
	{
		cout << "\nFull name: " << full_name;
		cout << "\nDate card: " << date_card;
		cout << "\nUsed time: " << used_time;
	}

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
	void enter_information_CHILDREN()
	{
		READER::enter_information();
		cout << "\nEnter the representative: ";
		cin.ignore();
		getline(cin, representative);
	}
	void export_information_CHILDREN()
	{
		READER::export_information();
		cout << "\nThe representative: " << representative;
	}
	int cost_CHILDREN()
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
	void enter_information_ADULT()
	{
		READER::enter_information();
		cout << "\nEnter the ID: ";
		cin >> ID;
	}
	void export_information_ADULT()
	{
		READER::export_information();
		cout << "\nThe ID: " << ID;
	}
	int cost_ADULT()
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
	double Total_income();

	CLIBRARY();
	~CLIBRARY();

private:
	CHILDREN list_of_readers_CHILDREN[100];
	ADULT list_of_readers_ADULT[100];
	int number_of_readers_CHILDREN = 0;
	int number_of_readers_ADULT = 0;
};

void CLIBRARY::INPUT()
{
	int option{};
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
			CHILDREN reader_CHILDREN;

			cout << "\n\t\tENTER FORMATION OF CHILDREN READER";
			reader_CHILDREN.enter_information_CHILDREN();

			list_of_readers_CHILDREN[number_of_readers_CHILDREN] = reader_CHILDREN;
			number_of_readers_CHILDREN++;
		}
		else if (option == 2)
		{
			ADULT reader_ADULT;;

			cout << "\n\t\tENTER FORMATION OF ADULT READER";
			reader_ADULT.enter_information_ADULT();

			list_of_readers_ADULT[number_of_readers_ADULT] = reader_ADULT;
			number_of_readers_ADULT++;
		}
		else if (option == 0)
		{
			cout << "\n\t\tPROGRAM END" << endl;
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
	cout << "\nEXPORT INFORMATION OF ALL READERS";

	cout << "\n\t\tCHILD READERS";
	for (int i = 0; i < number_of_readers_CHILDREN; i++)
	{
		cout << "\nChildren reader " << i + 1 << endl;
		list_of_readers_CHILDREN[i].export_information_CHILDREN();
		cout << "\nCost: " << list_of_readers_CHILDREN[i].cost_CHILDREN();
		cout << endl;
	}

	cout << "\n\t\tADULT READERS";
	for (int i = 0; i < number_of_readers_ADULT; i++)
	{
		cout << "\nAdult reader " << i + 1 << endl;
		list_of_readers_ADULT[i].export_information_ADULT();
		cout << "\nCost: " << list_of_readers_ADULT[i].cost_ADULT();
		cout << endl;
	}

	cout << "\n\t\tTOTAL INCOME";
	cout << "\nTotal income: " << Total_income();
}

double CLIBRARY::Total_income()
{
	double sum = 0;

	for (int i = 0; i < number_of_readers_CHILDREN; i++)
	{
		sum += list_of_readers_CHILDREN[i].cost_CHILDREN();
	}
	for (int i = 0; i < number_of_readers_ADULT; i++)
	{
		sum += list_of_readers_ADULT[i].cost_ADULT();
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


	
	CLIBRARY* readers = new CLIBRARY;
	readers->INPUT();
	readers->OUTPUT();

	delete readers;
	cout << endl;
	return 0;
}