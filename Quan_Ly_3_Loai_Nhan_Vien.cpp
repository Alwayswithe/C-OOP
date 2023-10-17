#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;


class BASIC_IMFORMATION
{
public:
	void enter_information()
	{
		cout << "\nEnter full name: ";
		cin.ignore();
		getline(cin, full_name);

		cout << "\nEnter year_of_birth: ";
		cin >> year_of_birth;

		cout << "\nEnter gender: ";
		cin.ignore();
		getline(cin, gender);

		cout << "\nEnter address: ";
		cin.ignore();
		getline(cin, address);

		cout << "\nEnter the height: ";
		cin >> height;
		cout << "\nEnter the weight: ";
		cin >> weight;

		cout << "\nEnter phone number: ";
		cin >> phone_number;
	}
	void export_information()
	{
		cout << "\nFull Name: " << full_name;
		cout << "\nYears of birth: " << year_of_birth;
		cout << "\nGender: " << gender;
		cout << "\nAddress: " << address;
		cout << "\nPhone number: " << phone_number;
		cout << "\nThe Height: " << height;
		cout << "\nThe Weight: " << weight;
	}

	BASIC_IMFORMATION();
	~BASIC_IMFORMATION();

protected:
	string full_name;
	int year_of_birth;
	string gender;
	string address;
	float height;
	float weight;
	float phone_number;
};

BASIC_IMFORMATION::BASIC_IMFORMATION()
{
}

BASIC_IMFORMATION::~BASIC_IMFORMATION()
{
}



class PLUMBER : public BASIC_IMFORMATION
{
public:
	void enter_information_PLUMBER()
	{
		BASIC_IMFORMATION::enter_information();
		cout << "\nEnter the working hours: ";
		cin >> working_hours;
	}
	void export_information_PLUMBER()
	{
		BASIC_IMFORMATION::export_information();
		cout << "\nWorking hours: " << working_hours;
	}
	float salary_PLUMBER()
	{
		return working_hours * 50000;
	}


	PLUMBER();
	~PLUMBER();

private:
	float working_hours;
};

PLUMBER::PLUMBER()
{
}

PLUMBER::~PLUMBER()
{
}



class SHIPPER : public BASIC_IMFORMATION
{
public:
	void enter_information_SHIPPER()
	{
		BASIC_IMFORMATION::enter_information();
		cout << "\nDelivery quantity: "; 
		cin >> delivery_quantity;
	}
	void export_information_SHIPPER()
	{
		BASIC_IMFORMATION::export_information();
		cout << "\nDelivery quantity: " << delivery_quantity;
	}
	float salary_SHIPPER()
	{
		return delivery_quantity * 33500;
	}

	SHIPPER();
	~SHIPPER();

private:
	float delivery_quantity;

};

SHIPPER::SHIPPER()
{
}

SHIPPER::~SHIPPER()
{
}



class TECHNOLOGY_DRIVER : public BASIC_IMFORMATION
{
public:
	void enter_information_TECHNOLOGY_DRIVER()
	{
		BASIC_IMFORMATION::enter_information();
		cout << "\nEnter km number: ";
		cin >> km_number;
	}
	void export_information_TECHNOLOGY_DRIVER()
	{
		BASIC_IMFORMATION::export_information();
		cout << "\nKm number: " << km_number;
	}
	float salary_TECHNOLOGY_DRIVER()
	{
		return km_number * 40000;
	}


	TECHNOLOGY_DRIVER();
	~TECHNOLOGY_DRIVER();

private:
	float km_number;
};

TECHNOLOGY_DRIVER::TECHNOLOGY_DRIVER()
{
}

TECHNOLOGY_DRIVER::~TECHNOLOGY_DRIVER()
{
}


void Check_option(int& option);
void Meau(PLUMBER* List_of_employees_PLUMBER[], int number_employess_PLUMBER, SHIPPER* List_of_employees_SHIPPER[], int number_employess_SHIPPER, TECHNOLOGY_DRIVER* List_of_employees_TECHNOLOGY_DRIVER[], int number_employess_TECHNOLOGY_DRIVER);
double Total_salary_PLUMBER(PLUMBER* List_of_employees_PLUMBER[], int number_employess_PLUMBER);
double Total_salary_SHIPPER(SHIPPER* List_of_employees_SHIPPER[], int number_employess_SHIPPER);
double Total_salary_TECHNOLOGY_DRIVER(TECHNOLOGY_DRIVER* List_of_employees_TECHNOLOGY_DRIVER[], int number_employess_TECHNOLOGY_DRIVER);
double Total_cost_paying_all_employees(PLUMBER* List_of_employees_PLUMBER[], int number_employess_PLUMBER, SHIPPER* List_of_employees_SHIPPER[], int number_employess_SHIPPER, TECHNOLOGY_DRIVER* List_of_employees_TECHNOLOGY_DRIVER[], int number_employess_TECHNOLOGY_DRIVER);



int main() {

	PLUMBER* List_of_employees_PLUMBER[100];
	SHIPPER* List_of_employees_SHIPPER[100];
	TECHNOLOGY_DRIVER* List_of_employees_TECHNOLOGY_DRIVER[100];

	int number_employess_PLUMBER = 0;
	int number_employess_SHIPPER = 0;
	int number_employess_TECHNOLOGY_DRIVER = 0;


	Meau(List_of_employees_PLUMBER, number_employess_PLUMBER, List_of_employees_SHIPPER, number_employess_SHIPPER, List_of_employees_TECHNOLOGY_DRIVER, number_employess_TECHNOLOGY_DRIVER);

	cout << endl;
	return 0;
}	

void Meau(PLUMBER* List_of_employees_PLUMBER[], int number_employess_PLUMBER, SHIPPER* List_of_employees_SHIPPER[], int number_employess_SHIPPER, TECHNOLOGY_DRIVER* List_of_employees_TECHNOLOGY_DRIVER[], int number_employess_TECHNOLOGY_DRIVER)
{
	int option;

	while (true)
	{
		system("cls");

		cout << "\n\t\tMANAGEMENT PROGRAM";
		cout << "\n1. Enter information of PLUMBER";
		cout << "\n2. Enter information of SHIPPER";
		cout << "\n3. Enter information of TECHONOLOGY DIVER";
		cout << "\n4. Export information of PLUMBER";
		cout << "\n5. Export information of SHIPPER";
		cout << "\n6. Export information of TECHONOLOGY DIVER";
		cout << "\n7. The total cost of paying the PLUMBER";
		cout << "\n8. The total cost of paying the SHIPPER";
		cout << "\n9. The total cost of paying the ECHONOLOGY DIVER";
		cout << "\n10. The total cost of paying all employees";
		cout << "\n11. Descending all employees base on salary";
		cout << "\n12. Delete employee out of the list";
		cout << "\n0. Exit the program";
		cout << "\n\t\t\tEND";

		cout << "\nEnter your option: ";
		cin >> option;
		Check_option(option);

		if (option == 1)
		{
			PLUMBER* employee_PLUMBER = new PLUMBER();
			cout << "\n\t\tENTER THE INFORMATION OF PLUMBER";
			employee_PLUMBER->enter_information_PLUMBER();

			List_of_employees_PLUMBER[number_employess_PLUMBER] = employee_PLUMBER;
			number_employess_PLUMBER++;
		}
		else if (option == 2)
		{
			SHIPPER* employee_SHIPPER = new SHIPPER();
			cout << "\n\t\tENTER THE INFORMATION OF SHIPPER";
			employee_SHIPPER->enter_information_SHIPPER();

			List_of_employees_SHIPPER[number_employess_SHIPPER] = employee_SHIPPER;
			number_employess_SHIPPER++;
		}
		else if (option == 3)
		{
			TECHNOLOGY_DRIVER* employee_TECHNOLOGY_DRIVER = new TECHNOLOGY_DRIVER();
			cout << "\n\t\tENTER THE INFORMATION OF TECHNOLOGY DRIVER";
			employee_TECHNOLOGY_DRIVER->enter_information_TECHNOLOGY_DRIVER();

			List_of_employees_TECHNOLOGY_DRIVER[number_employess_TECHNOLOGY_DRIVER] = employee_TECHNOLOGY_DRIVER;
			number_employess_TECHNOLOGY_DRIVER++;
		}
		else if (option == 4)
		{
			cout << "\n\t\tEXPORT THE INFORMATION OF PLUMBER";
			for (int i = 0; i < number_employess_PLUMBER; i++)
			{
				cout << "\nPlumber " << i + 1 << endl;
				List_of_employees_PLUMBER[i]->export_information_PLUMBER();
				cout << "\nSalary: " << (size_t)List_of_employees_PLUMBER[i]->salary_PLUMBER();
				cout << endl;
			}
			system("pause");
		}
		else if (option == 5)
		{
			cout << "\n\t\tEXPORT THE INFORMATION OF SHIPPER";
			for (int i = 0; i < number_employess_SHIPPER; i++)
			{
				cout << "\nShipper " << i + 1 << endl;
				List_of_employees_SHIPPER[i]->export_information_SHIPPER();
				cout << "\nSalary: " << (size_t)List_of_employees_SHIPPER[i]->salary_SHIPPER();
				cout << endl;
			}
			system("pause");
		}
		else if (option == 6)
		{
			cout << "\n\t\tEXPORT THE INFORMATION OF TECHNOLOGY DRIVERS";
			for (int i = 0; i < number_employess_TECHNOLOGY_DRIVER; i++)
			{
				cout << "\nDriver " << i + 1 << endl;
				List_of_employees_TECHNOLOGY_DRIVER[i]->export_information_TECHNOLOGY_DRIVER();
				cout << "\nSalary: " << (size_t)List_of_employees_TECHNOLOGY_DRIVER[i]->salary_TECHNOLOGY_DRIVER();
				cout << endl;
			}
			system("pause");
		}
		else if (option == 7)
		{
			cout << "\n\t\tTOTAL SALARY OF ALL PLUMBERS";
			cout << "\nTotal salary: " << (size_t)Total_salary_PLUMBER(List_of_employees_PLUMBER, number_employess_PLUMBER);
			cout << endl;
			system("pause");
		}
		else if (option == 8)
		{
			cout << "\n\t\tTOTAL SALARY OF ALL SHIPPER";
			cout << "\nTotal salary: " << (size_t)Total_salary_SHIPPER(List_of_employees_SHIPPER, number_employess_SHIPPER);
			cout << endl;
			system("pause");
		}
		else if (option == 9)
		{
			cout << "\n\t\tTOTAL SALARY OF ALL TEACHNOLOGY DRIVER";
			cout << "\nTotal salary: " << (size_t)Total_salary_TECHNOLOGY_DRIVER(List_of_employees_TECHNOLOGY_DRIVER, number_employess_TECHNOLOGY_DRIVER);
			cout << endl;
			system("pause");
		}
		else if (option == 10)
		{
			cout << "\n\t\tTHE TOTAL COST OF PAYING ALL EMPLOYEES";
			cout << "\nThe total: " << (size_t)Total_cost_paying_all_employees(List_of_employees_PLUMBER, number_employess_PLUMBER, List_of_employees_SHIPPER, number_employess_SHIPPER, List_of_employees_TECHNOLOGY_DRIVER, number_employess_TECHNOLOGY_DRIVER);
			cout << endl;
			system("pause");
		}
		else if (option == 0)
		{
			cout << "\n\t\tEND PROGRAM";
			break;
		}
	}

	for (int i = 0; i < number_employess_PLUMBER; i++)
	{
		delete List_of_employees_PLUMBER[i];
	}
	for (int i = 0; i < number_employess_SHIPPER; i++)
	{
		delete List_of_employees_SHIPPER[i];
	}
	for (int i = 0; i < number_employess_TECHNOLOGY_DRIVER; i++)
	{
		delete List_of_employees_TECHNOLOGY_DRIVER[i];
	}
}

void Check_option(int& option)
{
	while (option > 11 || option < 0)
	{
		cout << "\The option is not vailid";
		cout << "\nPlease re-enter the option: ";
		cin >> option;
	}
}

double Total_salary_PLUMBER(PLUMBER* List_of_employees_PLUMBER[], int number_employess_PLUMBER)
{
	double sum = 0;
	for (int i = 0; i < number_employess_PLUMBER; i++)
	{
		sum += List_of_employees_PLUMBER[i]->salary_PLUMBER();
	}
	return sum;
}

double Total_salary_SHIPPER(SHIPPER* List_of_employees_SHIPPER[], int number_employess_SHIPPER)
{
	double sum = 0;
	for (int i = 0; i < number_employess_SHIPPER; i++)
	{
		sum += List_of_employees_SHIPPER[i]->salary_SHIPPER();
	}
	return sum;
}

double Total_salary_TECHNOLOGY_DRIVER(TECHNOLOGY_DRIVER* List_of_employees_TECHNOLOGY_DRIVER[], int number_employess_TECHNOLOGY_DRIVER)
{
	double sum = 0;
	for (int i = 0; i < number_employess_TECHNOLOGY_DRIVER; i++)
	{
		sum += List_of_employees_TECHNOLOGY_DRIVER[i]->salary_TECHNOLOGY_DRIVER();
	}
	return sum;
}

double Total_cost_paying_all_employees(PLUMBER* List_of_employees_PLUMBER[], int number_employess_PLUMBER, SHIPPER* List_of_employees_SHIPPER[], int number_employess_SHIPPER, TECHNOLOGY_DRIVER* List_of_employees_TECHNOLOGY_DRIVER[], int number_employess_TECHNOLOGY_DRIVER)
{
	double sum = 0;

	for (int i = 0; i < number_employess_PLUMBER; i++)
	{
		sum += List_of_employees_PLUMBER[i]->salary_PLUMBER();
	}
	for (int i = 0; i < number_employess_SHIPPER; i++)
	{
		sum += List_of_employees_SHIPPER[i]->salary_SHIPPER();
	}
	for (int i = 0; i < number_employess_TECHNOLOGY_DRIVER; i++)
	{
		sum += List_of_employees_TECHNOLOGY_DRIVER[i]->salary_TECHNOLOGY_DRIVER();
	}

	return sum;
}