#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class PLUMBER
{
private:
	string full_name;
	int year_of_birth;
	string gender;
	string address;
	float height;
	float weight;
	int phone_number;
	float working_hours;


public:

	void enter_information_PLUMBER();
	void export_information_PLUMBER();
	float saraly_PLUMBER();

	PLUMBER();
	~PLUMBER();

};

void PLUMBER::enter_information_PLUMBER() 
{
	cout << "\nEnter full name: ";
	cin.ignore();
	getline(cin, full_name);

	cout << "\nEnter the year of birth: ";
	cin >> year_of_birth;

	cout << "\nEnter the gender: ";
	cin.ignore();
	getline(cin, gender);

	cout << "\nEnter the address: ";
	cin.ignore();
	getline(cin, address);

	cout << "\nEnter the phone number: ";
	cin >> phone_number;

	cout << "\nEnter the height: ";
	cin >> height;
	cout << "\nEnter the weight: ";
	cin >> weight;

	cout << "\nEnter the working hours: ";
	cin >> working_hours;

}

void PLUMBER::export_information_PLUMBER() 
{
	cout << "\nFull Name: " << full_name;
	cout << "\nYears of birth: " << year_of_birth;
	cout << "\nGender: " << gender;
	cout << "\nAddress: " << address;
	cout << "\nPhone number: " << phone_number;
	cout << "\nThe Height: " << height;
	cout << "\nThe Weight: " << weight;
	cout << "\nWorking hours: " << working_hours;
}

float PLUMBER::saraly_PLUMBER()
{
	return working_hours * 50000;
}

PLUMBER::PLUMBER()
{
}

PLUMBER::~PLUMBER()
{
}



class SHIPPER
{
public:

	void enter_information_SHIPPER();
	void export_information_SHIPPER();
	float salary_SHIPPER();

	SHIPPER();
	~SHIPPER();

private:
	string full_name;
	int year_of_birth;
	string gender;
	string address;
	float height;
	float weight;
	int phone_number;
	float delivery_quantity;
};

void SHIPPER::enter_information_SHIPPER()
{
	cout << "\nEnter full name: ";
	cin.ignore();
	getline(cin, full_name);

	cout << "\nEnter the year of birth: ";
	cin >> year_of_birth;

	cout << "\nEnter the gender: ";
	cin.ignore();
	getline(cin, gender);

	cout << "\nEnter the address: ";
	cin.ignore();
	getline(cin, address);

	cout << "\nEnter the phone number: ";
	cin >> phone_number;

	cout << "\nEnter the height: ";
	cin >> height;
	cout << "\nEnter the weight: ";
	cin >> weight;

	cout << "\nEnter the Delivery quantity: ";
	cin >> delivery_quantity;

}

void SHIPPER::export_information_SHIPPER()
{
	cout << "\nFull Name: " << full_name;
	cout << "\nYears of birth: " << year_of_birth;
	cout << "\nGender: " << gender;
	cout << "\nAddress: " << address;
	cout << "\nPhone number: " << phone_number;
	cout << "\nThe Height: " << height;
	cout << "\nThe Weight: " << weight;
	cout << "\nDelivery quantity: " << delivery_quantity;
}

float SHIPPER::salary_SHIPPER() 
{
	return delivery_quantity * 33500;
}

SHIPPER::SHIPPER()
{
}

SHIPPER::~SHIPPER()
{
}


class TECHNOLOGY_DRIVER
{
public:

	void enter_information_TECHNOLOGY_DRIVER();
	void export_information_TECHNOLOGY_DRIVER();
	float Salary_TECHNOLOGY_DRIVER();

	TECHNOLOGY_DRIVER();
	~TECHNOLOGY_DRIVER();

private:
	string full_name;
	int year_of_birth;
	string gender;
	string address;
	float height;
	float weight;
	int phone_number;
	float km_number;

};

void TECHNOLOGY_DRIVER::enter_information_TECHNOLOGY_DRIVER()
{
	cout << "\nEnter full name: ";
	cin.ignore();
	getline(cin, full_name);

	cout << "\nEnter the year of birth: ";
	cin >> year_of_birth;

	cout << "\nEnter the gender: ";
	cin.ignore();
	getline(cin, gender);

	cout << "\nEnter the address: ";
	cin.ignore();
	getline(cin, address);

	cout << "\nEnter the phone number: ";
	cin >> phone_number;

	cout << "\nEnter the height: ";
	cin >> height;
	cout << "\nEnter the weight: ";
	cin >> weight;

	cout << "\nEnter the Km number: ";
	cin >> km_number;
}

void TECHNOLOGY_DRIVER::export_information_TECHNOLOGY_DRIVER()
{
	cout << "\nFull Name: " << full_name;
	cout << "\nYears of birth: " << year_of_birth;
	cout << "\nGender: " << gender;
	cout << "\nAddress: " << address;
	cout << "\nPhone number: " << phone_number;
	cout << "\nThe Height: " << height;
	cout << "\nThe Weight: " << weight;
	cout << "\nThe km number: " << km_number;
}

float TECHNOLOGY_DRIVER::Salary_TECHNOLOGY_DRIVER()
{
	return km_number * 40000;
}

TECHNOLOGY_DRIVER::TECHNOLOGY_DRIVER()
{
}

TECHNOLOGY_DRIVER::~TECHNOLOGY_DRIVER()
{
}



void Meau(PLUMBER List_of_Plumber[], int number_employee_PLUMBER, SHIPPER List_of_Shipper[], int number_employee_SHIPPER, TECHNOLOGY_DRIVER List_of_Technology_Driver[], int number_employee_Technology_Driver);
void Check_option(int& option);
double Total_salary_PUMBER(PLUMBER List_of_Plumber[], int number_employee_PLUMBER);
void Permutation(PLUMBER& a, PLUMBER& b);
void Descending_base_on_salary_PUMBER(PLUMBER List_of_Plumber[], int number_employee_PLUMBER);
double Total_salary_SHIPPER(SHIPPER List_of_Shipper[], int number_employee_SHIPPER);
double Total_salary_TECHNOLOGY_DRIVER(TECHNOLOGY_DRIVER List_of_Technology_Driver[], int number_employee_Technology_Driver);
double Total_cost_paying_all_employees(PLUMBER List_of_Plumber[], int number_employee_PLUMBER, SHIPPER List_of_Shipper[], int number_employee_SHIPPER, TECHNOLOGY_DRIVER List_of_Technology_Driver[], int number_employee_Technology_Driver);


int main() {

	PLUMBER List_of_Plumber[100];
	SHIPPER List_of_Shipper[100];
	TECHNOLOGY_DRIVER List_of_Technology_Driver[100];
	int number_employee_PLUMBER = 0;
	int number_employee_SHIPPER = 0;
	int number_employee_Technology_Driver = 0;

	Meau(List_of_Plumber, number_employee_PLUMBER, List_of_Shipper, number_employee_SHIPPER, List_of_Technology_Driver, number_employee_Technology_Driver);

	cout << endl;
	return 0;
}

void Meau(PLUMBER List_of_Plumber[], int number_employee_PLUMBER, SHIPPER List_of_Shipper[], int number_employee_SHIPPER, TECHNOLOGY_DRIVER List_of_Technology_Driver[], int number_employee_Technology_Driver)
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
		//Check_option(option);

		if (option == 1)
		{
			cout << "\n\t\ENTER THE LIST OF INFORMATION OF PLUMBER";
			PLUMBER emloyee_PLUMBER;
			emloyee_PLUMBER.enter_information_PLUMBER();

			List_of_Plumber[number_employee_PLUMBER] = emloyee_PLUMBER;
			number_employee_PLUMBER++;
		}
		else if (option == 2)
		{
			cout << "\n\t\tENTER THE LIST OF INFORMATION OF SHIPPER";
			SHIPPER employee_SHIPPER;
			employee_SHIPPER.enter_information_SHIPPER();

			List_of_Shipper[number_employee_SHIPPER] = employee_SHIPPER;
			number_employee_SHIPPER++;
		}
		else if (option == 3)
		{
			cout << "\n\t\tENTER THE LIST OF INFORMATION OF TECHNOLOGY DRIVER";
			TECHNOLOGY_DRIVER employee_TECHNOLOGY_DRIVER;
			employee_TECHNOLOGY_DRIVER.enter_information_TECHNOLOGY_DRIVER();

			List_of_Technology_Driver[number_employee_Technology_Driver] = employee_TECHNOLOGY_DRIVER;
			number_employee_Technology_Driver++;
		}
		else if (option == 4)
		{
			cout << "\n\t\tEXPORT THE LIST OF INFORMATION OF PLUMBER" << endl;
			for (int i = 0; i < number_employee_PLUMBER; i++)
			{
				cout << "\nEmployee " << i << endl;
				List_of_Plumber[i].export_information_PLUMBER();
				cout << "\nSaraly: " << (size_t)List_of_Plumber[i].saraly_PLUMBER();
				cout << endl;
			}
			system("pause");
		}
		else if (option == 5)
		{
			cout << "\nEXPORT THE LIST OF INFORMATION OF SHIPPER";
			for (int i = 0; i < number_employee_SHIPPER; i++)
			{
				cout << "\nEmployee " << i + 1 << endl;
				List_of_Shipper[i].export_information_SHIPPER();
				cout << "\nSaraly: " << (size_t)List_of_Shipper[i].salary_SHIPPER();
				cout << endl;
			}
			system("pause");
		}
		else if (option == 6)
		{
			cout << "\nEXPORT THE LIST OF INFORMATION OF TECHNOLOGY DRIVER";
			for (int i = 0; i < number_employee_Technology_Driver; i++)
			{
				cout << "\nEmployee " << i + 1 << endl;
				List_of_Technology_Driver[i].export_information_TECHNOLOGY_DRIVER();
				cout << "\nSalary: " << (size_t)List_of_Technology_Driver[i].Salary_TECHNOLOGY_DRIVER();
				cout << endl;
			}
			system("pause");
		}
		else if (option == 7)
		{
			cout << "\n\t\tTOTAL SALARY OF ALL PLUMBERS";
			cout << "\nTotal: " << (size_t)Total_salary_PUMBER(List_of_Plumber, number_employee_PLUMBER);
			system("pause");
		}
		else if (option == 8)
		{
			cout << "\n\t\tTOTAL SALARY OF ALL SHIPPER";
			cout << "\nSalary: " << (size_t)Total_salary_SHIPPER(List_of_Shipper, number_employee_SHIPPER);
			system("pause");
		}
		else if (option == 9)
		{
			cout << "\nTOTAL SALARY OF ALL TECHNOLOGY DRIVER";
			cout << "\nSalary: " << (size_t)Total_salary_TECHNOLOGY_DRIVER(List_of_Technology_Driver, number_employee_Technology_Driver);
			system("pause");
		}
		else if (option == 10)
		{
			cout << "\nTHE TOTAL COST OF PAYING ALL EMPLOYEES";
			cout << "\nThe cost: " << (size_t)Total_cost_paying_all_employees(List_of_Plumber, number_employee_PLUMBER, List_of_Shipper, number_employee_SHIPPER, List_of_Technology_Driver, number_employee_Technology_Driver);
			system("pause");
		}
		else if (option == 11)
		{
			cout << "\n\t\tDECENDING PLUMBERS BASE ON SALARY" << endl;
			Descending_base_on_salary_PUMBER(List_of_Plumber, number_employee_PLUMBER);
			for (int i = 0; i < number_employee_PLUMBER; i++)
			{
				cout << "\nEmployee " << i << endl;
				List_of_Plumber[i].export_information_PLUMBER();
				cout << "\nSaraly: " << (size_t)List_of_Plumber[i].saraly_PLUMBER();
				cout << endl;
			}
			system("pause");
		}
		else if (option == 12)
		{
			int employee_delete = NULL;
			cout << "\n\t\tDELETE EMPLOYEE OUT OF THE LIST";
			cout << "\nEnter the delete employee: ";
			cin >> employee_delete;
			for (int i = 0; i < number_employee_PLUMBER; i++)
			{
				if (i == employee_delete)
				{
					for (int j = i; j < number_employee_PLUMBER; j++)
					{
						List_of_Plumber[j] = List_of_Plumber[j + 1];
					}
					number_employee_PLUMBER--;
				}
			}
			cout << "\nDone deleted";
			cout << endl;
			system("pause");
		}
		else if (option == 0)
		{
			cout << "\n\t\tEND PROGRAM";
			break;
		}
	}	
}

void Check_option(int& option)
{
	while (option > 12 || option < 0)
	{
		cout << "\The option is not vailid";
		cout << "\nPlease re-enter the option: ";
		cin >> option;
	}
}

double Total_salary_PUMBER(PLUMBER List_of_Plumber[], int number_employee_PLUMBER)
{
	double sum{};

	for (int i = 0; i < number_employee_PLUMBER; i++)
	{
		sum += List_of_Plumber[i].saraly_PLUMBER();
	}

	return sum;

}

double Total_salary_SHIPPER(SHIPPER List_of_Shipper[], int number_employee_SHIPPER)
{
	double sum{};

	for (int i = 0; i < number_employee_SHIPPER; i++)
	{
		sum += List_of_Shipper[i].salary_SHIPPER();
	}
	return sum;
}

double Total_salary_TECHNOLOGY_DRIVER(TECHNOLOGY_DRIVER List_of_Technology_Driver[], int number_employee_Technology_Driver)
{
	double sum{};

	for (int i = 0; i < number_employee_Technology_Driver; i++)
	{
		sum += List_of_Technology_Driver[i].Salary_TECHNOLOGY_DRIVER();
	}
	return sum;
}

double Total_cost_paying_all_employees(PLUMBER List_of_Plumber[], int number_employee_PLUMBER, SHIPPER List_of_Shipper[], int number_employee_SHIPPER, TECHNOLOGY_DRIVER List_of_Technology_Driver[], int number_employee_Technology_Driver)
{
	double sum{};

	for (int i = 0; i < number_employee_PLUMBER; i++)
	{
		sum += List_of_Plumber[i].saraly_PLUMBER();
	}

	for (int i = 0; i < number_employee_SHIPPER; i++)
	{
		sum += List_of_Shipper[i].salary_SHIPPER();
	}

	for (int i = 0; i < number_employee_Technology_Driver; i++)
	{
		sum += List_of_Technology_Driver[i].Salary_TECHNOLOGY_DRIVER();
	}

	return sum;
}

void Permutation(PLUMBER& a, PLUMBER& b)
{
	PLUMBER swap;

	swap = a;
	a = b;
	b = swap;
}

void Descending_base_on_salary_PUMBER(PLUMBER List_of_Plumber[], int number_employee_PLUMBER)
{
	for (int i = 0; i < number_employee_PLUMBER - 1; i++)
	{
		for (int j = i + 1; j < number_employee_PLUMBER; j++)
		{
			if (List_of_Plumber[i].saraly_PLUMBER() < List_of_Plumber[j].saraly_PLUMBER())
			{
				Permutation(List_of_Plumber[i], List_of_Plumber[j]);
			}
		}
	}
}
