#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class VEHICLE
{
public:

	void enter_information_renter()
	{
		cout << "\nEnter full name: ";
		cin.ignore();
		getline(cin, full_name);
		
		cout << "\nEnter the rental hours: ";
		cin >> rental_hours;
	}
	void export_information_renter()
	{
		cout << "\nFull name: " << full_name;
		cout << "\nRental hours: " << rental_hours;
	}

	VEHICLE();
	~VEHICLE();

protected:
	string full_name;
	float rental_hours;

};

VEHICLE::VEHICLE()
{
}

VEHICLE::~VEHICLE()
{
}



class BICYCLE : public VEHICLE
{
public:

	float cost_renting_BICYCLE();

	BICYCLE();
	~BICYCLE();

private:

};

float BICYCLE::cost_renting_BICYCLE()
{
	return 10000 + (rental_hours - 1) * 8000;
}

BICYCLE::BICYCLE()
{
}

BICYCLE::~BICYCLE()
{
}



class MOTORCYCLE : public VEHICLE
{
public:

	void enter_information_MOTORCYCLE();
	void export_information_MOTORCYCLE();
	float cost_renting_MOTORCYCLE();
	int GETTER_model_MOTORCYCLE()
	{
		return model_MOTORCYCLE;
	}

	MOTORCYCLE();
	~MOTORCYCLE();

private:
	int model_MOTORCYCLE;
	string license_plates_MOTORCYCLE;
};

void MOTORCYCLE::enter_information_MOTORCYCLE()
{
	VEHICLE::enter_information_renter();

	cout << "\nEnter car model (100 or 250): ";
	cin >> model_MOTORCYCLE;

	cin.ignore();
	cout << "\nEnter license plates of the motorcycle: ";
	getline(cin, license_plates_MOTORCYCLE);
	
}

void MOTORCYCLE::export_information_MOTORCYCLE()
{
	VEHICLE::export_information_renter();

	cout << "\nCar model: " << model_MOTORCYCLE;
	cout << "\nLicense plates: " << license_plates_MOTORCYCLE;
}

float MOTORCYCLE::cost_renting_MOTORCYCLE()
{
	if (model_MOTORCYCLE == 100)
	{
		return 150000 + (rental_hours - 1) * 100000;
	}
	else if (model_MOTORCYCLE == 250)
	{
		return 200000 + (rental_hours - 1) * 100000;
	}
}

MOTORCYCLE::MOTORCYCLE()
{
}

MOTORCYCLE::~MOTORCYCLE()
{
}


void Meau(BICYCLE List_of_BICYCLE_rental[], int number_of_BICYCLE_rental, MOTORCYCLE List_of_MOTORCYCLE_rental[], int number_of_MOTORCYCLE_rental);
void Check_option(int& option);
double Total_income_BICYCLE(BICYCLE List_of_BICYCLE_rental[], int number_of_BICYCLE_rental);
double Total_income_MOTORCYCLE(MOTORCYCLE List_of_MOTORCYCLE_rental[], int number_of_MOTORCYCLE_rental);
double Total_income_MOTORCYCLE_MODEL_250(MOTORCYCLE List_of_MOTORCYCLE_rental[], int number_of_MOTORCYCLE_rental);



int main() {

	BICYCLE List_of_BICYCLE_rental[100];
	MOTORCYCLE List_of_MOTORCYCLE_rental[100];
	int number_of_BICYCLE_rental = 0;
	int number_of_MOTORCYCLE_rental = 0;

	Meau(List_of_BICYCLE_rental, number_of_BICYCLE_rental, List_of_MOTORCYCLE_rental, number_of_MOTORCYCLE_rental);

	cout << endl;
	return 0;
}

void Meau(BICYCLE List_of_BICYCLE_rental[], int number_of_BICYCLE_rental, MOTORCYCLE List_of_MOTORCYCLE_rental[], int number_of_MOTORCYCLE_rental)
{
	int option;

	while (true)
	{
		system("cls");

		cout << "\n\t\tMANAGEMENT VEHICLE PROGRAM";
		cout << "\n1. Enter information on BICYCLE rental";
		cout << "\n2. Enter information on MOTORCYCLE rental";
		cout << "\n3. Export information on BICYCLE rental";
		cout << "\n4. Export information on MOTORCYCLE rental";
		cout << "\n5. The total income from BICYCLE rental";
		cout << "\n6. The total income from MOTORCYCLE rental";
		cout << "\n7. The total income from MOTORCYCLE model 250 rental";
		cout << "\n0. Exit the program";
		cout << "\n\t\t\tEND";

		cout << "\nEnter your option: ";
		cin >> option;

		switch (option)
		{
			case 1:
			{
				cout << "\n\t\tENTER INFORMATION ON BICYCLE RENTAL";
				BICYCLE bicycle_rental;
				bicycle_rental.enter_information_renter();

				List_of_BICYCLE_rental[number_of_BICYCLE_rental] = bicycle_rental;
				number_of_BICYCLE_rental++;
			}
			break;
			case 2:
			{
				cout << "\n\t\tENTER INFORMATION ON MOTORCYCLE RENTAL";
				MOTORCYCLE motorcycle_rental;
				motorcycle_rental.enter_information_MOTORCYCLE();

				List_of_MOTORCYCLE_rental[number_of_MOTORCYCLE_rental] = motorcycle_rental;
				number_of_MOTORCYCLE_rental++;
			}
			break;
			case 3:
			{
				cout << "\n\t\EXPORT INFORMATION ON BICYCLE RENTAL";
				for (int i = 0; i < number_of_BICYCLE_rental; i++)
				{
					cout << "\nBicycle " << i + 1 << endl;
					List_of_BICYCLE_rental[i].export_information_renter();
					cout << "\nCost: " << (size_t)List_of_BICYCLE_rental[i].cost_renting_BICYCLE();
					cout << endl;
				}
				system("pause");
			}
			break;
			case 4:
			{
				cout << "\n\t\EXPORT INFORMATION ON MOTORCYCLE RENTAL";
				for (int i = 0; i < number_of_MOTORCYCLE_rental; i++)
				{
					cout << "\nMotorcycle " << i + 1 << endl;
					List_of_MOTORCYCLE_rental[i].export_information_MOTORCYCLE();
					cout << "\nCost: " << (size_t)List_of_MOTORCYCLE_rental[i].cost_renting_MOTORCYCLE();
					cout << endl;
				}
				system("pause");
			}
			break;
			case 5:
			{
				cout << "\n\t\THE TOTAL INCOME FROM BICYCLE RENTAL";
				cout << "\nThe total: " << (size_t)Total_income_BICYCLE(List_of_BICYCLE_rental, number_of_BICYCLE_rental);
				system("pause");
			}
			break;
			case 6:
			{
				cout << "\n\t\THE TOTAL INCOME FROM MOTORCYCLE RENTAL";
				cout << "\nThe total: " << (size_t)Total_income_MOTORCYCLE(List_of_MOTORCYCLE_rental, number_of_MOTORCYCLE_rental);
				system("pause");
			}
			break;
			case 7:
			{
				cout << "\n\t\THE TOTAL INCOME FROM MOTORCYCLE MODEL 250 RENTAL";
				cout << "\nThe total: " << (size_t)Total_income_MOTORCYCLE_MODEL_250(List_of_MOTORCYCLE_rental, number_of_MOTORCYCLE_rental);
				cout << endl;
				system("pause");
			}
			break;
			case 0:
			{
				cout << "\n\t\tEND PROGRAM";
				exit(0);
			}
			break;
		}
	}
}

void Check_option(int& option)
{
	while (option > 7 || option < 0)
	{
		cout << "\The option is not vailid";
		cout << "\nPlease re-enter the option: ";
		cin >> option;
	}
}

double Total_income_BICYCLE(BICYCLE List_of_BICYCLE_rental[], int number_of_BICYCLE_rental)
{
	double sum = 0;

	for (int i = 0; i < number_of_BICYCLE_rental; i++)
	{
		sum += List_of_BICYCLE_rental[i].cost_renting_BICYCLE();
	}
	return sum;
}

double Total_income_MOTORCYCLE(MOTORCYCLE List_of_MOTORCYCLE_rental[], int number_of_MOTORCYCLE_rental)
{
	double sum = 0;

	for (int i = 0; i < number_of_MOTORCYCLE_rental; i++)
	{
		sum += List_of_MOTORCYCLE_rental[i].cost_renting_MOTORCYCLE();
	}
	return sum;
}

double Total_income_MOTORCYCLE_MODEL_250(MOTORCYCLE List_of_MOTORCYCLE_rental[], int number_of_MOTORCYCLE_rental)
{
	double sum = 0;

	for (int i = 0; i < number_of_MOTORCYCLE_rental; i++)
	{
		if (List_of_MOTORCYCLE_rental[i].GETTER_model_MOTORCYCLE() == 250)
		{
			sum += List_of_MOTORCYCLE_rental[i].cost_renting_MOTORCYCLE();
		}
	}
	return sum;
}