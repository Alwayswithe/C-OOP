
// DOI LAI DIA CHI CUA CAC FILE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


class ACCOUNT_INFORMATION
{
public:

	void Enter_information()
	{
		string re_password;

		cout << "\n\tEnter the new ID: ";
		getline(cin, ID);

		cout << "\n\tEnter the new Password: ";
		getline(cin, Password);

		cout << "\n\tRe_enter the new Password: ";
		getline(cin, re_password);

		while (Password.compare(re_password) != 0)
		{
			cout << "\n\tYour password dose not match the previous password";
			cout << "\n\tPlease Re_enter the new Password: ";
			getline(cin, re_password);
		}

	}

	string Getter_ID()
	{
		return ID;
	}
	string Getter_Password()
	{
		return Password;
	}

	ACCOUNT_INFORMATION();
	~ACCOUNT_INFORMATION();

private:

	string ID;
	string Password;
};

ACCOUNT_INFORMATION::ACCOUNT_INFORMATION()
{
}

ACCOUNT_INFORMATION::~ACCOUNT_INFORMATION()
{
}



class ADMINISTRATOR : public ACCOUNT_INFORMATION 
{
public:

	void Enter_information_ADMINISTRATOR()
	{
		ACCOUNT_INFORMATION::Enter_information();
	}

	ADMINISTRATOR();
	~ADMINISTRATOR();

private:

	int code_product;
	string name_product;
	float price_product;
	int quantity_product;
	
};

ADMINISTRATOR::ADMINISTRATOR()
{
}

ADMINISTRATOR::~ADMINISTRATOR()
{
}



class BUYER : public ACCOUNT_INFORMATION
{
public:

	void Recreat_information_BUYER()
	{
		ACCOUNT_INFORMATION::Enter_information();
	}
	
	BUYER();
	~BUYER();

private:

};

BUYER::BUYER()
{
}

BUYER::~BUYER()
{
}



class FOODS_PRODUCT
{
public:

	void Enter_information_product()
	{
		cout << "\n\tEnter the code of the product: ";
		cin >> code_product;
		cout << "\n\tEnter the name of the product: ";
		cin.ignore();
		getline(cin, name_product);
		cout << "\n\tEnter the price of the product: ";
		cin >> price_product;
		cout << "\n\tEnter the quantity of the product: ";
		cin >> quantity_product;
	}

	void Export_list_food()
	{
		cout << "\n\tCode product: " << code_product;
		cout << "\n\tName product: " << name_product;
		cout << "\n\tPrice product: " << price_product;
		cout << "\n\tQuantity product: " << quantity_product;
	}


	int Getter_code_product()
	{
		return code_product;
	}
	void Setter_code_product(int new_code_product)
	{
		code_product = new_code_product;
	}

	string Getter_name_product()
	{
		return name_product;
	}
	void Setter_name_product(string new_name_product)
	{
		name_product = new_name_product;
	}

	float Getter_price_product()
	{
		return price_product;
	}
	void Setter_price_product(float new_price_product)
	{
		price_product = new_price_product;
	}

	int Getter_quantity_product()
	{
		return quantity_product;
	}
	void Setter_quantity_product(int new_quantity_product)
	{
		quantity_product = new_quantity_product;
	}



	FOODS_PRODUCT();
	~FOODS_PRODUCT();

private:

	int code_product;
	string name_product;
	float price_product;
	int quantity_product;

};

FOODS_PRODUCT::FOODS_PRODUCT()
{
}

FOODS_PRODUCT::~FOODS_PRODUCT()
{
}



int Check_File_In(string name_file);
void Login_Administrator(string& ID_ad, string& Password_ad);
void Login_BUYER(string& ID_BUYER, string& Password_BUYER);
int Check_ID_Password_ADMINISTRATOR(string ID_ad, string ad_name_file, string Password_ad, string ad_password_file);
int Check_ID_Password_BUYER(string ID_BUYER, string Password_BUYER, string ID_BUYER_data, string Password_BUYER_data);
void Add_New_Account_ADMINISTRATOR(ADMINISTRATOR* List_of_ADMINISTRATOR[], int number_of_ADMINISTRATOR);
void Add_New_Account_BUYER(BUYER* List_of_BUYER[], int number_of_BUYER);
void Add_New_Product(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT);
int Read_The_Data_List_Food(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT);
void Show_List_Foods(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT);
void Delete_Product(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT);
void Modify_Product(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT);
void Buy_Product(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT);


int main() {

	int user_position = 2;
	

	string ad_name_file;
	string ad_password_file;
	string ID_ad;
	string Password_ad;

	string ID_BUYER;
	string Password_BUYER;
	string ID_BUYER_data;
	string Password_BUYER_data;


	ADMINISTRATOR* List_of_ADMINISTRATOR[100];
	BUYER* List_of_BUYER[100];
	FOODS_PRODUCT* List_of_FOODS_PRODUCT[100];

	int number_of_ADMINISTRATOR = 0;
	int number_of_BUYER = 0;
	int number_of_FOODS_PRODUCT = 0;

	cout << "\n\t\tSupermarket Main Menu";
	cout << "\n\t\t---------------------";
	cout << "\n\t\t| 1) Administrator  |";
	cout << "\n\t\t| 2) Buyer          |";
	cout << "\n\t\t| 3) Exit           |";
	cout << "\n\t\t---------------------";

	cout << "\n\tPlese select: ";
	//cin >> user_position;

	
	switch (user_position)
	{
		case 1:
		{
			int administrator_option = 1;

			system("cls");
			cout << endl << "\n\t\tADMINISTRATOR";

			cout << "\n\tLogin";
			cout << "\n\tSign up";
			//cin >> administrator_option;

			if (administrator_option == 1)
			{
				system("cls");
				cout << endl << "\n\t\tADMINISTRATOR LOGIN";

				Login_Administrator(ID_ad, Password_ad);

				while (Check_ID_Password_ADMINISTRATOR(ID_ad, ad_name_file, Password_ad, ad_password_file) != 2)
				{
					system("cls");
					cout << endl << "\n\t\tADMINISTRATOR LOGIN";
					cout << endl << "\n\tYour ID or Password is not correct";
					cout << "\n\tPlease re_login";
					Login_Administrator(ID_ad, Password_ad);
				}

				//system("cls");
				int admin_option = 3;

				cout << "\n\t\t   Administrator Menu";
				cout << "\n\t\t-------------------------";
				cout << "\n\t\t| 1) Add the product    |";
				cout << "\n\t\t| 2) Modify the product |";
				cout << "\n\t\t| 3) Delete the product |";
				cout << "\n\t\t| 4) Back to main menu  |";
				cout << "\n\t\t-------------------------";

				cout << "\n\tEnter the administrator's option: ";
				//cin >> admin_option;

				if (admin_option == 1)
				{
					Add_New_Product(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
				}
				else if (admin_option == 2)
				{
					cout << "\n\t\tLIST OF FOODS";
					Read_The_Data_List_Food(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
					Show_List_Foods(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);

					cout << "\n\tModify the product";
					Modify_Product(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
					Show_List_Foods(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
				}
				else if (admin_option == 3)
				{
					cout << "\n\t\tLIST OF FOODS";
					
					Read_The_Data_List_Food(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
					Show_List_Foods(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
					Delete_Product(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
					cout << "\n\tList of Food product after updating" << endl;
					Show_List_Foods(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
					
				}
			}
			else if (administrator_option == 2)
			{
				system("cls");
				cout << endl << "\n\t\tADMINISTRATOR SIGN UP";

				Add_New_Account_ADMINISTRATOR(List_of_ADMINISTRATOR, number_of_ADMINISTRATOR);

				cout << "\n\tThe new administrator account was created successfully";
			}

		}
		break;
		case 2:
		{
			int BUYER_option = 1;

			system("cls");
			cout << endl << "\n\t\tCUSTOMER BUYER";

			cout << "\n\t1. Login";
			cout << "\n\t2. Sign up";
			//cin >> BUYER_option;

			if (BUYER_option == 1)
			{
				system("cls");
				cout << endl << "\n\t\BUYER LOGIN";

				Login_BUYER(ID_BUYER, Password_BUYER);

				while (Check_ID_Password_BUYER(ID_BUYER, Password_BUYER, ID_BUYER_data, Password_BUYER_data) != 2)
				{
					system("cls");
					cout << endl << "\n\t\BUYER LOGIN";
					cout << endl << "\n\tYour ID or Password is not correct";
					cout << "\n\tPlease re_login";
					Login_BUYER(ID_BUYER, Password_BUYER);
				}

				int customer_option = 1;

				cout << "\n\t\t   Customer Menu";
				cout << "\n\t\t-------------------------";
				cout << "\n\t\t| 1) Buy the product    |";
				cout << "\n\t\t| 2) Back to main menu  |";
				cout << "\n\t\t-------------------------";

				cout << "\n\tEnter the Customer's option: ";
				//cin >> customer_option;

				if (customer_option == 1)
				{
					Read_The_Data_List_Food(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
					
					Buy_Product(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);


				}
				else if (customer_option == 2)
				{

				}


			}
			else if (BUYER_option == 2)
			{
				system("cls");
				cout << endl << "\n\t\tBUYER SIGN UP";

				Add_New_Account_BUYER(List_of_BUYER, number_of_BUYER);

				cout << "\n\tThe new buyer account was created successfully";
			}
		}
		break;
	}
	



	for (int i = 0; i < number_of_ADMINISTRATOR; i++)
	{
		delete List_of_ADMINISTRATOR[i];
	}
	for (int i = 0; i < number_of_BUYER; i++)
	{
		delete List_of_BUYER[i];
	}
	for (int i = 0; i < number_of_FOODS_PRODUCT; i++)
	{
		delete List_of_FOODS_PRODUCT[i];
	}

	cout << endl;
	return 0;
}

// Login gate for Administrators
void Login_Administrator(string& ID_ad, string& Password_ad)
{
	cout << "\n\tEnter ID: ";
	getline(cin, ID_ad);

	cout << "\n\tEnter Password: ";
	getline(cin, Password_ad);
}

// Login gate for Custummers
void Login_BUYER(string& ID_BUYER, string& Password_BUYER)
{
	cout << "\n\tEnter ID: ";
	getline(cin, ID_BUYER);

	cout << "\n\tEnter Password: ";
	getline(cin, Password_BUYER);
}

// Check Administrators' ID and Password
int Check_ID_Password_ADMINISTRATOR(string ID_ad, string ad_name_file, string Password_ad, string ad_password_file)
{
	int check = 0;
	ifstream FileIn;

	FileIn.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (ID user administrator).TXT", ios_base::in);
	if (FileIn.fail() == true)
	{
		cout << "\n\tInformation of Administrator' ID file is not exist";
		return 0;
	}

	while (FileIn.eof() == false)
	{
		getline(FileIn, ad_name_file, '\n');
		if (ID_ad.compare(ad_name_file) == 0)
		{
			check++;
		}
	}
	FileIn.close();


	FileIn.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (Password AD).TXT", ios_base::in);
	if (FileIn.fail() == true)
	{
		cout << "\n\tInformation of Administrator' password file is not exist";
		return 0;
	}

	while (FileIn.eof() == false)
	{
		getline(FileIn, ad_password_file, '\n');
		if (Password_ad.compare(ad_password_file) == 0)
		{
			check++;
		}
	}
	FileIn.close();

	return check;
}

// Check Custummers' ID and Password
int Check_ID_Password_BUYER(string ID_BUYER, string Password_BUYER, string ID_BUYER_data, string Password_BUYER_data)
{
	ifstream FileIn;
	int check = 0;

	FileIn.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (BUYER'S ID).TXT", ios_base::in);
	if (FileIn.fail() == true)
	{
		cout << "\n\tInformation of BUYER's ID file is not exist";
		return 0;
	}

	while (FileIn.eof() == false)
	{
		getline(FileIn, ID_BUYER_data, '\n');
		if (ID_BUYER.compare(ID_BUYER_data) == 0)
		{
			check++;
		}
	}
	FileIn.close();


	FileIn.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (BUYER'S PASSWORD).TXT", ios_base::in);
	if (FileIn.fail() == true)
	{
		cout << "\n\tInformation of BUYER's Password file is not exist";
		return 0;
	}

	while (FileIn.eof() == false)
	{
		getline(FileIn, Password_BUYER_data, '\n');
		if (Password_BUYER.compare(Password_BUYER_data) == 0)
		{
			check++;
		}
	}
	FileIn.close();


	return check;
}

// Add new Administrator account
void Add_New_Account_ADMINISTRATOR(ADMINISTRATOR* List_of_ADMINISTRATOR[], int number_of_ADMINISTRATOR)
{
	ofstream FileOut;
	ADMINISTRATOR* employee_ADMINISTRATOR = new ADMINISTRATOR();

	employee_ADMINISTRATOR->Enter_information_ADMINISTRATOR();
	List_of_ADMINISTRATOR[number_of_ADMINISTRATOR] = employee_ADMINISTRATOR;
	number_of_ADMINISTRATOR++;

	FileOut.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (Password AD).TXT", ios_base::app);
	
	FileOut << employee_ADMINISTRATOR->Getter_Password() << endl;
	FileOut.close();

	FileOut.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (ID user administrator).TXT", ios_base::app);
	
	FileOut << employee_ADMINISTRATOR->Getter_ID() << endl;
	FileOut.close();

}

// Add new Custummers account
void Add_New_Account_BUYER(BUYER* List_of_BUYER[], int number_of_BUYER)
{
	ofstream FileOut;
	BUYER* customer_BUYER = new BUYER();

	customer_BUYER->Enter_information();
	List_of_BUYER[number_of_BUYER] = customer_BUYER;
	number_of_BUYER++;

	FileOut.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (BUYER'S ID).TXT", ios_base::app);

	FileOut << customer_BUYER->Getter_ID() << endl;
	FileOut.close();

	FileOut.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (BUYER'S PASSWORD).TXT", ios_base::app);
	
	FileOut << customer_BUYER->Getter_Password() << endl;
	FileOut.close();

}

int Check_File_In(string name_file)
{
	ifstream FileIn;

	if (FileIn.fail() == true)
	{
		cout << "\n\tInformation of " << name_file << " file is not exist";
		return 0;
	}
	
	return 0;
}

// Add new product into the product list
void Add_New_Product(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT)
{
	ofstream FileOut;
	FOODS_PRODUCT* food = new FOODS_PRODUCT();

	cout << "\n\t\tADD NEW PRODUCT";
	food->Enter_information_product();
	List_of_FOODS_PRODUCT[number_of_FOODS_PRODUCT] = food;
	number_of_FOODS_PRODUCT++;

	FileOut.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (List of product).TXT", ios_base::app);
	FileOut << endl << food->Getter_code_product() << " " << food->Getter_name_product() << " " << food->Getter_price_product() << " " << food->Getter_quantity_product();

	FileOut.close();
}

// Read the information of the product to add the information into array (List_of_FOODS_PRODUCT) before staring working
int Read_The_Data_List_Food(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT)
{
	ifstream FileIn;

	int code_product;
	string name_product;
	float price_product;
	int quantity_product;

	string black_space;

	FileIn.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (List of product).TXT", ios_base::in);
	if (FileIn.fail() == true)
	{
		cout << "\n\tInformation of List FOODS PRODUCT file is not exist";
		return 0;
	}

	number_of_FOODS_PRODUCT = 0;
	while (FileIn.eof() == false)
	{
		FOODS_PRODUCT* food = new FOODS_PRODUCT();

		FileIn >> code_product;
		FileIn.seekg(1, 1);
		getline(FileIn, name_product, ' ');
		FileIn >> price_product;
		FileIn >> quantity_product;
		getline(FileIn, black_space, '\n');

		food->Setter_code_product(code_product);
		food->Setter_name_product(name_product);
		food->Setter_price_product(price_product);
		food->Setter_quantity_product(quantity_product);

		List_of_FOODS_PRODUCT[number_of_FOODS_PRODUCT] = food;
		number_of_FOODS_PRODUCT++;
	}


	FileIn.close();
	return 0;
}

// Show the list of food into the console
void Show_List_Foods(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT)
{
	int space_black = 20;

	cout << endl;
	cout << right;
	cout << "\t" << setw(50) << "LIST FOOD";
	cout << "\n\t----------------------------------------------------------------------------------------";
	cout << endl;
	cout << left;
	cout << "\t" << setw(space_black) << "code product";
	cout << "\t" << setw(space_black) << "name product";
	cout << "\t" << setw(space_black) << "price product";
	cout << "\t" << setw(space_black) << "quantity product";
	cout << "\n\t----------------------------------------------------------------------------------------";
	

	for (int i = 0; i < number_of_FOODS_PRODUCT; i++)
	{
		cout << endl;
		cout << left;
		cout << "\t" << setw(space_black) << List_of_FOODS_PRODUCT[i]->Getter_code_product();
		cout << "\t" << setw(space_black) << List_of_FOODS_PRODUCT[i]->Getter_name_product();
		cout << "\t" << setw(space_black) << List_of_FOODS_PRODUCT[i]->Getter_price_product();
		cout << "\t" << setw(space_black) << List_of_FOODS_PRODUCT[i]->Getter_quantity_product();
	}
	cout << endl;
}

// Delete the product in Food List
void Delete_Product(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT)
{
	vector<string> lines;
	string line;

	int code_product;
	int location;

	fstream FileOpen;
	ofstream FileOut;

	cout << "\nEnter the code of the product which you want to delete that product: ";
	cin >> code_product;

	for (int i = 0; i < number_of_FOODS_PRODUCT; i++)
	{
		if (code_product == List_of_FOODS_PRODUCT[i]->Getter_code_product())
		{
			location = i + 1;
		}
	}
	
	FileOpen.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (List of product).TXT", ios_base::in);
	
	while (getline(FileOpen, line))
	{
		lines.push_back(line);
	}
	FileOpen.close();

	FileOut.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (List of product).TXT");

	for (int i = 0; i < lines.size(); i++)
	{
		if (i != location && i != 0)
		{
			FileOut << endl  << lines[i];
		}
	}
	FileOut.close();

	// Update the new date in List_of_FOODS_RODUCT
	Read_The_Data_List_Food(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);
}

// Modify the product in Food List
void Modify_Product(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT)
{

	int code_product;

	int new_code_product;
	string new_name_product;
	float new_price_product;
	int new_quantity_product;

	cout << "\n\tEnter the code of the product which you want to modify that product: ";
	cin >> code_product;

	for (int i = 0; i < number_of_FOODS_PRODUCT; i++)
	{
		if (List_of_FOODS_PRODUCT[i]->Getter_code_product() == code_product)
		{
			cout << "\n\tEnter the new code for the product: ";
			cin >> code_product;
			List_of_FOODS_PRODUCT[i]->Setter_code_product(code_product);

			cout << "\n\tEnter the new name for the product: ";
			cin.ignore();
			getline(cin, new_name_product);
			List_of_FOODS_PRODUCT[i]->Setter_name_product(new_name_product);

			cout << "\n\tEnter the new price for the product: ";
			cin >> new_price_product;
			List_of_FOODS_PRODUCT[i]->Setter_price_product(new_price_product);

			cout << "\n\tEnter the new price for the product: ";
			cin >> new_quantity_product;
			List_of_FOODS_PRODUCT[i]->Setter_quantity_product(new_quantity_product);
		}
	}

	ofstream FileOut("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (List of product).TXT", std::ofstream::out);
	FileOut.close();

	FileOut.open("C:\\Code\\Microsoft Visual Studio\\Spring - 2022\\OOP_C++\\Supermarket Billing System (List of product).TXT", ios_base::out);

	for (int i = 0; i < number_of_FOODS_PRODUCT; i++)
	{
		FileOut << endl << List_of_FOODS_PRODUCT[i]->Getter_code_product() << " " << List_of_FOODS_PRODUCT[i]->Getter_name_product() << " " << List_of_FOODS_PRODUCT[i]->Getter_price_product() << " " << List_of_FOODS_PRODUCT[i]->Getter_quantity_product();
	}

	FileOut.close();
}

// Buy the product
void Buy_Product(FOODS_PRODUCT* List_of_FOODS_PRODUCT[], int& number_of_FOODS_PRODUCT)
{

	int code_product;
	int quantity_product;

	int mark_number_product;

	string continue_shopping;

	do
	{
		
		system("cls");

		Show_List_Foods(List_of_FOODS_PRODUCT, number_of_FOODS_PRODUCT);

		cout << "\n\tEnter the code product that you wanna buy: ";
		cin >> code_product;

		// Check the existion of the code product that custumer wanna buy
		int check_code_product = 0;
		do
		{
			for (int i = 0; i < number_of_FOODS_PRODUCT; i++)
			{
				if (code_product == List_of_FOODS_PRODUCT[i]->Getter_code_product())
				{
					check_code_product = 1;
					mark_number_product = i;
					break;
				}
			}

			if (check_code_product == 0)
			{
				cout << "\n\tYour code_product is not exist in the list food";
				cout << "\n\tPlease re-enter the code_product: ";
				cin >> code_product;
			}

		} while (check_code_product == 0);


		cout << "\n\tEnter the quantity of product that you wanna buy: ";
		cin >> quantity_product;

		// Check the quantity of the product that custumer wanna buy
		int check_quantity_product = 0;
		do
		{
			if (quantity_product <= List_of_FOODS_PRODUCT[mark_number_product]->Getter_quantity_product() && quantity_product >= 1)
			{
				check_quantity_product = 1;
				break;
			}
			
			if (check_quantity_product == 0)
			{
				cout << "\n\tYour quantity product is out of range in the list food";
				cout << "\n\tPlease re-enter the quantity product: ";
				cin >> quantity_product;
			}

		} while (check_quantity_product == 0);


		cout << "\n\tDo you wanna continue shopping: ";
		cin.ignore();
		getline(cin, continue_shopping);

	} while (continue_shopping == "yes");

}